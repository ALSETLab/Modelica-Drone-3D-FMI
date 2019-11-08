/* Begin file dsblock4.c */
/* File version: 1.7, 1999-01-20 */

/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

/* end */
      }
	  if (DymolaOneIteration_==-1) DymolaOneIteration_=0;
	  if (did_->DymolaEventOptional_var && *idemand_==4 && Iter==2 && RootFinder_) {
		  int i1_;
		  for(i1_=0;i1_<nrel_*2;i1_++) {
			  if (QZold_[i1_]*QZ_[i1_]<0)
				  AnyEvent_=true;
		  }
		  if (AnyEvent_) {
			  *idemand_=5;
			  DYNEvent=true;
			  Iter=0;
			  goto iterateEvent;
		  }
	  }
	  if (AnyEvent_)
	    did_->HaveEventIterated_var=true;

    if ( initializationPhase_ || (( (Init_ && nrel_ > 0) || AnyEvent_) && (FirstEvent || EventIterate_) && Iter <= MaxIter)) {
      if (GlobalError_ != 0 || *QiErr != 0) goto leave;
      if (PrintEvent&(1<<1)) {
		  if (DymolaOneIteration_==0 || DymolaOneIteration_==4) 
            DymosimMessage("Iterating to find consistent restart conditions.");
	  } else if (Iter==MaxIter) {
		  if (!(PrintEvent&(1<<10))) {
			  DymosimMessage("");
			  DymosimMessage("On the final iteration for restart conditions we get:");
			  PrintEvent|=(1<<1);
		  }
	  }
	  if (initializationPhase_==1)
		  initializationPhase_=2;
	  else {
		if (Init_) Iter = 0;
		Init_ = false;
		initializationPhase_=0;
	  }
	  NewParameters_ = NewParameters_ && AnyEventParameter_;
      DYNEvent = true;
      *icall_  = 0;
	  if (DymolaOneIteration_==4) {
		  DymolaOneIteration_=0;
	  } else if (DymolaOneIteration_) {
		  DymolaOneIteration_=3;
		  goto leave;
	  }
      goto iterate;
    } else if (Iter > MaxIter) {
      DymosimMessage("");
      DymosimMessageDouble("ERROR: Finding consistent restart conditions failed at time: ", DYNTime);
      DymosimMessage("");
	  if ((!Init_ && PrintEvent&(1 << 1)) || (Init_ && PrintEvent&(1 << 2)))
		  DynLogEvents(-5, 0, 0, 0, 0, 0);
      *QiErr = 1;
      GlobalError_ = 1;
      goto leave;
    }
	if(DymolaOneIteration_!=0){
		int i;
		for(i=0;i<NWhen_;++i){QEvaluate_[i]=QEvaluateNew_[i];};
	}
	DymolaOneIteration_=0;
    Init_ = FirstEvent;      /* restore Init */
    FirstEvent = false;

	{
		if (( (Init_ && nrel_ > 0) || AnyEvent_ || Iter > 1) && (PrintEvent&(1<<1))) {
	      DymosimMessageDouble("      during event at Time : ", DYNTime);
		}
		if (Init_ && (PrintEvent&(1<<1) || PrintEvent&(1<<2))) DynLogEvents(-3, DYNTime, 0, 0, (PrintEvent&(1 << 2)), 0);
		if (*idemand_ == 7 && PrintEvent&(1<<1)) DynLogEvents(-4, DYNTime, 0, 0, 0, 0);
    }
#ifdef DYNEventSpecial
	if (*QiErr==0 && !Init_ && DYNEvent && !AnyDEvent_ && !AnyREvent_  && (*idemand_ == 5 || *idemand_ == 7)) {
		if (AnyIEvent_) {
			*QiErr=-994;
		} else {
#ifdef DYNHasMultiRate_
			*QiErr=-993;
#else
			*QiErr=-995;
#endif
			DynLogEvents(-6, 0.0, 0, NULL, 0, 0.0);
			if (*idemand_ == 5 && did_->hasStoredInTemp && DYNInitialGuessPolynomialUpdate_) {
				unsigned ii_;
				EqRemember2Time_ = EqRemTempTime_; EqRemAcc2Time_ = EqRemTempTimeAcc_;
				for (ii_ = 0; ii_ < SizeEq_; ii_++) EqRemember2_[ii_] = EqRememberTemp_[ii_];
			}
		}
	}
#endif
	if (*idemand_ <= 2 || *idemand_ >= 5) did_->hasStoredInTemp = 0;
	
	if (DYNFindEvent) CheckForEvents(did_,DYNTime, Init_, DYNEvent, QZ_, nrel2_, F_, (DYNFindEvent==1)?(nx_):(0), duser_, iuser_);

#if 1
	if (DAEsolver_ && (DYNEvent || atDAEEvent_)) {
		int i_;
		for (i_ = 0; i_ < NX_; i_++)
			XD_[i_] = F_[i_];
		if (DYNEvent)
			atDAEEvent_ = 0;
	}
#endif

/* Modify only enabled crossing functions. */
    if (SpuriousEvents_ && *idemand_ == 4) {
	  int i1_;
      for (i1_ = 1; i1_ <= nrel_; i1_++) {
        if (FirstCross_ || Qenable_[i1_]) {
          QZold_[2*i1_-2] = QZ_[2*i1_-2];
          QZold_[2*i1_-1] = QZ_[2*i1_-1]; 
        } else {
		  QZ_[2*i1_-2] = QZold_[2*i1_-2];
          QZ_[2*i1_-1] = QZold_[2*i1_-1]; 
        }
      }
      FirstCross_ = 0;
    } else if (!SpuriousEvents_ && DYNEvent) {
		int i1_;
		for (i1_ = 1; i1_ <= nrel_; i1_++)
			if (!Qenable_[i1_]) {
				if (QL_[i1_]&2 || QZ_[2*i1_-1]==0) {
					QZ_[2*i1_-2]=QZ_[2*i1_-1]=0.1;
				}
				QL_[i1_]&=1;
			} else {
				QL_[i1_]&=3;
			}
			if (did_->DymolaEventOptional_var) for(i1_=0;i1_<2*nrel_;i1_++) {QZold_[i1_]=QZ_[i1_];}
	}


} else {   /* return jump from setjmp/longjmp */
  *QiErr = 1L;
  if (DYNTime <= InitTime && Iter <= 1 && DymolaHomotopyUsed) {
	  /* similar as in dsblock3.c - but in case the evaluation failed */
	  if (DymolaUserHomotopy) {
		  if (DymolaHomotopyLambda <= 0) DymosimMessage("Error: could not solve simplified initialization for homotopy method.");
		  else if (DymolaHomotopyLambdaDelta <= 1e-4) {
			  if (DymolaHomotopyLambdaFail > 0)
				  DymosimMessage("Error: adaptive homotopy method got stuck after starting. Can set scripting flag Advanced.DebugHomotopy=true; simulate again, and open continuation.csv to investigate");
			  else
				  DymosimMessage("Error: adaptive homotopy method could not start using actual - check that actual and simplified arguments are similar.");
		  } else {
			  GlobalError_ = 0;
			  *QiErr = 0;
			  DymolaHomotopyLambda -= DymolaHomotopyLambdaDelta;
			  DymolaHomotopyLambdaDelta *= 0.5;
			  DymolaHomotopyLambdaFail = DymolaHomotopyLambda;
			  DymolaHomotopyLambda += DymolaHomotopyLambdaDelta;
			  DymosimMessage("Error: reducing step size for homotopy.");
			  DYNHReject = 1;
			  UpdateInitVars(time, X_, XD_, U_, DP_, IP_, LP_,
				  F_, Y_, W_, QZ_, duser_, iuser_, cuser_, did_, 0);
			  goto iterate2;
		  }
	  } else if (ResetCounter_ != did_->oldReset_var) {
		  did_->oldReset_var = ResetCounter_;
		  if (!(PrintEvent&(1 << 10))) DymosimMessage("Trying to solve non-linear system using global homotopy-method.");
		  DymolaUserHomotopy = 1;
		  DymolaHomotopyLambda = 0;
		  UpdateInitVars(time, X_, XD_, U_, DP_, IP_, LP_,
			  F_, Y_, W_, QZ_, duser_, iuser_, cuser_, did_, 0);
		  GlobalError_ = 0;
		  *QiErr = 0;
		  goto iterate2;
	  }
  }
#ifdef AutoResetAfter
  if (*QiErr!=0 && *QiErr!=-999 && *QiErr!=-998) {
  	  resetActive=1;
	  restartTime=DYNTime+AutoResetAfter;
	  *QiErr=GlobalError_=0;
  }
#endif
  did_->inCall_var = 0;
  return 0;
}

#if defined(Sections_) 
  *icall_  = *idemand_;
#else
  *icall_  = 4; 
#endif

leave:
#if !defined(DYMOLA_DSPACE) && !defined(NO_FILE) && defined(DymolaPrecisionTiming_) && defined(DymosimRealTimePriority_)
  if (*idemand_==7) {
	  int i,maxi=0;
	  for(i=0;;++i) {
		  if (i*2>=did_->DymolaTimeZeroLength_var || did_->DymolaTimeZero_vec[2*i+1]==0) 
			  break;
	  }
	  maxi=i;
	  if (maxi>0) {
		  FILE*f=fopen("plotTiming.mos","w");
		  fprintf(f,"times=fill(0.1,%d,2);\n",maxi);
		for(i=0;i<maxi;++i) {
			fprintf(f,"times[%d,:]={%g,%g};\n",i+1,did_->DymolaTimeZero_vec[2*i],did_->DymolaTimeZero_vec[2*i+1]);
		}
		fclose(f);
   		DymosimMessage("RunScript(\"plotTiming.mos\",true);plotArray(times[:,1],times[:,2],-1);");
	  }
  }
#endif
#if defined(GenerateSimulinkTiming) && defined(DynSimStruct) && !defined(DYMOLA_DSPACE)
  if (*idemand_==7) {
	  DymosimMessageDouble("Time for solution:",CurrentClockTime-did_->TimeStartOfSimulation_var);
  }
#endif
  if (GlobalError_ != 0 && *QiErr==0)
    *QiErr = GlobalError_;
#ifdef AutoResetAfter
  if (*QiErr!=0 && *QiErr!=-999 && *QiErr!=-998) {
  	  resetActive=1;
	  restartTime=DYNTime+AutoResetAfter;
	  *QiErr=GlobalError_=0;
  }
#endif
  did_->inCall_var = 0;
  return 0;
}

static struct DYNInstanceData tempData={0,0, 0,0,
#ifdef DynSimStruct
	  1
#else
	  0
#endif
	,0,{{0}}
    ,{0.0},{0},0.0,
	0.0,1e30,0.0,0.0,1.0,1.0,-1e30,
	0,
#ifdef DymolaInitializeStateFirst_
		  1
#else
		  0
#endif
	  ,0,0,0.0,0,0,0,0, 0,0,0,

	  1.0, 0.0, 0.1, 0, 0, 0.0, 0.0,
	  -1e33,-1e33,{{0}}, 
#ifdef NrDymolaTimers_
	  NrDymolaTimers_
#else
	  1
#endif
	  ,{0},{0},
#ifdef DymolaNrStepTimers
	  DymolaNrStepTimers
#else
	  0
#endif
	  ,0,0,0, 0,0,0,0,0,0,0,0,0};
DYMOLA_STATIC void DYNInitializeDid(struct DYNInstanceData*did_) {
	if (did_) {
#if defined(DYN_MULTINSTANCE)
		struct DYN_ThreadData*threadData=DYN_GetThreadData();
		if (threadData) {threadData->m_external=0;threadData->did=0;}
#endif
		*did_=tempData;
	}
}
DYMOLA_STATIC void registerTimeEvent(const double atTime) {
#if defined(DYN_MULTINSTANCE)
	if (DYN_GetThreadData()->did) {
		registerTimeEventNew(atTime, DYN_GetThreadData()->did);
		return;
	}
#endif
	registerTimeEventNew(atTime, &tempData);
}
DYMOLA_STATIC void registerTimeEventNew(const double atTime,struct DYNInstanceData*did_) {
   struct BasicDDymosimStruct*basicD=getBasicDDymosimStructNew(did_);
   double eventAccuracy;
   eventAccuracy=(6*DBL_EPSILON)*(fabs(atTime)+basicD->mOrigTimeError);
#if 0
  /* Simple case, just move up end-point a little */
   NextTimeEvent=Dymola_min(atTime+eventAccuracy,NextTimeEvent);
  /*DymosimMessageDouble("Next Event:",NextTimeEvent);*/
#else
  /* The logic is as follows: */
  /* All time events within TimeEventAccuracy will trigger one event.*/
  /* This event will occur after all of the events has occured.*/
  
  /* The next interval with events is [startNextTimeEvent,NextTimeEvent].*/
  /* The maximum length is eventAccuracy */

  if (basicD->mNextTimeEvent>=1e30)
    did_->startNextTimeEvent_var=basicD->mNextTimeEvent;
    /* Initialization. Should be moved */

  /*DymosimMessageDouble("Register ",atTime);*/
  if (atTime>=basicD->mNextTimeEvent+eventAccuracy)
    return; /* Event in the far future, ignore */
  else if (atTime<did_->startNextTimeEvent_var) {
    /* First event in the interval */
    did_->startNextTimeEvent_var=atTime;
    if (did_->startNextTimeEvent_var+eventAccuracy<basicD->mNextTimeEvent) {
      /* Switch to a new interval: [atTime,atTime] */
      basicD->mNextTimeEvent=atTime;
    }
  } else if ((atTime<=did_->startNextTimeEvent_var+eventAccuracy)&&(atTime>basicD->mNextTimeEvent)) {
    /* Last event in the interval */
    basicD->mNextTimeEvent=atTime;
  }
  /*DymosimMessageDouble("Next time event",NextTimeEvent);*/
#endif
}
static double DymosimGetTime2() {
#if defined(DYN_MULTINSTANCE)
	if (DYN_GetThreadData()->did) {
		return DYN_GetThreadData()->did->time_var;
	}
#endif
	return tempData.time_var;
}
DYMOLA_STATIC int isModelicaEvent(void) {
#if defined(DYN_MULTINSTANCE)
	if (DYN_GetThreadData()->did) {
		return DYN_GetThreadData()->did->Event_var;
	}
#endif
	return tempData.Event_var;
}
DYMOLA_STATIC struct ExternalTable_* DymosimGetExternalObject() {
#if defined(DYN_MULTINSTANCE)
	if (DYN_GetThreadData()->did) {
		return DYN_GetThreadData()->did->externalTable_vec;
	}
#endif
	return tempData.externalTable_vec;
}
DYMOLA_STATIC double initialTime(void) {
#if defined(DYN_MULTINSTANCE)
	if (DYN_GetThreadData()->did) {
		return DYN_GetThreadData()->did->InitTime_var;
	}
#endif
	return tempData.InitTime_var;
}
DYMOLA_STATIC void SetDymolaEnforceWhen(struct DYNInstanceData*did_, int val) {
	if (did_) did_->enforceWhen_var=val;
	else tempData.enforceWhen_var=val;
}
DYMOLA_STATIC int GetDymolaOneIteration(struct DYNInstanceData*did_) {
	if (did_) return did_->DymolaOneIteration_var;
	return tempData.DymolaOneIteration_var;
}
DYMOLA_STATIC void SetDymolaOneIteration(struct DYNInstanceData*did_, int val) {
	if (did_) did_->DymolaOneIteration_var=val;
	else tempData.DymolaOneIteration_var=val;
}
DYMOLA_STATIC void SetDymolaEventOptional(struct DYNInstanceData*did_, int val) {
	if (did_) did_->DymolaEventOptional_var=val;
	else tempData.DymolaEventOptional_var=val;
}
DYMOLA_STATIC int GetDymolaHaveEventIterated(struct DYNInstanceData*did_) {
	if (did_) return did_->HaveEventIterated_var;
	else return tempData.HaveEventIterated_var;
}
DYMOLA_STATIC void SetDymolaJacobianPointers2(struct DYNInstanceData*did_, double * QJacobian_,double * QBJacobian_,double * QCJacobian_,double * QDJacobian_,int QJacobianN_,
	int QJacobianNU_,int QJacobianNY_,double * QJacobianSparse_,int * QJacobianSparseR_,int * QJacobianSparseC_,int QJacobianNZ_,int *QJacobianABCDNZ_) {
	if (!did_) did_=&tempData;
	did_->QJacobian_var=QJacobian_;
	did_->QBJacobian_var=QBJacobian_;
	did_->QCJacobian_var=QCJacobian_;
	did_->QDJacobian_var=QDJacobian_;
	did_->QJacobianN_var=QJacobianN_;
	did_->QJacobianNU_var=QJacobianNU_;
	did_->QJacobianNY_var=QJacobianNY_;	
	did_->QJacobianSparse_var=QJacobianSparse_;	
	did_->QJacobianSparseR_var=QJacobianSparseR_;
	did_->QJacobianSparseC_var=QJacobianSparseC_;
	did_->QJacobianNZ_var=QJacobianNZ_;
	did_->QSparseABCD_var=QJacobianABCDNZ_!=0;
	if (QJacobianABCDNZ_) *QJacobianABCDNZ_=
#ifdef AnalyticJacobianElementsABCD_
		AnalyticJacobianElementsABCD_
#else
		0
#endif
		;
}
DYMOLA_STATIC void SetDymolaJacobianPointers(struct DYNInstanceData*did_, double * QJacobian_,double * QBJacobian_,double * QCJacobian_,double * QDJacobian_,int QJacobianN_,
	int QJacobianNU_,int QJacobianNY_,double * QJacobianSparse_,int * QJacobianSparseR_,int * QJacobianSparseC_,int QJacobianNZ_) {
	SetDymolaJacobianPointers2(did_, QJacobian_, QBJacobian_, QCJacobian_, QDJacobian_, QJacobianN_, QJacobianNU_, QJacobianNY_, QJacobianSparse_, QJacobianSparseR_, QJacobianSparseC_, QJacobianNZ_, 0);
}
DYMOLA_STATIC struct DymolaTimes* GetDymolaTimers(struct DYNInstanceData*did_, int*len) {
	if (!did_) did_=&tempData;
	if (len) *len=did_->DymolaTimerStructsLen_var;
	return did_->DymolaTimerStructs_vec;
}

DYMOLA_STATIC void copyDStatesToDid(struct DYNInstanceData*did_, double* dStates, double* previousVars){
	if(!did_){
		did_=&tempData;
	}
	memcpy(did_->discreteState_var, dStates, ND_ * sizeof(double));
	memcpy(did_->pre_var, previousVars, NXP_ * sizeof(double));
}

DYMOLA_STATIC void copyDStatesFromDid(struct DYNInstanceData*did_, double* dStates, double* previousVars){
	if(!did_){
		did_=&tempData;
	}
	memcpy(dStates, did_->discreteState_var, ND_ * sizeof(double));
	memcpy(previousVars, did_->pre_var, NXP_ * sizeof(double));
}


DYMOLA_STATIC void fetchTempDataAndSizes(struct DYNInstanceData**did_, size_t * sz) {
	if (did_) { 
		*did_ = &tempData; 
	}
	if (sz) { 
		*sz = sizeof(tempData);
	}
}

DYMOLA_STATIC int* GlobalErrorPointer(void) {
#if defined(DYN_MULTINSTANCE)
	if (DYN_GetThreadData()->did) {
		return &(DYN_GetThreadData()->did->GlobalError_var);
	}
#endif
	return &(tempData.GlobalError_var);
}
DYMOLA_STATIC int dsblock_(int *idemand_, int *icall_, 
      double *time, double X_[], double XD_[], double U_[], 
      double DP_[], int IP_[], Dymola_bool LP_[], 
      double F_[], double Y_[], double W_[], double QZ_[], 
      double duser_[], int iuser_[], void* cuser_[],
	  int *QiErr)
{
	return dsblock_tid(idemand_, icall_, time, X_, XD_, U_, DP_, IP_, LP_, F_, Y_, W_, QZ_, duser_, iuser_, cuser_, &tempData, QiErr,  0);
}

struct DeclarePhase;
DYMOLA_STATIC void declareNew_(double x0_[], double dp_[], double du_[], void*cuser_[], int *QiErr, int setDefault_, struct DeclarePhase*);
DYMOLA_STATIC void declare_(double x0_[], double dp_[], double du_[], void*cuser_[], int *QiErr)
{
/* End dsblock4.c */
	declareNew_(x0_, dp_, du_, cuser_, QiErr, 0, 0);
}
DYMOLA_STATIC void declareNew_(double x0_[], double dp_[], double du_[], void*cuser_[], int *QiErr, int setDefault_, struct DeclarePhase*phase)
{
	int setDefaultX_=0,setDefaultU_=0,setDefaultY_=0,setDefaultP_=0,setDefaultDX_=0,setDefaultW_=0;
