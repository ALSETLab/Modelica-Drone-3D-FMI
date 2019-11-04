#ifndef FMIFUNCTIONS__H
#define FMIFUNCTIONS__H

/* Below section was moved here from fmiFunctions.c to be able to handle source code export correctly; for FMI 1.0,
   inclusion of this file from types.h is necessary, why the model identifier must be set already in this header file. */
#ifndef BUILD_LIBFMI
/*  -- start inclusion of model identifier -- */
#include "fmiModelIdentifier.h"
/* pre-processor variable MODEL_IDENTIFIER was renamed to FMI2_FUNCTION_PREFIX for FMI 2.0 and also supposed to include the trailing '_' */
#if !defined FMI2_FUNCTION_PREFIX && defined MODEL_IDENTIFIER
#define _paste(a,b) a ## b
#define _pasteB(a,b) _paste(a,b)
#define FMI2_FUNCTION_PREFIX _pasteB(MODEL_IDENTIFIER,_)
#endif


/*  -- end inclusion of model identifier -- */
#endif /* BUILD_LIBFMI */

#ifdef FMU_SOURCE_CODE_EXPORT

#if !defined(FMI_2) && !defined(FMU_CO_SIM)
#include "fmiModelFunctions.h"
typedef fmiCallbackFunctions fmiMECallbackFunctions;
#define fmiPlatform fmiModelTypesPlatform
#else 
#if defined(FMI_2) 
#include "fmi2Functions.h"
#else
#include "fmiFunctions.h"
typedef fmiCallbackFunctions fmiCoSimCallbackFunctions;
/* For source co-simulation code export we must provide the type definition from model exchange here to enable code-reuse later . */
typedef struct {
     fmiCallbackLogger         logger;
     fmiCallbackAllocateMemory allocateMemory;
     fmiCallbackFreeMemory     freeMemory;
   } fmiMECallbackFunctions;
#endif
#endif /* !defined(FMI_2) && !defined(FMU_CO_SIM) */

#else /* FMU_SOURCE_CODE_EXPORT */

#ifdef FMI_2
#include "fmi2Functions.h"
#else
#include "fmiFunctions_1.0.h"
#endif /* FMI_2 */

#endif /* FMU_SOURCE_CODE_EXPORT */

#endif /* FMIFUNCTIONS__H */
