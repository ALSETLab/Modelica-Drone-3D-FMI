/* Functions from libs needed by FMI implementation, that are not obtained during source code export */

#include "dlldata.h"

/* when compiling as a single compilation unit, definition is provided in dsmodel.c */
#ifndef FMU_SOURCE_SINGLE_UNIT
void setBasicStruct(double*d,int*i) {
	dymosimGetThreadData()->modelData.basicI=(struct BasicIDymosimStruct*)(i);
	dymosimGetThreadData()->modelData.basicD=(struct BasicDDymosimStruct*)(d);
}
#endif /* FMU_SOURCE_SINGLE_UNIT */
