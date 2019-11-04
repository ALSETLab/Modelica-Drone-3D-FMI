#ifndef fmiFunctions_2_0_fwd_h
#define fmiFunctions_2_0_fwd_h

/* Header file for declarations of generic FMI 2.0 implementation. */

#include "fmiFunctions_.h"


#ifdef fmiVersion
#undef fmiVersion
#endif
#define fmiVersion fmi2Version

/***************************************************
Common Functions
****************************************************/

/* Inquire version numbers of header files */
   DYMOLA_STATIC fmi2GetTypesPlatformTYPE fmiGetTypesPlatform_;
   DYMOLA_STATIC fmi2GetVersionTYPE       fmiGetVersion_;
   DYMOLA_STATIC fmi2SetDebugLoggingTYPE  fmiSetDebugLogging_;

/* Creation and destruction of FMU instances */
   DYMOLA_STATIC fmi2InstantiateTYPE  fmiInstantiate_;
   DYMOLA_STATIC fmi2FreeInstanceTYPE fmiFreeInstance_;

/* Enter and exit initialization mode, terminate and reset */
   DYMOLA_STATIC fmi2SetupExperimentTYPE         fmiSetupExperiment_;
   DYMOLA_STATIC fmi2EnterInitializationModeTYPE fmiEnterInitializationMode_;
   DYMOLA_STATIC fmi2ExitInitializationModeTYPE  fmiExitInitializationMode_;
   DYMOLA_STATIC fmi2TerminateTYPE               fmiTerminate_;
   DYMOLA_STATIC fmi2ResetTYPE                   fmiReset_;

/* Getting and setting variables values */
   DYMOLA_STATIC fmi2GetRealTYPE    fmiGetReal_;
   DYMOLA_STATIC fmi2GetIntegerTYPE fmiGetInteger_;
   DYMOLA_STATIC fmi2GetBooleanTYPE fmiGetBoolean_;
   DYMOLA_STATIC fmi2GetStringTYPE  fmiGetString_;

   DYMOLA_STATIC fmi2SetRealTYPE    fmiSetReal_;
   DYMOLA_STATIC fmi2SetIntegerTYPE fmiSetInteger_;
   DYMOLA_STATIC fmi2SetBooleanTYPE fmiSetBoolean_;
   DYMOLA_STATIC fmi2SetStringTYPE  fmiSetString_;

/* Getting and setting the internal FMU state */
   DYMOLA_STATIC fmi2GetFMUstateTYPE            fmiGetFMUstate_;
   DYMOLA_STATIC fmi2SetFMUstateTYPE            fmiSetFMUstate_;
   DYMOLA_STATIC fmi2FreeFMUstateTYPE           fmiFreeFMUstate_;
   DYMOLA_STATIC fmi2SerializedFMUstateSizeTYPE fmiSerializedFMUstateSize_;
   DYMOLA_STATIC fmi2SerializeFMUstateTYPE      fmiSerializeFMUstate_;
   DYMOLA_STATIC fmi2DeSerializeFMUstateTYPE    fmiDeSerializeFMUstate_;

/* Getting derivatives */
   DYMOLA_STATIC fmi2GetDirectionalDerivativeTYPE fmiGetDirectionalDerivative_;

/***************************************************
Functions for FMI for Model Exchange
****************************************************/

/* Enter and exit the different modes */
   DYMOLA_STATIC fmi2EnterEventModeTYPE               fmiEnterEventMode_;
   DYMOLA_STATIC fmi2NewDiscreteStatesTYPE            fmiNewDiscreteStates_;
   DYMOLA_STATIC fmi2EnterContinuousTimeModeTYPE      fmiEnterContinuousTimeMode_;
   DYMOLA_STATIC fmi2CompletedIntegratorStepTYPE      fmiCompletedIntegratorStep_;

/* Providing independent variables and re-initialization of caching */
   DYMOLA_STATIC fmi2SetTimeTYPE                 fmiSetTime_;
   DYMOLA_STATIC fmi2SetContinuousStatesTYPE     fmiSetContinuousStates_;

/* Evaluation of the model equations */
   DYMOLA_STATIC fmi2GetDerivativesTYPE                fmiGetDerivatives_;
   DYMOLA_STATIC fmi2GetEventIndicatorsTYPE            fmiGetEventIndicators_;
   DYMOLA_STATIC fmi2GetContinuousStatesTYPE           fmiGetContinuousStates_;
   DYMOLA_STATIC fmi2GetNominalsOfContinuousStatesTYPE fmiGetNominalsOfContinuousStates_;

/***************************************************
Functions for FMI for Co-Simulation
****************************************************/

   DYMOLA_STATIC fmi2SetRealInputDerivativesTYPE  fmiSetRealInputDerivatives_;
   DYMOLA_STATIC fmi2GetRealOutputDerivativesTYPE fmiGetRealOutputDerivatives_;

   DYMOLA_STATIC fmi2DoStepTYPE     fmiDoStep_;
   DYMOLA_STATIC fmi2CancelStepTYPE fmiCancelStep_;
#ifdef HYBRID_COSIM
   DYMOLA_STATIC fmi2HybridDoStepTYPE     fmiHybridDoStep_;
   DYMOLA_STATIC fmi2GetNextEventTimeTYPE fmiGetNextEventTime_;
#endif

#ifdef FMI_CLOCKED_STATES
   DYMOLA_STATIC fmi2SetClockTYPE                    fmiSetClock_;
   DYMOLA_STATIC fmi2GetClockTYPE                    fmiGetClock_;
   DYMOLA_STATIC fmi2SetIntervalTYPE                 fmiSetInterval_;
   DYMOLA_STATIC fmi2GetIntervalTYPE                 fmiGetInterval_;
#endif
/* Inquire slave status */
   DYMOLA_STATIC fmi2GetStatusTYPE        fmiGetStatus_;
   DYMOLA_STATIC fmi2GetRealStatusTYPE    fmiGetRealStatus_;
   DYMOLA_STATIC fmi2GetIntegerStatusTYPE fmiGetIntegerStatus_;
   DYMOLA_STATIC fmi2GetBooleanStatusTYPE fmiGetBooleanStatus_;
   DYMOLA_STATIC fmi2GetStringStatusTYPE  fmiGetStringStatus_;

#endif /* fmiFunctions_2_0_fwd_h */
