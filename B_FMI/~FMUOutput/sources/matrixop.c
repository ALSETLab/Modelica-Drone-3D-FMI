/*  * Code for matrix functions in Dymola
 *
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 * Author: Hans Olsson Dynasim AB, 1999
 * Version: 1.2, 1999-07-16*/
/* */

#ifndef MATRIX_OP_C
#define MATRIX_OP_C

#if defined(_MSC_VER)
#if (!DymolaGlobalOptimizations_) || (DymolaGlobalOptimizations_ == 2)
#pragma optimize( "g", on )
#endif
#endif

#if (!defined(LIBDSDLL_EXPORTS)) || defined(DYMOSIM_DLL_EXPORTS)

#include "matrixop1.h"
#include "localeless.h" /* needed for at least sprintfC */

#include <stddef.h>
#include <limits.h>
#include <float.h>
#include <string.h>

struct TaggedIndexStack {
	enum Subtag tag;
	union {
		Integer index;
		Integer range[3];
		IntegerArray vector;
	} u;
};
#undef Assert
#define Assert(b,x) if (!(b)) AssertModelicaF(b,#b,x)

DYMOLA_STATIC struct TaggedIndexStack*HandleVaList(va_list ap, struct TaggedIndexStack*VA_handler,int num_VA_handler) {
	int i;
	struct TaggedIndexStack*VA_handler_p=VA_handler;
	for(i=0;i<num_VA_handler;++i,++VA_handler_p) {
		  enum Subtag tag=va_arg(ap,int);
		  Assert(i+4<num_VA_handler,"Out of memory for va_list");
		  VA_handler_p->tag=(enum Subtag)(tag);
		  if (tag==EndMark) 
			  break;
		  switch(tag) {
		  case Colon:
			  break;
		  case Range:case RangeRange:
			  {
				  Integer start,stop,stride=1;
				  start=va_arg(ap,Integer);
				  if (tag==RangeRange) stride=va_arg(ap,Integer);
				  stop=va_arg(ap,Integer);
				  VA_handler_p->u.range[0]=start;
				  VA_handler_p->u.range[1]=stride;
				  VA_handler_p->u.range[2]=stop;
			  }
			  break;
			  
		  case Index:
			  {
				  VA_handler_p->u.index=va_arg(ap,Integer);
				  break;
			  }
		  case Vector:
			  {
				  VA_handler_p->u.vector=va_arg(ap,IntegerArray);
				  break;
			  }
		  case EndMark:
			  {
				  /* shouldn't happen*/
				  break;
			  }
		  }	
	}
	return VA_handler;
}


/* Buffers and keeping track of them by Mark and Release */
/* The idea is that each function has two marks:
 RealArray f(...) {
  RealArray res=RealTemporaryMatrix(...);
  MarkObject returnMark=PushMark();
  RealArray temp=RealTemporaryMatrix(...);
  ...
  MarkObject functionMark=PushMark();
  ...
  for(...) {
     ...
     Release(); // Destroy everything except local variables and return-value
     {
       RealArray v_=RealScalarArray(...);
       Integer index_;
       
       MarkObject for_mark=PushMark();
       for(index_=0;index_<v_.dims[0];index_++) {
         v=v_.data[index_];
         ...
         Release();
       };
       PopMark(for_mark);
  }
  ...
  Release();
  ...
  PopMark(returnMark); // Destroy everything except the return-value
  return res;
  }
  */
DYMOLA_STATIC MarkObject currentMarkNon={{RealbufferNon,IntegerbufferNon,SizebufferNon,StringbufferNon},{RealbufferNon,IntegerbufferNon,SizebufferNon,StringbufferNon}};
DYMOLA_STATIC char*startstringmarkNon=simplestringNon;
#if defined(DYN_MULTINSTANCE)
#define startMark (DYN_GetThreadData()->m_start)
#define currentMark (DYN_GetThreadData()->m_current)
#define stringmark  (DYN_GetThreadData()->m_stringmark)
#define startstringmark  (DYN_GetThreadData()->m_startstringmark)
#define EndRealbuffer (DYN_GetThreadData()->m_endreal)
#define EndIntegerbuffer (DYN_GetThreadData()->m_endinteger)
#define EndSizebuffer (DYN_GetThreadData()->m_endsize)
#define EndStringbuffer (DYN_GetThreadData()->m_endstring)
#define Endsimplestring (DYN_GetThreadData()->m_endsimplestring)
DYMOLA_STATIC void EnsureMarkInitializedFunction() {
	struct DYN_ThreadData*threadData=0;
	threadData=DYN_GetThreadData();
	if (threadData && 0==threadData->m_endreal) {
		const int numReal=
#ifndef DYNREALBUFFER
	500000
#else
	DYNREALBUFFER
#endif
	;
		const int numInteger =
#ifndef DYNINTEGERBUFFER
			50000
#else
			DYNINTEGERBUFFER
#endif
			;
		const int numString =
#ifndef DYNSTRINGBUFFER
			10000
#else
			DYNSTRINGBUFFER
#endif
			;
		threadData->m_current.place.Realbuffer=(Real*)calloc(numReal,sizeof(Real));
		threadData->m_endreal=threadData->m_current.place.Realbuffer+numReal;
		threadData->m_current.place.Integerbuffer=(Integer*)calloc(numInteger,sizeof(Integer));
		threadData->m_endinteger=threadData->m_current.place.Integerbuffer+ numInteger;
		threadData->m_current.place.Sizebuffer=(SizeType*)calloc(numInteger,sizeof(SizeType));
		threadData->m_endsize=threadData->m_current.place.Sizebuffer+ numInteger;
		threadData->m_current.place.Stringbuffer=(String*)calloc(numString,sizeof(String));
		threadData->m_endstring=threadData->m_current.place.Stringbuffer+ numString;
		threadData->m_current.mark=threadData->m_current.place;
		threadData->m_start=threadData->m_current;
		threadData->m_stringmark=threadData->m_startstringmark=calloc(numString,1);
		threadData->m_endsimplestring=threadData->m_stringmark+ numString;
	}
}
DYMOLA_STATIC void EnsureMarkFree(struct DYN_ThreadData*threadData) {
	if (threadData && 0!=threadData->m_endreal) {
		free(threadData->m_start.place.Realbuffer);
		free(threadData->m_start.place.Integerbuffer);
		free(threadData->m_start.place.Sizebuffer);
		free(threadData->m_start.place.Stringbuffer);
		free((void*)threadData->m_startstringmark);

		threadData->m_start.place.Realbuffer=0;
		threadData->m_endreal=0;
		threadData->m_start.place.Integerbuffer=0;
		threadData->m_endinteger=0;
		threadData->m_start.place.Sizebuffer=0;
		threadData->m_endsize=0;
		threadData->m_start.place.Stringbuffer=0;
		threadData->m_endstring=0;
		threadData->m_start.mark=threadData->m_start.place;
		threadData->m_current=threadData->m_start;
		threadData->m_stringmark=threadData->m_startstringmark=0;
		threadData->m_endsimplestring=0;
	}
}
DYMOLA_STATIC void EnsureMarkFree2() {
	EnsureMarkFree(DYN_GetThreadData());
}
#define EnsureMarkInitialized() if (EndRealbuffer==0) EnsureMarkInitializedFunction();
#else
DYMOLA_STATIC MarkObject startMark={{Realbuffer,Integerbuffer,Sizebuffer,Stringbuffer},{Realbuffer,Integerbuffer,Sizebuffer,Stringbuffer}};
#if (defined(_OPENMP) && !defined(DISABLE_DYMOLA_OPENMP))
#pragma omp threadprivate(startMark)
#endif
DYMOLA_STATIC MarkObject currentMark={{Realbuffer,Integerbuffer,Sizebuffer,Stringbuffer},{Realbuffer,Integerbuffer,Sizebuffer,Stringbuffer}};
#if (defined(_OPENMP) && !defined(DISABLE_DYMOLA_OPENMP))
#pragma omp threadprivate(currentMark)
#endif
extern char simplestring[];
DYMOLA_STATIC char*stringmark=simplestring;
#if (defined(_OPENMP) && !defined(DISABLE_DYMOLA_OPENMP))
#pragma omp threadprivate(stringmark)
#endif
DYMOLA_STATIC char*startstringmark=simplestring;
#if (defined(_OPENMP) && !defined(DISABLE_DYMOLA_OPENMP))
#pragma omp threadprivate(startstringmark)
#endif
#if (defined(_OPENMP) && !defined(DISABLE_DYMOLA_OPENMP))
#include <omp.h>
DYMOLA_STATIC void EnsureMarkInitializedFunction() {
	int i=omp_get_thread_num();
	int n=0;
	int num;
	if (0==n) {
		n=omp_get_max_threads();
		if (n<omp_get_num_procs()) n=omp_get_num_procs();
		if (n<omp_get_num_threads()) n=omp_get_num_threads();
	}
	num=sizeof(Realbuffer)/sizeof(*Realbuffer);
	currentMark.place.Realbuffer=Realbuffer+(i*num)/n;
	EndRealbuffer=Realbuffer+((i+1)*num)/n;
	num=sizeof(Integerbuffer)/sizeof(*Integerbuffer);
	currentMark.place.Integerbuffer=Integerbuffer+(i*num)/n;
	EndIntegerbuffer=Integerbuffer+((i+1)*num)/n;
	num=sizeof(Sizebuffer)/sizeof(*Sizebuffer);
	currentMark.place.Sizebuffer=Sizebuffer+(i*num)/n;
	EndSizebuffer=Sizebuffer+((i+1)*num)/n;
	num=sizeof(Stringbuffer)/sizeof(*Stringbuffer);
	currentMark.place.Stringbuffer=Stringbuffer+(i*num)/n;
	EndStringbuffer=Stringbuffer+((i+1)*num)/n;
	currentMark.mark=currentMark.place;
	startMark=currentMark;
	num=sizeof(simplestring)/sizeof(*simplestring);
	stringmark=startstringmark=simplestring+(i*num)/n;
	Endsimplestring=simplestring+((i+1)*num)/n;
}
#define EnsureMarkInitialized() if (EndRealbuffer==0) EnsureMarkInitializedFunction();
#else
#define EnsureMarkInitialized()
#endif
#endif

DYMOLA_STATIC MarkObject PushMark(void) {
  MarkObject oldMark;
  EnsureMarkInitialized();
  oldMark=currentMark;
  currentMark.mark=currentMark.place;
  return oldMark;
}


DYMOLA_STATIC void RePushMark(MarkObject*oldMark) {
  MarkObject newMark;
  EnsureMarkInitialized();
  newMark=PushMark();
  if (oldMark) oldMark->place=newMark.place;
}

/* Release: used after each matrix assignment in the function */
DYMOLA_STATIC void Release() {EnsureMarkInitialized();currentMark.place=currentMark.mark;}

/* At the end of the function */
DYMOLA_STATIC void PopMark(MarkObject oldMark) {EnsureMarkInitialized();currentMark=oldMark;}



/* Raw allocation of r temporaries and return a pointer to the start*/
DYMOLA_STATIC Real *RealTemp(SizeType r) {
  Real *d=0;
  EnsureMarkInitialized();
  d=currentMark.place.Realbuffer;
  currentMark.place.Realbuffer+=r;
  Assert(currentMark.place.Realbuffer<EndRealbuffer,"Out of memory for reals\nIt could due to too large matrices, infinite recursion, or uninitialized variables.\nYou can change the memory size by setting the variable Advanced.RealBufferSize.");
  return d;
}
DYMOLA_STATIC Integer *IntegerTemp(SizeType r) {
  Integer *i=0;
  EnsureMarkInitialized();
  i=currentMark.place.Integerbuffer;
  currentMark.place.Integerbuffer+=r;
  Assert(currentMark.place.Integerbuffer<EndIntegerbuffer,"Out of memory for integers\nIt could due to too large matrices, infinite recursion, or uninitialized variables.\nYou can increase the size of 'Integerbuffer' in dymola/source/matrixop.h.");
  return i;
}
DYMOLA_STATIC SizeType *SizeTemp(SizeType r) {
  SizeType *s=0;
  EnsureMarkInitialized();
  s=currentMark.place.Sizebuffer;
  currentMark.place.Sizebuffer+=r;
  Assert(currentMark.place.Sizebuffer<EndSizebuffer,"Out of memory for array dimensions\nIt could due to too many matrices, infinite recursion, or uninitialized variables.\nYou can increase the size of 'Sizebuffer' in dymola/source/matrixop.h.");
  return s;
}


DYMOLA_STATIC String * StringTemp(SizeType r) {
	String *s=0;
	EnsureMarkInitialized();
	s=currentMark.place.Stringbuffer;
	currentMark.place.Stringbuffer+=r;
	Assert(currentMark.place.Stringbuffer<EndStringbuffer,"Out of memory for strings\nIt could due to too large matrices, infinite recursion, or uninitialized variables.\nYou can increase the size of 'Stringbuffer' in dymola/source/matrixop.h.");
	return s;
}

DYMOLA_STATIC Real *RealNonTemp(SizeType r) {
  Real *d=0;
  d=currentMarkNon.place.Realbuffer;
  currentMarkNon.place.Realbuffer+=r;
  Assert(currentMarkNon.place.Realbuffer<EndRealbufferNon,"Out of memory for reals\nIt could due to too large matrices, infinite recursion, or uninitialized variables.\nYou can change the memory size by setting the variable Advanced.RealBufferSize.");
  return d;
}
DYMOLA_STATIC Integer *IntegerNonTemp(SizeType r) {
  Integer *i=0;
  i=currentMarkNon.place.Integerbuffer;
  currentMarkNon.place.Integerbuffer+=r;
  Assert(currentMarkNon.place.Integerbuffer<EndIntegerbufferNon,"Out of memory for integers\nIt could due to too large matrices, infinite recursion, or uninitialized variables.\nYou can increase the size of 'Integerbuffer' in dymola/source/matrixop.h.");
  return i;
}
DYMOLA_STATIC SizeType *SizeNonTemp(SizeType r) {
  SizeType *s=0;
  s=currentMarkNon.place.Sizebuffer;
  currentMarkNon.place.Sizebuffer+=r;
  Assert(currentMarkNon.place.Sizebuffer<EndSizebufferNon,"Out of memory for array dimensions\nIt could due to too many matrices, infinite recursion, or uninitialized variables.\nYou can increase the size of 'Sizebuffer' in dymola/source/matrixop.h.");
  return s;
}
DYMOLA_STATIC String * StringNonTemp(SizeType r) {
	String *s=0;
	s=currentMarkNon.place.Stringbuffer;
	currentMarkNon.place.Stringbuffer+=r;
	Assert(currentMarkNon.place.Stringbuffer<EndStringbufferNon,"Out of memory for strings\nIt could due to too large matrices, infinite recursion, or uninitialized variables.\nYou can increase the size of 'Stringbuffer' in dymola/source/matrixop.h.");
	return s;
}
/*  Helper to find index of element */
DYMOLA_STATIC SizeType FindIndex(SizeType ndims,SizeType*dims,va_list ap) {
  SizeType i,index;
  index=0;
  for(i=0;i<ndims;i++) {
    SizeType j=va_arg(ap,SizeType);
    SizeType dim=dims[i];
    Assert((j>=1)&&(j<=dim),"Index out of bounds");
    index=index*dim+(j-1);
  }
  return index;
}
/* Start of common routines */
/* Test for size compatibility, used in assertions */
DYMOLA_STATIC Integer RealMatchingSizes(const RealArray a,const RealArray b) {
  SizeType i;
  if (a.ndims!=b.ndims) return 0;
  for(i=0;i<a.ndims;i++) {if(a.dims[i]!=b.dims[i]) return 0;}
  return 1;
}
/* Return total number of elements */
DYMOLA_STATIC SizeType CommonNrElements(SizeType ndims, SizeType* dims) {
	SizeType prodsize = 1;
	SizeType i;
	for (i = 0; i<ndims; i++) prodsize *= dims[i];
	return prodsize;
}
/* Return total number of elements */
DYMOLA_STATIC SizeType RealNrElements(const RealArray a) {
  SizeType prodsize=1;
  SizeType i;
  for(i=0;i<a.ndims;i++) prodsize*=a.dims[i];
  return prodsize;
}
/* Create Array-temporaries given the dimensions */
/*  Internal: Use an existing va_list */
DYMOLA_STATIC RealArray RealVaTemporarySize(SizeType ndims,va_list ap) {
  RealArray temp;
  SizeType i;
  temp.ndims=ndims;
  temp.dims=SizeTemp(ndims);
  for(i=0;i<ndims;i++) temp.dims[i]=va_arg(ap,SizeType);
  return temp;
}
DYMOLA_STATIC RealArray RealVaTemporary(SizeType ndims,va_list ap) {
    RealArray temp=RealVaTemporarySize(ndims,ap);
    temp.data=RealTemp(RealNrElements(temp));
    return temp;
}

DYMOLA_STATIC RealArray RealVaNonTemporarySize(SizeType ndims,va_list ap) {
  RealArray temp;
  SizeType i;
  temp.ndims=ndims;
  temp.dims=SizeNonTemp(ndims);
  for(i=0;i<ndims;i++) temp.dims[i]=va_arg(ap,SizeType);
  return temp;
}
DYMOLA_STATIC RealArray RealVaNonTemporary(SizeType ndims,va_list ap) {
    RealArray temp=RealVaNonTemporarySize(ndims,ap);
    temp.data=RealNonTemp(RealNrElements(temp));
    return temp;
}

DYMOLA_STATIC IntegerArray IntegerVaNonTemporarySize(SizeType ndims,va_list ap) {
  IntegerArray temp;
  SizeType i;
  temp.ndims=ndims;
  temp.dims=SizeNonTemp(ndims);
  for(i=0;i<ndims;i++) temp.dims[i]=va_arg(ap,SizeType);
  return temp;
}
DYMOLA_STATIC IntegerArray IntegerVaNonTemporary(SizeType ndims,va_list ap) {
    IntegerArray temp=IntegerVaNonTemporarySize(ndims,ap);
    temp.data=IntegerNonTemp(IntegerNrElements(temp));
    return temp;
}

DYMOLA_STATIC StringArray StringVaNonTemporarySize(SizeType ndims,va_list ap) {
  StringArray temp;
  SizeType i;
  temp.ndims=ndims;
  temp.dims=SizeNonTemp(ndims);
  for(i=0;i<ndims;i++) temp.dims[i]=va_arg(ap,SizeType);
  return temp;
}
DYMOLA_STATIC StringArray StringVaNonTemporary(SizeType ndims,va_list ap) {
    StringArray temp=StringVaNonTemporarySize(ndims,ap);
    temp.data=StringNonTemp(StringNrElements(temp));
    return temp;
}

/*  Construct a temporary of the same size as a */
DYMOLA_STATIC RealArray RealMatch(const RealArray a) {
  RealArray temp;
  SizeType i;
  temp.ndims=a.ndims;
  temp.dims=SizeTemp(a.ndims);
  for(i=0;i<a.ndims;i++) temp.dims[i]=a.dims[i];
  temp.data=RealTemp(RealNrElements(a));
  return temp;
}
/* Construct array from sizes, using variable number of arguments */
DYMOLA_STATIC RealArray RealTemporary(SizeType ndims,...) {
  RealArray temp;
  va_list ap;
  va_start(ap,ndims);
  temp=RealVaTemporary(ndims,ap);
  va_end(ap);
  return temp;
}
/* Construct array from sizes, using variable number of arguments */
DYMOLA_STATIC RealArray RealNonTemporary(SizeType ndims,...) {
  RealArray temp;
  va_list ap;
  va_start(ap,ndims);
  temp=RealVaNonTemporary(ndims,ap);
  va_end(ap);
  return temp;
}
DYMOLA_STATIC IntegerArray IntegerNonTemporary(SizeType ndims,...) {
  IntegerArray temp;
  va_list ap;
  va_start(ap,ndims);
  temp=IntegerVaNonTemporary(ndims,ap);
  va_end(ap);
  return temp;
}
DYMOLA_STATIC StringArray StringNonTemporary(SizeType ndims,...) {
  StringArray temp;
  va_list ap;
  va_start(ap,ndims);
  temp=StringVaNonTemporary(ndims,ap);
  va_end(ap);
  return temp;
}
/* Special cases for vectors and matrices (most often used) */
DYMOLA_STATIC RealArray RealTemporaryMatrix(SizeType r,SizeType c) {
  RealArray temp;
  temp.ndims=2;
  temp.dims=SizeTemp(2);
  temp.dims[0]=r;temp.dims[1]=c;
  temp.data=RealTemp(r*c);
  return temp;
}
DYMOLA_STATIC RealArray RealTemporaryVector(SizeType r) {
  RealArray temp;
  temp.ndims=1;
  temp.dims=SizeTemp(1);
  temp.dims[0]=r;
  temp.data=RealTemp(r);
  return temp;
}
/* Assignment */
DYMOLA_STATIC void RealAssign(RealArray a,const RealArray b) {
  SizeType prodsize=RealNrElements(a);
  SizeType i;
  Assert(RealMatchingSizes(a,b),"Array dimensions did not match");
  for(i=0;i<prodsize;i++) a.data[i]=b.data[i];
}
/* Indexing to set/get elements */

DYMOLA_STATIC Real RealElement(const RealArray a,...) {
  SizeType index;
  va_list ap;
  va_start(ap,a);
  index=FindIndex(a.ndims,a.dims,ap);
  va_end(ap);
  return a.data[index];
}
/* Sizes */
DYMOLA_STATIC Integer RealSize(const RealArray a,SizeType i) {
    Assert((i>=1)&&(i<=a.ndims),"Size must be between 1 and ndims of array");
    return a.dims[i-1];
}
DYMOLA_STATIC IntegerArray RealSizes(const RealArray a) {
    IntegerArray res;
    Integer i;
    res.ndims=1;
    res.dims=SizeTemp(1);
    res.dims[0]=a.ndims;
    res.data=IntegerTemp(a.ndims);
    for(i=0;i<a.ndims;i++) res.data[i]=a.dims[i];
    return res;
}
/* Set element, note that val is prior to the index list. */
DYMOLA_STATIC void SetRealElement(Real val,RealArray a,...) {
  SizeType index;
  va_list ap;
  va_start(ap,a);
  index=FindIndex(a.ndims,a.dims,ap);
  a.data[index]=val;
  va_end(ap);
}
/* For debug write out */
DYMOLA_STATIC void RealWrite(const RealArray a) {
  SizeType i;
  DymosimMessageInt("Dims: ",a.ndims);
  for(i=0;i<a.ndims;i++) DymosimMessageInt(" ",a.dims[i]);
  for(i=0;i<RealNrElements(a);i++) DymosimMessageMatrixElement("",i,1,a.data[i]);
}

/* Construct Arrays from other arrays */
DYMOLA_STATIC RealArray RealArrayArray(SizeType narg,RealArray first,...) {
  RealArray res;
  SizeType i,j,prodsize;
  va_list ap;
  res.ndims=first.ndims+1;
  res.dims=SizeTemp(res.ndims);
  res.dims[0]=narg;
  for(i=1;i<res.ndims;i++) res.dims[i]=first.dims[i-1];
  prodsize=RealNrElements(first);  
  res.data=RealTemp(prodsize*narg);
  va_start(ap,first);
  for(i=0;i<narg;i++) {
    RealArray next;
    next=(i!=0)?va_arg(ap,RealArray):first;
    Assert(RealMatchingSizes(first,next),"Arrays in array must be of equal sizes");
    for(j=0;j<prodsize;j++)
      res.data[i*prodsize+j]=next.data[j];
  }
  va_end(ap);
  return res;
}
/* Construct arrays from scalars */
DYMOLA_STATIC RealArray RealScalarArray(SizeType narg,...) {
  RealArray res;
  SizeType i;
  va_list ap;
  res=RealTemporaryVector(narg);
  va_start(ap,narg);
  for(i=0;i<narg;i++) {
    res.data[i]=va_arg(ap,Real);
  }
  va_end(ap);
  return res;
}

/* Get/Put of submatrices, i.e. a[i,:,v,1:4] */

/* Actual get of a submatrix */
DYMOLA_STATIC void RealFromSub(RealArray to,SizeType to_offset,SizeType to_dim,
              const RealArray from,SizeType from_offset,SizeType from_dim,
              SizeType trailingsize,
			  struct TaggedIndexStack*ap) {
  Integer tag;
  if (!ap) return; /* Error */
  tag=ap->tag;
  switch(tag) {
  case Colon:
    {
      SizeType newdim=from.dims[from_dim];
      SizeType i;
      for(i=0;i<newdim;i++) RealFromSub(to,to_offset*newdim+i,
        to_dim+1,from,from_offset*newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Range:case RangeRange:
    {
      Integer start,stop,stride=1,i,from_newdim,to_newdim;
      start=ap->u.range[0];
      if (tag==RangeRange) stride=ap->u.range[1];
      stop=ap->u.range[2];
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<to_newdim;i++) 
        RealFromSub(to,to_offset*to_newdim+i,to_dim+1,
        from,from_offset*from_newdim+(start+stride*i-1),from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Index:
    {
      Integer i=ap->u.index;
      RealFromSub(to,to_offset,to_dim,
        from,from_offset*from.dims[from_dim]+i-1,from_dim+1,trailingsize,ap+1);
      break;
    }
  case Vector:
    {
      IntegerArray v=ap->u.vector;
      Integer from_newdim,to_newdim,i;
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<v.dims[0];i++)
        RealFromSub(to,to_offset*to_newdim+i,to_dim+1,
        from,from_offset*from_newdim+v.data[i]-1,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case EndMark:
    {
      SizeType i;
      Real *to_p=to.data+to_offset;
      Real *from_p=from.data+from_offset;
      for(i=0;i<trailingsize;i++,to_p+=1,from_p+=1) *to_p=*from_p;
      break;
    }
  }
}
/* Concatenate along dimensions 'along' (1..ndims) and given nargs arguments */
DYMOLA_STATIC RealArray RealCat(SizeType along,SizeType nargs,RealArray first,...) {
  RealArray res;
  va_list ap;
  SizeType i,j;
  res.ndims=first.ndims;
  res.dims=SizeTemp(res.ndims);
  along--; /* Adapt to C usage */
  {
    /* Pass 1: determine size of output */
    for(j=0;j<first.ndims;j++) res.dims[j]=first.dims[j]; /* Starting values */
    va_start(ap,first);
    for(i=1;i<nargs;i++) {
      RealArray a;
      a=va_arg(ap,RealArray);
      Assert(a.ndims==first.ndims,"Number of dimensions must match for cat");
#ifndef NDEBUG
      for(j=0;j<a.ndims;j++) if (j!=along) {Assert(first.dims[j]==a.dims[j],"Sizes must match for cat");}
#endif
      res.dims[along]+=a.dims[along];
    }
    va_end(ap);
  }
  res.data=RealTemp(CommonNrElements(res.ndims, res.dims));
  {
    /* Pass 2: copy data */
    SizeType presize=1;      /* Blocks */
    SizeType trailingsize=1; /* Elements in each block */
    SizeType marker=0; /* How far are in res along dimension along */
    for(i=0;i<along;i++) presize*=res.dims[i];
    for(i=along+1;i<res.ndims;i++) trailingsize*=res.dims[i];
    va_start(ap,first);
    for(i=0;i<nargs;i++) {
      SizeType pre,current,trailing;
      RealArray a;
      if (i!=0) a=va_arg(ap,RealArray); else a=first;
      for(pre=0;pre<presize;pre++) 
        for(current=0;current<a.dims[along];current++)
          for(trailing=0;trailing<trailingsize;trailing++)
		  res.data[(pre*res.dims[along]+(current+marker))*trailingsize+trailing]=
            a.data[(pre*a.dims[along]+current)*trailingsize+trailing];
      marker+=a.dims[along];
    }
    va_end(ap);
  }
  return res;
}

/* The helper in Modelica */
DYMOLA_STATIC RealArray RealPromote(const RealArray a,SizeType n) {
  RealArray res;
  SizeType i;
  Assert(n>=a.ndims,"Promote cannot decrease number of dimensions");
  res.ndims=n;
  res.data=a.data; /* No need to copy */
  res.dims=SizeTemp(n);
  for(i=0;i<a.ndims;i++) res.dims[i]=a.dims[i];
  for(i=a.ndims;i<n;i++) res.dims[i]=1;
  return res;
}
DYMOLA_STATIC RealArray RealPromoteScalar(const Real x,SizeType n) {
    RealArray res;
    Integer i;
    res.ndims=n;
    res.data=RealTemp(1);
    res.data[0]=x;
    res.dims=SizeTemp(n);
    for(i=0;i<n;i++) res.dims[i]=1;
    return res;
}
/* Actual put of submatrix */
DYMOLA_STATIC void RealToSub(RealArray to,SizeType to_offset,SizeType to_dim,
              const RealArray from,SizeType from_offset,SizeType from_dim,
              SizeType trailingsize,
			  struct TaggedIndexStack*ap) {
  Integer tag;
  if (!ap) return; /* Error */
  tag=ap->tag;
  switch(tag) {
  case Colon:
    {
      SizeType newdim=from.dims[from_dim];
      SizeType i;
      for(i=0;i<newdim;i++) RealToSub(to,to_offset*newdim+i,
        to_dim+1,from,from_offset*newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Range:case RangeRange:
    {
      Integer start,stop,stride=1,i,from_newdim,to_newdim;
      start=ap->u.range[0];
      if (tag==RangeRange) stride=ap->u.range[1];
      stop=ap->u.range[2];
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<from_newdim;i++) 
        RealToSub(to,to_offset*to_newdim+(start+stride*i-1),to_dim+1,
        from,from_offset*from_newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Index:
    {
      Integer i=ap->u.index;
      RealToSub(to,to_offset*to.dims[to_dim]+(i-1),to_dim+1,
        from,from_offset,from_dim,trailingsize,ap+1);
      break;
    }    
  case Vector:
    {
      IntegerArray v=ap->u.vector;
      Integer from_newdim,to_newdim,i;
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<v.dims[0];i++)
        RealToSub(to,to_offset*to_newdim+(v.data[i]-1),to_dim+1,
        from,from_offset*from_newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case EndMark:
    {
      SizeType i;
      Real *to_p=to.data+to_offset;
      Real *from_p=from.data+from_offset;
      for(i=0;i<trailingsize;i++,to_p+=1,from_p+=1) *to_p=*from_p;
      break;
    }
  }
}
/* Use as: RealGetSub(a,Colon,Index,3,Range,3,4,EndMark)=a[:,3,3:4] */
DYMOLA_STATIC RealArray RealGetSub(const RealArray a,...) {
  RealArray temp;
  va_list ap;
  SizeType ndims=a.ndims,trailingsize=1,nargs=0;
  /* Pass 1. Determine nr. dimensions of output */
  {
    Integer over=0;
    va_start(ap,a);
    for(;!over;) {
      enum Subtag tag=va_arg(ap,int);
      switch (tag) {
      case Colon:nargs++;break;
      case RangeRange:va_arg(ap,Integer); /* Fallthru*/
      case Range:va_arg(ap,Integer),va_arg(ap,Integer);nargs++;break;
      case Vector:va_arg(ap,RealArray);nargs++;break;
      case Index:va_arg(ap,Integer);Assert(ndims>0,"Internal error in subscriptring of array");ndims--;nargs++;break;
      case EndMark:over=1;break;
      }
    }
    va_end(ap);
    Assert(nargs<=a.ndims,"Too many subscripts for array");

  }
  temp.ndims=ndims;
  temp.dims=SizeTemp(ndims);
  /* Pass 2. Determine size of output */
  {
    Integer over=0;
    SizeType temp_dim=0,a_dim=0;
    va_start(ap,a);
    for(;!over;) {
      enum Subtag tag=va_arg(ap,int);
      switch (tag) {
      case Colon:temp.dims[temp_dim]=a.dims[a_dim];temp_dim++;break;
      case RangeRange:case Range:
        {
          Integer start,stop,stride=1,num;
          start=va_arg(ap,Integer);
          if (tag==RangeRange) stride=va_arg(ap,Integer);
          stop=va_arg(ap,Integer);
          num=1+(stop-start)/stride;
          if (num<=0) num=0;
          else {
            Assert((start>=1)&&(start<=a.dims[a_dim]),"Range subscripting: start out of range");
            Assert((stop >=1)&&(stop <=a.dims[a_dim]),"Range subscripting: end out of range");
          }
          temp.dims[temp_dim]=num;
          temp_dim++;
          break;
        }
      case Vector:
        {
          IntegerArray v=va_arg(ap,IntegerArray);
          SizeType i;
          Assert(v.ndims==1,"Array subscripting: only vectors (and scalars) allowed as indicies");
          temp.dims[temp_dim]=v.dims[0];
          for(i=0;i<v.dims[0];i++) {
		  Assert((v.data[i]>=1)&&(v.data[i]<=a.dims[a_dim]),"Array subscripting: vector index out of range");
	  }
          temp_dim++;
          break;
        }
      case Index:
        {
          Integer i=va_arg(ap,Integer);
          Assert((i>=1)&&(i<=a.dims[a_dim]),"Array subscripting: scalar index out of range");
          break;
        }
      case EndMark:over=1;break;
      }
      a_dim++;
    }
    va_end(ap);    
    {
      SizeType i;
      for(i=nargs;i<a.ndims;i++) {
        temp.dims[temp_dim++]=a.dims[i];
        trailingsize*=a.dims[i];
      }
    }
  }
  temp.data=RealTemp(CommonNrElements(temp.ndims, temp.dims));
  /* Pass 3. Copy output */
  {
	struct TaggedIndexStack*apt=0;
	struct TaggedIndexStack VA_handler[100];
    va_start(ap,a);
	apt=HandleVaList(ap, VA_handler, sizeof(VA_handler)/sizeof(*VA_handler));
	va_end(ap);
    RealFromSub(temp,0,0,a,0,0,trailingsize,apt);
  }
  return temp;
}
/* Use as RealPutSub(a, out,Index,3,Colon,Range,3,4) yields out[3,:,3:4]=a; */
DYMOLA_STATIC RealArray RealCopy(const RealArray a) {
	int i,imax;
	RealArray temp;
	temp.ndims=a.ndims;
	temp.dims=SizeTemp(a.ndims);
	for(i=0;i<a.ndims;++i) temp.dims[i]=a.dims[i];
	imax=RealNrElements(a);
	temp.data=RealTemp(imax);
	for(i=0;i<imax;++i) temp.data[i]=a.data[i];
	return temp;
}
DYMOLA_STATIC void RealPutSub(const RealArray ain,RealArray out,...) {
  RealArray a;
  va_list ap;
  SizeType out_dim=0,a_dim=0,trailingsize=1,nargs=0;
  a=RealCopy(ain);
  /* Pass 1. Determine nr. dimensions of output */
  {
    Integer over=0;
    va_start(ap,out);
    for(;!over;) {
      enum Subtag tag=va_arg(ap,int);
      switch (tag) {
      case Colon:
        Assert(out_dim<out.ndims,"Internal error in subscripting (:)");
        Assert(a_dim<a.ndims,"Internal error in subscripting (:)");
        Assert(out.dims[out_dim]==a.dims[a_dim],"Assignment array subscripting: A[:]=B must have identical sizes");
        out_dim++;
        a_dim++;
        break;
      case RangeRange:case Range:
        {
          Integer start,stop,stride=1,num;
          Assert(out_dim<out.ndims,"Internal error in subscripting: range");
          Assert(a_dim<a.ndims,"Internal error in subscripting: range ");
          start=va_arg(ap,Integer);
          if (tag==RangeRange) stride=va_arg(ap,Integer);
          stop=va_arg(ap,Integer);
          num=(stop-start+stride)/stride;
          if (num<=0) num=0;
          else {
            Assert((start>=1)&&(start<=out.dims[out_dim]),"Assignment array subscripting: start of range out of bounds");
            Assert((stop>=1)&&(stop<=out.dims[out_dim]),"Assignment array subscripting: end of range out of bounds");
          }
          Assert(a.dims[a_dim]==num,"Assignment array subscripting: A[a:b]=B must have identical sizes");
          out_dim++;
          a_dim++;
          break;
        }
      case Vector:
        {
          IntegerArray v=va_arg(ap,IntegerArray);
          SizeType i;
          Assert(out_dim<out.ndims,"Internal error in vector subscripting");
          Assert(a_dim<a.ndims,"Internal error in vector subscripting");
          Assert(v.ndims==1,"Assignment array subscripting: array index must be a vector");
          Assert(a.dims[a_dim]==v.dims[0],"Assignment array subscripting: A[vect]=B must have identical sizes");
          for(i=0;i<v.dims[0];i++) {
		  Assert((v.data[i]>=1)&&(v.data[i]<=out.dims[out_dim]),"Assignment array subscripting: vector index out of bounds");
	  }
          out_dim++;
          a_dim++;
          break;
        }
      case Index:
        {
          Integer i=va_arg(ap,Integer);
          Assert(out_dim<out.ndims,"Internal error in scalar subscripting");
          Assert((i>=1)&&(i<=out.dims[out_dim]),"Assignment array subscripting: scalar index out of bounds");
          out_dim++;
          break;
        }
      case EndMark:over=1;break;
      }
    }
    va_end(ap);
    Assert(a.ndims-a_dim==out.ndims-out_dim,"Assignment array subscripting: unequal number of dimensions");
    {
      SizeType i;
      for(i=a_dim;i<a.ndims;i++) {
        trailingsize*=a.dims[i];
        Assert(a.dims[i]==out.dims[(i-a_dim)+out_dim],"Internal error in subscripting");
      }
    }
  }
  /* Pass 2. Copy output */
  {
	struct TaggedIndexStack*apt=0;
	struct TaggedIndexStack VA_handler[100];
	va_start(ap,out);
	apt=HandleVaList(ap, VA_handler, sizeof(VA_handler)/sizeof(*VA_handler));
	va_end(ap);
    RealToSub(out,0,0,a,0,0,trailingsize,apt);
  }
}


/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
/* Fill */
DYMOLA_STATIC RealArray RealFillAssign(RealArray res,const Real t) {
  SizeType i,prodsize;
  prodsize=RealNrElements(res);
  for(i=0;i<prodsize;i++) res.data[i]=t;
  return res;
}
DYMOLA_STATIC RealArray RealFill(const Real t,SizeType ndims,...) {
  va_list ap;
  RealArray temp;
  va_start(ap,ndims);
  temp=RealFillAssign(RealVaTemporary(ndims,ap),t);
  va_end(ap);
  return temp;
}
DYMOLA_STATIC RealArray RealFillArray(const RealArray a,SizeType ndims,...) {
	va_list ap;
	int i,j,inputProd,fillProd;
	RealArray temp;
	temp.ndims=a.ndims+ndims;
	temp.dims=SizeTemp(temp.ndims);

	va_start(ap,ndims);
	for(i=0;i<ndims;++i) temp.dims[i]=va_arg(ap,SizeType);
	va_end(ap);
	for(i=0;i<a.ndims;++i) temp.dims[i+ndims]=a.dims[i];

	fillProd=1;
	for(i=0;i<ndims;++i) fillProd*=temp.dims[i];
	inputProd=RealNrElements(a);

	temp.data=RealTemp(inputProd*fillProd);
	for(i=0;i<inputProd;++i) {
		for(j=0;j<fillProd;j++) {
		  temp.data[i+j*inputProd]=a.data[i];
		}
	}
	return temp;
}

DYMOLA_STATIC Real Realscalar(const RealArray a) {
    Assert(RealNrElements(a)==1,"scalar requires exactly one element");
    return a.data[0];
}
/* Matrix operations not limited to numeric matrices */
DYMOLA_STATIC RealArray Realvector(const RealArray a) {
    RealArray res;
#ifndef NDEBUG
    Integer i,found_non_one=0;
    for(i=0;i<a.ndims;i++) {if (a.dims[i]>1) {Assert(!found_non_one,"vector requires exactly one vector non-unit dimension");found_non_one=1;}}
#endif
    res.ndims=1;
    res.dims=SizeTemp(1);
    res.dims[0]=RealNrElements(a);
    res.data=a.data;
    return res;
}
DYMOLA_STATIC RealArray Realmatrix(const RealArray a) {
    RealArray res;
    res.ndims=2;
    res.dims=SizeTemp(2);
    res.dims[0]=a.dims[0];
    res.dims[1]=(a.ndims<2)?1:a.dims[1];
    res.data=a.data;
    Assert(RealNrElements(a)==RealNrElements(res),"matrix requires size(x,i)=1 for i>2");
    return res;
}
DYMOLA_STATIC RealArray Realtranspose(const RealArray a) {
    RealArray res;
    Integer i,j,k,remsize;
    res.ndims=a.ndims;
    Assert(a.ndims>=2,"transpose requires ndims>=2");
    res.dims=SizeTemp(a.ndims);
    res.dims[0]=a.dims[1];
    res.dims[1]=a.dims[0];
    remsize=1;
    for(i=2;i<a.ndims;i++) {
	remsize*=(res.dims[i]=a.dims[i]);
    }
    res.data=RealTemp(CommonNrElements(res.ndims, res.dims));
    for(i=0;i<res.dims[0];i++) for(j=0;j<res.dims[1];j++) {
	for(k=0;k<remsize;k++) {
	    res.data[(i*res.dims[1]+j)*remsize+k]=a.data[(j*a.dims[1]+i)*remsize+k];
	}
    }
    return res;
}
DYMOLA_STATIC RealArray Realouterproduct(const RealArray a,const RealArray b) {
    Assert(a.ndims==1,"Outerproduct require a vector as first argument");
    Assert(b.ndims==1,"Outerproduct require a vector as second argument");
    {
	    SizeType na=a.dims[0],nb=b.dims[0];
	    SizeType i,j;
	    RealArray res=RealTemporaryMatrix(na,nb);
	    for(i=0;i<na;i++) {
		    Real ai=a.data[i];
		    for(j=0;j<nb;j++) 
			    res.data[i*nb+j]=ai*b.data[j];
	    }
	    return res;
    }
}
DYMOLA_STATIC RealArray Realsymmetric(const RealArray a) {
    RealArray res;
    Integer i,j,n=a.dims[0];
    Assert(a.ndims==2,"symmetric requires ndims==2");
    Assert(a.dims[0]==a.dims[1],"symmetric requires square matrix");
    res=RealTemporaryMatrix(n,n);
    for(i=0;i<n;i++) {
	for(j=0;j<=i;j++) 
		res.data[i*n+j]=a.data[j*n+i];
	for(;j<n;j++) res.data[i*n+j]=a.data[i*n+j];
    }
    return res;
}
/* End of common routines for String*/
/* Basic operations, add, subtract, scale*/
/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
DYMOLA_STATIC RealArray RealAddAssign(RealArray res,const RealArray a,const RealArray b) {
  SizeType prodsize,i;
  Assert(RealMatchingSizes(a,b),"Add of arrays require arguments of matching size");
  Assert(RealMatchingSizes(res,a),"Add of arrays require result of matching size");
  prodsize=RealNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=a.data[i]+b.data[i];
  return res;
}
DYMOLA_STATIC RealArray RealAdd(const RealArray a,const RealArray b) {
  return RealAddAssign(RealMatch(a),a,b);
}
DYMOLA_STATIC RealArray RealSubtractAssign(RealArray res,const RealArray a,const RealArray b) {
  SizeType prodsize,i;
  Assert(RealMatchingSizes(a,b),"Subtract of arrays require arguments of matching size");
  Assert(RealMatchingSizes(res,a),"Subtract of arrays require result of matching size");
  prodsize=RealNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=a.data[i]-b.data[i];
  return res;
}
DYMOLA_STATIC RealArray RealSubtract(const RealArray a,const RealArray b) {
  return RealSubtractAssign(RealMatch(a),a,b);
}
DYMOLA_STATIC RealArray RealScaleAssign(RealArray res,const RealArray a,const Real t) {
  SizeType i,prodsize;
  Assert(RealMatchingSizes(res,a),"Array times scalar require result of matching size");
  prodsize=RealNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=t*a.data[i];
  return res;
}
DYMOLA_STATIC RealArray RealScale(const RealArray a,const Real t) {
  return RealScaleAssign(RealMatch(a),a,t);
}
DYMOLA_STATIC RealArray RealMinusAssign(RealArray res,const RealArray a) {
  SizeType i,prodsize;
  Assert(RealMatchingSizes(res,a),"Negating a matrix require result of matching size");
  prodsize=RealNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=-a.data[i];
  return res;
}
DYMOLA_STATIC RealArray RealMinus(const RealArray a) {
  return RealMinusAssign(RealMatch(a),a);
}
/* sum, max, min, and product */
DYMOLA_STATIC Real Realsum(const RealArray a) {
    Real res=0;
    Integer max_elem=RealNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) res+=a.data[i];
    return res;
}
DYMOLA_STATIC Real RealAbssum(const RealArray a) {
    Real res=0;
    Integer max_elem=RealNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) {
	    Real x=a.data[i];
	    if (x>0) res+=x; else res-=x;
    }
    return res;
}
DYMOLA_STATIC Real RealAbssumDiff(const RealArray a,const RealArray b) {
    Real res=0;
    Integer max_elem=RealNrElements(a);
    Integer i;
	Assert(max_elem==RealNrElements(b),"Diff");
    for(i=0;i<max_elem;i++) {
	    Real xa=a.data[i];
		Real xb=b.data[i];
		Real scale=1+((xa>0)?xa:-xa);
		Real x=(xa-xb)/scale;
	    if (x>0) res+=x; else res-=x;
    }
    return res;
}
DYMOLA_STATIC Real Realmax(const RealArray a) {
    Real res=-DBL_MAX;
    Integer max_elem=RealNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) if (a.data[i]>res) res=a.data[i];
    return res;
}
DYMOLA_STATIC Real Realmin(const RealArray a) {
    Real res=DBL_MAX;
    Integer max_elem=RealNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) if (a.data[i]<res) res=a.data[i];
    return res;
}
DYMOLA_STATIC Real Realproduct(const RealArray a) {
    Real res=1;
    Integer max_elem=RealNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) res*=a.data[i];
    return res;
}

DYMOLA_STATIC RealArray Realdiagonal(const RealArray a) {
    RealArray res;
    Integer i,j,n;
    Assert(a.ndims==1,"diagonal requires vector input");
    n=a.dims[0];
    res=RealTemporaryMatrix(n,n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) res.data[i*n+j]=(i==j)?a.data[i]:0;
    return res;
}

DYMOLA_STATIC RealArray Realcross(const RealArray x,const RealArray y) {
    RealArray res=RealTemporaryVector(3);
    Assert((x.ndims==1)&&(y.ndims==1),"cross requires vector input");
    Assert(x.dims[0]==3,"cross requires 3-vector input for first argument");
    Assert(y.dims[0]==3,"cross requires 3-vector input for second argument");
    res.data[0]=x.data[1]*y.data[2]-x.data[2]*y.data[1];
    res.data[1]=x.data[2]*y.data[0]-x.data[0]*y.data[2];
    res.data[2]=x.data[0]*y.data[1]-x.data[1]*y.data[0];
    return res;
}
DYMOLA_STATIC RealArray Realskew(const RealArray x) {
    RealArray res=RealTemporaryMatrix(3,3);
    Assert(x.ndims==1,"skew requires vector input");
    Assert(x.dims[0]==3,"skew requires 3-vector input");
    SetRealElement(0,res,1,1);
    SetRealElement(-RealElement(x,3),res,1,2);
    SetRealElement(RealElement(x,2),res,1,3);
    SetRealElement(RealElement(x,3),res,2,1);
    SetRealElement(0,res,2,2);
    SetRealElement(-RealElement(x,1),res,2,3);
    SetRealElement(-RealElement(x,2),res,3,1);
    SetRealElement(RealElement(x,1),res,3,2);
    SetRealElement(0,res,3,3);
    return res;
}
/* Multiply */
DYMOLA_STATIC RealArray RealMultiplyMMAssign(RealArray res,
                                     const RealArray a,const RealArray b) {
  SizeType i,j,k,imax,jmax,kmax;
  Assert(res.ndims==2,"Matrix multiply gives a matrix as result");
  Assert(a.ndims==2,"Matrix multiply requires that first operand is a matrix");
  Assert(b.ndims==2,"Matrix multiply requires that second operand is a matrix");
  Assert(res.dims[0]==a.dims[0],"Matrix multiply requires that first dimension of result and first argument match");
  Assert(res.dims[1]==b.dims[1],"Matrix multiply requires that second dimension of result and second argument match");
  Assert(a.dims[1]==b.dims[0],"Matrix multiply requires that inner dimensions of operands match");
  imax=res.dims[0];
  jmax=res.dims[1];
  kmax=a.dims[1];
  for(i=0;i<imax;i++) for(j=0;j<jmax;j++) {
    Real d=0;
    for(k=0;k<kmax;k++) d+=a.data[i*kmax+k]*b.data[k*jmax+j];
    res.data[i*jmax+j]=d;
  }
  return res;
}
DYMOLA_STATIC RealArray RealMultiplyMVAssign(RealArray res,const RealArray a,const RealArray b) {
    SizeType i,j,imax,jmax;
    Assert(a.ndims==2,"Matrix times vector requires a matrix as first operand");
    Assert(b.ndims==1,"Matrix times vector requires a vector as second operand");
    Assert(res.ndims==1,"Matrix times vector gives a vector result");
    Assert(res.dims[0]==a.dims[0],"Matrix times vector: requires size(M*v,1)=size(M,1)");
    Assert(a.dims[1]==b.dims[0],"Matrix times vector: requires size(M,2)==size(v,1)");
    imax=a.dims[0];
    jmax=a.dims[1];
    for(i=0;i<imax;i++) {
	Real d=0;
	for(j=0;j<jmax;j++) d+=a.data[i*jmax+j]*b.data[j];
	res.data[i]=d;
    }
    return res;
}
DYMOLA_STATIC RealArray RealMultiplyVMAssign(RealArray res,const RealArray a,const RealArray b) {
    SizeType i,j,imax,jmax;
    Assert(a.ndims==1,"Vector times matrix requires a vector as first operand");
    Assert(b.ndims==2,"Vector times matrix requires a matrix as second operand");
    Assert(res.ndims==1,"Vector times matrix gives a vector result");
    Assert(res.dims[0]==b.dims[1],"Vector times matrix: requires size(v*M,1)=size(M,2)");
    Assert(a.dims[0]==b.dims[0],"Vector times matrix: requires size(v,1)=size(M,1)");
    imax=b.dims[1];
    jmax=b.dims[0];
    for(i=0;i<imax;i++) {
	Real d=0;
	for(j=0;j<jmax;j++) d+=a.data[j]*b.data[j*imax+i];
	res.data[i]=d;
    }
    return res;
}
DYMOLA_STATIC Real RealMultiplyVV(const RealArray a,const RealArray b) {
    SizeType i,imax;
    Real d=0;
    Assert(a.ndims==1,"Scalar product requires vector as first operand");
    Assert(b.ndims==1,"Scalar product requires vector as second operand");
    Assert(a.dims[0]==b.dims[0],"Scalar product requires vectors of matching size");
    imax=a.dims[0];
    for(i=0;i<imax;i++) d+=a.data[i]*b.data[i];
    return d;
}
DYMOLA_STATIC RealArray RealMultiplyMM(const RealArray a,const RealArray b) {
  return RealMultiplyMMAssign(RealTemporaryMatrix(a.dims[0],b.dims[1]),a,b);
}
DYMOLA_STATIC RealArray RealMultiplyMV(const RealArray a,const RealArray b) {
    return RealMultiplyMVAssign(RealTemporaryVector(a.dims[0]),a,b);
}
DYMOLA_STATIC RealArray RealMultiplyVM(const RealArray a,const RealArray b) {
    return RealMultiplyVMAssign(RealTemporaryVector(b.dims[1]),a,b);
}
DYMOLA_STATIC RealArray RealIdentity(SizeType n) {
    RealArray res;
    Integer i,j;
    res.ndims=2;
    res.dims=SizeTemp(2);
    res.dims[0]=res.dims[1]=n;
    res.data=RealTemp(n*n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) res.data[i*n+j]=(i==j);
    return res;
}
DYMOLA_STATIC RealArray RealPow(const RealArray a,const Integer n) {
    Assert(n>=0,"Matrices can only be raised to positive integer");
    Assert(a.ndims==2,"Matrix raised to a positive integer requires a matrix as first operand");
    Assert(a.dims[0]==a.dims[1],"Matrix raised to a positive integer requires a square matrix as first operand");
    if (n==1) return a;
    else if (n==0) return RealIdentity(a.dims[0]);
    else {
	if (n%2) {
	    return RealMultiplyMM(RealPow(a,n-1),a);
	} else {
	    RealArray ahalf=RealPow(a,n/2);
	    return RealMultiplyMM(ahalf,ahalf);
	}
    }
}
/* For from:stride:to */
DYMOLA_STATIC RealArray RealRange(const Real from,const Real to,const Real stride) {
  Real extraStride=stride;
  Real diff=to-from;
  Real extra=0;
  Integer num;
  Assert(stride!=0,"range requires non-zero stride");
  if (stride<0) {
		diff=-diff;
		extraStride=-extraStride;
	}
	if (extraStride!=floor(extraStride)) {
		extra+=fabs(diff);
	}
	if (diff!=floor(diff)) {
		extra+=fabs(from)+fabs(to);
	}
	num=1+(Integer)floor((diff+extra*1.11022302462516E-016)/extraStride);
  if (num<0) num=0;
  {
    RealArray res=RealTemporaryVector(num);
    Integer i;
    for(i=0;i<num;i++) SetRealElement(from+i*stride,res,i+1);
    return res;
  }
}


/* End of common routines with Integer */
/* Unique routines */

DYMOLA_STATIC RealArray linspace(const Real from,const Real to,const Integer n) {
    RealArray res=RealTemporaryVector(n);
    Integer i;
    Real delta=(to-from)/(n-1);
    Assert(n>=2,"Linspace number of point>=2");
    for(i=0;i<n-1;i++) res.data[i]=from+delta*i;
    res.data[n-1]=to; /* Guard against roundoff errors.*/
    return res;
}

/* Go from IntegerArray to RealArray */
DYMOLA_STATIC RealArray RealConvertInteger(const IntegerArray a) {
  RealArray res;
  SizeType i,n;
  res.ndims=a.ndims;
  res.dims=a.dims;
  n=CommonNrElements(res.ndims, res.dims);
  res.data=RealTemp(n);
  for(i=0;i<n;i++) res.data[i]=a.data[i];
  return res;
}
DYMOLA_STATIC IntegerArray IntegerConvertReal(const RealArray a) {
  IntegerArray res;
  SizeType i,n;
  res.ndims=a.ndims;
  res.dims=a.dims;
  n=CommonNrElements(res.ndims, res.dims);
  res.data=IntegerTemp(n);
  for(i=0;i<n;i++) res.data[i]=real2integer(a.data[i]);
  return res;
}
/* Routines for moutil.h */
#if 0 && !defined(LINALG_PACK)
#error
#endif
DYMOLA_STATIC RealArray RealInverse(const RealArray A) {
	Assert(A.ndims==2,"Can only invert matrices");
	Assert(A.dims[0]==A.dims[1],"Can only invert square matrices");
	{
		RealArray Ainv=RealMatch(A);
		MarkObject returnMark=PushMark();
		Real*RWork=RealTemp(A.dims[0]*A.dims[0]+4+6*A.dims[0]);
		Integer*IWork=IntegerTemp(A.dims[0]*2+1);
		SizeType i1,i2,i3,i4,i,j,Ev=0;
		SizeType Factored=0,IError=0;
		i1 = A.dims[0];
		i2 = A.dims[1];
		i3 = 0;
		i4 = 3;
		for(i=0;i<A.dims[0];++i) {
			double T=0;
			double*b=Ainv.data+i*A.dims[0];
			for(j=0;j<A.dims[0];++j) b[j]=0;
			b[i]=1;
			dymli2_(&i3,&i4,A.data,&i1,&i2,b,
				&T,&Ev,&Ev,RWork,IWork,&Factored,&IError);
			if (IError!=0 && A.dims[0]==1) {
				Ainv.data[0]=0;
				IError=0;
			}
			Assert(IError==0,"Inverse failed");
		}
		PopMark(returnMark);
		return Ainv;
	}
}
DYMOLA_STATIC RealArray RealScaleDiv(const RealArray a,const Real t) {
    Assert(t!=0,"Division by zero in function RealScaleDiv");
    return RealScaleAssign(RealMatch(a),a,1/t);
}
/* Routines for Integer */
/* Test for size compatibility, used in assertions */
DYMOLA_STATIC Integer IntegerMatchingSizes(const IntegerArray a,const IntegerArray b) {
  SizeType i;
  if (a.ndims!=b.ndims) return 0;
  for(i=0;i<a.ndims;i++) {if(a.dims[i]!=b.dims[i]) return 0;}
  return 1;
}
/* Return total number of elements */
DYMOLA_STATIC SizeType IntegerNrElements(const IntegerArray a) {
  SizeType prodsize=1;
  SizeType i;
  for(i=0;i<a.ndims;i++) prodsize*=a.dims[i];
  return prodsize;
}
/* Create Array-temporaries given the dimensions */
/*  Internal: Use an existing va_list */
DYMOLA_STATIC IntegerArray IntegerVaTemporarySize(SizeType ndims,va_list ap) {
  IntegerArray temp;
  SizeType i;
  temp.ndims=ndims;
  temp.dims=SizeTemp(ndims);
  for(i=0;i<ndims;i++) temp.dims[i]=va_arg(ap,SizeType);
  return temp;
}
DYMOLA_STATIC IntegerArray IntegerVaTemporary(SizeType ndims,va_list ap) {
    IntegerArray temp=IntegerVaTemporarySize(ndims,ap);
    temp.data=IntegerTemp(IntegerNrElements(temp));
    return temp;
}
/*  Construct a temporary of the same size as a */
DYMOLA_STATIC IntegerArray IntegerMatch(const IntegerArray a) {
  IntegerArray temp;
  SizeType i;
  temp.ndims=a.ndims;
  temp.dims=SizeTemp(a.ndims);
  for(i=0;i<a.ndims;i++) temp.dims[i]=a.dims[i];
  temp.data=IntegerTemp(IntegerNrElements(a));
  return temp;
}
/* Construct array from sizes, using variable number of arguments */
DYMOLA_STATIC IntegerArray IntegerTemporary(SizeType ndims,...) {
  IntegerArray temp;
  va_list ap;
  va_start(ap,ndims);
  temp=IntegerVaTemporary(ndims,ap);
  va_end(ap);
  return temp;
}
/* Special cases for vectors and matrices (most often used) */
DYMOLA_STATIC IntegerArray IntegerTemporaryMatrix(SizeType r,SizeType c) {
  IntegerArray temp;
  temp.ndims=2;
  temp.dims=SizeTemp(2);
  temp.dims[0]=r;temp.dims[1]=c;
  temp.data=IntegerTemp(r*c);
  return temp;
}
DYMOLA_STATIC IntegerArray IntegerTemporaryVector(SizeType r) {
  IntegerArray temp;
  temp.ndims=1;
  temp.dims=SizeTemp(1);
  temp.dims[0]=r;
  temp.data=IntegerTemp(r);
  return temp;
}
/* Assignment */
DYMOLA_STATIC void IntegerAssign(IntegerArray a,const IntegerArray b) {
  SizeType prodsize=IntegerNrElements(a);
  SizeType i;
  Assert(IntegerMatchingSizes(a,b),"Array dimensions did not match");
  for(i=0;i<prodsize;i++) a.data[i]=b.data[i];
}
/* Indexing to set/get elements */

DYMOLA_STATIC Integer IntegerElement(const IntegerArray a,...) {
  SizeType index;
  va_list ap;
  va_start(ap,a);
  index=FindIndex(a.ndims,a.dims,ap);
  va_end(ap);
  return a.data[index];
}
/* Sizes */
DYMOLA_STATIC Integer IntegerSize(const IntegerArray a,SizeType i) {
    Assert((i>=1)&&(i<=a.ndims),"Size must be between 1 and ndims of array");
    return a.dims[i-1];
}
DYMOLA_STATIC IntegerArray IntegerSizes(const IntegerArray a) {
    IntegerArray res;
    Integer i;
    res.ndims=1;
    res.dims=SizeTemp(1);
    res.dims[0]=a.ndims;
    res.data=IntegerTemp(a.ndims);
    for(i=0;i<a.ndims;i++) res.data[i]=a.dims[i];
    return res;
}
/* Set element, note that val is prior to the index list. */
DYMOLA_STATIC void SetIntegerElement(Integer val,IntegerArray a,...) {
  SizeType index;
  va_list ap;
  va_start(ap,a);
  index=FindIndex(a.ndims,a.dims,ap);
  a.data[index]=val;
  va_end(ap);
}
/* For debug write out */
DYMOLA_STATIC void IntegerWrite(const IntegerArray a) {
  SizeType i;
  DymosimMessageInt("Dims: ",a.ndims);
  for(i=0;i<a.ndims;i++) DymosimMessageInt(" ",a.dims[i]);
  for(i=0;i<IntegerNrElements(a);i++) DymosimMessageMatrixElement("",i,1,a.data[i]);
}

/* Construct Arrays from other arrays */
DYMOLA_STATIC IntegerArray IntegerArrayArray(SizeType narg,IntegerArray first,...) {
  IntegerArray res;
  SizeType i,j,prodsize;
  va_list ap;
  res.ndims=first.ndims+1;
  res.dims=SizeTemp(res.ndims);
  res.dims[0]=narg;
  for(i=1;i<res.ndims;i++) res.dims[i]=first.dims[i-1];
  prodsize=IntegerNrElements(first);  
  res.data=IntegerTemp(prodsize*narg);
  va_start(ap,first);
  for(i=0;i<narg;i++) {
    IntegerArray next;
    next=(i!=0)?va_arg(ap,IntegerArray):first;
    Assert(IntegerMatchingSizes(first,next),"Arrays in array must be of equal sizes");
    for(j=0;j<prodsize;j++)
      res.data[i*prodsize+j]=next.data[j];
  }
  va_end(ap);
  return res;
}
/* Construct arrays from scalars */
DYMOLA_STATIC IntegerArray IntegerScalarArray(SizeType narg,...) {
  IntegerArray res;
  SizeType i;
  va_list ap;
  res=IntegerTemporaryVector(narg);
  va_start(ap,narg);
  for(i=0;i<narg;i++) {
    res.data[i]=va_arg(ap,Integer);
  }
  va_end(ap);
  return res;
}

/* Get/Put of submatrices, i.e. a[i,:,v,1:4] */

/* Actual get of a submatrix */
DYMOLA_STATIC void IntegerFromSub(IntegerArray to,SizeType to_offset,SizeType to_dim,
              const IntegerArray from,SizeType from_offset,SizeType from_dim,
              SizeType trailingsize,
			  struct TaggedIndexStack*ap) {
  Integer tag;
  if (!ap) return; /* Error */
  tag=ap->tag;
  switch(tag) {
  case Colon:
    {
      SizeType newdim=from.dims[from_dim];
      SizeType i;
      for(i=0;i<newdim;i++) IntegerFromSub(to,to_offset*newdim+i,
        to_dim+1,from,from_offset*newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Range:case RangeRange:
    {
      Integer start,stop,stride=1,i,from_newdim,to_newdim;
      start=ap->u.range[0];
      if (tag==RangeRange) stride=ap->u.range[1];
      stop=ap->u.range[2];
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<to_newdim;i++) 
        IntegerFromSub(to,to_offset*to_newdim+i,to_dim+1,
        from,from_offset*from_newdim+(start+stride*i-1),from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Index:
    {
      Integer i=ap->u.index;
      IntegerFromSub(to,to_offset,to_dim,
        from,from_offset*from.dims[from_dim]+i-1,from_dim+1,trailingsize,ap+1);
      break;
    }
  case Vector:
    {
      IntegerArray v=ap->u.vector;
      Integer from_newdim,to_newdim,i;
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<v.dims[0];i++)
        IntegerFromSub(to,to_offset*to_newdim+i,to_dim+1,
        from,from_offset*from_newdim+v.data[i]-1,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case EndMark:
    {
      SizeType i;
      Integer *to_p=to.data+to_offset;
      Integer *from_p=from.data+from_offset;
      for(i=0;i<trailingsize;i++,to_p+=1,from_p+=1) *to_p=*from_p;
      break;
    }
  }
}
/* Concatenate along dimensions 'along' (1..ndims) and given nargs arguments */
DYMOLA_STATIC IntegerArray IntegerCat(SizeType along,SizeType nargs,IntegerArray first,...) {
  IntegerArray res;
  va_list ap;
  SizeType i,j;
  res.ndims=first.ndims;
  res.dims=SizeTemp(res.ndims);
  along--; /* Adapt to C usage */
  {
    /* Pass 1: determine size of output */
    for(j=0;j<first.ndims;j++) res.dims[j]=first.dims[j]; /* Starting values */
    va_start(ap,first);
    for(i=1;i<nargs;i++) {
      IntegerArray a;
      a=va_arg(ap,IntegerArray);
      Assert(a.ndims==first.ndims,"Number of dimensions must match for cat");
      for(j=0;j<a.ndims;j++) if (j!=along) {Assert(first.dims[j]==a.dims[j],"Sizes must match for cat");}
      res.dims[along]+=a.dims[along];
    }
    va_end(ap);
  }
  res.data=IntegerTemp(CommonNrElements(res.ndims, res.dims));
  {
    /* Pass 2: copy data */
    SizeType presize=1;      /* Blocks */
    SizeType trailingsize=1; /* Elements in each block */
    SizeType marker=0; /* How far are in res along dimension along */
    for(i=0;i<along;i++) presize*=res.dims[i];
    for(i=along+1;i<res.ndims;i++) trailingsize*=res.dims[i];
    va_start(ap,first);
    for(i=0;i<nargs;i++) {
      SizeType pre,current,trailing;
      IntegerArray a;
      if (i!=0) a=va_arg(ap,IntegerArray); else a=first;
      for(pre=0;pre<presize;pre++) 
        for(current=0;current<a.dims[along];current++)
          for(trailing=0;trailing<trailingsize;trailing++)
            res.data[(pre*res.dims[along]+(current+marker))*trailingsize+trailing]=
            a.data[(pre*a.dims[along]+current)*trailingsize+trailing];
      marker+=a.dims[along];
    }
    va_end(ap);
  }
  return res;
}

/* The helper in Modelica */
DYMOLA_STATIC IntegerArray IntegerPromote(const IntegerArray a,SizeType n) {
  IntegerArray res;
  SizeType i;
  Assert(n>=a.ndims,"Promote cannot decrease number of dimensions");
  res.ndims=n;
  res.data=a.data; /* No need to copy */
  res.dims=SizeTemp(n);
  for(i=0;i<a.ndims;i++) res.dims[i]=a.dims[i];
  for(i=a.ndims;i<n;i++) res.dims[i]=1;
  return res;
}
DYMOLA_STATIC IntegerArray IntegerPromoteScalar(const Integer x,SizeType n) {
    IntegerArray res;
    Integer i;
    res.ndims=n;
    res.data=IntegerTemp(1);
    res.data[0]=x;
    res.dims=SizeTemp(n);
    for(i=0;i<n;i++) res.dims[i]=1;
    return res;
}
/* Actual put of submatrix */
DYMOLA_STATIC void IntegerToSub(IntegerArray to,SizeType to_offset,SizeType to_dim,
              const IntegerArray from,SizeType from_offset,SizeType from_dim,
              SizeType trailingsize,
			  struct TaggedIndexStack*ap) {
  Integer tag;
  if (!ap) return; /* Error */
  tag=ap->tag;
  switch(tag) {
  case Colon:
    {
      SizeType newdim=from.dims[from_dim];
      SizeType i;
      for(i=0;i<newdim;i++) IntegerToSub(to,to_offset*newdim+i,
        to_dim+1,from,from_offset*newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Range:case RangeRange:
    {
      Integer start,stop,stride=1,i,from_newdim,to_newdim;
      start=ap->u.range[0];
      if (tag==RangeRange) stride=ap->u.range[1];
      stop=ap->u.range[2];
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<from_newdim;i++) 
        IntegerToSub(to,to_offset*to_newdim+(start+stride*i-1),to_dim+1,
        from,from_offset*from_newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Index:
    {
      Integer i=ap->u.index;
      IntegerToSub(to,to_offset*to.dims[to_dim]+(i-1),to_dim+1,
        from,from_offset,from_dim,trailingsize,ap+1);
      break;
    }    
  case Vector:
    {
      IntegerArray v=ap->u.vector;
      Integer from_newdim,to_newdim,i;
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<v.dims[0];i++)
        IntegerToSub(to,to_offset*to_newdim+(v.data[i]-1),to_dim+1,
        from,from_offset*from_newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case EndMark:
    {
      SizeType i;
      Integer *to_p=to.data+to_offset;
      Integer *from_p=from.data+from_offset;
      for(i=0;i<trailingsize;i++,to_p+=1,from_p+=1) *to_p=*from_p;
      break;
    }
  }
}
/* Use as: IntegerGetSub(a,Colon,Index,3,Range,3,4,EndMark)=a[:,3,3:4] */
DYMOLA_STATIC IntegerArray IntegerGetSub(const IntegerArray a,...) {
  IntegerArray temp;
  va_list ap;
  SizeType ndims=a.ndims,trailingsize=1,nargs=0;
  /* Pass 1. Determine nr. dimensions of output */
  {
    Integer over=0;
    va_start(ap,a);
    for(;!over;) {
      Integer tag=va_arg(ap,Integer);
      switch (tag) {
      case Colon:nargs++;break;
      case RangeRange:va_arg(ap,Integer); /* Fallthru*/
      case Range:va_arg(ap,Integer),va_arg(ap,Integer);nargs++;break;
      case Vector:va_arg(ap,IntegerArray);nargs++;break;
      case Index:va_arg(ap,Integer);Assert(ndims>0,"Internal error in subscriptring of array");ndims--;nargs++;break;
      case EndMark:over=1;break;
      }
    }
    va_end(ap);
    Assert(nargs<=a.ndims,"Too many subscripts for array");

  }
  temp.ndims=ndims;
  temp.dims=SizeTemp(ndims);
  /* Pass 2. Determine size of output */
  {
    Integer over=0;
    SizeType temp_dim=0,a_dim=0;
    va_start(ap,a);
    for(;!over;) {
      Integer tag=va_arg(ap,Integer);
      switch (tag) {
      case Colon:temp.dims[temp_dim]=a.dims[a_dim];temp_dim++;break;
      case RangeRange:case Range:
        {
          Integer start,stop,stride=1,num;
          start=va_arg(ap,Integer);
          if (tag==RangeRange) stride=va_arg(ap,Integer);
          stop=va_arg(ap,Integer);
          num=1+(stop-start)/stride;
          if (num<=0) num=0;
          else {
            Assert((start>=1)&&(start<=a.dims[a_dim]),"Range subscripting: start out of range");
            Assert((stop >=1)&&(stop <=a.dims[a_dim]),"Range subscripting: end out of range");
          }
          temp.dims[temp_dim]=num;
          temp_dim++;
          break;
        }
      case Vector:
        {
          IntegerArray v=va_arg(ap,IntegerArray);
          SizeType i;
          Assert(v.ndims==1,"Array subscripting: only vectors (and scalars) allowed as indicies");
          temp.dims[temp_dim]=v.dims[0];
          for(i=0;i<v.dims[0];i++) {
		  Assert((v.data[i]>=1)&&(v.data[i]<=a.dims[a_dim]),"Array subscripting: vector index out of range");
	  }
          temp_dim++;
          break;
        }
      case Index:
        {
          Integer i=va_arg(ap,Integer);
          Assert((i>=1)&&(i<=a.dims[a_dim]),"Array subscripting: scalar index out of range");
          break;
        }
      case EndMark:over=1;break;
      }
      a_dim++;
    }
    va_end(ap);    
    {
      SizeType i;
      for(i=nargs;i<a.ndims;i++) {
        temp.dims[temp_dim++]=a.dims[i];
        trailingsize*=a.dims[i];
      }
    }
  }
  temp.data=IntegerTemp(CommonNrElements(temp.ndims, temp.dims));
  /* Pass 3. Copy output */
  {
	struct TaggedIndexStack*apt=0;
	struct TaggedIndexStack VA_handler[100];
    va_start(ap,a);
	apt=HandleVaList(ap, VA_handler, sizeof(VA_handler)/sizeof(*VA_handler));
	va_end(ap);
    IntegerFromSub(temp,0,0,a,0,0,trailingsize,apt);
  }
  return temp;
}
/* Use as IntegerPutSub(a, out,Index,3,Colon,Range,3,4) yields out[3,:,3:4]=a; */
DYMOLA_STATIC IntegerArray IntegerCopy(const IntegerArray a) {
	int i,imax;
	IntegerArray temp;
	temp.ndims=a.ndims;
	temp.dims=SizeTemp(a.ndims);
	for(i=0;i<a.ndims;++i) temp.dims[i]=a.dims[i];
	imax=IntegerNrElements(a);
	temp.data=IntegerTemp(imax);
	for(i=0;i<imax;++i) temp.data[i]=a.data[i];
	return temp;
}
DYMOLA_STATIC void IntegerPutSub(const IntegerArray ain,IntegerArray out,...) {
  IntegerArray a;
  va_list ap;
  SizeType out_dim=0,a_dim=0,trailingsize=1,nargs=0;
  a=IntegerCopy(ain);
  /* Pass 1. Determine nr. dimensions of output */
  {
    Integer over=0;
    va_start(ap,out);
    for(;!over;) {
      Integer tag=va_arg(ap,Integer);
      switch (tag) {
      case Colon:
        Assert(out_dim<out.ndims,"Internal error in subscripting (:)");
        Assert(a_dim<a.ndims,"Internal error in subscripting (:)");
        Assert(out.dims[out_dim]==a.dims[a_dim],"Assignment array subscripting: A[:]=B must have identical sizes");
        out_dim++;
        a_dim++;
        break;
      case RangeRange:case Range:
        {
          Integer start,stop,stride=1,num;
          Assert(out_dim<out.ndims,"Internal error in subscripting: range");
          Assert(a_dim<a.ndims,"Internal error in subscripting: range ");
          start=va_arg(ap,Integer);
          if (tag==RangeRange) stride=va_arg(ap,Integer);
          stop=va_arg(ap,Integer);
          num=(stop-start+stride)/stride;
          if (num<=0) num=0;
          else {
            Assert((start>=1)&&(start<=out.dims[out_dim]),"Assignment array subscripting: start of range out of bounds");
            Assert((stop>=1)&&(stop<=out.dims[out_dim]),"Assignment array subscripting: end of range out of bounds");
          }
          Assert(a.dims[a_dim]==num,"Assignment array subscripting: A[a:b]=B must have identical sizes");
          out_dim++;
          a_dim++;
          break;
        }
      case Vector:
        {
          IntegerArray v=va_arg(ap,IntegerArray);
          SizeType i;
          Assert(out_dim<out.ndims,"Internal error in vector subscripting");
          Assert(a_dim<a.ndims,"Internal error in vector subscripting");
          Assert(v.ndims==1,"Assignment array subscripting: array index must be a vector");
          Assert(a.dims[a_dim]==v.dims[0],"Assignment array subscripting: A[vect]=B must have identical sizes");
          for(i=0;i<v.dims[0];i++) {
		  Assert((v.data[i]>=1)&&(v.data[i]<=out.dims[out_dim]),"Assignment array subscripting: vector index out of bounds");
	  }
          out_dim++;
          a_dim++;
          break;
        }
      case Index:
        {
          Integer i=va_arg(ap,Integer);
          Assert(out_dim<out.ndims,"Internal error in scalar subscripting");
          Assert((i>=1)&&(i<=out.dims[out_dim]),"Assignment array subscripting: scalar index out of bounds");
          out_dim++;
          break;
        }
      case EndMark:over=1;break;
      }
    }
    va_end(ap);
    Assert(a.ndims-a_dim==out.ndims-out_dim,"Assignment array subscripting: unequal number of dimensions");
    {
      SizeType i;
      for(i=a_dim;i<a.ndims;i++) {
        trailingsize*=a.dims[i];
        Assert(a.dims[i]==out.dims[(i-a_dim)+out_dim],"Internal error in subscripting");
      }
    }
  }
  /* Pass 2. Copy output */
  {
	struct TaggedIndexStack*apt=0;
	struct TaggedIndexStack VA_handler[100];
	va_start(ap,out);
	apt=HandleVaList(ap, VA_handler, sizeof(VA_handler)/sizeof(*VA_handler));
	va_end(ap);
    IntegerToSub(out,0,0,a,0,0,trailingsize,apt);
  }
}

/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
/* Fill */
DYMOLA_STATIC IntegerArray IntegerFillAssign(IntegerArray res,const Integer t) {
  SizeType i,prodsize;
  prodsize=IntegerNrElements(res);
  for(i=0;i<prodsize;i++) res.data[i]=t;
  return res;
}
DYMOLA_STATIC IntegerArray IntegerFill(const Integer t,SizeType ndims,...) {
  va_list ap;
  IntegerArray temp;
  va_start(ap,ndims);
  temp=IntegerFillAssign(IntegerVaTemporary(ndims,ap),t);
  va_end(ap);
  return temp;
}
DYMOLA_STATIC IntegerArray IntegerFillArray(const IntegerArray a,SizeType ndims,...) {
	va_list ap;
	int i,j,inputProd,fillProd;
	IntegerArray temp;
	temp.ndims=a.ndims+ndims;
	temp.dims=SizeTemp(temp.ndims);

	va_start(ap,ndims);
	for(i=0;i<ndims;++i) temp.dims[i]=va_arg(ap,SizeType);
	va_end(ap);
	for(i=0;i<a.ndims;++i) temp.dims[i+ndims]=a.dims[i];

	fillProd=1;
	for(i=0;i<ndims;++i) fillProd*=temp.dims[i];
	inputProd=IntegerNrElements(a);

	temp.data=IntegerTemp(inputProd*fillProd);
	for(i=0;i<inputProd;++i) {
		for(j=0;j<fillProd;j++) {
		  temp.data[i+j*inputProd]=a.data[i];
		}
	}
	return temp;
}

DYMOLA_STATIC Integer Integerscalar(const IntegerArray a) {
    Assert(IntegerNrElements(a)==1,"scalar requires exactly one element");
    return a.data[0];
}
/* Matrix operations not limited to numeric matrices */
DYMOLA_STATIC IntegerArray Integervector(const IntegerArray a) {
    IntegerArray res;
#ifndef NDEBUG
    Integer i,found_non_one=0;
    for(i=0;i<a.ndims;i++) {if (a.dims[i]>1) {Assert(!found_non_one,"vector requires exactly one vector non-unit dimension");found_non_one=1;}}
#endif
    res.ndims=1;
    res.dims=SizeTemp(1);
    res.dims[0]=IntegerNrElements(a);
    res.data=a.data;
    return res;
}
DYMOLA_STATIC IntegerArray Integermatrix(const IntegerArray a) {
    IntegerArray res;
    res.ndims=2;
    res.dims=SizeTemp(2);
    res.dims[0]=a.dims[0];
    res.dims[1]=(a.ndims<2)?1:a.dims[1];
    res.data=a.data;
    Assert(IntegerNrElements(a)==IntegerNrElements(res),"matrix requires size(x,i)=1 for i>2");
    return res;
}
DYMOLA_STATIC IntegerArray Integertranspose(const IntegerArray a) {
    IntegerArray res;
    Integer i,j,k,remsize;
    res.ndims=a.ndims;
    Assert(a.ndims>=2,"transpose requires ndims>=2");
    res.dims=SizeTemp(a.ndims);
    res.dims[0]=a.dims[1];
    res.dims[1]=a.dims[0];
    remsize=1;
    for(i=2;i<a.ndims;i++) {
	remsize*=(res.dims[i]=a.dims[i]);
    }
    res.data=IntegerTemp(CommonNrElements(res.ndims, res.dims));
    for(i=0;i<res.dims[0];i++) for(j=0;j<res.dims[1];j++) {
	for(k=0;k<remsize;k++) {
	    res.data[(i*res.dims[1]+j)*remsize+k]=a.data[(j*a.dims[1]+i)*remsize+k];
	}
    }
    return res;
}
DYMOLA_STATIC IntegerArray Integerouterproduct(const IntegerArray a,const IntegerArray b) {
    Assert(a.ndims==1,"Outerproduct require a vector as first argument");
    Assert(b.ndims==1,"Outerproduct require a vector as second argument");
    {
	    SizeType na=a.dims[0],nb=b.dims[0];
	    SizeType i,j;
	    IntegerArray res=IntegerTemporaryMatrix(na,nb);
	    for(i=0;i<na;i++) {
		    Integer ai=a.data[i];
		    for(j=0;j<nb;j++) 
			    res.data[i*nb+j]=ai*b.data[j];
	    }
	    return res;
    }
}
DYMOLA_STATIC IntegerArray Integersymmetric(const IntegerArray a) {
    IntegerArray res;
    Integer i,j,n=a.dims[0];
    Assert(a.ndims==2,"symmetric requires ndims==2");
    Assert(a.dims[0]==a.dims[1],"symmetric requires square matrix");
    res=IntegerTemporaryMatrix(n,n);
    for(i=0;i<n;i++) {
	for(j=0;j<=i;j++) res.data[i*n+j]=a.data[j*n+i];
	for(;j<n;j++) res.data[i*n+j]=a.data[i*n+j];
    }
    return res;
}
/* End of common routines for String*/
/* Basic operations, add, subtract, scale*/
/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
DYMOLA_STATIC IntegerArray IntegerAddAssign(IntegerArray res,const IntegerArray a,const IntegerArray b) {
  SizeType prodsize,i;
  Assert(IntegerMatchingSizes(a,b),"Add of arrays require arguments of matching size");
  Assert(IntegerMatchingSizes(res,a),"Add of arrays require result of matching size");
  prodsize=IntegerNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=a.data[i]+b.data[i];
  return res;
}
DYMOLA_STATIC IntegerArray IntegerAdd(const IntegerArray a,const IntegerArray b) {
  return IntegerAddAssign(IntegerMatch(a),a,b);
}
DYMOLA_STATIC IntegerArray IntegerSubtractAssign(IntegerArray res,const IntegerArray a,const IntegerArray b) {
  SizeType prodsize,i;
  Assert(IntegerMatchingSizes(a,b),"Subtract of arrays require arguments of matching size");
  Assert(IntegerMatchingSizes(res,a),"Subtract of arrays require result of matching size");
  prodsize=IntegerNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=a.data[i]-b.data[i];
  return res;
}
DYMOLA_STATIC IntegerArray IntegerSubtract(const IntegerArray a,const IntegerArray b) {
  return IntegerSubtractAssign(IntegerMatch(a),a,b);
}
DYMOLA_STATIC IntegerArray IntegerScaleAssign(IntegerArray res,const IntegerArray a,const Integer t) {
  SizeType i,prodsize;
  Assert(IntegerMatchingSizes(res,a),"Array times scalar require result of matching size");
  prodsize=IntegerNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=t*a.data[i];
  return res;
}
DYMOLA_STATIC IntegerArray IntegerScale(const IntegerArray a,const Integer t) {
  return IntegerScaleAssign(IntegerMatch(a),a,t);
}
DYMOLA_STATIC IntegerArray IntegerMinusAssign(IntegerArray res,const IntegerArray a) {
  SizeType i,prodsize;
  Assert(IntegerMatchingSizes(res,a),"Negating a matrix require result of matching size");
  prodsize=IntegerNrElements(a);
  for(i=0;i<prodsize;i++) res.data[i]=-a.data[i];
  return res;
}
DYMOLA_STATIC IntegerArray IntegerMinus(const IntegerArray a) {
  return IntegerMinusAssign(IntegerMatch(a),a);
}
/* sum, max, min, and product */
DYMOLA_STATIC Integer Integersum(const IntegerArray a) {
    Integer res=0;
    Integer max_elem=IntegerNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) res+=a.data[i];
    return res;
}
DYMOLA_STATIC Integer IntegerAbssum(const IntegerArray a) {
    Integer res=0;
    Integer max_elem=IntegerNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) {
	    Integer x=a.data[i];
	    if (x>0) res+=x; else res-=x;
    }
    return res;
}
DYMOLA_STATIC Integer Integermax(const IntegerArray a) {
    Integer res=INT_MIN;
    Integer max_elem=IntegerNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) if (a.data[i]>res) res=a.data[i];
    return res;
}
DYMOLA_STATIC Integer Integermin(const IntegerArray a) {
    Integer res=INT_MAX;
    Integer max_elem=IntegerNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) if (a.data[i]<res) res=a.data[i];
    return res;
}
DYMOLA_STATIC Integer Integerproduct(const IntegerArray a) {
    Integer res=1;
    Integer max_elem=IntegerNrElements(a);
    Integer i;
    for(i=0;i<max_elem;i++) res*=a.data[i];
    return res;
}

DYMOLA_STATIC IntegerArray Integerdiagonal(const IntegerArray a) {
    IntegerArray res;
    Integer i,j,n;
    Assert(a.ndims==1,"diagonal requires vector input");
    n=a.dims[0];
    res=IntegerTemporaryMatrix(n,n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) res.data[i*n+j]=(i==j)?a.data[i]:0;
    return res;
}

DYMOLA_STATIC IntegerArray Integercross(const IntegerArray x,const IntegerArray y) {
    IntegerArray res=IntegerTemporaryVector(3);
    Assert((x.ndims==1)&&(y.ndims==1),"cross requires vector input");
    Assert(x.dims[0]==3,"cross requires 3-vector input for first argument");
    Assert(y.dims[0]==3,"cross requires 3-vector input for second argument");
    res.data[0]=x.data[1]*y.data[2]-x.data[2]*y.data[1];
    res.data[1]=x.data[2]*y.data[0]-x.data[0]*y.data[2];
    res.data[2]=x.data[0]*y.data[1]-x.data[1]*y.data[0];
    return res;
}
DYMOLA_STATIC IntegerArray Integerskew(const IntegerArray x) {
    IntegerArray res=IntegerTemporaryMatrix(3,3);
    Assert(x.ndims==1,"skew requires vector input");
    Assert(x.dims[0]==3,"skew requires 3-vector input");
    SetIntegerElement(0,res,1,1);
    SetIntegerElement(-IntegerElement(x,3),res,1,2);
    SetIntegerElement(IntegerElement(x,2),res,1,3);
    SetIntegerElement(IntegerElement(x,3),res,2,1);
    SetIntegerElement(0,res,2,2);
    SetIntegerElement(-IntegerElement(x,1),res,2,3);
    SetIntegerElement(-IntegerElement(x,2),res,3,1);
    SetIntegerElement(IntegerElement(x,1),res,3,2);
    SetIntegerElement(0,res,3,3);
    return res;
}
/* Multiply */
DYMOLA_STATIC IntegerArray IntegerMultiplyMMAssign(IntegerArray res,
                                     const IntegerArray a,const IntegerArray b) {
  SizeType i,j,k,imax,jmax,kmax;
  Assert(res.ndims==2,"Matrix multiply gives a matrix as result");
  Assert(a.ndims==2,"Matrix multiply requires that first operand is a matrix");
  Assert(b.ndims==2,"Matrix multiply requires that second operand is a matrix");
  Assert(res.dims[0]==a.dims[0],"Matrix multiply requires that first dimension of result and first argument match");
  Assert(res.dims[1]==b.dims[1],"Matrix multiply requires that second dimension of result and second argument match");
  Assert(a.dims[1]==b.dims[0],"Matrix multiply requires that inner dimensions of operands match");
  imax=res.dims[0];
  jmax=res.dims[1];
  kmax=a.dims[1];
  for(i=0;i<imax;i++) for(j=0;j<jmax;j++) {
    Integer d=0;
    for(k=0;k<kmax;k++) d+=a.data[i*kmax+k]*b.data[k*jmax+j];
    res.data[i*jmax+j]=d;
  }
  return res;
}
DYMOLA_STATIC IntegerArray IntegerMultiplyMVAssign(IntegerArray res,const IntegerArray a,const IntegerArray b) {
    SizeType i,j,imax,jmax;
    Assert(a.ndims==2,"Matrix times vector requires a matrix as first operand");
    Assert(b.ndims==1,"Matrix times vector requires a vector as second operand");
    Assert(res.ndims==1,"Matrix times vector gives a vector result");
    Assert(res.dims[0]==a.dims[0],"Matrix times vector: requires size(M*v,1)=size(M,1)");
    Assert(a.dims[1]==b.dims[0],"Matrix times vector: requires size(M,2)==size(v,1)");
    imax=a.dims[0];
    jmax=a.dims[1];
    for(i=0;i<imax;i++) {
	Integer d=0;
	for(j=0;j<jmax;j++) {
	    d+=a.data[i*jmax+j]*b.data[j];
	}
	res.data[i]=d;
    }
    return res;
}
DYMOLA_STATIC IntegerArray IntegerMultiplyVMAssign(IntegerArray res,const IntegerArray a,const IntegerArray b) {
    SizeType i,j,imax,jmax;
    Assert(a.ndims==1,"Vector times matrix requires a vector as first operand");
    Assert(b.ndims==2,"Vector times matrix requires a matrix as second operand");
    Assert(res.ndims==1,"Vector times matrix gives a vector result");
    Assert(res.dims[0]==b.dims[1],"Vector times matrix: requires size(v*M,1)=size(M,2)");
    Assert(a.dims[0]==b.dims[0],"Vector times matrix: requires size(v,1)=size(M,1)");
    imax=b.dims[1];
    jmax=b.dims[0];
    for(i=0;i<imax;i++) {
	Integer d=0;
	for(j=0;j<jmax;j++) {
	    d+=a.data[j]*b.data[j*imax+i];
	}
	res.data[i]=d;
    }
    return res;
}
DYMOLA_STATIC Integer IntegerMultiplyVV(const IntegerArray a,const IntegerArray b) {
    SizeType i,imax;
    Integer d=0;
    Assert(a.ndims==1,"Scalar product requires vector as first operand");
    Assert(b.ndims==1,"Scalar product requires vector as second operand");
    Assert(a.dims[0]==b.dims[0],"Scalar product requires vectors of matching size");
    imax=a.dims[0];
    for(i=0;i<imax;i++) d+=a.data[i]*b.data[i];
    return d;
}
DYMOLA_STATIC IntegerArray IntegerMultiplyMM(const IntegerArray a,const IntegerArray b) {
  return IntegerMultiplyMMAssign(IntegerTemporaryMatrix(a.dims[0],b.dims[1]),a,b);
}
DYMOLA_STATIC IntegerArray IntegerMultiplyMV(const IntegerArray a,const IntegerArray b) {
    return IntegerMultiplyMVAssign(IntegerTemporaryVector(a.dims[0]),a,b);
}
DYMOLA_STATIC IntegerArray IntegerMultiplyVM(const IntegerArray a,const IntegerArray b) {
    return IntegerMultiplyVMAssign(IntegerTemporaryVector(b.dims[1]),a,b);
}
DYMOLA_STATIC IntegerArray IntegerIdentity(SizeType n) {
    IntegerArray res;
    Integer i,j;
    res.ndims=2;
    res.dims=SizeTemp(2);
    res.dims[0]=res.dims[1]=n;
    res.data=IntegerTemp(n*n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) res.data[i*n+j]=(i==j);
    return res;
}
DYMOLA_STATIC IntegerArray IntegerPow(const IntegerArray a,const Integer n) {
    Assert(n>=0,"Matrices can only be raised to positive integer");
    Assert(a.ndims==2,"Matrix raised to a positive integer requires a matrix as first operand");
    Assert(a.dims[0]==a.dims[1],"Matrix raised to a positive integer requires a square matrix as first operand");
    if (n==1) return a;
    else if (n==0) return IntegerIdentity(a.dims[0]);
    else {
	if (n%2) {
	    return IntegerMultiplyMM(IntegerPow(a,n-1),a);
	} else {
	    IntegerArray ahalf=IntegerPow(a,n/2);
	    return IntegerMultiplyMM(ahalf,ahalf);
	}
    }
}
/* For from:stride:to */
DYMOLA_STATIC IntegerArray IntegerRange(const Integer from,const Integer to,const Integer stride) {
  Integer num;
  Assert(stride!=0,"range requires non-zero stride");
  num=(Integer)floor((to-from)*1.0/stride)+1;
  if (num<0) num=0;
  {
    IntegerArray res=IntegerTemporaryVector(num);
    Integer i;
    for(i=0;i<num;i++) SetIntegerElement(from+i*stride,res,i+1);
    return res;
  }
}

/* Test for size compatibility, used in assertions */
DYMOLA_STATIC Integer StringMatchingSizes(const StringArray a,const StringArray b) {
  SizeType i;
  if (a.ndims!=b.ndims) return 0;
  for(i=0;i<a.ndims;i++) {if(a.dims[i]!=b.dims[i]) return 0;}
  return 1;
}
/* Return total number of elements */
DYMOLA_STATIC SizeType StringNrElements(const StringArray a) {
  SizeType prodsize=1;
  SizeType i;
  for(i=0;i<a.ndims;i++) prodsize*=a.dims[i];
  return prodsize;
}
/* Create Array-temporaries given the dimensions */
/*  Internal: Use an existing va_list */
DYMOLA_STATIC StringArray StringVaTemporarySize(SizeType ndims,va_list ap) {
  StringArray temp;
  SizeType i;
  temp.ndims=ndims;
  temp.dims=SizeTemp(ndims);
  for(i=0;i<ndims;i++) temp.dims[i]=va_arg(ap,SizeType);
  return temp;
}
DYMOLA_STATIC StringArray StringVaTemporary(SizeType ndims,va_list ap) {
    StringArray temp=StringVaTemporarySize(ndims,ap);
    temp.data=StringTemp(StringNrElements(temp));
    return temp;
}
/*  Construct a temporary of the same size as a */
DYMOLA_STATIC StringArray StringMatch(const StringArray a) {
  StringArray temp;
  SizeType i;
  temp.ndims=a.ndims;
  temp.dims=SizeTemp(a.ndims);
  for(i=0;i<a.ndims;i++) temp.dims[i]=a.dims[i];
  temp.data=StringTemp(StringNrElements(a));
  return temp;
}
/* Construct array from sizes, using variable number of arguments */
DYMOLA_STATIC StringArray StringTemporary(SizeType ndims,...) {
  StringArray temp;
  va_list ap;
  va_start(ap,ndims);
  temp=StringVaTemporary(ndims,ap);
  va_end(ap);
  return temp;
}
/* Special cases for vectors and matrices (most often used) */
DYMOLA_STATIC StringArray StringTemporaryMatrix(SizeType r,SizeType c) {
  StringArray temp;
  temp.ndims=2;
  temp.dims=SizeTemp(2);
  temp.dims[0]=r;temp.dims[1]=c;
  temp.data=StringTemp(r*c);
  return temp;
}
DYMOLA_STATIC StringArray StringTemporaryVector(SizeType r) {
  StringArray temp;
  temp.ndims=1;
  temp.dims=SizeTemp(1);
  temp.dims[0]=r;
  temp.data=StringTemp(r);
  return temp;
}
/* Assignment */
DYMOLA_STATIC void StringAssign(StringArray a,const StringArray b) {
  SizeType prodsize=StringNrElements(a);
  SizeType i;
  Assert(StringMatchingSizes(a,b),"Array dimensions did not match");
  for(i=0;i<prodsize;i++) a.data[i]=b.data[i];
}
/* Indexing to set/get elements */

DYMOLA_STATIC const char* StringElement(const StringArray a,...) {
  SizeType index;
  va_list ap;
  va_start(ap,a);
  index=FindIndex(a.ndims,a.dims,ap);
  va_end(ap);
  return a.data[index];
}
/* Sizes */
DYMOLA_STATIC Integer StringSize(const StringArray a,SizeType i) {
    Assert((i>=1)&&(i<=a.ndims),"Size must be between 1 and ndims of array");
    return a.dims[i-1];
}
DYMOLA_STATIC IntegerArray StringSizes(const StringArray a) {
    IntegerArray res;
    Integer i;
    res.ndims=1;
    res.dims=SizeTemp(1);
    res.dims[0]=a.ndims;
    res.data=IntegerTemp(a.ndims);
    for(i=0;i<a.ndims;i++) res.data[i]=a.dims[i];
    return res;
}
/* Set element, note that val is prior to the index list. */
DYMOLA_STATIC void SetStringElement(const char* val,StringArray a,...) {
  SizeType index;
  va_list ap;
  va_start(ap,a);
  index=FindIndex(a.ndims,a.dims,ap);
  a.data[index]=val;
  va_end(ap);
}
/* For debug write out */
DYMOLA_STATIC void StringWrite(const StringArray a) {
  SizeType i;
  DymosimMessageInt("Dims: ",a.ndims);
  for(i=0;i<a.ndims;i++) DymosimMessageInt(" ",a.dims[i]);
  for(i=0;i<StringNrElements(a);i++) DymosimMessage((char *) a.data[i]);
}

/* Construct Arrays from other arrays */
DYMOLA_STATIC StringArray StringArrayArray(SizeType narg,StringArray first,...) {
  StringArray res;
  SizeType i,j,prodsize;
  va_list ap;
  res.ndims=first.ndims+1;
  res.dims=SizeTemp(res.ndims);
  res.dims[0]=narg;
  for(i=1;i<res.ndims;i++) res.dims[i]=first.dims[i-1];
  prodsize=StringNrElements(first);  
  res.data=StringTemp(prodsize*narg);
  va_start(ap,first);
  for(i=0;i<narg;i++) {
    StringArray next;
    next=(i!=0)?va_arg(ap,StringArray):first;
    Assert(StringMatchingSizes(first,next),"Arrays in array must be of equal sizes");
    for(j=0;j<prodsize;j++)
      res.data[i*prodsize+j]=next.data[j];
  }
  va_end(ap);
  return res;
}
/* Construct arrays from scalars */
DYMOLA_STATIC StringArray StringScalarArray(SizeType narg,...) {
  StringArray res;
  SizeType i;
  va_list ap;
  res=StringTemporaryVector(narg);
  va_start(ap,narg);
  for(i=0;i<narg;i++) {
    res.data[i]=va_arg(ap,const char*);
  }
  va_end(ap);
  return res;
}

/* Get/Put of submatrices, i.e. a[i,:,v,1:4] */

/* Actual get of a submatrix */
DYMOLA_STATIC void StringFromSub(StringArray to,SizeType to_offset,SizeType to_dim,
              const StringArray from,SizeType from_offset,SizeType from_dim,
              SizeType trailingsize,
			  struct TaggedIndexStack*ap) {
  Integer tag;
  if (!ap) return; /* Error */
  tag=ap->tag;
  switch(tag) {
  case Colon:
    {
      SizeType newdim=from.dims[from_dim];
      SizeType i;
      for(i=0;i<newdim;i++) StringFromSub(to,to_offset*newdim+i,
        to_dim+1,from,from_offset*newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Range:case RangeRange:
    {
      Integer start,stop,stride=1,i,from_newdim,to_newdim;
      start=ap->u.range[0];
      if (tag==RangeRange) stride=ap->u.range[1];
      stop=ap->u.range[2];
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<to_newdim;i++) 
        StringFromSub(to,to_offset*to_newdim+i,to_dim+1,
        from,from_offset*from_newdim+(start+stride*i-1),from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Index:
    {
      Integer i=ap->u.index;
      StringFromSub(to,to_offset,to_dim,
        from,from_offset*from.dims[from_dim]+i-1,from_dim+1,trailingsize,ap+1);
      break;
    }
  case Vector:
    {
      IntegerArray v=ap->u.vector;
      Integer from_newdim,to_newdim,i;
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<v.dims[0];i++)
        StringFromSub(to,to_offset*to_newdim+i,to_dim+1,
        from,from_offset*from_newdim+v.data[i]-1,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case EndMark:
    {
      SizeType i;
      String *to_p=to.data+to_offset;
      String *from_p=from.data+from_offset;
      for(i=0;i<trailingsize;i++,to_p+=1,from_p+=1) *to_p=*from_p;
      break;
    }
  }
}
/* Concatenate along dimensions 'along' (1..ndims) and given nargs arguments */
DYMOLA_STATIC StringArray StringCat(SizeType along,SizeType nargs,StringArray first,...) {
  StringArray res;
  va_list ap;
  SizeType i,j;
  res.ndims=first.ndims;
  res.dims=SizeTemp(res.ndims);
  along--; /* Adapt to C usage */
  {
    /* Pass 1: determine size of output */
    for(j=0;j<first.ndims;j++) res.dims[j]=first.dims[j]; /* Starting values */
    va_start(ap,first);
    for(i=1;i<nargs;i++) {
      StringArray a;
      a=va_arg(ap,StringArray);
      Assert(a.ndims==first.ndims,"Number of dimensions must match for cat");
      for(j=0;j<a.ndims;j++) if (j!=along) {Assert(first.dims[j]==a.dims[j],"Sizes must match for cat");}
      res.dims[along]+=a.dims[along];
    }
    va_end(ap);
  }
  res.data=StringTemp(CommonNrElements(res.ndims, res.dims));
  {
    /* Pass 2: copy data */
    SizeType presize=1;      /* Blocks */
    SizeType trailingsize=1; /* Elements in each block */
    SizeType marker=0; /* How far are in res along dimension along */
    for(i=0;i<along;i++) presize*=res.dims[i];
    for(i=along+1;i<res.ndims;i++) trailingsize*=res.dims[i];
    va_start(ap,first);
    for(i=0;i<nargs;i++) {
      SizeType pre,current,trailing;
      StringArray a;
      if (i!=0) a=va_arg(ap,StringArray); else a=first;
      for(pre=0;pre<presize;pre++) 
        for(current=0;current<a.dims[along];current++)
          for(trailing=0;trailing<trailingsize;trailing++)
		  res.data[(pre*res.dims[along]+(current+marker))*trailingsize+trailing]=
            a.data[(pre*a.dims[along]+current)*trailingsize+trailing];
      marker+=a.dims[along];
    }
    va_end(ap);
  }
  return res;
}

/* The helper in Modelica */
DYMOLA_STATIC StringArray StringPromote(const StringArray a,SizeType n) {
  StringArray res;
  SizeType i;
  Assert(n>=a.ndims,"Promote cannot decrease number of dimensions");
  res.ndims=n;
  res.data=a.data; /* No need to copy */
  res.dims=SizeTemp(n);
  for(i=0;i<a.ndims;i++) res.dims[i]=a.dims[i];
  for(i=a.ndims;i<n;i++) res.dims[i]=1;
  return res;
}
DYMOLA_STATIC StringArray StringPromoteScalar(const char* x,SizeType n) {
    StringArray res;
    Integer i;
    res.ndims=n;
    res.data=StringTemp(1);
    res.data[0]=x;
    res.dims=SizeTemp(n);
    for(i=0;i<n;i++) res.dims[i]=1;
    return res;
}
/* Actual put of submatrix */
DYMOLA_STATIC void StringToSub(StringArray to,SizeType to_offset,SizeType to_dim,
              const StringArray from,SizeType from_offset,SizeType from_dim,
              SizeType trailingsize,
			  struct TaggedIndexStack*ap) {
  Integer tag;
  if (!ap) return; /* Error */
  tag=ap->tag;
  switch(tag) {
  case Colon:
    {
      SizeType newdim=from.dims[from_dim];
      SizeType i;
      for(i=0;i<newdim;i++) StringToSub(to,to_offset*newdim+i,
        to_dim+1,from,from_offset*newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Range:case RangeRange:
    {
      Integer start,stop,stride=1,i,from_newdim,to_newdim;
      start=ap->u.range[0];
      if (tag==RangeRange) stride=ap->u.range[1];
      stop=ap->u.range[2];
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<from_newdim;i++) 
        StringToSub(to,to_offset*to_newdim+(start+stride*i-1),to_dim+1,
        from,from_offset*from_newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case Index:
    {
      Integer i=ap->u.index;
      StringToSub(to,to_offset*to.dims[to_dim]+(i-1),to_dim+1,
        from,from_offset,from_dim,trailingsize,ap+1);
      break;
    }    
  case Vector:
    {
      IntegerArray v=ap->u.vector;
      Integer from_newdim,to_newdim,i;
      from_newdim=from.dims[from_dim];
      to_newdim=to.dims[to_dim];
      for(i=0;i<v.dims[0];i++)
        StringToSub(to,to_offset*to_newdim+(v.data[i]-1),to_dim+1,
        from,from_offset*from_newdim+i,from_dim+1,
        trailingsize,ap+1);
      break;
    }
  case EndMark:
    {
      SizeType i;
      String *to_p=to.data+to_offset;
      String *from_p=from.data+from_offset;
      for(i=0;i<trailingsize;i++,to_p+=1,from_p+=1) *to_p=*from_p;
      break;
    }
  }
}
/* Use as: StringGetSub(a,Colon,Index,3,Range,3,4,EndMark)=a[:,3,3:4] */
DYMOLA_STATIC StringArray StringGetSub(const StringArray a,...) {
  StringArray temp;
  va_list ap;
  SizeType ndims=a.ndims,trailingsize=1,nargs=0;
  /* Pass 1. Determine nr. dimensions of output */
  {
    Integer over=0;
    va_start(ap,a);
    for(;!over;) {
      Integer tag=va_arg(ap,Integer);
      switch (tag) {
      case Colon:nargs++;break;
      case RangeRange:va_arg(ap,Integer); /* Fallthru*/
      case Range:va_arg(ap,Integer),va_arg(ap,Integer);nargs++;break;
      case Vector:va_arg(ap,StringArray);nargs++;break;
      case Index:va_arg(ap,Integer);Assert(ndims>0,"Internal error in subscriptring of array");ndims--;nargs++;break;
      case EndMark:over=1;break;
      }
    }
    va_end(ap);
    Assert(nargs<=a.ndims,"Too many subscripts for array");

  }
  temp.ndims=ndims;
  temp.dims=SizeTemp(ndims);
  /* Pass 2. Determine size of output */
  {
    Integer over=0;
    SizeType temp_dim=0,a_dim=0;
    va_start(ap,a);
    for(;!over;) {
      Integer tag=va_arg(ap,Integer);
      switch (tag) {
      case Colon:temp.dims[temp_dim]=a.dims[a_dim];temp_dim++;break;
      case RangeRange:case Range:
        {
          Integer start,stop,stride=1,num;
          start=va_arg(ap,Integer);
          if (tag==RangeRange) stride=va_arg(ap,Integer);
          stop=va_arg(ap,Integer);
          num=1+(stop-start)/stride;
          if (num<=0) num=0;
          else {
            Assert((start>=1)&&(start<=a.dims[a_dim]),"Range subscripting: start out of range");
            Assert((stop >=1)&&(stop <=a.dims[a_dim]),"Range subscripting: end out of range");
          }
          temp.dims[temp_dim]=num;
          temp_dim++;
          break;
        }
      case Vector:
        {
          IntegerArray v=va_arg(ap,IntegerArray);
          SizeType i;
          Assert(v.ndims==1,"Array subscripting: only vectors (and scalars) allowed as indicies");
          temp.dims[temp_dim]=v.dims[0];
          for(i=0;i<v.dims[0];i++) {
		  Assert((v.data[i]>=1)&&(v.data[i]<=a.dims[a_dim]),"Array subscripting: vector index out of range");
	  }
          temp_dim++;
          break;
        }
      case Index:
        {
          Integer i=va_arg(ap,Integer);
          Assert((i>=1)&&(i<=a.dims[a_dim]),"Array subscripting: scalar index out of range");
          break;
        }
      case EndMark:over=1;break;
      }
      a_dim++;
    }
    va_end(ap);    
    {
      SizeType i;
      for(i=nargs;i<a.ndims;i++) {
        temp.dims[temp_dim++]=a.dims[i];
        trailingsize*=a.dims[i];
      }
    }
  }
  temp.data=StringTemp(CommonNrElements(temp.ndims, temp.dims));
  /* Pass 3. Copy output */
  {
    String *data=temp.data;
	struct TaggedIndexStack*apt=0;
	struct TaggedIndexStack VA_handler[100];
    va_start(ap,a);
	apt=HandleVaList(ap, VA_handler, sizeof(VA_handler)/sizeof(*VA_handler));
	va_end(ap);
    StringFromSub(temp,0,0,a,0,0,trailingsize,apt);
  }
  return temp;
}
/* Use as StringPutSub(a, out,Index,3,Colon,Range,3,4) yields out[3,:,3:4]=a; */
DYMOLA_STATIC StringArray StringCopy(const StringArray a) {
	int i,imax;
	StringArray temp;
	temp.ndims=a.ndims;
	temp.dims=SizeTemp(a.ndims);
	for(i=0;i<a.ndims;++i) temp.dims[i]=a.dims[i];
	imax=StringNrElements(a);
	temp.data=StringTemp(imax);
	for(i=0;i<imax;++i) temp.data[i]=a.data[i];
	return temp;
}
DYMOLA_STATIC void StringPutSub(const StringArray ain,StringArray out,...) {
  StringArray a;
  va_list ap;
  SizeType out_dim=0,a_dim=0,trailingsize=1,nargs=0;
  a=StringCopy(ain);
  /* Pass 1. Determine nr. dimensions of output */
  {
    Integer over=0;
    va_start(ap,out);
    for(;!over;) {
      enum Subtag tag=va_arg(ap,int);
      switch (tag) {
      case Colon:
        Assert(out_dim<out.ndims,"Internal error in subscripting (:)");
        Assert(a_dim<a.ndims,"Internal error in subscripting (:)");
        Assert(out.dims[out_dim]==a.dims[a_dim],"Assignment array subscripting: A[:]=B must have identical sizes");
        out_dim++;
        a_dim++;
        break;
      case RangeRange:case Range:
        {
          Integer start,stop,stride=1,num;
          Assert(out_dim<out.ndims,"Internal error in subscripting: range");
          Assert(a_dim<a.ndims,"Internal error in subscripting: range ");
          start=va_arg(ap,Integer);
          if (tag==RangeRange) stride=va_arg(ap,Integer);
          stop=va_arg(ap,Integer);
          num=(stop-start+stride)/stride;
          if (num<=0) num=0;
          else {
            Assert((start>=1)&&(start<=out.dims[out_dim]),"Assignment array subscripting: start of range out of bounds");
            Assert((stop>=1)&&(stop<=out.dims[out_dim]),"Assignment array subscripting: end of range out of bounds");
          }
          Assert(a.dims[a_dim]==num,"Assignment array subscripting: A[a:b]=B must have identical sizes");
          out_dim++;
          a_dim++;
          break;
        }
      case Vector:
        {
          IntegerArray v=va_arg(ap,IntegerArray);
          SizeType i;
          Assert(out_dim<out.ndims,"Internal error in vector subscripting");
          Assert(a_dim<a.ndims,"Internal error in vector subscripting");
          Assert(v.ndims==1,"Assignment array subscripting: array index must be a vector");
          Assert(a.dims[a_dim]==v.dims[0],"Assignment array subscripting: A[vect]=B must have identical sizes");
          for(i=0;i<v.dims[0];i++) {
		  Assert((v.data[i]>=1)&&(v.data[i]<=out.dims[out_dim]),"Assignment array subscripting: vector index out of bounds");
	  }
          out_dim++;
          a_dim++;
          break;
        }
      case Index:
        {
          Integer i=va_arg(ap,Integer);
          Assert(out_dim<out.ndims,"Internal error in scalar subscripting");
          Assert((i>=1)&&(i<=out.dims[out_dim]),"Assignment array subscripting: scalar index out of bounds");
          out_dim++;
          break;
        }
      case EndMark:over=1;break;
      }
    }
    va_end(ap);
    Assert(a.ndims-a_dim==out.ndims-out_dim,"Assignment array subscripting: unequal number of dimensions");
    {
      SizeType i;
      for(i=a_dim;i<a.ndims;i++) {
        trailingsize*=a.dims[i];
        Assert(a.dims[i]==out.dims[(i-a_dim)+out_dim],"Internal error in subscripting");
      }
    }
  }
  /* Pass 2. Copy output */
  {
	struct TaggedIndexStack*apt=0;
	struct TaggedIndexStack VA_handler[100];
	va_start(ap,out);
	apt=HandleVaList(ap, VA_handler, sizeof(VA_handler)/sizeof(*VA_handler));
	va_end(ap);
    StringToSub(out,0,0,a,0,0,trailingsize,apt);
  }
}


/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
/* Fill */
DYMOLA_STATIC StringArray StringFillAssign(StringArray res,const char* t) {
  SizeType i,prodsize;
  prodsize=StringNrElements(res);
  for(i=0;i<prodsize;i++) res.data[i]=t;
  return res;
}
DYMOLA_STATIC StringArray StringFill(const char* t,SizeType ndims,...) {
  va_list ap;
  StringArray temp;
  va_start(ap,ndims);
  temp=StringFillAssign(StringVaTemporary(ndims,ap),t);
  va_end(ap);
  return temp;
}
DYMOLA_STATIC StringArray StringFillArray(const StringArray a,SizeType ndims,...) {
	va_list ap;
	int i,j,inputProd,fillProd;
	StringArray temp;
	temp.ndims=a.ndims+ndims;
	temp.dims=SizeTemp(temp.ndims);

	va_start(ap,ndims);
	for(i=0;i<ndims;++i) temp.dims[i]=va_arg(ap,SizeType);
	va_end(ap);
	for(i=0;i<a.ndims;++i) temp.dims[i+ndims]=a.dims[i];

	fillProd=1;
	for(i=0;i<ndims;++i) fillProd*=temp.dims[i];
	inputProd=StringNrElements(a);

	temp.data=StringTemp(inputProd*fillProd);
	for(i=0;i<inputProd;++i) {
		for(j=0;j<fillProd;j++) {
		  temp.data[i+j*inputProd]=a.data[i];
		}
	}
	return temp;
}
DYMOLA_STATIC const char* Stringscalar(const StringArray a) {
    Assert(StringNrElements(a)==1,"scalar requires exactly one element");
    return a.data[0];
}
/* Matrix operations not limited to numeric matrices */
DYMOLA_STATIC StringArray Stringvector(const StringArray a) {
    StringArray res;
#ifndef NDEBUG
    Integer i,found_non_one=0;
    for(i=0;i<a.ndims;i++) {if (a.dims[i]>1) {Assert(!found_non_one,"vector requires exactly one vector non-unit dimension");found_non_one=1;}}
#endif
    res.ndims=1;
    res.dims=SizeTemp(1);
    res.dims[0]=StringNrElements(a);
    res.data=a.data;
    return res;
}
DYMOLA_STATIC StringArray Stringmatrix(const StringArray a) {
    StringArray res;
    res.ndims=2;
    res.dims=SizeTemp(2);
    res.dims[0]=a.dims[0];
    res.dims[1]=(a.ndims<2)?1:a.dims[1];
    res.data=a.data;
    Assert(StringNrElements(a)==StringNrElements(res),"matrix requires size(x,i)=1 for i>2");
    return res;
}
DYMOLA_STATIC StringArray Stringtranspose(const StringArray a) {
    StringArray res;
    Integer i,j,k,remsize;
    res.ndims=a.ndims;
    Assert(a.ndims>=2,"transpose requires ndims>=2");
    res.dims=SizeTemp(a.ndims);
    res.dims[0]=a.dims[1];
    res.dims[1]=a.dims[0];
    remsize=1;
    for(i=2;i<a.ndims;i++) {
	remsize*=(res.dims[i]=a.dims[i]);
    }
    res.data=StringTemp(CommonNrElements(res.ndims, res.dims));
    for(i=0;i<res.dims[0];i++) for(j=0;j<res.dims[1];j++) {
	for(k=0;k<remsize;k++) {
	    res.data[(i*res.dims[1]+j)*remsize+k]=a.data[(j*a.dims[1]+i)*remsize+k];
	}
    }
    return res;
}
DYMOLA_STATIC StringArray Stringsymmetric(const StringArray a) {
    StringArray res;
    Integer i,j,n=a.dims[0];
    Assert(a.ndims==2,"symmetric requires ndims==2");
    Assert(a.dims[0]==a.dims[1],"symmetric requires square matrix");
    res=StringTemporaryMatrix(n,n);
    for(i=1;i<=n;i++) {
	for(j=1;j<=i;j++) SetStringElement(StringElement(a,j,i),res,i,j);
	for(;j<=n;j++) SetStringElement(StringElement(a,i,j),res,i,j);
    }
    return res;
}
/* End of common routines for String*/
DYMOLA_STATIC Integer VectorWhenHandle(IntegerArray cond,IntegerArray eval,IntegerArray evalnew,Integer Event,Integer*AnyEvent) {
    /* Returns true if edge of any of the vector conditions.*/
    Integer anyTrue=false;
    SizeType i,nrElem; 
    Assert(IntegerMatchingSizes(cond,eval),"Internal error in array when.");
    nrElem=IntegerNrElements(cond);
    for(i=0;i<nrElem;i++) {
		if (cond.data[i]) {
			if (Event) {
				if (eval.data[i]) {
					anyTrue = true;
					*AnyEvent = true;
					evalnew.data[i] = false;
				}
			}
		} else {
			if (Event && !eval.data[i]) {
				/* *AnyEvent=true; */
			}
			evalnew.data[i] = true;
		}
    }
    return anyTrue;
}

static void RealCopyMajor(RealArray to,SizeType to_offset,const RealArray x,SizeType from_offset,SizeType from_dist,SizeType dim) {
	if (dim>=x.ndims-1) {
		SizeType i,imax=to.dims[dim];
		for(i=0;i<imax;i++)
			to.data[to_offset*imax+i]=x.data[from_offset+i*from_dist];
	} else {
		SizeType i,imax=to.dims[dim];
		for(i=0;i<imax;i++) RealCopyMajor(to,to_offset*imax+i,x,from_offset+i*from_dist,from_dist*imax,dim+1);
	}
}
DYMOLA_STATIC void RealSwitchMajorAssign(RealArray temp,const RealArray x) {
	RealCopyMajor(temp,0,x,0,1,0);
}

DYMOLA_STATIC RealArray RealSwitchMajor(const RealArray x) {
	if (x.ndims<=1) 
		return x;
	{
	RealArray temp=RealMatch(x);
	{int i;for(i=0;i<x.ndims;i++) temp.dims[i]=x.dims[x.ndims-i-1]; /* Switch dimensions */}
	RealSwitchMajorAssign(temp,x);
	return temp;
	}
}

static void IntegerCopyMajor(IntegerArray to,SizeType to_offset,const IntegerArray x,SizeType from_offset,SizeType from_dist,SizeType dim) {
	if (dim>=x.ndims-1) {
		SizeType i,imax=to.dims[dim];
		for(i=0;i<imax;i++) 
			to.data[to_offset*imax+i]=x.data[from_offset+i*from_dist];
	} else {
		SizeType i,imax=to.dims[dim];
		for(i=0;i<imax;i++) 
			IntegerCopyMajor(to,to_offset*imax+i,x,from_offset+i*from_dist,from_dist*imax,dim+1);
	}
}
DYMOLA_STATIC void IntegerSwitchMajorAssign(IntegerArray temp,const IntegerArray x) {
	IntegerCopyMajor(temp,0,x,0,1,0);
}
DYMOLA_STATIC IntegerArray IntegerSwitchMajor(const IntegerArray x) {
	if (x.ndims<=1) 
		return x;
	{IntegerArray temp=IntegerMatch(x);
	{int i;for(i=0;i<x.ndims;i++) temp.dims[i]=x.dims[x.ndims-i-1]; /* Switch dimensions */}
	IntegerSwitchMajorAssign(temp,x);
	return temp;
	}
}

static void StringCopyMajor(StringArray to,SizeType to_offset,const StringArray x,SizeType from_offset,SizeType from_dist,SizeType dim) {
	if (dim>=x.ndims-1) {
		SizeType i,imax=to.dims[dim];
		for(i=0;i<imax;i++) 
			to.data[to_offset*imax+i]=x.data[from_offset+i*from_dist];
	} else {
		SizeType i,imax=to.dims[dim];
		for(i=0;i<imax;i++) 
			StringCopyMajor(to,to_offset*imax+i,x,from_offset+i*from_dist,from_dist*imax,dim+1);
	}
}
DYMOLA_STATIC void StringSwitchMajorAssign(StringArray temp,const StringArray x) {	
	StringCopyMajor(temp,0,x,0,1,0);
}
DYMOLA_STATIC StringArray StringSwitchMajor(const StringArray x) {
	if (x.ndims<=1) 
		return x;
	{StringArray temp=StringMatch(x);
	{int i;for(i=0;i<x.ndims;i++) temp.dims[i]=x.dims[x.ndims-i-1]; /* Switch dimensions */}
	StringSwitchMajorAssign(temp,x);
	return temp;
	}
}
DYMOLA_STATIC RealArray RealLeading(int i,int j,RealArray a) {
	RealArray res;
	res.ndims=a.ndims-i;
	res.dims=a.dims+i;
	res.data=a.data+j*CommonNrElements(res.ndims, res.dims);
	return res;
}
DYMOLA_STATIC IntegerArray IntegerLeading(int i,int j,IntegerArray a) {
	IntegerArray res;
	res.ndims=a.ndims-i;
	res.dims=a.dims+i;
	res.data=a.data+j*CommonNrElements(res.ndims, res.dims);
	return res;
}
DYMOLA_STATIC StringArray StringLeading(int i,int j,StringArray a) {
	StringArray res;
	res.ndims=a.ndims-i;
	res.dims=a.dims+i;
	res.data=a.data+j*CommonNrElements(res.ndims, res.dims);
	return res;
}

#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
#include "amat.h"
#include "sprwat.h"
#endif

DYMOLA_STATIC RealArray readMatrix(const char*fil,const char*matnam,Integer rows,Integer cols) {
	RealArray m=RealTemporaryMatrix(rows,cols);
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	Amatrix amatrix;
	AmatGetFile afile;
	int ret=amatGetOpen((char*)fil,"NoClass",(char*)0,&afile);
	int found=0;
	Assert(ret==0,amatError);
	for(;ret==0 && !found;) {
		amatInit(&amatrix);
		ret=amatGetMatrix(&afile, &amatrix);
		Assert(ret<=1,amatError);
		if (ret<=1 && strcmp(matnam,amatrix.name)==0) {
			int i,j;
			Assert(rows==amatrix.nrow && cols==amatrix.ncol,"Matrix dimension incorrect");
			Assert(amatrix.type==doubleMatrix || amatrix.type==realMatrix || amatrix.type==integerMatrix,"No string matrices allowed");
			found=1;
			for(i=0;i<rows;i++) for(j=0;j<cols;j++) {
				double val=0;
				switch(amatrix.type) {
				case doubleMatrix:val=amatrix.data.d[i+j*rows];break;
				case realMatrix:val=amatrix.data.r[i+j*rows];break;
				case integerMatrix:val=amatrix.data.i[i+j*rows];break;
				default: break;
				}
				SetRealElement(val,m,i+1,j+1);
			}
		}
		amatDel(&amatrix);
	}
	amatGetClose(&afile);
	Assert(found, "Read of matrix failed");
#else
	Assert(false, "Cannot read files");
#endif
	return m;
}

DYMOLA_STATIC IntegerArray readMatrixSize(const char*fil,const char*matnam) {
	IntegerArray m=IntegerTemporaryVector(2);
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	Amatrix amatrix;
	AmatGetFile afile;
	int ret=amatGetOpen((char*)fil,"NoClass",(char*)0,&afile);
	int found=0;
	Assert(ret==0,amatError);
	for(;ret==0 && !found;) {
		amatInit(&amatrix);
		ret=amatGetMatrix(&afile, &amatrix);
		Assert(ret<=1,amatError);
		if (ret<=1 && strcmp(matnam,amatrix.name)==0) {
			found=1;
			SetIntegerElement(amatrix.nrow,m,1);
			SetIntegerElement(amatrix.ncol,m,2);
		}
		amatDel(&amatrix);
	}
	amatGetClose(&afile);
	Assert(found, "Read of matrix failed");
#else
	Assert(false, "Cannot read files");
#endif
	return m;
}
DYMOLA_STATIC StringArray readMATmatrices_M(const char*fil) {
	StringArray s;
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	/* 1. Find number of matrices */
	int nrMatrices=0,i=0;
	Amatrix amatrix;
	AmatGetFile afile;
	int ret=amatGetOpen((char*)fil,"NoClass",(char*)0,&afile);

	
	Assert(ret==0,amatError);
	for(;ret==0;) {
		amatInit(&amatrix);
		ret=amatGetMatrix(&afile, &amatrix);
		if (ret<=1) ++nrMatrices;
		amatDel(&amatrix);
	}
	amatGetClose(&afile);
	s=StringFillAssign(StringTemporaryMatrix(nrMatrices,2), "");
	ret=amatGetOpen((char*)fil,"NoClass",(char*)0,&afile);
	for(;ret==0;) {
		amatInit(&amatrix);
		ret=amatGetMatrix(&afile, &amatrix);
		if (ret<=1) {
			char*s1=StringAllocate(strlen(amatrix.name));
			const char*s2="Unknown";
			strcpy(s1, amatrix.name);
			++i;
			switch(amatrix.type) {
				case doubleMatrix:case realMatrix:s2="Real";break;
				case integerMatrix:s2="Integer";break;
				default:break;
			}
			SetStringElement(s1, s, i, 1);
			SetStringElement(s2, s, i, 2);
		}
		amatDel(&amatrix);
	}
	amatGetClose(&afile);
#else
	Assert(false, "Cannot read files");
	s = StringTemporaryVector(0);
#endif
	return s;
}


DYMOLA_STATIC Real RealReadScalar(const char*fil,const char*matnam) {
	/* 
	Modified 2008-06-11 Dan Henriksson 
	Original implementation caused fatal error in 
	VS 8 when compiling models for HILS on xPC */

	/* return Realscalar(RealReadArray(fil,matnam,2)); */

	RealArray m;
	Real val;
#if defined(DYMOLA_DSPACE) || defined(NO_FILE)
	Assert(false, "Cannot read files");
	m = RealTemporaryMatrix(0, 0);
#else
	m = RealReadArray(fil,matnam,2);
#endif
	val = Realscalar(m);
	return val;
}
DYMOLA_STATIC RealArray RealReadArray(const char*fil,const char*matnam,Integer ndims) {
	RealArray m;
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	Amatrix amatrix;
	AmatGetFile afile;
	char sizeName[200] = "";
	int ret;
	int found, foundSize;
	Assert((ndims >= 1), "Current version can only read scalars, vectors, and matrices");
	m.ndims = ndims;
	m.dims = SizeTemp(ndims);
	ret = amatGetOpen((char*)fil, "NoClass", (char*)0, &afile);
	found = 0;
	foundSize = 0;
	if (ndims > 2) {
		sprintfC(sizeName, "%s.size", matnam);
	}
	for(;ret==0 && !found;) {
		amatInit(&amatrix);
		ret=amatGetMatrix(&afile, &amatrix);
		Assert(ret<=1,amatError);
		if (ret<=1 && strcmp(matnam,amatrix.name)==0) {
			int i,j,rows=amatrix.nrow,cols=amatrix.ncol;
			Assert(amatrix.type==doubleMatrix || amatrix.type==realMatrix || amatrix.type==integerMatrix,"No string matrices allowed");
			found=1;
			m.data = RealTemp(rows*cols);
			if (!foundSize) {
				m.dims[0] = amatrix.nrow;
				m.dims[1] = amatrix.ncol;
			}
			for (i = 0; i < rows*cols; ++i) {
				double val = 0;
				switch (amatrix.type) {
				case doubleMatrix:val = amatrix.data.d[i]; break;
				case realMatrix:val = amatrix.data.r[i]; break;
				case integerMatrix:val = amatrix.data.i[i]; break;
				default: break;
				}
				m.data[i] = val;
			}

		} else if (ret <= 1 && ndims > 2 && !found && strcmp(sizeName, amatrix.name) == 0 && amatrix.nrow == ndims) {
			int i;
			Assert(amatrix.type == integerMatrix, "Integer matrix required");
			for (i = 0; i < ndims; ++i) m.dims[i] = amatrix.data.i[i];
			foundSize = 1;
		}
		amatDel(&amatrix);
	}
	amatGetClose(&afile);
	Assert(found, "Read of matrix failed");
	if (ndims==1) return Realvector(m);
#else
	Assert(false, "Cannot read files");
	m = RealTemporaryMatrix(0, 0);
#endif
	return m;
}
DYMOLA_STATIC Integer IntegerReadScalar(const char*fil,const char*matnam) {
	/* 
	Modified 2008-06-11 Dan Henriksson 
	Original implementation caused fatal error in 
	VS 8 compiler for HILS on xPC */

	/* return Integerscalar(IntegerReadArray(fil,matnam,2)); */

	IntegerArray m;
	Integer val;
#if defined(DYMOLA_DSPACE) || defined(NO_FILE)
	Assert(false, "Cannot read files");
	m = IntegerTemporaryMatrix(0, 0);
#else
	m = IntegerReadArray(fil,matnam,2);
#endif
	val = Integerscalar(m);
	return val;
}
DYMOLA_STATIC IntegerArray IntegerReadArray(const char*fil,const char*matnam,Integer ndims) {
	IntegerArray m;
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	Amatrix amatrix;
	AmatGetFile afile;
	char sizeName[200] = "";
	int ret;
	int found, foundSize;
	Assert((ndims >= 1), "Current version can only read scalars, vectors, and matrices");
	m.ndims = ndims;
	m.dims = SizeTemp(ndims);
	ret = amatGetOpen((char*)fil, "NoClass", (char*)0, &afile);
	found = 0;
	foundSize = 0;
	if (ndims > 2) {
		sprintfC(sizeName, "%s.size", matnam);
	}
	for(;ret==0 && !found;) {
		amatInit(&amatrix);
		ret=amatGetMatrix(&afile, &amatrix);
		if (ret<=1 && strcmp(matnam,amatrix.name)==0) {
			int i,j,rows=amatrix.nrow,cols=amatrix.ncol;
			Assert(amatrix.type==integerMatrix,"Integer matrix required");
			found=1;
			m.data = IntegerTemp(rows*cols);
			if (!foundSize) {
				m.dims[0] = amatrix.nrow;
				m.dims[1] = amatrix.ncol;
			}
			for (i = 0; i < rows*cols; ++i) {
				Integer val = 0;
				switch (amatrix.type) {
				case integerMatrix:val = amatrix.data.i[i]; break;
				default: break;
				}
				m.data[i] = val;
			}
		} else if (ret <= 1 && ndims > 2 && !found && strcmp(sizeName, amatrix.name) == 0 && amatrix.nrow == ndims) {
			int i;
			Assert(amatrix.type == integerMatrix, "Integer matrix required");
			for (i = 0; i < ndims; ++i) m.dims[i] = amatrix.data.i[i];
			foundSize = 1;
		}
		amatDel(&amatrix);
	}
	amatGetClose(&afile);
	Assert(found, "Read of matrix failed");
	if (ndims==1) return Integervector(m);
#else
	Assert(false, "Cannot read files");
	m = IntegerTemporaryMatrix(0, 0);
#endif
	return m;
}
DYMOLA_STATIC String StringReadScalar(const char*fil,const char*matnam) {
	/* 
	Modified 2008-06-11 Dan Henriksson 
	Original implementation caused fatal error in 
	VS 8 compiler for HILS on xPC */

	/* return Stringscalar(StringReadArray(fil,matnam,1)); */

	StringArray m;
	String val;
#if defined(DYMOLA_DSPACE) || defined(NO_FILE)
	Assert(false, "Cannot read files");
	m = StringTemporaryVector(0);
#else
	m = StringReadArray(fil,matnam,1);
#endif
	val = Stringscalar(m);
	return val;
}
DYMOLA_STATIC StringArray StringReadArray(const char*fil,const char*matnam,Integer ndims) {
	StringArray m;
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	Amatrix amatrix;
	AmatGetFile afile;
	char sizeName[200] = "";
	int ret;
	int found, foundSize;
	Assert((ndims >= 1), "Current version can only read scalars, vectors, and matrices");
	m.ndims = ndims;
	m.dims = SizeTemp(ndims);
	ret = amatGetOpen((char*)fil, "NoClass", (char*)0, &afile);
	found = 0;
	foundSize = 0;
	if (ndims > 1) {
		sprintfC(sizeName, "%s.size", matnam);
	}
	Assert((ndims<=1)&&(ndims>=1),"Current version can only read scalars and vectors");
	for(;ret==0 && !found;) {
		amatInit(&amatrix);
		ret=amatGetMatrixP3(&afile, &amatrix,voidMatrix,0,0);
		Assert(ret<=1,amatError);
		if (ret <= 1 && strcmp(matnam, amatrix.name) == 0) {
			int i, j, rows = amatrix.nrow;
			Assert(amatrix.type == charMatrix, "Only string matrices allowed");
			found = 1;
			m.data = StringTemp(rows);
			if (!foundSize) {
				m.dims[0] = amatrix.nrow;
			}
			for (i = 0; i < rows; ++i) {
#if defined(_MSC_VER) && _MSC_VER >= 1400
				const char*val = amatrix.data.c[i] ? _strdup(amatrix.data.c[i]) : "";
#else
				const char*val = amatrix.data.c[i] ? strdup(amatrix.data.c[i]) : "";
#endif
				m.data[i] = val;
			}
		} else if (ret <= 1 && ndims > 1 && !found && strcmp(sizeName, amatrix.name) == 0 && amatrix.nrow == ndims) {
			int i;
			Assert(amatrix.type == integerMatrix, "Integer matrix required");
			for (i = 0; i < ndims; ++i) m.dims[i] = amatrix.data.i[i];
			foundSize = 1;
		}
		amatDel(&amatrix);
	}
	amatGetClose(&afile);
	Assert(found, "Read of matrix failed");
	if (ndims==1) return Stringvector(m);
#else
	Assert(false, "Cannot read files");
	m = StringTemporaryVector(0);
#endif
	return m;
}
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
static void writeSize(AmatPutFile*file, int ndims, int sizes[], const char*name) {
	char sizename[200];
	Amatrix sizeMatrix;
	sizeMatrix.ncol = 1;
	sizeMatrix.nrow = ndims;
	sizeMatrix.type = integerMatrix;
	sizeMatrix.data.i = sizes;
	sprintfC(sizename, "%s.size", name);
	sizeMatrix.name = sizename;
	amatPutMatrix(file, sizeMatrix);
}
#endif
DYMOLA_STATIC void writeArrays(const char*fileName,int nargs,...) {
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	/* Format for ...: nargs copies of:
	    const char*name,AmatType typ,int ndims,Array (RealArray etc) or scalar (Real, Integer,...)
	    */
	AmatPutFile file;
	va_list ap;
	if (amatPutOpen   ((char*)fileName, amatBinary, binNormal, "", "", "", &file) != 0) {
		Assert(false,"failed to open output file");
	}
	va_start(ap, nargs);
	for(;nargs>0;nargs--) {
		const char*matnam=va_arg(ap,const char*);
		Amatrix amatrix;
		int ret=100;
		amatrix.name=(char*)matnam;
		amatrix.nrow = amatrix.ncol = 1;
		{
			AmatType argtype = va_arg(ap, AmatType);
			int ndims = va_arg(ap, int);
			int tooLarge = ndims > 2 || ndims >= 2 && argtype == charMatrix;
			amatrix.type = argtype;
			if (ndims == 0) {
				switch (argtype) {
				case doubleMatrix:
				{
					Real x = va_arg(ap, Real);
					amatrix.data.d = &x;
					ret = amatPutMatrix(&file, amatrix);
					break;
				}
				case integerMatrix:
				{
					Integer x = va_arg(ap, Integer);
					amatrix.data.i = &x;
					ret = amatPutMatrix(&file, amatrix);
					break;
				}
				case charMatrix:
				{
					String x = va_arg(ap, String);
					amatrix.data.c = (char**)&x;
					ret = amatPutMatrixPadding(&file, amatrix, '\0');
					break;
				}
				default:
					; /* error */
				}
			} else {
				MarkObject mark = PushMark();
				switch (argtype) {
				case doubleMatrix:
				{
					RealArray x = va_arg(ap, RealArray);
					RealArray temp = x;
					amatrix.nrow = x.dims[0];
					if (tooLarge) {
						amatrix.nrow = RealNrElements(x);
						writeSize(&file, ndims, x.dims, matnam);
					} else if (x.ndims > 1) amatrix.ncol = x.dims[1];
					amatrix.data.d = (double*)temp.data;
					ret = amatPutMatrix(&file, amatrix);
					break;
				}
				case integerMatrix:
				{
					IntegerArray x = va_arg(ap, IntegerArray);
					IntegerArray temp = x;
					amatrix.nrow = x.dims[0];
					if (tooLarge) {
						amatrix.nrow = IntegerNrElements(x);
						writeSize(&file, ndims, x.dims, matnam);
					} else if (x.ndims > 1) amatrix.ncol = x.dims[1];
					amatrix.data.i = (Integer*)temp.data;
					ret = amatPutMatrix(&file, amatrix);
					break;
				}
				case charMatrix:
				{
					StringArray x = va_arg(ap, StringArray);
					StringArray temp = x;
					amatrix.nrow = x.dims[0];
					if (tooLarge) {
						amatrix.nrow = StringNrElements(x);
						writeSize(&file, ndims, x.dims, matnam);
					} else if (x.ndims > 1) amatrix.ncol = x.dims[1];
					amatrix.data.c = (char**)temp.data;
					ret = amatPutMatrix(&file, amatrix);
					break;
				}
				default:
					; /* error */
				}
				PopMark(mark);
			}
		}
		Assert(ret==0,"Write of matrix must succeed");
	}
	va_end(ap);
	amatPutClose(&file);
#else
	Assert(false, "Cannot write files");
#endif
}

DYMOLA_STATIC Integer writeMatrix(const char*fil,const char*matnam,const RealArray mat, int append) {
	int ret=1;
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
	if (append) {
		int num=0,i;
		Amatrix amatOld[20];
		AmatGetFile fileHandle;
		if ( amatGetOpen((char*)(fil), "NoClass", "0.0", &fileHandle ) == 0 ) {
			for (;num<19;) {
				amatInit(amatOld+num);
				if (amatGetMatrix(&fileHandle, amatOld+num) !=0)
					break;
				if (strcmp(amatOld[num].name,matnam)!=0) {
					num++;
				} else {
					amatDel(amatOld+num);
				}
			}
			amatGetClose(&fileHandle);
		}
		{
			MarkObject mark;
			RealArray temp;
			Amatrix amatrix;
			AmatPutFile filehandle;

			mark = PushMark();
			temp = RealSwitchMajor(mat);
			amatrix.name = (char*) matnam;
			amatrix.nrow = mat.dims[0];
			amatrix.ncol = mat.dims[1];
			amatrix.type = doubleMatrix;
			amatrix.data.d = (double*) temp.data;
			amatrix.nrowallocated = 0;
			amatrix.nrowread = 0;

			if ( amatPutOpen   ((char*)(fil), amatBinary,binNormal, "", "", "", &filehandle) != 0 ) 
				ret=1;
			else {
				for(i=0;i<num;++i) {
					ret=amatPutMatrix(&filehandle,amatOld[i]);
					if (ret!=0) break;
				}
				if (ret==0)
					ret=amatPutMatrix(&filehandle,amatrix);
				amatPutClose(&filehandle);
			}
			for(i=0;i<num;++i) amatDel(amatOld+i);
			Assert(mat.ndims==2,"Only writing of matrices");
			PopMark(mark);
		}
	} else {
		MarkObject mark;
		RealArray temp;
		Amatrix amatrix;

		mark = PushMark();
		temp = RealSwitchMajor(mat);
		amatrix.name = (char*) matnam;
		amatrix.nrow = mat.dims[0];
		amatrix.ncol = mat.dims[1];
		amatrix.type = doubleMatrix;
		amatrix.data.d = (double*) temp.data;
		amatrix.nrowallocated = 0;
		amatrix.nrowread = 0;
		ret=amatWrite((char*)fil,amatBinary,amatrix);	
		Assert(mat.ndims==2,"Only writing of matrices");
		PopMark(mark);
	}
#endif
	return ret==0;	
}


/* Major pop, e.g. at end of integration */
DYMOLA_STATIC void PopMarkMarks() {
  EnsureMarkInitialized();
  currentMark=startMark;
  stringmark=startstringmark;
}
DYMOLA_STATIC char* GetStringMark() {
	EnsureMarkInitialized();
	return (char*)stringmark;
}
DYMOLA_STATIC void SetStringMark(char*s) {
	EnsureMarkInitialized();
	if (s) stringmark=s;
}
DYMOLA_STATIC const char* SqueezeString(const char*s, char*startMarker) {
	EnsureMarkInitialized();
	if (s>=startMarker && s<stringmark) {
		int len=strlen(s)+1;
		int i;
		if (s+len<=stringmark) {
			stringmark=startMarker+len;
			for(i=0;i<len;++i) startMarker[i]=s[i]; /* Might overlap*/
			s=startMarker;
		}
	} else {
		stringmark=startMarker;
	}
	return s;
}

DYMOLA_STATIC String ConvertPointerToString(const char*a) {
	if (a) return a;
	else return "";
}
DYMOLA_STATIC String ConvertToNonTempString(String s) {
	if (s>=startstringmark && s<Endsimplestring) {
		char*s2;
		SizeType len=0;
		int i;
		for(len=0;s[len]!=0;++len);
		Assert(startstringmarkNon+len+1<Endsimplestring,"Room to allocate string");
		s2=startstringmarkNon;
		startstringmarkNon+=(len+1);
		for(i=0;i<=len;++i) s2[i]=s[i];
		return s2;
	}
	return s;
}
DYMOLA_STATIC StringArray ConvertToNonTempStringArray(StringArray s) {
	StringArray s2;
	int len,i;
	s2=s;
	len=StringNrElements(s);
	for(i=0;i<len;++i) s2.data[i]=ConvertToNonTempString(s2.data[i]);
	return s2;
}
DYMOLA_STATIC char* StringAllocate(SizeType len) {
	char*ret=0;
	EnsureMarkInitialized();
	ret=(char*)stringmark;
	Assert(stringmark+len+1<Endsimplestring,"Room to allocate string");
	stringmark+=(len+1);
	return ret;
}
DYMOLA_STATIC String StringAdd(String a,String b) {
	char*ret=StringAllocate(strlen(a)+strlen(b));
	strcpy(ret,a);
	strcat(ret,b);
	return ret;
}
DYMOLA_STATIC String Real2String(Real x,Integer minwidth,Integer precision) {
	char buf[100];
	char*ret;
	Assert(precision<40 && minwidth<40,"");
	sprintf(buf,"%*.*g",(int)minwidth,(int)precision,(double)x);
	ret=StringAllocate(strlen(buf));
	strcpy(ret,buf);
	return ret;
}
DYMOLA_STATIC String Integer2String(Integer x,Integer minwidth,Integer precision) {
	char buf[100];
	char*ret;
	Assert(precision<40 && minwidth<40,"");
	sprintf(buf,"%*.*d",(int)minwidth,(int)precision,(int)x);
	ret=StringAllocate(strlen(buf));
	strcpy(ret,buf);
	return ret;
}
DYMOLA_STATIC String Real2String3(Real x,Integer leftJustified,Integer minwidth,Integer precision) {
	char buf[100];
	char*ret;
	Assert(precision<40 && minwidth<40,"");
	sprintf(buf,leftJustified?"%-*.*g":"%*.*g",(int)minwidth,(int)precision,(double)x);
	ret=StringAllocate(strlen(buf));
	strcpy(ret,buf);
	return ret;
}
DYMOLA_STATIC String Real2String2(Real x,Integer leftJustified,Integer minwidth) {
	return Real2String3(x,leftJustified,minwidth,6);
}
DYMOLA_STATIC String Integer2String2(Integer x,Integer leftJustified,Integer minwidth) {
	char buf[100];
	char*ret;
	Assert(minwidth<40,"");
	sprintf(buf,leftJustified?"%-*d":"%*d",(int)minwidth,(int)x);
	ret=StringAllocate(strlen(buf));
	strcpy(ret,buf);
	return ret;
}

DYMOLA_STATIC String Boolean2String2(Integer x,Integer leftJustified,Integer minwidth) {
	char buf[100];
	char*ret;
	Assert(minwidth<40,"");
	sprintf(buf,leftJustified?"%-*s":"%*s",(int)minwidth,x?"true":"false");
	ret=StringAllocate(strlen(buf));
	strcpy(ret,buf);
	return ret;
}
DYMOLA_STATIC String Real2StringFormat(Real x,String s) {
	char buf[100];
	char*ret;
	buf[99]='\0';
	sprintf(buf,StringAdd("%",s),x);
	Assert(buf[99]=='\0',"");
	ret=StringAllocate(strlen(buf));
	strcpy(ret,buf);
	return ret;
}

DYMOLA_STATIC void CopySlice(Real*x,RealArray y) {
	SizeType nrElem=RealNrElements(y);
	int i;
	for(i=0;i<nrElem;++i) x[i]=y.data[i];
	return;
}
DYMOLA_STATIC RealArray RealTemporaryDense(Real*d,SizeType ndims,...) {
    RealArray temp;
    va_list ap;
    va_start(ap,ndims);
    temp=RealVaTemporarySize(ndims,ap);
    va_end(ap);
    temp.data=d;
    return temp;
}
DYMOLA_STATIC StringArray StringTemporaryDense(String*d,SizeType ndims,...) {
    StringArray temp;
    va_list ap;
    va_start(ap,ndims);
    temp=StringVaTemporarySize(ndims,ap);
    va_end(ap);
    temp.data=d;
    return temp;
}
DYMOLA_STATIC IntegerArray IntegerTemporaryDense(Real*d,SizeType ndims,...) {
    IntegerArray temp;
	int i,nrElem;
    va_list ap;
    va_start(ap,ndims);
    temp=IntegerVaTemporary(ndims,ap);
    va_end(ap);
	nrElem=IntegerNrElements(temp);
    for(i=0;i<nrElem;++i) temp.data[i]=(Integer)(d[i]);
    return temp;
}
DYMOLA_STATIC IntegerArray IntegerTemporaryDenseOrig(Integer*d,SizeType ndims,...) {
    IntegerArray temp;
    va_list ap;
    va_start(ap,ndims);
    temp=IntegerVaTemporarySize(ndims,ap);
    va_end(ap);
    temp.data=d;
    return temp;
}
DYMOLA_STATIC void ModelicaError(const char *string) {
	DymosimError((string));
}
DYMOLA_STATIC void ModelicaFormatError(const char *string,...) {
	char buf[4000];
	va_list ap;
	va_start(ap,string);
#if defined(__WATCOMC__)  && defined(DynSimStruct) || defined(NO_FILE) || defined(DYMOLA_DSPACE)
	strcpy(buf,string);
#elif defined(_MSC_VER) && _MSC_VER>=1200
	_vsnprintf(buf,sizeof(buf)/sizeof(*buf),string,ap);
#else
	vsprintf(buf,string,ap);
#endif
	va_end(ap);
	DymosimError(buf);
}
DYMOLA_STATIC void DymosimMessageNoNL(const char*);
DYMOLA_STATIC void ModelicaMessage(const char *string) {
	DymosimMessageNoNL(string);
}
DYMOLA_STATIC void ModelicaFormatMessage(const char *string,...) {
	char buf[4000];
	va_list ap;
	va_start(ap,string);
#if defined(__WATCOMC__)  && defined(DynSimStruct) || defined(NO_FILE) || defined(DYMOLA_DSPACE)
	strcpy(buf,string);
#elif defined(_MSC_VER) && _MSC_VER>=1200
	_vsnprintf(buf,sizeof(buf)/sizeof(*buf),string,ap);
#else
	vsprintf(buf,string,ap);
#endif
	va_end(ap);
	DymosimMessageNoNL(buf);
}
DYMOLA_STATIC char* ModelicaAllocateString(size_t len) {
	char*s=StringAllocate(len);
	s[0]='\0';
	return s;
}
DYMOLA_STATIC char* ModelicaAllocateStringWithErrorReturn(size_t len) {
	EnsureMarkInitialized();
	if (stringmark+len+1<Endsimplestring)
		return ModelicaAllocateString(len);
	else return 0;
}
DYMOLA_STATIC IntegerArray ANDArray(const IntegerArray a,const IntegerArray b) {
	SizeType prodsize,i;
	IntegerArray res=IntegerMatch(a);
	Assert(IntegerMatchingSizes(a,b),"and of arrays require arguments of matching size");
	prodsize=IntegerNrElements(a);
	for(i=0;i<prodsize;i++) res.data[i]=a.data[i] && b.data[i];
	return res;
}
DYMOLA_STATIC IntegerArray ORArray(const IntegerArray a,const IntegerArray b) {
	SizeType prodsize,i;
	IntegerArray res=IntegerMatch(a);
	Assert(IntegerMatchingSizes(a,b),"or of arrays require arguments of matching size");
	prodsize=IntegerNrElements(a);
	for(i=0;i<prodsize;i++) res.data[i]=a.data[i] || b.data[i];
	return res;
}
DYMOLA_STATIC IntegerArray NOTArray(const IntegerArray a) {
	SizeType prodsize,i;
	IntegerArray res=IntegerMatch(a);
	prodsize=IntegerNrElements(a);
	for(i=0;i<prodsize;i++) res.data[i]=!a.data[i];
	return res;
}

#if defined(LIBDS_EXPORTS) || defined(LIBDSDLL_EXPORTS)
/*TODO: can it really be excluded for Windows? */
#if !defined(_MSC_VER) || defined(__MINGW32__)
#include "localeless.cpp"
#endif
#else
#include "localeless.cpp"
#endif

#endif

#if defined(_MSC_VER)
#if !DymolaGlobalOptimizations_
/* Reset optimization to compiler switches */
#pragma optimize( "", on )
#endif
#endif
#endif
