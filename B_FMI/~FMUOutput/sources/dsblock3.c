/* Begin dsblock3.c
   File version: 1.3, 1998-10-29 */
/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

    if (Init_) {
		int i1_;
		for (i1_ = 1; i1_ <= nrel_; i1_++) {
			QZold_[2*i1_-2] = 1;
			QZold_[2*i1_-1] = 1; 
			QZ_[2*i1_-2] = 1;
			QZ_[2*i1_-1] = 1; 
		}
	}

	if (Init_) {
		int i1_;
		for (i1_=0; i1_<sizeof(QPre_)/sizeof(QPre_[0]); i1_++) {
			RefPre_[i1_] = 0; 
			QPre_[i1_] = 0;
		}
	 }
	  if (DymolaOneIteration_<3) Iter = 0;
	  if (did_->DymolaEventOptional_var && *idemand_==5 && RootFinder_ ) {
		  if (DYNTime<NextTimeEvent && !triggerStepEvent_) {
			  DYNEvent=false;
			  *idemand_=4;
			  Iter=1;
		  }
	  }
	  if (DymolaOneIteration_==5) goto iterate2;
iterateEvent:
	  if (DYNEvent) {
		   NextTimeEvent=1e100;
		   did_->HaveEventIterated_var=true;
	  }
      if (*idemand_ == 4 || (DYNEvent && DymolaOneIteration_!=3 && DymolaOneIteration_!=4)) {
		  int i1_;
	      for (i1_ = 1; i1_ <= nrel_; i1_++) Qenable_[i1_] = false;
	  }
	  if (DYNEvent) {
		  ClearNextSample(did_);
	  }
iterate:
	DYNHReject=0;
	if (DYNEvent) ++dymolaEventsNr_;
	  if ((Iter%11)==10) {
		  int i1_;
		  for (i1_ = 1; i1_ <= nrel_; i1_++) Qenable_[i1_] = false;
	  }
      PerformIteration_ = false;
      Iter = Iter + 1;
	  if ((!Init_ && PrintEvent&(1 << 1)) || (Init_ && PrintEvent&(1 << 2))) DynLogEvents(Iter, 0, 0, 0, 0, 0);
      AnyEvent_ = false;
	  AnyEventParameter_ = false;
#if defined(DYNCALLFMUREINIT)
	  DelayedUpdateReinit(time, X_, W_, U_, Y_, did_);
#endif
iterate2:
  equations_(idemand_, icall_, 
      time, X_, XD_, U_, 
      DP_, IP_, LP_, 
      F_, Y_, W_, QZ_, 
      duser_, iuser_, cuser_, did_, 
      QiErr, tid);
	  if (*QiErr>=1 && *QiErr<=4 && DYNTime<=InitTime && Iter<=1 && DymolaHomotopyUsed && !DymolaUserHomotopy) {
		  if (ResetCounter_!=did_->oldReset_var) {
			  did_->oldReset_var=ResetCounter_;
			  if (!(PrintEvent&(1<<10))) DymosimMessage("Trying to solve non-linear system using global homotopy-method.");
			  DymolaUserHomotopy=1;
			  *QiErr=-997;
		  }
	  }
	  if (*QiErr==-997) { 
		  if(DymolaUserHomotopy && DymolaHomotopyLambda!=0) {
			  DymolaHomotopyLambda=0;
			  UpdateInitVars(time, X_, XD_, U_, DP_, IP_, LP_, 
					F_, Y_, W_, QZ_, duser_, iuser_, cuser_, did_,0);
			  GlobalError_=0;
			  *QiErr=0;
			  goto iterate2;
		  }
	  } else if (*QiErr==-996) {
		  if (DymolaUserHomotopy) {
			  GlobalError_=0;
			  *QiErr=0;
			  if (DymolaHomotopyLambda<1) {
				  if (DymolaHomotopyLambdaDelta<0.08 && DymolaHomotopyLambda>DymolaHomotopyLambdaFail+DymolaHomotopyLambdaDelta*6)
					  DymolaHomotopyLambdaDelta*=2;
				  DymolaHomotopyLambda+=DymolaHomotopyLambdaDelta;
				  if (DymolaHomotopyLambda>1-1e-9) DymolaHomotopyLambda=1; 
				  DYNHReject=0;
				  UpdateInitVars(time, X_, XD_, U_, DP_, IP_, LP_, 
					F_, Y_, W_, QZ_, duser_, iuser_, cuser_, did_,0);
				  goto iterate2;
			  } else DymolaUserHomotopy=0;
		  }
	  } else if (*QiErr!=0 && DymolaUserHomotopy) {
		  if (DymolaHomotopyLambda<=0) DymosimMessage("Error: could not solve simplified initialization for homotopy method.");
		  else if (DymolaHomotopyLambdaDelta<=1e-4) {
			  if (DymolaHomotopyLambdaFail>0) 
				  DymosimMessage("Error: adaptive homotopy method got stuck after starting. Can set scripting flag Advanced.DebugHomotopy=true; simulate again, and open continuation.csv to investigate");
			  else 
				  DymosimMessage("Error: adaptive homotopy method could not start using actual - check that actual and simplified arguments are similar.");
		  } else {
			  GlobalError_=0;
			  *QiErr=0;
			  DymolaHomotopyLambda-=DymolaHomotopyLambdaDelta;
			  DymolaHomotopyLambdaDelta*=0.5;
			  DymolaHomotopyLambdaFail=DymolaHomotopyLambda;
			  DymolaHomotopyLambda+=DymolaHomotopyLambdaDelta;
			  DymosimMessage("Error: reducing step size for homotopy.");
			  DYNHReject=1;
			  UpdateInitVars(time, X_, XD_, U_, DP_, IP_, LP_, 
					F_, Y_, W_, QZ_, duser_, iuser_, cuser_, did_,0);
			  goto iterate2;
		  } 
	  }

      if (PerformIteration_)
        goto iterate;

      if (DYNEvent) {

/* End dsblock3.c */
