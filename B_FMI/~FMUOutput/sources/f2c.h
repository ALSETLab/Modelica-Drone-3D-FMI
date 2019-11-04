/* f2c.h  --  Standard Fortran to C header file */
/*
 * Copyright (C) 1995-2008 Dynasim AB.
 * All rights reserved.
 *
 * Based on the f2c.h which is copyright 1990 - 1997 by AT&T, Lucent Technologies and Bellcore.
 * 
 * AT&T, Lucent and Bellcore disclaim all warranties with regard to
 * this software, including all implied warranties of
 * merchantability and fitness.  In no event shall AT&T, Lucent or
 * Bellcore be liable for any special, indirect or consequential
 * damages or any damages whatsoever resulting from loss of use,
 * data or profits, whether in an action of contract, negligence or
 * other tortious action, arising out of or in connection with the
 * use or performance of this software.
 *
 */

/**  barf  [ba:rf]  2.  "He suggested using FORTRAN, and everybody barfed."

	- From The Shogakukan DICTIONARY OF NEW ENGLISH (Second edition) */

#ifndef F2C_INCLUDE
#define F2C_INCLUDE

#include "dymutil.h"
#include <string.h>
#include <stddef.h>
#if defined(DYMOLA_DSPACE) || defined(NO_FILE)
#include <dsdefs.h>
#else
#include <stdio.h>
#endif
#undef Dymola_min
#undef Dymola_max

typedef int integer;
typedef const char *address;
typedef short shortint;
typedef float real;
typedef double doublereal;
typedef struct { float r, i; } complex;
typedef struct { doublereal r, i; } doublecomplex;
typedef int  logical;
typedef short shortlogical;
typedef char logical1;
typedef char integer1;
typedef long long longint; /* system-dependent */

#define TRUE_ (1)
#define FALSE_ (0)

/* Extern is for use with -E */
#ifndef Extern
#define Extern extern
#endif

/* I/O stuff */

#ifdef f2c_i2
/* for -i2 */
typedef short flag;
typedef short ftnlen;
typedef short ftnint;
#else
typedef int flag;
typedef int ftnlen;
typedef int ftnint;
#endif

/*external read, write*/
typedef struct
{	flag cierr;
	ftnint ciunit;
	flag ciend;
	char *cifmt;
	ftnint cirec;
} cilist;

/*internal read, write*/
typedef struct
{	flag icierr;
	char *iciunit;
	flag iciend;
	char *icifmt;
	ftnint icirlen;
	ftnint icirnum;
} icilist;

/*open*/
typedef struct
{	flag oerr;
	ftnint ounit;
	char *ofnm;
	ftnlen ofnmlen;
	char *osta;
	char *oacc;
	char *ofm;
	ftnint orl;
	char *oblnk;
} olist;

/*close*/
typedef struct
{	flag cerr;
	ftnint cunit;
	char *csta;
} cllist;

/*rewind, backspace, endfile*/
typedef struct
{	flag aerr;
	ftnint aunit;
} alist;

/* inquire */
typedef struct
{	flag inerr;
	ftnint inunit;
	char *infile;
	ftnlen infilen;
	ftnint	*inex;	/*parameters in standard's order*/
	ftnint	*inopen;
	ftnint	*innum;
	ftnint	*innamed;
	char	*inname;
	ftnlen	innamlen;
	char	*inacc;
	ftnlen	inacclen;
	char	*inseq;
	ftnlen	inseqlen;
	char 	*indir;
	ftnlen	indirlen;
	char	*infmt;
	ftnlen	infmtlen;
	char	*inform;
	ftnint	informlen;
	char	*inunf;
	ftnlen	inunflen;
	ftnint	*inrecl;
	ftnint	*innrec;
	char	*inblank;
	ftnlen	inblanklen;
} inlist;

union Multitype {	/* for multiple entry points */
	integer1 g;
	shortint h;
	integer i;
	longint j;
	float r;
	doublereal d;
	complex c;
	doublecomplex z;
	};

typedef union Multitype Multitype;

typedef int Long;	/* No longer used; formerly in Namelist */

struct Vardesc {	/* for Namelist */
	char *name;
	char *addr;
	ftnlen *dims;
	int  type;
	};
typedef struct Vardesc Vardesc;

struct Namelist {
	char *name;
	Vardesc **vars;
	int nvars;
	};
typedef struct Namelist Namelist;

#undef Dymola_abs
#define Dymola_abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal)Dymola_abs(x)
#define Dymola_min(a,b) ((a) <= (b) ? (a) : (b))
#define Dymola_max(a,b) ((a) >= (b) ? (a) : (b))
#define dmin(a,b) (doublereal)Dymola_min(a,b)
#define dmax(a,b) (doublereal)Dymola_max(a,b)

/* undef any lower-case symbols that your C compiler predefines, e.g.: */

#ifndef Skip_f2c_Undefs
#undef cray
#undef gcos
#undef mc68010
#undef mc68020
#undef mips
#undef pdp11
#undef sgi
#undef sparc
#undef sun
#undef sun2
#undef sun3
#undef sun4
#undef u370
#undef u3b
#undef u3b2
#undef u3b5
#undef unix
#undef vax
#endif

/* Included from f2c.add (needed, if compiled with a C++ compiler) */
#ifdef __cplusplus
extern "C" {
#endif
extern int abort_(void);
extern double c_abs(const complex *);
extern void c_cos(complex *, const complex *);
extern void c_div(complex *, const complex *, const complex *);
extern void c_exp(complex *, const complex *);
extern void c_log(complex *, const complex *);
extern void c_sin(complex *, const complex *);
extern void c_sqrt(complex *, const complex *);
extern double d_abs(const double *);
extern double d_acos(const double *);
extern double d_asin(const double *);
extern double d_atan(const double *);
extern double d_atn2(const double *, const double *);
extern void d_cnjg(const doublecomplex *, const doublecomplex *);
extern double d_cos(const double *);
extern double d_cosh(const double *);
extern double d_dim(const double *, const double *);
extern double d_exp(const double *);
extern double d_imag(const doublecomplex *);
extern double d_int(const double *);
DYMOLA_STATIC double d_lg10(const double *);
extern double d_log(const double *);
extern double d_mod(const double *, const double *);
extern double d_nint(const double *);
extern double d_prod(const float *, const float *);
DYMOLA_STATIC double d_sign(const double *, const double *);
extern double d_sin(const double *);
extern double d_sinh(const double *);
extern double d_sqrt(const double *);
extern double d_tan(const double *);
extern double d_tanh(const double *);
extern double derf_(const double *);
extern double derfc_(const double *);
extern integer do_fio(ftnint *, char *, ftnlen);
extern integer do_lio(ftnint *, ftnint *, char *, ftnlen);
extern integer do_uio(ftnint *, char *, ftnlen);
extern integer e_rdfe(void);
extern integer e_rdue(void);
extern integer e_rsfe(void);
extern integer e_rsfi(void);
extern integer e_rsle(void);
extern integer e_rsli(void);
extern integer e_rsue(void);
extern integer e_wdfe(void);
extern integer e_wdue(void);
extern integer e_wsfe(void);
extern integer e_wsfi(void);
extern integer e_wsle(void);
extern integer e_wsli(void);
extern integer e_wsue(void);
extern int ef1asc_(ftnint *, ftnlen *, ftnint *, ftnlen *);
extern integer ef1cmc_(ftnint *, ftnlen *, ftnint *, ftnlen *);
extern integer f_back(alist *);
extern integer f_clos(cllist *);
extern integer f_end(alist *);
extern void f_exit(void);
extern integer f_inqu(inlist *);
extern integer f_open(olist *);
extern integer f_rew(alist *);
extern int flush_(void);
extern void getarg_(integer *, char *, ftnlen);
extern void getenv_(char *, char *, ftnlen, ftnlen);
extern short h_abs(const short *);
extern short h_dim(const short *, const short *);
extern short h_dnnt(const double *);
extern short h_indx(const char *, char *, ftnlen, ftnlen);
extern short h_len(const char *, ftnlen);
extern short h_mod(const short *, short *);
extern short h_nint(const float *);
extern short h_sign(const short *, const short *);
extern short hl_ge(const char *, const char *, ftnlen, ftnlen);
extern short hl_gt(const char *, const char *, ftnlen, ftnlen);
extern short hl_le(const char *, const char *, ftnlen, ftnlen);
extern short hl_lt(const char *, const char *, ftnlen, ftnlen);
extern integer i_abs(const integer *);
extern integer i_dim(const integer *, const integer *);
DYMOLA_STATIC integer i_dnnt(const double *);
DYMOLA_STATIC integer i_indx(const char *, const char *, ftnlen, ftnlen);
DYMOLA_STATIC integer i_len(const char *, ftnlen);
extern integer i_mod(const integer *, const integer *);
DYMOLA_STATIC integer i_nint(float *);
DYMOLA_STATIC integer i_sign(const integer *, const integer *);
extern integer iargc_(void);
extern ftnlen l_ge(const char *, const char *, ftnlen, ftnlen);
extern ftnlen l_gt(const char *, const char *, ftnlen, ftnlen);
extern ftnlen l_le(const char *, const char *, ftnlen, ftnlen);
extern ftnlen l_lt(const char *, const char *, ftnlen, ftnlen);
extern void pow_ci(complex *, const complex *, const integer *);
DYMOLA_STATIC double pow_di(const double *, const integer *);
extern short pow_hh(const short *, const shortint *);
DYMOLA_STATIC integer pow_ii(const integer *, const integer *);
extern double pow_ri(const float *, const integer *);
extern void pow_zi(doublecomplex *, const doublecomplex *, const integer *);
extern void pow_zz(doublecomplex *, const doublecomplex *, const doublecomplex *);
extern double r_abs(const float *);
extern double r_acos(const float *);
extern double r_asin(const float *);
extern double r_atan(const float *);
extern double r_atn2(const float *, const float *);
extern void r_cnjg(complex *, const complex *);
extern double r_cos(const float *);
extern double r_cosh(const float *);
extern double r_dim(const float *, const float *);
extern double r_exp(const float *);
extern double r_imag(const complex *);
extern double r_int(const float *);
extern double r_lg10(const float *);
extern double r_log(const float *);
extern double r_mod(const float *, const float *);
extern double r_nint(const float *);
extern double r_sign(const float *, const float *);
extern double r_sin(const float *);
extern double r_sinh(const float *);
extern double r_sqrt(const float *);
extern double r_tan(const float *);
extern double r_tanh(const float *);
DYMOLA_STATIC int s_cat(char *, const char *const*, const integer *, const integer *, ftnlen);
DYMOLA_STATIC integer s_cmp(const char *, const char *, ftnlen, ftnlen);
DYMOLA_STATIC int s_copy(char *, const char *, ftnlen, ftnlen);
extern int s_paus(char *, ftnlen);
extern integer s_rdfe(cilist *);
extern integer s_rdue(cilist *);
extern integer s_rnge(char *, integer, char *, integer);
extern integer s_rsfe(cilist *);
extern integer s_rsfi(icilist *);
extern integer s_rsle(cilist *);
extern integer s_rsli(icilist *);
extern integer s_rsne(cilist *);
extern integer s_rsni(icilist *);
extern integer s_rsue(cilist *);
extern int s_stop(char *, ftnlen);
extern integer s_wdfe(cilist *);
extern integer s_wdue(cilist *);
extern integer s_wsfe(cilist *);
extern integer s_wsfi(icilist *);
extern integer s_wsle(cilist *);
extern integer s_wsli(icilist *);
extern integer s_wsne(cilist *);
extern integer s_wsni(icilist *);
extern integer s_wsue(cilist *);
extern void sig_die(char *, int);
extern integer signal_(integer *, void (*)(int));
extern int system_(const char *, ftnlen);
extern double z_abs(doublecomplex *);
extern void z_cos(doublecomplex *, const doublecomplex *);
extern void z_div(doublecomplex *, const doublecomplex *, const doublecomplex *);
extern void z_exp(doublecomplex *, const doublecomplex *);
extern void z_log(doublecomplex *, const doublecomplex *);
extern void z_sin(doublecomplex *, const doublecomplex *);
extern void z_sqrt(doublecomplex *, const doublecomplex *);
extern int dserrs_ (const integer *err_type, const integer *ercode,
              const doublereal  *dval, const integer *ival,
              const char *cval, ftnlen cval_len);

DYMOLA_STATIC void dymosimmessage_(const char message[], int lstr);
DYMOLA_STATIC void dymosimmessagedouble_(const char message[], const double *d, int lstr);
DYMOLA_STATIC void dymosimmessagedouble2_(const char message[], const double *d, const char message2[], 
                            int lstr, int lstr2);
DYMOLA_STATIC void dymosimmessagedoubles_(const char message[], const double d[], const int *nd, int lstr);
DYMOLA_STATIC void DymosimMessageInt_(const char* message, const int *i, int lstr);

DYMOLA_STATIC void dymosimmessageSev_(int severity, const char message[], int lstr);
DYMOLA_STATIC void dymosimmessagedoubleSev_(int severity, const char message[], const double *d, int lstr);
DYMOLA_STATIC void dymosimmessagedouble2Sev_(int severity, const char message[], const double *d, const char message2[], 
                            int lstr, int lstr2);
DYMOLA_STATIC void dymosimmessagedoublesSev_(int severity, const char message[], const double d[], const int *nd, int lstr);
DYMOLA_STATIC void dymosimmessagedoublesSevIndent_(int severity, const char message[], const double d[], const int *nd, int lstr, unsigned indent);
DYMOLA_STATIC void DymosimMessageIntSev_(int severity, const char* message, const int *i, int lstr);

#if defined(LIBDS_EXPORTS) || defined(LIBDSDLL_EXPORTS)
#ifndef F2C_DISABLE_INTERNAL
#include "f2c_internal.h"
#endif
#endif


#ifdef __cplusplus
	}
#endif

#endif
