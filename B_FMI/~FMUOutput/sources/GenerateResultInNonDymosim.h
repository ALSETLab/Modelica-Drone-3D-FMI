/*
 * Copyright (C) 2003 Dynasim AB.
 * All rights reserved.
 *
 */


#ifndef GenerateResultInNonDymosim_HEADER
#define GenerateResultInNonDymosim_HEADER


/* #define GenerateResultInNonDymosim_DT 0.01 
To limit result file size.
*/

/* Calling sequence:
   // DeclarePhase0();
   SetDeclarePhase(0,...); //Reset.

   declare_(...); // Normal call of declare. Not needed

   // DeclarePhase1(...);
   SetDeclarePhase(1,...); //Init
   declare_(...);
   SetDeclarePhase(2,...);

   // DeclarePhase3(...);
   SetDeclarePhase(3,...); //Open file
   declare_(...);
   SetDeclarePhase(4,...);
   SetDeclarePhase(5,...); //Store constants
   declare_(...)
   SetDeclarePhase(6,...); 

   for(...) {
      
	  // DeclarePhase7(...);
	  SetDeclarePhase(7,...); // Store non-constants
	  declare_(...)
	  SetDeclarePhase(8,...); 
  }

  // DeclarePhase9();
  SetDeclarePhase(9,...);

  The arguments to SetDeclarePhase should be the same except the first one. 

  The routine use local variables during each call of declare from even to odd.
  But no non-local storage remains between the groups.
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dsblock.h>
#include "atraj.h"

struct DeclarePhaseTemp {
	int declarePhase_;
	int countConst_,countAlias_,countNonConst_;
	int *(offsets_[7]);
	int **baseoffsets_;
	float* resultPart_;
	const double* (pointers_[7]);
	char const** trajNames_;
	char const** trajDesc_;
	int* trajInfo_;
	int infoCount_;
	char* isPublicW_;
	char* isPublicX_;
	char* isPublicXD_;
	char* isPublicP_;
};
struct DeclarePhase {
	struct Atrajectory traj;
	AmatData nameData,descData,infoData,data1,data2;
	int totalInfoCount;
	int* (baseoffsets[7]);
    const char* filePath;
	AmatPutFile file;
	int openedFile;
	int createdTraj;
	double lastTime;
	int counter;
	struct DeclarePhaseTemp temp;
};
void DeclarePhase0(void**cuser);
void DeclarePhase1(struct DeclarePhase*phase);
void DeclarePhase3(struct DeclarePhase*phase,double startTime,double stopTime,
				   const double*parameters,const double*states,
				   const double*derivatives,
				   const double*outputs,
				   const double*inputs,
				   const double*auxiliary);
void DeclarePhase7(struct DeclarePhase*phase,double time,double tEnd,
				   const double*parameters,const double*states,
				   const double*derivatives,
				   const double*outputs,
				   const double*inputs,
				   const double*auxiliary);
void DeclarePhase9(struct DeclarePhase*phase);
#endif
