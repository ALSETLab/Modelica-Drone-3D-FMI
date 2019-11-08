/* The generic implementation of the FMI co-simulation interface. */

#ifndef FMU_SKIP_CO_SIM

/* need to include first so that correct files are included */
#include "conf.h"
#include "util.h"
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
#include "integration.h"
#endif
#include "result.h"

#include "fmiFunctions_fwd.h"

#include "adymosim.h"

#include <math.h>
#include <assert.h>
#ifndef DYMOLA_STATIC_IMPORT
#define DYMOLA_STATIC_IMPORT DYMOLA_STATIC
#endif

/* ----------------- macros ----------------- */

#ifdef FMI_2
#define CS_RESULT_SAMPLE(atEvent)                            \
if (comp->storeResult == FMITrue) {                          \
		result_sample(comp, atEvent);                        \
		if (noSetFMUStatePriorToCurrentPoint == FMITrue) {   \
			result_flush(comp);                              \
		}                                                    \
}
#else
#define CS_RESULT_SAMPLE(atEvent)                            \
if (comp->storeResult == FMITrue) {                          \
		result_sample(comp, atEvent);                        \
}
#endif

/* ----------------- local function declarations ----------------- */

static FMIStatus handleEvent(FMIComponent c);


/* ----------------- local variables ----------------- */

/* when compiling as a single complilation unit, this is already defined */
#ifndef FMU_SOURCE_SINGLE_UNIT
extern Component* globalComponent2;
#endif

/* ----------------- function definitions ----------------- */

/* For 2.0 this is replaced by a function common for both ME and Co-sim. */
#ifndef FMI_2
DYMOLA_STATIC const char* fmiGetTypesPlatform_()
{
	return fmiPlatform;
}
#endif

/* ---------------------------------------------------------------------- */
#ifdef FMI_2
DYMOLA_STATIC FMIComponent fmiInstantiateSlave_(FMIString instanceName,
												FMIString fmuGUID,
												FMIString fmuResourceLocation,
												const FMICallbackFunctions* functions,
												FMIBoolean visible,
												FMIBoolean loggingOn)
{
	static FMIString label = "fmi2Instantiate";
	Component* comp = fmiInstantiateModel_(instanceName, fmuGUID, fmuResourceLocation, functions, visible, loggingOn);
	/* ignore argument "visible" since we never provide any GUI */
	if (comp == NULL) {
		return NULL;
	}

	if (functions->stepFinished != NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "",
			"%s: Callback function stepFinished != NULL but asynchronous fmiDoStep is not supported",label);
	}
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	return comp;
}
#else

FMIComponent fmiInstantiateSlave_(FMIString  instanceName,
                                  FMIString  fmuGUID,
                                  FMIString  fmuLocation,
                                  FMIString  mimeType,
                                  FMIReal    timeout,
                                  FMIBoolean visible,
                                  FMIBoolean interactive,
                                  fmiCoSimCallbackFunctions functions,
                                  FMIBoolean loggingOn)
{
	static FMIString label = "fmiInstantiateSlave";
	Component* comp;
	static fmiMECallbackFunctions meFunctions;
	meFunctions.logger = functions.logger;
	meFunctions.allocateMemory = functions.allocateMemory;
	meFunctions.freeMemory = functions.freeMemory;

	/* Since we don't support tool coupling, the following arguments are ignored:
	fmuLocation, mimeType */

	comp = (Component*) fmiInstantiateModel_(instanceName, fmuGUID, meFunctions, loggingOn);
	if (comp == NULL) {
		return NULL;
	}	
	if (functions.stepFinished != NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "",
			"%s: Callback function stepFinished != NULL but asynchronous fmiDoStep is not supported",label);
	}

	if (timeout > 0) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: timeout != 0 is not supported",label);
	}
	/* ignore argument "visible" since we never provide any GUI */ 
	if (interactive) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: interactive not supported",label);
	}
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	return comp;

}
#endif /* FMI_2 */

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC void fmiFreeSlaveInstance_(FMIComponent c)
{
    fmiFreeModelInstance_(c);
}
DYMOLA_STATIC_IMPORT const double cvodeTolerance;
#ifdef FMI_2
/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiEnterSlaveInitializationMode_(FMIComponent c,
	                                                     FMIReal      relativeTolerance,
														 FMIReal      tStart,
														 FMIBoolean   StopTimeDefined,
														 FMIReal      tStop)
{
	static FMIString label = "fmi2EnterInitializationMode";
	Component* comp = (Component*) c;
	FMIStatus status;
	if(!comp->relativeToleranceDefined){
		relativeTolerance = cvodeTolerance;
	}
	status = util_initialize_slave(c, relativeTolerance, tStart, StopTimeDefined, tStop);
	if (status != FMIOK) {
		return status;
	}
	comp->mStatus = modelInitializationMode;
	comp->inlineStepCounter = 0;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	return status;
}

/* ---------------------------------------------------------------------- */
FMIStatus fmiExitSlaveInitializationMode_(FMIComponent c)
{
	static FMIString label = "fmiExitInitializationMode";
	Component* comp = (Component*) c;
	FMIStatus status;

	util_logger(comp, comp->instanceName, FMIOK, "", "%s...", label);
	status = util_exit_model_initialization_mode(c, label, modelContinousTimeMode);
	if (status != FMIOK) {
		return status;
	}
	comp->mStatus = modelContinousTimeMode;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s completed", label);
	return FMIOK;
}

#else /* FMI_2 */
/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiInitializeSlave_(FMIComponent c,
											FMIReal      tStart,
											FMIBoolean   StopTimeDefined,
											FMIReal      tStop)
{
	static FMIString label = "fmiInitializeSlave";
	Component* comp = (Component*) c;
	FMIStatus status;
	comp->isCoSim=FMITrue;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s...", label);
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	if(!comp->istruct->mInlineIntegration){
		util_logger(comp, comp->instanceName, FMIOK, "", "%s cvode tolerance is %g", label, cvodeTolerance);
	}
#endif
	status = util_initialize_slave(c, cvodeTolerance, tStart, StopTimeDefined, tStop);
	if (status != FMIOK) {
		return status;
	}
	comp->mStatus = modelContinousTimeMode;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s completed", label);
	return status;
}
#endif /* FMI_2 */

/* ---------------------------------------------------------------------- */
extern void delayBuffersClose(void);
extern void delayBuffersCloseNew(struct DYNInstanceData*);
DYMOLA_STATIC void copyDStatesToDid(struct DYNInstanceData*did_, double* dStates, double* previousVars);
DYMOLA_STATIC void copyDStatesFromDid(struct DYNInstanceData*did_, double* dStates, double* previousVars);
DYMOLA_STATIC int dsblock_tid(int *idemand_, int *icall_,
	double *time, double x_[], double xd_[], double u_[],
	double dp_[], int ip_[], Dymola_bool lp_[],
	double f_[], double y_[], double w_[], double qz_[],
	double duser_[], int iuser_[], void*cuser_[], struct DYNInstanceData*,
	int *ierr_, int tid);

DYMOLA_STATIC FMIStatus fmiTerminateSlave_(FMIComponent c)
{	
#ifdef FMI_2
	static FMIString label = "fmi2Terminate";
#else
	static FMIString label = "fmiTerminateSlave";
#endif
	Component* comp = (Component*) c;
	FMIStatus status =FMIOK;
	FMIStatus status2 = FMIOK;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s...", label);
	if (comp->mStatus == modelTerminated) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: already terminated, ignoring call", label);
		return FMIWarning;
	}
	if(comp->QiErr == 0 && comp->terminationByModel == FMIFalse){
		/*Special case for terminal, call dsblock_ directly instead of
		using util_refresh_cache to avoid messy logic*/
		int terminal = iDemandTerminal;
		copyDStatesToDid(comp->did,comp->dStates,comp->previousVars);
		if (comp->did) {
			globalComponent2=comp;
			dsblock_tid(&terminal, &comp->icall, &comp->time, comp->states, 0,
			comp->inputs, comp->parameters,
			0, 0, comp->derivatives, comp->outputs, comp->auxiliary,                                
			comp->crossingFunctions, comp->duser, comp->iuser,
			(void**) comp->sParameters, comp->did, &comp->QiErr, 0);
			globalComponent2=0;
		} else {
			dsblock_(&terminal, &comp->icall, &comp->time, comp->states, 0,             
			comp->inputs, comp->parameters, 0, 0, comp->derivatives,       
			comp->outputs, comp->auxiliary,                                
			comp->crossingFunctions, comp->duser, comp->iuser,
			(void**) comp->sParameters, &comp->QiErr);
		}
		copyDStatesFromDid(comp->did,comp->dStates,comp->previousVars);
		if (comp->QiErr>=-995 && comp->QiErr<=-990) comp->QiErr=0; /* Ignore special cases for now */
		if(!(comp->QiErr == 0 || comp->QiErr==-999)){
			status = FMIError;
			util_logger(comp, comp->instanceName, FMIError, "",
				"%s: calling terminal section of dsblock_ failed, QiErr = %d",
				label,comp->QiErr);
		}
	}
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	if(!comp->istruct->mInlineIntegration){
		integration_teardown(c);
	}
#endif
	util_print_dymola_timers(c);
#ifndef FMU_SOURCE_CODE_EXPORT
	if (comp->storeResult == FMITrue) {
		result_teardown(comp);
	}
#endif /* FMU_SOURCE_CODE_EXPORT */
    if (comp->did) {
		delayBuffersCloseNew(comp->did);
	} else {
		delayBuffersClose();
	}
	comp->mStatus = modelTerminated;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s completed", label);
	return status;
}

extern void declare_(double*, double*, double*, void**,int*);
DYMOLA_STATIC FMIStatus fmiResetSlave_(FMIComponent c)
{
#ifdef FMI_2
	static FMIString label = "fmi2Reset";
#else
	static FMIString label = "fmiResetSlave";
#endif
	Component* comp = (Component*) c;
	FMIStatus status = FMIOK;
	int QiErr = 0;
	size_t i;

	util_logger(comp, comp->instanceName, FMIOK, "", "%s...", label);

	switch (comp->mStatus) {
		case modelContinousTimeMode:
		case modelInitializationMode:
#ifdef FMI_2
		case modelEventMode:
		case modelEventMode2:   
		case modelEventModeExit:
#endif
			if(comp->isCoSim){
				status = fmiTerminateSlave_(c);
#ifdef FMI_2
			}else{

	            status = fmiTerminateModel_(c);
#endif
			}
			if (status != FMIOK && status != FMIWarning) {
				return status;
			}
			/* fall-through */
		case modelTerminated:
			/* reset states and parameters */
			if(comp->tsParameters == NULL && comp->nSPar>0){
#ifdef FMI_2
			  comp->tsParameters = (FMIChar**) comp->functions->allocateMemory(comp->nSPar, sizeof(FMIChar*));
#else
			  comp->tsParameters = (FMIChar**) comp->functions.allocateMemory(comp->nSPar, sizeof(FMIChar*));
#endif
			  if (comp->tsParameters == NULL) {
				  util_logger(comp, comp->instanceName, FMIFatal, "", "%s failed: out of Memory", label);
				  fmiFreeModelInstance_(comp);
				  return FMIFatal;
			  }
			}
			declare_(comp->states, comp->parameters, comp->inputs, (void**) comp->tsParameters, &QiErr);
			for(i=0; i < comp->nSPar; ++i){
				size_t len;
				len=strlen(comp->tsParameters[i]);
				if (len>MAX_STRING_SIZE) len=MAX_STRING_SIZE;
				memcpy((comp->sParameters)[i], comp->tsParameters[i], len+1);
				(comp->sParameters)[i][MAX_STRING_SIZE]='\0';
			}
			/*Clear aux and outputs to handle cases when dsmodel assumes default 0 start value*/
			for(i = 0; i < comp->nAux; ++i){
				comp->auxiliary[i] = 0;
			}
			for(i = 0; i < comp->nOut; ++i){
				comp->outputs[i]=0;
			}

			if (QiErr != 0) {
				util_logger(comp, comp->instanceName, FMIError, "",
					"%s: declare_ failed, QiErr = %d", label, QiErr);
				return util_error(comp);
			}
			comp->mStatus = modelInstantiated;
			comp->recalJacobian = 1;
			break;
		case modelInstantiated:
			util_logger(comp, comp->instanceName, FMIOK, "", "%s: already reset, ignoring call", label);
			return FMIOK;
	}

	util_logger(comp, comp->instanceName, status, "", "%s completed", label);
	return status;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSetRealInputDerivatives_(FMIComponent c,
													const  FMIValueReference vr[],
													size_t nvr,
													const  FMIInteger order[],
													const  FMIReal value[])
{
#ifdef FMI_2
	static FMIString label = "fmi2SetRealInputDerivatives";
#else
	static FMIString label = "fmiSetRealInputDerivatives";
#endif
	Component* comp = (Component*) c;
#ifdef ONLY_INCLUDE_INLINE_INTEGRATION
	util_logger(comp, comp->instanceName, FMIWarning, "", "%s is not suported with inline integration",label);
	return FMIWarning;
#else
	size_t nu = comp->nIn; 
	size_t i;
	if(comp->istruct->mInlineIntegration){
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s is not suported with inline integration",label);
		return FMIWarning;
    }
	if(	comp->mStatus == modelInstantiated){
		util_logger(comp, comp->instanceName, FMIWarning, "",
#ifdef FMI_2
			"%s: fmi2EnterInitializationMode must be called before calling %s", label, label);
#else
			"%s: fmiInitializeSlave must be called before calling %s", label, label);
#endif
		return FMIWarning;
	}

	if (nvr == 0 || nvr > nu) {
		util_logger(comp, comp->instanceName, FMIWarning, "",
			"%s: invalid nvr = %d (number of inputs = %d), ignoring call", label, nvr, nu);
		return FMIWarning;
	}

	for (i = 0; i < nvr; i++) {
		const FMIValueReference r = vr[i];
		int ix = FMI_INDEX(r);

		if (order[i] == 1) {
			switch (FMI_CATEGORY(r)) {
			case dsInput:
				comp->iData->inputDerivatives[ix] = value[i];
				break;
			default:
				util_logger(comp, comp->instanceName, FMIWarning, "", "%s: variable is not input", label);
				return FMIWarning;
			}
		} else {
			util_logger(comp, comp->instanceName, FMIWarning, "",
						"%s: derivative order %d is not supported", label, order[i]);
			return FMIWarning;
		}
	}
	memcpy(comp->iData->inputsT0, comp->inputs, comp->nIn * sizeof(FMIReal));
	comp->iData->derivativeTime = comp->time;
	comp->iData->useDerivatives = 1;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	return FMIOK;
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetRealOutputDerivatives_(FMIComponent c,
													 const   FMIValueReference vr[],
													 size_t  nvr,
													 const   FMIInteger order[],
													 FMIReal value[])
{


#ifdef FMI_2
	static FMIString label = "fmi2GetRealOutputDerivatives";
#else
	static FMIString label = "fmiGetRealOutputDerivatives";
#endif
	Component* comp = (Component*) c;
#ifdef ONLY_INCLUDE_INLINE_INTEGRATION
	util_logger(comp, comp->instanceName, FMIWarning, "", "%s is not suported with inline integration",label);
	return FMIWarning;
#else
	IntegrationData* iData = comp->iData;
	FMIReal dt = comp->time - iData->timePrev;
	size_t ny = comp->nOut; 
	size_t i;
	if(comp->istruct->mInlineIntegration){
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s is not suported with inline integration",label);
		return FMIWarning;
	}
	if(	comp->mStatus == modelInstantiated){
		util_logger(comp, comp->instanceName, FMIWarning, "",
#ifdef FMI_2
			"%s: fmi2EnterInitializationMode must be called before calling %s", label, label);
#else
			"%s: fmiInitializeSlave must be called before calling %s", label, label);
#endif
		return FMIWarning;
	}
	if (nvr == 0 || nvr > ny) {
		util_logger(comp, comp->instanceName, FMIWarning, "",
			"%s: invalid nvr = %d (number of outputs = %d)", label, nvr, ny);
		return FMIWarning;
	}

	/* fetch new output values */
	if (util_refresh_cache(comp, iDemandOutput, label, NULL)) {
		return util_error(comp);
	}

	for (i = 0; i < nvr; i++) {
		const FMIValueReference r = vr[i];
		int ix = FMI_INDEX(r);

		if (order[i] == 1) {
			switch (FMI_CATEGORY(r)) {
			case dsOutput:
				if (dt <= 0) {
					util_logger(comp, comp->instanceName, FMIWarning, "",
						"%s: time interval for estimate is %f, returning 0", label, dt);
					value[i] = 0;
				}
				value[i] = (comp->outputs[ix] - iData->outputsPrev[ix]) / dt;
				break;
			default:
				util_logger(comp, comp->instanceName, FMIWarning, "", "%s: variable is not output", label);
				return FMIWarning;
				break;
			}
		} else if (order[i] > 1) {
			value[i] = 0;
		} else {
			util_logger(comp, comp->instanceName, FMIWarning, "", "%s: derivative order 0 is not allowed", label);
			return FMIWarning;
		}
	}
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	return FMIOK;
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */
}


/* ---------------------------------------------------------------------- */
DYMOLA_STATIC 
#ifdef FMI_2
FMIStatus fmiDoStep_(FMIComponent c, FMIReal currentCommunicationPoint, FMIReal communicationStepSize, 
					 FMIBoolean noSetFMUStatePriorToCurrentPoint)
#else
FMIStatus fmiDoStep_(FMIComponent c, FMIReal currentCommunicationPoint, FMIReal communicationStepSize,
					 FMIBoolean newStep)
#endif
{
#ifdef FMI_2
	static FMIString label = "fmi2DoStep";
#else
	static FMIString label = "fmiDoStep";
#endif
	Component* comp = (Component*) c;
	int QiErr = 0;
	FMIStatus status;
	FMIReal endStepTime;
	FMIBoolean finalTimeEventCalled = FMIFalse;
	FMIReal tdev = fabs(comp->time - currentCommunicationPoint);
	if(comp->mStatus == modelInstantiated || comp->mStatus== modelInitializationMode){
		util_logger(comp, comp->instanceName, FMIWarning, "",
				"%s: Initialization must be finished before calling fmiDoStep", label);
		return FMIWarning;
	}
	if (comp->mStatus == modelTerminated || comp->terminationByModel == FMITrue) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: model is terminated",label);
		return FMIWarning;
	}
	/* check if reasonably close to expected time */
	if (!comp->istruct->mInlineIntegration ? tdev > 0 : tdev > 1.5*comp->dstruct->mDymolaFixedStepSize) {
		if (tdev >= SMALL_TIME_DEV(comp->time)) {
			util_logger(comp, comp->instanceName, FMIWarning, "",
				"%s: currentCommunicationPoint = %.16f, expected %.16f",label, currentCommunicationPoint, comp->time);
			return FMIWarning;
		}
		/* compensate by adjusting step size, unless event iteration request */
		/*no longer since current comuncation point and not internal time is used to calculate end time*/
#if 0
		if (communicationStepSize != 0) {
			FMIReal dh = currentCommunicationPoint - comp->time;
#ifdef FMU_VERBOSITY
			util_logger(comp, comp->instanceName, FMIOK, "",
				"t=%f: Adjusting communicationStepSize with %.16e s.\n", comp->time, dh);
#endif
			communicationStepSize += dh;
		}
#endif
	}

	if (communicationStepSize == 0) {
		return handleEvent(c);
	}

#ifndef FMI_2
	if (newStep == FMIFalse) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: newStep = fmiFalse not supported", label);
		return FMIWarning;
	}
#endif

	/*endStepTime = comp->time + communicationStepSize;*/
	endStepTime = currentCommunicationPoint + communicationStepSize;
	if (comp->StopTimeDefined) {
		/* check if reasonably within stop time */
		tdev = endStepTime - comp->tStop;
		if (tdev > 0) {
			/* allow twice as much since we might have adjusted communicationStepSize already */
			if (tdev > 2 * SMALL_TIME_DEV(comp->tStop)) {
				util_logger(comp, comp->instanceName, FMIWarning, "",
					"%s: trying to compute past tStop = %f, to %.16f,  at t = %f", "",label, comp->tStop, endStepTime, comp->time);
				return FMIWarning;
			}
			/* adjust end time */
			util_logger(comp, comp->instanceName, FMIOK, "",
				"t = %f: Reducing communicationStepSize %.16e s to avoid passing tStop.\n", comp->time, tdev);
			endStepTime = comp->tStop;
		}
	}
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	if(!comp->istruct->mInlineIntegration){
		/* handle any values changed externally */
		if (comp->valWasSet) {
			FMIStatus status = handleEvent(c);
			comp->valWasSet = 0;
			if (status != FMIOK) {
				return status;
			}
		}
		/* check if re-computing derivatives necessary */
		else if (comp->icall < iDemandDerivative) {
			int QiErr = util_refresh_cache(comp, iDemandDerivative, label, NULL);
			if (QiErr != 0) {
				return (QiErr == 1) ? FMIDiscard : util_error(comp);
			}
		}
		/* integration should have been setup by now */
		assert(comp->iData != NULL);

		/* Time events can be predicted/handled outside integration steps while state/step events must be
		   detected within (since we cannot predict their time). Step events are OK to handle after
		   each step. */
		while (comp->time < endStepTime || endStepTime == comp->dstruct->mNextTimeEvent && !finalTimeEventCalled ) {
			FMIBoolean callEventUpdate = FMIFalse;
			if (comp->time < comp->dstruct->mNextTimeEvent) {
				FMIReal intStopTime = MIN(comp->dstruct->mNextTimeEvent,comp->nextResultSampleTime);
				FMIReal nextTime = MIN(endStepTime, intStopTime);
				/* integrate */
				switch(integration_step(comp, nextTime)) {
					case integrationOK:
						break;
					case integrationTerminate:
						status = FMIDiscard;
						util_logger(comp, comp->instanceName, status, "", "%s: simulation terminated by model",label);
						comp->terminationByModel = FMITrue;
						return status;
					case integrationError:
						util_logger(comp, comp->instanceName, FMIError, "", "%s: integration_step failed",label);
						return util_error(comp);
				}
				fmiSetTime_(c, nextTime);
				/* compute approximate inputs */
				integration_extrapolate_inputs(comp, nextTime); 
				/* check step events in case they occurred at the very end time of step */
				if (comp->istruct->mTriggerStepEvent != 0) {
					callEventUpdate = FMITrue;
#ifdef LOG_EVENTS
					util_logger(c, comp->instanceName, FMIOK, "", "%.12f: step event", comp->time);
#endif
				}
				if(comp->storeResult && nextTime == comp->nextResultSampleTime && !callEventUpdate && nextTime != comp->dstruct->mNextTimeEvent){
					/*if event sampling will be handled at the event instead*/
					CS_RESULT_SAMPLE(FMIFalse);
				}
			} else {
				fmiSetTime_(c, comp->dstruct->mNextTimeEvent);
				if(comp->time == endStepTime){
					finalTimeEventCalled=FMITrue;
				}
				callEventUpdate = FMITrue;
#ifdef LOG_EVENTS
				util_logger(c, comp->instanceName, FMIOK, "", "%.12f: time event", comp->time);
#endif
			}
			if (callEventUpdate) {
				FMIStatus status;
				CS_RESULT_SAMPLE(FMITrue);
				status = handleEvent(c);
				if (status != FMIOK) {
					return status;
				}
				CS_RESULT_SAMPLE(FMITrue);
			}
		}
		comp->time = endStepTime;
		comp->iData->useDerivatives = 0;
	}else{
#endif /* ndef ONLY_INCLUDE_INLINE_INTEGRATION */
		double stepTime = 0;
		double h = comp->dstruct->mDymolaFixedStepSize;
		unsigned long long startStepCount = comp->inlineStepCounter;
		while( (stepTime=(++comp->inlineStepCounter)*h) < endStepTime+0.1*h){
			status = fmiSetTime_(c, stepTime);
			if(status!=FMIOK){
				return status;
			}
			status = handleEvent(c);
			if (status != FMIOK) {
				return status;
			}
		}
		/*Remove last step counter increase that failed while statement*/
		--comp->inlineStepCounter;
		if(startStepCount != comp->inlineStepCounter){
			CS_RESULT_SAMPLE(FMITrue);
		}

#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	}
#endif
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	return FMIOK;
}
#ifdef FMI_2 
DYMOLA_STATIC FMIStatus fmiHybridDoStep_(FMIComponent c, FMIReal currentCommunicationPoint, FMIReal communicationStepSize, 
					 FMIBoolean noSetFMUStatePriorToCurrentPoint, FMIBoolean *encounteredEvent, FMIReal *endTime)

{
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	Component* comp = (Component*) c;
	static FMIString label = "fmi2HybridDoStep";
	int QiErr = 0;
	FMIStatus status;
	FMIReal endStepTime;
	FMIReal tdev = fabs(comp->time - currentCommunicationPoint);

	if (comp->mStatus == modelTerminated || comp->terminationByModel == FMITrue) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: model is terminated", label);
		return FMIWarning;
	}
		/* handle any values changed externally */
	if (comp->eventIterRequired || comp->valWasSet || comp->mStatus == modelCsPreEventMode || comp->hycosimInputEvent) {
		/* fmiStatus status = handleEvent(c); */
		comp->mStatus = modelCsPreEventMode;
		comp->eventIterRequired = 1;
		*encounteredEvent=FMITrue;
		*endTime = comp->time;
		return FMIOK;
	}

	if(comp->mStatus != modelContinousTimeMode){
		if(comp->mStatus == modelEventModeExit){
			/*We have to reinit solution after event*/
			if (integration_reinit(comp, 1) != integrationOK) {
				return util_error(comp);
			}
			comp->mStatus = modelContinousTimeMode;
		}else{
			util_logger(comp, comp->instanceName, FMIWarning, "", "%s: more eventIteration needed before calling hybridDoStep",label);
			return FMIWarning;
		}
	}
	/* check if reasonably close to expected time */
	if (tdev > 0) {
		if (tdev >= SMALL_TIME_DEV(comp->time)) {
			util_logger(comp, comp->instanceName, FMIDiscard, "",
				"%s: currentCommunicationPoint = %.16f, expected %.16f", label, currentCommunicationPoint, comp->time);
			return FMIDiscard;
		}
		/* compensate by adjusting step size, unless event iteration request */
		if (communicationStepSize != 0) {
			FMIReal dh = currentCommunicationPoint - comp->time;
#ifdef FMU_VERBOSITY
			util_logger(comp, comp->instanceName, FMIOK, "",
				"t=%f: Adjusting communicationStepSize with %.16e s.\n", comp->time, dh);
#endif
			communicationStepSize += dh;
		}
	}

	if(communicationStepSize == 0) {
		return handleEvent(c);
		/*TODO new event handling at 0 step?*/
	}

	endStepTime = currentCommunicationPoint + communicationStepSize;
	if (comp->StopTimeDefined) {
		/* check if reasonably within stop time */
		tdev = endStepTime - comp->tStop;
		if (tdev > 0) {
			/* allow twice as much since we might have adjusted communicationStepSize already */
			if (tdev > 2 * SMALL_TIME_DEV(comp->tStop)) {
				util_logger(comp, comp->instanceName, FMIWarning, "",
					"%s: trying to compute past tStop = %f, to %.16f,  at t = %f", label, comp->tStop, endStepTime, comp->time);
				return FMIWarning;
			}
			/* adjust end time */
			util_logger(comp, comp->instanceName, FMIOK, "",
				"t = %f: Reducing communicationStepSize %.16e s to avoid passing tStop.\n", comp->time, tdev);
			endStepTime = comp->tStop;
		}
	}
	/* check if re-computing derivatives necessary */
	else if (comp->icall < iDemandDerivative) {
		int QiErr = util_refresh_cache(comp, iDemandDerivative, label, NULL);
		if (QiErr != 0) {
			return (QiErr == 1) ? FMIDiscard : util_error(comp);
		}
	}

	/* integration should have been setup by now */
	assert(comp->iData != NULL);

	/* Time events can be predicted/handled outside integration steps while state/step events must be
	   detected within (since we cannot predict their time). Step events are OK to handle after
	   each step. */
	while (comp->time < endStepTime || endStepTime == comp->dstruct->mNextTimeEvent){
		if (comp->time < comp->dstruct->mNextTimeEvent) {
			FMIReal nextTime = MIN(endStepTime, comp->dstruct->mNextTimeEvent);
			/* integrate */
			switch(integration_step_return_at_event(c, nextTime, endTime)) {
				case integrationOK:
					break;
				case integrationTerminate:
					status = FMIDiscard;
					util_logger(comp, comp->instanceName, status, "", "%s: simulation terminated by model",label);
					comp->terminationByModel = FMITrue;
					return status;
				case integrationError:
					util_logger(comp, comp->instanceName, FMIError, "", "%s: integration_step failed", label);
					return util_error(comp);
				case integrationEvent:
					*encounteredEvent=FMITrue;
					comp->mStatus = modelCsPreEventMode;
					comp->firstEventCall = FMITrue;
					return FMIOK;
			}
			fmiSetTime_(c, nextTime);
				/* compute approximate inputs */
			integration_extrapolate_inputs(comp, nextTime); 
				/* check step events in case they occurred at the very end time of step */
			if (comp->istruct->mTriggerStepEvent != 0) {
				comp->eventIterRequired =1;
				*encounteredEvent=FMITrue;
#ifdef LOG_EVENTS
				util_logger(c, comp->instanceName, FMIOK, "", "%.12f: step event", comp->time);
#endif
				*endTime = nextTime;
				comp->mStatus = modelCsPreEventMode;
				comp->firstEventCall = FMITrue;
				return FMIOK;
			}
		} else {
			fmiSetTime_(c, comp->dstruct->mNextTimeEvent);
			*endTime = comp->dstruct->mNextTimeEvent;
			*encounteredEvent=FMITrue;
			comp->mStatus = modelCsPreEventMode;
			comp->firstEventCall = FMITrue;
			return FMIOK;
#ifdef LOG_EVENTS
			util_logger(c, comp->instanceName, FMIOK, "", "%.12f: time event", comp->time);
#endif
		}
	}

	*encounteredEvent=FMIFalse;
    comp->time = endStepTime;
	comp->mStatus = modelContinousTimeMode;
	comp->firstEventCall = FMITrue;
	CS_RESULT_SAMPLE(FMITrue);

	comp->iData->useDerivatives = 0;
#endif /* ndef ONLY_INCLUDE_INLINE_INTEGRATION */ 
	return FMIOK;
}

DYMOLA_STATIC FMIStatus fmiGetNextEventTime_(FMIComponent c, FMIReal *eventTime)
{
	Component* comp = (Component*) c;
	*eventTime = comp->dstruct->mNextTimeEvent;
	return FMIOK;
}

#endif /*FMI_2*/


/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiCancelStep_(FMIComponent c)
{
	Component* comp = (Component*) c;
#ifdef FMI_2
	static FMIString label = "fmi2CancelStep";
#else
	static FMIString label = "fmiCancelStep";
#endif
	util_logger(comp, comp->instanceName, FMIDiscard, "", "%s: asynchronous execution of fmiDoStep is not supported",label);
	return FMIDiscard; /*	asynchronous execution of fmiDoStep is not supported,
							so this method should not be called at all */
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetStatus_(FMIComponent c, const FMIStatusKind s, FMIStatus* value)
{
#ifdef FMI_2
	static FMIString label = "fmi2GetStatus";
#else
	static FMIString label = "fmiGetStatus";
#endif
	Component* comp = (Component*) c;
	util_logger(comp, comp->instanceName, FMIDiscard, "",
		"%s: not supported since asynchronous execution of fmiDoStep is not supported",label);
	return FMIDiscard;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetRealStatus_(FMIComponent c, const FMIStatusKind s, FMIReal* value)
{
#ifdef FMI_2
	static FMIString label = "fmi2GetRealStatus";
#else
	static FMIString label = "fmiGetRealStatus";
#endif
	Component* comp = (Component*) c;
	if (s != FMILastSuccessfulTime) {
		util_logger(comp, comp->instanceName, FMIDiscard, "", "%s: fmiStatusKind %d unknown",label, s);
		return FMIDiscard;
	}
	*value = comp->time;
	return FMIOK;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetIntegerStatus_(FMIComponent c, const FMIStatusKind s, FMIInteger* value)
{
#ifdef FMI_2
	static FMIString label = "fmi2GetIntegerStatus";
#else
	static FMIString label = "fmiGetIntegerStatus";
#endif
	Component* comp = (Component*) c;
	util_logger(comp, comp->instanceName, FMIDiscard, "", "%s: fmiStatusKind %d unknown", label, s);
	return FMIDiscard;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetBooleanStatus_(FMIComponent c, const FMIStatusKind s, FMIBoolean* value)
{
#ifdef FMI_2
	static FMIString label = "fmi2GetBooleanStatus";
#else
	static FMIString label = "fmiGetBooleanStatus";
#endif
	Component* comp = (Component*) c;
#ifdef FMI_2
	if (s != FMITerminated)
#endif
	{
		util_logger(comp, comp->instanceName, FMIDiscard, "", "%s: fmiStatusKind %d unknown",label, s);
		return FMIDiscard;
	}
#ifdef FMI_2
	*value = comp->terminationByModel;
	return FMIOK;
#endif
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetStringStatus_(FMIComponent c, const FMIStatusKind s, FMIString* value)
{
#ifdef FMI_2
	static FMIString label = "fmi2GetStringStatus";
#else
	static FMIString label = "fmiGetStringStatus";
#endif
	Component* comp = (Component*) c;
	util_logger(comp, comp->instanceName, FMIDiscard, "",
		"%s: not supported since asynchronous execution of fmiDoStep is not supported",label);
	return FMIDiscard;
}

/* ----------------- local function definitions ----------------- */
static FMIStatus handleEvent(FMIComponent c)
{
	Component* comp = (Component*) c;
	FMIStatus status;
#ifdef FMI_2
	FMIBoolean terminateSimulation;
#else
	FMIEventInfo eventInfo;
#endif

	status = util_event_update(comp, FMIFalse,
#ifdef FMI_2
		&terminateSimulation);
#else
		&eventInfo);
#endif
	if (status != FMIOK) {
		return status;
	}

#ifdef FMI_2
	if (terminateSimulation)  {
#else
	if (eventInfo.terminateSimulation) {
#endif
		status = FMIDiscard;
		util_logger(comp, comp->instanceName, status, "", "fmiDoStep: simulation terminated by model");
		comp->terminationByModel = FMITrue;
		return status;
	}

#ifndef FMI_2
	assert(eventInfo.stateValueReferencesChanged == FMIFalse);
#endif
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	if(!comp->istruct->mInlineIntegration){
		if (integration_reinit(comp,1) != integrationOK) {
			return util_error(comp);
		}
	}
#endif
	return FMIOK;
}

#endif /* FMU_SKIP_CO_SIM */
