/* The generic implementation of the FMI interface common for both ME and Co-simulation. */

/* need to include first so that correct files are included */
#include "conf.h"
#include "util.h"
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
#include "integration.h"
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */
#include "fmiFunctions_fwd.h"
#ifdef FMI_2
/* for serialization of FMU state */
#if !defined(NO_FILE)
#include "tpl.h"
#endif
#endif /* FMI_2 */

#include "adymosim.h"
#include <assert.h>
#include <math.h>

/* ----------------- macros ----------------- */

#define ALLOC_AND_CHECK(dest, n, size)    	     					\
	dest = allocateMemory(n, size);	                        		\
	if (dest == NULL) {														\
		goto mem_fail;                                                      \
	} else {																\
		freeList[freeIndex++] = dest;										\
	}

/* ----------------- local function declarations ----------------- */

/* allocate memory for the FMU state */


#if defined(FMI_2)
static FMIStatus allocateFMUState(FMIFMUstate* FMUState, Component* source);

#if !defined(NO_FILE)
/* create TPL map */
static tpl_node* createTplMap(Component* comp, tpl_bin *tplDidBin);

/* local functions for TPL to use */
static void *tplMalloc(size_t size);
static void tplFree(void* ptr);
#endif
#endif /* FMI_2 */

/* find the largest iDemand value in a given array of value references */
static int getLargestIdemand(const FMIValueReference vr[], size_t nvr);

#ifdef FMI_2
static int copyVariables(Component* source, Component* target, const FMICallbackFunctions* funcs);
#endif

/* ----------------- local variables ----------------- */

/* when compiling as a single complilation unit, this is already defined */
#ifndef FMU_SOURCE_SINGLE_UNIT
/* only supports single instances */
Component* globalComponent = NULL;
Component* globalComponent2 = NULL;
#endif

/* Global logger function used by DymosimMessage routines */
DYMOLA_STATIC void fmu_logger(const char* message, int newline, int severity) 
{
	char hashHandeldMessage[4096];
	FMIStatus stat=FMIError;
	int i = 0;
	int j = 0;
	Component* comp;

	switch (severity){
		case 0: stat = FMIOK; break; 
        case 1: stat = FMIWarning; break;
        case 2: stat = FMIError;   break;
	}
		
	for(; j<sizeof(hashHandeldMessage)-1;++i,++j){
		if(message[i]=='\0'){
			hashHandeldMessage[j]='\0';
			break;
		}
		if(message[i]=='#'){
			hashHandeldMessage[j++]='#';
		}
		hashHandeldMessage[j]=message[i];
	}
	hashHandeldMessage[sizeof(hashHandeldMessage)-1]='\0';
		
	comp = globalComponent;
	if (comp == NULL) comp=globalComponent2;
	if (comp != NULL) {
		if (newline) {
			util_logger(comp, comp->instanceName, stat, "", "%s", hashHandeldMessage);
		} else {
			util_buflogger(comp, comp->instanceName, stat, "", "%s", hashHandeldMessage);
		}
	}
}

/* ----------------- external variables ----------------- */

#ifndef DYMOLA_STATIC_IMPORT
#define DYMOLA_STATIC_IMPORT DYMOLA_STATIC
#endif

/* ----------------- unexposed function definitions ----------------- */


/* Enable storing of result from within FMU */
DYMOLA_STATIC void __enableResultStoring(FMIComponent c) {
	Component* comp = (Component*) c;
	comp->storeResult = FMITrue;
}

/* ----------------- function definitions ----------------- */

/* For 1.0 it belongs to Co-sim interface only */
#ifdef FMI_2
DYMOLA_STATIC const char* fmiGetTypesPlatform_()
{
	return fmi2TypesPlatform;
}
#endif

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC const char* fmiGetVersion_()
{
	return fmiVersion;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSetDebugLogging_(FMIComponent c, FMIBoolean loggingOn
#ifdef FMI_2
, size_t nCategories, const FMIString categories[]
#endif
)
{
	Component* comp = (Component*) c;
	comp->loggingOn = loggingOn;
#ifdef FMI_2
	/* TODO: handle categories */
#endif
	return FMIOK;
}

#ifdef FMI_2
static FMIString initFuncName = "fmi2EnterInitializationMode";
#else
static FMIString initFuncName = "fmiInitializeModel";
#endif

/* Common get macro */
#define FMI_GET(type, label, vr_label, m, vr, nvr, value, idemand) {                \
	Component* comp = (Component*) c;                                               \
	size_t i;                                                                       \
                                                                                    \
	if(comp->mStatus == modelInstantiated ){                                        \
		util_logger(comp, comp->instanceName, FMIWarning, "",                       \
		"fmiGet"#label": Not allowed before call of %s", initFuncName);             \
		return FMIWarning;                                                          \
	}                                                                               \
	                                                                                \
    if (comp->mStatus != modelTerminated &&                                         \
        ( comp->icall < idemand && comp->mStatus != modelInitializationMode||       \
	    comp->mStatus == modelInitializationMode && comp->valWasSet                 \
        || comp->enforceRefresh )) {                                                \
                                                                                    \
		 /* refresh cache */                                                        \
		int QiErr = 0;                                                              \
		if(comp->enforceRefresh && idemand <1) idemand = 3;                         \
        QiErr = util_refresh_cache(comp, idemand, NULL, NULL);                      \
		if (QiErr != 0) {                                                           \
		    FMIStatus status =                                                      \
			(QiErr == 1 && strcmp(#label, "Real") == 0) ? FMIDiscard : FMIError;    \
			util_logger(comp, comp->instanceName, status, "",                       \
			       "fmiGet"#label": dsblock_ failed, QiErr = %d", QiErr);           \
			HANDLE_STATUS_RETURN(status);                                           \
		}                                                                           \
	}                                                                               \
                                                                                    \
	for (i = 0; i < nvr; i++) {                                                     \
		const FMIValueReference r = vr[i];                                          \
		int ix = FMI_INDEX(r);                                                      \
                                                                                    \
		switch (FMI_CATEGORY(r)) {                                                  \
		case dsOutput:                                                              \
			value[i] = (type)comp->outputs[ix];                                     \
			break;                                                                  \
        case dsAux:                                                                 \
			value[i] = (type)comp->auxiliary[ix];                                   \
			break;                                                                  \
		case dsState:                                                               \
			value[i] = (type)comp->states[ix];                                      \
			break;                                                                  \
		case dsDerivative:                                                          \
			value[i] = (type)comp->derivatives[ix];                                 \
			break;                                                                  \
		case dsParameter2:case dsParameter:                                         \
			value[i] = (type)comp->parameters[ix];                                  \
			break;                                                                  \
        case dsInput: case dsInput2:                                                \
			value[i] = (type)comp->inputs[ix];                                      \
			break;                                                                  \
		case 11: /*dState */                                                        \
		    value[i] = (type)comp->dStates[ix];                                     \
			break;                                                                  \
		case 12: /*PreviousVar*/                                                    \
		    value[i] = (type)comp->dStates[ix];                                     \
			break;                                                                  \
		case dsSystemVar:                                                             \
             if( 0xffffffff == r){                                                  \
	           value[i] = (type)comp->time;                                         \
               break;                                                               \
             }                                                                      \
		default:                                                                    \
			util_logger(comp, comp->instanceName, FMIWarning, "",                   \
			"fmiGet"#label": cannot get #"#vr_label"%u#", r);                       \
			return FMIWarning;                                                      \
		}                                                                           \
		util_logger(comp, comp->instanceName, FMIOK, "",                            \
		"fmiGet"#label": #"#vr_label"%u# = %g", r, (double) value[i]);              \
	}                                                                               \
} return FMIOK


/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetReal_(FMIComponent c, const FMIValueReference vr[], size_t nvr, FMIReal value[])
{
	int idemand = getLargestIdemand(vr, nvr);
	FMI_GET(FMIReal, Real, r, c, vr, nvr, value, idemand);

}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetInteger_(FMIComponent c, const FMIValueReference vr[], size_t nvr, FMIInteger value[])
{
	int idemand = getLargestIdemand(vr, nvr);
	FMI_GET(FMIInteger, Integer, i, c, vr, nvr, value, idemand);
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetBoolean_(FMIComponent c, const FMIValueReference vr[], size_t nvr, FMIBoolean value[])
{
	int idemand = getLargestIdemand(vr, nvr);
	FMI_GET(FMIBoolean, Boolean, b, c, vr, nvr, value, idemand);
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiGetString_(FMIComponent c, const FMIValueReference vr[], size_t nvr, FMIString value[])
{
#ifdef FMI_2
	static FMIString label = "fmi2GetString";
#else
	static FMIString label = "fmiGetString";
#endif
	Component* comp = (Component*) c;
	int idemand = getLargestIdemand(vr, nvr);
	size_t i;
	if(comp->mStatus == modelInstantiated ){
		util_logger(comp, comp->instanceName, FMIWarning, "",
			"%s: Not allowed before call of %s",label, initFuncName);
		return FMIWarning;
	}
	if (comp->icall < idemand || comp->mStatus == modelInitializationMode && comp->valWasSet) {                              
		int QiErr = 0;                                                             
        QiErr = util_refresh_cache(comp, idemand, NULL, NULL);
		if (QiErr != 0) {
			util_logger(comp, comp->instanceName, FMIError, "",
				"%s: dsblock_ failed, QiErr = %d",label, QiErr);
			HANDLE_STATUS_RETURN(FMIError);
		}
	}
	for ( i = 0; i < nvr; i++) {
		const FMIValueReference r = vr[i];
		int ix = FMI_INDEX(r);
		switch (FMI_CATEGORY(r)) {
		case dsStringParameter2:case dsStringParameter:
			value[i] = comp->sParameters[ix];
			break;
		default:
			util_logger(comp, comp->instanceName, FMIWarning, "", 
				"%s: cannot get #s%u#",label, r);
			return FMIWarning;
		}
		util_logger(comp, comp->instanceName, FMIOK, "",
			"%s: #s%u# = %s",label, r, (FMIString) value[i]);
	}

	return FMIOK;
}
#ifdef ONLY_INCLUDE_INLINE_INTEGRATION
#define integration_sync_extrapolation_input(a, b)
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */


/* ---------------------------------------------------------------------- */
/* Common set macro */
#define FMI_SET(label, vr_label, m, vr, nvr, value)                            \
    Component* comp = (Component*) c;                                          \
	size_t i;                                                                  \
    FMIBoolean allowed = FMITrue;                                              \
    FMIBoolean modified = FMIFalse;                                            \
                                                                               \
	for (i = 0; i < nvr; i++) {                                                \
		const FMIValueReference r = vr[i];                                     \
		int ix = FMI_INDEX(r);                                                 \
                                                                               \
		switch (FMI_CATEGORY(r)) {                                             \
        case dsInput:                                                          \
            if (comp->inputs[ix] != value[i]) {                                \
			    comp->inputs[ix] = value[i];                                   \
                modified = FMITrue;                                            \
			    if (comp->isCoSim) {                                           \
				    integration_sync_extrapolation_input(comp, ix);            \
					comp->hycosimInputEvent =1;                                \
			    }                                                              \
			}                                                                  \
			break;                                                             \
		case dsState:                                                          \
/* allow this to help our own master out, although not really legal */         \
/*		    if (comp->isCoSim && comp->mStatus != modelInstantiated) {       */\
/*                allowed = fmiFalse;                                        */\
/*			} else {                                                         */\
			    /* allow since equivalent with setContinuousStates */          \
                if (comp->states[ix] != value[i]) {                            \
				   comp->states[ix] = value[i];                                \
                   modified = FMITrue;                                         \
				}                                                              \
/*			} */                                                               \
			break;                                                             \
        case dsAux:                                                            \
		 /*Allow if inline since states have become aux at that time*/         \
		    if (comp->mStatus == modelInstantiated ||                          \
                comp->mStatus == modelInitializationMode ||                    \
				comp->istruct->mInlineIntegration ||                           \
                comp->AdvancedDiscreteStates) {                                \
                if (comp->auxiliary[ix] != value[i]) {                         \
			       comp->auxiliary[ix] = value[i];                             \
                   modified = FMITrue;                                         \
				}                                                              \
			}else {                                                            \
                allowed = FMIFalse;                                            \
		 	}                                                                  \
			break;                                                             \
		case dsParameter:                                                      \
		    /* TODO: check extra bit in value reference whether tunable */     \
     		/*if (comp->mStatus == modelInstantiated || "tunable") {*/         \
			if (comp->parameters[ix] != value[i]) {                            \
			    comp->parameters[ix] = value[i];                               \
                modified = FMITrue;                                            \
				if (comp->istruct) comp->istruct->mParametersNr++;			   \
			}                                                                  \
			/*} else {*/                                                       \
            /*    allowed = fmiFalse;*/                                        \
			/*}*/															   \
			break;                                                             \
        case dsDerivative:                                                     \
		if (comp->mStatus == modelInstantiated) {                              \
                if (comp->derivatives[ix] != value[i]) {                       \
			       comp->derivatives[ix] = value[i];                           \
                   modified = FMITrue;                                         \
				}                                                              \
			} else {                                                           \
                allowed = FMIFalse;                                            \
			}                                                                  \
			break;                                                             \
        case dsOutput:                                                         \
     		if (comp->mStatus == modelInstantiated) {                          \
                if (comp->outputs[ix] != value[i]) {                           \
				   comp->outputs[ix] = value[i];                               \
                   modified = FMITrue;                                         \
				}                                                              \
			} else {                                                           \
                allowed = FMIFalse;                                            \
			}                                                                  \
			break;                                                             \
		case dsDState: /*dState */                                             \
		    if (comp->dStates[ix] != value[i]) {                               \
				comp->dStates[ix] = value[i];                                  \
                modified = FMITrue;                                            \
		    }                                                                  \
			break;                                                             \
		case dsPrevious: /*PreviousVar*/                                       \
			if (comp->dStates[ix] != value[i]) {                               \
				comp->dStates[ix] = value[i]; /*Set the state is correct*/     \
                modified = FMITrue;                                            \
		    }                                                                  \
			break;                                                             \
		case dsParameter2:                                                     \
        case dsInput2:                                                         \
			allowed = FMIFalse;                                                \
            break;                                                             \
		default:                                                               \
	        util_logger(comp, comp->instanceName, FMIWarning, "",              \
			       "fmiSet"#label": cannot set #"#vr_label"%u#  ", r);         \
            return FMIWarning;                                                 \
		}                                                                      \
                                                                               \
		if (allowed == FMIFalse) {                                             \
			util_logger(comp, comp->instanceName, FMIWarning, "",              \
			       "fmiSet"#label": may not change #"#vr_label"%u# at this "   \
			       "stage, setting of variable ignored", r);                   \
			return FMIWarning;                                                 \
		}                                                                      \
		util_logger(comp, comp->instanceName, FMIOK, "",                       \
		"fmiSet"#label": #"#vr_label"%u# = %g", r, (double) value[i]);         \
	}                                                                          \
                                                                               \
    if (modified == FMITrue) {                                                 \
   	   comp->icall = iDemandStart;                                             \
	   comp->valWasSet = 1;                                                    \
	   comp->recalJacobian = 1;                                                \
	}                                                                          \
	return FMIOK                                                               

/* ---------------------------------------------------------------------- */


DYMOLA_STATIC FMIStatus fmiSetReal_(FMIComponent c, const FMIValueReference vr[], size_t nvr, const FMIReal value[])
{
	FMI_SET(Real, r, c, vr, nvr, value);
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSetInteger_(FMIComponent c, const FMIValueReference vr[], size_t nvr, const FMIInteger value[])
{
	FMI_SET(Integer, i, c, vr, nvr, value);
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSetBoolean_(FMIComponent c, const FMIValueReference vr[], size_t nvr, const FMIBoolean value[])
{
	FMI_SET(Boolean, b, c, vr, nvr, value);
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSetString_(FMIComponent c, const FMIValueReference vr[], size_t nvr, const FMIString  value[])
{
#ifdef FMI_2
	static FMIString label = "fmi2SetString";
#else
	static FMIString label = "fmiSetString";
#endif
	Component* comp = (Component*) c;
	size_t i; 
	FMIBoolean allowed = FMITrue; 
	FMIBoolean modified = FMIFalse; 
	for (i = 0; i < nvr; i++) {
		size_t len;
		const FMIValueReference r = vr[i];
		int ix = FMI_INDEX(r);
		switch (FMI_CATEGORY(r)) { 
		case dsStringParameter:
			len=strlen(value[i]);
			if (len>MAX_STRING_SIZE) len=MAX_STRING_SIZE;
			memcpy((comp->sParameters)[ix], value[i], len+1);
			comp->sParameters[ix][MAX_STRING_SIZE]='\0';
			if (comp->istruct) comp->istruct->mParametersNr++;
			break;
		default:
			util_logger(comp, comp->instanceName, FMIWarning, "",
				"%s: cannot set #s%u#  ",label, r);
			return FMIWarning;
		}
		if (allowed == FMIFalse) {
			util_logger(comp, comp->instanceName, FMIWarning, "",
				"%s: may not change #s%u# at this stage",label, r);
			return FMIWarning;
		}
		util_logger(comp, comp->instanceName, FMIOK, "",
			"%s: #s%u# = %s",label, r, (FMIString) value[i]);
	}
	if (modified == FMITrue) {
		comp->icall = iDemandStart;
		comp->valWasSet = 1;
		comp->recalJacobian = 1;
	}
	return FMIOK;
}

#ifdef FMI_2
DYMOLA_STATIC_IMPORT size_t dyn_allowMultipleInstances;
DYMOLA_STATIC void DYNInitializeDid(struct DYNInstanceData*did_);

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC void getDelayStruct(struct DYNInstanceData* did_, delayStruct** del, size_t* nbrDel);

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiFreeFMUstate_(FMIComponent c, FMIFMUstate* FMUstate)
{

	static FMIString label = "fmi2FreeFMUstate";
	Component* comp = (Component*) c;
	Component* target;
	FMICallbackFreeMemory freeMemory;
	int i;

	if (FMUstate == NULL || *FMUstate == NULL) {
		return FMIOK;
	}
	target = (Component*) *FMUstate;

	/* first handle part common for both Model exchange and co-simulation */
	freeMemory = comp->functions->freeMemory;
	freeMemory(target->states);
	freeMemory(target->oldStates);
	freeMemory(target->derivatives);
	freeMemory(target->parameters);
	freeMemory(target->inputs);
	freeMemory(target->outputs);
	freeMemory(target->auxiliary);
	freeMemory(target->crossingFunctions);
	freeMemory(target->statesNominal);
	freeMemory(target->dStates);
	freeMemory(target->previousVars);
	for(i = (int) comp->nSPar-1; i >=0; --i){
		freeMemory( (target->sParameters)[i]);
	}
	freeMemory(target->sParameters);
	freeMemory(target->dstruct);
	freeMemory(target->istruct);
	if(target->did){
		delayStruct* del;
		size_t ndel;
		getDelayStruct(target->did,&del,&ndel);
		freeDelay(del, ndel);
	}
	freeMemory(target->did);
#if defined(FMI_2) &&! defined(NO_FILE)
	freeMemory(target->serializedDelayData);
#endif
	/* then handle co-simulation specific part */
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	if (comp->isCoSim && !comp->istruct->mInlineIntegration) {
		integration_free_state(c, target);
	}
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */
	freeMemory(*FMUstate);
	*FMUstate = NULL;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	return FMIOK;
}


DYMOLA_STATIC FMIStatus fmiGetFMUstate_(FMIComponent c, FMIFMUstate* FMUstate)
{
	static FMIString label = "fmi2GetFMUstate";
	Component* source = (Component*) c;
	Component* target;
	FMIStatus status = FMIOK;

	/* first handle part common for both Model exchange and co-simulation */

	/* TODO support for many Strings */
	int freeIndex = 0;
	FMICallbackAllocateMemory allocateMemory = source->functions->allocateMemory;
	if(source->storeResult){
		util_logger(source, source->instanceName, FMIWarning, "","%s failed, FMU uses internal result generation; this is not possible to combine with %s",label,label); 
		return FMIWarning;
	}
	util_logger(source, source->instanceName, FMIOK, "", label);

	if (*FMUstate == NULL) {
		FMIStatus status = allocateFMUState(FMUstate, source);
		if (status != FMIOK) {
			return status;
		}
	}

	{
		/*Check tat del is allocated to avoid messy problems later*/
		delayStruct * del =NULL;
		size_t nDel;
		extern int Buffersize;
		getDelayStruct(source->did, &del, &nDel);
		if(del[0].nx == 0)
			allocDelayBuffers(del, nDel, Buffersize);
	}
	target = (Component*) *FMUstate;
	{
		int ret;
		switch (ret = copyVariables(source, target, source->functions)){
			case 0:
				break;
			case 1:
				util_logger(source, source->instanceName, FMIError, "","%s failed, out of memory",label); 
				return util_error(source);
			case 2:
				util_logger(source, source->instanceName, FMIError, "","%s failed, internal mismach when copying variables",label); 
				return util_error(source);
			default:
				util_logger(source, source->instanceName, FMIError, "","%s failed, unhandeld internal error code %d",label,ret); 
				return util_error(source);
		}		
	}

	/* then handle co-simulation specific part */
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	if (source->isCoSim && !source->istruct->mInlineIntegration) {
		status = integration_get_state(source, target);
		if (status == FMIOK) {
			target->allocDone = 1;
			return FMIOK;
		} else {
			util_logger(c, source->instanceName, FMIError, "", "%s failed",label);
			return util_error(source);
		}
	}
#endif

	target->allocDone = 1;
	return FMIOK;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSetFMUstate_(FMIComponent c, FMIFMUstate FMUstate)
{
	static FMIString label = "fmi2SetFMUstate";
	Component* target = (Component*) c;
	Component* source;
	/* first handle part common for both Model exchange and co-simulation */
	if(target->storeResult){
		util_logger(target, target->instanceName, FMIWarning, "","%s failed, FMU uses internal result generation; this is not possible to combine with %s",label,label); 
		return FMIWarning;
	}
	if (FMUstate == NULL) {
		util_logger(target, target->instanceName, FMIWarning, "", "%s: FMUstate == NULL",label);
		return FMIWarning;
	}
	source = (Component*) FMUstate;
	assert(source->allocDone);
	/* set state vectors, derivatives, etc */
	{
	  int ret;
	  switch (ret = copyVariables(source, target, target->functions)){
		  case 0:
			  break;
		  case 1:
			  util_logger(source, source->instanceName, FMIError, "","%s failed, out of memory",label); 
			   return util_error(source);
		  case 2:
			  util_logger(source, source->instanceName, FMIError, "","%s failed, internal mismach when copying variables",label); 
			  return util_error(source);
		  default:
			  util_logger(source, source->instanceName, FMIError, "","%s failed, unhandeld internal error code %d",label,ret); 
			  return util_error(source);
	  }
  }

	/* then handle co-simulation specific part */
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	if (target->isCoSim && !target->istruct->mInlineIntegration) {
		return integration_set_state(source, target);
	}
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */

	util_logger(target, target->instanceName, FMIOK, "", "%s", label);
	return FMIOK;
}



/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSerializedFMUstateSize_(FMIComponent c, FMIFMUstate FMUstate, size_t *size)
{
	static FMIString label = "fmi2SerializedFMUstateSize";
	Component* comp = (Component*) c;
	static size_t sizeRequired = 0;
	FMIStatus status = FMIOK;

	
	if(comp->storeResult){
		util_logger(comp, comp->instanceName, FMIWarning, "","%s failed, FMU uses internal result generation; this is not possible to combine with %s",label,label); 
		return FMIWarning;
	}
#if !defined(NO_FILE)
	/* verify input */
	if (FMUstate == NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: FMUstate == NULL",label);
		return FMIWarning;
	}

	if (size == NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: size == NULL",label);
		return FMIWarning;
	}

	/* cannot vary during session, so only needed to determine once */
	if (sizeRequired == 0) {
		tpl_node* tn = NULL;
		delayStruct* del;
		size_t ndel, delayBuffSize;
		Component* state = (Component*) FMUstate;
		getDelayStruct(state->did, &del, &ndel);
		delayBuffSize = del[0].nx*2;
		if(!state->serializedDelayData){
			state->serializedDelayData = (double*) comp->functions->allocateMemory(ndel*delayBuffSize*2,sizeof(double));
			if(!state->serializedDelayData){
				util_logger(comp, comp->instanceName, FMIError, "", "%s: out of memory",label);
				return FMIError;
			}
		}
		/* need to setup tpl to figure out required size */
		tn = createTplMap(FMUstate, comp->tplDidBin);
		if (tn == NULL) {
			return FMIWarning;
		}

		if (tpl_pack(tn, 0) != 0) {
			util_logger(comp, comp->instanceName, FMIWarning, "", "%s: tpl_pack failed",label);
			status = FMIWarning;
		} else {
			/* fetch required size */
			if (tpl_dump(tn, TPL_GETSIZE, &sizeRequired) != 0) {
				util_logger(comp, comp->instanceName, FMIWarning, "", "%s: tpl_dump failed",label);
				status = FMIWarning;
			}
		}
		tpl_free(tn);
		comp->functions->freeMemory(state->serializedDelayData);
		state->serializedDelayData = NULL;
	}

	*size = sizeRequired;
#else
	util_logger(comp, comp->instanceName, FMIWarning, "", "%s: FMU is compiled with flag NO_FILE indicating that the running system does not have a file system,\r\n use fmi2Get/SetFMUstate instead",label);
	status = FMIWarning;
#endif
	return status;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiSerializeFMUstate_(FMIComponent c,
											  FMIFMUstate FMUstate,
											  FMIByte* serializedState,
											  size_t size)
{
	static FMIString label = "fmi2SerializeFMUstate";
	Component* comp = (Component*) c;
	Component* state = (Component*) FMUstate;
	FMIStatus status = FMIOK;
	delayStruct * del =NULL;
	size_t delayBuffSize, nDel, i;

#if !defined(NO_FILE)
	tpl_node *tn;
	if(comp->storeResult){
		util_logger(comp, comp->instanceName, FMIWarning, "","%s failed, FMU uses internal result generation; this is not possible to combine with %s",label,label); 
		return FMIWarning;
	}
	/* verify input */
	if (FMUstate == NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: FMUstate == NULL",label);
		return FMIWarning;
	}

	if (serializedState == NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: serializedState == NULL",label);
		return FMIWarning;
	}
	getDelayStruct(state->did, &del, &nDel);
	delayBuffSize = (size_t) del[0].nx;
	
	if(!state->serializedDelayData){
		state->serializedDelayData = (double*) comp->functions->allocateMemory(nDel*delayBuffSize*2,sizeof(double));
		if(!state->serializedDelayData){
			util_logger(comp, comp->instanceName, FMIError, "", "%s: out of memory",label);
			return FMIError;
		}
	}

	for(i = 0; i< nDel; ++i){
		memcpy(state->serializedDelayData+i*delayBuffSize*2,del[i].x,delayBuffSize*2);
	}
	/* setup tpl */
	tn = createTplMap(FMUstate, comp->tplDidBin);
	if (tn == NULL) {
		return FMIWarning;
	}

	/* save state */
	if (tpl_pack(tn, 0) != 0) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: tpl_pack failed",label);
		status = FMIWarning;
	} else {
		/* dump to target array */
		if (tpl_dump(tn, TPL_MEM|TPL_PREALLOCD, serializedState, size) != 0) {
			util_logger(comp, comp->instanceName, FMIWarning, "", "%s: tpl_dump failed",label);
			status = FMIWarning;
		}
	}
	tpl_free(tn);
	comp->functions->freeMemory(state->serializedDelayData);
	state->serializedDelayData = NULL;
#else
	util_logger(comp, comp->instanceName, FMIWarning, "", "%s: FMU is compiled with flag NO_FILE indicating that the running system does not have a file system,\r\n use fmi2Get/SetFMUstate instead",label);
	status = FMIWarning;
#endif
	return status;
}
#define STATIC_TMP_ALLOC 128
/* ---------------------------------------------------------------------- */
DYMOLA_STATIC FMIStatus fmiDeSerializeFMUstate_(FMIComponent c, 
												const FMIByte serializedState[],
												size_t size,
												FMIFMUstate* FMUstate)
{
	static FMIString label = "fmi2SerializeFMUstate";
	Component* comp = (Component*) c;
	FMIStatus status = FMIOK;
#if !defined(NO_FILE)
	tpl_node *tn;
	Component* state;
	delayStruct * del = NULL;
	size_t delayBuffSize, nDel, i;
	double ** tmpDelayBuffers = NULL;
	double * tmpDelayBuffersStatic[STATIC_TMP_ALLOC] = {0};
	/* verify input */
	if(comp->storeResult){
		util_logger(comp, comp->instanceName, FMIWarning, "","%s failed, FMU uses internal result generation; this is not possible to combine with %s",label,label); 
		return FMIWarning;
	}
	if (serializedState == NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: serializedState == NULL",label);
		return FMIWarning;
	}

	if (FMUstate == NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: FMUstate == NULL",label);
		return FMIWarning;
	}

	if(*FMUstate==NULL){ /* setup state target */
		status = allocateFMUState(FMUstate, comp);
		if (status != FMIOK) {
			return status;
		}
	}
	state = (Component*) *FMUstate;
	state->allocDone = 1;
	getDelayStruct(state->did, &del, &nDel);

	delayBuffSize = (size_t) del[0].nx;
	if(nDel > STATIC_TMP_ALLOC){
		tmpDelayBuffers = (double**) comp->functions->allocateMemory(nDel,sizeof(double*));
		if(!tmpDelayBuffers){
			util_logger(comp, comp->instanceName, FMIError, "", "%s: out of memory",label);
			return FMIError;
		}
	}else{
		tmpDelayBuffers = tmpDelayBuffersStatic;
	}
	

	for(i = 0; i < nDel; ++i){
		tmpDelayBuffers[i] = del[i].x;
	}
	if(!state->serializedDelayData){
		state->serializedDelayData = (double*) comp->functions->allocateMemory(nDel*delayBuffSize*2,sizeof(double));
		if(!state->serializedDelayData){
			util_logger(comp, comp->instanceName, FMIError, "", "%s: out of memory",label);
			return FMIError;
		}
	}

	/* setup tpl*/
	tn = createTplMap(state, comp->tplDidBin);
	if (tn == NULL) {
		return FMIWarning;
	}

	/* load from source array */
	if (tpl_load(tn, TPL_MEM, serializedState, size) != 0) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: tpl_load failed",label);
		status = FMIWarning;
	} else {
		/* restore state */
		size_t j;
		/* first free old string parameters memory since tpl allocates new for strings (and binary data) */
		for (j = 0; j< state->nSPar; j++) {
			tplFree(state->sParameters[j]);
		}

		if (tpl_unpack(tn, 0) < 0) {
			util_logger(comp, comp->instanceName, FMIWarning, "", "%s: tpl_unpack failed",label);
			status = FMIWarning;
		} else {
			/* restore did */
			memcpy(state->did, comp->tplDidBin->addr, comp->tplDidBin->sz);
            tplFree(comp->tplDidBin->addr);
			comp->tplDidBin->addr = NULL;
			for(i = 0; i< nDel; ++i){
				del[i].x = tmpDelayBuffers[i];
				memcpy(del[i].x,state->serializedDelayData +i*delayBuffSize*2 ,delayBuffSize*2*sizeof(double));
				del[i].y = del[i].x+delayBuffSize;

			}
		}
	}
	tpl_free(tn);
	comp->functions->freeMemory(state->serializedDelayData);
	state->serializedDelayData = NULL;
	if(nDel > STATIC_TMP_ALLOC){
		comp->functions->freeMemory(tmpDelayBuffers);
		tmpDelayBuffers = NULL;
	}
#else
	util_logger(comp, comp->instanceName, FMIWarning, "", "%s: FMU is compiled with flag NO_FILE indicating that the running system does not have a file system,\r\n use fmi2Get/SetFMUstate instead",label);
	status = FMIWarning;
#endif
	return status;
}

/* ---------------------------------------------------------------------- */
DYMOLA_STATIC void SetDymolaJacobianPointers(struct DYNInstanceData*did_, double * QJacobian_,double * QBJacobian_,double * QCJacobian_,double * QDJacobian_,int QJacobianN_,
	int QJacobianNU_,int QJacobianNY_,double * QJacobianSparse_,int * QJacobianSparseR_,int * QJacobianSparseC_,int QJacobianNZ_);
DYMOLA_STATIC void SetDymolaEnforceWhen(struct DYNInstanceData*did_, int val);
DYMOLA_STATIC FMIStatus fmiGetDirectionalDerivative_(FMIComponent c,
													 const FMIValueReference z_ref[],
													 size_t nz,
													 const FMIValueReference v_ref[],
													 size_t nv,
													 const FMIReal dv[],
													 FMIReal dz[])
{
	static FMIString label = "fmi2GetDirectionalDerivative";

	size_t i;
	size_t j;
	Component* comp = (Component*) c;
	FMIStatus status = FMIOK;

	FMICallbackAllocateMemory allocateMemory = comp->functions->allocateMemory;
	FMICallbackFreeMemory freeMemory = comp->functions->freeMemory;
	JacobianData* jacData = &comp->jacData;
	extern int QJacobianDefined_;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s", label);
	LOG(comp, FMIOK, label);

	for (i = 0; i < nz; i++) {
		dz[i] = 0;
	}
	
	/*  analytic Jacobian available ? */
	if (QJacobianDefined_ && (comp->mStatus != modelInstantiated ||
		comp->mStatus != modelInitializationMode) && !comp->AdvancedDiscreteStates ) {
			/*Analytical Jacobians are only valid after intialization*/
		int nx, nx2, nu, ny, nw, np, nrel, ncons, dae;
		int nA, nB, nC, nD;
		
		GetDimensions(&nx, &nx2, &nu, &ny, &nw, &np, &nrel, &ncons, &dae);

		nA = nx * nx;
		nB = nx * nu;
		nC = ny * nx;
		nD = ny * nu;

		/* avoid re-allocation on each call */
		if (jacData->nJacA < nA || jacData->jacA == NULL) {
			freeMemory(jacData->jacA);
			jacData->jacA = (double*) allocateMemory(nA+1, sizeof(double));
		}
		if (jacData->nJacB < nB || jacData->jacB == NULL) {
			freeMemory(jacData->jacB);
			jacData->jacB = (double*) allocateMemory(nB+1, sizeof(double));
		}
		if (jacData->nJacC < nC || jacData->jacC == NULL) {
			freeMemory(jacData->jacC);
			jacData->jacC = (double*) allocateMemory(nC+1, sizeof(double));
		}
		if (jacData->nJacD < nD || jacData->jacD == NULL) {
			freeMemory(jacData->jacD);
			jacData->jacD = (double*) allocateMemory(nD+1, sizeof(double));
		}

		if (jacData->jacA == NULL || jacData->jacB == NULL || jacData->jacC== NULL || jacData->jacD == NULL) {
			util_logger(comp, comp->instanceName, FMIError, "", "%s: memory allocation failed", label);
			status = FMIError;
			goto done1;
		}

		jacData->nJacA = nA;
		jacData->nJacB = nB;
		jacData->nJacC = nC;
		jacData->nJacD = nD;		


		if(comp->icall < iDemandDerivative || comp->recalJacobian){
			SetDymolaJacobianPointers(comp->did, jacData->jacA, jacData->jacB, jacData->jacC, jacData->jacD, nx, nu, ny, 0, 0,0,0);
			if (util_refresh_cache(comp, iDemandDerivative, label, NULL)) {
				status = FMIError;
				goto done1;
			}
			comp->recalJacobian = 0;
		}



		for (j = 0; j < nv; j++) {
			/* skip for seed == 0 */
			if (dv[j] != 0) {
				FMIBoolean vIsState = FMITrue;
				int v_ix = FMI_INDEX(v_ref[j]);

				/* determine type for v reference*/
				dsCategory v_cat = FMI_CATEGORY(v_ref[j]);
				switch(v_cat) {
				case dsState:
					assert(v_ix < nx);
					break;
				case dsInput:
					assert(v_ix < nu);
					vIsState = FMIFalse;
					break;
				default:
					util_logger(comp, comp->instanceName, FMIError, "",
						"%s: v_ref[%d] refers neither to state nor input", label, i);
					status = FMIError;
					goto done1;
				}

				/* Compute column j */
				for (i = 0; i < nz; i++) {
					/* figure out which of A, B, C and D matrix to fetch from */
					dsCategory z_cat = FMI_CATEGORY(z_ref[i]);
					int z_ix = FMI_INDEX(z_ref[i]);
					switch (z_cat) {
					case dsDerivative:
						assert(z_ix < nx);
						if (vIsState == FMITrue) {
							dz[i] += dv[j] * jacData->jacA[z_ix + v_ix * nx];
						} else {
							dz[i] += dv[j] * jacData->jacB[z_ix + v_ix * nx];
						}
						break;
					case dsOutput:
						assert(z_ix < ny);
						if (vIsState == FMITrue) {
							dz[i] += dv[j] * jacData->jacC[z_ix + v_ix * ny];
						} else {
							dz[i] += dv[j] * jacData->jacD[z_ix + v_ix * ny];
						}
						break;
					default:
						util_logger(comp, comp->instanceName, FMIError, "",
							"%s: z_ref[%d] refers neither to state derivative nor output", label, i);
						status = FMIError;
						goto done1;
					}
				}
			}
		}

done1:
		SetDymolaJacobianPointers(comp->did, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0);
		HANDLE_STATUS_RETURN(status);
	}

	/*  analytic Jacobian not available */
	{

		double *jacV;
		double *jacVTmp1;
		double *jacVTmp2;
		double *jacZ;
		double *jacZTmp1;
		double *jacZTmp2;
		double h;
		FMIBoolean success1;
		FMIBoolean success2;
		comp->istruct->mInJacobian=1;
		/* avoid re-allocation on each call */
		if (jacData->nJacV < nv) {
			freeMemory(jacData->jacV);
			freeMemory(jacData->jacVTmp1);
			freeMemory(jacData->jacVTmp2);
			jacData->jacV = (double*) allocateMemory(nv, sizeof(double));
			jacData->jacVTmp1 = (double*) allocateMemory(nv, sizeof(double));
			jacData->jacVTmp2 = (double*) allocateMemory(nv, sizeof(double));
		}
		if (jacData->nJacZ < nz) {
			freeMemory(jacData->jacZ);
			freeMemory(jacData->jacZTmp1);
			freeMemory(jacData->jacZTmp2);
			jacData->jacZ = (double*) allocateMemory(nz, sizeof(double));
			jacData->jacZTmp1 = (double*) allocateMemory(nz, sizeof(double));
			jacData->jacZTmp2 = (double*) allocateMemory(nz, sizeof(double));
		}

		if (jacData->jacV == NULL || jacData->jacVTmp1 == NULL || jacData->jacVTmp2 == NULL || 
			jacData->jacZ == NULL || jacData->jacZTmp1 == NULL || jacData->jacZTmp2 == NULL) {
			util_logger(comp, comp->instanceName, FMIError, "", "%s: memory allocation failed", label);
			status = FMIError;
			goto done2;
		}

		jacData->nJacV = nv;
		jacData->nJacZ = nz;

		/* save current v_values for later restoring */

		if( (status = fmiGetReal_(c, v_ref, nv, jacData->jacV)) != FMIOK ||
			(status = fmiGetReal_(c, z_ref, nz, jacData->jacZ)) != FMIOK ){
			goto done2;
		}
		if(comp->AdvancedDiscreteStates){
			if((status = fmiGetFMUstate_(c,&jacData->stateStore)) != FMIOK ){
				goto done2;
			}
			SetDymolaEnforceWhen(comp->did,1);
			comp->icall = 0;
		}	
		jacV = jacData->jacV;
		jacVTmp1 = jacData->jacVTmp1;
		jacVTmp2 = jacData->jacVTmp2;
		jacZ = jacData->jacZ;
		jacZTmp1 = jacData->jacZTmp1;
		jacZTmp2 = jacData->jacZTmp2;

		h=1e6;
		for(i=0; i < nv; ++i ){
			if( dv[i] != 0 ){
				double temp = ( fabs(jacV[i]) + 1.0 ) * 1.0e-5 / fabs(dv[i]);
				if( temp < h )
					h=temp;
			}
		}

		/* perturb each state/continuous input */
		for (i = 0; i < nv; i++) {
			/* skip for seed == 0 */
			if (dv[i] != 0) {
				jacVTmp1[i] = jacV[i] + h*dv[i];
				jacVTmp2[i] = jacV[i] - h*dv[i];
			}else{
				jacVTmp1[i]=jacVTmp2[i]=jacV[i];
				
			}
		}
		if ((status = fmiSetReal_(c, v_ref, nv, jacVTmp1)) != FMIOK ) {
				goto done2;
		}
		comp->enforceRefresh = FMITrue;
		status = fmiGetReal_(c, z_ref, nz, jacZTmp1);
		comp->enforceRefresh = FMIFalse;
		if(comp->AdvancedDiscreteStates){
			if( (status = fmiSetFMUstate_(c,jacData->stateStore)) != FMIOK ){
				goto done2;
			}
			SetDymolaEnforceWhen(comp->did,1);
		}
		success1 = status == FMIOK;
		if ((status = fmiSetReal_(c, v_ref, nv, jacVTmp2)) != FMIOK ) {
				goto done2;
		}
		comp->enforceRefresh = FMITrue;
		status = fmiGetReal_(c, z_ref, nz, jacZTmp2);
		comp->enforceRefresh = FMIFalse;
		success2 = status == FMIOK;

		if(success1 && success2){
			/*Central Difference*/
			for (i = 0; i < nz; i++) {
				dz[i] =  (FMIReal) (jacZTmp1[i] - jacZTmp2[i]) / (2.0 * h);
			}
		}else if(success1){
			/*Forwad Difference*/
			for (i = 0; i < nz; i++) {
				dz[i] =  (FMIReal) (jacZTmp1[i] - jacZ[i]) / h;
			}
		}else if(success2){
			/*Backward Difference*/
			for (i = 0; i < nz; i++) {
				dz[i] =  (FMIReal) ( jacZ[i]- jacZTmp2[i]) / h;
			}
		}else{
			goto done2;
		}
		/* Restore */
		if(comp->AdvancedDiscreteStates){
			if( (status = fmiSetFMUstate_(c,jacData->stateStore)) != FMIOK ){
				goto done2;
			}
			SetDymolaEnforceWhen(comp->did,0);
		}else if ((status = fmiSetReal_(c, v_ref, 1, jacV)) != FMIOK) {
			goto done2;
		}

done2:
		comp->istruct->mInJacobian=0;
		HANDLE_STATUS_RETURN(status);
	}
}
/* Wrapper functions for merging CS and ME functions with fmi 2 RC1 */

DYMOLA_STATIC FMIComponent fmiInstantiate_(FMIString instanceName, FMIType fmuType, FMIString fmuGUID, FMIString fmuResourceLocation, const FMICallbackFunctions* functions, FMIBoolean visible, FMIBoolean loggingOn){

	Component* comp;
	if(fmuType==FMICoSimulation){
		comp = (Component*) fmiInstantiateSlave_(instanceName, fmuGUID, fmuResourceLocation, functions, visible, loggingOn);
		if(comp)
			comp->isCoSim = FMITrue;
	}else if(fmuType==FMIModelExchange){
		comp = (Component*) fmiInstantiateModel_(instanceName, fmuGUID, fmuResourceLocation, functions, visible, loggingOn);
		if(comp)
			comp->isCoSim = FMIFalse;
	}else{
		return NULL;
	}
	return comp;
}

DYMOLA_STATIC void fmiFreeInstance_(FMIComponent c)
{
    fmiFreeModelInstance_(c);
}

DYMOLA_STATIC FMIStatus fmiSetupExperiment_(FMIComponent c,
											FMIBoolean relativeToleranceDefined,
											FMIReal relativeTolerance,
											FMIReal tStart,
											FMIBoolean tStopDefined,
											FMIReal tStop)
{
	/* TODO fix warning of unsuported features for CS/ME now instead of at initialization */
	static FMIString label = "fmi2SetupExperiment";
	Component* comp = (Component*) c;
	comp->tStart = tStart;
	comp->StopTimeDefined = tStopDefined;
	comp->tStop = tStop;
	if(relativeToleranceDefined && !comp->isCoSim ){
		util_logger(comp, comp->instanceName, FMIWarning, "", "%s: tolerance control not supported for fmuType fmi2ModelExchange, setting toleranceDefined to fmi2False",label);
		comp->relativeToleranceDefined = FMIFalse;
		comp->relativeTolerance =0;
	}else{
		comp->relativeToleranceDefined = relativeToleranceDefined;
		comp->relativeTolerance = relativeTolerance;
	}
	comp->time = tStart;
	comp->icall = iDemandStart;
	util_logger(comp, comp->instanceName, FMIOK, "", "%s: startTime is set to %g",label, tStart);
	return FMIOK;
}
DYMOLA_STATIC FMIStatus fmiEnterInitializationMode_(FMIComponent c)
{
	Component* comp = (Component*) c;
	if(comp->isCoSim){
		return fmiEnterSlaveInitializationMode_(comp, comp->relativeTolerance, comp->tStart, comp->StopTimeDefined, comp->tStop);
	}else if(!comp->isCoSim){
		return fmiEnterModelInitializationMode_(comp, FMIFalse, 0);
	}
	return util_error(comp);
}
DYMOLA_STATIC FMIStatus fmiExitInitializationMode_(FMIComponent c)
{
	Component* comp = (Component*) c;
	if(comp->isCoSim){
		return fmiExitSlaveInitializationMode_(comp);
	}else if(!comp->isCoSim){
		return fmiExitModelInitializationMode_(comp);
	}
	return util_error(comp);
}

DYMOLA_STATIC FMIStatus fmiTerminate_(FMIComponent c)
{
	Component* comp = (Component*) c;
	if(comp->isCoSim){
		return fmiTerminateSlave_(comp);
	}else if(!comp->isCoSim){
		return fmiTerminateModel_(comp);
	}
	return util_error(comp);
}

DYMOLA_STATIC FMIStatus fmiReset_(FMIComponent c)
{
	return fmiResetSlave_(c);
}

/* ----------------- local function definitions ----------------- */

/* -------------------------------------------------------------- */
static FMIStatus allocateFMUState(FMIFMUstate* FMUstate, Component* source)
{
	Component* target;
	void* freeList[128];
	int freeIndex = 0;
	FMICallbackAllocateMemory allocateMemory = source->functions->allocateMemory;
	size_t i;

	ALLOC_AND_CHECK(*FMUstate, 1, sizeof(Component));
	target = (Component*)*FMUstate;
	target->iData = NULL;
	/* set to true when dsmodel data also allocated (which is possibly obsolete),
	   outside of this function */
	target->allocDone = 0;

	/* get state vectors, derivatives, etc */
	target->nStates = source->nStates;
	target->nPar = source->nPar;
	target->nIn = source->nIn;
	target->nOut = source->nOut;
	target->nAux = source->nAux;
	target->nCross = source->nCross;
	target->nSPar = source->nSPar;
	target->nDStates = source->nDStates;
	target->nPrevious = source->nPrevious;

	ALLOC_AND_CHECK(target->states, source->nStates + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->oldStates, source->nStates + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->derivatives, source->nStates + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->parameters, source->nPar + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->inputs, source->nIn + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->outputs, source->nOut + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->auxiliary, source->nAux + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->crossingFunctions, source->nCross + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->statesNominal, source->nStates + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->sParameters, source->nSPar + 1, sizeof(FMIChar*));
	ALLOC_AND_CHECK(target->dStates, source->nDStates + 1, sizeof(FMIReal));
	ALLOC_AND_CHECK(target->previousVars, source->nPrevious + 1, sizeof(FMIReal));
	for (i = 0; i < target->nSPar; ++i) {
		ALLOC_AND_CHECK(target->sParameters[i], MAX_STRING_SIZE + 1, sizeof(FMIChar));
	}
	target->sParameters[target->nSPar] = NULL;

	ALLOC_AND_CHECK(target->dstruct, 1, sizeof(struct BasicDDymosimStruct));
	ALLOC_AND_CHECK(target->istruct, 1, sizeof(struct BasicIDymosimStruct));

	if (dyn_allowMultipleInstances) {

		ALLOC_AND_CHECK(target->did, 1, dyn_allowMultipleInstances);
		DYNInitializeDid(target->did);
	}
	else {
		target->did = NULL;
	}

	{
		delayStruct *del = NULL;
		size_t nDel;
		extern int Buffersize;
		getDelayStruct(target->did, &del, &nDel);
		allocDelayBuffers(del, nDel, Buffersize);
	}
	

#if defined(FMI_2) &&! defined(NO_FILE)
	target->serializedDelayData = NULL;
#endif

	return FMIOK;

mem_fail:
	{
		int i;
		util_logger(source, source->instanceName, FMIError, "", "memory allocation failed");
		for (i = freeIndex - 1; i >= 0; i--) {
			source->functions->freeMemory(freeList[i]);
		}
		*FMUstate = NULL;
		return util_error(source);
	}
}

/* -------------------------------------------------------------- */
#if !defined(NO_FILE)
static tpl_node* createTplMap(Component* comp, tpl_bin *tplDidBin)
{
	tpl_node* tn;
	delayStruct *del = NULL;
	size_t delayBufferDataSize, nDel;
	/* skipping const to avoid compiler warning when calling tpl_pack */
	char* TPL_STRUCTURE_STRING =
		"if"                      /* relativeToleranceDefined, relativeTolerance */
        "i"                       /* loggingOn */     
		"f#f#f#f#f#f#f#f#f#f#s#"  /* states, derivates etc */
		"fiiiiiiiiiiiUfi"         /* time, icall, mStatus etc */
		"S(fffff)S(iiiiiiiiiiiii)"  /* dstruct, istruct */
		"B"                       /* did */
		"f#"

#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
	/* TODO: Need to deal with Sundials data structures to handle co-simulation case */
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */
		;

	/* setup TPL hooks during first use */
	if (globalComponent != NULL) {
		static int tplhooks_setup = 0;
		if (!tplhooks_setup) {
			extern tpl_hook_t tpl_hook;
			tpl_hook.tpl_malloc = tplMalloc;
			tpl_hook.tpl_free = tplFree;
			tplhooks_setup = 1;
		}
	}

    /* setting addr and sz is only significant for serialization; for deserialziation
       tpl sets the values */
	tplDidBin->addr = comp->did;
	tplDidBin->sz = (uint32_t) dyn_allowMultipleInstances;

	getDelayStruct(comp->did,&del,&nDel);

	delayBufferDataSize = nDel*del[0].nx*2;
	/* add one to handle empty arrays (size 0 not allowed in tpl_map) */
	tn = tpl_map(TPL_STRUCTURE_STRING,
        &(comp->relativeToleranceDefined),
		&(comp->relativeTolerance),
 		&(comp->loggingOn),
		comp->states, comp->nStates + 1,
		comp->derivatives, comp->nStates + 1,
		comp->parameters, comp->nPar + 1,
		comp->inputs, comp->nIn + 1,
		comp->outputs, comp->nOut + 1,
		comp->auxiliary, comp->nAux + 1,
		comp->crossingFunctions, comp->nCross + 1,
		comp->statesNominal, comp->nStates + 1,
		comp->dStates, comp->nDStates + 1,
		comp->previousVars, comp->nPrevious + 1,
		comp->sParameters, comp->nSPar + 1,
		&(comp->time),
		&(comp->icall),
		&(comp->mStatus),
		&(comp->terminationByModel),
		&(comp->storeResult),
		&(comp->valWasSet),
		&(comp->eventIterRequired),
		&(comp->recalJacobian),
		&(comp->enforceRefresh),
		&(comp->hycosimInputEvent),
		&(comp->firstEventCall),
		&(comp->eventIterationOnGoing),
        &(comp->inlineStepCounter),
        &(comp->nextResultSampleTime),
		&(comp->AdvancedDiscreteStates),
		comp->dstruct,
		comp->istruct,
		tplDidBin,
		comp->serializedDelayData,delayBufferDataSize
#ifndef ONLY_INCLUDE_INLINE_INTEGRATION
		/* TODO: Need to deal with Sundials data structures to handle co-simulation case */
#endif /* ONLY_INCLUDE_INLINE_INTEGRATION */              
	);

	if (tn == NULL) {
		util_logger(comp, comp->instanceName, FMIWarning, "", "createTplMap: tpl_map returned NULL");
	}

	return tn;
}

/* -------------------------------------------------------------- */
static void *tplMalloc(size_t size)
{
	/* in case globalComponent no longer valid, use ordinary malloc as fallback */
	if (globalComponent == NULL) {
		return malloc(size);
	}
	return globalComponent->functions->allocateMemory(1, size);
}

/* -------------------------------------------------------------- */
static void tplFree(void* ptr)
{
	/* in case globalComponent no longer valid, use ordinary free as fallback */
	if (globalComponent == NULL) {
		free(ptr);
        return;
	}
	globalComponent->functions->freeMemory(ptr);
}
#endif
#endif /* FMI_2 */

/* -------------------------------------------------------------- */
static int getLargestIdemand(const FMIValueReference vr[], size_t nvr)
{
	int idemand = iDemandStart;
	size_t i;

	/* find biggest idemand among requested values */
	for (i = 0; i < nvr; i++) {
		const FMIValueReference r = vr[i];
		int id = FMI_IDEMAND(r);
		if (id > idemand) {
			idemand = id;
		}
	}
	return idemand;
}

#ifdef FMI_2
/* -------------------------------------------------------------- */
static int copyVariables(Component* source, Component* target, const FMICallbackFunctions* funcs)
{
  target->relativeToleranceDefined = source->relativeToleranceDefined;
  target->relativeTolerance = source->relativeTolerance;

  target->loggingOn = source->loggingOn;

  memcpy(target->states, source->states, source->nStates * sizeof(FMIReal));
  memcpy(target->derivatives, source->derivatives, source->nStates * sizeof(FMIReal));
  memcpy(target->parameters, source->parameters, source->nPar * sizeof(FMIReal));
  memcpy(target->inputs, source->inputs, source->nIn * sizeof(FMIReal));
  memcpy(target->outputs, source->outputs, source->nOut * sizeof(FMIReal));
  memcpy(target->auxiliary, source->auxiliary, source->nAux * sizeof(FMIReal));
  memcpy(target->crossingFunctions, source->crossingFunctions, source->nCross * sizeof(FMIReal));
  memcpy(target->statesNominal, source->statesNominal, source->nStates * sizeof(FMIReal));
  memcpy(target->dStates, source->dStates, source->nDStates * sizeof(FMIReal));
  memcpy(target->previousVars, source->previousVars, source->nPrevious * sizeof(FMIReal));
  {
    size_t i = 0;
    for(i = 0; i< target->nSPar; ++i) {
      memcpy(target->sParameters[i], source->sParameters[i], (MAX_STRING_SIZE+1) * sizeof(FMIChar));
			target->sParameters[i][MAX_STRING_SIZE]='\0';
    }
  }
  target->time = source->time;
  target->icall = source->icall;
  target->mStatus = source->mStatus;
  target->terminationByModel = source->terminationByModel;
  target->storeResult = source->storeResult;
  target->inlineStepCounter = source->inlineStepCounter;
  target->nextResultSampleTime = source->nextResultSampleTime;
  target->AdvancedDiscreteStates = source->AdvancedDiscreteStates;
  target->valWasSet = source->valWasSet;
  target->eventIterRequired = source->eventIterRequired;
  target->recalJacobian = source->recalJacobian;
  target->enforceRefresh = source->enforceRefresh;
  target->hycosimInputEvent = source->hycosimInputEvent;

  target->firstEventCall = source->firstEventCall;
  target->eventIterationOnGoing = source->eventIterationOnGoing;

  memcpy(target->dstruct, source->dstruct, sizeof(struct BasicDDymosimStruct));
  memcpy(target->istruct, source->istruct, sizeof(struct BasicIDymosimStruct));

  if(target->did && dyn_allowMultipleInstances && source->did){

	  delayStruct *srcDel = NULL, *trgDel = NULL;
	  size_t nSrcDel = 0, nTrgDel = 0, i = 0;
	  double ** trgTmpPtr = NULL;
	  double * trgTmpStatic[STATIC_TMP_ALLOC] = { 0 };
	  getDelayStruct(source->did, &srcDel, &nSrcDel);
	  getDelayStruct(target->did, &trgDel, &nTrgDel);
	  if (!srcDel || !trgDel || nSrcDel != nTrgDel)
		  return 2;

	  if(copyDelay(trgDel, srcDel, (int)nSrcDel))
		  return 1;

	  if (nSrcDel <= STATIC_TMP_ALLOC){
		  trgTmpPtr = trgTmpStatic;
	  }
	  else{
		  trgTmpPtr = (double**) funcs->allocateMemory(nSrcDel, sizeof(double*));
		  if (!trgTmpPtr)
			  return 1;
	  }

	  for (i = 0; i < nSrcDel; ++i){
		  trgTmpPtr[i] = trgDel[i].x;
	  }
	  memcpy(target->did, source->did, dyn_allowMultipleInstances);
	  for (i = 0; i < nSrcDel; ++i){
		  trgDel[i].x = trgTmpPtr[i]; 
		  trgDel[i].y = trgDel[i].x + trgDel[i].nx;
	  }
	  if(nSrcDel > STATIC_TMP_ALLOC){
		  funcs->freeMemory(trgTmpPtr);
		  trgTmpPtr = NULL;
	  }
  }
  return 0;
}
#undef STATIC_TMP_ALLOC
#endif /* FMI_2 */
