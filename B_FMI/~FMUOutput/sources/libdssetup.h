#ifndef LIBDS_SETUP_H
#define LIBDS_SETUP_H

#if !defined(LIBDS_API)
#ifdef LIBDS_DLL
#ifdef LIBDSDLL_EXPORTS
#define LIBDS_API __declspec(dllexport)
#define LIBDS_API_AFTER __declspec(dllexport)
#else
#define LIBDS_API __declspec(dllimport)
#define LIBDS_API_AFTER __declspec(dllimport)
#endif
#else
  #if defined(RT) && !defined(DYM2DS) && !defined(DYM2CCUR)
   #define LIBDS_API static
  #else
#define LIBDS_API extern
  #endif
#define LIBDS_API_AFTER
/* Without extern since it is after DYMOLA_STATIC */
#endif
#endif

#endif
