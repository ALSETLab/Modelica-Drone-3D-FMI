#ifndef fmiFunctions_1_0_fwd_h
#define fmiFunctions_1_0_fwd_h

/* Header file for declarations of generic FMI implementation. */


#include "fmiFunctions_.h"

/***************************************************
 Common Functions
****************************************************/

DYMOLA_STATIC const char* fmiGetVersion_();
DYMOLA_STATIC fmiStatus fmiSetDebugLogging_(fmiComponent c, fmiBoolean loggingOn);
DYMOLA_STATIC fmiStatus fmiGetReal_(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiReal    value[]);
DYMOLA_STATIC fmiStatus fmiGetInteger_(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiInteger value[]);
DYMOLA_STATIC fmiStatus fmiGetBoolean_(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiBoolean value[]);
DYMOLA_STATIC fmiStatus fmiGetString_(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiString  value[]);
DYMOLA_STATIC fmiStatus fmiSetReal_(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiReal    value[]);
DYMOLA_STATIC fmiStatus fmiSetInteger_(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiInteger value[]);
DYMOLA_STATIC fmiStatus fmiSetBoolean_(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiBoolean value[]);
DYMOLA_STATIC fmiStatus fmiSetString_(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiString  value[]);

/***************************************************
 Functions for FMI for Model Exchange
****************************************************/

DYMOLA_STATIC fmiComponent fmiInstantiateModel_(fmiString              instanceName,
												fmiString              GUID,
												fmiMECallbackFunctions functions,
												fmiBoolean             loggingOn);
DYMOLA_STATIC fmiStatus fmiInitialize_(fmiComponent c, fmiBoolean toleranceControlled,
									   fmiReal relativeTolerance, fmiEventInfo* eventInfo);
DYMOLA_STATIC void fmiFreeModelInstance_(fmiComponent c);
DYMOLA_STATIC fmiStatus fmiSetTime_(fmiComponent c, fmiReal time);
DYMOLA_STATIC fmiStatus fmiTerminate_(fmiComponent c);
DYMOLA_STATIC fmiStatus fmiGetEventIndicators_(fmiComponent c, fmiReal eventIndicators[], size_t ni);
DYMOLA_STATIC fmiStatus fmiGetDerivatives_(fmiComponent c, fmiReal derivatives[]    , size_t nx);

/* for source export, these require model exchange header files */
#ifndef FMU_SKIP_MODEL_EXCHANGE

DYMOLA_STATIC const char* fmiGetModelTypesPlatform_();
DYMOLA_STATIC fmiStatus fmiSetContinuousStates_(fmiComponent c, const fmiReal x[], size_t nx);
DYMOLA_STATIC fmiStatus fmiEventUpdate_(fmiComponent c, fmiBoolean intermediateResults, fmiEventInfo* eventInfo);
DYMOLA_STATIC fmiStatus fmiCompletedIntegratorStep_(fmiComponent c, fmiBoolean* callEventUpdate);
DYMOLA_STATIC fmiStatus fmiGetContinuousStates_(fmiComponent c, fmiReal states[], size_t nx);
DYMOLA_STATIC fmiStatus fmiGetNominalContinuousStates_(fmiComponent c, fmiReal x_nominal[], size_t nx);
DYMOLA_STATIC fmiStatus fmiGetStateValueReferences_(fmiComponent c, fmiValueReference vrx[], size_t nx);

#endif /* FMU_SKIP_MODEL_EXCHANGE */

/***************************************************
 Functions for FMI for Co-Simulation
****************************************************/

/* for source export, these require co-simulation header files */
#ifndef FMU_SKIP_CO_SIM

DYMOLA_STATIC const char* fmiGetTypesPlatform_();
DYMOLA_STATIC fmiComponent fmiInstantiateSlave_(fmiString  instanceName,
												fmiString  fmuGUID,
												fmiString  fmuLocation,
												fmiString  mimeType,
												fmiReal    timeout,
												fmiBoolean visible,
												fmiBoolean interactive,
												fmiCoSimCallbackFunctions functions,
												fmiBoolean loggingOn);
DYMOLA_STATIC void fmiFreeSlaveInstance_ (fmiComponent c);
DYMOLA_STATIC fmiStatus fmiInitializeSlave_(fmiComponent c,
											fmiReal      tStart,
											fmiBoolean   StopTimeDefined,
											fmiReal      tStop);
DYMOLA_STATIC fmiStatus fmiTerminateSlave_(fmiComponent c);
DYMOLA_STATIC fmiStatus fmiResetSlave_(fmiComponent c);
DYMOLA_STATIC fmiStatus fmiSetRealInputDerivatives_(fmiComponent c,
													const  fmiValueReference vr[],
													size_t nvr,
													const  fmiInteger order[],
													const  fmiReal value[]);
DYMOLA_STATIC fmiStatus fmiGetRealOutputDerivatives_(fmiComponent c,
													 const   fmiValueReference vr[],
													 size_t  nvr,
													 const   fmiInteger order[],
													 fmiReal value[]);
DYMOLA_STATIC fmiStatus fmiDoStep_(fmiComponent c,
								   fmiReal      currentCommunicationPoint,
								   fmiReal      communicationStepSize,
								   fmiBoolean   newStep);
DYMOLA_STATIC fmiStatus fmiCancelStep_(fmiComponent c);
DYMOLA_STATIC fmiStatus fmiGetStatus_(fmiComponent c, const fmiStatusKind s, fmiStatus*  value);
DYMOLA_STATIC fmiStatus fmiGetRealStatus_(fmiComponent c, const fmiStatusKind s, fmiReal*    value);
DYMOLA_STATIC fmiStatus fmiGetIntegerStatus_(fmiComponent c, const fmiStatusKind s, fmiInteger* value);
DYMOLA_STATIC fmiStatus fmiGetBooleanStatus_(fmiComponent c, const fmiStatusKind s, fmiBoolean* value);
DYMOLA_STATIC fmiStatus fmiGetStringStatus_ (fmiComponent c, const fmiStatusKind s, fmiString*  value);

#endif /* FMU_SKIP_CO_SIM */

#endif /* fmiFunctions_1_0_fwd_h */
