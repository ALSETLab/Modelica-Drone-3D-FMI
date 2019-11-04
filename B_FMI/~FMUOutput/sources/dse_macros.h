/*
	Internal macro definitions for generated embedded code.
*/

#ifndef DSE_MACROS_H
#define DSE_MACROS_H

#include "dse_types.h"

#ifdef inline_embedded
	static_assert(0, "Macro error: 'embedded_inline' already defined.");
#else
	#define inline_embedded static __inline
	#ifdef __STDC_VERSION__
		#if __STDC_VERSION__ >= 199901L
		#define inline_embedded static inline
		#endif
	#endif
#endif

#define ModelFunctionEnd() \
	return 0

#define IF \
	(
#define THEN \
	) ? (
#define ELSE \
	) :
#define AND \
	&&
#define OR \
	||
#define NOT \
	!
#define true \
	(1)
#define false \
	(0)
#define homotopy(a, b) \
	(a)
#define GreaterS(a, b, c, d, e) \
	((a) > (c))
#define LessS(a, b, c, d, e) \
	((a) < (c))
#define divGuarded(x, sx, y, sy) \
	(((real_t)(x)) / (y))
#define divinvGuarded(y, sy) \
	(((real_t)(1)) / (y))

inline_embedded real_t abs_real_t(const real_t x)
{
	return x >= 0 ? x : -x;
}

inline_embedded real_t sqr(const real_t x)
{
	return x * x;
}

inline_embedded real_t sqrt_real_t(const real_t x)
{
	/* Newton's iterative method with upper bound of iterations: */
#ifndef sqrt_precision
#define sqrt_precision 1e-9
#endif
#ifndef sqrt_bound
#define sqrt_bound 10u
#endif
	real_t result = x;
	if (x > 0)
	{
		real_t result_previous;
		uinteger_t i = 0;
		do
		{
			result_previous = result;
			result = 0.5 * (result + x / result);
		}
		while (++i <= (sqrt_bound) && abs_real_t(result - result_previous) > (sqrt_precision));
	}
	return result;
}

inline_embedded real_t sqrtGuarded(const real_t x, const char* const sx)
{
	return x >= 0 ? sqrt_real_t(x) : 0;
}

inline_embedded real_t RealBmin(const real_t x, const real_t y)
{
	return x < y ? x : y;
}

inline_embedded real_t RealBmax(const real_t x, const real_t y)
{
	return x > y ? x : y;
}

/* Backup solution to scalar system Ax=b, if A=0 */

#define RememberSimple_(x, nr) \
	(0.0)

#define SolveScalarLinear(A, As, b, bs, x, xs) \
	{ \
		const real_t A_val = (A); \
		if (A_val != 0) \
		{ \
			(x) = (b) / A_val; \
		} \
	}

#define SolveScalarLinearParametric(A, As, b, bs, x, xs) \
	SolveScalarLinear((A), (As), (b), (bs), (x), (xs))

/* Help variables */

#ifdef NGlobalHelp_
static real_t helpvar[NGlobalHelp_] = {0};
#define DYNhelp \
	(helpvar)
#endif

#define DYNX(s, i) \
	(*((i) + (s))) /* s[i]: first evaluate i, afterwards s */

/* External LU-solver interface for linear systems of equations */

#ifdef use_default_external_lu_solver
#ifdef external_lu_solver
static_assert(0, "LU-solver configuration error: LU-solver already defined.");
#endif

#define external_lu_solver 1
#define external_lu_solver_is_default 1

#define NWLINEARSOLVER(n) \
	(n)

/*
	Find entry along column col_ind of A (from the row with index col_ind and below) with largest
	modulus. Then swaps the row with index col_ind with the row containing the largest entry. The
	reordering is stored in the pivot vector p.

	-> Integer	n		: Dimensions of A and p; n > 0 required
	-> Real		A[n, n]	: A-matrix stored in one vector in row-major order
	<- Real		A[n, n]	: Pivoted A-matrix
	-> Integer	col_ind	: Index of column to search in
	-> Integer	p		: Permutation vector containing the order of the rows of A
	<- Integer	p		: Permutation vector after pivoting
*/
static void pivot(
	const uinteger_t n,
	real_t* const A,
	const uinteger_t col_ind,
	integer_t* const p)
{
	uinteger_t max_ind = col_ind, j;
	real_t max_val = abs_real_t(A[col_ind*n + col_ind]);

	/* Find entry with largest modulus in column col_ind (row col_ind and below). */
	for (j = col_ind + 1; j != n; ++j)
	{
		if (abs_real_t(A[j*n + col_ind]) > max_val)
		{
			max_val = abs_real_t(A[j*n + col_ind]);
			max_ind = j;
		}
	}

	/* If largest entry found below row col_ind, update p and swap the rows. */
	if (max_ind != col_ind)
	{
		const integer_t temp_p = p[max_ind];
		p[max_ind] = p[col_ind];
		p[col_ind] = temp_p;
		for (j = 0; j != n; ++j)
		{
			const real_t temp_A = A[max_ind*n + j];
			A[max_ind*n + j] = A[col_ind*n + j];
			A[col_ind*n + j] = temp_A;
		}
	}
}

/*  
	The function performs an LU factorization of matrix A using partial pivoting. The matrices L
	and U are returned in A. The upper-triangular U in the upper-triangular part of A
	(including the main diagonal). The lower-triangular L in the lower- triangular part of A. L
	is 1 on the main diagonal, however these values are not stored. Partial pivoting is used to
	give below-diagonal elements in L of magnitude less than 1. The order of the rows after
	pivoting is returned in the vector p.

		Algorithm based on:
		Trefethen, L.N., Bau, D. (1997)
		Numerical Linear Algebra
		Lecture 21

	-> Integer	n		: Dimensions of A and p; n > 0 required
	-> Real		A[n, n]	: A-matrix stored in one vector in row-major order
	<- Real		A[n, n]	: LU-decomposition of A
	-> Integer	nw		: Length of work array (not needed here)
	-> Real		work	: Real work array of length nw (not needed here)
	<- Integer	p[n]	: Pivot vector
	<- Return			: =  0: No error: LU decomposition successfully computed.
						  = -1: Error: A is singular
*/
integer_t LinFactorize(
	const uinteger_t n,
	real_t* const A,
	const uinteger_t nw,
	real_t* const work,
	integer_t* const p)
{
	uinteger_t k, j, i;

	/* Initialize the pivot vector p. */
	for (k = 0; k != n; ++k)
	{
		p[k] = k;
	}

	/* LU algorithm with partial pivoting. */
	for (k = 0; k != n - 1; ++k)
	{
		/*
			Find entry along column k (row k and below) with largest modulus and swap row k with
			the row containing the largest entry.
		*/
		pivot(n, A, k, p);

		/* The pivot element is zero iff the matrix A is singular. */
		if (A[k*n + k] == 0) {
			return -1;
		}

		/* Perform elimination on all rows below the current (row k). */
		for (j = k + 1; j != n; ++j)
		{
			A[j*n + k] /= A[k*n + k];
			for (i = k + 1; i != n; ++i)
			{
				A[j*n + i] -= A[j*n + k] * A[k*n + i];
			}

		}
	}

	/* If the last diagonal element is zero after decomposition the matrix is singular. */
	if (A[n*n - 1] == 0)
	{
		return -1;
	}
	
	/* If non of the singularity checks above are valid the matrix is non-singular. */
	return 0;
}

/*
	The matrix D is assumed to contain the factors L and U and the row order information is assumed
	to be stored in the vector p. The right-hand-side is given in b and the solution is returned in
	the same vector.

	-> Integer	n		: Dimensions of D and pivots; n > 0 required
	-> Real		D[n, n]	: LU-decomposition of A stored in one vector in row-major order
	-> Integer	p[n]	: Pivot vector
	-> Real		b[n]	: b-vector
	<- Real		b[n]	: solution vector of linear system
	-> Integer	nw		: Length of work array
	-> Real		work[n]	: Real work array of length nw
	<- Return			: =  0: No error: Solution of linear system successfully computed.
						  = -1: Error.
*/
integer_t LinSolve(
	const uinteger_t n,
	const real_t* const D,
	const integer_t* const p,
	real_t* const b,
	const uinteger_t nw,
	real_t* const work)
{
	uinteger_t k, j;

	/* Buffer memory must be the same length as b. */
	if (n != nw)
	{
		return -1;
	}

	/* Rearrange right-hand-side vector b according to pivot vector p. Result stored in work. */
	for (k = 0; k != n; ++k)
	{
		work[k] = b[p[k]];
	}

	/* Forward substitution using L (lower triangular part of D). Result stored in b. */
	for (k = 0; k != n; ++k)
	{
		real_t sum = 0;
		for (j = 0; j != k; ++j)
		{
			sum += D[k*n + j] * b[j];
		}
		b[k] = work[k] - sum;
	}

	/* Back substitution using U. Overwrites b. */
	for (k = n - 1; k != -1; --k)
	{
		real_t sum = 0;
		for (j = k + 1; j != n; ++j)
		{
			sum += D[k*n + j] * b[j];
		}
		b[k] = (b[k] - sum) / D[k*n + k]; /* Division safe as U is non-singular. */
	}

	return 0;
}

#endif

/* Rosenbrock methods (require LU-solver) */

#ifndef external_lu_solver

#define RosenBrockSolver(n, s) \
	static_assert(0, "Rosenbrock methods error: no LU-solver defined.");

#else

#define RosenBrockMethod1a \
	static const real_t a[1 *1] = {0.0}; \
	static const real_t c[1 * 1] = {0}; \
	static const real_t m[1] = {1}; \
	static const real_t c2[2] = {0, 1}; \
    static const real_t gamma = 1; \
	static const integer_t Nstages = 1

#define RosenBrockMethod2a \
	static const real_t a[2 * 2] = {0, 0, 3.414213562373095, 0.0}; \
	static const real_t c[2 * 2] = {0, 0, -6.82842712474619, 0}; \
	static const real_t m[2] = {5.121320343559642, 1.7071067811865475}; \
	static const real_t c2[3] = {0, 1, 1}; \
    static const real_t gamma = 0.2928932188134525; \
	static const integer_t Nstages = 2

#define RosenBrockMethod3a \
	static const real_t a[2 * 2] = {0, 0, 0.8452994616207485, 0.0}; \
	static const real_t c[2 * 2] = {0, 0, -1.690598923241497, 0}; \
	static const real_t m[2] = {1.5849364905389036, 0.9509618943233421}; \
	static const real_t c2[3] = {0, 0.6666666666666667 /* 2.0 / 3.0 */, 1}; \
    static const real_t gamma = 0.7886751345948129; \
	static const integer_t Nstages = 2

#define RosenBrockMethod4a \
	static const real_t a[4 * 4] = {0, 0, 0, 0, 2, 0, 0, 0, 1.8679481466559786, 0.23444556814091, 0, 0, 1.8679481466559786, 0.23444556814091,  0, 0}; \
	static const real_t c[4 * 4] = {0, 0, 0, 0, -7.1376499213588991, 0, 0, 0, 2.5809235306935996, 0.6516298653277054, 0, 0, -2.1371152877552761, -0.3214695297257358, -0.6949660544490384, 0}; \
	static const real_t m[4] = {2.2555662310268407,  0.2870550595798414, 0.4353119671472782,  1.0935076529988492}; \
	static const real_t c2[5] = {0., 1.1456321249642698,   0.655214977162467, 0.655214977162467 ,1}; \
    static const real_t gamma = 0.5728160624821349; \
	static const integer_t Nstages = 4

#define RosenBrockMethod1b \
	static const real_t g2[1] = {1}

#define RosenBrockMethod2b \
	static const real_t g2[2] = {0.2928932188134525, -0.2928932188134525}

#define RosenBrockMethod3b \
	static const real_t g2[2] = {0.7886751345948129, -0.2628917115316043}

#define RosenBrockMethod4b \
	static const real_t g2[4] = {0.5728160624821349,  -1.7691770777109217, 0.75929394500212, -0.1048946262078667}

#define RosenBrockSolvera(n, s) \
	if ((s) > 0) \
	{ \
		const real_t step_size = s; \
		real_t f[n]; \
		real_t A[n * n]; \
		integer_t A_n = n; \
		real_t E[n * n]; \
		integer_t E_n = n; \
		real_t Af[NWLINEARSOLVER(n)]; \
		integer_t Ap[n]; \
		real_t u2[n + 1]; \
		real_t y0[n ? n : 1]; \
		integer_t NewStep = 0; \
		integer_t FinalStage = 0; \
		integer_t i, j, k

#define RosenBrockSolverb(n) \
		for (i = 0; i < n * n; ++i) \
		{ \
			A[i] = E[i] = 0; \
		} \
		for (i = 1; i <= Nstages + 1; ++i) \
		{ \
			NewStep = (i == 1); \
			FinalStage = (i == Nstages + 1)

#define RosenBrockSolver4(n, s) \
		RosenBrockSolvera(n, s); \
		real_t u[n * 4 + 1] = {0}; \
		RosenBrockMethod4a; \
		RosenBrockSolverb(n)

#define RosenBrockSolver3(n, s) \
		RosenBrockSolvera(n, s); \
		real_t u[n * 2 + 1] = {0}; \
		RosenBrockMethod3a; \
		RosenBrockSolverb(n)

#define RosenBrockSolver2(n, s) \
		RosenBrockSolvera(n, s); \
		real_t u[n * 2 + 1] = {0}; \
		RosenBrockMethod2a; \
		RosenBrockSolverb(n)

#define RosenBrockSolver1(n, s) \
		RosenBrockSolvera(n, s); \
		real_t u[n * 1 + 1] = {0}; \
		RosenBrockMethod1a; \
		RosenBrockSolverb(n)

#define EndRosenBrockSolver(n) \
			if (NewStep) \
			{ \
				real_t dx = 1 / (gamma * step_size); \
				for (j = 0; j < n * n; ++j) \
				{ \
					A[j] = E[j] * dx - A[j]; \
				} \
				if (LinFactorize(n, A, sizeof(Af) / sizeof(Af[0]), Af, Ap)) \
				{ \
					return -1; \
				} \
			} \
			else \
			{ \
				for (k = 0; k < n; ++k) \
				{ \
					real_t v_accumulator = 0; \
					for (j = 1; j < i; ++j) \
					{ \
						v_accumulator += c[(i - 1) * Nstages + (j - 1)] * u[(j - 1) * n + k]; \
					} \
					u2[k] = v_accumulator / step_size; \
				} \
				for (k = 0; k < n; ++k) \
				{ \
					for (j = 0; j < n; ++j) \
					{ \
						f[k] += E[k * n + j] * u2[j]; \
					} \
				} \
			} \
            if (LinSolve(n, A, Ap, f, sizeof(Af) / sizeof(Af[0]), Af)) \
			{ \
				return -1; \
			} \
			for (k = 0; k < n; ++k) \
			{ \
				u[(i - 1) * n + k] = f[k]; \
			} \
		} \
	}

#define UpdateRosenBrockState(v, k, n, z) \
	if (NewStep) \
	{ \
		y0[k] = v; \
	} \
	else if (FinalStage) \
	{ \
		v = y0[k]; \
		for (j = 1; j <= Nstages; ++j) \
		{ \
			v += m[j - 1] * u[(j - 1) * n + k]; \
		} \
	} \
	else \
	{ \
		v = y0[k]; \
		for (j = 1; j < i; ++j) \
		{ \
			v += a[(i - 1) * Nstages + (j - 1)] * u[(j - 1) * n + k]; \
		} \
	}

#endif

/* Matrix and vector operations */

#define SetRealVectorElement(val, vec, ind) \
	(vec)[(ind) - 1] = (val)

#define SetRealMatrixElement(val, mat, indR, indC) \
	(mat)[((indC) - 1) * mat##_n + ((indR) - 1)] = (val)

/* Time */

#ifndef Time
#define Time \
	([]{static_assert(0, "Time configuration error: no 'time' defined by embedded environment.");}, 0)
#endif

/* Assertions (NOT SUPPORTED) */

#define Assert(b, x)
#define AssertModelica(b, bs, x)
#define AssertModelica3(b, bs, x, l)
#define AssertModelica4(b, bs, x, l, hi)

/* Activation conditions (NOT SUPPORTED) */

#define beginwhenBlock
#define whenModelicaS(cond)
#define endwhenModelica()
#define endwhenBlock

/* SubClocks with ticks > 1 (NOT SUPPORTED) */

#define PRE(x, nr) \
	(x)

#define sampleNew3(start, interval, phase, maxVal, SampleCounter) \
	(false)

#undef inline_embedded

#endif
