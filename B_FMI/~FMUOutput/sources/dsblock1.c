/* Begin dsblock1.c */

/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

/* Start of DSblock C output.
   Version: 1.8, 1997-04-29
            1.9, 1997-07-04  relative tolerance of integrator used
                             for nonlinear equation solvers
           1.10, 1997-11-28  - stdlib.h included in order to get no conflicts
                               with a possible f2c.h in userfunc.c
                             - longjmp introduced for error messages, in order
                               that the model evaluation is stopped immediately
                             - event iteration at initial time even if
                               EventIterate_ = 0
                             - userfunc.c before RootFinder_/EventIterate_ flags
                               in order that these flags can be also set in 
                               userfunc.c (often more convenient).
           1.11, 1998-03-22  - changes for linear solvers (and tearing)
           1.12, 1999-01-25  - explicit initializer for matrices to avoid
                               initialization at runtime (increases executable size)
           1.13, 1999-03-03  - includes userdefs.h (userfunc.c was split in two)
*/
#if !defined(DSE_STRUCT)
 #if defined(DS_EMBEDDED)
  #define DSE_STRUCT sts->
 #else
  #define DSE_STRUCT
 #endif
#endif

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <setjmp.h>

#include <dsblock.h>

#include <userdefs.h>
#include <userfunc.c>     /* To include user defined functions called 
                             from model equations. */
#if (defined(__unix__) || defined(__linux__) || defined(__APPLE_CC__)) && defined(__GNUC__) && defined(FMI_MODULE_NAME)
/* need access to non-standard function dladdr */
#define __USE_GNU
#include <dlfcn.h>
#undef __USE_GNU
#endif /* defined(UNIX) ... */

#if defined(NO_FILE)  
#if !defined(NO_FILE_SYSTEM)
#define NO_FILE_SYSTEM 1
#endif
#if !defined(NO_PID)
#define NO_PID 1
#endif
#if !defined(NO_TIME)
#define NO_TIME 1
#endif
#endif

#define MODELICA_EXTERNAL static
#include <ModelicaInternal.c>   /* Utility functions in Modelica 2.1 */
#include <ModelicaStrings.c>



#if ! defined(RootFinder_)
#   if ! defined(DynSimStruct) || defined(Matlab51) || defined(FMU_SOURCE_CODE_EXPORT)
#      define RootFinder_ 1     /* Root finder available in integration algorithm. */
#   else
#      define RootFinder_ 0
#   endif 
#endif

#if ! defined(EventIterate_)
#   define EventIterate_ 1     /* 1: Iterate for consistent conditions after event. 
                                  0: Propagate event next time. */
#endif

#if ! defined(TryLUFactorization_) 
#define TryLUFactorization_ 0 /* 0: Do not attempt LU-factorization (i.e. use QR-factorization)*/
#endif

#if ! defined(EquilibMatrix_)
#define EquilibMatrix_ 1 /* Row and column equilibrate matrix: Improves reliability at some cost */
#endif

#if ! defined(LargeEPS_)
#define LargeEPS_ 1e-4 /* An upper bound for the event epsilon */
#endif

#if ! defined(SlowIter_)
#define SlowIter_ 5 /* Number of iterations before attempting to increase event epsilon */
#endif

#if ! defined(SpuriousEvents_)
#   define SpuriousEvents_ 0    
#endif

#if ! defined(DAEsolver_)
#   define DAEsolver_ 0    
#endif

#if !defined(DymolaAimForHighAccuracy_)
#define DymolaAimForHighAccuracy_ 1
#endif

#if !defined(DymolaNewJacobian_)
#define DymolaNewJacobian_ 1
#endif

#if !defined(DymolaAllowNewJacobianAnyway_)
#define DymolaAllowNewJacobianAnyway_ 1
#endif

#if !defined(DymolaNrStepTimers)
#define DymolaNrStepTimers 100000
#endif

#if !defined(DymolaNonLinearIterations_)
#define DymolaNonLinearIterations_ 0
#elif DymolaNonLinearIterations_>8
#error Cannot set DymolaNonLinearIterations_ above 8
#undef DymolaNonLinearIterations_
#define DymolaNonLinearIterations_ 8
#endif

#if 0 && DymolaPrecisionTiming_ && !defined(DymolaUninterruptedTimers_)
#define DymolaUninterruptedTimers_ 1
#endif

#if DymolaPrecisionTiming_ && !defined(DymolaUseRDTSC_)
#define DymolaUseRDTSC_  1
#endif

#ifndef DYNInitialGuessInterpolation_
#define DYNInitialGuessInterpolation_ 1
#endif
#ifndef DYNInitialGuessPolynomialUpdate_
#define DYNInitialGuessPolynomialUpdate_ 1
#endif

#include <dsutil.h>

#if !defined(DYMOLA_DSPACE) && !defined(RT)
#if DymolaUninterruptedTimers_ && defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
#include "intrin.h"
#endif
void DymolaOnInterrupt(void) {
#if DymolaUninterruptedTimers_ && defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
		_enable();
#elif DymolaUninterruptedTimers_ && defined(__GNUC__) && defined(i386)
		__asm__("sti");
#endif
}
int DymolaNoInterrupt(void) {
#if DymolaUninterruptedTimers_ && defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
		_disable();
#elif DymolaUninterruptedTimers_ && defined(__GNUC__) && defined(i386)
		__asm__("cli");
#endif
		return 0;
}
#endif

DYMOLA_STATIC void GetDimensions2(int *nx_, int *nx2_, int *nu_, int *ny_, int *nw_, 
  int *np_, int*nsp, int *nrel2_, int *nrel_, int *ncons_, int *dae_);

#define MAXQ       10000  /* Maximum number of sub-expressions. */
#define MaxMat     100    /* Maximum size of linear systems of equations. */
                          /* QMaxNonLin >= MaxMat required */
#define MAXEVENT   2000   /* Maximum number of event relations. */
#define QMaxNonLin 100    /* Maximum size of non-linear systems of equations. */
                          /* QMaxNonLin >= MaxMat required, because DymLin uses  */
                          /* QSol_, QRes_, QJac_ from the nonlinear equation and the */
                          /* work arrays dwork_, iwork_ from the linear equation storage */

#if defined(DYMOLA_DSPACE) && defined(__GNUC__)
#define ZERO_INITIALIZED = {0}
#else
#define ZERO_INITIALIZED /* = {0} */
#endif

  
	  /* Not used anymore: */
      static double d1_;
      static int c1_, c2_, c3_;


#define DymolaStoreAuxiliaries_ (((struct BasicIDymosimStruct*)(DSE_STRUCT iuser_))->mDymolaStoreAuxiliaries)
      /* Auxiliary variables. */
      static double Q_[MAXQ] ZERO_INITIALIZED;
	  static int DYNStrInit(struct DYNInstanceData*);
	  DYMOLA_STATIC void DYNSetAuxString(struct DYNInstanceData*did_,const char*,int i);
	  DYMOLA_STATIC void DYNSetAuxStringArray(struct DYNInstanceData*did_,struct StringArray,int i);
	  DYMOLA_STATIC const char*DYNGetAuxStr(struct DYNInstanceData*did_,int i);

      /* Variables to handle linear systems of equations. */
      static double qa_[MaxMat*MaxMat] ZERO_INITIALIZED, qb_[MaxMat] ZERO_INITIALIZED;
      static double dwork_[MaxMat*MaxMat+5*MaxMat] ZERO_INITIALIZED;
      static int iwork_[3*MaxMat];

      /* Variables to handle non-linear systems of equations. */
      #define QI_ (20+(QMaxNonLin*QMaxNonLin+15*QMaxNonLin)/2)
      static double QRes_[QMaxNonLin];
      static double QSol_[QMaxNonLin];
      static double QJac_[QMaxNonLin*QMaxNonLin] ZERO_INITIALIZED;
      static double QD_[QI_] ZERO_INITIALIZED;
      static int   QIDUM_[20];
#define Qtol (did_->Qtol_var)
      static int QInfRev, QiOpt, QNnl, Qinfo, QNLnr, QBase;

	  DYMOLA_STATIC int* QNLfunc;
	  DYMOLA_STATIC int* QNLjac;
	  DYMOLA_STATIC int *QNLcalls;
	  DYMOLA_STATIC int QNLmax;


#define PrintEvent (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mPrintEvent)
#define inJacobian_ (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mInJacobian)
#define solverHandleEq_ (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mSolverHandleEq)
#define continueSimulate_ (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mContinueSimulate)
#define dymolaParametersNr_ (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mParametersNr)
#define atDAEEvent_ (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mAtDAEEvent)
#define rememberOnlyAccepted_ (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mRememberOnlyAccepted)


      static int nx_, nx2_, nu_, ny_, nw_, np_, nsp_, nrel2_, nrel_, ncons_, dae_;

#define DYNTime (did_->time_var)
#define InitTime (did_->InitTime_var)
#define LastTime (did_->LastTime_var)
#define StepSize (did_->StepSize_var)
#define currentStepSize_ (did_->currentStepSize_var)
#define currentStepSizeRatio_ (did_->currentStepSizeRatio_var)
#define previousTime_ (did_->previousTime_var)
#define DYNhelp (did_->helpvar_vec)
#define DYNEvent (did_->Event_var)
#define initializationPhase_ (did_->initializationPhase_var)
#define Iter (did_->Iter_var)
#define MaxIter (did_->MaxIter_var)
#define EPS_ (did_->EPS_var)
#define FirstCross_ (did_->FirstCross_var)
#define FirstEvent (did_->FirstEvent_var)
#define ResetCounter_ (did_->ResetCounter_var)
#define DYNHReject (did_->HReject_var)

#define GlobalError_ (did_->GlobalError_var)
#define MixedFailFlag_ (did_->MixedFailFlag_var)
#define PerformIteration_ (did_->PerformIteration_var)

#define DymolaHomotopyLambda (did_->DymolaHomotopyLambda_var)
#define DymolaHomotopyLambdaFail (did_->DymolaHomotopyLambdaFail_var)
#define DymolaHomotopyLambdaDelta (did_->DymolaHomotopyLambdaDelta_var)
#define DymolaHomotopyUsed (did_->DymolaHomotopyUsed_var)
#define DymolaUserHomotopy (did_->DymolaUserHomotopy_var)

#define DymolaOneIteration_ (did_->DymolaOneIteration_var)
#define EqRemember1Time_ (did_->EqRemember1Time_var)
#define EqRemember2Time_ (did_->EqRemember2Time_var)
#define QPre_ (did_->QPre_vec)
#define RefPre_ (did_->RefPre_vec)
#define EqRemember1_ (did_->EqRemember1_vec)
#define EqRemember2_ (did_->EqRemember2_vec)
#define DYNAuxStr_ (did_->DYNAuxStrPtr_vec)
#define Aux_ (did_->Aux_vec)
#define QEvaluate_ (did_->QEvaluate_vec)
#define QEvaluateNew_ (did_->QEvaluateNew_vec)
#define QCheckIf_ (did_->QCheckIf_vec)
#define QTimed_ (did_->QTimed_vec)
#define Qenable_ (did_->Qenable_vec)
#define NextSampleTime_ (did_->NextSampleTime_vec)
#define NextSampleTimeNew_ (did_->NextSampleTimeNew_vec)
#define NextSampleAct_ (did_->NextSampleAct_vec)
#define NextSampleActNew_ (did_->NextSampleActNew_vec)
#define QL_ (did_->QL_vec)
#define QRel_ (did_->QRel_vec)
#define QM_ (did_->QM_vec)
#define Qn_ (did_->Qn_vec)
#define Qp_ (did_->Qp_vec)
#define Qscaled_ (did_->Qscaled_vec)
#define QZold_ (did_->QZold_vec)
#define oldQZ_ (did_->oldQZ_vec)
#define oldQZDummy_ (did_->oldQZDummy_vec)
#define oldQZ2_ (did_->oldQZ2_vec)
#define oldQZ3_ (did_->oldQZ3_vec)
#define QImd_ (did_->QImd_vec)
#define QIml_ (did_->QIml_vec)
#define Init_ (did_->Init_var)
#define AnyEvent_ (did_->AnyEvent_var)
#define AnyDEvent_ (did_->AnyDEvent_var)
#define AnyREvent_ (did_->AnyREvent_var)
#define AnyIEvent_ (did_->AnyIEvent_var)
#define AnyEventParameter_ (did_->AnyEventParameter_var)
#define NewParameters_ (did_->NewParameters_var)
#define dymolaEventsNr_ (did_->dymolaEventsNr_var)
#define EnforceWhen_ (did_->enforceWhen_var)
#define D_ (did_->discreteState_var)
#define XP_ (did_->pre_var)


#define EqRemAcc1Time_ (did_->eqRememberAccepted1Time)
#define EqRemAcc2Time_ (did_->eqRememberAccepted2Time)
#define EqRememberTemp_ (did_->EqRememberTemp_vec)
#define EqRemTempTime_ (did_->eqRememberTempTime)
#define EqRemTempTimeAcc_ (did_->eqRememberTempTimeAcc)

#define DYNAdvicePrinted_ (did_->nonlinearFailureAdvicePrinted)

#define DelayStruct_ (did_->del_vec)

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

#if !defined(NCheckIf_)
#define NCheckIf_ 0
#endif
#if !defined(NGlobalHelp_)
#define NGlobalHelp_ 100
#endif
#if !defined(NGlobalHelpI_)
#define NGlobalHelpI_ 100
#endif
#include <delay.h>

	  typedef struct DYNInstanceData {
		  struct BasicDDymosimStruct*basicD;
		  struct BasicIDymosimStruct*basicI;
		  int DymolaOneIteration_var; /* =2 first, =3 subsequent, 4 subsequent no iter, 5 subsequent without iteration, return !=0 => need more */
		  int HaveEventIterated_var;
		  int DymolaEventOptional_var;
		  int inCall_var;
		  delayStruct del_vec[SizeDelay_ ? SizeDelay_ : 1];
		  double helpvar_vec[NGlobalHelp_+1];
		  int helpvari_vec[NGlobalHelpI_+1];
		  double time_var;
		  double InitTime_var;
		  double LastTime_var;
		  double StepSize_var;
		  double currentStepSize_var;
		  double currentStepSizeRatio_var;
		  double currentStepSizeRatio2_var; /* Unused */
		  double previousTime_var;

		  Dymola_bool Event_var;
	      int initializationPhase_var;
	      int Iter_var, MaxIter_var;
          double EPS_var;
          int FirstCross_var;
          Dymola_bool FirstEvent_var;
	      int ResetCounter_var;
		  int HReject_var;

		  int GlobalError_var;
		  int MixedFailFlag_var;
		  Dymola_bool PerformIteration_var;

		  double DymolaHomotopyLambda_var;
		  double DymolaHomotopyLambdaFail_var;
		  double DymolaHomotopyLambdaDelta_var;
		  int DymolaHomotopyUsed_var;
		  int DymolaUserHomotopy_var;

		  double TimeStartOfSimulation_var;

		  double startNextTimeEvent_var;
		  double EqRemember1Time_var;
		  double EqRemember2Time_var;
		  struct DymolaTimes DymolaTimerStructs_vec[
#ifdef NrDymolaTimers_
			  NrDymolaTimers_ ? NrDymolaTimers_ : 1
#else
			  1
#endif
		  ];
		  int DymolaTimerStructsLen_var;
		  double DymolaStartTimers_vec[
#ifdef NrDymolaTimers_
NrDymolaTimers_ ? NrDymolaTimers_ : 1
#else
	1
#endif
			];
            double DymolaTimeZero_vec[DymolaNrStepTimers];
            int DymolaTimeZeroLength_var;
			int DymolaTimecounter_var;
		  double QPre_vec[SizePre_?SizePre_:1];
		  double RefPre_vec[SizePre_?SizePre_:1];
		  double EqRemember1_vec[SizeEq_?SizeEq_:1];
		  double EqRemember2_vec[SizeEq_?SizeEq_:1];
		  double Aux_vec[MAXAux+10000];
		  Dymola_bool QEvaluate_vec[NWhen_+1];
		  Dymola_bool QEvaluateNew_vec[NWhen_+1]; 
		  double QCheckIf_vec[NCheckIf_+1];
		  Dymola_bool QTimed_vec[NTim_+1];
		  Dymola_bool Qenable_vec[NRel_+1];
		  int oldReset_var;
		  double NextSampleTime_vec[NSamp_+1];
	      double NextSampleTimeNew_vec[NSamp_+1];
	      Dymola_bool NextSampleAct_vec[NSamp_+1];
	      Dymola_bool NextSampleActNew_vec[NSamp_+1];
		  Dymola_bool QL_vec[NRel_+1];
	      double QRel_vec[NRel_+1];
	      double QM_vec[NRel_+1];
	      double Qn_vec[NRel_+1];
	      double Qp_vec[NRel_+1];
	      double Qscaled_vec[NRel_+1];
	      double QZold_vec[2*NRel_+1];
	      double oldQZ_vec[2*NRel_+1];
	      double oldQZDummy_vec[2*NRel_+1];
	      double oldQZ2_vec[2*NRel_+1];
		  double oldQZ3_vec[2*NRel_+1];
		  Dymola_bool Init_var, AnyEvent_var, AnyDEvent_var, AnyREvent_var, AnyIEvent_var, AnyEventParameter_var, NewParameters_var;
		  struct ExternalTable_ externalTable_vec[
#ifdef NExternalObject_ 
			NExternalObject_+1
#else
			  1
#endif
		  ];
		  int dymolaParametersNrOld_;
	      int dymolaEventsNr_var;
		  int enforceWhen_var;

	      double * QJacobian_var;
	      double * QBJacobian_var;
	      double * QCJacobian_var;
	      double * QDJacobian_var;
	      int QJacobianN_var;
	      int QJacobianNU_var;
	      int QJacobianNY_var;
	      double * QJacobianSparse_var;
	      int* QJacobianSparseR_var ;
	      int* QJacobianSparseC_var ;
	      int QJacobianNZ_var;
		  int QSparseABCD_var;

		  double QImd_vec[
#ifdef NI_
	NI_*(2*NI_+5)+NX_*(4+3*NI_)+	
#endif
1
];
		  int QIml_vec[
#ifdef NI_
	5*NI_+
#endif
	1
];
		  char DYNAuxStrBuff_vec[
#if defined(MAXAuxStr_) && MAXAuxStr_>0
			MAXAuxStr_
#else
		  1
#endif
		  *
#if defined(MAXAuxStrLen_) && MAXAuxStrLen_>10
			MAXAuxStrLen_
#else
		  10
#endif
			  ];
			char* DYNAuxStrPtr_vec[
#if defined(MAXAuxStr_) && MAXAuxStr_>0
			MAXAuxStr_
#else
		  1
#endif
			];
			int currentIteration_var;
			double discreteState_var[ND_+1];
			double pre_var[NXP_+1];
			double xInitial_var[NInitial_+1];
			double xInitial_var2[NInitial_+1];
			double decoupleTime_var;
			Dymola_bool sectioncondition_var;
			double Qtol_var;

			double eqRememberAccepted1Time;
			double eqRememberAccepted2Time;
			double EqRememberTemp_vec[SizeEq_ ? SizeEq_ : 1];
			double eqRememberTempTime;
			double eqRememberTempTimeAcc;
			int hasStoredInTemp;
			int eqRememberReplaceOldDynamics;
			int eqRememberReplaceOldAccepted;

			int nonlinearFailureAdvicePrinted;
			char fmiResourceLocation[1024];
			
	  } DYNInstanceData;
	  /* Temporary ones: */

#define sectioncondition (did_->sectioncondition_var)
	  DYMOLA_STATIC int isModelicaEvent(void);
	  DYMOLA_STATIC int* GlobalErrorPointer(void);

struct BasicDDymosimStruct*getBasicDDymosimStructNew(struct DYNInstanceData*did) {
	if (did && did->basicD) return did->basicD;
	return getBasicDDymosimStruct();
}
#define triggerStepEvent_ (((struct BasicIDymosimStruct*) (DSE_STRUCT iuser_))->mTriggerStepEvent)
#ifndef FindEvent_
#define DYNFindEvent (((struct BasicIDymosimStruct*)  (DSE_STRUCT iuser_))->mFindEvent)
#else
#define DYNFindEvent FindEvent_
#if 0
#undef FindEvent_
#define FindEvent_ 1
#endif
#endif
	  
#define DYMResourceQuote2(fmin) #fmin
#define DYMResourceQuote(fmin) DYMResourceQuote2(fmin)

#if defined(DYN_MULTINSTANCE)
DYMOLA_STATIC size_t dyn_allowMultipleInstances=sizeof(struct DYNInstanceData);
#else
DYMOLA_STATIC size_t dyn_allowMultipleInstances=0;
#endif

#if defined(_WIN32) && (defined(_MSC_VER) || defined(DYN_MULTINSTANCE)) || defined(__MINGW32__)
#include <windows.h>
#if defined(DYN_MULTINSTANCE)
static DWORD dsTlsDynInstance=0;
#endif
#if !defined(FMU_SOURCE_CODE_EXPORT) && defined(FMI_MODULE_NAME)
#if defined(DYN_MULTINSTANCE)
DYMOLA_STATIC void EnsureMarkFree(struct DYN_ThreadData*threadData);
#endif
BOOL __stdcall DllMain(HINSTANCE hinstDLL,  /* DLL module handle*/
    DWORD fdwReason,              /* reason called*/
    LPVOID lpvReserved)           /* reserved*/
{ 
    LPVOID lpvData; 
    BOOL fIgnore; 
 
    switch (fdwReason) 
    { 
        /* The DLL is loading due to process */
        /* initialization or a call to LoadLibrary. */
 
        case DLL_PROCESS_ATTACH: 
 
            /* Allocate a TLS index.*/
 #if defined(DYN_MULTINSTANCE)
            if ((dsTlsDynInstance = TlsAlloc()) == 0xFFFFFFFF) 
                return FALSE; 
#endif
           /* No break: Initialize the index for first thread.*/
 
        /* The attached process creates a new thread. */
 
        case DLL_THREAD_ATTACH: 
 
            /* Initialize the TLS index for this thread.*/

 
            break; 
 
        /* The thread of the attached process terminates.*/
 
        case DLL_THREAD_DETACH: 
 
            /* Release the allocated memory for this thread.*/
#if defined(DYN_MULTINSTANCE) 
            lpvData = TlsGetValue(dsTlsDynInstance); 
            if (lpvData != NULL) {
				EnsureMarkFree((struct DYN_ThreadData*)(lpvData));
                LocalFree((HLOCAL) lpvData); 
			}
			lpvData = NULL;
			TlsSetValue(dsTlsDynInstance, lpvData);
#endif
            break; 
 
        /* DLL unload due to process termination or FreeLibrary.  */
 
        case DLL_PROCESS_DETACH: 
 
            /* Release the allocated memory for this thread. */
 #if defined(DYN_MULTINSTANCE)
            lpvData = TlsGetValue(dsTlsDynInstance); 
            if (lpvData != NULL) {
				EnsureMarkFree((struct DYN_ThreadData*)(lpvData));
                LocalFree((HLOCAL) lpvData); 
			}
			lpvData = NULL;
			TlsSetValue(dsTlsDynInstance, lpvData);
            /* Release the TLS index. */
			TlsFree(dsTlsDynInstance); 
#endif
#ifndef __MINGW32__
			freeClocale();
#endif
            break; 
 
        default: 
            break; 
    } 
 
    return TRUE; 
    UNREFERENCED_PARAMETER(hinstDLL); 
    UNREFERENCED_PARAMETER(lpvReserved); 
}
#endif /*!defined(FMU_SOURCE_CODE_EXPORT)*/
#if defined(DYN_MULTINSTANCE)
static struct DYN_ThreadData* DYN_GetThreadData() {
	LPVOID lpvData; 
	lpvData = TlsGetValue(dsTlsDynInstance); 
    if (lpvData == NULL) {
		/* This is a critical region, but since using Tls it is already guarded */
		lpvData = LocalAlloc(LPTR, sizeof(struct DYN_ThreadData)); /* LPTR means fixed and zero-initialized */
		if (lpvData) {
			TlsSetValue(dsTlsDynInstance, lpvData);
		}
	}
	return (struct DYN_ThreadData*)(lpvData);
}
#endif /*defined(DYN_MULTINSTANCE)*/
#endif
#if defined(DYN_MULTINSTANCE) && !(defined(_WIN32))
#if defined(__GNUC__) || DYN_COMPILER_SUPPORTS__THREAD
static __thread struct DYN_ThreadData dyn_threadData={0};
static struct DYN_ThreadData* DYN_GetThreadData() {
	return &dyn_threadData;
}
#else
#error Multiple instance only supported for Windows and Gcc so far
#endif
#endif

#if defined(RT) || defined(NRT)
#if defined(DYN_MULTINSTANCE)
LIBDS_API struct BasicIDymosimStruct*getBasicIDymosimStruct() {
	return DYN_GetThreadData()->did->basicI;
}
LIBDS_API struct BasicDDymosimStruct*getBasicDDymosimStruct() {
	return DYN_GetThreadData()->did->basicD;
}
LIBDS_API void setBasicStruct(double*d,int*i) {
	if (!DYN_GetThreadData()->did) return;
	DYN_GetThreadData()->did->basicI=(struct BasicIDymosimStruct*)(i);
	DYN_GetThreadData()->did->basicD=(struct BasicDDymosimStruct*)(d);
}
#else
static struct BasicIDymosimStruct*basicI=0;
static struct BasicDDymosimStruct*basicD=0;
LIBDS_API struct BasicIDymosimStruct*getBasicIDymosimStruct() {
	return basicI;
}
LIBDS_API struct BasicDDymosimStruct*getBasicDDymosimStruct() {
	return basicD;
}
LIBDS_API void setBasicStruct(double*d,int*i) {
	basicI=(struct BasicIDymosimStruct*)(i);
	basicD=(struct BasicDDymosimStruct*)(d);
}
#endif
#endif

static const char*dymosimResourceLocation=0;
#ifdef FMI_MODULE_NAME
const char* dymosimFMIPath() {
	static char extraPath[1000];
#ifdef NO_FILE
	extraPath[0] = 0;
#elif (defined(_WIN32) && defined(_MSC_VER)) || defined(__MINGW32__)
	HMODULE hMySelf=0;
	hMySelf=GetModuleHandleA(DYMResourceQuote(FMI_MODULE_NAME));
	extraPath[0] = 0;
	GetModuleFileNameA(hMySelf, extraPath, sizeof(extraPath)-1);
#elif (defined(__unix__) || defined(__linux__) || defined(__APPLE_CC__)) && defined(__GNUC__) && defined(FMI_MODULE_NAME)
   Dl_info dl_info;
   dladdr(dymosimFMIPath, &dl_info);
   extraPath[0] = 0;
   strncpy(extraPath, dl_info.dli_fname, sizeof(extraPath)-1);
#endif
   extraPath[sizeof(extraPath)-1] = 0;
   return extraPath;
}
#endif
static char dymosimResourceExtraPath[1000];
DYMOLA_STATIC const char* dymosimResources2(struct DYNInstanceData*did_) {
	static int first=1;
#if defined(MatlabR13)
	return "DymosimResources/";
#endif
	if (did_ && did_->fmiResourceLocation[0] != '\0') {
		return did_->fmiResourceLocation;
	}
	if (first && !dymosimResourceLocation) {

		char*last;
		int twice=0;
#if (defined(_WIN32) && defined(_MSC_VER)) || defined(__MINGW32__)
		HMODULE hMySelf=0;
		const char* separator = "\\";
#ifdef FMI_MODULE_NAME
		hMySelf=GetModuleHandleA(DYMResourceQuote(FMI_MODULE_NAME));
		twice=1;
#else
		hMySelf=GetModuleHandleA(0);
#endif /* FMI_MODULE_NAME */
		dymosimResourceExtraPath[0] = 0;
		if (GetModuleFileNameA(hMySelf, dymosimResourceExtraPath, sizeof(dymosimResourceExtraPath)/sizeof(*dymosimResourceExtraPath))!=0) {

#elif defined(__GNUC__)
		{
			const char* separator = "/";
#if defined(UNIX) && defined(FMI_MODULE_NAME)
			/* Linux gcc and FMU so file */
			twice = 1;

			Dl_info dli;
			if (dladdr(__builtin_return_address(0), &dli) != 0 && dli.dli_fname != NULL) {
				strcpy(dymosimResourceExtraPath, dli.dli_fname);
			} else {
				DymosimMessage("Error: dladdr failed to fetch location of this FMU so file.");
			}
#else  /* defined(UNIX) && defined(FMI_MODULE_NAME) */
			/* resources for non-FMUs not supported on Linux, neglect */
#endif /* defined(UNIX) && defined(FMI_MODULE_NAME) */

#else  /* defined(__GNUC__) ... */
			/* neither Windows nor gcc, neglect */
		{
					const char* separator = "/";
#endif /* defined(__GNUC__) ... */
#ifdef __MINGW32__
			/* Fetch path from explcitly stored file created during translation.
			   This special treatment is a consequence of the fact that MinGW gcc does not support delay loading. */
			{
				FILE* f;
				strcat(dymosimResourceExtraPath, ".originalPath.txt");
				f = fopen(dymosimResourceExtraPath, "r");
				if (f == NULL) {
					DymosimMessage("Error: failed to open file with original path for this FMU");
				}
				else {
					char format[32];
					snprintf(format, sizeof(format), "%%%us", sizeof(dymosimResourceExtraPath) / sizeof(*dymosimResourceExtraPath) - 1);
					fscanf(f, format, dymosimResourceExtraPath);
					fclose(f);
				}
			}
#endif /* __MINGW32__ */
			dymosimResourceExtraPath[sizeof(dymosimResourceExtraPath)/sizeof(*dymosimResourceExtraPath)-1]=0; /* /Make sure it is NUL-terminated */
			last=strrchr(dymosimResourceExtraPath,'\\');
			if (last==0) last=strrchr(dymosimResourceExtraPath,'/');
			if (last && twice) {
				last[0]=0;
				last=strrchr(dymosimResourceExtraPath,'\\');
				if (last==0) last=strrchr(dymosimResourceExtraPath,'/');
				if (last) {
					last[0]=0;
					last=strrchr(dymosimResourceExtraPath,'\\');
					if (last==0) last=strrchr(dymosimResourceExtraPath,'/');
				}
			}
			if (last) last[1]=0;
			if (twice) {
				strcat(dymosimResourceExtraPath,"resources");
				strcat(dymosimResourceExtraPath,separator);
			} else {
				strcat(dymosimResourceExtraPath,"DymosimResources");
				strcat(dymosimResourceExtraPath,separator);
			}	
			dymosimResourceLocation= dymosimResourceExtraPath;
		}
		first=0;
	}
	return dymosimResourceLocation ? dymosimResourceLocation : "DymosimResources/";
}
DYMOLA_STATIC const char* dymosimResources() {
	return dymosimResources2(0);
}
DYMOLA_STATIC double DYNhomotopy(double actual, double simple,struct DYNInstanceData*did_) {
	DymolaHomotopyUsed=1;
	return simple*(1-DymolaHomotopyLambda)+actual*DymolaHomotopyLambda;
}
DYMOLA_STATIC void dymosimSetResources2(struct DYNInstanceData*did_, const char*s) {
	if (did_) {
		did_->fmiResourceLocation[0] = '\0';
		if (s && s[0]!='\0') {
			strncpy(did_->fmiResourceLocation, s, sizeof(did_->fmiResourceLocation) - 1);
			did_->fmiResourceLocation[sizeof(did_->fmiResourceLocation) - 2] = '\0';
			if (did_->fmiResourceLocation[strlen(did_->fmiResourceLocation)-1]!='/' && did_->fmiResourceLocation[strlen(did_->fmiResourceLocation) - 1] != '\\') strcat(did_->fmiResourceLocation, "/");
		}
	} else {
		if (s && s[0] != '\0') {
			strcpy(dymosimResourceExtraPath, s);
			if (dymosimResourceExtraPath[strlen(dymosimResourceExtraPath) - 1] != '/' && dymosimResourceExtraPath[strlen(dymosimResourceExtraPath) - 1] != '\\') strcat(dymosimResourceExtraPath, "/");
			dymosimResourceLocation = dymosimResourceExtraPath;
		} else {
			dymosimResourceLocation = 0;
		}
	}
}
DYMOLA_STATIC void dymosimSetResources(const char*s) {
	dymosimSetResources2(0, s);
}
static void handleevent4funcMinor(struct DYNInstanceData*did_,const char*rele,const char*sube,int index, int PrintEvent2,int ltz,int invres) {
	handleevent4(rele,sube,&QL_[index], &Qp_[index-1],&Qn_[index-1],EPS_*Qscaled_[index-1],QRel_[index-1],Init_, PrintEvent2,&AnyEvent_,ltz,invres,Qenable_[index],LargeEPS_*Qscaled_[index-1],Iter>SlowIter_,index);
}
static void handleevent4func(struct DYNInstanceData*did_,const char*rele,const char*sube,int index, int PrintEvent2,int ltz,int invres) {
	handleevent5(rele,sube,&QL_[index], &Qp_[index-1],&Qn_[index-1],EPS_*Qscaled_[index-1],QRel_[index-1],Init_, PrintEvent2,&AnyEvent_,&AnyDEvent_,ltz,invres,Qenable_[index],LargeEPS_*Qscaled_[index-1],Iter>SlowIter_,index);
}

static Dymola_bool handleevent4Sfunc(struct DYNInstanceData*did_,const char*rele,const char*sube,double*QZV,int index, int incross,double Time,int PrintEvent2,int ltz,int invres) {
	Dymola_bool AE=0;
	Dymola_bool res;
	res=handleevent5S(rele,sube,
		&QL_[index],&Qp_[index-1],&Qn_[index-1],EPS_,QRel_[index-1],&QZV[2*(index)-2],Init_,DYNEvent,incross,PrintEvent2,&AE,ltz,invres,&Qenable_[index],LargeEPS_,Iter>SlowIter_,DYNTime, Iter==1, index);
	if (AE) {AnyEvent_=1;AnyIEvent_=1;}
	return res;
}
static int DYNIncrementFExternal() {
	AssertModelicaF(
#ifdef NSizeOfFunctionStack
		FunctionExternalContext_<NSizeOfFunctionStack
#else
	    0
#endif
		,"", "Out of stack for external objects in functions; see documentation to change.");

	return FunctionExternalContext_++;
}
#if defined(DYMOSIM)
LIBDS_API double PositiveImpulse(int, double, double,int);
LIBDS_API double SymmetricImpulse(int, double, int);
LIBDS_API double DiracImpulse(int, double, double, int);
LIBDS_API double DiracIntegral(int, double, double , int);
LIBDS_API double HeaviSide(int, double, double, int);
static void InitI(struct DYNInstanceData* did_,int,int);
#endif

#if defined(_MSC_VER)
#if !DymolaGlobalOptimizations_
/* Visual C++ does not work well for large models with global optimization.
   Remove at your own risk */
#pragma optimize( "g", off )
#elif DymolaGlobalOptimizations_ == 2
#pragma optimize( "g", on )
#endif
#endif

#if defined(DS_EMBEDDED)
#include <dsembedded.c>
#endif
#if defined(DYNCALLFMUREINIT)
DYMOLA_STATIC void DelayedUpdateReinit(double*time, double* X_, double* W_,double* U_,double* Y_, struct DYNInstanceData*did_);
#endif
DYMOLA_STATIC void equations_(int *idemand_, int *icall_, 
      double *time, double X_[], double XD_[], double U_[], \
      double DP_[], int IP_[], Dymola_bool LP_[], \
      double F_[], double Y_[], double W_[], double QZ_[], 
      double duser_[], int iuser_[], void*cuser_[], struct DYNInstanceData* did_, 
      int *QiErr, int tid) 
{   
/* End dsblock1.c */
