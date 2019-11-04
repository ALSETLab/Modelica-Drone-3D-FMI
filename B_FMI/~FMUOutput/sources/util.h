/* Utility header file for Dymosim FMI implementation. */

#ifndef util_h
#define util_h

/* need to include first so that correct files are included */
#include "conf.h"
#include "types.h"
#include <float.h>

/* ----------------- macros ----------------- */

/* Standard value reference */
/* idemand: 31-28, category: 27-24, index: 23-0 */
#define FMI_IDEMAND(valueRef) ((valueRef) >> 28)
#define FMI_CATEGORY(valueRef) (((valueRef) & 0xf000000) >> 24)
#define FMI_INDEX(valueRef) ((valueRef) & 0xffffff)

/* Value reference for embedded systems */
/* idemand: 31-28, restricted: 27, FMI type size: 26-23, index: 22-0 */

#define MIN(A, B) ((A) <= (B) ? (A) : (B))

#define SMALL_TIME_DEV(curtime) (4 * DBL_EPSILON * (1 + fabs(curtime)))

#define LOG(c, status, msg) util_logger(c, c->instanceName, status, "", msg)

#define HANDLE_STATUS_RETURN(status) return (status == FMIError) ? util_error(comp) : status;

#define MAX_STRING_SIZE 500
/*TODO support larger string sizes and allocate more memory if needed*/
/* ------------------ function declarations ----------------- */

/* logger wrapper for handling off enabled/disabled logging */
DYMOLA_STATIC void util_logger(Component* comp, FMIString instanceName, FMIStatus status,
	                           FMIString category, FMIString message, ...);

/* buffered variant used when line breaks should be omitted */
DYMOLA_STATIC void util_buflogger(Component* comp, FMIString instanceName, FMIStatus status,
	                              FMIString category, FMIString message, ...);

/* cannot use strdup since direct use of malloc not allowed */
DYMOLA_STATIC FMIString util_strdup(const FMICallbackFunctions *functions, FMIString s);

/* locally modified variant from Sundials to store in buffer instead of printing */
DYMOLA_STATIC int util_check_flag(void *flagvalue, char *funcname, int opt, Component* comp);

/* refresh variable values using dsblock_ */
DYMOLA_STATIC int util_refresh_cache(Component* comp, int idemand, const char* label, FMIBoolean* iterationConverged);

/* handle termination due to an error */
DYMOLA_STATIC FMIStatus util_error(Component* comp);

/* Initialize model, partly or completely, depending on argument "complete". */
DYMOLA_STATIC FMIStatus util_initialize_model(FMIComponent c, FMIBoolean toleranceControlled, FMIReal relativeTolerance, FMIBoolean complete);

/* Perform event iteration. */
DYMOLA_STATIC FMIStatus util_event_update(FMIComponent c, FMIBoolean intermediateResults,
#ifdef FMI_2
/* needs another argument since not in eventInfo for FMI 2*/
FMIBoolean* terminateSolution
#else
FMIEventInfo* eventInfo
#endif
);

/* Initialize slave, partly or completely, depending on FMI version */
DYMOLA_STATIC FMIStatus util_initialize_slave(FMIComponent c, FMIReal relativeTolerance, FMIReal tStart, FMIBoolean StopTimeDefined, FMIReal tStop);

DYMOLA_STATIC void util_print_dymola_timers(FMIComponent c);

#ifdef FMI_2
/* Exit initialization mode. */
	DYMOLA_STATIC FMIStatus util_exit_model_initialization_mode(FMIComponent c, const char* label, ModelStatus nextStatus);

/* --------------------------------------------------------------------------------------------------------
API functions defined in earlier version of fmi 2.0 still in use internally
----------------------------------------------------------------------------------------------------------*/

/* Creation and destruction of model instances and setting debug status */
   DYMOLA_STATIC FMIComponent fmiInstantiateModel_(FMIString, FMIString, FMIString, const FMICallbackFunctions*, FMIBoolean, FMIBoolean);
   DYMOLA_STATIC void fmiFreeModelInstance_(FMIComponent);

   /* Evaluation of the model equations */
   DYMOLA_STATIC FMIStatus fmiEnterModelInitializationMode_(FMIComponent, FMIBoolean, FMIReal);
   DYMOLA_STATIC FMIStatus fmiExitModelInitializationMode_(FMIComponent);
   DYMOLA_STATIC FMIStatus fmiTerminateModel_(FMIComponent);

   /* Creation and destruction of slave instances */
   DYMOLA_STATIC FMIComponent fmiInstantiateSlave_(FMIString, FMIString, FMIString, const FMICallbackFunctions*, FMIBoolean, FMIBoolean);
   DYMOLA_STATIC void fmiFreeSlaveInstance_(FMIComponent);

   /* Simulating the slave */
   DYMOLA_STATIC FMIStatus fmiEnterSlaveInitializationMode_(FMIComponent, FMIReal, FMIReal, FMIBoolean, FMIReal);
   DYMOLA_STATIC FMIStatus fmiExitSlaveInitializationMode_(FMIComponent);
   DYMOLA_STATIC FMIStatus fmiTerminateSlave_(FMIComponent);
   DYMOLA_STATIC FMIStatus fmiResetSlave_(FMIComponent);


#endif

#endif /* util_h */
