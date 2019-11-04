/*
 * Special sprintf() for use with WATCOM C under MATLAB.
 * Calling sprintf() otherwise causes a fatal error.
 *
 * Copyright (c) 1999-2001 Dynasim AB. All rights reserved.
 *
 */

#if defined(__WATCOMC__)  && defined(DynSimStruct) && !defined(SPECIAL_SPRINTF)
#define SPECIAL_SPRINTF

static int special_sprintf(char* s, const char* format, ...)
{
	do {
		*s = *format;
		++s;
		++format;
	} while (*format != 0);
	s[0] = '\0';
	return 1;
}

#define sprintf special_sprintf

#endif

