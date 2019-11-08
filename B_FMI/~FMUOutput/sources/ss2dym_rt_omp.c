/* ss2dym.c
 
SS2DYM - SimStruct to Dymola interface.

Author:  Hilding Elmqvist, Dynasim AB
Version:
  1.0, 1995-03-19 
  1.1, 1996-09-27: 
    Second S-Function parameter x0 for initial conditions added. 
    Two parameters param and x0 must now be provided in the
    S-Function block. Courtesy: ABB Corporate Research, Switzerland
  1.2, 1996-11-06:
    Modifications in order to allow approximate state event handling.
  1.3, 1997-04-17: Corrected non-essential index bug.
  1.4, 1997-07-18: Initialization of iErr added.
  1.5, 1997-11-26: Support of state events (zero crossing) 
                   in Simulink 2.1 added.
  1.6, 1997-11-29: Fixes for compatibility with Matlab 4.2
  1.7, 1998-02-10: Fixed problem with ssIsSampleHitEvent in mdlUpdate
  1.8, 1998-03-28: Activated state event handling.
  1.9, 1998-09-13: Introduced call to ssSetSolverNeedsReset(S) to 
                   handle init(x).
                   Clean-up for dSPACE use.
  1.10 1999-01-20: Further clean-up for dSPACE and MATLAB 4.2
  1.11 1999-06-20: Support for time events.
  1.12 1999-06-21: Support for sections.
  1.13 2000-10-09: Improve event handling and stiff solvers, set solverHandleEq_
  1.14 2001-02-16: Add terminate call.
  1.15 2001-10-01: Correct FeedThrough for Matlab 6.1.

This is a SimStruct to Dymola interface. It enables models generated 
by Dymola to be incorporated in SIMULINK.

*/
/*
 * Copyright (C) 1995-2005 Dynasim AB.
 * All rights reserved.
 *
 */

/* OpenMP RT interface */
#ifndef _GNU_SOURCE
 #define _GNU_SOURCE
#endif
#include <sched.h>
#include <mpadvise.h>
#include <omp.h>
#define NUM_THREADS 4

/* Uncomment only if the model that is exported to Simulink contains an imported FMU. */
/* #define ModelWithFMU */

#ifndef S_FUNCTION_LEVEL
#define S_FUNCTION_LEVEL 2
#endif
/* Must increase to 2 for Jacobians. Can only use level 2 for Matlab 6.1 (and Matlab 6.0)
   and later (since some functions were not present in Matlab 5.3). */
#if S_FUNCTION_LEVEL > 1 && !defined(Matlab6) && !((defined(RT) || defined(NRT)) && !defined(DYMOLA_DSPACE))
#undef S_FUNCTION_LEVEL
#define S_FUNCTION_LEVEL 1
#endif

#if !defined(DYMOLA_STATIC)
#if defined(__cplusplus)
#define DYMOLA_STATIC extern
#elif defined(RT) && !defined(DYM2DS) && !defined(DYM2CCUR)
#define DYMOLA_STATIC static
#else
#define DYMOLA_STATIC
#endif
#endif

#if (defined(RT) || defined(NRT)) && !defined(DYMOLA_DSPACE)
#if !defined(Matlab51)
#define Matlab51
#endif
#if !defined(Matlab6)
#define Matlab6
#endif
#if !defined(LABCAR)
#define NO_FILE
#endif
#define DYMOSIM_RT_IMP
#endif
#if !defined(S_FUNCTION_NAME)
#if !defined(Matlab51) && defined(DYMOLA_DSPACE)
#define S_FUNCTION_NAME simstr
#else
#define S_FUNCTION_NAME SimStr
#endif
#endif

#if defined(RT) && !defined(DYM2CCUR)
static int simulinkInterface_;
static int DirectFeedThrough_;
#endif

/*#define AUTO_RESET_AFTER 5*/
#if defined(AUTO_RESET_AFTER)
static int isAutoResetting=0;
static double autoResetTime=0;
#endif

#define HAVE_GENERATED_JACOBIAN 0
  /* Change to 1 to use Jacobian code (must generate Jacobian code in Dymola) */
  /* Requires Matlab 6.1 (or Matlab 6.0?) */

  /* You also have to uncomment S_FUNCTION_LEVEL as above */

#if HAVE_GENERATED_JACOBIAN && !(S_FUNCTION_LEVEL > 1)
#error Jacobian require S_FUNCTION_LEVEL 2
#undef HAVE_GENERATED_JACOBIAN
/* Note: This error check might fail!!!! */
#endif


#if defined(DYMOLA_DSPACE)
/* Assume we are compiling for dSPACE application. */
#if !defined(__GNUC__)
#if !defined(_MICROTEC)
/* If this is not the Microtec GCC compiler, assume TI DSP (DS1003) */
#define double real_T
#endif
#endif
#include <dsdefs.h>
#endif

#if defined(Matlab51)
  #include "tmwtypes.h"
#endif

#include <math.h>
#include "simstruc.h"

#include "dsblock.h"
#include "userdefs.h"
#include "sprwat.h"

#define LogCalls 0            /* Log calls to mdl-functions or not. */

#if 0
#define DirectFeedThrough 0      /* Old manual setting of DirectFeedThrough, no longer used.
                                 Change this to 0 if there is no direct feed
                                 through and you need to use the block in a 
                                 loop. This will make the simulation a little 
                                 slower. Setting it to 0 can crash in Matlab 6.1.*/
#else
extern int DirectFeedThrough_;
#define DirectFeedThrough DirectFeedThrough_
#endif

static int NotInitialized = 1;

/* To re-calculate bound parameters */
static int ParamChange = 0;


static int EventInUpdate = 1;
static int HaveEventIterated_=0;
static double InitTime_;

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
#ifdef GenerateResultInNonDymosim
#if !GenerateResultInNonDymosim
/* Since it is not legal to embed = in mex-scripts */
#undef GenerateResultInNonDymosim
#define GenerateResultInNonDymosim 1
#endif
#endif

#if GenerateResultInNonDymosim==1 && (defined(RT) || defined(NRT) || defined(DYMOLA_DSPACE))
#undef GenerateResultInNonDymosim
/* In case we only wanted resulted in normal Simulink */
#endif

#ifdef GenerateResultInNonDymosim
#include "GenerateResultInNonDymosim.c"
#include "atraj.c"
struct DeclarePhase phase={0};
#endif

DYMOLA_STATIC void InitializeDymosimStruct(struct BasicDDymosimStruct*,struct BasicIDymosimStruct*);
DYMOLA_STATIC void declare_(double*,double*,double*,void**,int*);
DYMOLA_STATIC void dymTableClear(void);
DYMOLA_STATIC void delayBuffersClose(void);

#if !defined(DYMOLA_DSPACE) && !defined(RT) && !defined(NRT)
extern void DymosimEnsureDLLLoaded(const char*const*toLoad, void***handles, int load, const char* fmuDLLpath);
void**handles=0;
extern const char*dllLibraryPath[];
#endif

DYMOLA_STATIC void SetDymolaJacobianPointers(struct DYNInstanceData*did_, double * QJacobian_,double * QBJacobian_,double * QCJacobian_,double * QDJacobian_,int QJacobianN_,
	int QJacobianNU_,int QJacobianNY_,double * QJacobianSparse_,int * QJacobianSparseR_,int * QJacobianSparseC_,int QJacobianNZ_);
DYMOLA_STATIC void SetDymolaEventOptional(struct DYNInstanceData*did_, int val);
DYMOLA_STATIC int GetDymolaHaveEventIterated(struct DYNInstanceData*did_);

double timeToAdd = 0.0;

DYMOLA_STATIC void simblock_(SimStruct *S, 
     int *idemand_, int *icall_, 
     double *time, double x_[], double xd_[], double u_[], 
     double dp_[], int ip_[], Dymola_bool lp_[], 
     double f_[], double y_[], double w_[], double qz_[], 
     double duser_[],
     int *ierr_) {
  int idem;
  int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;
  int actual_np;
  int isResetting=0;
  void**cuser_;
  int*iuser_;
  double*duser2_;

  GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);
  duser2_=duser_+7+nu;
  cuser_=&(ssGetPWork(S)[1]);
  iuser_=(int*)(ssGetPWork(S)[0]);
  setBasicStruct(duser2_,iuser_);
start:
  *ierr_ = 0;
  *icall_ = 0;
  (*time) += timeToAdd;
  if (NotInitialized) {
#if !GenerateResultInNonDymosim
	  if (cuser_)
		  declare_(0,0,0,cuser_,ierr_);
#endif
	  InitializeDymosimStruct(getBasicDDymosimStruct(),getBasicIDymosimStruct());
  }
#if defined(AUTO_RESET_AFTER)
  if (NotInitialized)
	  isAutoResetting=0;
  if (isAutoResetting) {
	  if (*time>=autoResetTime && *idemand_==5) {
		NotInitialized=1;
		isResetting=1;
		isAutoResetting=0;
	  } else return;
  }
#endif
  if (NotInitialized)
    getBasicDDymosimStruct()->mNextTimeEvent = 1.0E37;

  if (NotInitialized) {
	  extern int simulinkInterface_;
#if GenerateResultInNonDymosim
	  DeclarePhase9(&phase);
	  DeclarePhase0(cuser_);
#endif
#if LogCalls
	DymosimMessage("simBlock initialize");
#endif

	SetDymolaEventOptional(0, 1);
    GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);
	/* See support e-mail 2003-05-26 08:34. */
#if !defined(DYMOLA_DSPACE) && !defined(RT) && !defined(NRT)
    {
      static int firstTime=1;
      if (firstTime) {
         char str[1000];
         extern int Check5(char*);
#if defined(MatlabR13)
		 mxArray*mx=mexGetVariable("base", "DymolaRuntimeCode");
#else
         mxArray*mx=mexGetArray("DymolaRuntimeCode", "base");
#endif
         if (mx && mxGetClassID(mx)==mxCHAR_CLASS) {
			mxGetString(mx, str, sizeof(str));
         } else {str[0]=0;}
         if (!Check5(str)) {
			ssSetErrorStatus(S, "No license to run model");
            return;
         }
         firstTime=0;
	  }
	}
#endif
	if(ssGetSFcnParamsCount(S) == 0) {
		actual_np = 0;
	} else {
#if S_FUNCTION_LEVEL > 1
	actual_np = mxGetM(ssGetSFcnParam(S,0));
#else
	actual_np = mxGetM(ssGetArg(S,0));
#endif
	}
    if (actual_np != np) {
      DymosimMessageInt("Expected number of parameters: ", np);
      DymosimMessageInt("Actual number of parameters: ", actual_np);
      ssSetErrorStatus(S, "Error encountered in S-function MEX file: wrong size of parameter vector.");
      return;
    }
	{
		/*char str[100];*/
		/*sprintf(str,"Var %d, order %d, %s inline %d\n",ssIsVariableStepSolver(S),ssIsVariableStepSolver(S),
			ssGetSolverName(S),
			inlineIntegration_);*/
		if (getBasicIDymosimStruct()->mInlineIntegration==1 && getBasicDDymosimStruct()->mDymolaFixedStepSize<=0) {
            if (ssIsVariableStepSolver(S) || (strcmp(ssGetSolverName(S),"FixedStepDiscrete")!=0 &&
                                              strcmp(ssGetSolverName(S),"ode1")!=0 && 
                                              strcmp(ssGetSolverName(S),"euler")!=0) && 
                                              strcmp(ssGetSolverName(S),"Euler")!=0) {
                                                 
                ssSetErrorStatus(S, "Error encountered in Dymola block: \n"
				                    "Inline integration requires fixed-step ode1 (Euler) or discrete solver. \n\n"
                                    "To use other solvers, set Advanced.InlineAsDiscrete = true in Dymola.\n"
                                    "This will make the DymolaBlock a discrete block with the sampling time given\n"
                                    "by the Realtime tab in the Dymola Simulation Setup.");
                return;
            }
        }
		getBasicIDymosimStruct()->mFindEvent=(getBasicIDymosimStruct()->mInlineIntegration && getBasicDDymosimStruct()->mDymolaFixedStepSize>0) 
			|| (!ssIsVariableStepSolver(S) && ssGetSolverMaxOrder(S)<=1);
		/*DymosimMessage(str);*/
	}

    idem = 0;
	getBasicIDymosimStruct()->mSolverHandleEq=1;
        InitTime_=*time;
		{
			int i_;
			getBasicDDymosimStruct()->mOrigTimeError=0;
			dymTableClear();
			delayBuffersClose(); 
#if !defined(DYMOLA_DSPACE) && !defined(RT) && !defined(NRT)
			if (handles==0) {
				if (dllLibraryPath != 0 && dllLibraryPath[0] != 0) {
					DymosimEnsureDLLLoaded(dllLibraryPath, &handles, 1, 0);
				}
			}
#endif
			for(i_=0;i_<nw;i_++) w_[i_]=0;
		}
	{
		if (!DirectFeedThrough) {
			int i_;
			if (isResetting) {
				for(i_=0;i_<nu;i_++) duser_[3+i_]=u_[i_];
			}
			u_=&(duser_[3]);
			if (!isResetting) for(i_=0;i_<nu;i_++) u_[i_]=0.0;
			
		}
#if defined(RT)
        /* For HILS, initialization is performed from mdlInitializeConditions (to avoid overruns in first time-step) */
		/* At this point input values are not yet computed. */
		/* Input start values provided in model are used. */
		/* NOTE: Offline siulation in Simulink uses actual input values during initialization! */
        {
			int i_;
            for(i_=0;i_<nu;i_++) u_[i_]=u0_[i_];
        }
#endif

#if LogCalls
	DymosimMessage("simBlock initialize call");
#endif
		dsblock_(&idem, icall_, time, x_, xd_, u_, dp_, ip_, lp_, 
      f_, y_, w_, qz_, duser2_, iuser_, cuser_, ierr_);
#if LogCalls
	DymosimMessage("simBlock initialized");
#endif	
#if GenerateResultInNonDymosim
	  DeclarePhase1(&phase);
	  DeclarePhase3(&phase,*time,ssGetTFinal(S),dp_,x_,xd_,y_,u_,w_); 
#endif
       }
    NotInitialized = 0;
  }

  if (!DirectFeedThrough && *idemand_==1 && InitTime_==*time)
    u_=&(duser_[3]);

  dsblock_(idemand_, icall_, time, x_, xd_, u_, dp_, ip_, lp_, 
    f_, y_, w_, qz_, duser2_, iuser_, cuser_, ierr_);
  if ((*ierr_ == -993) || (*ierr_==-994) || (*ierr_==-995)) {
	  *ierr_=0;
  } else if (*ierr_==-998) {
	  *ierr_=0;
	  if (!isResetting) {
		isResetting=1;
		NotInitialized=1;
		goto start;
	  }
  }
#if defined(AUTO_RESET_AFTER)
  if (*ierr_!=0) {
	  isAutoResetting=1;
	  autoResetTime=*time+AUTO_RESET_AFTER;
	  *ierr_=0;
  }
#endif

#if defined(Matlab51)
  HaveEventIterated_=0;
  if(*ierr_ != 0) {
    ssSetErrorStatus(S, "Error encountered in DymolaBlock S-function. See Message in Matlab window.");
    return;
  } else if (isResetting && nx>0) {
	  HaveEventIterated_=1;
  } else if (*idemand_==5 && GetDymolaHaveEventIterated(0)) {
	  HaveEventIterated_=1;
  }
#endif
}


/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *
 * The sizes information is used by SIMULINK to determine the S-function 
 * block's characteristics (number of inputs, outputs, states, etc.).
 * 
 */

static void mdlInitializeSizes(SimStruct *S)
{
    int nx, nx2, nu, ny, nw, np, nsp, nrel2, nrel, ncons, dae;
#if LogCalls
      DymosimMessage("mdlInitializeSizes start");
#endif
#if defined(Matlab51)
    ssSetNumSFcnParams(S, 2);  /* Number of expected parameters */
	/* See support e-mail 2003-05-26 08:34.
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        ssSetErrorStatus(S, "Wrong number of parameters to S-function MEX file");
        return;
    }
	*/

    if (sizeof(real_T) != sizeof(double))
      DymosimError("Incompatible size of real_T and double");
#else
    ssSetNumInputArgs(     S, 2);      /* number of input arguments */
#endif

    GetDimensions2(&nx, &nx2, &nu, &ny, &nw, &np, &nsp, &nrel2, &nrel, &ncons, &dae);
    ssSetNumContStates(    S, nx);     /* number of continuous states */
	{
		struct BasicDDymosimStruct basicD={0};
		struct BasicIDymosimStruct basicI={0};
		InitializeDymosimStruct(&basicD,&basicI);
		EventInUpdate=!DirectFeedThrough || basicI.mInlineIntegration;
	}
#if GenerateResultInNonDymosim
	if (1)
#else
	if (DirectFeedThrough && EventInUpdate)
#endif
		ssSetNumDiscStates(S, 1);
	else
		ssSetNumDiscStates(    S, 0);      /* number of discrete states */
/*  ssSetNumDiscStates(    S, 1);      
         Use one discrete dummy state to force mdlUpdate to be called even if 
         there is direct feedthrough.               */
#if S_FUNCTION_LEVEL > 1
	if (nu>0) {
		if (!ssSetNumInputPorts(S, 1)) 
			return;
		ssSetInputPortWidth(S, 0, nu);      /* Width of input */
		ssSetInputPortRequiredContiguous(S, 0, 1);
		ssSetInputPortDirectFeedThrough(S, 0, DirectFeedThrough); /* direct feedthrough flag */
	}
	if (ny>0) {
		if (!ssSetNumOutputPorts(S, 1)) 
			return;
		ssSetOutputPortWidth(S, 0, ny);     /* Width of output */
	}
#else
    ssSetNumInputs(        S, nu);     /* number of inputs */
    ssSetNumOutputs(       S, ny);     /* number of outputs */
    ssSetDirectFeedThrough(S, DirectFeedThrough); /* direct feedthrough flag */
#endif

    ssSetNumSampleTimes(   S, 1);      /* number of sample times */
    ssSetNumRWork(         S, nu+nx+ny+nw+2*nrel+7+(sizeof(struct BasicDDymosimStruct)/sizeof(double)));      /* number of real work vector elements */
    ssSetNumPWork(         S, nsp+1);      /* number of pointer work vector elements */
#if defined(Matlab51)
    ssSetNumModes(         S, 0);   /* number of mode work vector elements   */
    ssSetNumNonsampledZCs( S, 2*nrel + 1); /* number of zero crossings. 
	  The last one is used for time events. */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);  /* dsblock_ does use longjump. */
#if HAVE_GENERATED_JACOBIAN
	{ 
		extern int QJacobianDefined_;
		ssSetJacobianNzMax(S, (ny+nx)*(nu+nx));
		ssSetNumRWork(S, ssGetNumRWork(S)+ssGetJacobianNzMax(S));
		if (!QJacobianDefined_) {
	        ssSetErrorStatus(S, "HAVE_GENERATED_JACOBIAN defined, but no Jacobian in model.");
			return;
		}
	}
#endif
#endif
	NotInitialized=1;
	timeToAdd = 0.0;
#if !defined(ModelWithFMU)
	ParamChange=1; /* Will enforce evaluating BoundParameterSection from mdlDerivatives */
					/* Required to get correct values of inputs if no direct feedthrough */ 
#endif
}


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *
 * This function is used to specify the sample time(s) for your S-function.
 * You must register the same number of sample times as specified in 
 * ssSetNumSampleTimes. 
 */

static void mdlInitializeSampleTimes(SimStruct *S)
{
#if defined(Matlab5) || defined(Matlab51) 
	struct BasicDDymosimStruct basicD={0};
	struct BasicIDymosimStruct basicI={0};
	InitializeDymosimStruct(&basicD,&basicI);
	if (basicI.mInlineIntegration && basicD.mDymolaFixedStepSize>0) {
		ssSetSampleTime(S, 0, basicD.mDymolaFixedStepSize);
	} else if (basicI.mInlineIntegration && basicD.mDymolaFixedStepSize<0) {
		ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
	} else {
		ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);
	}
	ssSetOffsetTime(S, 0, 0.0);

#else
    ssSetSampleTimeEvent(S, 0, 0.0);
    ssSetOffsetTimeEvent(S, 0, 0.0);
#endif
}

#if S_FUNCTION_LEVEL > 1
static void mdlOutputs(SimStruct *S, int_T tid);
static void mdlUpdate(SimStruct *S, int_T tid);
#endif

/* Function: mdlInitializeConditions ==========================================
 * Abstract:
 *
 * In this function, you should initialize the continuous and discrete
 * states for your S-function block.  The initial states are placed
 * in the x0 variable.  You can also perform any other initialization
 * activities that your S-function may require.
 */

#if S_FUNCTION_LEVEL > 1
static void mdlInitializeConditions(SimStruct *S)
#define MDL_INITIALIZE_CONDITIONS
#elif defined(Matlab51)
  static void mdlInitializeConditions(real_T *x0, SimStruct *S)
#else
  static void mdlInitializeConditions(double *x0, SimStruct *S)
#endif
{
    double *arg1;
    int i, nx, actual_nx;
#if S_FUNCTION_LEVEL > 1
	double * x0 = (double*)ssGetContStates(S);
#endif

#if LogCalls
      DymosimMessage("mdlInitializeConditions");
#endif

	nx = ssGetNumContStates(S);
	/* See support e-mail 2003-05-26 08:34. */
	if(ssGetSFcnParamsCount(S) == 0) {
		arg1 = NULL;
		actual_nx = 0;
	} else {
#if S_FUNCTION_LEVEL > 1
		arg1 = (double *) mxGetPr(ssGetSFcnParam(S,1));
		actual_nx = mxGetM(ssGetSFcnParam(S,1));
#else
		arg1 = (double *) mxGetPr(ssGetArg(S,1));
		actual_nx = mxGetM(ssGetArg(S,1));
#endif
	}
    if (actual_nx != nx) {
      ssSetErrorStatus(S, "Error encountered in S-function MEX file: wrong size of x0 vector.");
      return;
    }
	{
		/*char str[100];*/
		int nx,nx2,nu,ny,nw,np,nrel,ncons,dae;
		GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);
		/* Allocate */ 
		ssGetPWork(S)[0] = calloc(sizeof(struct BasicIDymosimStruct)/sizeof(int), sizeof(int));
		setBasicStruct(ssGetRWork(S)+nx+ny+nw+2*nrel+nu+7,(int*)(ssGetPWork(S)[0]));
		getBasicIDymosimStruct()->mFindEvent=!ssIsVariableStepSolver(S) && ssGetSolverMaxOrder(S)<=1;
		/*sprintf(str,"Var %d, order %d, %s inline %d\n",ssIsVariableStepSolver(S),ssIsVariableStepSolver(S),
			ssGetSolverName(S),
			inlineIntegration_);
		DymosimMessage(str);*/
		if (getBasicIDymosimStruct()->mInlineIntegration==1 && getBasicDDymosimStruct()->mDymolaFixedStepSize<=0 && !getBasicIDymosimStruct()->mFindEvent) {
			ssSetErrorStatus(S, "Error encounted in Dymola block: inline integration requires fixed step size "
			"euler or discrete solver.");
			return;
		}
	}
    for (i = 0; i < nx; i++)
      x0[i] = arg1[i];

    NotInitialized = 1;
#if LogCalls
      DymosimMessage("mdlInitializeConditions done");
#endif
	
	/* To force initialization before first sample for HILS */
	/* (using mdlOutputs as a shortcut to simblock_ for initialization) */
	/* Works only with level 2 S-functions */
#if S_FUNCTION_LEVEL > 1
#if defined(RT)
	/* Execute three time steps before simulation loop to avoid massive initial overruns */
	mdlOutputs(S, 0);
	mdlUpdate(S, 0);
	timeToAdd = 0.001;
	mdlOutputs(S, 0);
	mdlUpdate(S, 0);
	timeToAdd = 0.002;
	mdlOutputs(S, 0);
	mdlUpdate(S, 0);
#endif
#endif
}

#define MDL_CHECK_PARAMETERS   
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
static void mdlCheckParameters(SimStruct *S)
{
#if !defined(ModelWithFMU)
	ParamChange=1;
	/* dymolaParametersNr_ will be set in mdlDerivatives to avoid problems
	   with undefined input signals if dsblock_ is called from mdlOutputs */
#endif
	
#if LogCalls
	DymosimMessage("mdlCheckParameters called");
#endif
}
#endif /* MDL_CHECK_PARAMETERS */

#if defined(MDL_RTW) && defined(MATLAB_MEX_FILE)
static void mdlRTW(SimStruct *S)
{
	real_T* duser;
	int_T dlen;
	real_T *params = mxGetPr(ssGetSFcnParam(S, 0));
    int_T  pLen   = mxGetNumberOfElements(ssGetSFcnParam(S, 0));
    real_T *x0 = mxGetPr(ssGetSFcnParam(S, 1));
    int_T  x0Len   = mxGetNumberOfElements(ssGetSFcnParam(S, 1));
	if (!ssWriteRTWParameters(S,2,
                              SSWRITE_VALUE_VECT,"params","",params,pLen,
                              SSWRITE_VALUE_VECT,"x0","",x0,x0Len)) {
        return; /* An error occurred which will be reported by Simulink */
    }
	/* Write RWork vector to model.rtw file */
	duser = ssGetRWork(S);
	dlen = ssGetNumRWork(S);
	if ( !ssWriteRTWParamSettings(S, 1, SSWRITE_VALUE_VECT, "RWork", duser, dlen) ) {
        return; /* An error occured, which will be reported by Simulink. */
    }
	/*printf("Running mdlRTW!\n"); */
}
#endif /* MDL_RTW */

/* Function: mdlOutputs =======================================================
 * Abstract:
 *
 * In this function, you compute the outputs of your S-function
 * block. The outputs are placed in the y variable.
 */

#if S_FUNCTION_LEVEL > 1
#define MDL_OUTPUTS
	static void mdlOutputs(SimStruct *S, int_T tid)
#elif defined(Matlab51)
  static void mdlOutputs(real_T *y_, const real_T *x_, const real_T *u_, 
                       SimStruct *S, int_T tid)
#else
  static void mdlOutputs(double *y_, double *x_, double *u_, SimStruct *S, int tid)
#endif
{
    double time, xd[1], *dp, *duser;
    int idemand, icall, ip[1], ierr;
    Dymola_bool lp[1];
    int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;
    int i;
	int evaluateIt=1;

    double *y, *x, *u;
#if LogCalls
		DymosimMessage("mdlOutputs start");
#endif

    GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);
#if S_FUNCTION_LEVEL > 1
	if (nx>0) x = (double*)ssGetContStates(S); else x=0;
	if (nu>0) u = (double*)ssGetInputPortRealSignal(S, 0); else u = 0;
	if (ny>0) y = (double*)ssGetOutputPortRealSignal(S, 0); else y = 0;
	if (np>0) dp = (double*)mxGetPr(ssGetSFcnParam(S,0)); else dp = 0;
#else
    y = (double *) y_;
    x = (double *) x_;
    u = (double *) u_;
	if (np>0) dp = (double *) mxGetPr(ssGetArg(S,0)); else dp = 0;
#endif

    time = ssGetT(S);

	duser = ssGetRWork(S);

#if LogCalls
      DymosimMessageDouble("mdlOutput: Time = ", time);
#endif

	if (!EventInUpdate && ssIsMajorTimeStep(S)) {
      idemand = 5;  /* Event or time event */

#if LogCalls
      DymosimMessage("mdlOutput - Possible Event");
#endif
      simblock_(S, &idemand, &icall, &time, x, xd, u, dp, ip, lp, 
               &duser[0], 
               &duser[nx], 
               &duser[nx+ny], 
               &duser[nx+ny+nw],
               &duser[nx+ny+nw+2*nrel],
               &ierr);
	  evaluateIt=0;
#if LogCalls
	  DymosimMessageInt("Major time step, event:",HaveEventIterated_);
#endif
#if defined(Matlab51)
      if (HaveEventIterated_) ssSetSolverNeedsReset(S);
#endif
    }
    
	if (ny > 0 || (EventInUpdate && ssIsMajorTimeStep(S))) {
#if LogCalls
	   DymosimMessage("mdlOutput: Actual outputs");
#endif
      if (1 || ! DirectFeedThrough)
		idemand = 5;      /* Calculate only outputs. AND EVENTS*/
      else 
        idemand = 2;      /* Calculate both output and derivatives. */

	  if (evaluateIt)
		  simblock_(S, &idemand, &icall, &time, x, xd, u, dp, ip, lp, 
               &duser[0], 
               &duser[nx], 
               &duser[nx+ny], 
               &duser[nx+ny+nw],
               &duser[nx+ny+nw+2*nrel],
               &ierr);

      for (i = 0; i < ny; i++)
        y[i] = duser[nx+i];
    }
#if LogCalls
      DymosimMessage("mdlOutput Done");
#endif
}


/* Function: mdlUpdate ========================================================
 * Abstract:
 *
 * This function is called once for every major integration time step.
 * Discrete states are typically updated here, but this function is useful
 * for performing any tasks that should only take place once per integration
 * step.
 */

#if S_FUNCTION_LEVEL > 1
#define MDL_UPDATE
   static void mdlUpdate(SimStruct *S, int_T tid)
#elif defined(Matlab51)
  static void mdlUpdate(real_T *x_, const real_T *u_, SimStruct *S, int_T tid)
#else
  static void mdlUpdate(double *x_, double *u_, SimStruct *S, int tid)
#endif
{
    double time, xd[1], *dp, *duser;
    int idemand, icall, ip[1], ierr;
    Dymola_bool lp[1];
    int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;

    double *x, *u;
#if LogCalls
		DymosimMessage("mdlUpdate start");
#endif
	return; /* Events handled during mdlOutputs */

    GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);
#if S_FUNCTION_LEVEL > 1
	if (nx>0) x = (double*)ssGetContStates(S); else x=0;
	if (nu>0) u = (double*)ssGetInputPortRealSignal(S, 0); else u = 0;
	if (np>0) dp = (double*)mxGetPr(ssGetSFcnParam(S,0)); else dp = 0;
#else
    x = (double *) x_;
    u = (double *) u_;
	if (np>0) dp = (double *) mxGetPr(ssGetArg(S,0)); else dp = 0;
#endif
    time = ssGetT(S);

    duser = ssGetRWork(S);
	if (EventInUpdate) {
      idemand = 5;  /* Event or time event */
      simblock_(S, &idemand, &icall, &time, x, xd, u, dp, ip, lp, 
               &duser[0], 
               &duser[nx], 
               &duser[nx+ny], 
               &duser[nx+ny+nw],
               &duser[nx+ny+nw+2*nrel],
               &ierr);
	  HaveEventIterated_=GetDymolaHaveEventIterated(0);
#if LogCalls
	  DymosimMessageInt("Update, event:",HaveEventIterated_);
#endif
#if defined(Matlab51)
      if (HaveEventIterated_) ssSetSolverNeedsReset(S);
#endif
	}

#if LogCalls
      DymosimMessageDouble("mdlUpdate: Time = ", time);
#endif
#if GenerateResultInNonDymosim
	  DeclarePhase7(&phase,time,10,dp,x,&duser[0],&duser[nx],u,&duser[nx+ny]);
#endif
}


/* Function: mdlDerivatives ===================================================
 * Abstract:
 *
 * In this function, you compute the S-function block's derivatives.
 * The derivatives are placed in the dx variable.
 */

#if S_FUNCTION_LEVEL > 1
#define MDL_DERIVATIVES
  static void mdlDerivatives(SimStruct *S)
#elif defined(Matlab51)
  static void mdlDerivatives(real_T *dx_, const real_T *x_, const real_T *u_, 
                           SimStruct *S, int_T tid)
#else
  static void mdlDerivatives(double *dx_, double *x_, double *u_, SimStruct *S, int tid)
#endif
{
    double time, xd[1], *dp, *duser;
    int idemand, icall, ip[1], ierr;
    Dymola_bool lp[1];
    int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;
    int i;

    double *dx, *x, *u;
#if LogCalls
		DymosimMessage("mdlDerivatives start");
#endif
    GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);
#if S_FUNCTION_LEVEL > 1
	if (nx>0) dx = (double*)ssGetdX(S); else dx = 0;
	if (nx>0) x = (double*)ssGetContStates(S); else x=0;
	if (nu>0) u = (double*)ssGetInputPortRealSignal(S, 0); else u = 0;
	if (np>0) dp = (double*)mxGetPr(ssGetSFcnParam(S,0)); else dp = 0;
#else
	dx = (double *) dx_;
    x = (double *) x_;
    u = (double *) u_;
	if (np>0) dp = (double *) mxGetPr(ssGetArg(S,0)); else dp = 0;
#endif

    time = ssGetT(S);

    duser = ssGetRWork(S);

#if LogCalls
    DymosimMessageDouble("mdlDerivatives: Time = ", time);
#endif
	if (ParamChange == 1) {
		ParamChange = 0;
		getBasicIDymosimStruct()->mParametersNr++;
	}

    if (nx > 0 /* && ! DirectFeedThrough*/) {
      idemand = 2;
	
      simblock_(S, &idemand, &icall, &time, x, xd, u, dp, ip, lp, 
               &duser[0], 
               &duser[nx], 
               &duser[nx+ny], 
               &duser[nx+ny+nw],
               &duser[nx+ny+nw+2*nrel],
               &ierr);

      for (i = 0; i < nx; i++)
        dx[i] = duser[i];
	}
}


/* Function: mdlTerminate =====================================================
 * Abstract:
 *
 * In this function, you should perform any actions that are necessary
 * at the termination of a simulation.  For example, if memory was allocated
 * in mdlInitializeConditions, this is the place to free it.
 */

#define MDL_TERMINATE
static void mdlTerminate(SimStruct *S)
{
	double time, xd[1], *dp, *duser;
    int idemand, icall, ip[1], ierr;
    Dymola_bool lp[1];
    int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;

	double *u, *x;

	if (NotInitialized)
		return;

#if !defined(DYMOLA_CRAMAS_TERMINATE)
    GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);

#if S_FUNCTION_LEVEL > 1
	if (nx>0) x = (double*)ssGetContStates(S); else x=0;
	if (nu>0) u = (double*)ssGetInputPortRealSignal(S, 0); else u = 0;
#else
    if (nx>0) x = (double *) ssGetX(S); else x = 0;
    if (nu>0) u = (double *) ssGetU(S); else u = 0;
#endif


    time = ssGetT(S);
    if (np>0) dp = (double *) mxGetPr(ssGetSFcnParam(S,0)); else dp = 0;
    duser = ssGetRWork(S);

	idemand=7;

	simblock_(S, &idemand, &icall, &time, x, xd, u, dp, ip, lp, 
               &duser[0], 
               &duser[nx], 
               &duser[nx+ny], 
               &duser[nx+ny+nw],
               &duser[nx+ny+nw+2*nrel],
               &ierr);
#endif

#if GenerateResultInNonDymosim
		  DeclarePhase9(&phase);
#endif
		  if (ssGetPWork(S)[0] != NULL) {
			  free(ssGetPWork(S)[0]);
		  }
}

#if defined(Matlab51)
/*#if defined(MATLAB_MEX_FILE) || defined(NRT) */
#define MDL_ZERO_CROSSINGS
  static void mdlZeroCrossings(SimStruct *S)
  {
    double time, xd[1], *dp, *duser;
    int idemand, icall, ip[1], ierr;
    Dymola_bool lp[1];
    int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;
    int i;

    double *u, *x, *zcSignals;
#if LogCalls
		DymosimMessage("mdlZeroCrossings start");
#endif
    GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);

#if S_FUNCTION_LEVEL > 1
    if (nu>0) u = (double *) ssGetInputPortRealSignal(S, 0); else u = 0;
	if (np>0) dp = (double*)mxGetPr(ssGetSFcnParam(S,0)); else dp = 0;
	if (nx>0) x = (double *) ssGetContStates(S); else x=0;
#else
	if (nu>0) u = (double*)ssGetU(S); else u=0;
	if (np>0) dp = (double *) mxGetPr(ssGetArg(S,0)); else dp = 0;
	if (nx>0) x = (double*)ssGetX(S); else x=0;
#endif

    zcSignals = (double *) ssGetNonsampledZCs(S);

    time = ssGetT(S);
    duser = ssGetRWork(S);

#if LogCalls
    DymosimMessageDouble("mdlZeroCrossings: Time = ", time);
#endif

    if (nrel > 0) {
      idemand = 4;

      simblock_(S, &idemand, &icall, &time, x, xd, u, dp, ip, lp, 
               &duser[0], 
               &duser[nx], 
               &duser[nx+ny], 
               &duser[nx+ny+nw],
               &duser[nx+ny+nw+2*nrel],
               &ierr);

      for (i = 0; i < 2*nrel; i++)
        zcSignals[i] = duser[nx+ny+nw+i];

    }
	zcSignals[2*nrel] = getBasicDDymosimStruct()->mNextTimeEvent - time;
#if LogCalls
	DymosimMessageDouble("  ZeroCrossing for time event: ", getBasicDDymosimStruct()->mNextTimeEvent - time);
#endif
  }
#endif


#if defined(Matlab51) && HAVE_GENERATED_JACOBIAN
#define MDL_JACOBIAN
static void mdlJacobian(SimStruct *S) {
	double*QJacobian_;
	double*QBJacobian_;
	double*QCJacobian_;
	double*QDJacobian_;


	double time, xd[1], *dp, *duser;
    int idemand, icall, ip[1], ierr;
    Dymola_bool lp[1];
    int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;
    int row,col;
	int n_row,n_col;
	double *u, *x;
#if LogCalls
		DymosimMessage("mdlJacobian start");
#endif

    GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);

#if S_FUNCTION_LEVEL > 1
	if (nu>0) u = (double*)ssGetInputPortRealSignal(S, 0); else u = 0;
	if (nx>0) x  = (double*)ssGetContStates(S); else x=0;
#else
	if (nu>0) u = (double*)ssGetU(S); else u=0;
	if (nx>0) x = (double*)ssGetX(S); else x=0;
#endif

    time = ssGetT(S);
    if (np>0) dp = mxGetPr(ssGetSFcnParam(S,0)); else dp = 0;
    duser = ssGetRWork(S);

	idemand=2;

	QJacobian_=duser+nu+nx+ny+nw+2*nrel+7+(sizeof(struct BasicDDymosimStruct)/sizeof(double));

	QBJacobian_=QJacobian_+nx*nx;
	QCJacobian_=QBJacobian_+nx*nu;
	QDJacobian_=QCJacobian_+nx*ny;
	SetDymolaJacobianPointers(0, QJacobian, QBJacobian_, QCJacobian_, QDJacobian_, nx, nu, ny, 0, 0, 0, 0);

#if LogCalls
	DymosimMessageDouble("mdlJacobian: Time = ", time);
#endif
	
	simblock_(S, &idemand, &icall, &time, x, xd, u, dp, ip, lp, 
               &duser[0], 
               &duser[nx], 
               &duser[nx+ny], 
               &duser[nx+ny+nw],
               &duser[nx+ny+nw+2*nrel],
               &ierr);
	n_row = nx+ny;
	n_col = nx+nu;

	{
		double*Pr=(double*)(ssGetJacobianPr(S));
		int*Ir=(int*)(ssGetJacobianIr(S));
		int*Jc=(int*)(ssGetJacobianJc(S));
		int acc=0;
		for(col=0;col<n_col;++col) {
			Jc[col]=acc;
			for(row=0;row<n_row;++row,++acc) {
				if (row<nx && col<nx) {
					/* A*/
					Pr[acc]=QJacobian_[row+col*nx];
				} else if (row<nx) {
					/* B */
					Pr[acc]=QBJacobian_[row+(col-nx)*nx];
				} else if (col<nx) {
					/* C */
					Pr[acc]=QCJacobian_[(row-nx)+col*ny];
				} else {
					/* D */
					Pr[acc]=QDJacobian_[(row-nx)+(col-nx)*ny];
				}
				Ir[acc]=row;
			}
		}
		Jc[n_col]=acc;
	}

	QJacobian_=(double*)0;
	QBJacobian_=(double*)0;
	QCJacobian_=(double*)0;
	QDJacobian_=(double*)0;
	SetDymolaJacobianPointers(0, QJacobian, QBJacobian_, QCJacobian_, QDJacobian_, nx, nu, ny, 0, 0, 0, 0);
#if LogCalls
		DymosimMessage("mdlJacobian done");
#endif

}
#endif

#if defined(Matlab51) && HAVE_GENERATED_JACOBIAN
#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
  /* Function: mdlStart =======================================================
   * Abstract:
   *    This function is called once at start of model execution. If you
   *    have states that should be initialized once, this is the place
   *    to do it.
   */
  static void mdlStart(SimStruct *S)
  {
     int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;
 
#if LogCalls
		DymosimMessage("mdlStart");
#endif
	{
		int*Ir=(int*)(ssGetJacobianIr(S));
		int*Jc=(int*)(ssGetJacobianJc(S));
		int acc=0;
		int row,col;
		int n_row,n_col;
		if (!Ir || !Jc) {
#if LogCalls
			DymosimMessage("mdlStart with no Jacobian");
#endif
			return;
		}
		GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);
		n_row = nx+ny;
		n_col = nx+nu;

		for(col=0;col<n_col;++col) {
			Jc[col]=acc;
			for(row=0;row<n_row;++row,++acc) {
				Ir[acc]=row;
			}
		}
		Jc[n_col]=acc;
	}

  }
#endif /*  MDL_START */
#endif


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
