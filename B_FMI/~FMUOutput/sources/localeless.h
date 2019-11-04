#ifndef LOCALELESS_H
#define LOCALELESS_H

#include <stdarg.h>
#include <stdio.h>
#if !defined(DYMOLA_STATIC)
#if defined(__cplusplus)
#define DYMOLA_STATIC extern
#elif defined(RT) && !defined(DYM2DS)
#define DYMOLA_STATIC static
#else
#define DYMOLA_STATIC
#endif
#endif
/*
definition of common routines to ensure that they are in the C-locale.
*/
#ifdef __cplusplus
extern "C" {
#endif
DYMOLA_STATIC double atofC(const char *str);
DYMOLA_STATIC int atoiC(const char *str);
DYMOLA_STATIC int atolC(const char*str);
#if defined(_MSC_VER)
DYMOLA_STATIC int _stricmpC(const char *string1,const char *string2);
#endif
DYMOLA_STATIC int isalnumC(int c);
DYMOLA_STATIC int isalphaC(int c);
DYMOLA_STATIC int isdigitC(int c);
DYMOLA_STATIC int islowerC(int c);
DYMOLA_STATIC int isupperC(int c);
DYMOLA_STATIC int isspaceC(int c);

DYMOLA_STATIC int toupperC(int c);
DYMOLA_STATIC int tolowerC(int c);

DYMOLA_STATIC int fscanfC255s(FILE*, char*s);
DYMOLA_STATIC int fscanfC_Bracket_255s(FILE*, char*s, char*s2);
DYMOLA_STATIC int fscanfClf(FILE*, double*x);
DYMOLA_STATIC int fscanfClf3(FILE*, double*x, double*y, double*z);
DYMOLA_STATIC int fscanfCg(FILE*, float*);
DYMOLA_STATIC int fscanfCd(FILE*f,  int*x);
DYMOLA_STATIC int fscanfCu3(FILE*f,  unsigned*r,unsigned*g,unsigned*b);
DYMOLA_STATIC int fscanfCd3(FILE*f,  int*r,int*g,int*b);
DYMOLA_STATIC int fscanfCcond_version_s(FILE*f, char*cond, char*version,char*s);

DYMOLA_STATIC int sscanfCd(const char*line, int*);
DYMOLA_STATIC int sscanfCi(const char*line, int*);
DYMOLA_STATIC int sscanfCd_minus3(const char*line, int*y,int*m,int*d);
DYMOLA_STATIC int sscanfCd5(const char*line, int*a,int*b,int*c,int*d,int*e);
DYMOLA_STATIC int sscanfCi3_slash(const char*line,int*a,int*b,int*c);
DYMOLA_STATIC int sscanfCi2_slash(const char*line,int*a,int*b);
DYMOLA_STATIC int sscanfCi2_slashlash(const char*line,int*a,int*b);
DYMOLA_STATIC int sscanfCg(const char*line, float*);
DYMOLA_STATIC int sscanfCx2_underscore(const char*line,unsigned int*a,unsigned int*b);
DYMOLA_STATIC int sscanfClu(const char*line, unsigned int*a);
DYMOLA_STATIC int sscanfCtext_ssdd(const char*line, const char*fmt, char*a,char*b, int*c,int *d);
DYMOLA_STATIC int sscanfCincludename(const char*line, char*s);
DYMOLA_STATIC int sscanfCversion(const char*line,char*vers);

DYMOLA_STATIC int sscanfCg_comma(const char*line, float*x);

DYMOLA_STATIC int sscanfClg(const char*line, double*);
DYMOLA_STATIC int sscanfClg_49s(const char*line, double*x, char*s);
DYMOLA_STATIC int sscanfCcomp_s_par(const char*line, char*cond, char*vers);
DYMOLA_STATIC int sscanfCu(const char*line, unsigned*);
DYMOLA_STATIC int sscanfCg_comma4(const char*line, float*a,float*b,float*c,float*d);
DYMOLA_STATIC int sscanfCi_comma4(const char*line, int*a,int*b,int*c,int*d);
DYMOLA_STATIC int sscanfClfc(const char*line, double*d, char*dummy);
DYMOLA_STATIC int sscanfCtext_d(const char*line, const char*txtWithPercentD, int*x);
DYMOLA_STATIC int sscanfCtext_d3(const char*line, const char*txtWithPercentD, int*r,int*g,int*b);
DYMOLA_STATIC int sscanfCtext_d4(const char*line, const char*txtWithPercentD, int*a,int*b,int*c,int*d);
DYMOLA_STATIC int sscanfCtext_d5(const char*line, const char*txtWithPercentD, int*a,int*b,int*c,int*d,int*e);
DYMOLA_STATIC int sscanfC255s_n(const char*line, char*s,int*length);
DYMOLA_STATIC int sscanfC255s(const char*line, char*s);
DYMOLA_STATIC int sscanfCtext_s2(const char*line, const char*txtWithPercentD,char*a,char*b);
DYMOLA_STATIC int sscanfCtext_s4(const char*line, const char*txtWithPercentD,char*a,char*b,char*c,char*);
DYMOLA_STATIC int sscanfCtext_sd(const char*line, const char*txtWithPercentD,char*a,int*b);
DYMOLA_STATIC int sscanfCtext_s2d(const char*line, const char*txtWithPercentD,char*a,char*b,int*c);

DYMOLA_STATIC int sprintfC(char*s, const char*format, ...);
DYMOLA_STATIC int fprintfC(FILE*f, const char*format, ...);
DYMOLA_STATIC int vfprintfC(FILE*f, const char*format, va_list extra);
DYMOLA_STATIC int vsnprintfC(char*buf,size_t buf_len,const char*fmt,va_list arg);

DYMOLA_STATIC void freeClocale();
#ifdef __cplusplus
}
#endif
#endif
