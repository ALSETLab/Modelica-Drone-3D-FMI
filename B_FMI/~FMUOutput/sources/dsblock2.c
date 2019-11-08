/* Begin dsblock2.c 
   File version: 1.3, 1999-01-20 */

/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

/*
#if defined(Sections_) 
  *icall_  = *idemand_;
#else
  *icall_  = 4; 
#endif
*/

finish:
leave:
  if (GlobalError_ != 0)
    *QiErr = GlobalError_;
  }

#ifdef DYMOSIM
	LIBDS_API void DynLogEvents(int action, doublereal time, int event_type, const char* expression, int iresult, double result);
#endif

#if defined(DYNHideWindowsPopup) && defined(_WIN32)
#include <windows.h>
#endif

DYMOLA_STATIC void ClearNextSample(struct DYNInstanceData* did_);
DYMOLA_STATIC int dsblock_tid(int *idemand_, int *icall_, 
      double *time, double X_[], double XD_[],  double U_[], 
      double DP_[], int IP_[], Dymola_bool LP_[], 
      double F_[], double Y_[], double W_[], double QZ_[], 
      double duser_[], int iuser_[], void*cuser_[],struct DYNInstanceData* did_, 
      int *QiErr, int tid)
{
#if defined(DS_EMBEDDED)
	dse_SetStatePointers(sts, idemand_, icall_, time, X_, XD_, U_, DP_, IP_, LP_, F_, Y_, W_, QZ_, did_ ? did_->Aux_vec : 0, duser_, iuser_, cuser_, QiErr);
#endif

	DYNPropagateDidToThread(did_);
        if (did_->inCall_var && !*idemand_ == 0) {if (*idemand_ != 3) *QiErr=1; return 0;} /* Recursive call, allow in special case */ 
	did_->inCall_var = 1;
      
	  if (setjmp(DYNGlobal_jmp_buf_env.TheBuffer) == 0) {

      DYNTime = *time;
      Init_ = *idemand_ == 0;
	  did_->HaveEventIterated_var = false;
	  if (DymolaOneIteration_==0 || DymolaOneIteration_==2) {AnyDEvent_=false;AnyIEvent_=false;AnyREvent_=false;}
	  if (Init_ && (DymolaOneIteration_==0 || DymolaOneIteration_==2) ) {
		  did_->dymolaParametersNrOld_=0;
		  dymolaParametersNr_++;
	  }
	  NewParameters_ = did_->dymolaParametersNrOld_!=dymolaParametersNr_;
	  if (NewParameters_) *icall_=0;
	  did_->dymolaParametersNrOld_=dymolaParametersNr_;
		
      DYNEvent = Init_  || *idemand_ == 5 || *idemand_ == 7 ||
        (! RootFinder_ && *idemand_ == 3) || NewParameters_;
	  (((struct BasicIDymosimStruct*)iuser_)->mEvent)=DYNEvent;
	  if (Init_) {
		  ++ResetCounter_;
		  GlobalError_ = 0;
	  }
	  GlobalError_ = 0;
/*    GlobalError_ = 0; */  /* In order to handle errors at events. */ 

	  rememberOnlyAccepted_ = 0;
      if (Init_) {
		  DYNAdvicePrinted_ = 0;
#if defined(DYNHideWindowsPopup) && defined(_WIN32)
		  SetErrorMode(SEM_NOGPFAULTERRORBOX);
#endif
#if defined(GenerateSimulinkTiming) && defined(DynSimStruct) && !defined(DYMOLA_DSPACE)
	    did_->TimeStartOfSimulation_var=CurrentClockTime;
#endif
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
		InitTime=DYNTime;
        FirstEvent = true;
#if defined(PrintEvent_)
        PrintEvent = PrintEvent_;
#else
        PrintEvent = 0;
#endif
        MaxIter = 25;
        EPS_ = 1e-10;

		{int i1_;
#ifdef DYMOSIM
		 int Ierror_;
        i1_ = 2;
#if !defined(PrintEvent_)
        blosii_(&i1_, &PrintEvent, &Ierror_);
#endif

        i1_ = 3;
        blosii_(&i1_, &MaxIter, &Ierror_);

        i1_ = 4;
        blosid_(&i1_, &EPS_, &Ierror_);

        i1_ = 5;
        blosid_(&i1_, &Qtol, &Ierror_);
#else
#ifdef TOLERANCE_FROM_SETUP
		Qtol = TOLERANCE_FROM_SETUP;
#else
        Qtol = 1.E-4;
#endif /* TOLERANCE_FROM_SETUP */
#endif

        dymmdp_();
		if (!DelayStruct_[0].x) {
			if (allocDelayBuffers(DelayStruct_, SizeDelay_ ? SizeDelay_ : 1, Buffersize)) {
				*QiErr = -500;
				did_->inCall_var = 0;
				return 0;
			}
		}
        for (i1_ = 0; i1_ < QNLmax; i1_++) {
          QNLfunc[i1_] = 0;
          QNLjac[i1_] = 0;
		  QNLcalls[i1_] = 0;
        }
		}

        FirstCross_ = 1;
        GetDimensions2(&nx_, &nx2_, &nu_, &ny_, &nw_, &np_, &nsp_, &nrel2_, &nrel_, &ncons_, &dae_);
      }
      if (DYNEvent && !did_->DymolaEventOptional_var) {
           triggerStepEvent_=0;
      }
/* End dsblock2.c */
