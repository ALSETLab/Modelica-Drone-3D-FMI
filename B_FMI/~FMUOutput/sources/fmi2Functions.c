#ifndef BUILDFMU
/* needed for source code export */
#include "conf.h"
#endif

#ifdef FMI_2
#include "fmiFunctions_.h"
#include "fmi2Functions_fwd.h"

/* This file contains wrappers for all FMI functions and is provided in
   the Dymola distribution instead of the actual implementation. This is
   necessary to avoid exposing the latter. */

DYMOLA_STATIC void __enableResultStoring(fmi2Component c);

/*Temp hack for directional derivatives of clocked systems*/
#ifdef FMI_CLOCKED_STATES
const int  fmiClockedStates = 1;
#else
const int  fmiClockedStates = 0;
#endif

/***************************************************
 Common Functions
****************************************************/

const char* fmi2GetTypesPlatform()
{
	return fmiGetTypesPlatform_();
}

/* ------------------------------------------------------ */
const char* fmi2GetVersion()
{
	return fmiGetVersion_();
}

/* ------------------------------------------------------ */
fmi2Status fmi2SetDebugLogging(fmi2Component c, fmi2Boolean loggingOn, size_t nCategories, const fmi2String categories[]) 
{
	return fmiSetDebugLogging_(c, loggingOn, nCategories, categories);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetReal(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, fmi2Real value[])
{
	return fmiGetReal_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetInteger(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, fmi2Integer value[])
{
	return fmiGetInteger_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetBoolean(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, fmi2Boolean value[])
{
	return fmiGetBoolean_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetString(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, fmi2String  value[])
{
	return fmiGetString_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SetReal(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, const fmi2Real value[])
{
	return fmiSetReal_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SetInteger(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, const fmi2Integer value[])
{
	return fmiSetInteger_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SetBoolean(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, const fmi2Boolean value[])
{
	return fmiSetBoolean_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SetString(fmi2Component c, const fmi2ValueReference vr[], size_t nvr, const fmi2String  value[])
{
	return fmiSetString_(c, vr, nvr, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetFMUstate(fmi2Component c, fmi2FMUstate* FMUstate)
{
	return fmiGetFMUstate_(c, FMUstate);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SetFMUstate(fmi2Component c, fmi2FMUstate FMUstate)
{
	return fmiSetFMUstate_(c, FMUstate);
}

/* ------------------------------------------------------ */
fmi2Status fmi2FreeFMUstate(fmi2Component c, fmi2FMUstate* FMUstate)
{
	return fmiFreeFMUstate_(c, FMUstate);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SerializedFMUstateSize(fmi2Component c, fmi2FMUstate FMUstate, size_t *size)
{
	return fmiSerializedFMUstateSize_(c, FMUstate, size);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SerializeFMUstate(fmi2Component c, fmi2FMUstate FMUstate, fmi2Byte serializedState[], size_t size)
{
	return fmiSerializeFMUstate_(c, FMUstate, serializedState, size);
}

/* ------------------------------------------------------ */
fmi2Status fmi2DeSerializeFMUstate(fmi2Component c, const fmi2Byte serializedState[], size_t size, fmi2FMUstate* FMUstate)
{
	return fmiDeSerializeFMUstate_(c, serializedState, size, FMUstate);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetDirectionalDerivative(fmi2Component c,
								   const fmi2ValueReference z_ref[],
								   size_t nz,
								   const fmi2ValueReference v_ref[],
								   size_t nv,
								   const fmi2Real dv[],
								   fmi2Real dz[])
{
	return fmiGetDirectionalDerivative_(c, z_ref, nz, v_ref, nv, dv, dz);
}

fmi2Component fmi2Instantiate(fmi2String instanceName,
						fmi2Type fmuType, 
						fmi2String fmuGUID, 
						fmi2String fmuResourceLocation, 
						const fmi2CallbackFunctions* functions, 
						fmi2Boolean visible, 
						fmi2Boolean loggingOn)
{
	fmi2Component comp = fmiInstantiate_(instanceName, fmuType, fmuGUID, fmuResourceLocation, functions, visible, loggingOn);
#ifndef FMU_SOURCE_CODE_EXPORT
	if (comp != NULL) {
		/* determine whether to store results or not */
#include "dsmodel_fmuconf.h"	
	}
#endif /* FMU_SOURCE_CODE_EXPORT */
	return comp;
}

void fmi2FreeInstance(fmi2Component c)
{
	fmiFreeInstance_(c);
}

fmi2Status fmi2SetupExperiment(fmi2Component c,
								fmi2Boolean relativeToleranceDefined,
								fmi2Real relativeTolerance,
								fmi2Real tStart,
								fmi2Boolean tStopDefined,
								fmi2Real tStop)
{
	return fmiSetupExperiment_(c, relativeToleranceDefined, relativeTolerance, tStart, tStopDefined, tStop);
}

fmi2Status fmi2EnterInitializationMode(fmi2Component c)
{
	return fmiEnterInitializationMode_(c);
}

fmi2Status fmi2ExitInitializationMode(fmi2Component c)
{
	return fmiExitInitializationMode_(c);
}

fmi2Status fmi2Terminate(fmi2Component c)
{
	return fmiTerminate_(c);
}

fmi2Status fmi2Reset(fmi2Component c)
{
	return fmiReset_(c);
}


/***************************************************
 Functions for FMI for Model Exchange
****************************************************/

#ifndef FMU_SKIP_MODEL_EXCHANGE


/* ------------------------------------------------------ */
fmi2Status fmi2SetTime(fmi2Component c, fmi2Real time)
{
	return fmiSetTime_(c, time);
}

/* ------------------------------------------------------ */
fmi2Status fmi2SetContinuousStates(fmi2Component c, const fmi2Real x[], size_t nx)
{
	return fmiSetContinuousStates_(c, x, nx);
}

/* ------------------------------------------------------ */
fmi2Status fmi2EnterEventMode(fmi2Component c)
{
	return fmiEnterEventMode_(c);
}

/* ------------------------------------------------------ */
fmi2Status fmi2NewDiscreteStates(fmi2Component c, fmi2EventInfo* eventInfo)
{
	return fmiNewDiscreteStates_(c, eventInfo);
}

/* ------------------------------------------------------ */
fmi2Status fmi2EnterContinuousTimeMode(fmi2Component c)
{
	return fmiEnterContinuousTimeMode_(c);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetNominalsOfContinuousStates(fmi2Component c, fmi2Real x_nominal[], size_t nx)
{
	return fmiGetNominalsOfContinuousStates_(c, x_nominal, nx);
}



/* ------------------------------------------------------ */
fmi2Status fmi2CompletedIntegratorStep(fmi2Component c,
                                     fmi2Boolean noSetFMUStatePriorToCurrentPoint,
                                     fmi2Boolean* enterEventMode,
                                     fmi2Boolean* terminateSimulation)
{
  return fmiCompletedIntegratorStep_(c, noSetFMUStatePriorToCurrentPoint, enterEventMode, terminateSimulation);
}


/* ------------------------------------------------------ */
fmi2Status fmi2GetDerivatives(fmi2Component c, fmi2Real derivatives[], size_t nx)
{
	return fmiGetDerivatives_(c, derivatives, nx);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetEventIndicators(fmi2Component c, fmi2Real eventIndicators[], size_t ni)
{
	return fmiGetEventIndicators_(c, eventIndicators, ni);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetContinuousStates(fmi2Component c, fmi2Real states[], size_t nx)
{
	return fmiGetContinuousStates_(c, states, nx);
}
#ifdef FMI_CLOCKED_STATES
fmi2Status fmi2SetClock(fmi2Component c, const fmi2Integer clockIndex[], size_t nClockIndex, const fmi2Boolean tick[], const fmi2Boolean subactive[])
{
	return fmiSetClock_(c, clockIndex, nClockIndex, tick, subactive);
}

fmi2Status fmi2GetClock(fmi2Component c, const fmi2Integer clockIndex[], size_t nClockIndex, fmi2Boolean active[])
{
	return fmiGetClock_(c, clockIndex, nClockIndex, active);
}
	
fmi2Status fmi2SetInterval(fmi2Component c, const fmi2Integer clockIndex[], size_t nClockIndex, fmi2Real interval[])
{
	return fmiSetInterval_(c, clockIndex, nClockIndex, interval);
}

fmi2Status fmi2GetInterval(fmi2Component c, const fmi2Integer clockIndex[], size_t nClockIndex, fmi2Real interval[])
{
	return fmiGetInterval_(c, clockIndex, nClockIndex, interval);
}
#endif /* FMI_CLOCKED_STATES */

#endif /* FMU_SKIP_MODEL_EXCHANGE */

/***************************************************
 Functions for FMI for Co-Simulation
****************************************************/

#ifndef FMU_SKIP_CO_SIM

/* ------------------------------------------------------ */
fmi2Status fmi2SetRealInputDerivatives(fmi2Component c,
                                     const  fmi2ValueReference vr[],
                                     size_t nvr,
                                     const  fmi2Integer order[],
                                     const  fmi2Real value[])
{
    return fmiSetRealInputDerivatives_(c, vr, nvr, order, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetRealOutputDerivatives(fmi2Component c,
                                      const   fmi2ValueReference vr[],
                                      size_t  nvr,
                                      const   fmi2Integer order[],
                                      fmi2Real value[])
{
    return fmiGetRealOutputDerivatives_(c, vr, nvr, order, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2DoStep(fmi2Component c,
                    fmi2Real      currentCommunicationPoint,
                    fmi2Real      communicationStepSize,
					fmi2Boolean   noSetFMUStatePriorToCurrentPoint)
{
    return fmiDoStep_(c, currentCommunicationPoint, communicationStepSize, noSetFMUStatePriorToCurrentPoint);
}
#ifdef HYBRID_COSIM
fmi2Status fmi2HybridDoStep(fmi2Component c,
                    fmi2Real      currentCommunicationPoint,
                    fmi2Real      communicationStepSize,
					fmi2Boolean   noSetFMUStatePriorToCurrentPoint,
					fmi2Boolean   *encounteredEvent,
					fmi2Real *endTime)
{
	return fmiHybridDoStep_(c, currentCommunicationPoint, communicationStepSize, noSetFMUStatePriorToCurrentPoint,encounteredEvent,endTime);
}

fmi2Status fmi2GetNextEventTime(fmi2Component c, fmi2Real *eventTime)
{
	return fmiGetNextEventTime_(c,eventTime);
}
#endif
/* ------------------------------------------------------ */
fmi2Status fmi2CancelStep(fmi2Component c)
{
    return fmiCancelStep_(c);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetStatus(fmi2Component c, const fmi2StatusKind s, fmi2Status*  value)
{
    return fmiGetStatus_(c, s, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetRealStatus(fmi2Component c, const fmi2StatusKind s, fmi2Real*    value)
{
    return fmiGetRealStatus_(c, s, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetIntegerStatus(fmi2Component c, const fmi2StatusKind s, fmi2Integer* value)
{
    return fmiGetIntegerStatus_(c, s, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetBooleanStatus(fmi2Component c, const fmi2StatusKind s, fmi2Boolean* value)
{
    return fmiGetBooleanStatus_(c, s, value);
}

/* ------------------------------------------------------ */
fmi2Status fmi2GetStringStatus(fmi2Component c, const fmi2StatusKind s, fmi2String*  value)
{
    return fmiGetStringStatus_(c, s, value);
}

#endif /* FMU_SKIP_CO_SIM */

#endif /* FMI_2 */
