#ifndef dymosim_h
#define dymosim_h
/*
 * Copyright (C) 1997-2004 Dynasim AB.
 * All rights reserved.
 *
 */
#include "libdssetup.h"
#include "stdio.h"
#include "adymosim.h"
/* API for command line arguments to dymosim.exe ---------------*/
#ifdef __cplusplus
extern "C" {
#endif
#ifndef LIBDS_DLL


/* The functions normally return true on success and false on failure. */
extern int dymosimMain(int argc, char *argv[]);
/* Perform the action for the linked model and then return. Arguments as when running dymosim.exe*/
/* This can only be done when model and libds is linked together, since it relies on linking with the model */
/* Therefore it is only provided when libds is a DLL */
#endif

struct DymosimModel;
struct DymosimLinearization;
LIBDS_API int dymosimMainModel (int argc, char *argv[],const struct DymosimModel*f);
/* Similar to dymosimMain, but for the dll-variant. 
This runs an entire simulation to the end before returning.
The struct pointer represents the model and is returned by DymosimModelFunctions()
 in the model.
When model and libds is linked together the 'f' argument is ignored.
*/

/* API for controlling the simulator: -------------------------*/
struct DymosimSimulator;
#ifndef DYMOSIM_SEVERITY_H
#define DYMOSIM_SEVERITY_H
enum Dymosim_Severity {Dymosim_Message,Dymosim_Warning,Dymosim_Error};
#endif

LIBDS_API struct DymosimSimulator* DymosimNew(const struct DymosimModel*model,
								const char*LogFile,
                                const char*ResultFile,
								const char*sim_name,
								FILE*fp_out,
								FILE*fp_err,
								void (*ErrorHandler)(enum Dymosim_Severity severity,const char*message),
                                                                int noFileBasedMessages);
/* For setting up the simulator. */
/* All argument, except the first are optional and can be NULL.
   When model and libds is linked together the DymosimModel argument is ignored (and can be null).*/

LIBDS_API struct DymosimSimulator* DymosimNew2(const struct DymosimModel*model,
								const char*LogFile,
                                const char*ResultFile,
								const char*sim_name,
								FILE*fp_out,
								FILE*fp_err,
								void (*ErrorHandler)(enum Dymosim_Severity severity,const char*message),
                                                                int noFileBasedMessages,
																const char* fmuDLLPath,
																int isFMU);
/* For setting up the simulator with FMU interface. */
/* All argument, except the first are optional and can be NULL.
   When model and libds is linked together the DymosimModel argument is ignored (and can be null).*/

LIBDS_API int DymosimRun(struct DymosimSimulator*, double deltaT);
LIBDS_API int DymosimRunTo(struct DymosimSimulator*, double tStop);
LIBDS_API int DymosimRunToEvent(struct DymosimSimulator*sim, double*p_tStop, int allowEarlyStop);
/* Run a simulation.*/
/* 0 means failed, 1 means simulation terminated, 2 means reached given end */
/* 3 means event stopping it early and p_tStop contains the actual stop-time */
/* 4 means terminated by internal Modelica terminate call*/

LIBDS_API int DymosimLoadSnapshot(struct DymosimSimulator*,const char*);
/* Load the current setup from a file in dsin.txt format */

LIBDS_API int DymosimSaveSnapshot(struct DymosimSimulator*,const char*,int binary);
/* Saves the current setup to a file in dsin.txt format (or binary equivalent).*/


LIBDS_API int DymosimTerminateAndFree(struct DymosimSimulator*,int ok,
									  const char*FinalFile,int binary);
/* Terminate the simulation (successfully if ok - this will call terminal-section), 
  stores on the file (if a file name is given - nothing written if NULL) and frees the simulator.
  Note: The model is called if ok is true. This is done to run any 'when terminal()'.
*/
LIBDS_API int DymosimResetModel(struct DymosimSimulator*sim,int runTerminal);
/* Reset the model */

/* The following must be set before starting the simulation. */
/* See adymosim.h */
/* Note that loading a snap-shot overwrites them */
LIBDS_API AdymosimExperiment DymosimGetExperiment(struct DymosimSimulator*);
LIBDS_API void DymosimSetExperiment(struct DymosimSimulator*,AdymosimExperiment);
LIBDS_API AdymosimMethod DymosimGetMethod(struct DymosimSimulator*);
LIBDS_API void DymosimSetMethod(struct DymosimSimulator*,AdymosimMethod);
LIBDS_API AdymosimSettings DymosimGetSettings(struct DymosimSimulator*);
LIBDS_API void DymosimSetSettings(struct DymosimSimulator*,AdymosimSettings);

typedef void (*DymosimSnapshotHookType)(struct Adymosim*);
LIBDS_API void DymosimSetSaveSnapshotHook(struct DymosimSimulator*,DymosimSnapshotHookType);
LIBDS_API void DymosimSetLoadSnapshotHook(struct DymosimSimulator*,DymosimSnapshotHookType);
LIBDS_API DymosimSnapshotHookType DymosimGetLoadSnapshotHook(struct DymosimSimulator*);
LIBDS_API DymosimSnapshotHookType DymosimGetSaveSnapshotHook(struct DymosimSimulator*);
/* Setting callbacks that hook into the loading/saving handling */
/* The Save routine is called just prior to writing the file to disk */
/* The Load routine is called just after the file has been read */

/* For accessing variables */
/* Note: The const char* for names is only valid as long as the DymosimSimulator*/
struct DymosimVariableHandle {
	dsCategory category;
	integer index;

	dsBaseType basetype;
	const char*name;
};

/* For going through all variables:*/
LIBDS_API int DymosimEnumerateVariables(struct DymosimSimulator*,
										struct DymosimVariableHandle*,
										integer*state);
/* to use:  */
/* for(state=0;DymosimEnumerateVariables(sim,&handle,&state);) {...} */


LIBDS_API int DymosimEnumerateAliases(struct DymosimSimulator*sim,
										struct DymosimVariableHandle*pointedHandle,
                                        const char **aliasName,
                                        integer *aliasSign,
										integer*state);
/* to use:  */
/* for(state=0;DymosimEnumerateAliases(sim,&pointed_handle,pCurrentName,&state);) {...} */

LIBDS_API int DymosimEnumerateAll(struct DymosimSimulator*sim,
struct DymosimVariableHandle*pointedHandle,
	const char **aliasName,
	integer *aliasSign,
	integer*state);
/* to use:  */
/* for(state=0;DymosimEnumerateAliases(sim,&pointed_handle,pCurrentName,&state);) {...} */
/* non-alias have *aliasName=0 */

static int DymosimIsParameter(struct DymosimSimulator*sim,struct DymosimVariableHandle*h) {
	return h && h->category==dsParameter;
}
static int DymosimIsInput(struct DymosimSimulator*sim,struct DymosimVariableHandle*h) {
	return h && h->category==dsInput;
}
static int DymosimIsOutput(struct DymosimSimulator*sim,struct DymosimVariableHandle*h) {
	return h && h->category==dsOutput;
}

/* For getting information about specific variables: */
LIBDS_API int DymosimFindVariableByName(struct DymosimSimulator*,const char*,
										struct DymosimVariableHandle*);
LIBDS_API int DymosimFindVariableByNumber(struct DymosimSimulator*,dsCategory,integer index,
										  struct DymosimVariableHandle*);
/* Returns true if variable was found and information about variable in last argument */

LIBDS_API int DymosimVariablesNr(struct DymosimSimulator*,dsCategory); 
/* For input, output, parameter: Returns number of variables in category*/

LIBDS_API const char* DymosimVariablesName(struct DymosimSimulator*,dsCategory,integer index);
/* For input, output, parameter: Returns name of i:th variable. index>=0, index<DymosimVariablesNr*/
/* Return 0 if illegal input.*/

LIBDS_API const char* DymosimVariableDescription(struct DymosimSimulator*dymosimData,dsCategory cat,integer index);
/* Returns description of i:th variable. index>=0, index<DymosimVariablesNr*/
/* Return 0 if illegal input.*/
LIBDS_API const char* DymosimVariableDescription2(struct DymosimSimulator*dymosimData,dsCategory cat,integer index, integer state);
/* Similar but uses state if >0 */
/* Return 0 if illegal input.*/

LIBDS_API double DymosimGetValue(struct DymosimSimulator*,dsCategory,integer index);
/* Returns current value of variable */

LIBDS_API int DymosimSetValue(struct DymosimSimulator*,dsCategory,integer index,double);
/* Sets value or variable. Returns true if ok. */
/* Can always be used for input and parameter */
/* Can for other variables only be used after DymosimLoadSnapShot and before simulation is started*/

LIBDS_API const char* DymosimGetString(struct DymosimSimulator*,dsCategory ,integer);
/*Retunrs a const char* to a string parameter, used in fmi*/

LIBDS_API int DymosimSetString(struct DymosimSimulator*,dsCategory,integer,const char*);
/*Takes a const char* ad copies it to a string parameter, used in fmi*/

LIBDS_API void DymosimPrint(struct DymosimSimulator*,int type,const char*msg);
/* To print a message. Uses aprint in the context of the simulation (do not aprint without context). */
/* Thus type is 0 for message, 1 for warning, 2 for error */

LIBDS_API int DymosimInitialize(struct DymosimSimulator*);
/* Ensures that the initial section has been run. Return true if ok, false otherwise */

LIBDS_API int DymosimInitializeLicensing( struct DymosimSimulator*sim, char *key );

LIBDS_API int DymosimLinearize(struct DymosimSimulator*,struct DymosimLinearization*);
/* Linearize the model, and return a ABCD-system */

LIBDS_API double DymosimGetTime(struct DymosimSimulator*);
/* Returns current value of time during simulation */

LIBDS_API int DymosimGetDirectionalDerivatives(struct DymosimSimulator* sim, const unsigned int z_ref[], const integer nz, const unsigned int v_ref[], const integer nv, const double dv[], double dz[]);
/* used for fmi function getDirectoinalDerivatives */

LIBDS_API int DymosimSetRealInputDerivatives(struct DymosimSimulator* sim, const int v_ref[], size_t nvr, const int order[], const double value[]);

LIBDS_API int DymosimGetRealOutputDerivatives(struct DymosimSimulator* sim, const unsigned int vr[], size_t nvr, const int order[], double value[]);

LIBDS_API int DymosimGetFMUState(struct DymosimSimulator*sim, void ** fmuState);

LIBDS_API int DymosimSetFMUState(struct DymosimSimulator*sim, void * fmuState);

LIBDS_API void DymosimFreeFMUState(struct DymosimSimulator*sim, void ** fmuState);

LIBDS_API int DymosimSerializedFMUstateSize(struct DymosimSimulator*sim, void * fmuState, size_t *size);

LIBDS_API int DymosimSerializeFMUstate(struct DymosimSimulator* sim, void* FMUstate, char* serializedState, size_t size);

LIBDS_API int  DymosimDeSerializeFMUstate(struct DymosimSimulator* sim, const char serializedState[], size_t size, void** FMUstate);

#ifdef __cplusplus
}
#endif
#endif
