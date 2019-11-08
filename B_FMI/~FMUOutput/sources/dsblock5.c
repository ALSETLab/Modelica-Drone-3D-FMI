/* Begin dsblock5.c */
/* File version: 1.4, 1998-03-20 */

/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

}



#undef externalTable_
#ifdef NBR_TASKS
DYMOLA_STATIC int nbrTasks_=NBR_TASKS;
#else
DYMOLA_STATIC int nbrTasks_=0;
#endif

#if !defined(DYMOLA_DSPACE) 
DYMOLA_STATIC double
DymolaStartTimers_[
#ifdef NrDymolaTimers_
NrDymolaTimers_ ? NrDymolaTimers_ : 1
#else
	1
#endif
];
DYMOLA_STATIC double DymolaTimeZero[100000]={0};
DYMOLA_STATIC int DymolaTimeZeroLength=100000;
#endif

#if !defined(DymolaHaveUpdateInitVars)
DYMOLA_STATIC void UpdateInitVars(double *time, double X_[], double XD_[], double U_[], \
      double DP_[], int IP_[], Dymola_bool LP_[], double F_[], double Y_[], double W_[], double QZ_[], double duser_[], int iuser_[], void*cuser_[], struct DYNInstanceData*did_,int initialCall) 
{
  return;
}
#endif



	  /* Must be initialized (and thus defined) because moutil is included first*/
	  static int DYNStrInit(struct DYNInstanceData*did_) {
		  if (DYNX(DYNAuxStr_,0)==0) {
			  int j;
			  for(j=0;j<sizeof(DYNAuxStr_)/sizeof(*DYNAuxStr_);++j) DYNAuxStr_[j]=did_->DYNAuxStrBuff_vec+j*
#if defined(MAXAuxStrLen_) && MAXAuxStrLen_>10
				  MAXAuxStrLen_
#else
				  10
#endif
				  ;
		  }
		  return 0;
	  }
	  DYMOLA_STATIC void DYNSetAuxString(struct DYNInstanceData*did_,const char*s,int i) {
		  DYNStrInit(did_);
		  if (i>=0 && i<sizeof(DYNAuxStr_)/sizeof(*DYNAuxStr_)) {
			  int j,mlen=
#if defined(MAXAuxStrLen_) && MAXAuxStrLen_>10
			MAXAuxStrLen_
#else
		  10
#endif
		      ;
			  for(j=0;j<mlen-1 && s[j];++j) DYNAuxStr_[i][j]=s[j];
			  DYNAuxStr_[i][j]=0;
			  if (s[j]) {DymosimMessage("Truncated string variable to");DymosimMessage(DYNAuxStr_[i]);}
		  } else DymosimMessage("Internal error in String handling.");
	  }
	  DYMOLA_STATIC void DYNSetAuxStringArray(struct DYNInstanceData*did_,struct StringArray s,int i) {
		  int nrElem,j;
		  nrElem=StringNrElements(s);
		  if (i>=0 && i+nrElem<=sizeof(DYNAuxStr_)/sizeof(*DYNAuxStr_)) {
			  for(j=0;j<nrElem;++j) {
				  DYNSetAuxString(did_,s.data[j],i+j);
			  }
		  } else DymosimMessage("Internal error in String array handling.");
	  }
	  DYMOLA_STATIC const char*DYNGetAuxStr(struct DYNInstanceData*did_,int i) {
		  DYNStrInit(did_);
		  if (i>=0 && i<sizeof(DYNAuxStr_)/sizeof(*DYNAuxStr_)) {
			  return DYNAuxStr_[i];
		  }
		  return "";
	  }
	  static int QNLfunc_vec[QNLmax_ ? QNLmax_ : 1] = {0};
	  DYMOLA_STATIC int* QNLfunc = QNLfunc_vec;
	  static int QNLjac_vec[QNLmax_ ? QNLmax_ :1] = {0};
	  DYMOLA_STATIC int* QNLjac = QNLjac_vec;
	  DYMOLA_STATIC int QNLmax=QNLmax_;
	  static int QNLcalls_vec[QNLmax_ ? QNLmax_ : 1] = { 0 };
	  DYMOLA_STATIC int* QNLcalls = QNLcalls_vec;
#if !defined(NExternalObject_)
#define NExternalObject_ 10
#endif
	  
	  static int delayID_vec[SizeDelay_?SizeDelay_:1] = {0};
	  DYMOLA_STATIC int* delayID = delayID_vec;
	  DYMOLA_STATIC int Buffersize = 20000;
	  DYMOLA_STATIC int setDefault_=0;
	  DYMOLA_STATIC int setDefaultX_=0,setDefaultU_=0,setDefaultY_=0,setDefaultP_=0,setDefaultDX_=0,setDefaultW_=0;
	  DYMOLA_STATIC LIBDS_API_AFTER void freeDelay(delayStruct* del, const size_t nbrDel);
DYMOLA_STATIC void delayBuffersCloseNew(struct DYNInstanceData*did_) {
	int i;
	 for(i=0;i<SizeDelay_;++i) delayID[i]=0;
	 for(i=0;i<MAXAux+10000;++i) Aux_[i]=0;
	 for(i=0;i<SizePre_;++i) QPre_[i]=0;
	 for(i=0;i<SizePre_;++i) RefPre_[i]=0;
	 for(i=0;i<SizeEq_;++i) EqRemember2_[i]=EqRemember1_[i]=EqRememberTemp_[i]=0;
	 for(i=0;i<NWhen_;++i) QEvaluateNew_[i]=QEvaluate_[i]=0;
	 for(i=0;i<NGlobalHelp_;++i) DYNhelp[i]=0;
	 for(i=0;i<NGlobalHelpI_;++i) did_->helpvari_vec[i]=0;
	 for(i=0;i<2*NRel_+1;++i) 
      oldQZ2_[i]=oldQZ3_[i] =  QZold_[i]=oldQZ_[i]=oldQZDummy_[i]=0;
	 for(i=0;i<NRel_+1;++i) QRel_[i]=QM_[i]=Qn_[i] = Qp_[i]=Qscaled_[i]=0.0;
	 for(i=0;i<NSamp_;++i) {NextSampleTime_[i]=NextSampleTimeNew_[i]=0;NextSampleAct_[i]=NextSampleActNew_[i]=0;}
	 for(i=0;i<NRel_+1;++i) QL_[i]=Qenable_[i]=0;
	 for(i=0;i<NTim_+1;++i) QTimed_[i]=0;
	 EqRemember1Time_=-1e33;
	 EqRemember2Time_=-1e33;
	 EqRemAcc1Time_ = -1e33;
	 EqRemAcc2Time_ = -1e33;
	 EqRemTempTime_ = -1e33;
	 EqRemTempTimeAcc_ = -1e33;
	 (did_->hasStoredInTemp) = 0;
	 (did_->eqRememberReplaceOldDynamics) = 0;
	 (did_->eqRememberReplaceOldAccepted) = 0;
	 (did_->decoupleTime_var)=-1e33;
	 for (i = NExternalObject_ - 1; i >= 0; --i) {
		 /* Reverse order in case of dependencies */
		 void*x = did_->externalTable_vec[i].obj_;
		 did_->externalTable_vec[i].obj_ = 0;
		 if (x && did_->externalTable_vec[i].destructor_)
			 (*(did_->externalTable_vec[i].destructor_))(x);
		 did_->externalTable_vec[i].destructor_ = 0;
#if (defined(_OPENMP) && !defined(DISABLE_DYMOLA_OPENMP))
		 if (did_->externalTable_vec[i].haveLock_) {
			 omp_destroy_lock(&(did_->externalTable_vec[i].lockExternal_));
			 did_->externalTable_vec[i].haveLock_ = 0;
	     }
#endif
	 }
	 for(i=0;i<did_->DymolaTimerStructsLen_var;i++) {
		 did_->DymolaTimerStructs_vec[i].num=0;
	 }
	 freeDelay(did_->del_vec, SizeDelay_ ? SizeDelay_ : 1);
}
DYMOLA_STATIC void delayBuffersClose(void) {
	delayBuffersCloseNew(&tempData);
}
DYMOLA_STATIC int dynInstanceDataSize() {
	return sizeof(struct DYNInstanceData);
}

DYMOLA_STATIC void CheckForEvents(struct DYNInstanceData*did_,double Time, int Init, int Event, 
       double QZ_[], int nrel_, double F_[], int nx_,double*duser_,int*iuser_)
/* SCRAMBLE ON */
{
#define DebugCheckForEvents 0
 

#define OvershootFactor 1.2
 	/* */
#define FindLastEvent 1
 	/* */
#define CheckForEventsEps 1e-10
 	/* */ 
#define SecondDegreeOvershootFactor 1.04

#define SecondDegreeUncertainty 0.4


#define SecondDegreeUncertainty2 0.7
    int ZZZ715,ZZZ39;   static double oldTime,oldDummyTime=-1e30;
   static double oldTime2, oldDummyTime2, oldstepSizeRatio;
   static double c1, c2, c1start;   static double T1end=-1e30;   static double T2end=-1e30, stepSizeRatio=1;   double ZZZ8329, ZZZ7652;

#ifdef InterpolateStatesForInline
   static const double CheckForEventsMinStep=0.2;
#else
   static const double CheckForEventsMinStep=0;
#endif
   int ZZZ5998;    if (Init) {
#if defined(FindEvent_)
     DymosimMessage("");
     DymosimMessage("Approximative event finder used. Must be used with Euler method.");     DymosimMessage("");
#endif
     StepSize = 0;     LastTime = 1E30;     T1end = -1E30;     T2end = -1E30; 	oldTime = Time; 	oldDummyTime = -1e30;
#if SecondDegree
 	oldTime2 =  oldDummyTime2 = Time; oldstepSizeRatio = 1.0;
#endif
 	c1=1; 	c2=1; 	c1start=1; 	stepSizeRatio=1;   }   if (StepSize == 0 && Time > LastTime)     StepSize = Time - LastTime; 
   if (Event)      LastTime = Time;    ZZZ5998 = Time>oldDummyTime;   if (ZZZ5998) 	{
#if SecondDegree
 	  oldTime2=oldTime; 	  oldDummyTime2=oldDummyTime; 	  oldstepSizeRatio=stepSizeRatio;
 	  if (StepSize!=0) { 		  if (Time>=T1end && Time<T2end) 			  stepSizeRatio = (T1end-oldTime)/StepSize; 		  else 			  stepSizeRatio = (Time-oldTime)/StepSize; 	  } 	  for (ZZZ715 = 0; ZZZ715 < 2*nrel_;ZZZ715++) {oldQZ3_[ZZZ715]=oldQZ2_[ZZZ715];oldQZ2_[ZZZ715]=oldQZ_[ZZZ715];}
#endif
 	  for(ZZZ715=0;ZZZ715<2*nrel_;ZZZ715++) oldQZ_[ZZZ715]=oldQZDummy_[ZZZ715];   }	
   { 	  for(ZZZ715=0;ZZZ715<2*nrel_;ZZZ715++) oldQZDummy_[ZZZ715]=Qenable_[ZZZ715/2+1] ? QZ_[ZZZ715] : 0;   }    if (StepSize!=0 && ZZZ5998) { 	  
#if DebugCheckForEvents
	   double ZZZ1317 = 0;  for (ZZZ715 = 0; ZZZ715 < 2*nrel_; ZZZ715++)  { 		  if (Qenable_[ZZZ715/2+1]) { 			  if (oldQZ_[ZZZ715]*QZ_[ZZZ715]<0) {
 				  double ZZZ8860; 				  ZZZ8860=QZ_[ZZZ715]/(QZ_[ZZZ715]-oldQZ_[ZZZ715]); 				  if (ZZZ8860>ZZZ1317) {ZZZ1317=ZZZ8860;ZZZ39=ZZZ715/2;} 			  } 		  } 	  } 	  if (ZZZ1317>0) { 		  char ZZZ732[200]; 		  if (Time<T2end) { 			  sprintf(ZZZ732,"Event at projected time %.10g overshoot %.10g",T1end,c1*ZZZ1317+1);
 		  } else if (stepSizeRatio>1+CheckForEventsEps || stepSizeRatio<1-CheckForEventsEps) { 			  sprintf(ZZZ732,"Missed event at time %.10g interpolated at %.10g",Time,Time-ZZZ1317*stepSizeRatio*StepSize); 		  } else { 			  sprintf(ZZZ732,"Event at time %.10g interpolated at %.10g",Time,Time-ZZZ1317*StepSize); 		  } 		  DymosimMessage(ZZZ732);
#if SecondDegree
 		  sprintf(ZZZ732,"Relation %d QZ=%.10g %.10g oldQZ=%.10g oldQZ2=%.10g oldQZ3=%.10g",ZZZ39,QZ_[2*ZZZ39],QZ_[2*ZZZ39+1],oldQZ_[2*ZZZ39],oldQZ2_[2*ZZZ39],oldQZ3_[2*ZZZ39]);
#else
 		  sprintf(ZZZ732,"Relation %d QZ=%.10g %.10g oldQZ=%.10g",ZZZ39,QZ_[2*ZZZ39],QZ_[2*ZZZ39+1],oldQZ_[2*ZZZ39]);

#endif
 		  DymosimMessage(ZZZ732); 	  }
#endif
 	     }    if (StepSize != 0 && Time >= T2end) {     c1 = c1start = FindLastEvent ? 0 :2; 	ZZZ7652 = (NextTimeEvent-Time)/StepSize; /* */
 	ZZZ39=-1; 	if (ZZZ7652>0 && ZZZ7652<2 && (FindLastEvent ? ZZZ7652>c1: ZZZ7652<c1)) { 		c1=ZZZ7652; 	}     for (ZZZ715 = 0; ZZZ715 < 2*nrel_; ZZZ715++) {        ZZZ8329 = (QZ_[ZZZ715] - oldQZ_[ZZZ715])/stepSizeRatio;       if (QZ_[ZZZ715] * (OvershootFactor*ZZZ8329*2 + QZ_[ZZZ715]) < 0 && Qenable_[ZZZ715/2+1] && QZ_[2*(ZZZ715/2)]*QZ_[2*(ZZZ715/2)+1]>0 ) {         /* */         ZZZ7652 = -QZ_[ZZZ715]/ZZZ8329+(OvershootFactor-1);  /* */
#if SecondDegree
 		if (oldDummyTime2>-1e30 && (oldQZ_[ZZZ715]>0 ? oldQZ2_[ZZZ715]>oldQZ_[ZZZ715] : oldQZ2_[ZZZ715]<oldQZ_[ZZZ715])) { 			/* */ 			double ZZZ3419, ZZZ8687, ZZZ4213, ZZZ2231, ZZZ4006, ZZZ6591, ZZZ5281, ZZZ8430, ZZZ7134; 			ZZZ3419=QZ_[ZZZ715]; 			ZZZ8687=(stepSizeRatio+oldstepSizeRatio); 			ZZZ4213=stepSizeRatio*ZZZ8687*oldstepSizeRatio; 			ZZZ2231=(ZZZ8687*ZZZ8687*(oldQZ_[ZZZ715]-ZZZ3419)-stepSizeRatio*stepSizeRatio*(oldQZ2_[ZZZ715]-ZZZ3419))/ZZZ4213; 			ZZZ4006=(-ZZZ8687*(oldQZ_[ZZZ715]-ZZZ3419)+stepSizeRatio*(oldQZ2_[ZZZ715]-ZZZ3419))/ZZZ4213; 			ZZZ6591=4*ZZZ3419*ZZZ4006; 			ZZZ5281=ZZZ2231*ZZZ2231;
 			ZZZ8430=(oldQZ_[ZZZ715]>0 ? oldQZ3_[ZZZ715]>oldQZ2_[ZZZ715] : oldQZ3_[ZZZ715]<oldQZ2_[ZZZ715])  				? SecondDegreeUncertainty : SecondDegreeUncertainty2; 			ZZZ7134=ZZZ5281-(ZZZ6591>0 ? ZZZ6591*(1+ZZZ8430) : ZZZ6591*(1-ZZZ8430)); 			if (ZZZ7134>=0) { 			double ZZZ5803; 			ZZZ5803=-(2*ZZZ3419/(-ZZZ2231-(ZZZ2231>0?1:-1)*sqrt(ZZZ7134)))+(SecondDegreeOvershootFactor-1);
#if DebugCheckForEvents
 			{char ZZZ732[200]; 			sprintf(ZZZ732,"%d ZZZ3419 %.10g ZZZ8687 %.10g ZZZ4213 %.10g ZZZ2231 %.10g ZZZ7652 %.10g ZZZ7134 %.10g",ZZZ715,ZZZ3419,ZZZ8687,ZZZ4213,ZZZ2231,ZZZ4006,ZZZ7134); 			DymosimMessage(ZZZ732);
 			sprintf(ZZZ732,"C1: %g C2: %g beta=-%g alpha=-%g QZ=%.10g oldQZ=%.10g oldQZ2=%.10g",ZZZ7652,ZZZ5803,stepSizeRatio+oldstepSizeRatio,stepSizeRatio, 				QZ_[ZZZ715],oldQZ_[ZZZ715],oldQZ2_[ZZZ715]); 			DymosimMessage(ZZZ732); 			}
#endif
 			if (ZZZ5803>-0.5 && ZZZ5803 < 2.5) ZZZ7652=ZZZ5803; 			} 		}
#endif
         if (ZZZ7652 > 0 && ZZZ7652<2 && (FindLastEvent ? ZZZ7652>c1: ZZZ7652<c1)) {       /* */
           c1 = ZZZ7652;      /* */ZZZ39=ZZZ715/2;         }       }     }      if (c1 != 1E30 && c1 != c1start && c1<1+CheckForEventsMinStep) {       /* */ 	  if (c1<CheckForEventsMinStep) c1=CheckForEventsMinStep;       c2 = 2 - c1;       
       T1end = Time + (1-CheckForEventsEps)*StepSize;            T2end = Time + (2-CheckForEventsEps)*StepSize; /* */
#if DebugCheckForEvents
 	  {char ZZZ732[200]; 	  sprintf(ZZZ732,"Project at %.10g to %.10g Short %.10g Long %.10g",Time,T1end,c1*StepSize,c2*StepSize); 	  DymosimMessage(ZZZ732);} 	  {char ZZZ732[200];
#if SecondDegree
 	  sprintf(ZZZ732,"Relation %d QZ=%.10g %.10g oldQZ=%.10g oldQZ2=%.10g oldQZ3=%.10g",ZZZ39,QZ_[2*ZZZ39],QZ_[2*ZZZ39+1],oldQZ_[2*ZZZ39],oldQZ2_[2*ZZZ39],oldQZ3_[2*ZZZ39]);
#else
 	  sprintf(ZZZ732,"Relation %d QZ=%.10g %.10g oldQZ=%.10g",ZZZ39,QZ_[2*ZZZ39],QZ_[2*ZZZ39+1],oldQZ_[2*ZZZ39]);
#endif
 	  DymosimMessage(ZZZ732); 	  }
#endif
 	} else { 		c2=1; 		T2end=Time; 		T1end=Time; 	}
   }   oldTime=oldDummyTime=Time;    currentStepSize_ = StepSize;
#ifdef InterpolateStatesForInline
   currentStepSizeRatio_ = 1;
#endif
   currentStepSizeRatio2_ = 1;    if (Time < T1end) {
 	currentStepSizeRatio2_ = c1;
#ifdef InterpolateStatesForInline
 	currentStepSizeRatio_ = c1;
#else
     currentStepSize_ = c1*StepSize;
#endif
     for (ZZZ715 = 0; ZZZ715 < nx_; ZZZ715++) {       F_[ZZZ715] = F_[ZZZ715]*c1;     }     /* */
   } else if (Time < T2end) { 	currentStepSizeRatio2_ = c2;
#ifdef InterpolateStatesForInline
 	currentStepSizeRatio_ = c2;
#else
     currentStepSize_ = c2*StepSize;
#endif
     for (ZZZ715 = 0; ZZZ715 < nx_; ZZZ715++) {       F_[ZZZ715] = F_[ZZZ715]*c2;     }
     /* */ 	oldTime=T1end;   }}

/* SCRAMBLE OFF */

DYMOLA_STATIC int sprintfC(char*s, const char*format, ...);

DYMOLA_STATIC Dymola_bool sampleFunction(struct DYNInstanceData*did_,double Time, double start, double interval, int counter,
                      Dymola_bool Init, Dymola_bool Event) {
  struct BasicDDymosimStruct*basicD=getBasicDDymosimStruct();
  Dymola_bool samp = false;

  if (Init  || (Event && NextSampleAct_[counter]==0)) {
	double x;
    basicD->mOrigTimeError=Dymola_max(basicD->mOrigTimeError,fabs(start)); /* Collect them */

    x=findCounter(Dymola_max(Time,start),start,interval);
	if (Init || x>NextSampleTime_[counter])
		NextSampleTime_[counter]=x;
    /* Samples at start,start+interval,...*/
    /* Replace Dymola_max(Time,start) by Time to sample at ...,start-interval,start,start+interval */
  };

  if (Event) {
    double eventTime=start+(NextSampleTime_[counter]-1)*interval;
    const double eventAccuracy=
#ifndef DynSimStruct
		5e-14
#else 
		1e-7
#endif
		*(fabs(Time)+basicD->mOrigTimeError);
    /* 5*eps to guard against different times */
      /*DymosimMessageDouble("Event at time: ",Time);*/
      /*DymosimMessageDouble("Event Time:",eventTime);*/
    while (eventTime<=Time+eventAccuracy) {
      NextSampleTime_[counter]+=1;
      eventTime=start+(NextSampleTime_[counter]-1)*interval;
      /*DymosimMessageDouble("Sampling at time: ", Time);*/
      /*DymosimMessageDouble("Next sampling",eventTime);*/
      samp = true;
	}
	NextSampleTimeNew_[counter]=NextSampleTime_[counter];
	NextSampleActNew_[counter]=1;
    registerTimeEventNew(eventTime, did_); /* The next event for this sampler */

	samp = samp && (Iter == 1);
	{
		struct BasicIDymosimStruct* basicI = getBasicIDymosimStruct();
		if (samp && basicI->mPrintEvent&(1 << 1) && (!Init || basicI->mPrintEvent&(1 << 2))) {
			char str[60], message_str[100];
			sprintfC(str, "sample(%g,%g)", start, interval);
			DynLogEvents(-1, 0, 1, str, 1, 0);
			sprintfC(message_str, "Sample event (%.60s) at time:", str);
			DymosimMessageDouble(message_str, DYNTime);
		}
	}
  }
  return samp;
}
DYMOLA_STATIC double DYNTimeFloorEvent(int do_divide, double y, struct DYNInstanceData*did_, double time, Dymola_bool*AnyEvent, Dymola_bool*AnyDEvent, int sampleCounter, int pr, int DymolaOneIteration, const char*str) {
	double res = did_->NextSampleTime_vec[sampleCounter];
	int wasZero;
	if (!AnyEvent) return 0;
	wasZero = (0 == res);
	{
		const double currVal = do_divide ? (time / y) : (time*y);
		if (res > 0) res -= 1.0;
		if (wasZero || currVal<res || currVal >= res + 1) {
			if (AnyDEvent) *AnyDEvent = 1;
			if (pr) {
				DymosimMessageDouble("Time event at time:", time);
				DynLogEvents(-1, 0, 1, str, 1, res);
			}
			*AnyEvent = 1;
			/* Update res */
			res = floor(currVal);
			did_->NextSampleTimeNew_vec[sampleCounter] = (res >= 0) ? res + 1 : res;
		}
		{
			/* Compute new time event point */
			double resNext = (y > 0) ? (res + 1) : (res);
			volatile double tNext = do_divide ? (resNext*y) : (resNext / y);
			if (do_divide ? floor(tNext / y) == res : floor(tNext*y) == res) {
#if defined(_MSC_VER) ? (_MSC_VER>=1800) : (__STDC_VERSION__>199901L)
				tNext = nextafter(tNext, DBL_MAX)+1e-20*fabs((do_divide?(1/y):y));
#else
				tNext = tNext*(1 + DBL_EPSILON) + 1e-20*fabs((do_divide ? (1 / y) : y));
#endif
			}
			registerTimeEventNew(tNext, did_);
		}
	}
	{
		return res;
	}
}
DYMOLA_STATIC Dymola_bool sampleFunctionM(struct DYNInstanceData*did_,double Time, double start, double interval, int counter,
                      Dymola_bool Init, Dymola_bool Event) {
  struct BasicDDymosimStruct*basicD=getBasicDDymosimStruct();
  Dymola_bool samp = false;
  if (interval<=0) DymosimError("Sample did not have positive sample interval");
  if (Init|| (Event && NextSampleTime_[counter]==0)) {
	  double x;
	if (Init==2) return false; 
    basicD->mOrigTimeError=Dymola_max(basicD->mOrigTimeError,fabs(start)); /* Collect them */

	x=findCounter(Dymola_max(Time,start),start,interval);
	if (Init || x>NextSampleTime_[counter])
		NextSampleTime_[counter]=x;
    /* Samples at start,start+interval,...*/
    /* Replace Dymola_max(Time,start) by Time to sample at ...,start-interval,start,start+interval */
  };

  if (Event) {
    double eventTime=start+(NextSampleTime_[counter]-1)*interval;
    const double eventAccuracy=
#ifndef DynSimStruct
		5e-14
#else 
		1e-7
#endif
		*(fabs(Time)+basicD->mOrigTimeError);
    /* 5*eps to guard against different times */
      /*DymosimMessageDouble("Event at time: ",Time);*/
      /*DymosimMessageDouble("Event Time:",eventTime);*/
	NextSampleTimeNew_[counter]=NextSampleTime_[counter];
    while (eventTime<=Time+eventAccuracy) {
      NextSampleTimeNew_[counter]+=1;
      eventTime=start+(NextSampleTimeNew_[counter]-1)*interval;
      /*DymosimMessageDouble("Sampling at time: ", Time);*/
      /*DymosimMessageDouble("Next sampling",eventTime);*/
      samp = true;
    }

	NextSampleActNew_[counter]=1;
    registerTimeEventNew(eventTime, did_); /* The next event for this sampler */

	samp = samp && (Iter == 1);
	{
		struct BasicIDymosimStruct* basicI = getBasicIDymosimStruct();
		if (samp && basicI->mPrintEvent&(1 << 1) && (!Init || basicI->mPrintEvent&(1 << 2))) {
			char str[60], message_str[100];
			sprintfC(str, "sample(%g,%g)", start, interval);
			DynLogEvents(-1, 0, 1, str, 1, 0);
			sprintfC(message_str, "Sample event (%.60s) at time:", str);
			DymosimMessageDouble(message_str, DYNTime);
		}
	}
  }
  return samp;
}
DYMOLA_STATIC Dymola_bool sampleFunctionM3(struct DYNInstanceData*did_,double Time, double start, double interval, int phase, int maxVal, int counter,
                      Dymola_bool Init, Dymola_bool Event) {
  struct BasicDDymosimStruct*basicD=getBasicDDymosimStruct();
  double x,x2;
  Dymola_bool samp = false;
  if (interval<=0 || maxVal<=0) DymosimError("Sample did not have positive sample interval");
  if (Init|| (Event && NextSampleTime_[counter]==0)) {
	if (Init==2) return false; 
    basicD->mOrigTimeError=Dymola_max(basicD->mOrigTimeError,fabs(start)); /* Collect them */

	x=findCounter(Dymola_max(Time,start),start,interval);
	if (Init || x>NextSampleTime_[counter])
		NextSampleTime_[counter]=x;
    /* Samples at start,start+interval,...*/
    /* Replace Dymola_max(Time,start) by Time to sample at ...,start-interval,start,start+interval */
  };

  if (Event) {
    double eventTime=start+(NextSampleTime_[counter]-1)*interval;
    const double eventAccuracy=
#ifndef DynSimStruct
		5e-14
#else 
		1e-7
#endif
		*(fabs(Time)+basicD->mOrigTimeError);
    /* 5*eps to guard against different times */
      /*DymosimMessageDouble("Event at time: ",Time);*/
      /*DymosimMessageDouble("Event Time:",eventTime);*/
	NextSampleTimeNew_[counter]=NextSampleTime_[counter];
    while (eventTime<=Time+eventAccuracy) {
      NextSampleTimeNew_[counter]+=1;
      eventTime=start+(NextSampleTimeNew_[counter]-1)*interval;
      /*DymosimMessageDouble("Sampling at time: ", Time);*/
      /*DymosimMessageDouble("Next sampling",eventTime);*/
	  samp=true;
    }
	x=floor((0.1+NextSampleTimeNew_[counter]-2-(maxVal-1-phase))/maxVal); /* the passed point */
	x2=x*maxVal+(maxVal-1-phase);
	samp=samp && (x2==(NextSampleTimeNew_[counter]-2)) && x>=0; /* Handle negative phase */
	eventTime=start+(x2+maxVal)*interval;
	NextSampleActNew_[counter]=1;
    registerTimeEventNew(eventTime, did_); /* The next event for this sampler */

	samp = samp && (Iter == 1);
	{
		struct BasicIDymosimStruct* basicI = getBasicIDymosimStruct();
		if (samp && basicI->mPrintEvent&(1 << 1) && (!Init || basicI->mPrintEvent&(1 << 2))) {
			char str[60], message_str[100];
			sprintfC(str, "sample(%g,%g)", start, interval);
			DynLogEvents(-1, 0, 1, str, 1, 0);
			sprintfC(message_str, "Sample event (%.60s) at time:", str);
			DymosimMessageDouble(message_str, DYNTime);
		}
	}
  }
  return samp;
}
#if defined(DYMOSIM) && defined(NI_)
LIBDS_API void InitI2(int, int, double*,int*);
static void InitI(struct DYNInstanceData* did_,int n,int d) {
	InitI2(n, d, QImd_, QIml_);
}
#else
static void InitI(struct DYNInstanceData* did_,int n,int d) {
	;
}
#endif
DYMOLA_STATIC void ClearNextSample(struct DYNInstanceData* did_) {
	int i;
	 for(i=0;i<NSamp_;++i) NextSampleActNew_[i]=0;
}

#if defined(DIRECT_FEED_THROUGH)
	  DYMOLA_STATIC int DirectFeedThrough_=1;
#else
	  DYMOLA_STATIC int DirectFeedThrough_=0;
#endif


#if DymolaUseRDTSC_
#if defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
#include "intrin.h"
#endif
static double rtdrealFrequency=1.0e9; 
static double rtdinvFreq=1.0/1.0e9;
struct MyLargeInteger {
	unsigned int LowPart;
	unsigned int HighPart;
};
static const double MInt=4294967296.0;

static double DymolaPerformance(double*d,int i) {
	struct MyLargeInteger count={0,0};
	if (sizeof(struct MyLargeInteger)!=sizeof(*d))
		return -1;
	{
#if defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
		(*(unsigned __int64*)&count)=__rdtsc();
#elif defined(__GNUC__)
		/* Gnu assembler: other names of registers, declare that rdtsc clobbers registers
		   and different order of operands */
		__asm("rdtsc" : /* none */ : : "eax", "edx" );
		__asm("mov %%eax, %0" : "=g" (count.LowPart));
		__asm("mov %%edx, %0" : "=g" (count.HighPart));
#elif defined(__LCC__)
		/* Lcc, default in Matlab, has it as an intrinsic function */
		extern long long _stdcall _rdtsc(void);
		{
			*(long long*)(&count)=_rdtsc();
		}
#endif

	}
	if (i==0) {
		if (d) *(struct MyLargeInteger*)(d)=count;
		return count.LowPart+count.HighPart*MInt;
	} else {
		struct MyLargeInteger*a=(struct MyLargeInteger*)(d);
		return (
			(count.HighPart*1.0-a->HighPart)*MInt+count.LowPart-a->LowPart)*rtdinvFreq;
	}
}
struct RegisterReturn {
	int EAXV1,EBXV1,ECXV1,EDXV1;
	int EAXV2,EBXV2,ECXV2,EDXV2;
	int EAXV3,EBXV3,ECXV3,EDXV3;
};
static void InitializeFrequency(double d) {
#if defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
	int dummy[4];
#endif
	static int firstCall=1;
	if (!firstCall) return;
	firstCall=0;
	if (d==0) {
		unsigned int x=0x80000000UL;
		union {
			struct RegisterReturn registerReturn;
			char ch[48];
		} myValues;
		myValues.ch[0]='\0';
#if defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
		__cpuid(dummy,x);
		x=dummy[0];
#elif defined(__GNUC__) && defined(i386)
		__asm("mov %0, %%eax": /*none */: "g" (x));
		__asm("cpuid");
		__asm("mov %%eax, %0" : "=g" (x));
#endif
		if (x>=0x80000004UL) {
			x=0x80000002UL;
#if defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
		__cpuid(dummy,x);
		myValues.registerReturn.EAXV1=dummy[0];
		myValues.registerReturn.EBXV1=dummy[1];
		myValues.registerReturn.ECXV1=dummy[2];
		myValues.registerReturn.EDXV1=dummy[3];
#elif defined(__GNUC__) && defined(i386)
			__asm("mov %0, %%eax": : "g" (x));
			__asm("cpuid" : : : "eax", "ebx", "ecx", "edx");
			__asm("mov %%eax, %0": "=g" (myValues.registerReturn.EAXV1));
			__asm("mov %%ebx, %0": "=g" (myValues.registerReturn.EBXV1));
			__asm("mov %%ecx, %0": "=g" (myValues.registerReturn.ECXV1));
			__asm("mov %%edx, %0": "=g" (myValues.registerReturn.EDXV1));
#endif
			x=0x80000003UL;
#if defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
		__cpuid(dummy,x);
		myValues.registerReturn.EAXV2=dummy[0];
		myValues.registerReturn.EBXV2=dummy[1];
		myValues.registerReturn.ECXV2=dummy[2];
		myValues.registerReturn.EDXV2=dummy[3];
#elif defined(__GNUC__) && defined(i386)
			__asm("mov %0, %%eax": : "g" (x));
			__asm("cpuid" : : : "eax", "ebx", "ecx", "edx");
			__asm("mov %%eax, %0": "=g" (myValues.registerReturn.EAXV2));
			__asm("mov %%ebx, %0": "=g" (myValues.registerReturn.EBXV2));
			__asm("mov %%ecx, %0": "=g" (myValues.registerReturn.ECXV2));
			__asm("mov %%edx, %0": "=g" (myValues.registerReturn.EDXV2));
#endif
			x=0x80000004UL;
#if defined(_MSC_VER) && (defined(_M_AMD64)||defined(_M_IX86))
		__cpuid(dummy,x);
		myValues.registerReturn.EAXV3=dummy[0];
		myValues.registerReturn.EBXV3=dummy[1];
		myValues.registerReturn.ECXV3=dummy[2];
		myValues.registerReturn.EDXV3=dummy[3];
#elif defined(__GNUC__) && defined(i386)
			__asm("mov %0, %%eax": : "g" (x));
			__asm("cpuid" : : : "eax", "ebx", "ecx", "edx");
			__asm("mov %%eax, %0": "=g" (myValues.registerReturn.EAXV3));
			__asm("mov %%ebx, %0": "=g" (myValues.registerReturn.EBXV3));
			__asm("mov %%ecx, %0": "=g" (myValues.registerReturn.ECXV3));
			__asm("mov %%edx, %0": "=g" (myValues.registerReturn.EDXV3));
#endif
			{
				double dMult=1e6;
				char*lastM=strrchr(myValues.ch,'M');
				if (lastM!=0 && lastM[1]=='H' && lastM[2]=='z') {
				} else {
					lastM=strrchr(myValues.ch,'G');
					if (lastM!=0 && lastM[1]=='H' && lastM[2]=='z') {
						dMult=1e9;
					} else lastM=0;
				}
				if (lastM!=0) {
					for(;lastM>myValues.ch && lastM[-1]==' ';lastM--);
					for(;lastM>myValues.ch && (lastM[-1]>='0' && lastM[-1]<='9' || lastM[-1]=='.');lastM--);
					if (sscanf(lastM,"%lg",&d)!=1) {
						d=0;
					} else d*=dMult;
				}
			}
				
		}
		if (d==0) {
			char str[200];
			sprintf(str,"Could not determine speed of processor. Assuming 1GHz\nCPU reported: %s\n",myValues.ch);
			DymosimMessage(str);
			d=1e9;
		} else {
			char str[200];
			sprintf(str,"Determined processor speed to %lg MHz\nCPU reported: %s\n",d/1e6,myValues.ch);
			DymosimMessage(str);
		}
	}
	rtdrealFrequency=d;
	rtdinvFreq=1.0/rtdrealFrequency;
	{
		extern double (*DymolaTimerCounterCallback)(double*,int);
		DymolaTimerCounterCallback=&DymolaPerformance;
	}
}
#if defined(DymolaUseRDTSCFrequency_)
#define SetupProcessorCounter() InitializeFrequency(DymolaUseRDTSCFrequency_)
#else 
#define SetupProcessorCounter() InitializeFrequency(0.0)
#endif

#else
#define SetupProcessorCounter()
#endif

DYMOLA_STATIC void GetDimensions(int *nx_, int *nx2_, int *nu_, int *ny_, int *nw_, int *np_, 
  int *nrel_, int *ncons_, int *dae_)
{
      *nx_ = NX_;
      *nx2_ = NX2_; 
      *nu_ = NU_;
      *ny_ = NY_;
      *nw_ = NW_;
      *np_ = NP_;
      *nrel_ = NRel_;
      *ncons_ = NCons_;
      *dae_ = DAEsolver_;
#if  defined(DynSimStruct)
	  SetupProcessorCounter();
#endif
}

DYMOLA_STATIC void GetDimensions2(int *nx_, int *nx2_, int *nu_, int *ny_, int *nw_, int *np_, int* nsp_,
  int*nrel2_,int *nrel_, int *ncons_, int *dae_)
{
      *nx_ = NX_;
      *nx2_ = NX2_; 
      *nu_ = NU_;
      *ny_ = NY_;
      *nw_ = NW_;
#ifdef NPS_
	  *nsp_ = NPS_;
#else
	  *nsp_ = 0;
#endif
      *np_ = NP_;
      *nrel_ = NRel_;
#ifdef NRelF_
	  *nrel2_ = NRelF_;
#else
	  *nrel2_ = NRel_;
#endif
      *ncons_ = NCons_;
      *dae_ = DAEsolver_;
#if  defined(DynSimStruct)
	  SetupProcessorCounter();
#endif
}

DYMOLA_STATIC void GetDimensions4(int *nx_, int *nx2_, int *nu_, int *ny_, int *nw_, int *np_, int* nsp_,
  int*nrel2_,int *nrel_, int *ncons_, int *dae_, int *nd_, int* nxp_){
	  *nx_ = NX_;
      *nx2_ = NX2_; 
      *nu_ = NU_;
      *ny_ = NY_;
      *nw_ = NW_;
#ifdef NPS_
	  *nsp_ = NPS_;
#else
	  *nsp_ = 0;
#endif
      *np_ = NP_;
      *nrel_ = NRel_;
#ifdef NRelF_
	  *nrel2_ = NRelF_;
#else
	  *nrel2_ = NRel_;
#endif
      *ncons_ = NCons_;
      *dae_ = DAEsolver_;
	  *nd_ = ND_;
	  *nxp_ = NXP_;
#if  defined(DynSimStruct)
	  SetupProcessorCounter();
#endif
}
      
static int nx_=NX_;
static int nx2_=NX2_;
static int nu_=NU_;
static int ny_=NY_;
static int nw_=NW_;
static int np_=NP_;
#ifdef NPS_
static int nsp_=NPS_;
#else
static int nsp_=0;
#endif
#ifdef NRelF_
static int nrel2_=NRelF_;
#else
static int nrel2_=NRel_;
#endif
static int nrel_=NRel_;
static int ncons_=NCons_;
static int dae_=DAEsolver_;
DYMOLA_STATIC void GetDimensions3(int *nrel_, int *ntim_, int *ncheckif_, int *nsamp_, int *nwhen_, int *nglobalhelp_, 
  int *maxaux, int *qnlmax_, int *sizepre_, int *sizeeq_)
{
	*nrel_ = NRel_;
	*ntim_ = NTim_;
	*ncheckif_ = NCheckIf_;
	*nsamp_ = NSamp_;
	*nwhen_ = NWhen_;
	*nglobalhelp_ = NGlobalHelp_;
	*maxaux = MAXAux;
	*qnlmax_ = QNLmax_;
	*sizepre_ = SizePre_;
	*sizeeq_ = SizeEq_;
}

DYMOLA_STATIC void InitializeDymosimStruct(struct BasicDDymosimStruct*basicD,struct BasicIDymosimStruct*basicI) {
#if INLINE_INTEGRATION
	  basicI->mInlineIntegration=INLINE_INTEGRATION;
#else
	  basicI->mInlineIntegration=0;
#endif
#if defined(DymolaGeneratedFixedStepSize_)
	 basicD->mDymolaFixedStepSize=DymolaGeneratedFixedStepSize_;
#else
	 basicD->mDymolaFixedStepSize=0.0;
#endif
	 basicD->mCurrentStepSizeRatio2 = 1.0;
	 basicD->mOrigTimeError=0;
#if defined(FMUStoreResultInterval_)
	 basicD->mStoreResultInterval = FMUStoreResultInterval_;
#else
	 basicD->mStoreResultInterval = 0;
#endif
}

#ifdef DYNSparseJacobian_
DYMOLA_STATIC const int global_sparse_enabled = DYNSparseJacobian_;
#else
DYMOLA_STATIC const int global_sparse_enabled = 0;
#endif

#if defined(RT) || defined(NRT)
#else

DYMOLA_STATIC int dsblockb_(const int *iopt_, int info_[], int sig_[], int dim_[], 
        double *t0_, double x0_[], double xd0_[], 
        double dp_[], int ip_[], Dymola_bool lp_[], 
		double duser_[], int iuser_[], void*cuser_[], 
        int *QiErr)
  {
    int /* c1_, c2_, c3_, i_, */ nx2_;
    /* double d1_; */

	*(GlobalErrorPointer())=0;
    if (DAEsolver_)
      nx2_ = NX2_;
    else
      nx2_ = 0;

    if (*iopt_ == 1) {	

    } else if (*iopt_ == 2) {
	
	  SetupProcessorCounter();

      if (NCons_ > 0)
        info_[0] = 2;
      else if (DAEsolver_)
        info_[0] = 1;
#if defined(HaveDummyDerivative_)
	  info_[1] = 1;
#endif

#if defined(AnalyticJacobian_)
	  info_[2] = AnalyticJacobianElements_;
#endif
      /* if (NRel_ > 0 && NX_ + nx2_ == 0) */
      if (NX_ + nx2_ == 0)
        sig_[0] = 1;       /* To enable handling of "state events" without states. */
      else 
        sig_[0] = NX_ + nx2_;
      sig_[1] = NU_;
      sig_[2] = NY_;
      if (NRel_ > 0 && RootFinder_)
        sig_[3] = 1;
      sig_[4] = NW_;
      sig_[5] = NP_;
      sig_[6] = NA_;   /* Number of alias signal matrices or scalars */
      sig_[7] = NA_;   /* Total number of alias elements */
  
      /* if (NRel_ > 0 && NX_ + nx2_ == 0) */
      if (NX_ + nx2_ == 0)
        dim_[0] = 1;
      else
        dim_[0]  = NX_ + nx2_;
      dim_[1]  = NU_;
      dim_[2]  = NY_;
      dim_[3]  = 2 * NRel_;
      dim_[4]  = NW_;
      dim_[5]  = NP_;
	  dim_[6]  = NRelF_;
	  dim_[7]  = SizeEq_;
      dim_[9]  = NHash1_;
      dim_[10] = NHash2_;
      dim_[11] = NX_;
      dim_[12] = nx2_;
	  dim_[13] = NGlobalHelp_;
	  dim_[14] = NHash3_;
#ifdef NPS_
      dim_[15] = NPS_;
#endif

      dim_[8] = dim_[0] + dim_[2] + dim_[3]*sig_[3] + dim_[4] + sizeof(struct BasicDDymosimStruct)/sizeof(doublereal);
      
    } else if (*iopt_ == 3) { 
      iuser_[0] = NX_ + nx2_ + NCons_;
      iuser_[1] = NY_;
      iuser_[2] = NW_;
      iuser_[3] = 2 * NRel_;
      InitializeDymosimStruct((struct BasicDDymosimStruct*)(duser_+
		   iuser_[0]+iuser_[1]+iuser_[2]+iuser_[3]),(struct BasicIDymosimStruct*)(iuser_+4));

	  


      /* if (NRel_ > 0 && NX_ + nx2_ == 0) */
      
			

      declareNew_(x0_, dp_, 0, cuser_, QiErr, 0, (struct DeclarePhase*)0);
    } 
	else if (*iopt_ == 4) {
		declareNew_(x0_,dp_,0,cuser_,QiErr, 1, (struct DeclarePhase*)0);
	} else if (*iopt_ == 5) {
		InitializeDymosimStruct((struct BasicDDymosimStruct*)(duser_),(struct BasicIDymosimStruct*)(iuser_));
	}



leave:
  if (*(GlobalErrorPointer()) != 0)
    *QiErr = *(GlobalErrorPointer());
  return 0;
}
#endif

#if defined(AnalyticJacobian_) && defined(AnalyticJacobianBCD_)
DYMOLA_STATIC int QJacobianDefined_=1;
#else
DYMOLA_STATIC int QJacobianDefined_=0;
#endif

#if !defined(QJacobianCGDef_)
DYMOLA_STATIC int QJacobianCG_[3]={0,0,0};
DYMOLA_STATIC int QJacobianGC_[1]={0};
DYMOLA_STATIC double QJacobianCD_[1]={0};
#endif

#if !defined(DYN_COMPILE_WITH_SPARSE) && !defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
DYMOLA_STATIC void *superlu_enabled(int nx, int analytic_jacobian, int nnz, const int nxOrig, const int cgOffset, const int gcOffset) { return 0; }
DYMOLA_STATIC int superlu_init(void *vdata, int use_slui_data_variables, int jacobian_rowvals_needs_reset) { return 1; }
DYMOLA_STATIC int superlu_get_nnz(void *vdata) { return 0; }
DYMOLA_STATIC int superlu_get_num_procs(void *vdata) { return 0; }
DYMOLA_STATIC void* superlu_init_interface_util(void *vdata) { return (void *)0; }
DYMOLA_STATIC void* superlu_init_interface_util_2(void *vdata, int n) { return (void *)0; }
DYMOLA_STATIC int superlu_set_jacobian_group(void *vdata, int group_number, double factor, const double* ypert1, const double* ypert2,
	const double* fpert1, const double* fpert2, int* rowvals, double* data) { return 1; }
DYMOLA_STATIC double superlu_jacobian_norm(void *vdata, double* ewt) { return -1.0; }
DYMOLA_STATIC int superlu_scale_jacobian(void *vdata, double val) { return 1; }
DYMOLA_STATIC int superlu_shift_jacobian(void *vdata, double val) { return 1; }
DYMOLA_STATIC int superlu_get_dsmodel_pointers_for_analytic_jacobian(void *vdata, double **vals, int **rows, int **cols) { return 1; }
DYMOLA_STATIC int superlu_set_analytic_jacobian_structure(void *vdata, int *rowvals, int *colptrs) { return 1; }
DYMOLA_STATIC int superlu_reset_jacobian_structure(void *vdata, int* rowvals, int* colptrs) { return 1; }
DYMOLA_STATIC int superlu_set_analytic_jacobian_values(void *vdata, double *data) { return 1; }
DYMOLA_STATIC int superlu_factorize(void *vdata, void *slui_util, int M, int N, int NNZ, double* data, int *rowvals, int *colptrs) { return 1; }
DYMOLA_STATIC int superlu_solve(void *vdata, double* x, void *slui_util) { return 1; }
DYMOLA_STATIC void superlu_deallocate(void *vdata) { ; }
DYMOLA_STATIC void superlu_dealloc_interface_util(void* slui_util) { ; }

DYMOLA_STATIC int CVSlsSetSparseJacFn(void *cvode_mem, void *jac) { return -1; }
DYMOLA_STATIC int CVSlsGetNumJacEvals(void *ida_mem, long int *njevals) { return -1; }
DYMOLA_STATIC int CVSuperLUMT(void *cv_mem, int num_threads, int n, int nnz) { return -1; }

#ifdef GODESS
DYMOLA_STATIC void* NewSparseMat(int M, int N, int NNZ) { return ((void*)0); }
DYMOLA_STATIC void* SlsConvertDls(void* A) { return ((void*)0); }
DYMOLA_STATIC void DestroySparseMat(void* A) { ; }
DYMOLA_STATIC void SlsSetToZero(void* A) { ; }
DYMOLA_STATIC void CopySparseMat(void* A, void* B) { ; }
DYMOLA_STATIC void ScaleSparseMat(double b, void* A) { ; }
DYMOLA_STATIC void AddIdentitySparseMat(void* A) { ; }
DYMOLA_STATIC int SlsAddMat(void* A, void* B) { return 1; }
DYMOLA_STATIC void ReallocSparseMat(void* A) { ; }
DYMOLA_STATIC int SlsMatvec(void* A, double *x, double *y) { return 1; }
DYMOLA_STATIC void PrintSparseMat(void* A) { ; }

DYMOLA_STATIC int CVSlsGetLastFlag(void *ida_mem, long int *flag) { return -1; }
DYMOLA_STATIC char *CVSlsGetReturnFlagName(long int flag) { return ""; }

DYMOLA_STATIC int CVSuperLUMTSetOrdering(void *cv_mem, int ordering_choice) { return -1; }
#endif /* GODESS */
#endif /* DYN_COMPILE_WITH_SPARSE */

/* vector to hold FMI value references for possible continuous time states*/
#if !defined(FMIStateValueReferencesDef_)
DYMOLA_STATIC unsigned int FMIStateValueReferences_[1]={~0};
#endif

DYMOLA_STATIC void GetNonlinearSolverStatistics(int*const qnlmax, const int**const qnlfunc, 
	const int**const qnljac, const int**const qnlcalls, int*const nrtimers)
{
	if (qnlmax) *qnlmax = QNLmax;
	if (qnlfunc) *qnlfunc = QNLfunc;
	if (qnljac) *qnljac = QNLjac;
	if (qnlcalls) *qnlcalls = QNLcalls;
#ifdef NrDymolaTimers_
	if (nrtimers) *nrtimers = NrDymolaTimers_;
#else
	if (nrtimers) *nrtimers = 0;
#endif
}

DYMOLA_STATIC void getDelayStruct(struct DYNInstanceData* did_, delayStruct** del, size_t* nbrDel) {
	if(nbrDel)
		*nbrDel = SizeDelay_ ? SizeDelay_ : 1;
	if (del) {
		if (did_) {
			*del = did_->del_vec;
		}else {
			*del = tempData.del_vec;
		}
	}
}

/* End dsblock5.c */

