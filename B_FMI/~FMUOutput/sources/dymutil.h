/* dymutil.h 
 *
 * Declarations of utility functions for Dymosim.
 *
 * Author: Hilding Elmqvist, Dynasim AB, 1995-02-21
 * Version: 1.0, 1996-11-01
 *
 */
/*
 * Copyright (C) 1995-2001 Dynasim AB.
 * All rights reserved.
 *
 */

#ifndef DYMUTIL_H
#define DYMUTIL_H

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

#ifdef __cplusplus
extern "C" {
#endif
DYMOLA_STATIC void DymosimMessage(const char* message);
DYMOLA_STATIC void DymosimMessageDouble(const char* message, double d);
DYMOLA_STATIC void DymosimMessageInt(const char* message, int i);
DYMOLA_STATIC double DymosimError(const char* message);

#ifdef __cplusplus
}
#endif
#endif
