/*Header for applying correct version prefix to FMI types and Functions*/
#ifndef FMI_VERSION_PREFIX
#define FMI_VERSION_PREFIX
#ifdef FMI_2
#include "fmi2TypesPlatform.h"
#include "fmi2FunctionTypes.h"
#define FMIprefix fmi2
#else
#ifdef FMU_SOURCE_CODE_EXPORT
#include "fmiFunctions_.h"
#else
#include "fmiPlatformTypes_.h"
#include "fmiFunctions_1.0.h"
#endif /* FMU_SOURCE_CODE_EXPORT */
#define FMIprefix fmi
#endif/*FMI_2*/

#define VersionPaste(a,b)     a ## b
#define VersionPasteB(a,b)    VersionPaste(a,b)
#define VersionFullName(name) VersionPasteB(FMIprefix, name)

/*-------------- fmi2TypesPlatform Conversion------------------*/
#define FMIComponent			VersionFullName(Component)               
#define FMICompoenetEnvironment VersionFullName(ComponentEnvironment) 
#define FMIFMUstate				VersionFullName(FMUstate)      
#define FMIValueReference		VersionFullName(ValueReference)
#define FMIReal					VersionFullName(Real)
#define FMIInteger				VersionFullName(Integer)
#define FMIBoolean				VersionFullName(Boolean)
#define FMIChar					VersionFullName(Char)
#define FMIString				VersionFullName(String)
#define FMIByte					VersionFullName(Byte)
#define FMITrue					VersionFullName(True)	
#define FMIFalse				VersionFullName(False)

/*fmiFunctions/fmi2FunctionTypes*/
/*--------------------Enumeraiton Status----------------------*/
#ifdef FMI_2
#define FMIOK					fmi2OK
#else
#define FMIOK					fmiOK
#endif
#define FMIWarning				VersionFullName(Warning)
#define FMIDiscard				VersionFullName(Discard)
#define FMIError				VersionFullName(Error)
#define FMIFatal				VersionFullName(Fatal)
#define FMIPending				VersionFullName(Pending)
#define FMIStatus				VersionFullName(Status)

/*-------------------Enumeration Type--------------------------*/
#define FMIModelExchange        VersionFullName(ModelExchange)
#define FMICoSimulation			VersionFullName(CoSimulation)
#define FMIType					VersionFullName(Type)

/*-------------------Enumeraion StausKind----------------------*/
#define FMIDoStepStatus			VersionFullName(DoStpeStatus)
#define FMIPendingStatus		VersionFullName(PendingStatus)
#define FMILastSuccessfulTime   VersionFullName(LastSuccessfulTime)
#define FMITerminated			VersionFullName(Terminated)
#define FMIStatusKind			VersionFullName(StatusKind)

/*-------------------Struct CallBackFunctions-------------------*/
#define FMICallbackLogger			VersionFullName(CallBackLogger)
#define FMICallbackAllocateMemory	VersionFullName(CallbackAllocateMemory)
#define FMICallbackFreeMemory		VersionFullName(CallbackFreeMemory)
#define FMIStepFinished				VersionFullName(StepFinished)
#define FMICallbackFunctions		VersionFullName(CallbackFunctions)

/*-------------------Struct EventInfo---------------------------*/
#define FMIEventInfo			VersionFullName(EventInfo)

#endif /*FMI_VERSION_PREFIX*/
