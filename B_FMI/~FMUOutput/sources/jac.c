/* Implementation of jac.h */

#include "jac.h"
#include "util.h"
#include "integration.h"

#include "fmiFunctions_fwd.h"

/* Sundials */
#include <cvode/cvode.h>
#include <sundials/sundials_math.h>
#include <nvector/nvector_serial.h>
#include <sundials/sundials_direct.h>

#include <assert.h>
#include <time.h>

/* ----------------- local function declarations ----------------- */

/* common function for J and J * v computation */
static int compute_Jdata(realtype t, N_Vector y, N_Vector fy, N_Vector v,
				  DlsMat J, N_Vector Jv, 
				  realtype srur, realtype mindy, realtype* ewt_data,
				  N_Vector tmp, FMIComponent c);

#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
/* computes sparse Jacobain data */
static int compute_JdataSparse(realtype t, N_Vector y, N_Vector fy, 
						 SlsMat J,  
						 realtype srur, realtype mindy, realtype* ewt_data,
						 N_Vector tmp, FMIComponent c);
#endif

/* computation of parameters for numeric computation of J */
static int compute_Jconf(N_Vector y, N_Vector fy, realtype* srur, realtype* mindy,
				  FMIComponent c);

/* ----------------- local variables ----------------- */

static size_t nGroups;

/* ----------------- external variables ----------------- */

extern int QJacobianCG_[];
extern int QJacobianGC_[];

/* ----------------- external function declarations ----------------- */

/* ----------------- function definitions ----------------- */

DYMOLA_STATIC void jac_setup(size_t ngroups){
	nGroups = ngroups;
}

/* ------------------------------------------------------ */
/* computes function f(t,y) */
DYMOLA_STATIC int jac_f(double t, N_Vector y, N_Vector ydot, void *user_data)
{
	FMIComponent* c = (FMIComponent*) user_data;
	Component* comp = (Component*) c;
	int retval = 0;
	N_VectorContent_Serial ydot_cont = NV_CONTENT_S(ydot);

	/* temporarily change time, states and inputs */
	FMIReal time = comp->time;
	FMIReal* states = comp->states;

	integration_extrapolate_inputs(comp, t);

	comp->states = N_VGetArrayPointer(y);
	comp->time = t;
	comp->icall = iDemandStart;
	if (fmiGetDerivatives_(c, ydot_cont->data, ydot_cont->length) != FMIOK) {
		retval = 1;
	}
	/* restore time, states and inputs */
	integration_extrapolate_inputs(comp, time);
	comp->states = states;
	comp->time = time;
	return retval;
}

/* ------------------------------------------------------ */
/* Jacobian routine, computes J(t,y) = df/dy numerically */
DYMOLA_STATIC int jac_Jacobian(long N, realtype t,
							   N_Vector y, N_Vector fy, DlsMat J, void *user_data,
							   N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
	FMIComponent* c = (FMIComponent*) user_data;
	Component* comp = (Component*) c;

	N_Vector ftmp = tmp1;

	realtype* ewt_data;
	realtype srur;
	realtype mindy;

	int j;
	/* error here is recoverable */
	int retval = 1;

	/* for later restoring */
	realtype* tmp2_data = N_VGetArrayPointer(tmp2);

	/* need raw pointers for some */
	realtype* y_data = N_VGetArrayPointer(y);
	realtype* fy_data = N_VGetArrayPointer(fy);
	realtype* ftmp_data = N_VGetArrayPointer(ftmp);

	if (compute_Jconf(y, fy, &srur, &mindy, c)) {
		goto done;
	}
	ewt_data = N_VGetArrayPointer(comp->iData->ewt);

	comp->istruct->mInJacobian = 1;

	/* use grouping if possible */
	if (nGroups > 0) {
		/* use grouping */
		/* cannot use tmp2 here since it reuses the pointer provided in N_VMake_Serial,
		   hence interfering with comp->states */
		if (!compute_Jdata(t, y, fy, NULL, J, NULL, srur, mindy, ewt_data, tmp3, c)) {
			retval = 0;
			goto done;
		}
		/* failed with grouping - fall back */
	}

	{
		/* no or failed grouping, perturb one variable at the time */
		N_Vector jthCol = tmp2;
		
		for (j = 0; j < N; j++) {
			realtype yjsaved;
			realtype dy1, dy2;
			realtype dy;
			realtype dy_inv;
			int k;

			/* generate the jth col of J(tn, y) */

			N_VSetArrayPointer(DENSE_COL(J, j), jthCol);

			yjsaved = y_data[j];
			/* perturb */
			dy1 = srur * SUNRabs(yjsaved);
			dy2 = mindy / ewt_data[j];
			dy = SUNMAX(dy1, dy2);
			/* keep sign to avoid y_data near 0 */
			if (yjsaved < 0) dy = -dy;

			/* retry a few times in case of failure */ 
			for (k = 0; k < 5; k++) {
				y_data[j] = yjsaved + dy;
				/* reduce rounding error at a low cost */
				dy = y_data[j] - yjsaved;

				/* compute new f */
				if (!jac_f(t, y, ftmp, user_data)) {
					break;
				}
				dy = -dy / 5; /* try smaller increment, and different sign */
				if (k>5) {
					/* failed */
					y_data[j] = yjsaved;
					goto done; 
				}
			}
			y_data[j] = yjsaved;
			dy_inv = RCONST(1.0) / dy;
			/* concisesness for the cost of duplicated multiplication */
			N_VLinearSum(dy_inv, ftmp, -dy_inv, fy, jthCol);
		}
	}

	retval = 0;

done:
	comp->istruct->mInJacobian = 0;
	/* restoring original array pointer appears to be necessary */
	N_VSetArrayPointer(tmp2_data, tmp2);
	return retval;
}

#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
/* sparse Jacobian routine, computes J(t,y) = df/dy numerically */
DYMOLA_STATIC int jac_JacobianSparse(realtype t,
							   N_Vector y, N_Vector fy, SlsMat J, void *user_data,
							   N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
	FMIComponent* c = (FMIComponent*) user_data;
	Component* comp = (Component*) c;

	N_Vector ftmp = tmp1;

	double* ewt_data;
	double srur;
	double mindy;

	int retval = 1;

	/* for later restoring */
	double* tmp2_data = N_VGetArrayPointer(tmp2);

	/* need raw pointers for some */
	double* y_data = N_VGetArrayPointer(y);
	double* fy_data = N_VGetArrayPointer(fy);
	double* ftmp_data = N_VGetArrayPointer(ftmp);

	if (compute_Jconf(y, fy, &srur, &mindy, c)) {
		goto done;
	}
	retval = 1; /* Everything below is recoverable */
	ewt_data = N_VGetArrayPointer(comp->iData->ewt);

	comp->istruct->mInJacobian = 1;
	
	/* use grouping if possible */
	if (QJacobianCG_[0] > 0) {
		/* use grouping */
		/* cannot use tmp2 here since it reuses the pointer provided in N_VMake_Serial,
		   hence interfering with comp->states */
		if (!compute_JdataSparse(t, y, fy, J, srur, mindy, ewt_data, tmp3, c)) {
			goto okdone;
		}
	} else {
		goto done; // Failed - since no group
	}
okdone:
	retval = 0;

done:
	comp->istruct->mInJacobian = 0;
	/* restoring original array pointer appears to be necessary */
	N_VSetArrayPointer(tmp2_data, tmp2);

	return retval;
}
#endif

/* ----------------- local function definitions ----------------- */

static int compute_Jdata(realtype t, N_Vector y, N_Vector fy, N_Vector v,
						 DlsMat J, N_Vector Jv, 
						 realtype srur, realtype mindy, realtype* ewt_data,
						 N_Vector tmp, FMIComponent c)
{
	Component* comp = (Component*) c;

	N_Vector ftmp = comp->iData->tmp1;

	realtype* y_data = N_VGetArrayPointer(y);
	realtype* fy_data = N_VGetArrayPointer(fy);
	realtype* v_data;
	realtype* Jv_data;
	realtype* ftmp_data = N_VGetArrayPointer(ftmp);

	realtype* ysaved_data = N_VGetArrayPointer(comp->iData->tmp2);
	realtype* dy_data = N_VGetArrayPointer(tmp);
	size_t group_nr;
	int group_ix = 1;
	int j;
	int N = (int)comp->nStates;

	/* compute exactly one of J or J * v */
	assert(J != NULL && Jv == NULL || J == NULL && Jv != NULL);

	/* initialize result */
	if (J != NULL) {
		for(j = 0; j < N; j++) {
			/* temporarily borrow tmp */
			N_VSetArrayPointer(DENSE_COL(J, j), tmp);
			N_VConst(0, tmp);
		}
	} else {
		v_data = N_VGetArrayPointer(v);
		Jv_data = N_VGetArrayPointer(Jv);
		N_VConst(0, Jv);
	}
	
	N_VSetArrayPointer(dy_data, tmp);

	/* iterate the groups */
	for (group_nr = 0; group_nr < nGroups; group_nr++) {
		int nmembers = QJacobianCG_[group_ix];
		int member;
		int i;
		int gc_ix = (int)(N * group_nr);
		int jac_res;

		/* perturb each group member */
		for (member = 1; member <= nmembers; member++) {
			realtype dy1, dy2;
			/* fetch column */
			int j = QJacobianCG_[group_ix + member] - 1;
			ysaved_data[j] = y_data[j];
			/* perturb the jth variable */
			dy1 = srur * SUNRabs(ysaved_data[j]);
			dy2 = mindy / ewt_data[j];
			dy_data[j] = SUNMAX(dy1, dy2);
			/* keep sign to avoid y_data near 0 */
			if (ysaved_data[j] < 0) dy_data[j] = -dy_data[j]; 
			y_data[j] += dy_data[j];
			/* reduce rounding error at a low cost */
			dy_data[j] = y_data[j] - ysaved_data[j];
		}

		/* compute new f */
		jac_res = jac_f(t, y, ftmp, c);
		
		/* restore y */
		for (member = 1; member <= nmembers; member++) {
			/* fetch column */
			j = QJacobianCG_[group_ix + member] - 1;
			y_data[j] = ysaved_data[j];
		}

		if (jac_res) {
			return 1;
		}

		/* store result */
		for (i = 0; i < N; i++) {
			int j = QJacobianGC_[gc_ix + i];
			if (j-- >= 1) {
				realtype val = (ftmp_data[i] - fy_data[i]) / dy_data[j];
				if (J != NULL) {
					DENSE_ELEM(J, i, j) = val;
				} else {
					val = DENSE_ELEM(comp->iData->J, i, j);
					Jv_data[i] += val * v_data[j];
				}
			}
		}

		group_ix += 1 + nmembers;
	}
	return 0;
}

/* ------------------------------------------------------ */
static int compute_Jconf(N_Vector y, N_Vector fy, realtype* srur, realtype* mindy,
						 FMIComponent c)
{
	/* the computation of minimal dy is borrowed from the default Jacobian
	cvDlsDenseDQJac in sundials */

	Component* comp = (Component*) c;

	realtype fnorm;
	realtype* y_data = N_VGetArrayPointer(y);
	realtype hcur;

	int flag = CVodeGetErrWeights(comp->iData->cvode_mem, comp->iData->ewt);
	if (util_check_flag(&flag, "CVodeGetErrWeights", 0, c)) return 1;

	/* base on uround and norm of f */
	*srur = SUNRsqrt(UNIT_ROUNDOFF);
	fnorm = N_VWrmsNorm(fy, comp->iData->ewt);
	flag = CVodeGetCurrentStep(comp->iData->cvode_mem, &hcur);
	if (util_check_flag(&flag, "CVodeGetCurrentStep", 1, c)) return 1;
	*mindy = (fnorm != RCONST(0.0)) ?
		(RCONST(1000.0) * SUNRabs(hcur) * UNIT_ROUNDOFF * comp->nStates * fnorm) : RCONST(1.0);
	return 0;
}

#if !defined(FMU_SOURCE_CODE_EXPORT) || defined(FMU_SOURCE_CODE_EXPORT_SPARSE)
/* computes sparse Jacobain data */
static int compute_JdataSparse(realtype t, N_Vector y, N_Vector fy, 
						 SlsMat J,  
						 realtype srur, realtype mindy, realtype* ewt_data,
						 N_Vector tmp, FMIComponent c)
{
	Component* comp = (Component*) c;

	N_Vector ftmp = comp->iData->tmp1;

	realtype* y_data = N_VGetArrayPointer(y);
	realtype* fy_data = N_VGetArrayPointer(fy);
	realtype* ftmp_data = N_VGetArrayPointer(ftmp);

	realtype* ysaved_data = N_VGetArrayPointer(comp->iData->tmp2);
	realtype* dy_data = N_VGetArrayPointer(tmp);
	size_t group_nr;
	int group_ix = 1;
	int i, j;
	int N = (int)comp->nStates;
	size_t nGroups = QJacobianCG_[0];

	N_VSetArrayPointer(dy_data, tmp);

	/* iterate the groups */
	for (group_nr = 0; group_nr < nGroups; group_nr++) {
		int nmembers = QJacobianCG_[group_ix];
		int member;
		int gc_ix = (int)(N * group_nr);
		int resOfJac=0;

		/* perturb each group member */
		for (member = 1; member <= nmembers; member++) {
			realtype dy1, dy2;
			/* fetch column */
			int j = QJacobianCG_[group_ix + member] - 1;
			ysaved_data[j] = y_data[j];
			/* perturb the jth variable */
			dy1 = srur * SUNRabs(ysaved_data[j]);
			dy2 = mindy / ewt_data[j];
			dy_data[j] = SUNMAX(dy1, dy2);
			if (ysaved_data[j]<0) dy_data[j] = -dy_data[j]; /* Keep sign */
			y_data[j] += dy_data[j];
			/* reduce rounding error at a low cost */
			dy_data[j] = y_data[j] - ysaved_data[j];
		}

		/* compute new f */
		resOfJac = jac_f(t, y, ftmp, c);

		/* restore y */
		for (member = 1; member <= nmembers; member++) {
			/* fetch column */
			j = QJacobianCG_[group_ix + member] - 1;
			y_data[j] = ysaved_data[j];
		}
		if (resOfJac) return 1; /* After restoring y */

		/* store result */
		for (i = 0; i < N; i++) {
			int j2 = QJacobianGC_[gc_ix + i]-1;
			if (j2>=0) {
				realtype val = (ftmp_data[i] - fy_data[i]) / dy_data[j2];
				int ix=comp->iData->sparseData.index[i+gc_ix];
				if (ix>=0) {
					J->data[ix]=val;
					J->rowvals[ix]=i;
			}
			}
		}

		group_ix += 1 + nmembers;
	}
	for(i=0;i<N+1;++i) J->colptrs[i]=comp->iData->sparseData.colPtrs[i];
	return 0;
}
#endif
