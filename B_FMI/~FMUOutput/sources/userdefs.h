#ifndef USERDEFS_H
#define USERDEFS_H
/* userdefs.h
 *
 * To include user defined definitions.
 *
 * Version:  1.1  1999-01-20  Dag Bruck  Added documentation of RootFinder_,
 *                                       EventIterate_ and PrintEvent_.
 *           1.3  1999-03-03  Dag Bruck  Moved major parts from userfunc.c.
 *
 */

/*
 * Copyright (C) 1998-2001 Dynasim AB.
 * All rights reserved.
 *
 */

/* Set the following constants as needed, if defaults are not ok. */

/* Root finder available in integration algorithm. */
/* #define RootFinder_ 1 */

/* Event iteration: 1 = Iterate for consistent conditions after event. 
                    0 = Propagate event next time. */
/* #define EventIterate_ 1 */

/* Print events etc in Matlab window. */
/* Note: This is now [5.1] a set of flags. Corresponding to field debug in dsin.txt */
/* #define PrintEvent_ ((1<<1)|(1<<2)) */


/* Try LU factorizaton: 1 = Try an LU-factorization for solving linear systems*/
/*                      0 = Do not try to LU-factorize */
/* If the LU-factorizations fails or is not attempted we will use QR-factorization*/
/* to solve the system in the least squares sense. */
/* It seems as though LU-factorization often fails and we thus never attempt to LU-factorize*/
#ifndef TryLUFactorization_
#define TryLUFactorization_ 0
#endif

/* EquilibMatrix_: 1 = Perform row and column equilibrization before LU/QR-decomposition */
/*                 0 = Do not perform it */
/* Equilibrization implies a small performance hit, but improves the result for badly scaled systems*/

/* #define EquilibMatrix_ 1 */

/* LargeEPS_ Is the upper bound for event epsilon during event iterations */
/*           Adaptively increasing event epsilon is used to get past some nasty non-linearities */
/*           If LargeEPS_ is smaller than event epsilon it has no effect */

/* #define LargeEPS_ 1e-2 */

/* SlowIter_ Increasing event epsilon is only during problems with event iterations */
/*           SlowIter_ determines how many event iterations that should be attempted before concluding that*/
/*           the iterations are converging slowly and attempting to increase event epsilon (up to LargeEPS_).*/
/*           If it smaller than the MaxIter_ no attempt will be made. */

/* #define SlowIter_ 5 */


/* GenerateSimulinkTiming:  To get timing of the entire simulation in simulink */
/*                          Useful for timing purposes */
/*                          Uncomment the define to activate it */
/* #define GenerateSimulinkTiming */


/* Aim for high accuracy in non-linear solver */

/* Uncomment the following line to only get an accuracy comparable to the */
/* tolerance in the non-linear solver. Normally we try to ensure that the */
/* error is also less than the event epsilon in order to avoid chattering */
/* This takes additional time, but is sometimes necessary in order to */
/* avoid numerical chattering */
/* */
/* #define DymolaAimForHighAccuracy_ 0 */


/* DymolaNoGuard_ */
/* Uncomment to use faster div, asin, etc */
/* The faster versions does not generate errors for illegal values */
/* and can thus cause substantial problems, if the model is evaluated */
/* for values that are outside of the legal ranges */
/* */
/* #define DymolaNoGuard_ 1 */

/* DymolaNewJacobian_ */
/* Uncomment the following line to not recompute Jacobians for every */
/* non-linear system of equations, when a new solution procedure is started */
/* */
/* #define DymolaNewJacobian_ 0 */

/* For timing */
/* DymolaPrecisionTiming_ */
/* Several timing related ones, all activated by one switch */
/* They give more reliable timing It only works with Visual C++/Gcc and using IA32 */
/* You have to specify processor unless operating at maximum frequency on P4*/
/* #define DymolaPrecisionTiming_ 1*/

/* Timing group: Uncomment the following line to deactivate interrupts during execution
   of model code */
/* It gives more reliable timing, but has some other drawbacks*/
/* It only works with Visual C++/Gcc and using IA32 */
/* DANGER: It does CRASH under some operating systems after Windows 98, */
/* due to privileged instructions.  */
/* #define DymolaUninterruptedTimers_ 1*/

/* Uncomment the following line to use processor instruction counter */
/* #define DymolaUseRDTSC_ 1*/

/* Uncomment the following line to set processor frequency in Hz*/
/* Not needed if operating at maximum frequency on P4 or later */
/* #define DymolaUseRDTSCFrequency_ 1.6e9 */
/* Set to 0 to use auto-detection (for P4 or later and maximum frequency) */

/* Automatically remove computation of auxiliary variables that are not used */
/* in the rest of the model (not even with pre as discrete variable). */
/* These variables are normally only useful for plotting */
/* Auxiliaries are not useful in Simulink, and not useful if not stored inside Dymola */
/* Note: For historic reasons this is always done on dSpace */
/* #define DymolaAutoRemoveAuxiliaries_ 1 */

/* For limiting number of non-linear iterations */
/* No effect if 0 or larger than 8 */
/* #define DymolaNonLinearIterations_ 3 */

/* Uncomment the following to allow global optimization for Visual C++ */
/* Note that Visual C++ does not work well for large models with global optimization.
   (The compilations take a very long time).*/
/* The possibilities are: 
   0 - forbid (default)
   1 - allow
   2 - require */
/* #define DymolaGlobalOptimizations_ 2 */
#endif
