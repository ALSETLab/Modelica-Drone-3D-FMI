#ifndef amach_h
#define amach_h

/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

/* Provide machine characteristics (automatically set in "amach.h"
   depending on machine):

   WIN32, _WIN32   : WIN32_ONLY is set.
   UNIX            : ASCII and binary files are opened identically.
                     In non-UNIX systems, the ANSI-C flags are used.
   REALTIME_DYMOSIM: Dymosim can be called from other processes under 
                     control of a hardware clock.
   INLINE_DYMOSIM  : inline feature of Dymosim added
                     (not yet defined).
   NO_UNDERSCORE   : No underscore is appended on Fortran subroutines
                     names (not used within Dymosim; just to keep this
                     this information).
  

   Can be explicitly set, when needed:

   MSDOS_ONLY      : "stderr" is redirected to "stdout".
                     Is overwritten by WIN32_ONLY
   WIN32_ONLY      : no "printf" functions are called. Output is
                     written on a log file. Overwrites the "MSDOS"
                     settings. Overwrites MSDOS_ONLY setting.
   _WORK_ARRAY     : storage is not allocated with "malloc". Instead
                     storage is used form one big static array.
                     Should no longer be used.
*/


/* PCs (checked on Microsoft Visual C++, 1.0 and 4.0) */

#ifdef _WIN32
#  ifndef WIN32_ONLY
#     ifndef MSDOS_ONLY
#        define WIN32_ONLY
#     endif
#  endif
#endif

#ifdef WIN32
#  ifndef WIN32_ONLY
#     ifndef MSDOS_ONLY
#        define WIN32_ONLY
#     endif
#  endif
#endif

#ifdef WIN32_ONLY
#  ifdef MSDOS_ONLY
#     undef  MSDOS_ONLY
#  endif
#endif




/* Unix machines */

#ifdef alpha
#  ifndef UNIX
#     define UNIX
#  endif
#endif

#ifdef ultrix
#  ifndef UNIX
#     define UNIX
#  endif
#endif

#ifdef sun
#  ifndef UNIX
#     define UNIX
#  endif
#endif

#ifdef __convex__
#  ifndef UNIX
#     define UNIX
#  endif
#endif

#ifdef __sgi
#  ifndef UNIX
#     define UNIX
#  endif
#  ifndef REALTIME_DYMOSIM
#     define REALTIME_DYMOSIM
#  endif
#endif

#ifdef _AIX
#  define NO_UNDERSCORE
#  ifndef UNIX
#     define UNIX
#  endif
#  ifndef REALTIME_DYMOSIM
#     define REALTIME_DYMOSIM
#  endif
#endif

/* only ftn compiler */
#ifdef apollo
#  define NO_UNDERSCORE
#  ifndef UNIX
#     define UNIX
#  endif
#endif

#ifdef __hpux
#  ifndef UNIX
#     define UNIX
#  endif
#endif

#endif
