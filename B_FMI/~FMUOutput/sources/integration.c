/* Implementation of integration.h */

#include "conf.h"
#include "util.h"
#include "integration.h"
#include "jac.h"
#include "result.h"

#include "fmiFunctions_fwd.h"

/* Sundials */
#include <cvode/cvode.h>
#include <cvode/cvode_dense.h>
#include <sundials/sundials_math.h>
#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
#include <cvode/cvode_superlumt.h>
#endif

/* for Dymola_abs */
#include "f2c.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>

/* ----------------- constants ----------------- */

#define RTOL_DEFAULT (1.0e-5)   /* scalar relative tolerance */

/* when testing with Modelica wrapper, the external step size may be large due to
   variable step size solvers being used externally */
#define MAX_STEPS 100000      /* maximum number if internal steps for a time step */
#define MAX_FAILURES 15       /* maximum number of error test failures permitted in attempting one step */
#define MAX_NON_LIN_ITERS 3   /* maximum number of non-linear iterations */

/* for Sundials */
/* the safety factor used in the nonlinear convergence test */
#define NON_LINEAR_CONV_TEST_COEFF 1e-1

/* ----------------- macros ----------------- */

#define CALL_SET(function, val)                               \
    flag = function(cvode_mem, val);                          \
	if (util_check_flag(&flag, #function, 1, comp)) goto fail \

#define CALL_SET2(function, val1, val2)                       \
    flag = function(cvode_mem, val1, val2);                   \
    if (util_check_flag(&flag, #function, 1, comp)) goto fail \

#define GET_STATISTIC(function, var)                          \
	flag = function(comp->iData->cvode_mem, &var);            \
	if (util_check_flag(&flag, #function, 1, comp)) {         \
	  var = -1;                                               \
	}

#define INT_RESULT_SAMPLE(atEvent)                            \
if (comp->storeResult == FMITrue) {                           \
		result_sample(comp, atEvent);                         \
}

/* ----------------- local function declarations ----------------- */

/* clones integration data */
static IntegrationStatus clone_data(Component* target, Component* source);

/* frees integration data */
static void free_data(Component* comp, Component* target);

/* root function used for event indicators */
static int g(realtype t, N_Vector y, realtype *gout, void *user_data);

/* step event check function */
static int check_step_event(void* user_data);

/* error message handler */
static void err_msg_handler(int error_code, const char *module,
							const char *function, char *msg,
							void *eh_data);

/* sets the weights for the weighted norm */
static int cvEwtSetVV(N_Vector y, N_Vector ewt, void *user_data);

#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
/* checks if sparse solver is to be used and returns number of nonzero elements */
static int EnableSparse(int nx);

/* computes fixed Jacobian structure data to be used when calculating numeric Jacobian using grouping */
static int PrepareSparse(Component *comp, SparseFixData *sparseData, int N, int nz);

/* return the number of cores to be used by the multithreaded sparse SuperLU */
static int getNumProcsCvode(int nx, int nnz, int bw);
#endif

/* ----------------- local variables ----------------- */

static size_t nGroups;

/* ----------------- external variables ----------------- */

extern int QJacobianCG_[];
extern int QJacobianGC_[];
extern const int global_sparse_enabled;

/* ----------------- external function declarations ----------------- */

extern void initializeData2(double* t);

/* ----------------- function definitions ----------------- */

/* ------------------------------------------------------ */
DYMOLA_STATIC IntegrationStatus integration_setup(FMIComponent c, FMIReal relTol)
{
	Component* comp = (Component*) c;
	realtype *abstol_data, *reltol_data;
	void *cvode_mem;
	int flag;
	size_t i;

	IntegrationData* iData;
	
	assert(comp->iData == NULL);
	assert(sizeof(realtype) == sizeof(FMIReal));

	if (comp->nStates == 0) {
		/* Add dummy state fo simplify code and avoid extra conditions for the vast majority of models.
		Note that concerned arrays already have 1 allocated element due to guarding offset 1 during instantiation. */
		comp->nStates = 1;
		comp->states[0] = 0;
		comp->statesNominal[0] = 1;
	}

	if (relTol <= 0) {
		relTol = RTOL_DEFAULT;
	}
#ifdef FMI_2
	comp->iData = (IntegrationData*) comp->functions->allocateMemory(1, sizeof(IntegrationData));
#else
	comp->iData = (IntegrationData*) comp->functions.allocateMemory(1, sizeof(IntegrationData));
#endif
	if (comp->iData == NULL) goto fail;

	iData = comp->iData;

	iData->y = iData->abstol = iData->reltol = iData->ewt = iData->tmp1 = iData->tmp2 = NULL;
	iData->sparseData.nnz = iData->sparseData.nGroups = 0;
	iData->sparseData.colPtrs = iData->sparseData.index = NULL;
	iData->cvode_mem = NULL;

	/* create serial vector from states */
	assert(comp->nStates > 0);
	/* it turns out using N_VNew_Serial(comp->nStates) gives worse accuracy for some reason */
	iData->y = N_VMake_Serial((long)comp->nStates, comp->states);
	if (util_check_flag((void *)(iData->y), "N_VMake_Serial", 0, comp)) goto fail;

	/* Backward Differentiation Formula and the use of a Newton iteration */
	cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);
	if (util_check_flag((void *)cvode_mem, "CVodeCreate", 0, comp)) goto fail;

	/* initialize the integrator memory and specify the
	   user's right hand side function in y'=f(t,y), the inital time and
	   the initial dependent variable vector y */
	flag = CVodeInit(cvode_mem, jac_f, comp->time, iData->y);
	if (util_check_flag(&flag, "CVodeInit", 1, comp)) goto fail;

	/* need to provide the context from FMI */
	CALL_SET(CVodeSetUserData, comp);

	/* specify the relative and absolute tolerances */
	iData->abstol = N_VNew_Serial((long)comp->nStates);
	if (util_check_flag((void *)(iData->abstol), "N_VNew_Serial", 0, comp)) goto fail;
	iData->reltol = N_VNew_Serial((long)comp->nStates);
	if (util_check_flag((void *)(iData->reltol), "N_VNew_Serial", 0, comp)) goto fail;
	abstol_data = N_VGetArrayPointer(iData->abstol);
	reltol_data = N_VGetArrayPointer(iData->reltol);
	for (i = 0; i < comp->nStates; i++) {
		realtype nom = comp->statesNominal[i];
		if (nom >= 0) {
			abstol_data[i] = relTol * nom;
			reltol_data[i] = relTol;
		} else {
			abstol_data[i] = relTol * (-nom);
			reltol_data[i] = 0.0;
		}
	}
	CALL_SET(CVodeWFtolerances, cvEwtSetVV);

	/* specify the safety factor used in the nonlinear convergence test */
	CALL_SET(CVodeSetNonlinConvCoef, NON_LINEAR_CONV_TEST_COEFF);

	/* specify the root function to handle event indicators */
	CALL_SET2(CVodeRootInit, (long)comp->nCross, g);

	/* specify step event detection function */
	CALL_SET(CVodeStepRootInit, check_step_event);

	nGroups = (size_t) QJacobianCG_[0];
	jac_setup(nGroups);

	{
#if defined(FMU_SOURCE_CODE_EXPORT) && !defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
		if (0) {
#else
		/* Check if SuperLU sparse solver is to be used and compute number non-zero elements */
		const int nz = EnableSparse((int)comp->nStates);
		if (nz)	{
			
			/* Compute Jacobian structure data to be used for sparse Jacobian evaluation */
			int band_width = PrepareSparse(comp, &(iData->sparseData), (int) comp->nStates, nz);
			int nprocs = getNumProcsCvode((int) comp->nStates, nz, band_width);
			if (nprocs <= 0) nprocs = 4;

			util_logger(comp, comp->instanceName, FMIOK, "",
				"Using SuperLU sparse solver on %d core%s.", nprocs, (nprocs > 1 ? "s" : ""));

			/* Use the SuperLU multithreaded linear solver */
			flag = CVSuperLUMT(cvode_mem, nprocs, (int) comp->nStates, nz);
			if (util_check_flag(&flag, "CVSuperLUMT", 1, comp)) goto fail;

			/* use own Jacobian function to enable use of grouping */
			CALL_SET(CVSlsSetSparseJacFn, jac_JacobianSparse);
#endif /* FMU_SOURCE_CODE_EXPORT */
		} else {

			comp->iData->sparseData.nnz = 0;

			/* use the CVDENSE dense linear solver */
			CALL_SET(CVDense, (int)comp->nStates);

			/* use own Jacobian function to enable use of grouping */
			CALL_SET(CVDlsSetDenseJacFn, jac_Jacobian);
		}
	}

	/* set maximum number of internal steps for a time step */
	CALL_SET(CVodeSetMaxNumSteps, MAX_STEPS);

	/* set maximum no. of nonlinear iterations */
	CALL_SET(CVodeSetMaxNonlinIters, MAX_NON_LIN_ITERS);

	/* set maximum number of error test failures permitted in attempting one step */
	CALL_SET(CVodeSetMaxErrTestFails, MAX_FAILURES);

	iData->tmp1 = N_VNew_Serial((long)comp->nStates);
	iData->tmp2 = N_VNew_Serial((long)comp->nStates);
	if (util_check_flag((void *)(iData->tmp1), "N_VNew_Serial", 0, comp) ||
		util_check_flag((void *)(iData->tmp2), "N_VNew_Serial", 0, comp)) {
			goto fail;
	}
	N_VConst(0.0,iData->tmp1);
	N_VConst(0.0,iData->tmp2);
	iData->cvode_mem = cvode_mem;
	iData->ewt = N_VNew_Serial((long)comp->nStates);
	if (util_check_flag((void *)(iData->ewt), "N_VNew_Serial", 0, comp)) goto fail;
	N_VConst(0.0,iData->ewt);
	CALL_SET2(CVodeSetErrHandlerFn, err_msg_handler, comp);

#ifdef FMU_VERBOSITY
	if (nGroups > 0) {
		util_logger(c, comp->instanceName, FMIOK, "",
			"grouping will be used when computing J (N = %d)", comp->nStates);
	} else {
		util_logger(c, comp->instanceName, FMIOK, "",
			"grouping will not be used when computing J (N = %d)", comp->nStates);
	}
#endif

	/*  turned out to be faster to set to 0 */
	comp->istruct->mSolverHandleEq = 0;

	/* initialize input derivatives handling */
	iData->inputDerivatives = iData->inputsT0 = NULL;
#ifdef FMI_2
	iData->inputDerivatives = (FMIReal*) comp->functions->allocateMemory(comp->nIn + 1, sizeof(FMIReal));
	iData->inputsT0 = (FMIReal*) comp->functions->allocateMemory(comp->nIn + 1, sizeof(FMIReal));
#else
	iData->inputDerivatives = (FMIReal*) comp->functions.allocateMemory(comp->nIn + 1, sizeof(FMIReal));
	iData->inputsT0 = (FMIReal*) comp->functions.allocateMemory(comp->nIn + 1, sizeof(FMIReal));
#endif

	/* initialize output derivatives handling */
	iData->outputsPrev = NULL;
#ifdef FMI_2
	iData->outputsPrev = (FMIReal*) comp->functions->allocateMemory(comp->nOut + 1, sizeof(FMIReal));
#else
	iData->outputsPrev = (FMIReal*) comp->functions.allocateMemory(comp->nOut + 1, sizeof(FMIReal));
#endif

	if (iData->inputDerivatives == NULL || iData->inputsT0 == NULL || iData->outputsPrev == NULL) {
			goto fail;
	}
	iData->useDerivatives = 0;

	/* initialize statistics */
	iData->stat.fCalls = 0;
	iData->stat.totTime = (float) clock();


	iData->stat.rejSteps = 0;
	iData->stat.rejIntSteps = 0;
	iData->stat.rejFCalls = 0;
	iData->stat.rejJacCalls = 0;

#ifdef SAVE_STATE_SUNDIALS
	iData->cvode_called = 0;
#endif

	return integrationOK;

fail:
	integration_teardown(comp);
	return integrationError;
}

/* ------------------------------------------------------ */
DYMOLA_STATIC void integration_teardown(FMIComponent c)
{
	Component* comp = (Component*) c;
	if (comp == NULL || comp->iData == NULL) {
		return;
	}

#ifdef LOG_STATISTICS
	/* log statistics */
	if (comp->iData->cvode_mem != NULL) {
		realtype tolsfac = 0;
		int flag = 0;
		IntegrationData* iData = comp->iData;
		Statistics* stat = &(comp->iData->stat);

		stat->totTime = clock() - stat->totTime;
		stat->totTime /= CLOCKS_PER_SEC;

		updateIntegrationStatistics(comp,&comp->iData->stat);
		GET_STATISTIC(CVodeGetTolScaleFactor, tolsfac);

		util_logger(comp, comp->instanceName, FMIOK, "",
			"Sundials CVode Statistics\n"
			"    Stop time                                : %.2f s\n"
			"    Simulation time                          : %.2f s\n"
			"    Number of external steps                 : %d\n"
			"    Number of internal steps                 : %d\n"
			"    Number of non-linear iterations          : %ld\n"
			"    Number of non-linear convergence failures: %ld\n"
			"    Number of f function evaluations         : %ld\n"
			"    Number of g function evaluations         : %ld\n"
			"    Number of Jacobian-evaluations (direct)  : %ld\n"
			"    Suggested tolerance scale factor         : %.1f\n"
			"    Grouping used                            : %s\n",
			comp->time, stat->totTime, stat->steps, stat->intSteps, stat->niters, stat->ncfails, 
			stat->fCalls, stat->ngevals, stat->njevals, tolsfac,	nGroups > 0 ? "yes" : "no");
#ifdef FMI_2
		util_logger(comp, comp->instanceName, FMIOK, "",
			"Rejected count\n"
			"    Number of external steps                 : %d\n"
			"    Number of internal steps                 : %d\n"
			"    Number of f function evaluations         : %d (%.2f s)\n"
			"    Number of Jac function evaluations       : %d\n",
			stat->rejSteps, stat->rejIntSteps,
			stat->rejFCalls, stat->rejJacCalls);
#endif
	}
#endif /* LOG_STATISTICS */

	free_data(comp, comp);
}

#ifdef SAVE_STATE_SUNDIALS
#include "cvode_impl.h"
#endif

/* ------------------------------------------------------ */
DYMOLA_STATIC IntegrationStatus integration_step(Component* comp, FMIReal tout)
{
	IntegrationData* iData = comp->iData;
	void* cvode_mem = iData->cvode_mem;
	
	/* initialize in case tret needs to be reported before set by Sundials */
	realtype tret = comp->time;

	int done = 0;

	assert(comp->nStates > 0);
	assert(tout > comp->time);

	while (!done) {
		int flag;

		/* store previous outputs for use in fmiGetRealOutputDerivatives */
		if (!util_refresh_cache(comp, iDemandOutput, "fetching current output", NULL)) {
			memcpy(iData->outputsPrev, comp->outputs, comp->nOut * sizeof(FMIReal));
			iData->timePrev = comp->time;
		}

		flag = CVode(cvode_mem, tout, iData->y, &tret, CV_NORMAL);
#ifdef SAVE_STATE_SUNDIALS
		iData->cvode_called = 1;
#endif
		switch (flag) {

		   case CV_SUCCESS:
			   done = 1;
			   break;

		   case CV_TOO_CLOSE:
			   /* Sundials simply gives up on finding initial step size if the next step after a restart is too small.
			   *  Must explicitly set initial step size as a workaround. */
			   {
				   realtype hcur;

				   flag = CVodeGetCurrentStep(cvode_mem, &hcur);
				   if (util_check_flag(&flag, "CVodeGetCurrentStep", 1, comp)) {
					   goto fail;
				   }
				   if (hcur == 0) {
					   /* next step size not yet computed */ 
					   /* somewhat arbitrary value but should never happen on sane usage */ 
					   hcur = 2 * UNIT_ROUNDOFF * (1 + SUNMAX(SUNRabs(tout), SUNRabs(comp->time)));
				   }
				   util_logger(comp, comp->instanceName, FMIOK, "",
					   "Internal step too small at t = %f, setting initial step size explicitly to %.16e", comp->time, hcur);
				   CALL_SET(CVodeSetInitStep, hcur);
			   }
			   break;

		   case CV_ROOT_RETURN:
			   {
				   /* state or step event occurred */
				   FMIStatus status;
#ifdef FMI_2
				   FMIBoolean terminateSimulation;
#else
				   FMIEventInfo eventInfo;

#endif
				   iData->useDerivatives = 0;

				   fmiSetTime_(comp, tret);
#ifdef LOG_EVENTS
				   if (comp->istruct->mTriggerStepEvent != 0) {
					   util_logger(comp, comp->instanceName, FMIOK, "", "%.12f: step event", comp->time);
				   } else {
					   util_logger(comp, comp->instanceName, FMIOK, "",
						   "%.12f: state event", tret);
				   }
#endif
				   INT_RESULT_SAMPLE(FMITrue);
				   status = util_event_update(comp, FMIFalse, 
#ifdef FMI_2					   
					   &terminateSimulation
#else					   
					   &eventInfo
#endif					  
					   );
				   if (status != FMIOK) {
					   goto fail;
				   }
				   INT_RESULT_SAMPLE(FMITrue);

#ifdef FMI_2
				   if (terminateSimulation == FMITrue) {
#else
				   if (eventInfo.terminateSimulation == FMITrue) {
#endif
					   return integrationTerminate;
				   }

				   if (integration_reinit(comp,1) != integrationOK) {
					   goto fail;
				   }
			   }
			   break;

		   default:
				util_check_flag(&flag, "CVode", 1, comp);
				goto fail;
		}
	}

	/* check if we are reasonably close to requested stop time */
	if (fabs(tret) - fabs(tout) > SMALL_TIME_DEV(comp->time)) {
		util_logger(comp, comp->instanceName, FMIError, "",
			"Internal step error: tret = %.16e  !=  tout = %.16e", tret, tout);
		goto fail;
	}

	iData->stat.steps++;
	return integrationOK;

fail:
	return integrationError;
}
#ifdef FMI_2
DYMOLA_STATIC IntegrationStatus integration_step_return_at_event(Component* comp, FMIReal tout, FMIReal* tRet)
{
	IntegrationData* iData = comp->iData;
	void* cvode_mem = iData->cvode_mem;
	
	/* initialize in case tret needs to be reported before set by Sundials */
	realtype tret = comp->time;

	int done = 0;

	assert(comp->nStates > 0);
	assert(tout > comp->time);

	while (!done) {
		int flag;

		/* store previous outputs for use in fmiGetRealOutputDerivatives */
		if (!util_refresh_cache(comp, iDemandOutput, "fetching current output", NULL)) {
			memcpy(iData->outputsPrev, comp->outputs, comp->nOut * sizeof(FMIReal));
			iData->timePrev = comp->time;
		}

		flag = CVode(cvode_mem, tout, iData->y, &tret, CV_NORMAL);
#ifdef SAVE_STATE_SUNDIALS
		iData->cvode_called = 1;
#endif
		switch (flag) {

		   case CV_SUCCESS:
			   done = 1;
			   break;

		   case CV_TOO_CLOSE:
			   /* Sundials simply gives up on finding initial step size if the next step after a restart is too small.
			   *  Must explicitly set initial step size as a workaround. */
			   {
				   realtype hcur;

				   flag = CVodeGetCurrentStep(cvode_mem, &hcur);
				   if (util_check_flag(&flag, "CVodeGetCurrentStep", 1, comp)) {
					   goto fail;
				   }
				   if (hcur == 0) {
					   /* next step size not yet computed */ 
					   /* somewhat arbitrary value but should never happen on sane usage */ 
					   hcur = 2 * UNIT_ROUNDOFF * (1 + SUNMAX(SUNRabs(tout), SUNRabs(comp->time)));
				   }
				   util_logger(comp, comp->instanceName, FMIOK, "",
					   "Internal step too small at t = %f, setting initial step size explicitly to %.16e", comp->time, hcur);
				   CALL_SET(CVodeSetInitStep, hcur);
			   }
			   break;

		   case CV_ROOT_RETURN:
			   {
				   /* state or step event occurred */

				   iData->useDerivatives = 0;

				   fmiSetTime_(comp, tret);
				   *tRet = (FMIReal) tret;
#ifdef LOG_EVENTS
				   if (comp->istruct->mTriggerStepEvent != 0) {
					   util_logger(comp, comp->instanceName, FMIOK, "", "%.12f: step event", comp->time);
				   } else {
					   util_logger(comp, comp->instanceName, FMIOK, "",
						   "%.12f: state event", tret);
				   }
#endif
				   INT_RESULT_SAMPLE(FMITrue);
				   return integrationEvent;
			   }
			   break;

		   default:
				util_check_flag(&flag, "CVode", 1, comp);
				goto fail;
		}
	}

	/* check if we are reasonably close to requested stop time */
	if (fabs(tret) - fabs(tout) > SMALL_TIME_DEV(comp->time)) {
		util_logger(comp, comp->instanceName, FMIError, "",
			"Internal step error: tret = %.16e  !=  tout = %.16e", tret, tout);
		goto fail;
	}
	*tRet = (FMIReal) tret;
	iData->stat.steps++;
	return integrationOK;

fail:
	*tRet = (FMIReal) tret;
	return integrationError;
}
#endif


DYMOLA_STATIC void updateIntegrationStatistics(Component* comp, Statistics* stat){

	long nniters, nncfails, ngevals, njevals, nfevals, nsteps;
	int flag;
	GET_STATISTIC(CVodeGetNumRhsEvals, nfevals);
	stat->fCalls += nfevals;
	GET_STATISTIC(CVodeGetNumNonlinSolvIters, nniters);
	stat->niters += nniters;
	GET_STATISTIC(CVodeGetNumNonlinSolvConvFails, nncfails);
	stat->ncfails += nncfails;
	GET_STATISTIC(CVodeGetNumGEvals, ngevals);
	stat->ngevals += ngevals;

#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
	if (comp->iData->sparseData.nnz) {
		GET_STATISTIC(CVSlsGetNumJacEvals, njevals);
		stat->njevals += njevals;
	} else 
#endif /* FMU_SOURCE_CODE_EXPORT */
		{
		GET_STATISTIC(CVDlsGetNumJacEvals, njevals);
		stat->njevals += njevals;
	}
	
	GET_STATISTIC(CVodeGetNumSteps, nsteps);
	stat->intSteps += nsteps;
}

/* ------------------------------------------------------ */
DYMOLA_STATIC IntegrationStatus integration_reinit(Component* comp, int updateStatistics)
{
	int flag;

	assert(comp->nStates > 0);
  
	if (updateStatistics) {
		updateIntegrationStatistics(comp, &comp->iData->stat);
	}

	flag = CVodeReInit(comp->iData->cvode_mem, comp->time, comp->iData->y);

#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
	if (comp->iData->sparseData.nnz)
		CVodeReInitSuperLUMT(comp->iData->cvode_mem);
#endif

	if (util_check_flag(&flag, "CVodeReInit", 1, comp)) return integrationError;

	return integrationOK;
}

/* ------------------------------------------------------ */
DYMOLA_STATIC void integration_sync_extrapolation_input(Component* comp, size_t ix)
{
	if (comp->iData != NULL && comp->iData->inputsT0 != NULL) {
		comp->iData->inputsT0[ix] = comp->inputs[ix];
	}
}

/* ------------------------------------------------------ */
DYMOLA_STATIC void integration_extrapolate_inputs(Component* comp, double t)
{
	if (comp->iData->useDerivatives) {
		IntegrationData* iData = comp->iData;
		size_t i;
		double dt = (t - iData->derivativeTime);
		for (i = 0; i < comp->nIn; i++) {
			comp->inputs[i] = iData->inputsT0[i] + iData->inputDerivatives[i] * dt;
		}
	}
}

#ifdef FMI_2
/* ------------------------------------------------------ */
DYMOLA_STATIC FMIStatus integration_get_state(Component* source, Component* target)
{
	if (source->nStates > 0) {
		if (source->iData != NULL) {
			/* possible to reuse iData allocation from target since no sizes of sub parts can have changed */
			Statistics stat = source->iData->stat;
			if (clone_data(target, source) != integrationOK) {
				goto mem_fail;
			}
			updateIntegrationStatistics(source,&stat);
			target->iData->stat = stat;
		} else if (target->iData != NULL) {
			/* free old iData to avoid memory leak */
			free_data(source, target);
		}
	}
	
	return FMIOK;

mem_fail:
	util_logger(source, source->instanceName, FMIError, "", "memory allocation failed");
	free_data(source, target);
	return util_error(source);
}

/* ------------------------------------------------------ */
DYMOLA_STATIC FMIStatus integration_set_state(Component* source, Component* target)
{
	if (target->nStates > 0) {
		if (source->iData != NULL) {
			/* possible to reuse iData allocation from comp since no sizes of sub parts can have changed */
			if (target->iData == NULL) {
				target->iData = (IntegrationData*) target->functions->allocateMemory(1, sizeof(IntegrationData));
				if (target->iData == NULL) goto mem_fail;
			}

			if (clone_data(target, source) != integrationOK) {
				goto mem_fail;
			}

			/* count of rejected steps before copying statistics */
			source->iData->stat.rejSteps += target->iData->stat.steps - source->iData->stat.steps;
			source->iData->stat.rejIntSteps += target->iData->stat.intSteps - source->iData->stat.intSteps;
			source->iData->stat.rejFCalls += target->iData->stat.fCalls - source->iData->stat.fCalls;

			memcpy(&target->iData->stat, &source->iData->stat, sizeof(Statistics));

#ifdef SAVE_STATE_SUNDIALS
			integration_reinit(target,1);
			/* code fetched from CVAckpntGet and modified */
			{
				CVodeMem cv_mem = (CVodeMem)target->iData->cvode_mem;
				CVodeCheckPointData* ck_mem = &target->iData->ck_mem;
				N_Vector* cv_zn = cv_mem->cv_zn;
				N_Vector* ck_zn = ck_mem->ck_zn;
				int q = cv_mem->cv_q;
				int qmax = cv_mem->cv_qmax;
				int j;

				/* Copy parameters from check point data structure */
				cv_mem->cv_nst       = ck_mem->ck_nst;
				cv_mem->cv_tretlast  = ck_mem->ck_tretlast;
				cv_mem->cv_q         = ck_mem->ck_q;
				cv_mem->cv_qprime    = ck_mem->ck_qprime;
				cv_mem->cv_qwait     = ck_mem->ck_qwait;
				cv_mem->cv_L         = ck_mem->ck_L;
				cv_mem->cv_gammap    = ck_mem->ck_gammap;
				cv_mem->cv_h         = ck_mem->ck_h;
				cv_mem->cv_hprime    = ck_mem->ck_hprime;
				cv_mem->cv_hscale    = ck_mem->ck_hscale;
				cv_mem->cv_eta       = ck_mem->ck_eta;
				cv_mem->cv_etamax    = ck_mem->ck_etamax;
				cv_mem->cv_saved_tq5 = ck_mem->ck_saved_tq5;

				/* Copy the arrays from check point data structure */
				for (j=0; j<=q; j++) N_VScale(1.0, ck_zn[j], cv_zn[j]);
				if ( q < qmax ) N_VScale(1.0, ck_zn[qmax], cv_zn[qmax]);

				for (j=0; j<=L_MAX; j++)     cv_mem->cv_tau[j] = ck_mem->ck_tau[j];
				for (j=0; j<=NUM_TESTS; j++) cv_mem->cv_tq[j] = ck_mem->ck_tq[j];
				for (j=0; j<=q; j++)         cv_mem->cv_l[j] = ck_mem->ck_l[j];
			}
#endif
		} else if (target->iData == NULL) {
			/* need to setup integration data from scratch */
			integration_setup(target, source->relativeTolerance);
		}
	}

/* for explicit saving of Sundials states, we already re-initialized _before_ restoring */
#ifndef SAVE_STATE_SUNDIALS
	integration_reinit(target,0);
#endif
	return FMIOK;

mem_fail:
	util_logger(target, target->instanceName, FMIError, "", "memory allocation failed");
	return util_error(source);
}

/* ------------------------------------------------------ */
DYMOLA_STATIC void integration_free_state(Component* comp, Component* target)
{
	if (target->nStates > 0) {
#ifdef SAVE_STATE_SUNDIALS
		/* free cloned Sundials internal data */
		CVodeCheckPointData* ck_mem = &target->iData->ck_mem;
		N_Vector* ck_zn = ck_mem->ck_zn;

		int q = ck_mem->ck_q;
		int j;

		for (j = 0; j < q; j++) {
			N_VDestroy(ck_zn[j]);
		}

		if (q < ck_mem->ck_qmax) {
			N_VDestroy(ck_zn[ck_mem->ck_qmax]);
		}
#endif
		free_data(comp, target);
	}
}

#endif /* FMI_2 */

/* ----------------- local function definitions ----------------- */

static IntegrationStatus clone_data(Component* target, Component* source)
{
	IntegrationData* iData;

	assert(target->nStates > 0);
	assert(source->nStates > 0);
	assert(source->iData != NULL);

	iData = target->iData;
	if (iData == NULL) {
#ifdef FMI_2
		target->iData = (IntegrationData*) source->functions->allocateMemory(1, sizeof(IntegrationData));
#else
		target->iData = (IntegrationData*) source->functions.allocateMemory(1, sizeof(IntegrationData));
#endif
		if (target->iData == NULL) {
			return integrationError;
		}
		iData = target->iData;
		iData->y = N_VClone(source->iData->y);
		iData->abstol = N_VClone(source->iData->abstol);
		iData->reltol = N_VClone(source->iData->reltol);
		iData->ewt = N_VClone(source->iData->ewt);
		iData->tmp1 = N_VClone(source->iData->tmp1);
		iData->tmp2 = N_VClone(source->iData->tmp2);

		if (source->iData->sparseData.nnz) {
#ifdef FMI_2
			iData->sparseData.colPtrs = (int *) source->functions->allocateMemory(source->nStates+1, sizeof(int));
			iData->sparseData.index = (int *) source->functions->allocateMemory(source->nStates * source->iData->sparseData.nGroups, sizeof(int));
#else
			iData->sparseData.colPtrs = (int *) source->functions.allocateMemory(source->nStates+1, sizeof(int));
			iData->sparseData.index = (int *) source->functions.allocateMemory(source->nStates * source->iData->sparseData.nGroups, sizeof(int));
#endif
		} else {
			iData->sparseData.colPtrs = NULL;
			iData->sparseData.index = NULL;
		}

		iData->inputDerivatives = target->iData->inputsT0 = target->iData->outputsPrev = NULL;
		target->iData = iData;
	}

	/* don't use N_V_COPY since it also copies ops member */
	N_VScale(1.0, source->iData->abstol, iData->abstol);
	N_VScale(1.0, source->iData->reltol, iData->reltol);
	N_VScale(1.0, source->iData->ewt, iData->ewt);
	N_VScale(1.0, source->iData->tmp1, iData->tmp1);
	N_VScale(1.0, source->iData->tmp2, iData->tmp2);
	
	iData->sparseData.nnz = source->iData->sparseData.nnz;
	iData->sparseData.nGroups = source->iData->sparseData.nGroups;
	if (source->iData->sparseData.nnz) {
		size_t i;
		for (i = 0; i < source->nStates+1; ++i)
			iData->sparseData.colPtrs[i] = source->iData->sparseData.colPtrs[i];
		for (i = 0; i < source->nStates * source->iData->sparseData.nGroups; ++i)
			iData->sparseData.index[i] = source->iData->sparseData.index[i];
	}

	/* handle input derivative data */
	iData->useDerivatives = source->iData->useDerivatives;
	if (iData->useDerivatives) {
		size_t nu = source->nIn;

		assert(source->iData->inputDerivatives != NULL);
		assert(nu > 0);
		if (iData->inputDerivatives == NULL) {
			assert(iData->inputsT0 == NULL);
			/* add extra array element also here for consistency although we know here that nu > 0 */
#ifdef FMI_2
			iData->inputDerivatives = (FMIReal*) source->functions->allocateMemory(nu + 1, sizeof(FMIReal));
			iData->inputsT0 = (FMIReal*) source->functions->allocateMemory(nu + 1, sizeof(FMIReal));
#else
			iData->inputDerivatives = (FMIReal*) source->functions.allocateMemory(nu + 1, sizeof(FMIReal));
			iData->inputsT0 = (FMIReal*) source->functions.allocateMemory(nu + 1, sizeof(FMIReal));
#endif
			if (iData->inputDerivatives == NULL || iData->inputsT0 == NULL) {
				goto mem_fail;
			}
		}
		memcpy(iData->inputDerivatives, source->iData->inputDerivatives, nu * sizeof(FMIReal));
		memcpy(iData->inputsT0, source->iData->inputsT0, nu * sizeof(FMIReal));

		iData->derivativeTime = source->iData->derivativeTime;
	}

	/* handle ouput derivative data */
	{
		size_t ny = source->nOut;

		assert(source->iData->outputsPrev != NULL);
		if (iData->outputsPrev == NULL) {
			/* add extra array element also here for consistency although we know here that nu > 0 */
#ifdef FMI_2
			iData->outputsPrev = (FMIReal*) source->functions->allocateMemory(ny + 1, sizeof(FMIReal));
#else
			iData->outputsPrev = (FMIReal*) source->functions.allocateMemory(ny + 1, sizeof(FMIReal));
#endif
			if (iData->outputsPrev == NULL) {
				goto mem_fail;
			}
		}
		memcpy(iData->outputsPrev, source->iData->outputsPrev, ny * sizeof(FMIReal));
		iData->timePrev = source->iData->timePrev;
	}

#ifdef SAVE_STATE_SUNDIALS
	/* code fetched from CVAckpntNew and modified */
	if (iData->cvode_called)
	{
		CVodeMem cv_mem = (CVodeMem)iData->cvode_mem;
		CVodeCheckPointData* ck_mem = &iData->ck_mem;
		N_Vector* cv_zn = cv_mem->cv_zn;
		N_Vector* ck_zn = ck_mem->ck_zn;
		int q = cv_mem->cv_q;
		int qmax = cv_mem->cv_qmax;
		int j;

		if (!target->allocDone) {
			/* Test if we need to allocate space for the last zn.
			* NOTE: zn(qmax) may be needed for a hot restart, if an order
			* increase is deemed necessary at the first step after a check point */
			for (j=0; j<=q; j++) {
				ck_zn[j] = N_VClone(cv_mem->cv_tempv);
				if (ck_zn[j] == NULL) {
					int jj;
					for (jj=0; jj<j; jj++) N_VDestroy(ck_zn[jj]);
					goto mem_fail;
				}
			}

			if (q < qmax) {
				ck_zn[qmax] = N_VClone(cv_mem->cv_tempv);
				if (ck_zn[qmax] == NULL) {
					int jj;
					for (jj=0; jj<=q; jj++) N_VDestroy(ck_zn[jj]);
					goto mem_fail;
				}
			}
		}

		/* Load check point data from cv_mem */

		for (j=0; j<=q; j++) N_VScale(1.0, cv_zn[j], ck_zn[j]);
		if ( q < qmax ) N_VScale(1.0, cv_zn[qmax], ck_zn[qmax]);

		/* TODO: try memcpy */
		for (j=0; j<=L_MAX; j++)     ck_mem->ck_tau[j] = cv_mem->cv_tau[j];
		for (j=0; j<=NUM_TESTS; j++) ck_mem->ck_tq[j] = cv_mem->cv_tq[j];
		for (j=0; j<=q; j++)         ck_mem->ck_l[j] = cv_mem->cv_l[j];

		ck_mem->ck_nst       = cv_mem->cv_nst;
		ck_mem->ck_tretlast  = cv_mem->cv_tretlast;
		ck_mem->ck_q         = cv_mem->cv_q;
		ck_mem->ck_qmax         = cv_mem->cv_qmax;
		ck_mem->ck_qprime    = cv_mem->cv_qprime;
		ck_mem->ck_qwait     = cv_mem->cv_qwait;
		ck_mem->ck_L         = cv_mem->cv_L;
		ck_mem->ck_gammap    = cv_mem->cv_gammap;
		ck_mem->ck_h         = cv_mem->cv_h;
		ck_mem->ck_hprime    = cv_mem->cv_hprime;
		ck_mem->ck_hscale    = cv_mem->cv_hscale;
		ck_mem->ck_eta       = cv_mem->cv_eta;
		ck_mem->ck_etamax    = cv_mem->cv_etamax;
		ck_mem->ck_saved_tq5 = cv_mem->cv_saved_tq5;
	}
	/* End of: code fetched from CVAckpntNew and modified */
#endif

	return integrationOK;

mem_fail:
	util_logger(source, source->instanceName, FMIError, "", "memory allocation failed");
#ifdef FMI_2
	source->functions->freeMemory(iData->outputsPrev);
	source->functions->freeMemory(iData->inputDerivatives);
	source->functions->freeMemory(iData->inputsT0);
	source->functions->freeMemory(iData);
#else
	source->functions.freeMemory(iData->outputsPrev);
	source->functions.freeMemory(iData->inputDerivatives);
	source->functions.freeMemory(iData->inputsT0);
	source->functions.freeMemory(iData);
#endif
	return integrationError;
}

/* ------------------------------------------------------ */
static void free_data(Component* comp, Component* target)
{
	IntegrationData* iData;

	if (target == NULL || target->iData == NULL) {
		return;
	}
	iData = target->iData;

	CVodeFree(&iData->cvode_mem);

	if (iData->y != NULL)      N_VDestroy_Serial(target->iData->y);
	if (iData->abstol != NULL) N_VDestroy_Serial(target->iData->abstol);
	if (iData->reltol != NULL) N_VDestroy_Serial(target->iData->reltol);
	if (iData->ewt != NULL)    N_VDestroy_Serial(target->iData->ewt);
	if (iData->tmp1 != NULL)   N_VDestroy_Serial(target->iData->tmp1);
	if (iData->tmp2 != NULL)   N_VDestroy_Serial(target->iData->tmp2);

	if (iData->sparseData.nnz) {
#ifdef FMI_2
		if (iData->sparseData.colPtrs != NULL) comp->functions->freeMemory(iData->sparseData.colPtrs);
		if (iData->sparseData.index != NULL) comp->functions->freeMemory(iData->sparseData.index);
#else
		if (iData->sparseData.colPtrs != NULL) comp->functions.freeMemory(iData->sparseData.colPtrs);
		if (iData->sparseData.index != NULL) comp->functions.freeMemory(iData->sparseData.index);
#endif
		iData->sparseData.colPtrs = NULL;
		iData->sparseData.index = NULL;
		iData->sparseData.nnz = 0;
		iData->sparseData.nGroups = 0;
	}

#ifdef FMI_2
	comp->functions->freeMemory(iData->outputsPrev);
	comp->functions->freeMemory(iData->inputDerivatives);
	comp->functions->freeMemory(iData->inputsT0);
	comp->functions->freeMemory(iData);
#else
	comp->functions.freeMemory(iData->outputsPrev);
	comp->functions.freeMemory(iData->inputDerivatives);
	comp->functions.freeMemory(iData->inputsT0);
	comp->functions.freeMemory(iData);
#endif
	target->iData = NULL;
}

/* ------------------------------------------------------ */
static int g(realtype t, N_Vector y, realtype *gout, void *user_data)
{
	FMIComponent* c = (FMIComponent*) user_data;
	Component* comp = (Component*) c;
	int retval = 0;

	/* temporarily change time, states and inputs to be able to reuse fmiGetEventIndicators */
	FMIReal time = comp->time;
	FMIReal* states = comp->states;

	assert(comp->nStates > 0);
	comp->states = N_VGetArrayPointer(y);

	integration_extrapolate_inputs(comp, t);

	comp->time = t;
	comp->icall = 0;
	if (fmiGetEventIndicators_(c, gout, comp->nCross) != FMIOK) {
		retval= -1;
	}

	/* restore time, states and inputs */
	integration_extrapolate_inputs(comp, time);
	comp->states = states;
	comp->time = time;
	return retval;
}

/* ------------------------------------------------------ */
static int check_step_event(void* user_data) {
	Component* comp = (Component*) user_data;
	return (comp->istruct->mTriggerStepEvent != 0);
}

/* ------------------------------------------------------ */
static void err_msg_handler(int error_code, const char *module, const char *function,
					 char *msg, void *eh_data)
{
	Component* comp = (Component*) eh_data;
	char * CVodeFlagName = CVodeGetReturnFlagName(error_code);
	util_logger(comp, comp->instanceName, FMIWarning, "", "%s: %s failed with %s:\n %s",
		module, function,  CVodeFlagName, msg);
	free(CVodeFlagName);
}

/* ------------------------------------------------------ */
/*
* cvEwtSetVV
*
* Function used to set the weight vector for the weighted norm. This allows elementwise relTol. Weights are set according to:
*
*	struct CVGodessData* comp = (struct CVGodessData*) user_data;
*  	ewt[i] = 1 / (comp->relTol[i] * SUNRabs(y[i]) + comp->absTol[i]), i=0,...,neq-1.
*
* - Erik Henningsson, 2017-05-30
*/
static int cvEwtSetVV(N_Vector y, N_Vector ewt, void *user_data) {

	Component* comp = (Component*) user_data; // user_data points to Component here
	IntegrationData* iData = comp->iData;
	int n;

	if (iData->abstol == NULL || iData->reltol == NULL) return -1;
	n = NV_LENGTH_S(y);
	if (NV_LENGTH_S(ewt) != n || NV_LENGTH_S(iData->reltol) != n || NV_LENGTH_S(iData->abstol) != n) return -1;

	N_VAbs(y, ewt);
	N_VProd(iData->reltol, ewt, ewt);
	N_VLinearSum(1.0, ewt, 1.0, iData->abstol, ewt);
	if (N_VMin(ewt) <= 0.0) return -1;
	N_VInv(ewt, ewt);
	return 0;
}

#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
/* checks if sparse solver is to be used and returns number of nonzero elements */
static int EnableSparse(int nx) {
	int nGroups = QJacobianCG_[0];
	if (!global_sparse_enabled)
		return 0;
	if (nGroups > 0) {
		// Count non-zero elements
		int i;
		int group_nr, group_ix = 1;
		int nz = 0;
		for (group_nr = 0; group_nr < nGroups; group_nr++) {
			int nmembers = QJacobianCG_[group_ix];
			int gc_ix = (int)(nx * group_nr);
			for (i = 0; i<nx; ++i) if (QJacobianGC_[gc_ix + i]>0) ++nz;
			group_ix += 1 + nmembers;
		}
		return nz;
	} else
		return 0;
}

/* computes fixed Jacobian structure data to be used when calculating numeric Jacobian using grouping */
static int PrepareSparse(Component *comp, SparseFixData *sparseData, int N, int nz) {
	int band_width = 0;
	int nGroups = QJacobianCG_[0];
	int i;

	sparseData->nnz = nz;
	sparseData->nGroups = nGroups;

#ifdef FMI_2
	sparseData->colPtrs = (int *) comp->functions->allocateMemory(N+1, sizeof(int));
	sparseData->index = (int *) comp->functions->allocateMemory(N*nGroups, sizeof(int));
#else
	sparseData->colPtrs = (int *) comp->functions.allocateMemory(N+1, sizeof(int));
	sparseData->index = (int *) comp->functions.allocateMemory(N*nGroups, sizeof(int));
#endif
	
	for(i=0;i<N*nGroups;++i) sparseData->index[i]=-1;

	{
		int nnz=0,j=0;
		for(;j<N;++j) {
			int group_nr;
			int group_ix=1;
			/* Set values */
			sparseData->colPtrs[j]=nnz;
			/* Find group */
			for (group_nr = 0; group_nr < nGroups; group_nr++) {
				int i, i2;
				int nmembers = QJacobianCG_[group_ix];
				int gc_ix = (int)(N * group_nr);
				for(i2=0;i2<nmembers;++i2) {
					if (QJacobianCG_[group_ix+i2+1]==j+1) {
						/* Found group containing it, copy specific values */
						for (i = 0; i < N; i++) {
							int col = QJacobianGC_[gc_ix + i]-1;
							if (col==j) {
								sparseData->index[gc_ix+i]=nnz;
								++nnz;
								band_width = Dymola_max(band_width, Dymola_abs(i - col));
							}
						}
					}
				}
				group_ix += 1 + nmembers;
			}
		}
		sparseData->colPtrs[j]=nnz;
	}
	return band_width;
}

/* return the number of cores to be used by the multithreaded sparse SuperLU */
static int getNumProcsCvode(int nx, int nnz, int bw) {

	const int np = global_sparse_enabled;
	if (np <= 0)
		return 1;
	else
		return np;
}
#endif
