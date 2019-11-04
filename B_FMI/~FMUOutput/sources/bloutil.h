#ifndef BLOUTIL_H
#define BLOUTIL_H
#include <string.h>

#include "libdssetup.h"
/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

/* Signal declarations */
LIBDS_API void (blo3co_)(double*);
LIBDS_API void (blo3st_)(int*);
LIBDS_API void (blo3pt_)(int*);
LIBDS_API void (blo3sa_)(const char* s1, const char* s2, int*, int*  , int*, int, int);
LIBDS_API void (blo3sb_)(const char* s1, const char* s2, const char* s3, int*, int, int, int);
LIBDS_API void (blo3ta_)(const char* s1, const char* s2, const int*, const int*  , const int*, const int*, const int*, int, int);

LIBDS_API void (blo3sx_)(const char* s1, const char* s2, int, int);
LIBDS_API void (blo3sd_)(const char* s1, const char* s2, int, int);
LIBDS_API void (blo3su_)(const char* s1, const char* s2, int, int);
LIBDS_API void (blo3sy_)(const char* s1, const char* s2, int, int);
LIBDS_API void (blo3pd_)(const char* s1, const char* s2, int, int);
LIBDS_API void (blo3psd_)(const char* s1, const char* s2);
LIBDS_API void (blo3sw_)(const char* s1, const char* s2, int, int);
LIBDS_API void (blo3tz_)(const char* s1, const char* s2, const int*, const int*, int, int);
/* Same for tw ty tu td tx */
LIBDS_API void (blosid_)(int* i, double* d, int* ierr);
LIBDS_API void (blosii_)(int* i, int* j, int* ierr);
LIBDS_API int dymmdp_(void);

/* Macros for signal declarations */

#define blo3co_(d1) \
  do { d1_ = d1; blo3co_(&d1_); } while (0)

#define blo3st_(c1) \
  do { c1_ = c1; blo3st_(&c1_); } while (0)

#define blo3pt_(c1) \
  do { c1_ = c1; blo3pt_(&c1_); } while (0)

#define blo3sa_(s1,s2,c1,c2,c3) \
  do { c1_ = c1; c2_ = c2; c3_ = c3; \
  blo3sa_(s1, s2, &c1_, &c2_, &c3_, strlen(s1), strlen(s2)); } while (0)

#define blo3sb_(s1,s2,s3,c1) \
  do { c1_ = c1; \
  blo3sb_(s1, s2, s3, &c1_, strlen(s1), strlen(s2), strlen(s3)); } while (0)

#define blo3sx_(s1,s2) \
  blo3sx_(s1, s2, strlen(s1), strlen(s2))

#define blo3sd_(s1,s2) \
  blo3sd_(s1, s2, strlen(s1), strlen(s2))

#define blo3su_(s1,s2) \
  blo3su_(s1, s2, strlen(s1), strlen(s2))

#define blo3sy_(s1,s2) \
  blo3sy_(s1, s2, strlen(s1), strlen(s2))

#define blo3pd_(s1,s2) \
  blo3pd_(s1, s2, strlen(s1), strlen(s2))

#define blo3sw_(s1,s2) \
  blo3sw_(s1, s2, strlen(s1), strlen(s2))

#define blo3tz_(s1,s2,i,j) \
  blo3tz_(s1, s2, i, j, strlen(s1), strlen(s2))
#endif

