#ifndef MATRIXOP1_H
#define MATRIXOP1_H
/*  * Declarations of matrix functions in Dymola
 *
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 * Author: Hans Olsson Dynasim AB, 1999
 * Version: 1.4, 1999-09-24*/
/* */
#include <math.h>

/* To make functions and variables static to allow several S-function blocks
	for real-time targets */
#if !defined(DYMOLA_STATIC)
#if defined(__cplusplus)
#define DYMOLA_STATIC extern
#elif defined(RT) && !defined(DYM2DS)
#define DYMOLA_STATIC static
#else
#define DYMOLA_STATIC
#endif
#endif
#if !defined(DYMOLA_STATIC2)
#if defined(__cplusplus)
#define DYMOLA_STATIC2 extern
#elif defined(RT) && !defined(DYM2DS)
#define DYMOLA_STATIC2 static
#else
#define DYMOLA_STATIC2 extern
#endif
#endif

#if defined(Matlab5) || defined(Matlab51) || defined(SimStruct) || defined(DYM2DS) || defined(FMU_SOURCE_CODE_EXPORT)
#if !defined(DynSimStruct)
#define DynSimStruct 1
/* Needed for dsutil.h in Modelica mode. */
#endif
#endif

#define Modelica

#include <stddef.h>
#include <stdarg.h>
#include <math.h>
#include "dsblock.h"
#include "f2c.h"

#ifndef DYN_MarkObject
#define DYN_MarkObject
typedef double Real;
#if defined(DYM2CCUR)
typedef int Integer;
#else
typedef int Integer;
#endif
typedef const char* String;
typedef Integer SizeType;

struct BufferObject {Real *Realbuffer;Integer *Integerbuffer;SizeType* Sizebuffer;String* Stringbuffer;};
struct MarkObject {struct BufferObject place,mark;};
#endif

#if defined(RT)
DYMOLA_STATIC2 Real Realbuffer[
#ifndef DYNREALBUFFER
	500000
#else
	DYNREALBUFFER
#endif
];
DYMOLA_STATIC2 Integer Integerbuffer[
#ifndef DYNINTEGERBUFFER
	50000
#else
	DYNINTEGERBUFFER
#endif
];
DYMOLA_STATIC2 SizeType Sizebuffer[
#ifndef DYNINTEGERBUFFER
	50000
#else
	DYNINTEGERBUFFER
#endif
];
DYMOLA_STATIC2 String Stringbuffer[
#ifndef DYNSTRINGBUFFER
	10000
#else
	DYNSTRINGBUFFER
#endif
];
DYMOLA_STATIC2 char simplestring[
#ifndef DYNSTRINGBUFFER
	100000
#else
	DYNSTRINGBUFFER
#endif
];
DYMOLA_STATIC2 Real RealbufferNon[
#ifndef DYNREALBUFFER
	70000
#else
	DYNREALBUFFER/10
#endif
];
DYMOLA_STATIC2 Integer IntegerbufferNon[
#ifndef DYNINTEGERBUFFER
	50000
#else
	DYNINTEGERBUFFER
#endif
];
DYMOLA_STATIC2 SizeType SizebufferNon[
#ifndef DYNINTEGERBUFFER
	50000
#else
	DYNINTEGERBUFFER
#endif
];
DYMOLA_STATIC2 String StringbufferNon[
#ifndef DYNSTRINGBUFFER
	10000
#else
	DYNSTRINGBUFFER
#endif
];
DYMOLA_STATIC2 char simplestringNon[
#ifndef DYNSTRINGBUFFER
	10000
#else
	DYNSTRINGBUFFER
#endif
];
DYMOLA_STATIC Real* EndRealbufferNon=RealbufferNon+sizeof(RealbufferNon)/sizeof(*RealbufferNon);
DYMOLA_STATIC Integer* EndIntegerbufferNon=IntegerbufferNon+sizeof(IntegerbufferNon)/sizeof(*IntegerbufferNon);
DYMOLA_STATIC SizeType* EndSizebufferNon=SizebufferNon+sizeof(SizebufferNon)/sizeof(*SizebufferNon);
DYMOLA_STATIC String* EndStringbufferNon=StringbufferNon+sizeof(StringbufferNon)/sizeof(*StringbufferNon);
DYMOLA_STATIC char* EndsimplestringNon=simplestringNon+sizeof(simplestringNon)/sizeof(*simplestringNon);
#if (defined(_OPENMP) && !defined(DISABLE_DYMOLA_OPENMP))
DYMOLA_STATIC Real* EndRealbuffer=0;
#pragma omp threadprivate(EndRealbuffer)
DYMOLA_STATIC Integer* EndIntegerbuffer=0;
#pragma omp threadprivate(EndIntegerbuffer)
DYMOLA_STATIC SizeType* EndSizebuffer=0;
#pragma omp threadprivate(EndSizebuffer)
DYMOLA_STATIC String* EndStringbuffer=0;
#pragma omp threadprivate(EndStringbuffer)
DYMOLA_STATIC char* Endsimplestring=0;
#pragma omp threadprivate(Endsimplestring)
DYMOLA_STATIC Real* EndRealbuffer2=Realbuffer+sizeof(Realbuffer)/sizeof(*Realbuffer);
DYMOLA_STATIC Integer* EndIntegerbuffer2=Integerbuffer+sizeof(Integerbuffer)/sizeof(*Integerbuffer);
DYMOLA_STATIC SizeType* EndSizebuffer2=Sizebuffer+sizeof(Sizebuffer)/sizeof(*Sizebuffer);
DYMOLA_STATIC String* EndStringbuffer2=Stringbuffer+sizeof(Stringbuffer)/sizeof(*Stringbuffer);
DYMOLA_STATIC char* Endsimplestring2=simplestring+sizeof(simplestring)/sizeof(*simplestring);
#else
DYMOLA_STATIC Real* EndRealbuffer=Realbuffer+sizeof(Realbuffer)/sizeof(*Realbuffer);
DYMOLA_STATIC Integer* EndIntegerbuffer=Integerbuffer+sizeof(Integerbuffer)/sizeof(*Integerbuffer);
DYMOLA_STATIC SizeType* EndSizebuffer=Sizebuffer+sizeof(Sizebuffer)/sizeof(*Sizebuffer);
DYMOLA_STATIC String* EndStringbuffer=Stringbuffer+sizeof(Stringbuffer)/sizeof(*Stringbuffer);
DYMOLA_STATIC char* Endsimplestring=simplestring+sizeof(simplestring)/sizeof(*simplestring);
#endif
#else
DYMOLA_STATIC2 Real Realbuffer[];
DYMOLA_STATIC2 Integer Integerbuffer[];
DYMOLA_STATIC2 SizeType Sizebuffer[];
DYMOLA_STATIC2 String Stringbuffer[];
DYMOLA_STATIC2 char simplestring[];
DYMOLA_STATIC2 Real* EndRealbuffer;
DYMOLA_STATIC2 Integer* EndIntegerbuffer;
DYMOLA_STATIC2 SizeType* EndSizebuffer;
DYMOLA_STATIC2 String* EndStringbuffer;
DYMOLA_STATIC2 char* Endsimplestring;

DYMOLA_STATIC2 Real RealbufferNon[];
DYMOLA_STATIC2 Integer IntegerbufferNon[];
DYMOLA_STATIC2 SizeType SizebufferNon[];
DYMOLA_STATIC2 String StringbufferNon[];
DYMOLA_STATIC2 char simplestringNon[];
DYMOLA_STATIC2 Real* EndRealbufferNon;
DYMOLA_STATIC2 Integer* EndIntegerbufferNon;
DYMOLA_STATIC2 SizeType* EndSizebufferNon;
DYMOLA_STATIC2 String* EndStringbufferNon;
DYMOLA_STATIC2 char* EndsimplestringNon;
#endif


#ifndef __cplusplus
typedef struct BufferObject BufferObject;
typedef struct MarkObject MarkObject;
#endif

/* Memory allocation */
DYMOLA_STATIC MarkObject PushMark(void);
DYMOLA_STATIC void RePushMark(MarkObject*);
DYMOLA_STATIC void Release(); /* Release: used after each matrix assignment in the function */
DYMOLA_STATIC void PopMark(MarkObject oldMark);/* At the end of the function */
DYMOLA_STATIC void PopMarkMarks();/* Major pop, e.g. at end of intgegration */
DYMOLA_STATIC char* GetStringMark();
DYMOLA_STATIC void SetStringMark(char*);
DYMOLA_STATIC const char* SqueezeString(const char*s, char*startMark);

/* Data structure for arrays of arbitrary dimension, stored in Fortran Style. */
/* Adressing of individual elements start at 1 */
typedef struct IntegerArray {
  SizeType ndims; /* Length of dims */
  SizeType *dims; /* A.dims[i-1]=size(a,i) */
  Integer *data;
} IntegerArray;
typedef struct RealArray {
  SizeType ndims;
  SizeType *dims;  
  Real *data;
} RealArray;
typedef struct StringArray {
	SizeType ndims;
	SizeType *dims;
	String *data;
} StringArray;

/* Each argument is tagged by Subtag */
enum Subtag {
  Colon, /* Corresponds to a[:] */
  Range, /* Corresponds to a[f:t] (two Integer arguments)*/
  RangeRange, /* Corresponds to a[f:s:t] (three Integer arguments) */
  Vector, /* Corresponds to a[v] where v is IntegerArray (actually vector) (one IntegerArray argument) */
  Index, /* Correspons to a[i] where i is an Integer (one Integer argument) */
  EndMark /* End of the argument list */
};
/* Start of common routines */
DYMOLA_STATIC RealArray RealNonTemporary(SizeType ndims,...);
DYMOLA_STATIC IntegerArray IntegerNonTemporary(SizeType ndims,...);
DYMOLA_STATIC StringArray StringNonTemporary(SizeType ndims,...);

DYMOLA_STATIC SizeType FindIndex(SizeType ndims,SizeType*dims,va_list ap);
DYMOLA_STATIC SizeType *SizeTemp(SizeType r);
DYMOLA_STATIC RealArray RealMatch(const RealArray a);
DYMOLA_STATIC IntegerArray IntegerMatch(const IntegerArray a);
DYMOLA_STATIC StringArray StringMatch(const StringArray a);

/* Construct array from sizes, using variable number of arguments */
DYMOLA_STATIC RealArray RealTemporary(SizeType ndims,...);

/* Special cases for vectors and matrices (most often used) */
DYMOLA_STATIC RealArray RealTemporaryMatrix(SizeType r,SizeType c);
DYMOLA_STATIC RealArray RealTemporaryVector(SizeType r);
/* Assignment */
DYMOLA_STATIC void RealAssign(RealArray a,const RealArray b);
/* Indexing to set/get elements */

DYMOLA_STATIC void* RecordElement(const RealArray a,...);
DYMOLA_STATIC Real RealElement(const RealArray a,...);
/* Sizes */
DYMOLA_STATIC Integer RealSize(const RealArray a,SizeType i);
DYMOLA_STATIC IntegerArray RealSizes(const RealArray a);
/* Set element, note that val is prior to the index list. */
DYMOLA_STATIC void SetRealElement(Real val,RealArray a,...);
/* For debug write out */
DYMOLA_STATIC void RealWrite(const RealArray a);

/* Construct Arrays from other arrays */
DYMOLA_STATIC RealArray RealArrayArray(SizeType narg,RealArray first,...);
/* Construct arrays from scalars */
DYMOLA_STATIC RealArray RealScalarArray(SizeType narg,...);

/* Construct from Record Arrays */
DYMOLA_STATIC RealArray RecordArrayRealSlice(const RealArray a,size_t off);
DYMOLA_STATIC RealArray RecordArrayRealArraySlice(const RealArray a,size_t off);

/* Concatenate along dimensions 'along' (1..ndims) and given nargs arguments */
DYMOLA_STATIC RealArray RealCat(SizeType along,SizeType nargs,RealArray first,...);

/* The helper in Modelica */
DYMOLA_STATIC RealArray RealPromote(const RealArray a,SizeType n);
DYMOLA_STATIC RealArray RealPromoteScalar(const Real x,SizeType n);
/* Use as: RealGetSub(a,Colon,Index,3,Range,3,4,EndMark)=a[:,3,3:4] */
DYMOLA_STATIC RealArray RealGetSub(const RealArray a,...);
DYMOLA_STATIC void RealPutSub(const RealArray a,RealArray out,...);

/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
/* Fill */
DYMOLA_STATIC RealArray RealFillAssign(RealArray res,const Real t);
DYMOLA_STATIC RealArray RealFill(const Real t,SizeType ndims,...);
DYMOLA_STATIC RealArray RealFillArray(const RealArray a,SizeType ndims,...);
DYMOLA_STATIC Real Realscalar(const RealArray a);
/* Matrix operations not limited to numeric matrices */
DYMOLA_STATIC RealArray Realvector(const RealArray a);
DYMOLA_STATIC RealArray Realmatrix(const RealArray a);
DYMOLA_STATIC RealArray Realtranspose(const RealArray a);
DYMOLA_STATIC RealArray Realouterproduct(const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray Realsymmetric(const RealArray a);
/* End of common routines for String*/
/* Basic operations, add, subtract, scale*/
/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
DYMOLA_STATIC RealArray RealAddAssign(RealArray res,const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealAdd(const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealSubtractAssign(RealArray res,const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealSubtract(const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealScaleAssign(RealArray res,const RealArray a,const Real t);
DYMOLA_STATIC RealArray RealScale(const RealArray a,const Real t);
DYMOLA_STATIC RealArray RealMinusAssign(RealArray res,const RealArray a);
DYMOLA_STATIC RealArray RealMinus(const RealArray a);
/* sum, max, min, and product */
DYMOLA_STATIC Real Realsum(const RealArray a);
DYMOLA_STATIC Real RealAbssum(const RealArray a);
DYMOLA_STATIC Real RealAbssumDiff(const RealArray a,const RealArray b);
DYMOLA_STATIC Real Realmax(const RealArray a);
DYMOLA_STATIC Real Realmin(const RealArray a);
DYMOLA_STATIC Real Realproduct(const RealArray a);

DYMOLA_STATIC RealArray Realdiagonal(const RealArray a);

DYMOLA_STATIC RealArray Realcross(const RealArray x,const RealArray y);
DYMOLA_STATIC RealArray Realskew(const RealArray x);
/* Multiply */
DYMOLA_STATIC RealArray RealMultiplyMMAssign(RealArray res,
                                     const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealMultiplyMVAssign(RealArray res,const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealMultiplyVMAssign(RealArray res,const RealArray a,const RealArray b);
DYMOLA_STATIC Real RealMultiplyVV(const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealMultiplyMM(const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealMultiplyMV(const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealMultiplyVM(const RealArray a,const RealArray b);
DYMOLA_STATIC RealArray RealIdentity(SizeType n);
DYMOLA_STATIC RealArray RealPow(const RealArray a,const Integer n);
/* For from:stride:to */
DYMOLA_STATIC RealArray RealRange(const Real from,const Real to,const Real stride);

/* End of common routines with Integer */
/* Unique routines */

DYMOLA_STATIC RealArray linspace(const Real from,const Real to,const Integer n);

/* Go from IntegerArray to RealArray */
DYMOLA_STATIC RealArray RealConvertInteger(const IntegerArray a);
DYMOLA_STATIC IntegerArray IntegerConvertReal(const RealArray a);
DYMOLA_STATIC RealArray RealScaleDiv(const RealArray a,const Real t);
/* Routines for Integer */
/* Create Array-temporaries given the dimensions */

/* Construct array from sizes, using variable number of arguments */
DYMOLA_STATIC IntegerArray IntegerTemporary(SizeType ndims,...);
/* Special cases for vectors and matrices (most often used) */
DYMOLA_STATIC IntegerArray IntegerTemporaryMatrix(SizeType r,SizeType c);
DYMOLA_STATIC IntegerArray IntegerTemporaryVector(SizeType r);
/* Assignment */
DYMOLA_STATIC void IntegerAssign(IntegerArray a,const IntegerArray b);
/* Indexing to set/get elements */

DYMOLA_STATIC Integer IntegerElement(const IntegerArray a,...);
/* Sizes */
DYMOLA_STATIC Integer IntegerSize(const IntegerArray a,SizeType i);
DYMOLA_STATIC IntegerArray IntegerSizes(const IntegerArray a);
/* Set element, note that val is prior to the index list. */
DYMOLA_STATIC void SetIntegerElement(Integer val,IntegerArray a,...);
/* For debug write out */
DYMOLA_STATIC void IntegerWrite(const IntegerArray a);

/* Construct Arrays from other arrays */
DYMOLA_STATIC IntegerArray IntegerArrayArray(SizeType narg,IntegerArray first,...);
/* Construct arrays from scalars */
DYMOLA_STATIC IntegerArray IntegerScalarArray(SizeType narg,...);

/* Construct from Record Arrays */
DYMOLA_STATIC IntegerArray RecordArrayIntegerSlice(const RealArray a,size_t off);
DYMOLA_STATIC IntegerArray RecordArrayIntegerArraySlice(const RealArray a,size_t off);

/* Concatenate along dimensions 'along' (1..ndims) and given nargs arguments */
DYMOLA_STATIC IntegerArray IntegerCat(SizeType along,SizeType nargs,IntegerArray first,...);

/* The helper in Modelica */
DYMOLA_STATIC IntegerArray IntegerPromote(const IntegerArray a,SizeType n);
DYMOLA_STATIC IntegerArray IntegerPromoteScalar(const Integer x,SizeType n);
/* Use as: IntegerGetSub(a,Colon,Index,3,Range,3,4,EndMark)=a[:,3,3:4] */
DYMOLA_STATIC IntegerArray IntegerGetSub(const IntegerArray a,...);
/* Use as IntegerPutSub(a, out,Index,3,Colon,Range,3,4) yields out[3,:,3:4]=a; */
DYMOLA_STATIC void IntegerPutSub(const IntegerArray a,IntegerArray out,...);


/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
/* Fill */
DYMOLA_STATIC IntegerArray IntegerFillAssign(IntegerArray res,const Integer t);
DYMOLA_STATIC IntegerArray IntegerFill(const Integer t,SizeType ndims,...);
DYMOLA_STATIC IntegerArray IntegerFillArray(const IntegerArray a,SizeType ndims,...);
DYMOLA_STATIC Integer Integerscalar(const IntegerArray a);
/* Matrix operations not limited to numeric matrices */
DYMOLA_STATIC IntegerArray Integervector(const IntegerArray a);
DYMOLA_STATIC IntegerArray Integermatrix(const IntegerArray a);
DYMOLA_STATIC IntegerArray Integertranspose(const IntegerArray a);
DYMOLA_STATIC IntegerArray Integerouterproduct(const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray Integersymmetric(const IntegerArray a);
/* End of common routines for String*/
/* Basic operations, add, subtract, scale*/
/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
DYMOLA_STATIC IntegerArray IntegerAddAssign(IntegerArray res,const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerAdd(const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerSubtractAssign(IntegerArray res,const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerSubtract(const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerScaleAssign(IntegerArray res,const IntegerArray a,const Integer t);
DYMOLA_STATIC IntegerArray IntegerScale(const IntegerArray a,const Integer t);
DYMOLA_STATIC IntegerArray IntegerMinusAssign(IntegerArray res,const IntegerArray a);
DYMOLA_STATIC IntegerArray IntegerMinus(const IntegerArray a);
/* sum, max, min, and product */
DYMOLA_STATIC Integer Integersum(const IntegerArray a);
DYMOLA_STATIC Integer IntegerAbssum(const IntegerArray a);
DYMOLA_STATIC Integer Integermax(const IntegerArray a);
DYMOLA_STATIC Integer Integermin(const IntegerArray a);
DYMOLA_STATIC Integer Integerproduct(const IntegerArray a);

DYMOLA_STATIC IntegerArray Integerdiagonal(const IntegerArray a);

DYMOLA_STATIC IntegerArray Integercross(const IntegerArray x,const IntegerArray y);
DYMOLA_STATIC IntegerArray Integerskew(const IntegerArray x);
/* Multiply */
DYMOLA_STATIC IntegerArray IntegerMultiplyMMAssign(IntegerArray res,
                                     const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerMultiplyMVAssign(IntegerArray res,const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerMultiplyVMAssign(IntegerArray res,const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC Integer IntegerMultiplyVV(const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerMultiplyMM(const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerMultiplyMV(const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerMultiplyVM(const IntegerArray a,const IntegerArray b);
DYMOLA_STATIC IntegerArray IntegerIdentity(SizeType n);
DYMOLA_STATIC IntegerArray IntegerPow(const IntegerArray a,const Integer n);
/* For from:stride:to */
DYMOLA_STATIC IntegerArray IntegerRange(const Integer from,const Integer to,const Integer stride);

/* Create Array-temporaries given the dimensions */
/* Construct array from sizes, using variable number of arguments */
DYMOLA_STATIC StringArray StringTemporary(SizeType ndims,...);
/* Special cases for vectors and matrices (most often used) */
DYMOLA_STATIC StringArray StringTemporaryMatrix(SizeType r,SizeType c);
DYMOLA_STATIC StringArray StringTemporaryVector(SizeType r);
/* Assignment */
DYMOLA_STATIC void StringAssign(StringArray a,const StringArray b);
/* Indexing to set/get elements */

DYMOLA_STATIC const char* StringElement(const StringArray a,...);
/* Sizes */
DYMOLA_STATIC Integer StringSize(const StringArray a,SizeType i);
DYMOLA_STATIC IntegerArray StringSizes(const StringArray a);
/* Set element, note that val is prior to the index list. */
DYMOLA_STATIC void SetStringElement(const char* val,StringArray a,...);
/* For debug write out */
DYMOLA_STATIC void StringWrite(const StringArray a);

/* Construct Arrays from other arrays */
DYMOLA_STATIC StringArray StringArrayArray(SizeType narg,StringArray first,...);
/* Construct arrays from scalars */
DYMOLA_STATIC StringArray StringScalarArray(SizeType narg,...);

/* Construct from Record Arrays */
DYMOLA_STATIC StringArray RecordArrayStringSlice(const RealArray a,size_t off);
DYMOLA_STATIC StringArray RecordArrayStringArraySlice(const RealArray a,size_t off);

/* Concatenate along dimensions 'along' (1..ndims) and given nargs arguments */
DYMOLA_STATIC StringArray StringCat(SizeType along,SizeType nargs,StringArray first,...);

/* The helper in Modelica */
DYMOLA_STATIC StringArray StringPromote(const StringArray a,SizeType n);
DYMOLA_STATIC StringArray StringPromoteScalar(const char* x,SizeType n);
/* Actual put of submatrix */
/* Use as: StringGetSub(a,Colon,Index,3,Range,3,4,EndMark)=a[:,3,3:4] */
DYMOLA_STATIC StringArray StringGetSub(const StringArray a,...);
/* Use as StringPutSub(a, out,Index,3,Colon,Range,3,4) yields out[3,:,3:4]=a; */
DYMOLA_STATIC void StringPutSub(const StringArray a,StringArray out,...);
DYMOLA_STATIC StringArray StringCopy(const StringArray a);

/* For each operation Op(...) we create a temporary result res */
/*  and call OpAssign(res,...) */
/* The operations Op(...) are convenient and used in the code */
/* Fill */
DYMOLA_STATIC StringArray StringFillAssign(StringArray res,const char* t);
DYMOLA_STATIC StringArray StringFill(const char* t,SizeType ndims,...);
DYMOLA_STATIC StringArray StringFillArray(const StringArray a,SizeType ndims,...);
DYMOLA_STATIC const char* Stringscalar(const StringArray a);
/* Matrix operations not limited to numeric matrices */
DYMOLA_STATIC StringArray Stringvector(const StringArray a);
DYMOLA_STATIC StringArray Stringmatrix(const StringArray a);
DYMOLA_STATIC StringArray Stringtranspose(const StringArray a);
DYMOLA_STATIC StringArray Stringsymmetric(const StringArray a);
/* End of common routines for String*/
static IntegerArray identity(Integer n) {return IntegerIdentity(n);}
static Integer real2integer(Real x) {return (Integer)(floor(x));}
DYMOLA_STATIC Integer VectorWhenHandle(IntegerArray cond,IntegerArray eval,IntegerArray evalnew,Integer Event,Integer*AnyEvent);
DYMOLA_STATIC SizeType CommonNrElements(SizeType ndims, SizeType* dims);
DYMOLA_STATIC SizeType RealNrElements(const RealArray a);
DYMOLA_STATIC SizeType IntegerNrElements(const IntegerArray);
DYMOLA_STATIC SizeType StringNrElements(const StringArray);
/* Convert between C and Fortran storage */
DYMOLA_STATIC RealArray RealSwitchMajor(const RealArray);
DYMOLA_STATIC IntegerArray IntegerSwitchMajor(const IntegerArray);
DYMOLA_STATIC StringArray StringSwitchMajor(const StringArray);
DYMOLA_STATIC void RealSwitchMajorAssign(RealArray,const RealArray);
DYMOLA_STATIC void IntegerSwitchMajorAssign(IntegerArray,const IntegerArray);
DYMOLA_STATIC void StringSwitchMajorAssign(StringArray,const StringArray);
DYMOLA_STATIC RealArray readMatrix(const char*fil,const char*matnam,Integer m,Integer n);
DYMOLA_STATIC IntegerArray readMatrixSize(const char*fil,const char*matnam);
DYMOLA_STATIC StringArray readMATmatrices_M(const char*fil);
DYMOLA_STATIC Integer writeMatrix(const char*fil,const char*matnam,const RealArray mat,int append);
DYMOLA_STATIC Real RealReadScalar(const char*fil,const char*matnam);
DYMOLA_STATIC RealArray RealReadArray(const char*fil,const char*matnam,Integer ndims);
DYMOLA_STATIC Integer IntegerReadScalar(const char*fil,const char*matnam);
DYMOLA_STATIC IntegerArray IntegerReadArray(const char*fil,const char*matnam,Integer ndims);
DYMOLA_STATIC String StringReadScalar(const char*fil,const char*matnam);
DYMOLA_STATIC StringArray StringReadArray(const char*fil,const char*matnam,Integer ndims);
DYMOLA_STATIC RealArray RealLeading(int,int,RealArray);
DYMOLA_STATIC IntegerArray IntegerLeading(int,int,IntegerArray);
DYMOLA_STATIC StringArray StringLeading(int,int,StringArray);
DYMOLA_STATIC void writeArrays(const char*fileName,int nargs,...);
DYMOLA_STATIC char* StringAllocate(SizeType len);
DYMOLA_STATIC String StringAdd(String a,String b);
DYMOLA_STATIC String Real2String(Real x,Integer minwidth,Integer precision);
DYMOLA_STATIC String Integer2String(Integer x,Integer minwidth,Integer precision);
DYMOLA_STATIC String Real2String3(Real x,Integer leftJustified,Integer minwidth,Integer precision);
DYMOLA_STATIC String Real2String2(Real x,Integer leftJustified,Integer minwidth);
DYMOLA_STATIC String Integer2String2(Integer x,Integer leftJustified,Integer minwidth);
DYMOLA_STATIC String Boolean2String2(Integer x,Integer leftJustified,Integer minwidth);
DYMOLA_STATIC String Real2StringFormat(Real x,String s);
DYMOLA_STATIC void CopySlice(Real*x,RealArray y);
DYMOLA_STATIC RealArray RealTemporaryDense(Real*d,SizeType ndims,...);
DYMOLA_STATIC IntegerArray IntegerTemporaryDense(Real*d,SizeType ndims,...);
DYMOLA_STATIC IntegerArray IntegerTemporaryDenseOrig(Integer*d,SizeType ndims,...);
DYMOLA_STATIC StringArray StringTemporaryDense(String*d,SizeType ndims,...);
DYMOLA_STATIC RealArray RealInverse(const RealArray A);
DYMOLA_STATIC IntegerArray NOTArray(const IntegerArray);
DYMOLA_STATIC IntegerArray ANDArray(const IntegerArray,const IntegerArray);
DYMOLA_STATIC IntegerArray ORArray(const IntegerArray,const IntegerArray);
DYMOLA_STATIC String ConvertToNonTempString(String s);
DYMOLA_STATIC StringArray ConvertToNonTempStringArray(StringArray s);

LIBDS_API int dymli2_(int* sysnr, int *fact, double *a, int* lda, int *n,double* b, double *Time, int *Event, int* PrintEvent, double* dwork, int* iwork, int *factor, int* ierr);

#endif
