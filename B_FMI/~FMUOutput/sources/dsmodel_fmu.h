/* A header for the dsmodel.c variant generated for FMU source code export. */

#include "util.h"
/* to e.g. get logging through the FMI logger function */
#define BUILDFMU
/* to make some necessary definitions available */
#define FMU
#include "dlldata.h"


#ifdef FMU_SOURCE_SINGLE_UNIT
static Component* globalComponent = NULL;
static Component* globalComponent2 = NULL;
#else
extern Component* globalComponent;
extern Component* globalComponent2;
/* Code copied from libds */
DYMOLA_STATIC struct BasicIDymosimStruct*getBasicIDymosimStruct() {
	return dymosimGetThreadData()->modelData.basicI;
}
DYMOLA_STATIC struct BasicDDymosimStruct*getBasicDDymosimStruct() {
	return dymosimGetThreadData()->modelData.basicD;
}
#endif /* FMU_SOURCE_SINGLE_UNIT */

/* Local version of this function from libds */
static void aprintLine(int type, const char *str) {
	FMIStatus stat;	
	Component* comp=globalComponent;
	if (comp == NULL) comp=globalComponent2;
	if (comp == NULL) {
		return;
	}
	switch (type) {
	   case 0: stat = FMIOK; break;
	   case 1: stat = FMIWarning; break;
	   case 2: stat = FMIError;   break;
	}
	util_logger(comp, comp->instanceName, stat, "", "%s", str);
}
