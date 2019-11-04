#ifndef DSBLOCK_H
#define DSBLOCK_H

/* dsblock.h */

/*
 * Copyright (C) 1997-2008 Dynasim AB.
 * All rights reserved.
 *
 */

#undef false
#undef true


/* To make functions and variabled static to allow several S-function blocks
	for real-time targets */
#if !defined(DYMOLA_STATIC)
#if defined(__cplusplus)
#define DYMOLA_STATIC extern
#elif defined(RT) && !defined(DYM2DS)
#define DYMOLA_STATIC static
#else
#define DYMOLA_STATIC
#endif
#endif

/* To support Lapack functions for code export */
#if !defined(RT)
#define dgetrf__RT dgetrf_
#define dgetrs__RT dgetrs_
#define dgeqpf__RT dgeqpf_
#define dlange__RT dlange_
#define dgecon__RT dgecon_
#define dgemm__RT dgemm_
#define dtrsm__RT dtrsm_
#define dtrsv__RT dtrsv_
#endif

typedef int Dymola_bool;
#define false 0
#define true  1

#include "libdssetup.h"
struct BasicIDymosimStruct {
	int mFindEvent;
	int mPrintEvent;
	int mallowSingularFlag;
	int mInJacobian;
	int mSolverHandleEq;
	int mInlineIntegration;
	int mTriggerStepEvent;

	int mDymolaStoreAuxiliaries;

	int mParametersNr;
	int mEvent;
	int mContinueSimulate;

	int mAtDAEEvent;
	int mRememberOnlyAccepted;
};
struct BasicDDymosimStruct {
	double mDymolaFixedStepSize;
	double mCurrentStepSizeRatio2;
	double mNextTimeEvent;
	double mOrigTimeError;
	double mStoreResultInterval;
};
struct DYNInstanceData;
#ifdef __cplusplus
extern "C" {
#endif
LIBDS_API struct BasicDDymosimStruct*getBasicDDymosimStruct(void);
DYMOLA_STATIC struct BasicDDymosimStruct*getBasicDDymosimStructNew(struct DYNInstanceData*);
LIBDS_API struct BasicIDymosimStruct*getBasicIDymosimStruct(void);
LIBDS_API void setBasicStruct(double*d,int*i);

DYMOLA_STATIC int dsblock_(int *idemand_, int *icall_, 
      double *time, double x_[], double xd_[], double u_[], 
      double dp_[], int ip_[], Dymola_bool lp_[], 
      double f_[], double y_[], double w_[], double qz_[], 
      double duser_[], int iuser_[], void*cuser_[], 
      int *ierr_);
DYMOLA_STATIC int dsblock_tid(int *idemand_, int *icall_, 
      double *time, double x_[], double xd_[], double u_[], 
      double dp_[], int ip_[], Dymola_bool lp_[], 
      double f_[], double y_[], double w_[], double qz_[], 
      double duser_[], int iuser_[], void*cuser_[], struct DYNInstanceData*,
      int *ierr_, int tid);

DYMOLA_STATIC int dsblockb_(const int *iopt, int info[], int sig[], int dim[], 
        double *t0, double x0[], double xd0[], 
	double dp[], int ip[], Dymola_bool lp[], 
        double duser[], int iuser[], void*cuser_[], 
        int *ierr);

DYMOLA_STATIC void GetDimensions(int *nx, int *nx2, int *nu, int *ny, int *nw, int *np, 
  int *nrel, int *ncons, int *dae);
DYMOLA_STATIC void GetDimensions2(int *nx, int *nx2, int *nu, int *ny, int *nw, int *np, int*nsp,
  int *nrel2, int*nrel, int *ncons, int *dae);
DYMOLA_STATIC void GetDimensions3(int *nrel_, int *ntim_, int *ncheckif_, int *nsamp_, int *nwhen_, int *nglobalhelp_, 
  int *maxaux, int *qnlmax_, int *sizepre_, int *sizeeq_);
DYMOLA_STATIC void GetDimensions4(int *nx, int *nx2, int *nu, int *ny, int *nw, int *np, int*nsp,
  int *nrel2, int*nrel, int *ncons, int *dae, int *nd, int* nxp);
DYMOLA_STATIC void GetNonlinearSolverStatistics(int*const qnlmax, const int**const qnlfunc,
  const int**const qnljac, const int**const qnlcalls, int*const nrtimers);
DYMOLA_STATIC double DymosimError(const char* message);

DYMOLA_STATIC void DymosimMessage(const char* message);

DYMOLA_STATIC void DymosimMessageDouble(const char* message, double d);

DYMOLA_STATIC void DymosimMessageInt(const char* message, int i);
DYMOLA_STATIC void DymosimMessageDoubleVector(const char* matrixname, double * d, int n);
DYMOLA_STATIC void DymosimMessageMatrixElement(char* name, int i, int j, double d);
DYMOLA_STATIC void AssertModelicaF(int b,const char*bs,const char*x);

struct SimulatorFunctions;
struct DYNInstanceData;
struct DymolaTimes;
		/* Pointers to functions exported from model */
struct DymosimModel {
	int tag;
	void (*registerTimeEvent)(const double t);
	
	void (*signalError)(void);
	
	int (*dsblock)(int *idemand_, int *icall_, 
		double *time, double x_[], double xd_[], double u_[], 
		double dp_[], int ip_[], Dymola_bool lp_[], 
		double f_[], double y_[], double w_[], double qz_[], 
		double duser_[], int iuser_[], void*cuser_[], 
		int *ierr_);
	
	int (*dsblockb)(const int *iopt, int info[], int sig[], int dim[], 
        double *t0, double x0[], double xd0[], 
		double dp[], int ip[], Dymola_bool lp[], 
        double duser[], int iuser[], void*cuser_[], 
        int *ierr);
	
	void (*GetDimensions2)(int *nx, int *nx2, int *nu, int *ny, int *nw, int *np, int*nsp,
		int *nrel2, int*nrel, int *ncons, int *dae);
	
	void (*initializeData)(double *time, double X_[], double XD_[], double U_[], 
		double DP_[], int IP_[], Dymola_bool LP_[], 
		double F_[], double Y_[], double W_[], double QZ_[], 
		double duser_[], int iuser_[], void*cuser_[], 
		int final_,int Init,int Event,int solverCall);
	
	int (*stepEventCallBack)(void); /* Optional, can be 0 */

	void (*delayBuffersClose)(void);
        const char*modelName;
		const char*default_dymosim_license_filename;

		int* QJacobianCG_;
		int* QJacobianGC_;
		double* QJacobianCD_;

		double** QJacobian_;
		int*QJacobianN_;
		int*QJacobianNU_;
		int*QJacobianNY_;
		double**QJacobianSparse_;
		int**QJacobianSparseR_;
		int**QJacobianSparseC_;
		int*QJacobianNZ_;

		struct DymolaTimes*dymolaTimes_;
		int dymolaTimersLen_;
		const char*const*usedLibraries;
		const char*const*dllLibraryPath;

		struct SimulatorFunctions*optFunctions;
		void (*SetDymolaJacobianPointers)(struct DYNInstanceData*did_, double * QJacobian_,double * QBJacobian_,double * QCJacobian_,double * QDJacobian_,int QJacobianN_,
	       int QJacobianNU_,int QJacobianNY_,double * QJacobianSparse_,int * QJacobianSparseR_,int * QJacobianSparseC_,int QJacobianNZ_);
		struct DymolaTimes* (*GetDymolaTimers)(struct DYNInstanceData*did_, int*len);
		void (*SetDymolaJacobianPointers2)(struct DYNInstanceData*did_, double * QJacobian_,double * QBJacobian_,double * QCJacobian_,double * QDJacobian_,int QJacobianN_,
	       int QJacobianNU_,int QJacobianNY_,double * QJacobianSparse_,int * QJacobianSparseR_,int * QJacobianSparseC_,int QJacobianNZ_,int *QJacobianABCDNZ);
};
#if (defined(LIBDS_DLL) || defined(LIBDS_NODLL_API)) && !defined(LIBDSDLL_EXPORTS) 
#if defined(LIBDS_DLL)
/* Exported from model */
#if defined(DYMOSIM_DLL_EXPORTS)
__declspec(dllexport) 
#else
__declspec(dllimport)
#endif
#endif
const struct DymosimModel* DymosimModelFunctions(void);
#endif

#ifdef __cplusplus
}
#endif
#endif

