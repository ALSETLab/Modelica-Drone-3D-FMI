#if defined(DYMOLA_STANDALONE) && defined(__cplusplus)

/* For errors that also need to be checked in release mode. Where we cannot proceeed*/
extern void ReportInternalErrorAndThrow();
#define assumptionFatal(x) do{if (!(x)) {ReportInternalErrorAndThrow();}}while(0)
#else
/* For _now_ de-activated, do{;}while(0) is standard for getting an empty statement useable everywhere - including if. */

#define assumptionFatal(x) do{;}while(0)
#endif

#if defined(DYMOLA_STANDALONE) && defined(DEBUG)
/* Only activated if you manually add the define 'DEBUG' */
#include <assert.h>

#define assumption(x) do{if (!(x)) {assert(x);/*ReportInternalError();throw AssertionFailed;*/}}while(0)

/* For errors that only need to be checked during development, will fall thru to other code in release mode and be handled gracefully */
#define assumptionDevelopment(x) assert(x)
#else

#define assumption(x) do{;}while(0)
#define assumptionDevelopment(x) do{;}while(0)
#endif
