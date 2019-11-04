/* Utility definitions for code generated
 * from Modelica translator.
 *
 * Author: Hilding Elmqvist, Dynasim AB
 *
 * Copyright (C) 1998-2001 Dynasim AB.
 * All rights reserved.
 *
 * Version: 1.0, 1998-08-18
 *          1.1, 1998-10-21, handling of states
 *          1.2, 1998-10-29, handling of events
 *          1.3, 1999-01-13, matrix features
 *          1.4, 1999-02-22, support for solving nonlinear equations
*/

#if !defined(RT)
#include <assert.h>
#endif
#ifndef DYMOLA_MOUTIL_C
#include <math.h>
#define DYMOLA_MOUTIL_C
#include <math.h>
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE)
#include "amat.h"
#endif
#if defined(DymolaStoreProtectedVariables_)
static int DYNStoreProtectedVariables=1;
#else
static int DYNStoreProtectedVariables=0;
#endif

#if !defined(DSE_STRUCT)
 #if defined(DS_EMBEDDED)
  #define DSE_STRUCT sts->
 #else
  #define DSE_STRUCT
 #endif
#endif
#ifndef DYNX
#if _MSC_VER>=1700
#define DYNX(s,i) (*(s+i))
#else
#define DYNX(s,i) s[i]
#endif
#endif

#define Modelica
DYMOLA_STATIC int* delayID;
DYMOLA_STATIC int Buffersize;

#include "dsblock.h"
#ifndef DYNassert_static
#define DYNassert_static(e) do { enum { DYN_assert_static_=1/(e) }; } while(0)
#endif


struct NonAlias_ {int tag;const char*n;const char*d;double val;double mi;double ma;double w;int ix;};

#undef  SpuriousEvents_
#define SpuriousEvents_ 0

/* ---------------------------------------------------- */

/* Macros to define variable names. */ 

#define SParameter(i)                ((const char*)(DYNX(cuser_,i)))
#define Parameter(i)                 DYNX(DP_,i)
#define Variable(i)                  DYNX(W_,i)
#define State(i)                     DYNX(X_,i)
#define Derivative(i)                DYNX(F_,i)
#define Input(i)                     DYNX(U_,i)
#define Output(i)                    DYNX(Y_,i)
#define Aux(i)                       DYNX(Aux_,i)
#define SAux(i)                      DYNX(DYNAuxStr_,i+DYNStrInit(did_))
#define DState(i)					 DYNX(D_,i)
#define Previous(i)					 DYNX(XP_,i)

/* ---------------------------------------------------- */

/* Macros for equations */

#define IF   (

#define THEN ) ? (

#define ELSE ) :

#define AND  &&

#define OR   ||

#define NSAND &

#define NSOR |

#define NOT  !


#define EventEPS 1E-8

#define Crossing(x, y, nr, op) \
  (Qenable_[nr]=true, \
  QZ_[2*nr]   = (x) - (y) - EventEPS, \
  QZ_[2*nr+1] = (x) - (y) + EventEPS

static 
#if defined(_MSC_VER) && _MSC_VER>=1200
__inline
#elif __GNUC__
__inline
#endif
double ScaledCross(double x,double y,double nom,double*r) {
	double v=x-y;
	*r=(x>nom) ? x : (-x>nom)? -x : nom;
    return v;
}

#define Greater(x, sx, y, sy, nr) HandleEvent2( (ScaledCross((x),(y),1.0,Qscaled_+nr)),sx,">",sy,(nr+1), 0, 0)

#define Less(x, sx, y, sy, nr) HandleEvent2( (ScaledCross((x),(y),1.0,Qscaled_+nr)) ,sx, "<", sy,(nr+1), 1, 0)

#define GreaterEqual(x,sx,y,sy,nr) HandleEvent2( (ScaledCross((x),(y),1.0,Qscaled_+nr)), sx, ">=", sy,(nr+1), 1, 1) 

#define LessEqual(x,sx,y,sy,nr) HandleEvent2( (ScaledCross((x),(y),1.0,Qscaled_+nr)), sx, "<=", sy,(nr+1), 0, 1)

#define GreaterMinor(x, sx, y, sy, nr) HandleEvent2Minor( (ScaledCross((x),(y),1.0,Qscaled_+nr)),sx,">",sy,(nr+1), 0, 0)

#define LessMinor(x, sx, y, sy, nr) HandleEvent2Minor( (ScaledCross((x),(y),1.0,Qscaled_+nr)) ,sx, "<", sy,(nr+1), 1, 0)

#define GreaterEqualMinor(x,sx,y,sy,nr) HandleEvent2Minor( (ScaledCross((x),(y),1.0,Qscaled_+nr)), sx, ">=", sy,(nr+1), 1, 1) 

#define LessEqualMinor(x,sx,y,sy,nr) HandleEvent2Minor( (ScaledCross((x),(y),1.0,Qscaled_+nr)), sx, "<=", sy,(nr+1), 0, 1)

#define GreaterS(x, sx, y, sy, nr) HandleEvent2S( (ScaledCross((x),(y),1.0,Qscaled_+nr)) ,sx,">",sy,(nr+1), 0, 0)

#define LessS(x, sx, y, sy, nr) HandleEvent2S( (ScaledCross((x),(y),1.0,Qscaled_+nr)) ,sx, "<", sy,(nr+1), 1, 0)

#define GreaterEqualS(x,sx,y,sy,nr) HandleEvent2S( (ScaledCross((x),(y),1.0,Qscaled_+nr)), sx, ">=", sy,(nr+1), 1, 1) 

#define LessEqualS(x,sx,y,sy,nr) HandleEvent2S( (ScaledCross((x),(y),1.0,Qscaled_+nr)), sx, "<=", sy,(nr+1), 0, 1)

#define absEvent(x,sx,nr) (Qscaled_[nr]=1,HandleEvent2((x),sx," > ","0",(nr+1),0,0)?QRel_[nr]:-QRel_[nr])
#define signEvent(x,sx,nr1,nr2) (Qscaled_[nr1]=Qscaled_[nr2]=1,HandleEvent2((x),sx," > ","0",(nr1+1),0,0)?1: \
	HandleEvent2(QRel_[nr1],sx," < ","0",(nr2+1),1,0)?-1:0)
#define simplesignEvent(x,sx,nr1) (Qscaled_[nr1]=1,HandleEvent2((x),sx," > ","0",(nr1+1),0,0)?1:-1)

#define Equal(x, y, nr) \
  ((x) == (y))

#define NotEqual(x, y, nr) \
  ((x) != (y))

#define pre(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;AnyEvent_=true;}\
	else if (DYNX(QPre_,nr)!=x && !(!Init_ && DymolaOneIteration_ == 5 && !final_)) {\
       AnyEvent_=true;\
       if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2))) VariableChanged(sx,x,DYNTime);\
       if (!Init_ && final_==1 && (DymolaOneIteration_==2 || DymolaOneIteration_==3 || DymolaOneIteration_==5)) ; else DYNX(QPre_,nr)=x;\
    }

#define preCont(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;}\
	else {\
       DYNX(QPre_,nr)=x;\
    }
#define preW(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;}\
	else if (DYNX(QPre_,nr)!=x && !(!Init_ && DymolaOneIteration_ == 5 && !final_)) {\
	   if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2))) VariableChanged(sx,x,DYNTime);\
       if (!Init_ && final_==1 && (DymolaOneIteration_==2 || DymolaOneIteration_==3 || DymolaOneIteration_==5)) ; else DYNX(QPre_,nr)=x;\
    }

#define preD(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;AnyEvent_=true;}\
	else if (DYNX(QPre_,nr)!=x && !(!Init_ && DymolaOneIteration_ == 5 && !final_)) {\
       AnyEvent_=true;\
	   AnyDEvent_=true;\
       if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2))) VariableChanged(sx,x,DYNTime);\
       if (!Init_ && final_==1 && (DymolaOneIteration_==2 || DymolaOneIteration_==3 || DymolaOneIteration_==5)) ; else DYNX(QPre_,nr)=x;\
    }

#define preContD(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;}\
	else {\
	   if (DYNX(QPre_,nr)!=x) AnyDEvent_=true;\
       DYNX(QPre_,nr)=x;\
    }
#define preWD(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;}\
	else if (DYNX(QPre_,nr)!=x && !(!Init_ && DymolaOneIteration_ == 5 && !final_)) {\
	   AnyDEvent_=true;\
	   if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2)))  VariableChanged(sx,x,DYNTime);\
       if (!Init_ && final_==1 && (DymolaOneIteration_==2 || DymolaOneIteration_==3 || DymolaOneIteration_==5)) ; else DYNX(QPre_,nr)=x;\
    }

#define preI(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;AnyEvent_=true;}\
    else if (DYNX(QPre_,nr)!=x && !(!Init_ && DymolaOneIteration_ == 5 && !final_)) {\
       AnyEvent_=true;\
	   AnyIEvent_=true;\
       if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2))) VariableChanged(sx,x,DYNTime);\
       if (!Init_ && final_==1 && (DymolaOneIteration_==2 || DymolaOneIteration_==3 || DymolaOneIteration_==5)) ; else DYNX(QPre_,nr)=x;\
    }

#define preContI(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;}\
	else {\
	   if (DYNX(QPre_,nr)!=x) AnyIEvent_=true;\
       DYNX(QPre_,nr)=x;\
    }
#define preWI(x, sx, start, nr)\
    if (Init_ && (DymolaOneIteration_ == 0 || !final_ && DymolaOneIteration_ == 2) ) { DYNX(QPre_,nr)=start;}\
	else if (DYNX(QPre_,nr)!=x && !(!Init_ && DymolaOneIteration_ == 5 && !final_)) {\
	   AnyIEvent_=true;\
	   if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2))) VariableChanged(sx,x,DYNTime);\
       if (!Init_ && final_==1 && (DymolaOneIteration_==2 || DymolaOneIteration_==3 || DymolaOneIteration_==5)) ; else DYNX(QPre_,nr)=x;\
    }

static double spliceFunction2(double x,double deltax) {
	if (deltax<0) {
		x=-x;
		deltax=-deltax;
	}
	if (x<=-deltax) {
		return 0;
	} else if (x>=deltax) {
		return 1;
	} else {
		double piHalf=asin(1.0);
		return (1+tanh(tan((x/deltax)*piHalf)))/2;
	}
}
static double spliceFunction2der(double x,double deltax,double dx,double ddeltax) {
	if (deltax<0) {
		x=-x;
		deltax=-deltax;
		dx=-dx;
		ddeltax=-ddeltax;
	}
	if (x<=-deltax || x>=deltax) {
		return 0;
	} else {
		double piHalf=asin(1.0);
		double x1=(x/deltax);
		double y=x1*piHalf;
		double z=cosh(tan(y))*cos(y);
		return ((dx-x1*ddeltax)*(piHalf)/(2*deltax))/(z*z);
	}
}

#define spliceFunction(pos, neg, x, deltax, id) \
  (((double*)DYNhelp)[id]=spliceFunction2((x),(deltax)), \
    ((double*)DYNhelp)[id]*(((double*)DYNhelp)[id]>0 ? (pos) : 0.0)+(1-((double*)DYNhelp)[id])*(((double*)DYNhelp)[id]<1 ? (neg) : 0.0))

#define spliceFunction_der(pos, neg, x, deltax, pos_der, neg_der, x_der, deltax_der, id) \
  (((double*)DYNhelp)[id]=spliceFunction2((x),(deltax)), \
    ((double*)DYNhelp)[id]*(((double*)DYNhelp)[id]>0 ? (pos_der) : 0.0)+(1-((double*)DYNhelp)[id])*(((double*)DYNhelp)[id]<1 ? (neg_der) : 0.0)\
    + (((double*)DYNhelp)[id]>0 && ((double*)DYNhelp)[id]<1 ? spliceFunction2der((x),(deltax),(x_der),(deltax_der))*((pos)-(neg)): 0.0))


#define DecoupleRemember_(x, nr) (Init_?x:DYNX(QPre_,nr))
#define DoDecoupleRemember_(x, nr) (DYNX(QPre_,nr)=x)
#define StartDecoupleBlock {if ((Init_||*time==did_->InitTime_var||*time>(did_->decoupleTime_var))&&final_&&!solverCall) {\
	(did_->decoupleTime_var)=*time;
	
#define EndDecoupleBlock }}
#define PRE(x, nr) DYNX(QPre_,nr)
#define Remember_(x, nr) \
	x = (eq_remember_enable_linear ?\
		DYNX(EqRemember1_,nr)+eq_remember_time_factor*(DYNX(EqRemember2_,nr)-DYNX(EqRemember1_,nr)) :\
		DYNX(EqRemember2_,nr))
#define RememberSimple_(x, nr) \
	  DYNX(EqRemember2_,nr)

#define DoRememberCommon_(sectionCondition, replaceOld, x, val, nr)\
	if (replaceOld) EqRemember1_[nr] = EqRemember2_[nr];\
	if (sectionCondition) {DYNX(EqRemember2_,nr) = (initializationPhase_ == 1) ? (val) : (x);}\
	else if (rememberCrossing && DYNInitialGuessPolynomialUpdate_)\
		{ if (rememberCrossing & 2) DYNX(EqRemember2_,nr) = (x); else DYNX(EqRemember1_,nr) = (x); }
#define DoRemember_(x, val, nr) DoRememberCommon_(rememberDynamicsSection, (did_->eqRememberReplaceOldDynamics), x, val, nr)
#define DoRememAcc_(x, val, nr) DoRememberCommon_(rememberAcceptedSection, (did_->eqRememberReplaceOldAccepted), x, val, nr)

#define event(x) \
  (x)

#define noEvent(x) \
  (x)

#define reinit(x, expr) \
  (x = expr, AnyEvent_=1, AnyREvent_=1, 0);

#define reinitNew(x, expr, hv, iv) \
  (((DymolaOneIteration_==0) ? (x = expr):(hv=expr,iv=1)), AnyEvent_=1, AnyREvent_=1, 0);

#define reinitNewArray(x, expr, hv, iv) \
  (((DymolaOneIteration_==0) ? (RealAssign(x,expr)):(RealAssign(hv,expr),iv=1)), AnyEvent_=1, AnyREvent_=1, 0);


#define DYNdelay(expr, DelayTime, MaxDelayTime, nr, str) \
  (delayID[nr]= (delayID[nr]==0) ? delayIni2(DelayStruct_, nr, Dymola_abs(DelayTime), Buffersize, DYNTime, expr) : delayID[nr], \
    delayFunction2(DelayStruct_, nr, Dymola_abs(DelayTime), MaxDelayTime, DYNTime, expr, str))

#define DYNdelayDC(expr, DelayTime, nr, nrC) \
	delayDCFunction2(DelayStruct_, expr, DelayTime, delayID+nr, nr, Buffersize, DYNTime, DYNEvent, QRel_+nrC, Qp_+nrC, Qn_+nrC,\
		Qenable_+1+nrC, QZ_+2*nrC,&AnyEvent_)

#define DYNdelayDD(expr, DelayTime, nr, nrT) \
	delayDDFunction2(DelayStruct_, expr, DelayTime, delayID+nr, nr, Buffersize, DYNTime, DYNEvent, QTimed_+nrT)


/* ---------------------------------------------------- */

#ifdef DYMOSIM
LIBDS_API void DynErrCountCollectIterationNamesAndNominals(int nx_orig, int nx2, int start, int n, const char*const*varnames, const double*const nominals);
#else
static void DynErrCountCollectIterationNamesAndNominals(int nx_orig, int nx2, int start, int n, const char*const*varnames, const double*const nominals) { ; }
#endif

#define RememberDeclare_\
	const int eq_remember_accepted_variable_ = (*icall_ == 3);\
	int eq_remember_enable_linear = 0;\
	double eq_remember_1_time_ = -1e33;\
	double eq_remember_2_time_ = -1e33;\
	double eq_remember_time_factor = 1.0;

#define RememberInit_\
	if (eq_remember_accepted_variable_) {eq_remember_1_time_ = EqRemAcc1Time_; eq_remember_2_time_ = EqRemAcc2Time_;}\
	else {eq_remember_1_time_ = EqRemember1Time_; eq_remember_2_time_ = EqRemember2Time_;}\
	eq_remember_enable_linear = (solverHandleEq_ &&\
		((!eq_remember_accepted_variable_ && (((int)Dymola_abs(DYNInitialGuessInterpolation_)) & 1)) || \
		(eq_remember_accepted_variable_ && (((int)Dymola_abs(DYNInitialGuessInterpolation_)) & 2))) && \
		eq_remember_1_time_>-1e30 && eq_remember_1_time_<eq_remember_2_time_);\
	if (eq_remember_enable_linear)\
		eq_remember_time_factor = Dymola_min(4, (DYNTime - eq_remember_1_time_) / (eq_remember_2_time_ - eq_remember_1_time_));

#define NonLinearSystemOfEquations(Jac, res, x, n, nextra, numericJacobian, nr, base, hv, nhv, iv, niv) \
	{ \
    DeclareDidRealMatrix1(Jac, n, n, hv); \
	Real *Jac##__DWork=(&hv)+n*n; \
	int Jac##__LDWork=(20+((n+15)*n)/2+nextra);\
    int *Jac##__IWork=&iv;\
	static const int QBase=base;\
	struct MyJmpBuf saved_jmp_buf_env; \
    DeclareDidRealVector1(res, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+0*n]); \
    DeclareDidRealVector1(x, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+1*n]); \
	DeclareDidRealVector1(xInitial, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+2*n]); \
	DeclareDidRealVector1(xJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+3*n]); \
	DeclareDidRealVector1(resJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+4*n]); \
	DeclareDidRealVector1(resJac2, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+5*n]); \
	double lambda_=-2;\
	int *storedXP_=(&iv)+20+n;\
	int firstTime=1;\
	int* storedResetCounterP=(&iv)+21+n;\
	int veryFirstTime=ResetCounter_!=*(storedResetCounterP);\
	int veryFirstTime2=0;\
	int changePmatrix_=0;\
	int changePmatrixOld_=0;\
	int changePloop_=0;\
	int QNnl;int Qinfo,QNLnr,QiOpt,QInfRev,DAEsolverMode;\
	int DAEModeDummyJacobian = 0;\
	RememberDeclare_\
	 DeclareDidRealMatrix2(Jac, n, n, hv);\
	 DeclareDidRealVector2(res, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+0*n]); \
    DeclareDidRealVector2(x, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+1*n]); \
	DeclareDidRealVector2(xInitial, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+2*n]); \
	DeclareDidRealVector2(xJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+3*n]); \
	DeclareDidRealVector2(resJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+4*n]); \
	DeclareDidRealVector2(resJac2, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+5*n]); \
	DYNassert_static(nhv==n*n+(20+((n+15)*n)/2)+nextra+6*n && niv==22+n);\
	DAEsolverMode=(QBase!=-2) && DAEsolver_;\
	RememberInit_\
	if (veryFirstTime) {int i;(*storedXP_)=0;for(i=0;i<n;i++) x##__internal[i]=0,res##__internal[i]=0;for(i=0;i<20+n;++i) Jac##__IWork[i]=0;for(i=0;i<20+((n+15)*n)/2;++i) Jac##__DWork[i]=0;}\
	again##nr: firstTime=1; againsecond##nr:\
	if (DymolaUserHomotopy) {lambda_=1-DymolaHomotopyLambda;if (DymolaHomotopyLambda==0) veryFirstTime=1;}\
	veryFirstTime2=(*(storedResetCounterP)==0);\
    *(storedResetCounterP)=ResetCounter_;\
	saved_jmp_buf_env = DYNGlobal_jmp_buf_env;\
	if (DAEsolverMode) DynErrCountCollectIterationNamesAndNominals(nx_, nx2_, base + 1, n, varnames_, nominal_); \
      QNnl = n; \
	  if (DYNEvent || ! DAEsolverMode || atDAEEvent_) { \
		if (PrintEvent&(1 << 17) && QNLcalls && nr > 0 && nr <= QNLmax) ++QNLcalls[nr - 1]; \
        QNLnr = nr; \
        QiOpt = numericJacobian+1; \
        QInfRev  = -11+(numericJacobian?1:-DymolaNonLinearIterations_); \
		if ((!DymolaNewJacobian_ && !veryFirstTime) || !firstTime) QInfRev=-20-DymolaNonLinearIterations_-10*(1-DymolaAllowNewJacobianAnyway_);\
        if (inJacobian_ && !(*storedXP_)) {RealAssign(xJac,x); RealAssign(resJac,res); (*storedXP_)=1;\
		} else if ((*storedXP_)) {RealAssign(x,xJac);(*storedXP_)=inJacobian_;}\
	  } else { \
	    int i_;\
        QInfRev  = 0;\
        for (i_=1; i_<=QNnl; i_++) \
          SetVector(x, i_, ((double*)(DSE_STRUCT X_))[i_+QBase]); \
      }

#define NonLinearSystemOfEquationsNH(Jac, res, x, n, nextra, numericJacobian, nr, base, nin, hv, nhv, iv, niv) \
	{ \
    DeclareDidRealMatrix1(Jac, n, n, hv); \
	Real *Jac##__DWork=(&hv)+n*n; \
	int Jac##__LDWork=(20+((n+15)*n)/2+nextra);\
    int *Jac##__IWork=&iv;\
	static const int QBase=base;\
	struct MyJmpBuf saved_jmp_buf_env; \
    DeclareDidRealVector1(res, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+0*n]); \
    DeclareDidRealVector1(x, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+1*n]); \
	DeclareDidRealVector1(xInitial, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+2*n]); \
	DeclareDidRealVector1(xJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+3*n]); \
	DeclareDidRealVector1(resJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+4*n]); \
	DeclareDidRealVector1(resJac2, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+5*n]); \
	Real *hom1=(&hv)+n*n+(20+((n+15)*n)/2)+6*n;\
	Real *hom2=(&hv)+n*n+(20+((n+15)*n)/2)+6*n+nin;\
	Real homlocal,homlocaldelta,homlocalfail;\
	double lambda_=-2;\
	Real *savedVariables[nin];\
	const int QNin = nin;\
	int *storedXP_=(&iv)+20+n;\
	int firstTime=1;\
	int* storedResetCounterP=(&iv)+21+n;\
	int veryFirstTime=ResetCounter_!=*(storedResetCounterP);\
	int veryFirstTime2=0;\
	int changePmatrix_=0;\
	int changePmatrixOld_=0;\
	int changePloop_=0;\
	int QNnl;int Qinfo,QNLnr,QiOpt,QInfRev,DAEsolverMode;\
	int DAEModeDummyJacobian = 0;\
	RememberDeclare_\
	 DeclareDidRealMatrix2(Jac, n, n, hv);\
	 DeclareDidRealVector2(res, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+0*n]); \
    DeclareDidRealVector2(x, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+1*n]); \
	DeclareDidRealVector2(xInitial, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+2*n]); \
	DeclareDidRealVector2(xJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+3*n]); \
	DeclareDidRealVector2(resJac, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+4*n]); \
	DeclareDidRealVector2(resJac2, n, (&hv)[n*n+(20+((n+15)*n)/2)+nextra+5*n]); \
	DYNassert_static(nhv==n*n+(20+((n+15)*n)/2)+nextra+2*nin+6*n && niv==22+n);\
	DAEsolverMode=(QBase!=-2) && DAEsolver_;homlocal=-1;homlocaldelta=0;homlocalfail=0;\
	RememberInit_\
	if (veryFirstTime) {int i;(*storedXP_)=0;for(i=0;i<n;i++) x##__internal[i]=0,res##__internal[i]=0;for(i=0;i<20+n;++i) Jac##__IWork[i]=0;for(i=0;i<20+((n+15)*n)/2;++i) Jac##__DWork[i]=0; for(i=0;i<nin;++i) savedVariables[i]=0;}\
	again##nr: firstTime=1; againsecond##nr:\
	if (DymolaUserHomotopy) {lambda_=1-DymolaHomotopyLambda;if (DymolaHomotopyLambda==0) veryFirstTime=1;}\
	veryFirstTime2=(*(storedResetCounterP)==0);\
    *(storedResetCounterP)=ResetCounter_;\
	saved_jmp_buf_env = DYNGlobal_jmp_buf_env;\
	if (DAEsolverMode) DynErrCountCollectIterationNamesAndNominals(nx_, nx2_, base + 1, n, varnames_, nominal_); \
      QNnl = n; \
	  if (DYNEvent || ! DAEsolverMode || atDAEEvent_) { \
		if (PrintEvent&(1 << 17) && QNLcalls && nr > 0 && nr <= QNLmax) ++QNLcalls[nr - 1]; \
        QNLnr = nr; \
        QiOpt = numericJacobian+1; \
        QInfRev  = -11+(numericJacobian?1:-DymolaNonLinearIterations_); \
		if ((!DymolaNewJacobian_ && !veryFirstTime) || !firstTime) QInfRev=-20-DymolaNonLinearIterations_-10*(1-DymolaAllowNewJacobianAnyway_);\
        if (inJacobian_ && !(*storedXP_)) {RealAssign(xJac,x); RealAssign(resJac,res); (*storedXP_)=1;\
		} else if ((*storedXP_)) {RealAssign(x,xJac);(*storedXP_)=inJacobian_;}\
	  } else { \
	    int i_;\
		QInfRev  = 0;\
        for (i_=1; i_<=QNnl; i_++) \
          SetVector(x, i_, ((double*)X_)[i_+QBase]); \
      }


#define DummyNonLinear(Jac,residue,m,n,Pvar,var,stateP, hv, nhv, iv, niv) \
	{\
		LIBDS_API int CheckP(const double*,double*,int,int,int*,const double*);\
		LIBDS_API void ComputeP(const double*,double*,int,int,int,int*,double*);\
		DeclareDidRealMatrix1(JacCopy_,n,m,hv);\
		int i_,j_;\
		int*Pivots_=&iv;\
		DeclareDidRealMatrix2(JacCopy_,n,m,hv);\
		DYNassert_static(nhv==n*m && niv==3*n);\
		if (Init_ || (DYNEvent && changePmatrixOld_)) {\
		    int info;\
			int uno_=1,n_=n;\
			RealArray varP_=var;\
			ComputeP(&(GetMatrix(Jac,1,1)),&(GetMatrix(JacCopy_,1,1)),m,m,n,Pivots_,Pvar);\
			{int m1_=n-m;double d1_=1.0,d2_=0.0;\
				dgemv_("T",&n_,&m1_,&d1_,Pvar,&n_,varP_.data,&uno_,\
				&d2_,stateP,&uno_);}\
				for(i_=m+1;i_<=n;i_++) {double d_=-(stateP)[i_-(m+1)];\
                for(j_=1;j_<=n;j_++) d_+=(Pvar)[(i_-(m+1))*n+(j_-1)]*varP_.data[j_-1];\
				SetVector(residue,i_,d_);}\
			for(i_=m+1;i_<=n;i_++) for(j_=1;j_<=n;j_++) SetMatrix(Jac,i_,j_,(Pvar)[(i_-(m+1))*n+(j_-1)]);\
			Release();\
			changePmatrixOld_=0;\
			if ((PrintEvent&(1<<13)) || (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2)))) ReportDummySelection(varnames_,Pvar,DYNTime,m,n,PrintEvent);\
			AnyREvent_=true;\
		} else if (CheckP(&(GetMatrix(Jac,1,1)),&(GetMatrix(JacCopy_,1,1)),m,n,Pivots_,Pvar)) changePmatrix_=1;\
		if ((PrintEvent&(1<<14))&&terminal()) ReportDummySelection(varnames_,Pvar,DYNTime,m,n,PrintEvent);\
	}


#define SetInit(x, i, j, var, val) \
  if (firstTime) \
    var = val; \
  if (firstTime && !(DYNEvent || ! DAEsolverMode || atDAEEvent_)) \
    SetMatrix(x, i, j, var); \
  else \
	var = GetMatrix(x, i, j)

#define SetInitVector(x, i, var, val) \
  if (!DymolaUserHomotopy && lambda_>-1 && lambda_<1 || DymolaUserHomotopy && DymolaHomotopyLambda>0) {} else\
  if (firstTime) \
	var = val; \
  if ((DAEsolverMode && !DYNEvent && !atDAEEvent_) || !firstTime || inJacobian_) \
     var = GetVector(x, i); \
  else \
    SetVector(x, i, var); \


#define SetInitVectorNH(x, i, var, val) \
  if (homlocal>0 || DymolaUserHomotopy && DymolaHomotopyLambda>0) var=GetVector(x, i); else\
  if (firstTime) \
    var = val; \
  if ((DAEsolverMode && !DYNEvent && !atDAEEvent_) || !firstTime || inJacobian_) \
     var = GetVector(x, i); \
  else \
    SetVector(x, i, var); \


#define Residues \
  firstTime=0;\
  while (true) {\
	if (setjmp(DYNGlobal_jmp_buf_env.TheBuffer)!=0) {\
       PopAllMarks();\
       if (DAEsolverMode && !DYNEvent && !atDAEEvent_) goto leave;\
  	   GlobalError_ = 0;\
	   if (QInfRev>0) {\
          QInfRev+=100;\
		  if (!(PrintEvent&(1<<10))) DymosimMessage("Non-linear solver will attempt to handle this problem.\n");\
	   }\
	   else {\
	      if (!(PrintEvent&(1<<10))) DymosimMessage("First evaluation failed for non-linear solver.\n");\
		  if (solverHandleEq_) {EqRemember2Time_=-1e40;EqRemAcc2Time_=-1e40;}\
		  if (!((*(DSE_STRUCT QiErr)||MixedFailFlag_)&&(QInfRev==0))) QInfRev=-1;\
	   }\
	} else {\

#define DYNIsDummy \
	DAEModeDummyJacobian = ((DAEsolverMode && !DYNEvent && !atDAEEvent_ && !inJacobian_ && QInfRev == 0) ? 1 : 0);

#define Jacobian(Jac) \
  if (QInfRev == 2 || QInfRev<=-11 && QInfRev>-20 || QInfRev==32 || DAEModeDummyJacobian) { 


#if 1
LIBDS_API void dymnon8_(int*qinfrev, int qiopt, int qnnl, double*qsol, double* qres, double* qjac,
	double*qjac2,double*qres2,int lqjac2d,
	double qtol, double qtoldesired,
	int*qinfo, double*qd, int lqd, int*idum, int printevent, int inJacobian_, int qnlnr, double time,
	int*qnlfunc, int*qnljac, int qnlmax, const char*const*varnames, const double*nom, int*ierr___,
	const char*tag, int idemand, int*const advicePrinted, int preciseTol);

#define DymNonlinear3(QInfRev,QiOpt,QNnl,QSol,QRes,QJac,QJac2,QRes2,LQJac2,Qtol,Qtol2,Qinfo,QD,LQD,DumI, \
	PrintEvent,QNLnr,Time,QNLfunc,QNLjac,QNLmax,ierr_,tag,idemand,advicePrinted) {int i1_,i2_;\
    i1_ = LQD; \
    i2_ = QNLmax; \
	if (QNLnr > QNLmax) { \
      DymosimMessage("Internal error: The capacity for solving nonlinear systems of equations, QNLmax, needs to be increased"); \
      goto leave; \
      } \
	  if (QNnl==0) {QInfRev=0;}\
      else {dymnon8_(&QInfRev,QiOpt,QNnl,QSol,QRes,QJac,QJac2,QRes2,LQJac2,Qtol,Qtol2,&Qinfo,QD,i1_,DumI,\
	  PrintEvent,inJacobian_,QNLnr,Time,QNLfunc,QNLjac,i2_,varnames_,nominal_,ierr_,tag,idemand,&advicePrinted,\
	  Init_ && *idemand_==0 && *icall_==0 && DymolaHomotopyUsed && !DymolaUserHomotopy);}}
#elif 0
LIBDS_API void dymnon7_(int*qinfrev, int qiopt, int qnnl, double*qsol,double* qres,double* qjac,
					 double qtol, double qtoldesired,
	int*qinfo, double*qd, int lqd, int*idum, int printevent, int inJacobian_, int qnlnr, double time, 
	int*qnlfunc, int*qnljac, int qnlmax, const char*const*varnames,const double*nom,int*ierr___,
	const char*tag,int idemand,int*const advicePrinted,int preciseTol);

#define DymNonlinear2(QInfRev,QiOpt,QNnl,QSol,QRes,QJac,Qtol,Qtol2,Qinfo,QD,LQD,DumI, \
	PrintEvent,QNLnr,Time,QNLfunc,QNLjac,QNLmax,ierr_,tag,idemand,advicePrinted) {int i1_,i2_;\
    i1_ = LQD; \
    i2_ = QNLmax; \
	if (QNLnr > QNLmax) { \
      DymosimMessage("Internal error: The capacity for solving nonlinear systems of equations, QNLmax, needs to be increased"); \
      goto leave; \
      } \
	  if (QNnl==0) {QInfRev=0;}\
      else {dymnon7_(&QInfRev,QiOpt,QNnl,QSol,QRes,QJac,Qtol,Qtol2,&Qinfo,QD,i1_,DumI,\
	  PrintEvent,inJacobian_,QNLnr,Time,QNLfunc,QNLjac,i2_,varnames_,nominal_,ierr_,tag,idemand,&advicePrinted,\
	  Init_ && *idemand_==0 && *icall_==0 && DymolaHomotopyUsed && !DymolaUserHomotopy);}}
#else
LIBDS_API void dymnon6_(int*qinfrev, int qiopt, int qnnl, double*qsol,double* qres,double* qjac,
					 double qtol, double qtoldesired,
	int*qinfo, double*qd, int lqd, int*idum, int printevent, int inJacobian_, int qnlnr, double time, 
	int*qnlfunc, int*qnljac, int qnlmax, const char*const*varnames,const double*nom,int*ierr___);
#define DymNonlinear2(QInfRev,QiOpt,QNnl,QSol,QRes,QJac,Qtol,Qtol2,Qinfo,QD,LQD,DumI, \
	PrintEvent,QNLnr,Time,QNLfunc,QNLjac,QNLmax,ierr_,tag,idemand,&advicePrinted) {int i1_,i2_;\
    i1_ = LQD; \
    i2_ = QNLmax; \
    if (QNLnr > QNLmax) { \
      DymosimMessage("Internal error: The capacity for solving nonlinear systems of equations, QNLmax, needs to be increased"); \
      goto leave; \
      } \
	  dymnon6_(&QInfRev,QiOpt,QNnl,QSol,QRes,QJac,Qtol,Qtol2,&Qinfo,QD,i1_,DumI,\
	  PrintEvent,inJacobian_,QNLnr,Time,QNLfunc,QNLjac,i2_,varnames_,nominal_,ierr_);}

#endif
/*
\
     if (QInfRev==0 && Qinfo==4) goto leave;
*/

#define OverdeterminedNonLinear(Jac,Jac2,residue,residue2,m,n,m1,m2,var,hv,nhv) \
	{\
		LIBDS_API void CreateJacFull(const double*,double*,int,int,int,const int*);\
		LIBDS_API void ComputePfull(const double*,double*,int,int,int,int,int,int*,int*,double*,const double*,const double*);\
		LIBDS_API int CheckPfull(const double*,double*,int,int,int,int,int,int*,const int*);\
		DeclareDidRealMatrix1(JacCopy_,m,n,hv);\
		int i_,j_;\
		DeclareDidRealMatrix2(JacCopy_,m,n,hv);\
		DYNassert_static(nhv==n*m);\
		if (Init_ || (DYNEvent && changePmatrixOld_)) {\
			ComputePfull(&(GetMatrix(Jac2,1,1)),&(GetMatrix(JacCopy_,1,1)),m,m,n,m1,m2,IWork_+(m+n),IWork_,0,0,0);\
			changePmatrixOld_=0;\
		} else if (CheckPfull(&(GetMatrix(Jac2,1,1)),&(GetMatrix(JacCopy_,1,1)),m,m,n,m1,m2,IWork_+(m+n),IWork_)) changePmatrix_=1;\
		CreateJacFull(&(GetMatrix(Jac2,1,1)),&(GetMatrix(Jac,1,1)),m,m,n,IWork_);\
	} \
} {\
	LIBDS_API void NonLinearRoutine(int,int,double*,const int*,const double*,const double*,const double*,const double*);\
	NonLinearRoutine(m,n,&(GetVector(residue,1)),IWork_,&(GetVector(residue2,1)),0,0,0);\

#define OverdeterminedDummyNonLinear(Jac,Jac2,residue,residue2,l,m,nRequired,n,m1,m2,Pvar,var,stateP,hv,nhv) \
	{\
		LIBDS_API void CreateJacFull(const double*,double*,int,int,int,const int*);\
		LIBDS_API void ComputePfull3(const double*,double*,int,int,int,int,int,int,int*,int*,double*,const double*,const double*);\
		LIBDS_API int CheckPfull3(const double*,double*,int,int,int,int,int,int,int*,const int*);\
		DeclareDidRealMatrix1(JacCopy_,m,n,hv);\
		int i_,j_;\
		DeclareDidRealMatrix2(JacCopy_,m,n,hv);\
		DYNassert_static(nhv==n*m);\
		if (Init_ || (DYNEvent && changePmatrixOld_)) {\
			RealArray varP_=var;\
			ComputePfull3(&(GetMatrix(Jac2,1,1)),&(GetMatrix(JacCopy_,1,1)),l,m,n,m1,m2,nRequired,IWork_+(l+n),IWork_,Pvar,varP_.data,stateP);\
			Release();\
			changePmatrixOld_=0;\
			if ((PrintEvent&(1<<13)) || (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2)))) ReportDummySelection(varnames_,Pvar,DYNTime,m,n,PrintEvent);\
			AnyREvent_=true;\
		} else if (CheckPfull3(&(GetMatrix(Jac2,1,1)),&(GetMatrix(JacCopy_,1,1)),l,m,n,m1,m2,nRequired,IWork_+(l+n),IWork_)) changePmatrix_=1;\
		CreateJacFull(&(GetMatrix(Jac2,1,1)),&(GetMatrix(Jac,1,1)),l,m,n,IWork_);\
	} \
} {\
	LIBDS_API void NonLinearRoutine(int,int,double*,const int*,const double*,const double*,const double*,const double*);\
	RealArray varP_=var;\
	NonLinearRoutine(m,n,&(GetVector(residue,1)),IWork_,&(GetVector(residue2,1)),Pvar,varP_.data,stateP);\
	Release();


#define SolveNonLinearSystemOfEquationsInner(Jac, Jac2, res2, ld2, res, x, tag) \
  } \
  }  DYNGlobal_jmp_buf_env=saved_jmp_buf_env;\
     if (!(QInfRev != 0 || ((DYNEvent && !Init_ && changePmatrix_)?(changePmatrixOld_=changePmatrix_,QInfRev=-1,changePmatrix_=0,changePloop_++<5):0)))\
        break;\
    if (DYNEvent || ! DAEsolverMode || atDAEEvent_) { \
	  double Qtol1=Qtol;\
      double Qtol2=DymolaAimForHighAccuracy_ ? Dymola_min(EPS_*0.5,0.01*Qtol) : Qtol;\
	  if (inJacobian_ && (*storedXP_)) RealSubtractAssign(res,res,resJac);\
     DymNonlinear3(QInfRev,QiOpt,QNnl,&(GetVector(x,1)),&(GetVector(res,1)),\
      &(GetMatrix(Jac,1,1)),Jac2, res2, ld2,Qtol1,Qtol2,Qinfo, \
	  Jac##__DWork,Jac##__LDWork,Jac##__IWork,PrintEvent,QNLnr,DYNTime,QNLfunc,QNLjac,QNLmax,QiErr,tag,*idemand_,DYNAdvicePrinted_); \
	  if (*QiErr != 0) {*QiErr=0;QInfRev=0;DymosimError("Inner failed");}

#define SolveNonLinearSystemOfEquations(Jac, Jac2, res2, ld2, res, x, tag) \
  } \
  }  DYNGlobal_jmp_buf_env=saved_jmp_buf_env;\
	 if (QInfRev == 0) {\
	    if (DYNEvent && !Init_ && changePmatrix_) {\
		   changePmatrixOld_=changePmatrix_;\
           QInfRev=-1;\
		   changePmatrix_=0;\
		   if (changePloop_++>=5) break;\
		} else break;\
	 }\
    if (DYNEvent || ! DAEsolverMode || atDAEEvent_) { \
	  double Qtol1=Qtol;\
      double Qtol2=DymolaAimForHighAccuracy_ ? Dymola_min(EPS_*0.5,0.01*Qtol) : Qtol;\
 	  if (inJacobian_ && (*storedXP_)) RealSubtractAssign(res,res,resJac);\
     DymNonlinear3(QInfRev,QiOpt,QNnl,&(GetVector(x,1)),&(GetVector(res,1)),\
      &(GetMatrix(Jac,1,1)),Jac2, res2, ld2, Qtol1,Qtol2,Qinfo, \
	  Jac##__DWork,Jac##__LDWork,Jac##__IWork,PrintEvent,QNLnr,DYNTime,QNLfunc,QNLjac,QNLmax,QiErr,tag,*idemand_,DYNAdvicePrinted_);

#ifdef DYNDebugHomotopy_
DYMOLA_STATIC void WriteHomotopyItem(double v, const char*str);
#define DYNWriteHomotopy(x,lambda) \
	{int i_;\
	WriteHomotopyItem(lambda, "lambda");\
	for (i_ = 1; i_ <= QNnl; i_++)\
		WriteHomotopyItem(GetVector(x,i_), varnames_[i_-1]);\
	WriteHomotopyItem(0,0);\
	}
#else
static void WriteHomotopyItem(double v, const char*str) { ; }
#define DYNWriteHomotopy(x,lambda) 0
#endif

#define SolveNonLinearSystemOfEquationsNH(Jac, Jac2, res2, ld2, res, x, nr, tag) \
  } \
  }  DYNGlobal_jmp_buf_env=saved_jmp_buf_env;\
	 if (QInfRev == 0) {\
	    if (DYNEvent && !Init_ && changePmatrix_) {\
		   changePmatrixOld_=changePmatrix_;\
           QInfRev=-1;\
		   changePmatrix_=0;\
		   if (changePloop_++>=5) break;\
		} else break;\
	 }\
    if (DYNEvent || ! DAEsolverMode || atDAEEvent_) { \
	  double Qtol1=Qtol;\
      double Qtol2=DymolaAimForHighAccuracy_ ? Dymola_min(EPS_*0.5,0.01*Qtol) : Qtol;\
 	  if (inJacobian_ && (*storedXP_)) RealSubtractAssign(res,res,resJac);\
     DymNonlinear3(QInfRev,QiOpt,QNnl,&(GetVector(x,1)),&(GetVector(res,1)),\
      &(GetMatrix(Jac,1,1)),Jac2, res2, ld2, Qtol1,Qtol2,Qinfo, \
	  Jac##__DWork,Jac##__LDWork,Jac##__IWork,PrintEvent,QNLnr,DYNTime,QNLfunc,QNLjac,QNLmax,QiErr,tag,*idemand_,DYNAdvicePrinted_); \
	  if (*QiErr && DYNEvent && homlocal==-1) { *QiErr=0;DymosimMessage("Trying homotopy");DYNWriteHomotopy(x,0);homlocal=0;homlocaldelta=0.125;goto again##nr;}\
	  if (*QiErr && DYNEvent && homlocal>0 && homlocaldelta>1e-4) {*QiErr=0;DymosimMessage("Homotopy reducing");homlocal-=homlocaldelta;homlocalfail=homlocal;homlocaldelta/=2;homlocal+=homlocaldelta;goto again##nr;}

#define NonLinearSystemSave(a, nr) \
	if (homlocal==-1) {if (DYNEvent) hom1[nr]=a; else hom2[nr]=a; savedVariables[nr] = &a;}\
	else a=hom1[nr]*homlocal+hom2[nr]*(1-homlocal);


#define SolveNonLinearSystemOfEquationsInit(Jac, Jac2, res2, ld2, res, x, tag) \
  } \
  }  DYNGlobal_jmp_buf_env=saved_jmp_buf_env;\
     if (!(QInfRev != 0 || ((DYNEvent && !Init_ && changePmatrix_)?(changePmatrixOld_=changePmatrix_,QInfRev=-1,changePmatrix_=0,changePloop_++<5):0)))\
        break;\
    if (DYNEvent || ! DAEsolverMode || atDAEEvent_) { \
	  double Qtol1=Qtol;\
      double Qtol2=DymolaAimForHighAccuracy_ ? Dymola_min(EPS_*0.5,0.01*Qtol) : Qtol;\
      if (lambda_<0 && !inJacobian_) {Qtol1=Qtol2;}\
	  if (lambda_==-2 && !inJacobian_ && (QInfRev==1 || QInfRev<-1)) {RealAssign(resJac,res);lambda_=-1;}\
	  if (lambda_>0 && !DymolaUserHomotopy) {RealSubtractAssign(res,res,RealScale(resJac,lambda_));PopAllMarks();}\
	  if (inJacobian_ && (*storedXP_)) RealSubtractAssign(res,res,resJac);\
     DymNonlinear3(QInfRev,QiOpt,QNnl,&(GetVector(x,1)),&(GetVector(res,1)),\
      &(GetMatrix(Jac,1,1)),Jac2, res2, ld2, Qtol1,Qtol2,Qinfo, \
	  Jac##__DWork,Jac##__LDWork,Jac##__IWork,PrintEvent,QNLnr,DYNTime,QNLfunc,QNLjac,QNLmax,(DSE_STRUCT QiErr),tag,*idemand_,DYNAdvicePrinted_);





#define SolveNonLinearSystemOfEquationsMixed(Jac, Jac2, res2, ld2, res, x, tag) \
  } 	\
  } DYNGlobal_jmp_buf_env=saved_jmp_buf_env;\
   if (!(QInfRev != 0 || ((DYNEvent && !Init_ && changePmatrix_)?(changePmatrixOld_=changePmatrix_,QInfRev=-1,changePmatrix_=0,changePloop_++<5):0)))\
        break;\
    if (DYNEvent || ! DAEsolverMode || atDAEEvent_) { \
	  double Qtol1=Qtol;\
      double Qtol2=DymolaAimForHighAccuracy_ ? Dymola_min(EPS_*0.5,0.01*Qtol) : Qtol;\
	  if (inJacobian_ && (*storedXP_)) RealSubtractAssign(res,res,resJac);\
     DymNonlinear3(QInfRev,QiOpt,QNnl,&(GetVector(x,1)),&(GetVector(res,1)),\
      &(GetMatrix(Jac,1,1)),Jac2, res2, ld2, Qtol1,Qtol2,Qinfo, \
	  Jac##__DWork,Jac##__LDWork,Jac##__IWork,PrintEvent,QNLnr,DYNTime,QNLfunc,QNLjac,QNLmax,QiErr,tag,*idemand_,DYNAdvicePrinted_); \
	  if (*QiErr != 0) {MixedFailFlag_=*QiErr;*QiErr=0;QInfRev=0;}

#define VerifyOverdeterminedResidual(res1, n1, res2, n2, s) \
	if (QInfRev == 0 && !(DYNEvent && !Init_ && changePmatrix_)) {\
		if (!inJacobian_) {\
		int i;double res2=0,res1=0;\
		for(i=1;i<=n1;++i) res1+=sqr(GetVector(res1, i));for(i=1;i<=n2;++i) res2+=sqr(GetVector(res2, i));\
		if (res2>res1*1000+Qtol*Qtol*10) {*QiErr=1;if (!(PrintEvent&(1<<10))) {DymosimMessage("Too large residual for overdetermined system");DymosimMessage(s);}goto leave;}\
		}\
	}

#define EndNonLinearSystemOfEquations(res, x) \
     } \
	if (*QiErr != 0) goto leave; \
	 triggerStepEvent_=triggerStepEvent_|| (changePmatrix_ && !DYNEvent);\
	} \
    if (DAEsolverMode) {\
	  int i_;\
	  triggerStepEvent_=triggerStepEvent_|| (changePmatrix_ && !DYNEvent);\
      if (!DYNEvent && !atDAEEvent_) for (i_=1; i_<=QNnl; i_++) \
        ((double*)F_)[i_+QBase] = GetVector(res,i_); \
	  else for (i_=1; i_<=QNnl; i_++) \
        ((double*)X_)[i_+QBase] = GetVector(x,i_); \
	}\
 }

#define EndNonLinearSystemOfEquationsNH(res, x, nr) \
     } \
	if (*QiErr != 0) \
		{if (savedVariables && hom1) {int i__; for (i__ = 0; i__ < QNin; ++i__) {if (savedVariables[i__]) *(savedVariables[i__]) = hom1[i__];}} \
		 if (homlocal >= 0) WriteHomotopyItem(1,0);\
		 goto leave;} \
	 triggerStepEvent_=triggerStepEvent_|| (changePmatrix_ && !DYNEvent);\
	} \
    if (DAEsolverMode) {\
	  int i_;\
	  triggerStepEvent_=triggerStepEvent_|| (changePmatrix_ && !DYNEvent);\
      if (!DYNEvent && !atDAEEvent_) for (i_=1; i_<=QNnl; i_++) \
        ((double*)F_)[i_+QBase] = GetVector(res,i_); \
	  else for (i_=1; i_<=QNnl; i_++) \
        ((double*)X_)[i_+QBase] = GetVector(x,i_); \
	}\
	if (homlocal!=-1 && homlocal!=1) {DYNWriteHomotopy(x,homlocal);if (homlocaldelta<0.05 && homlocal>homlocalfail+4*homlocalfail) homlocaldelta*=2;homlocal+=homlocaldelta;if (homlocal>1) homlocal=1;goto again##nr;}\
	else if (homlocal >= 1) WriteHomotopyItem(1,0);\
 }

#define EndNonLinearSystemOfEquationsInit(res, x,nr) \
     } \
	 if (*(DSE_STRUCT QiErr) != 0 && !(*(DSE_STRUCT QiErr)>=1 && *(DSE_STRUCT QiErr)<=4 && lambda_==-1)) {if (lambda_>=0) WriteHomotopyItem(1,0); goto leave;} \
	 triggerStepEvent_=triggerStepEvent_|| (changePmatrix_ && !DYNEvent);\
	 }\
	 if (*(DSE_STRUCT QiErr)>=1 && *(DSE_STRUCT QiErr)<=4 && lambda_==-1) {*(DSE_STRUCT QiErr)=0;lambda_=1;if (!(PrintEvent&(1<<10))) DymosimMessage("Trying to solve non-linear system using global homotopy-method.");if (DymolaHomotopyUsed){DymolaUserHomotopy=1;GlobalError_=-997;goto leave;} else DYNWriteHomotopy(x,lambda_); goto again##nr;} \
	 if (!DymolaHomotopyUsed) {if (lambda_>0) {DYNWriteHomotopy(x,lambda_); lambda_-=0.1; if (lambda_-1e-3<0) lambda_=0; goto again##nr;}\
							   else if (lambda_==0) WriteHomotopyItem(1,0);}\
   }








#define ModelicaPrintMatrixRows(Mat, nRows) \
  DymosimMessageDoubleMatrix(#Mat, &(GetMatrix(Mat,1,1)), nRows, \
  MatrixNrColumns(Mat), MatrixNrRows(Mat) )

#define MixedSystemOfEquations(n,hv)\
	{\
	  DeclareDidRealVector1(oldVector,n, hv); \
	  int changeflag = 1;\
	   int niter = 0;\
	   double deltaTheta = 1e-3;\
	   double deltaTheta2 = 1e-12;\
       DeclareDidRealVector2(oldVector,n, hv); \
       while (1) {\
	     if (MixedFailFlag_&&DYNEvent&&!changeflag) {AnyEvent_=1;AnyDEvent_=1;MixedFailFlag_=0;AnyEventParameter_=1;break;}\
         if (!changeflag && !MixedFailFlag_) break;\
	     if (MixedFailFlag_&&(niter>0) && !(PrintEvent&(1<<10))) DymosimMessage("Fixed point iterating to handle problem.");\
	     changeflag = 0;MixedFailFlag_ = 0;\
		 ++niter;\
      if (niter > 13) {\
	    if (PrintEvent&(1<<1)) DymosimMessageDouble("Fix point iteration did not converge at time :", DYNTime);\
		if (!AnyEvent_) MixedFailFlag_=1;\
		break;\
	   }

#define MixedInitialSystemOfEquations(n, hv)\
	{\
	  DeclareDidRealVector1(oldVector,n, hv); \
	  int changeflag = 1;\
	   int niter = 0;\
	   double deltaTheta = 1e-3;\
	   double deltaTheta2 = 1e-12;\
	   DeclareDidRealVector2(oldVector,n, hv); \
       while (changeflag) {\
		 ++niter;\
      if (niter > 13) {\
	  	MixedFailFlag_=true;\
	    if ((PrintEvent&(1<<1))||MixedFailFlag_&&!(PrintEvent&(1<<10))) DymosimMessageDouble("Fix point iteration did not converge at time :", DYNTime);\
		break;\
	  } \
    	  if (MixedFailFlag_&& DymolaHomotopyUsed && !DymolaUserHomotopy) {if (!(PrintEvent&(1<<10))) DymosimMessage("Solving using global homotopy-method.");MixedFailFlag_=0;DymolaUserHomotopy=1;GlobalError_=-997;goto leave;}\
	     if (MixedFailFlag_&&(niter>0) && !(PrintEvent&(1<<10))) DymosimMessage("Fixed point iterating to handle problem.");\
      changeflag = 0;MixedFailFlag_ = 0;


#define EndMixedSystemOfEquations\
	   }}}if (MixedFailFlag_) {*(DSE_STRUCT QiErr)=MixedFailFlag_;goto leave;}}

#define MixedModeStartBoolean \
	{ int mixedModeFlag=(DYNEvent || !RootFinder_) && (niter>1);\
          int thetaIter=-1;int thetaIterFlag=1;double mixedModeTheta,mixedModeTheta2;\
	  int thetaNr=0;\
	  for(;thetaIterFlag!=0;thetaIter++) { \
	        mixedModeTheta=mixedModeTheta2=1; \
		if (thetaIter>-1) { 

#define MixedModeInit(nr, hv) \
		} \
		if (mixedModeFlag) { \
			double *Qold_=&(hv);

#define ThetaMixedCross(j,nr) \
			if (thetaIter==-1) DYNX(Qold_,j)=DYNX(Qenable_,nr+1) ? DYNX(QRel_,nr) : 0; \
			else if (DYNX(Qold_,j)*DYNX(QRel_,nr)<0) {\
				double th=DYNX(Qold_,j)/(DYNX(Qold_,j)-DYNX(QRel_,nr));\
				if (th<mixedModeTheta) {if(th<mixedModeTheta-deltaTheta2) mixedModeTheta2=mixedModeTheta;\
					mixedModeTheta=th;thetaNr=nr;}\
				else if (th<mixedModeTheta2-deltaTheta2 && th>mixedModeTheta+deltaTheta2) {mixedModeTheta2=th;}\
			}

#define MixedModeEndBoolean \
		} \
		if (thetaIter==-1) continue; \
		if (thetaIterFlag==2) break; else thetaIterFlag=2;\
		if (mixedModeTheta<1-deltaTheta) {\
			changeflag=1;\
			mixedModeTheta=Dymola_min(mixedModeTheta+deltaTheta,(mixedModeTheta+mixedModeTheta2)/2);\
			if (PrintEvent&(1<<1)) DymosimMessageDouble("Shorter attempt for mixed equation system",mixedModeTheta);\
		} else {\
			mixedModeTheta=1;\
			thetaIterFlag=0;\
		}



#define UpdateVariable(var, val)\
	{\
		int val1 = val;\
		if (!inJacobian_ && var != val1) {changeflag = 1;var = val1;if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2))) VariableChanged(#var,val,DYNTime);}\
	}

#define UpdateVariableNamed(var, varn, val)\
	{\
		int val1 = val;\
		if (!inJacobian_ && var != val1) {changeflag = 1;var = val1;if (PrintEvent&(1<<1) && (!Init_ || PrintEvent&(1<<2))) VariableChanged(varn,val,DYNTime);}\
	}

#define UpdateReal(var, nr) \
if(mixedModeTheta<1) \
  var=GetVector(oldVector,nr)+(mixedModeTheta)*(var-GetVector(oldVector,nr));\
SetVector(oldVector, nr, var);

#if defined(DS_EMBEDDED)
#define TranslatedEquations\
	dse_GetVariables(vars, sts);\
    sectioncondition = true;\
    {

#define EndTranslatedEquations\
    PopAllMarks();\
	dse_SetVariables(vars, sts);\
    }
#define ModelFunctionEnd() \
	   return 0;finish: return 1;leave:return 2
#else
#define TranslatedEquations\
    sectioncondition = true;\
    {

#define EndTranslatedEquations\
    PopAllMarks();\
    }
#endif

#define DefaultSection\
    }\
    sectioncondition = true;\
    {\

#define InitialSection2\
    }\
	sectioncondition = initializationPhase_?initializationPhase_==2:(initial() && !continueSimulate_);\
    if (sectioncondition) {\
        *icall_ = 0;

#define InitialSectionB\
    }\
	sectioncondition = initializationPhase_?initializationPhase_==2:(initialAlsoContinue());\
    if (sectioncondition) {\
        *icall_ = 0;

#define InitialSection3\
    }\
	sectioncondition = (initializationPhase_==1) || (initial() && !continueSimulate_);\
    if (sectioncondition) {\
        *icall_ = 0;

#define InitialSection\
    }\
    sectioncondition = (initializationPhase_ || initialAlsoContinue()) && (DymolaOneIteration_<3);\
    if (sectioncondition) {\
        *icall_ = 0;

#define InitialBoundSection\
    }\
    sectioncondition = (initializationPhase_ || initialAlsoContinue()) && (DymolaOneIteration_<3) && (!DymolaUserHomotopy || DymolaUserHomotopy && DymolaHomotopyLambda==0);\
    if (sectioncondition) {\
        *icall_ = 0;

#define InitialStartSection2\
    }\
	sectioncondition = (initializationPhase_?initializationPhase_==2:(initial() && !continueSimulate_)) && (!DymolaUserHomotopy || DymolaHomotopyLambda<=0) && (DymolaOneIteration_<3);\
    if (sectioncondition) {\
        *icall_ = 0;

#define InitialStartSection3\
    }\
	sectioncondition = ((initializationPhase_==1) || (initial() && !continueSimulate_)) && (!DymolaUserHomotopy || DymolaHomotopyLambda<=0) && (DymolaOneIteration_<3);\
    if (sectioncondition) {\
        *icall_ = 0;

#define InitialStartSection\
    }\
    sectioncondition = (initializationPhase_ || initialAlsoContinue()) && (DymolaOneIteration_<3) && (!DymolaUserHomotopy || DymolaHomotopyLambda<=0);\
    if (sectioncondition) {\
        *icall_ = 0;

#define EndInitialSection\
	if (DymolaUserHomotopy) {if (DymolaHomotopyLambda<1) {if (GlobalError_==0)GlobalError_=-996;goto leave;} else DymolaUserHomotopy=0;DymolaHomotopyLambda=1;}

#define BoundParameterSection \
	}\
	sectioncondition = NewParameters_ && (!DymolaUserHomotopy || DymolaUserHomotopy && DymolaHomotopyLambda==0);\
    if (sectioncondition) {

#define BoundParameterConstantSection \
	}\
	sectioncondition = NewParameters_;\
    if (sectioncondition) {

DYMOLA_STATIC void initializeData(double *time, double* X_, double* XD_, double* U_, 
      double* DP_, int IP_[], Dymola_bool LP_[], 
      double* F_, double* Y_, double* W_, double QZ_[], 
      double duser_[], int iuser_[], void*cuser_[],
      int final_,int Init,int m_Event,int solverCall);
DYMOLA_STATIC void initializeDataNew(double *time, double* X_, double* XD_, double* U_,
	double* DP_, int IP_[], Dymola_bool LP_[],
	double* F_, double* Y_, double* W_, double QZ_[],
	double duser_[], int iuser_[], void*cuser_[], struct DYNInstanceData*,
	int final_, int solverCall);

#define InitializeData(fin) {\
      initializeDataNew(time, X_, XD_, U_, \
      DP_, IP_, LP_, \
      F_, Y_, W_, QZ_, \
      duser_, iuser_, cuser_, did_,\
      fin,fin&&(did_->DymolaEventOptional_var&&solverHandleEq_&&(*idemand_==4))); \
	   }

#define InitializeDataSolver() {\
      initializeDataNew(time, X_, XD_, U_, \
      DP_, IP_, LP_, \
      F_, Y_, W_, QZ_, \
      duser_, iuser_, cuser_, did_,\
      0,1); \
	   }

#define StartDataBlock DYMOLA_STATIC void initializeData(double *time, double* X_, double* XD_, double* U_, \
      double* DP_, int IP_[], Dymola_bool LP_[], \
      double* F_, double* Y_, double* W_, double QZ_[], \
      double duser_[], int iuser_[], void*cuser_[],\
	int final_,int Init,int m_Event,int solverCall) {\
	if (!DYNInitialGuessPolynomialUpdate_ && rememberOnlyAccepted_ != 0 && rememberOnlyAccepted_ != 2) return;\
	if (rememberOnlyAccepted_ < 0) rememberOnlyAccepted_ = -rememberOnlyAccepted_;\
	tempData.Init_var=Init;tempData.Event_var=m_Event;\
	initializeDataNew(time,X_,XD_,U_,DP_,IP_,LP_,F_,Y_,W_,QZ_,duser_,iuser_,cuser_,&tempData,final_,solverCall);}\
    DYMOLA_STATIC void initializeDataNew(double *time, double* X_, double* XD_, double* U_, \
      double* DP_, int IP_[], Dymola_bool LP_[], \
      double* F_, double* Y_, double* W_, double QZ_[], \
      double duser_[], int iuser_[], void*cuser_[], struct DYNInstanceData*did_,\
	int final_,int solverCall) {


#define StartEqBlock if (solverCall ? 1 :\
	(Init_||(DYNEvent&&final_)||(!solverHandleEq_&&!inJacobian_&&final_))) {\
	const int rememberDynamics = (rememberOnlyAccepted_ != 1);\
	const int rememberCrossing = (rememberOnlyAccepted_ >> 2);\
	const int rememberDynamicsSection = ((!rememberCrossing && (!solverCall || rememberDynamics)) || !DYNInitialGuessPolynomialUpdate_);\
	const int rememberAcceptedSection = ((!rememberCrossing && (!solverCall || rememberOnlyAccepted_)) || !DYNInitialGuessPolynomialUpdate_);\
if ((solverCall||(DYNEvent&&solverHandleEq_)) && !rememberCrossing) {\
	if (!solverCall || rememberDynamics || !DYNInitialGuessPolynomialUpdate_) {\
		if (*time > EqRemember2Time_) {\
			EqRemember1Time_ = EqRemember2Time_;\
			(did_->eqRememberReplaceOldDynamics) = 1;\
		}\
	}\
	if (!solverCall || rememberOnlyAccepted_ || !DYNInitialGuessPolynomialUpdate_) {\
		if (*time > EqRemAcc2Time_ || DYNEvent) {\
			EqRemAcc1Time_ = EqRemAcc2Time_;\
			(did_->eqRememberReplaceOldAccepted) = 1;\
		}\
	}\
}\
if (rememberDynamicsSection) EqRemember2Time_ = *time;\
if (rememberAcceptedSection) EqRemAcc2Time_ = *time;\
if (rememberCrossing && DYNInitialGuessPolynomialUpdate_) {\
	if (!did_->hasStoredInTemp) { unsigned ii_; did_->hasStoredInTemp = 1; EqRemTempTime_ = EqRemember2Time_; EqRemTempTimeAcc_ = EqRemAcc2Time_;\
		for (ii_ = 0; ii_ < SizeEq_; ii_++) EqRememberTemp_[ii_] = EqRemember2_[ii_]; }\
	if (rememberCrossing & 2) { EqRemember2Time_ = *time; EqRemAcc2Time_ = *time; }\
						 else { EqRemember1Time_ = *time; EqRemAcc1Time_ = *time; } }

DYMOLA_STATIC void UpdateInitVars(double *time, double* X_, double* XD_, double* U_, 
      double* DP_, int IP_[], Dymola_bool LP_[], 
      double* F_, double* Y_, double* W_, double QZ_[], double duser_[], int iuser_[], void*cuser_[],struct DYNInstanceData*did_,int initialCall);


#define OutputSection\
    }\
    sectioncondition = ((*idemand_ >= 1 && *icall_ < 1) || (DYNEvent || *idemand_==4)) && (DymolaOneIteration_!=-1);\
    if (sectioncondition) {\
        *icall_ = 1;

#define DynamicsSection\
    }\
    sectioncondition = ((*idemand_ >= 2 && *icall_ < 2) || (DYNEvent || *idemand_==4)) && (DymolaOneIteration_!=-1);\
    if (sectioncondition) {\
        *icall_ = 2;

#define AcceptedSection\
    }\
    sectioncondition = ((*idemand_ >= 3 && *icall_ < 3) || (DYNEvent || *idemand_==4)) && (DymolaOneIteration_!=-1);\
    if (sectioncondition) {\
        *icall_ = 3;

#define AcceptedSection1\
    }\
    sectioncondition = ((*idemand_ >= 3 && *icall_ < 3) || (DYNEvent || *idemand_==4)) && (DymolaOneIteration_!=-1);\
    if (sectioncondition) {\
        *icall_ = 3;

#define ODEJacobianSection\
	}\
	sectioncondition = (did_->QJacobian_var || did_->QJacobianSparse_var);\
	if (sectioncondition) {\
	if (did_->QJacobian_var) {int i_;for(i_=0;i_<did_->QJacobianN_var*did_->QJacobianN_var;++i_) did_->QJacobian_var[i_]=0.0;}

#define ODEBCDJacobianSection\
	sectioncondition = (did_->QBJacobian_var && did_->QCJacobian_var && did_->QDJacobian_var) || (did_->QJacobianSparse_var && did_->QSparseABCD_var);\
	if (sectioncondition && (did_->QBJacobian_var && did_->QCJacobian_var && did_->QDJacobian_var)) {int i_;\
		for(i_=0;i_<did_->QJacobianN_var*did_->QJacobianNU_var;++i_) did_->QBJacobian_var[i_]=0.0;\
		for(i_=0;i_<did_->QJacobianNY_var*did_->QJacobianN_var;++i_) did_->QCJacobian_var[i_]=0.0;\
		for(i_=0;i_<did_->QJacobianNY_var*did_->QJacobianNU_var;++i_) did_->QDJacobian_var[i_]=0.0;\
	}\
	if (sectioncondition) 


#define ODEJacobian(iz, r, c, v) (did_->QJacobian_var?did_->QJacobian_var+(r-1)+(c-1)*did_->QJacobianN_var:did_->QJacobianSparse_var+iz)[0] = v; if (did_->QJacobianSparse_var) {did_->QJacobianSparseR_var[iz]=r-1;did_->QJacobianSparseC_var[iz]=c-1;}
#define ODEBJacobian(iz, r, c, v) (did_->QBJacobian_var?did_->QBJacobian_var+(r-1)+(c-1)*did_->QJacobianN_var:did_->QJacobianSparse_var+iz)[0]=v; if (did_->QJacobianSparse_var && did_->QSparseABCD_var) {did_->QJacobianSparseR_var[iz]=r-1;did_->QJacobianSparseC_var[iz]=c-1+AnalyticJacobianSize_;}
#define ODECJacobian(iz, r, c, v) (did_->QCJacobian_var?did_->QCJacobian_var+(r-1)+(c-1)*did_->QJacobianNY_var:did_->QJacobianSparse_var+iz)[0]=v; if (did_->QJacobianSparse_var && did_->QSparseABCD_var) {did_->QJacobianSparseR_var[iz]=r-1+AnalyticJacobianSize_;did_->QJacobianSparseC_var[iz]=c-1;}
#define ODEDJacobian(iz, r, c, v) (did_->QDJacobian_var?did_->QDJacobian_var+(r-1)+(c-1)*did_->QJacobianNY_var:did_->QJacobianSparse_var+iz)[0]=v; if (did_->QJacobianSparse_var && did_->QSparseABCD_var) {did_->QJacobianSparseR_var[iz]=r-1+AnalyticJacobianSize_;did_->QJacobianSparseC_var[iz]=c-1+AnalyticJacobianSize_;}


/* ---------------------------------------------------- */

/* Macros to build variable name table. */  
struct DeclarePhase;
#if defined(Matlab5) || defined(Matlab51) || defined(SimStruct) || defined(DYMOLA_DSPACE) || defined(DYM2DS) || defined(FMU_SOURCE_CODE_EXPORT)
#if !defined(DynSimStruct)
#define DynSimStruct 1
#endif
#endif
#define PreNonAliasDef(nr) DYMOLA_STATIC void declare__##nr(double x0_[],double dp_[],double du_[],void*cuser_[],int*QiErr,int setDefault_,int setDefaultX_,int setDefaultU_,int setDefaultY_,int setDefaultP_,int setDefaultDX_,int setDefaultW_, struct DeclarePhase*phase);
#define FuncStartNonAlias(nr) DYMOLA_STATIC void declare__##nr(double x0_[],double dp_[],double du_[],void*cuser_[],int*QiErr,int setDefault_,int setDefaultX_,int setDefaultU_,int setDefaultY_,int setDefaultP_,int setDefaultDX_,int setDefaultW_, struct DeclarePhase*phase) {
#define DeclareDState(var,descvar, val, mi, ma, w, typ, con) 
#define DeclarePrevious(var,descvar, val, mi, ma, w, typ, con) 
#if defined(DynSimStruct) || !defined(DYMOSIM)
/* Not in Dymosim => cannot use blo-routines */
#if GenerateResultInNonDymosim==2 || (GenerateResultInNonDymosim==1 && !(defined(RT) || defined(DYMOLA_DSPACE)))
#include "GenerateResultInNonDymosim.h"
/* Special code for generating result files from Matlab
   #define GenerateResultInMatlab 2 
    - do this always
   #define GenerateResultInMatlab 1
    - only when running inside Matlab and not on realtime platforms
*/

#define DeclareSParameter(par, descpar, ipar, val, mi, ma, w, typ, con) {0+(typ<<3)+(con<<5),par,val,0,0.0,0.0,w,ipar},
#define DeclareParameter(par, descpar, ipar, val, mi, ma, w,typ,con) {1+(typ<<3)+(con<<5),par,descpar,val,mi, ma,w,ipar},
#define DeclareState(x, descx, ix, val, mi, ma,w, typ,con) {2+(typ<<3)+(con<<5),x,descx,val,mi, ma, w, ix},
#define DeclareDerivative(dx, descdx, val, mi, ma,w, typ,con) {3+(typ<<3)+(con<<5),dx,descdx,val,mi, ma, w},
#define DeclareOutput(var, descvar, iy, val, mi, ma, w,typ, con)   {4+(typ<<3)+(con<<5),var,descvar,val,mi, ma, w}, 
#define DeclareInput(var, descvar, iu, val, mi, ma, w,typ, con)    {5+(typ<<3)+(con<<5),var,descvar,val,mi, ma, w},
#define DeclareVariable(var,descvar, val, mi, ma, w, typ, con)  {6+(typ<<3)+(con<<5),var,descvar,val,mi, ma, w},

#define DeclareAlias(name, description, aliasname, sign, sigtype, sigindex) {7+(sigtype<<3),name,description,sign,0.0,0.0,0,sigindex},
#define DeclareAlias2(name, description, aliasname, sign, sigtype, sigindex, typ) {7+(sigtype<<3)+(typ<<6),name,description,sign,0.0,0.0,0,sigindex},

#define PreNonAliasNew(nr) {declare__##nr(x0_,dp_,du_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}} 
#define PreNonAlias(nr) {PreNonAliasDef(nr);declare__##nr(x0_,dp_,du_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}} 
#define StartNonAlias(nr) static struct NonAlias_ nonalias_##nr []={
#define EndNonAlias(nr) {100}}; FuncStartNonAlias(nr) \
	struct NonAlias_*nonalias_=nonalias_##nr;\
	int i_,imax_;\
    switch(phase ? phase->temp.declarePhase_ : 0) {\
	   case 0: /* Handle literal start-values and parameters.*/\
		   for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
		       int t=nonalias_[i_].tag&7;\
			   switch(t) {\
				 case 0:if (cuser_) cuser_[nonalias_[i_].ix]=(void*)(nonalias_[i_].d);break;\
	             case 1:if (dp_) dp_[nonalias_[i_].ix]=nonalias_[i_].val;break;\
	             case 2:if (x0_) x0_[nonalias_[i_].ix]=nonalias_[i_].val;break;\
	      		 default:break;\
		   }}break;\
		  case 11: /* Count items */\
		  for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
		       int storF=(nonalias_[i_].tag>>6)&(512|1024);\
			   int stor=DYNStoreProtectedVariables || (storF==0 || storF==(512|1024));\
			   int t=nonalias_[i_].tag&7;\
			   switch(t) {\
			   case 1:if(stor)phase->temp.isPublicP_[setDefaultP_]|=1;++setDefaultP_;break;\
			   case 2:if(stor)phase->temp.isPublicX_[setDefaultX_]|=1;++setDefaultX_;break;\
			   case 3:if(stor)phase->temp.isPublicXD_[setDefaultDX_]|=1;++setDefaultDX_;break;\
			   case 6:if(stor)phase->temp.isPublicW_[setDefaultW_]|=1;++setDefaultW_;break;\
			   case 7:{\
					static const int mapToO[8]={0,2,5,4,0,6,3,1};\
				    int kind=mapToO[(nonalias_[i_].tag>>3)&7];\
					if (kind==6 && stor) phase->temp.isPublicW_[nonalias_[i_].ix]|=2;\
					if (kind==2 && stor) phase->temp.isPublicX_[nonalias_[i_].ix]|=2;\
					if (kind==3 && stor) phase->temp.isPublicXD_[nonalias_[i_].ix]|=2;\
					if (kind==1 && stor) phase->temp.isPublicP_[nonalias_[i_].ix]|=2;\
                 }\
			   default:break;\
		   }}break;\
       case 1: /* Count items */\
		   for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
		       int t=nonalias_[i_].tag&7;\
			   int storF=(nonalias_[i_].tag>>6)&(512|1024);\
			   int stor=DYNStoreProtectedVariables||(storF==0 || storF==(512|1024));\
			   if (t>=1 && t<=6) {\
			      if (!DYNStoreProtectedVariables && ((t==6 && !phase->temp.isPublicW_[setDefaultW_++])||(t==2 && !phase->temp.isPublicX_[setDefaultX_++])||(t==3 && !phase->temp.isPublicXD_[setDefaultDX_++])||(t==1 && !phase->temp.isPublicP_[setDefaultP_++]))) {phase->temp.offsets_[t]++;continue;}\
			   } else if(t==7) {\
				   static const int mapToO[8]={0,2,5,4,0,6,3,1};\
				    int kind=mapToO[(nonalias_[i_].tag>>3)&7];\
					if (!DYNStoreProtectedVariables && (kind==6||kind==2||kind==3||kind==1) && !stor) continue;\
					if (!DYNStoreProtectedVariables && (kind==6 && phase->temp.isPublicW_[nonalias_[i_].ix]==2)) {phase->temp.isPublicW_[nonalias_[i_].ix]=4;continue;}\
					if (!DYNStoreProtectedVariables && (kind==2 && phase->temp.isPublicX_[nonalias_[i_].ix]==2)) {phase->temp.isPublicX_[nonalias_[i_].ix]=4;continue;}\
					if (!DYNStoreProtectedVariables && (kind==3 && phase->temp.isPublicXD_[nonalias_[i_].ix]==2)) {phase->temp.isPublicXD_[nonalias_[i_].ix]=4;continue;}\
					if (!DYNStoreProtectedVariables && (kind==1 && phase->temp.isPublicP_[nonalias_[i_].ix]==2)) {phase->temp.isPublicP_[nonalias_[i_].ix]=4;continue;}\
			   }\
			   switch(t) {\
	             case 1:*((phase->temp.offsets_[t])++)= - ++(phase->temp.countConst_);break;\
	             case 2:*((phase->temp.offsets_[t])++)= ++(phase->temp.countNonConst_);break;\
	             case 3:*((phase->temp.offsets_[t])++)=++(phase->temp.countNonConst_);break;\
				 case 4:case 5:case 6:if (nonalias_[i_].tag&32) *(phase->temp.offsets_[t]++)= - ++(phase->temp.countConst_);else *((phase->temp.offsets_[t])++) = ++(phase->temp.countNonConst_);break;\
	             case 7:++(phase->temp.countAlias_);break;\
				 default:break;\
		   }}break;\
	   case 3:/* Add names, info */\
	      for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
		    int t=nonalias_[i_].tag&7;\
			int data=-1,offset,sgn=1;\
			int storF=(nonalias_[i_].tag>>6)&(512|1024);\
			int stor=DYNStoreProtectedVariables||(storF==0 || storF==(512|1024));\
			if (t>=1 && t<=7) {\
			    if (!DYNStoreProtectedVariables && (t==6||t==2||t==3||t==1) && !stor) {phase->temp.offsets_[t]++;continue;}\
				if (t==7) {\
					static const int mapToO[8]={0,2,5,4,0,6,3,1};\
				    int kind=mapToO[(nonalias_[i_].tag>>3)&7];\
					assert(kind!=0);\
					if (!DYNStoreProtectedVariables && (kind==6||kind==2||kind==3||kind==1) && !stor) continue;\
					offset=phase->temp.baseoffsets_[kind][nonalias_[i_].ix];\
					if (nonalias_[i_].val<0) sgn=-1;\
				} else offset=*((phase->temp.offsets_[t])++);\
				if (offset>0) {data=2;}else{offset=-offset;data=1;}\
			}\
		   if (data!=-1) {\
			   phase->temp.trajNames_[phase->temp.infoCount_]=nonalias_[i_].n;\
			   phase->temp.trajDesc_[phase->temp.infoCount_]=nonalias_[i_].d;\
			   phase->temp.trajInfo_[phase->temp.infoCount_+phase->totalInfoCount*0]=data;\
			   phase->temp.trajInfo_[phase->temp.infoCount_+phase->totalInfoCount*1]=sgn*(offset+1);\
			   phase->temp.trajInfo_[phase->temp.infoCount_+phase->totalInfoCount*2]=0;\
			   phase->temp.trajInfo_[phase->temp.infoCount_+phase->totalInfoCount*3]=-1;\
			   ++(phase->temp.infoCount_);\
		   }\
		  }break;\
	  case 5: /* Update constants*/\
			for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
		    int t=nonalias_[i_].tag&7;\
			if (!DYNStoreProtectedVariables && ((t==6 && !phase->temp.isPublicW_[setDefaultW_++])||(t==2 && !phase->temp.isPublicX_[setDefaultX_++])||(t==3 && !phase->temp.isPublicXD_[setDefaultDX_++])||(t==1 && !phase->temp.isPublicP_[setDefaultP_++]))) {++(phase->temp.offsets_[t]);++(phase->temp.pointers_[t]);continue;}\
			   if (t>=1 && t<=6) {\
			     if (*(phase->temp.offsets_[t])<0) \
					 phase->temp.resultPart_[2* - *(phase->temp.offsets_[t])+1] =phase->temp.resultPart_[2* - *(phase->temp.offsets_[t])] = (float)(*(phase->temp.pointers_[t]));\
				 ++(phase->temp.offsets_[t]);\
			     ++(phase->temp.pointers_[t]);\
			   }\
		  }break;\
	   case 7:/*Update non-constants */\
		  for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
		    int t=nonalias_[i_].tag&7;\
			if (t>=1 && t<=6) {\
			if (!DYNStoreProtectedVariables && ((t==6 && !phase->temp.isPublicW_[setDefaultW_++])||(t==2 && !phase->temp.isPublicX_[setDefaultX_++])||(t==3 && !phase->temp.isPublicXD_[setDefaultDX_++])||(t==1 && !phase->temp.isPublicP_[setDefaultP_++]))) {++(phase->temp.offsets_[t]);++(phase->temp.pointers_[t]);continue;}\
			     if (*(phase->temp.offsets_[t])>0) \
					 phase->temp.resultPart_[*(phase->temp.offsets_[t])] = (float)(*(phase->temp.pointers_[t]));\
				 ++(phase->temp.offsets_[t]);\
			     ++(phase->temp.pointers_[t]);\
			   }\
		  }break;\
		default:break;\
		}


#else
#define DeclareParameter(par, descpar, ipar, val, mi, ma, w,typ,con) if (dp_) dp_[ipar]=val;
#define DeclareSParameter(par, descpar, ipar, val, mi, ma, w,typ,con) if (cuser_) cuser_[ipar]=(void*)(val);
#define DeclareState(x, descx, ix, val, mi, ma,w, typ, con) if (x0_) x0_[ix]=val;
#define DeclareDerivative(dx, descdx, val, mi, ma,w, typ, con) 
#define DeclareOutput(var, descvar, iy, val, mi, ma, w,typ, con)  
#define DeclareInput(var, descvar, iu, val, mi, ma, w,typ, con)  if (du_) du_[iu]=val;
#define DeclareVariable(var,descvar, val, mi, ma, w, typ, con) 
#define DeclareAlias(name, description, aliasname, sign, sigtype, sigindex)
#define DeclareAlias2(name, description, aliasname, sign, sigtype, sigindex, typ)
#define PreNonAliasNew(nr) {declare__##nr(x0_,dp_,du_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}} 
#define PreNonAlias(nr) {PreNonAliasDef(nr);declare__##nr(x0_,dp_,du_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}} 
#define StartNonAlias(nr) FuncStartNonAlias(nr)
#define EndNonAlias(nr) 
#endif

#define DeclareConstant(c)
#define StartAlias(nr) void declarea__##nr(double x0_[],double dp_[],void*cuser_[],int*QiErr,int setDefault_,int setDefaultX_,int setDefaultU_,int setDefaultY_,int setDefaultP_,int setDefaultDX_,int setDefaultW_, struct DeclarePhase*phase) {
#define EndAlias(nr) 
#define PreAlias(nr) {void declarea__##nr(double x0_[],double dp_[],void*cuser_[],int*QiErr,int setDefault_,int setDefaultX_,int setDefaultU_,int setDefaultY_,int setDefaultP_,int setDefaultDX_,int setDefaultW_, struct DeclarePhase*phase);declarea__##nr(x0_,dp_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}} 

#else
#define DeclareSParameter(par,descpar,ipar,val,mi,ma,w,typ,con) {0+(typ<<3)+(con<<5),par,val,0,0.0,0.0,w,ipar},
#define DeclareParameter(par, descpar, ipar, val, mi, ma, w,typ,con) {1+(typ<<3)+(con<<5),par,descpar,val,mi, ma,w,ipar},
#define DeclareState(x, descx, ix, val, mi, ma,w, typ,con) {2+(typ<<3)+(con<<5),x,descx,val,mi, ma, w, ix},
#define DeclareDerivative(dx, descdx, val, mi, ma,w, typ,con) {3+(typ<<3)+(con<<5),dx,descdx,val,mi, ma, w},
#define DeclareOutput(var, descvar, iy, val, mi, ma, w,typ, con)   {4+(typ<<3)+(con<<5),var,descvar,val,mi, ma, w}, 
#define DeclareInput(var, descvar, iu, val, mi, ma, w,typ, con)    {5+(typ<<3)+(con<<5),var,descvar,val,mi, ma, w},
#define DeclareVariable(var,descvar, val, mi, ma, w, typ, con)  {6+(typ<<3)+(con<<5),var,descvar,val,mi, ma, w},

#define DeclareAlias(name, description, aliasname, sign, sigtype, sigindex) {7+(sigtype<<3),name,description,sign,0.0,0.0,0,sigindex},
#define DeclareAlias2(name, description, aliasname, sign, sigtype, sigindex, typ) {7+(sigtype<<3)+(typ<<6),name,description,sign,0.0,0.0,0,sigindex},

#define PreNonAliasDef(nr) DYMOLA_STATIC void declare__##nr(double x0_[],double dp_[],double du_[],void*cuser_[],int*QiErr,int setDefault_,int setDefaultX_,int setDefaultU_,int setDefaultY_,int setDefaultP_,int setDefaultDX_,int setDefaultW_, struct DeclarePhase*phase);
#define PreNonAliasNew(nr) {declare__##nr(x0_,dp_,du_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}}
#define PreNonAlias(nr) {PreNonAliasDef(nr);declare__##nr(x0_,dp_,du_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}} 
#define StartNonAlias(nr) static struct NonAlias_ nonalias_##nr []={


#define EndNonAlias(nr) {100}}; FuncStartNonAlias(nr) \
    LIBDS_API void blo3val(int,int,double,double,double,double,int);\
    int c1_,c2_,c3_;double d1_;int i_,imax_;\
	struct NonAlias_*nonalias_=nonalias_##nr;\
	c1_=c2_=c3_=0;d1_=0;\
    if (!setDefault_) {\
	for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
		switch(nonalias_[i_].tag&7) {\
		case 0:blo3psd_(nonalias_[i_].n,nonalias_[i_].d);cuser_[nonalias_[i_].ix]=(void*)(nonalias_[i_].d);break;\
		case 1:blo3pd_(nonalias_[i_].n,nonalias_[i_].d);dp_[nonalias_[i_].ix]=nonalias_[i_].val;if (nonalias_[i_].tag>=64) blo3pt_(nonalias_[i_].tag>>6);break;\
		case 2:blo3sx_(nonalias_[i_].n,nonalias_[i_].d);x0_[nonalias_[i_].ix]=nonalias_[i_].val;if (nonalias_[i_].tag>=64) blo3st_(nonalias_[i_].tag>>6);break;\
		case 3:blo3sd_(nonalias_[i_].n,nonalias_[i_].d);if (nonalias_[i_].tag>=64) blo3st_(nonalias_[i_].tag>>6);break;\
		case 4:blo3sy_(nonalias_[i_].n,nonalias_[i_].d);if (nonalias_[i_].tag&32) {blo3co_(nonalias_[i_].val);};if (nonalias_[i_].tag>=64) blo3st_(nonalias_[i_].tag>>6);break;\
		case 5:blo3su_(nonalias_[i_].n,nonalias_[i_].d);if (nonalias_[i_].tag&32) {blo3co_(nonalias_[i_].val);};if (nonalias_[i_].tag>=64) blo3st_(nonalias_[i_].tag>>6);break;\
		case 6:blo3sw_(nonalias_[i_].n,nonalias_[i_].d);if (nonalias_[i_].tag&32) {blo3co_(nonalias_[i_].val);};if (nonalias_[i_].tag>=64) blo3st_(nonalias_[i_].tag>>6);break;\
		case 7:blo3sa_(nonalias_[i_].n,nonalias_[i_].d,(nonalias_[i_].tag>>3)&7,nonalias_[i_].ix+1,(nonalias_[i_].val>0)?1:-1);if (nonalias_[i_].tag>=64) blo3st_(nonalias_[i_].tag>>6);break;\
		default:break;\
		}\
	}} else {\
	  for(i_=0,imax_=sizeof(nonalias_##nr)/sizeof(nonalias_##nr [0])-1;i_<imax_;++i_){\
	    int num=0;int sect=nonalias_[i_].tag&7;\
		if (sect!=7 && sect!=0) {switch(sect) {\
		case 1:num=++setDefaultP_;break;\
		case 2:num=++setDefaultX_;break;\
		case 3:num=++setDefaultDX_;break;\
		case 4:num=++setDefaultY_;break;\
		case 5:num=++setDefaultU_;break;\
		case 6:num=++setDefaultW_;break;\
		default:break;\
		}blo3val(sect,num,nonalias_[i_].val,nonalias_[i_].mi,nonalias_[i_].ma,nonalias_[i_].w,(nonalias_[i_].tag>>3)&3);}\
	}}\

#define PreAlias(nr) {void declarea__##nr(double x0_[],double dp_[],void*cuser_[],int*QiErr,int setDefault_,int setDefaultX_,int setDefaultU_,int setDefaultY_,int setDefaultP_,int setDefaultDX_,int setDefaultW_, struct DeclarePhase*phase);declarea__##nr(x0_,dp_,cuser_,QiErr,setDefault_,setDefaultX_,setDefaultU_,setDefaultY_,setDefaultP_,setDefaultDX_,setDefaultW_,phase);}} 
#define StartAlias(nr) static struct NonAlias_ alias_##nr []={
#define EndAlias(nr) {100}}; void declarea__##nr(double x0_[],double dp_[],void*cuser_[],int*QiErr,int setDefault_,int setDefaultX_,int setDefaultU_,int setDefaultY_,int setDefaultP_,int setDefaultDX_,int setDefaultW_, struct DeclarePhase*phase) {\
    LIBDS_API void blo3val(int,int,double,double,double,double,int);\
    int c1_,c2_,c3_;double d1_;int i_,imax_;\
	struct NonAlias_*alias_=alias_##nr;\
	c1_=c2_=c3_=0;d1_=0;\
    if (!setDefault_) {\
	for(i_=0,imax_=sizeof(alias_##nr)/sizeof(alias_##nr [0])-1;i_<imax_;++i_){\
		switch(alias_[i_].tag&7) {\
		case 0:blo3psd_(nonalias_[i_].n,nonalias_[i_].d);cuser_[nonalias_[i_].ix]=(void*)(nonalias_[i_].d);break;\
		case 1:blo3pd_(alias_[i_].n,alias_[i_].d);dp_[alias_[i_].ix]=alias_[i_].val;if (alias_[i_].tag>=64) blo3pt_(alias_[i_].tag>>6);break;\
		case 2:blo3sx_(alias_[i_].n,alias_[i_].d);x0_[alias_[i_].ix]=alias_[i_].val;if (alias_[i_].tag>=64) blo3st_(alias_[i_].tag>>6);break;\
		case 3:blo3sd_(alias_[i_].n,alias_[i_].d);if (alias_[i_].tag>=64) blo3st_(alias_[i_].tag>>6);break;\
		case 4:blo3sy_(alias_[i_].n,alias_[i_].d);if (alias_[i_].tag&32) {blo3co_(alias_[i_].val);};if (alias_[i_].tag>=64) blo3st_(alias_[i_].tag>>6);break;\
		case 5:blo3su_(alias_[i_].n,alias_[i_].d);if (alias_[i_].tag&32) {blo3co_(alias_[i_].val);};if (alias_[i_].tag>=64) blo3st_(alias_[i_].tag>>6);break;\
		case 6:blo3sw_(alias_[i_].n,alias_[i_].d);if (alias_[i_].tag&32) {blo3co_(alias_[i_].val);};if (alias_[i_].tag>=64) blo3st_(alias_[i_].tag>>6);break;\
		case 7:blo3sa_(alias_[i_].n,alias_[i_].d,(alias_[i_].tag>>3)&7,alias_[i_].ix+1,(alias_[i_].val>0)?1:-1);break;\
		default:break;\
		}\
	}} else {\
	  for(i_=0,imax_=sizeof(alias_##nr)/sizeof(alias_##nr [0])-1;i_<imax_;++i_){\
	    int num=0;int sect=alias_[i_].tag&7;\
		if (sect!=7 && sect!=0) {switch(sect) {\
		case 1:num=++setDefaultP_;break;\
		case 2:num=++setDefaultX_;break;\
		case 3:num=++setDefaultDX_;break;\
		case 4:num=++setDefaultY_;break;\
		case 5:num=++setDefaultU_;break;\
		case 6:num=++setDefaultW_;break;\
		default:break;\
		}blo3val(sect,num,alias_[i_].val,alias_[i_].mi,alias_[i_].ma,alias_[i_].w,(alias_[i_].tag>>3)&3);}\
	}}\

#endif

#if defined(DYMOLA_DSPACE) || defined(DynSimStruct) && DymolaAutoRemoveAuxiliaries_
#define AcceptedSection2\
   }sectioncondition=0; if (0) {*icall_=2;
#elif DymolaAutoRemoveAuxiliaries_
 #define AcceptedSection2\
    } sectioncondition=sectioncondition && DymolaStoreAuxiliaries_; if (sectioncondition) {
#else
#define AcceptedSection2
#endif

#define CrossingSection\
    }\
    sectioncondition = (*idemand_ >= 4 && *icall_ < 4) || (DYNEvent || *idemand_==4);\
    if (sectioncondition) {\
        *icall_ = 4;

#if !defined(DYMOSIM)
#define SetInitVectorSimple(x, i, var, i2, val) \
  if (veryFirstTime && lambda_<-1) \
    var = val; \
  if ((firstTime || ! DAEsolverMode) && !inJacobian_) \
    SetVector(x, i, var); \
  else \
	var = GetVector(x, i)
#define SetInitVectorSimpleNH(x, i, var, val) \
  if (veryFirstTime && lambda_<-1) \
    var = val; \
  if ((firstTime || ! DAEsolverMode) && !inJacobian_) \
    SetVector(x, i, var); \
  else \
	var = GetVector(x, i)
#else
#define SetInitVectorSimpleOld(x, i, var, val) \
  if (veryFirstTime && ((lambda_<-1 || lambda_==1) && !DymolaUserHomotopy || DymolaUserHomotopy && DymolaHomotopyLambda==0)) var=val;\
  if ((firstTime || ! DAEsolverMode) && !inJacobian_) \
    SetVector(x, i, var); \
  else \
	var = GetVector(x, i)
#define SetInitVectorSimple(x, i, var, i2, val) \
  if (veryFirstTime && ((lambda_<-1 || lambda_==1) && !DymolaUserHomotopy || DymolaUserHomotopy && DymolaHomotopyLambda==0)) {\
     var =DYNX(did_->xInitial_var, i2);\
  }\
  if (firstTime || ! DAEsolverMode) \
    SetVector(x, i, var); \
  else \
	var = GetVector(x, i)
#define SetInitVectorSimpleNH(x, i, var, val) \
  if (veryFirstTime && !(homlocal>0 || DymolaUserHomotopy && DymolaHomotopyLambda>0)) var=val;\
  if ((firstTime || ! DAEsolverMode) && !inJacobian_) \
    SetVector(x, i, var); \
  else \
	var = GetVector(x, i)
#endif



#if defined(DYMOLA_DSPACE) || defined(NO_FILE)
#define InitializeModes(datfile,Modes,nModes) {nModes=0;}
#if 0
/* Change to #if 1 to see modes in CPUClk */
#define AddMode(Modes,nModes,Mode) { \
  int j; \
  unsigned int cnt = 0; \
  for(j = 1; j <= MatrixNrRows(Modes); j++) \
    cnt = (cnt << 1) | (GetVector(Mode,j) != 0); \
  CPUClk = cnt; \
}
#else
#define AddMode(Modes,nModes,Mode)
#endif
#define OutputModes
#else
/* To handle modes */
#define AddMode(Modes,nModes,Mode) {\
  int i,j;\
  int doAppend=(nModes<MaxModes);\
  for(i=1;doAppend&&(i<=nModes);i++) {\
	  int allSame=1;\
	  for(j=1;allSame&&(j<=MatrixNrRows(Modes));j++) \
		  allSame=GetMatrix(Modes,j,i)==GetVector(Mode,j);\
	  doAppend=!allSame;\
  }\
  if (doAppend) {\
	  nModes++;\
	  for(j=1;j<=MatrixNrRows(Modes);j++)\
		   SetMatrix(Modes,j,nModes,GetVector(Mode,j)); \
  }\
 }



#define InitializeModes(datfile,Modes,nModes) {\
	Amatrix bigModes; AclassRead c[1];\
	bigModes.name="bigModes"; bigModes.nrow=MatrixNrRows(Modes);\
	bigModes.ncol=-MatrixNrColumns(Modes); bigModes.type=doubleMatrix; bigModes.data.d=Modes.data;\
c[0].matrix=&bigModes; c[0].req=1; c[0].rowDim=0; c[0].colDim=0; c[0].rowIndex=0; c[0].colIndex=0; c[0].onFile=0;\
nModes=0;\
if (amatReadAll(datfile,"NoClass",(char*)0,c,1)==0) {\
  nModes=bigModes.ncol;\
} else {\
  DymosimMessage(amatError);\
}\
}

#define OutputModes(datfile,mofile,newmodel,origmodel,pre,post,Modes,nModes,nModesOriginal) {\
   if (datfile) {\
   Amatrix bigModes;\
	bigModes.name="bigModes"; bigModes.nrow=MatrixNrRows(Modes);\
	bigModes.ncol=nModes; bigModes.type=doubleMatrix; bigModes.data.d=Modes.data;\
   amatWrite(datfile,amatBinary,bigModes);\
   }\
   if (mofile) {FILE *f=fopen(mofile,"w");\
   if (f) {\
           int i,j,jmax=MatrixNrRows(Modes);\
	   fprintf(f,"// Automatically constructed mode variables\n\n");\
	   fprintf(f,"model %s\n\n",newmodel);\
	   fprintf(f,"  extends %s;\n\n",origmodel);\
	   fprintf(f,"  %s,\n\n",pre);\
	   fprintf(f,"  bigModes={");\
           for(i=1;i<=nModes;i++) {fprintf(f,"\n    { ");for(j=1;j<=jmax;j++) \
	   fprintf(f,"%s%g",(j==1)?"":", ",GetMatrix(Modes,j,i));fprintf(f,(i==nModes)?"}":"},");}\
	   fprintf(f," }%s\n",post);\
	   fprintf(f,"end %s;\n\n",newmodel);\
   }\
   fclose(f);}\
   if (nModes>nModesOriginal) DymosimMessage("Found additional modes, please recompile model");\
}
#include <bloutil.h>
#ifdef Dymola_Include_MT
/* 
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using init_genrand(seed)  
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.                          

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote 
        products derived from this software without specific prior written 
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)

   Modified to include prefix; added code for using time to randomize values (and print it)
   and removed unused functions.
*/


/* Period parameters */  
#define Dymola_MT_N 624
#define Dymola_MT_M 397
#define Dymola_MT_MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define Dymola_MT_UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define Dymola_MT_LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned int Dymola_MT_mt[Dymola_MT_N]; /* the array for the state vector  */
static int Dymola_MT_mti=Dymola_MT_N+1; /* mti==N+1 means mt[N] is not initialized */

/* initializes mt[N] with a seed */
static void Dymola_MT_init_genrand(unsigned int s)
{
    Dymola_MT_mt[0]= s & 0xffffffffUL;
    for (Dymola_MT_mti=1; Dymola_MT_mti<Dymola_MT_N; Dymola_MT_mti++) {
        Dymola_MT_mt[Dymola_MT_mti] = 
	    (1812433253UL * (Dymola_MT_mt[Dymola_MT_mti-1] ^ (Dymola_MT_mt[Dymola_MT_mti-1] >> 30)) + Dymola_MT_mti); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        Dymola_MT_mt[Dymola_MT_mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
static void Dymola_MT_init_by_array(unsigned int init_key[], int key_length)
{
    int i, j, k;
    Dymola_MT_init_genrand(19650218UL);
    i=1; j=0;
    k = (Dymola_MT_N>key_length ? Dymola_MT_N : key_length);
    for (; k; k--) {
        Dymola_MT_mt[i] = (Dymola_MT_mt[i] ^ ((Dymola_MT_mt[i-1] ^ (Dymola_MT_mt[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        Dymola_MT_mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=Dymola_MT_N) { Dymola_MT_mt[0] = Dymola_MT_mt[Dymola_MT_N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=Dymola_MT_N-1; k; k--) {
        Dymola_MT_mt[i] = (Dymola_MT_mt[i] ^ ((Dymola_MT_mt[i-1] ^ (Dymola_MT_mt[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        Dymola_MT_mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=Dymola_MT_N) { Dymola_MT_mt[0] = Dymola_MT_mt[Dymola_MT_N-1]; i=1; }
    }

    Dymola_MT_mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */ 
}
#include <time.h>
#ifdef _MSC_VER
#include <process.h>
#endif
static void Dymola_MT_init_default(void) {
	char str[100];
#if 0
	 Dymola_MT_init_genrand(5489UL); /* a default initial seed is used */
#else
	unsigned int s =(unsigned int)(time(0));
#ifdef _MSC_VER
	s+=(unsigned int)(_getpid())*10235489UL;
#endif
	Dymola_MT_init_genrand(s);
	DymosimMessageInt("Random number seed for MT19937:",s);
#endif
}

/* generates a random number on [0,0xffffffff]-interval */
static unsigned int Dymola_MT_genrand_int32(void)
{
    unsigned int y;
    static unsigned int mag01[2]={0x0UL, Dymola_MT_MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (Dymola_MT_mti >= Dymola_MT_N) { /* generate N words at one time */
        int kk;

        if (Dymola_MT_mti == Dymola_MT_N+1)   /* if init_genrand() has not been called, */
           Dymola_MT_init_default(); /* a default initial seed is used */

        for (kk=0;kk<Dymola_MT_N-Dymola_MT_M;kk++) {
            y = (Dymola_MT_mt[kk]&Dymola_MT_UPPER_MASK)|(Dymola_MT_mt[kk+1]&Dymola_MT_LOWER_MASK);
            Dymola_MT_mt[kk] = Dymola_MT_mt[kk+Dymola_MT_M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<Dymola_MT_N-1;kk++) {
            y = (Dymola_MT_mt[kk]&Dymola_MT_UPPER_MASK)|(Dymola_MT_mt[kk+1]&Dymola_MT_LOWER_MASK);
            Dymola_MT_mt[kk] = Dymola_MT_mt[kk+(Dymola_MT_M-Dymola_MT_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (Dymola_MT_mt[Dymola_MT_N-1]&Dymola_MT_UPPER_MASK)|(Dymola_MT_mt[0]&Dymola_MT_LOWER_MASK);
        Dymola_MT_mt[Dymola_MT_N-1] = Dymola_MT_mt[Dymola_MT_M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        Dymola_MT_mti = 0;
    }
  
    y = Dymola_MT_mt[Dymola_MT_mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

/* generates a random number on [0,1) with 53-bit resolution*/
static double Dymola_MT_genrand_res53(void) 
{ 
    unsigned int a=Dymola_MT_genrand_int32()>>5, b=Dymola_MT_genrand_int32()>>6; 
    return(a*67108864.0+b)*(1.0/9007199254740992.0); 
} 
/* These real versions are due to Isaku Wada, 2002/01/09 added */
/* End of MT19937*/
#endif

#ifndef DYMOLA_TIMES
#define DYMOLA_TIMES
struct DymolaTimes {
	int num;
	double maxim;
	double minim;
	double total;
	int numAccum;
	double maximAccum;
	double minimAccum;
	double totalAccum;
	const char*name;
};
#endif
#if defined(DYMOLA_DSPACE) || defined(NO_FILE) || defined(FMU_SOURCE_CODE_EXPORT) || defined(LABCAR)
#define DymolaStartTimer(x)
#define DymolaEndTimer(x)
#define DymolaEndTimerName(x,n)
#define DymolaResetTimer(x) 0
#else
double DymolaTimerCounterSince(double*,int);
extern void DymolaOnInterrupt(void);
extern int DymolaNoInterrupt(void);

static void dymolaEndTimer(int num,struct DymolaTimes*dt,double Time,double*start,const char*name,double*tz,int tz_len,int*tz_cnt) {
	double diff=DymolaTimerCounterSince(start,1);
	if (num==0) {
		DymolaOnInterrupt();
	}
	if (!dt) return; /* Error */
#if !defined(DymosimRealTimePriority_)
	if (dt->num<=10 && 2*diff<dt->minim && diff>0) {
		dt->num=0;
		dt->numAccum=0;
		dt->total=0;
		dt->totalAccum=0;
	}
#endif
	if (dt->num==0) {
		dt->minim=diff;
		dt->maxim=diff;
		dt->name=name;
	} else {
#if !defined(DymosimRealTimePriority_)
		if (diff>2000*dt->maxim && dt->maxim>0)
			return;
#endif
		if (diff>dt->maxim) dt->maxim=diff;
		if (diff<dt->minim) dt->minim=diff;
	}
	dt->total+=diff;
#if defined(DymosimRealTimePriority_)
	if (num==0 && tz && tz_cnt && 2*(*tz_cnt)+2<tz_len) {
		if (tz[2*(*tz_cnt)]!=Time)
			++(*tz_cnt);
		tz[2*(*tz_cnt)]=Time;
		tz[2*(*tz_cnt)+1]+=diff;
	}
#endif
	dt->num++;
	if (dt->numAccum==0) {
		dt->maximAccum=diff;
		dt->minimAccum=diff;
	} else {
		if (diff>dt->maximAccum) dt->maximAccum=diff;
		if (diff<dt->minimAccum) dt->minimAccum=diff;
	}
	dt->totalAccum+=diff;
	dt->numAccum++;
}

#define DymolaStartTimer(x) ((x==0)&&((DymolaNoInterrupt()))),DymolaTimerCounterSince(did_->DymolaStartTimers_vec+x,0)
#define DymolaEndTimer(x) dymolaEndTimer(x,did_->DymolaTimerStructs_vec+x,DYNTime,did_->DymolaStartTimers_vec+x,"",did_->DymolaTimeZero_vec,did_->DymolaTimeZeroLength_var,&(did_->DymolaTimecounter_var))
#define DymolaEndTimerName(x,n) dymolaEndTimer(x,did_->DymolaTimerStructs_vec+x,DYNTime,did_->DymolaStartTimers_vec+x,n,did_->DymolaTimeZero_vec,did_->DymolaTimeZeroLength_var,&(did_->DymolaTimecounter_var))
#define DymolaResetTimer(x) did_->DymolaTimerStructs_vec[x].totalAccum=did_->DymolaTimerStructs_vec[x].num=did_->DymolaTimerStructs_vec[x].numAccum=0
#endif
#endif
#endif
