/* dsdefs.h
 *
 * This is a "dummy" version of stdio.h etc. for systems which lack one.
 * Rename it is stdio.h if needed.
 *
 * Functions printf() and sprintf() are defined here, but neither
 * of them do anything useful.
 *
 * Version 1.2	Dag Bruck
 *         1.3  Dag Bruck   Updated for DYMOLA_DSPACE.
 *
 * Copyright (C) 1997-2004 Dynasim AB.
 * All rights reserved.
 *
 */

#ifndef DSDEFS_H
#define DSDEFS_H

#if !defined(RTLAB) && !defined(LABCAR) && !defined(DYM2DS) && !defined(FMU_SOURCE_SINGLE_UNIT)
#if defined(NO_FILE) || ( defined(DYMOLA_DSPACE) && !defined(__STDIO_H) )
#define FILE int
#define fpos_t unsigned int
#if defined(DYMOLA_DSPACE)
#define __STDIO_H
#endif
#endif

#if defined(DYMOLA_DSPACE)
static int printf(const char* format, ...)
{ return 0; }

static int sprintf(char* s, const char* format, ...)
{ s[0] = '\0'; return 0; }
#endif
#endif

#if !defined(assert) && !defined(DYM2DS) && !defined(FMU_SOURCE_SINGLE_UNIT)
#define assert(test) (void)0
#endif

#endif
