#include "localeless.h"
#include <math.h>
#if _MSC_VER >= 1400 || defined(UNIX) /*|| defined(__MINGW32__)*/	/* To avoid compilation error on dSPACE DS1006 (gcc) */
#include <locale.h>
#else
#define LC_ALL 0
DYMOLA_STATIC char* setlocale(int category, const char* locale) {
	return "";
}
#endif
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#if _MSC_VER >= 1400
#ifdef __cplusplus
class MyCLocal {
	MyCLocal(MyCLocal const&);
	void operator=(MyCLocal const&);
public:
	_locale_t cloc;
	MyCLocal() { cloc = _create_locale(LC_ALL, "C"); }
	~MyCLocal() { _free_locale(cloc); }
};
static _locale_t *Clocale() {
	/* Avoiding memory leak at end */
	static MyCLocal myloc;
	return &myloc.cloc;
};
void freeClocale() {
	/*Emtpy in CPP only relevant for c code*/
};
#else /*  __cplusplus */
static _locale_t cloc = NULL;
static int firstTime = 1;
static _locale_t *Clocale() {
	/* The c-version has a memory leak; cannot avoid without using atexit and atexit for DLLs seems bad */
	if (firstTime) cloc = _create_locale(LC_ALL, "C");
	firstTime = 0;
	return &cloc;
}
void freeClocale() {
	_free_locale(cloc);
	cloc = NULL;
	firstTime = 1;
}
#endif  /* __cplusplus */

#else /* _MSC_VER >= 1400 */

#if defined(UNIX) /*|| defined(__MINGW32__)*/
DYMOLA_STATIC char* setAndSaveLocale() {
	char *oldLoc = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "C");
	return oldLoc;
}

#define INT_CALL1(func, arg)                                         \
  char* oldLoc = setAndSaveLocale();                                 \
  int val = func(arg);                                               \
  setlocale(LC_ALL, oldLoc);                                         \
  return val

#define DOUBLE_CALL1(func, arg1)                                     \
  char* oldLoc = setAndSaveLocale();			                     \
  double val = func(arg1);                                           \
  setlocale(LC_ALL, oldLoc);			                             \
  return val

#define INT_CALL2(func, arg1, arg2)                                  \
  char* oldLoc = setAndSaveLocale();                                 \
  int val = func(arg1, arg2);                                        \
  setlocale(LC_ALL, oldLoc);			                             \
  return val

#define INT_CALL3(func, arg1, arg2, arg3)                            \
  char* oldLoc = setAndSaveLocale();                                 \
  int val = func(arg1, arg2, arg3);                                  \
  setlocale(LC_ALL, oldLoc);			                             \
  return val

#define INT_CALL4(func, arg1, arg2, arg3, arg4)                      \
  char* oldLoc = setAndSaveLocale();                                 \
  int val = func(arg1, arg2, arg3, arg4);                            \
  setlocale(LC_ALL, oldLoc);			                             \
  return val

#define INT_CALL5(func, arg1, arg2, arg3, arg4, arg5)                \
  char* oldLoc = setAndSaveLocale();                                 \
  int val = func(arg1, arg2, arg3, arg4, arg5);                      \
  setlocale(LC_ALL, oldLoc);			                             \
  return val

#define INT_CALL6(func, arg1, arg2, arg3, arg4, arg5, arg6)          \
  char* oldLoc = setAndSaveLocale();                                 \
  int val = func(arg1, arg2, arg3, arg4, arg5, arg6);                \
  setlocale(LC_ALL, oldLoc);			                             \
  return val

#define INT_CALL7(func, arg1, arg2, arg3, arg4, arg5, arg6, arg7)    \
  char* oldLoc = setAndSaveLocale();                                 \
  int val = func(arg1, arg2, arg3, arg4, arg5, arg6, arg7);          \
  setlocale(LC_ALL, oldLoc);			                             \
  return val

#else /* defined(UNIX) || defined(__MINGW32__) */

DYMOLA_STATIC char* setAndSaveLocale() {
	return "";
}

#define INT_CALL1(func, arg)                                         \
  return func(arg)

#define DOUBLE_CALL1(func, arg)                                      \
  return func(arg)

#define INT_CALL2(func, arg1, arg2)                                  \
  return func(arg1, arg2)

#define INT_CALL3(func, arg1, arg2, arg3)                            \
  return func(arg1, arg2, arg3)

#define INT_CALL4(func, arg1, arg2, arg3, arg4)                      \
  return func(arg1, arg2, arg3, arg4)

#define INT_CALL5(func, arg1, arg2, arg3, arg4, arg5)                \
  return func(arg1, arg2, arg3, arg4, arg5)

#define INT_CALL6(func, arg1, arg2, arg3, arg4, arg5, arg6)          \
  return func(arg1, arg2, arg3, arg4, arg5, arg6)

#define INT_CALL7(func, arg1, arg2, arg3, arg4, arg5, arg6, arg7)    \
  return func(arg1, arg2, arg3, arg4, arg5, arg6, arg7)

#endif /* defined(UNIX) || defined(__MINGW32__) */
#endif /* _MSC_VER >= 1400 */

double atofC(const char *str) {
#if _MSC_VER >= 1400
	return _atof_l(str, *Clocale());
#else
	DOUBLE_CALL1(atof, str);
#endif
}

int atoiC(const char *str) {
#if _MSC_VER >= 1400
	return _atoi_l(str, *Clocale());
#else
	INT_CALL1(atoi,str);
#endif
}

int atolC(const char *str) {
#if _MSC_VER >= 1400
	return _atol_l(str, *Clocale());
#else
	INT_CALL1(atol, str);
#endif
}

#if _MSC_VER
int _stricmpC(const char *string1,const char *string2) {
#if _MSC_VER >= 1400
	return _stricmp_l(string1, string2, *Clocale());
#else
	return _stricmp(string1, string2);
#endif
}
#endif /* _MSC_VER */

int isalnumC(int c) {
#if _MSC_VER >= 1400
	return _isalnum_l(c, *Clocale());
#else
	INT_CALL1(isalnum, c);
#endif
}

int isalphaC(int c) {
#if _MSC_VER >= 1400
	return _isalpha_l(c, *Clocale());
#else
	INT_CALL1(isalpha, c);
#endif
}

int isdigitC(int c) {
#if _MSC_VER >= 1400
	return _isdigit_l(c, *Clocale());
#else
	INT_CALL1(isdigit, c);
#endif
}

int isupperC(int c) {
#if _MSC_VER >= 1400
	return _isupper_l(c, *Clocale());
#else
	INT_CALL1(isupper, c);
#endif
}

int islowerC(int c) {
#if _MSC_VER >= 1400
	return _islower_l(c, *Clocale());
#else
	INT_CALL1(islower, c);
#endif
}

int isspaceC(int c) {
#if _MSC_VER >= 1400
	return _isspace_l(c, *Clocale());
#else
	INT_CALL1(isspace, c);
#endif
}

int toupperC(int c) {
#if _MSC_VER >= 1400
	return _toupper_l(c, *Clocale());
#else
 #if !defined(NO_FILE)
	INT_CALL1(toupper, c);
 #else
	return c;
 #endif
#endif
}

int tolowerC(int c) {
#if _MSC_VER >= 1400
	return _tolower_l(c, *Clocale());
#else
	INT_CALL1(tolower, c);
#endif
}

extern int fscanfC_Bracket_255s(FILE*f, char*s, char *s2) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	_fscanf_l(f, "%[^\\[]255s", *Clocale(), s);
	return _fscanf_l(f, "%1s", *Clocale(), s2);
 #else
	char* oldLoc = setAndSaveLocale();
	fscanf(f, "%[^\\[]255s", s);
	int val = fscanf(f, "%1s", s2);
	setlocale(LC_ALL, oldLoc);
	return val;
 #endif
#else
	return 0;
#endif
}

extern int fscanfC255s(FILE*f, char*s) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f, "%255s", *Clocale(), s);
 #else
	INT_CALL3(fscanf, f, "%255s", s);
 #endif
#else
	return 0;
#endif
}

extern int fscanfClf(FILE*f, double*x) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f, " %lg", *Clocale(), x);
 #else
	INT_CALL3(fscanf, f, "%lg", x);
 #endif
#else
	return 0;
#endif
}
extern int fscanfClf3(FILE*f, double*x, double*y, double*z) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f, " %lg %lg %lg",  *Clocale(), x,y,z);
 #else
	INT_CALL5(fscanf, f, " %lg %lg %lg", x, y, z);
 #endif
#else
	return 0;
#endif	
}
extern int fscanfCg(FILE*f, float*x) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f,  " %g", *Clocale(), x);
 #else
	INT_CALL3(fscanf, f, " %g", x);
 #endif
#else
	return 0;
#endif
}
extern int fscanfCd(FILE*f,  int*x) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f, " %d", *Clocale(), x);
 #else
	INT_CALL3(fscanf, f, " %d", x);
 #endif
#else
	return 0;
#endif
}
extern int fscanfCu3(FILE*f,  unsigned*r,unsigned*g,unsigned*b) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f, " %u %u %u", *Clocale(), r,g,b);
 #else
	INT_CALL5(fscanf, f, " %u %u %u", r, g, b);

 #endif
#else
	return 0;
#endif
}
extern int fscanfCd3(FILE*f,  int*r,int*g,int*b) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f, " %d %d %d", *Clocale(), r,g,b);
 #else
	INT_CALL5(fscanf, f, " %d %d %d", r, g, b);
 #endif
#else
	return 0;
#endif
}

extern int fscanfCcond_version_s(FILE*f, char*cond, char*vers,char*s) {
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	return _fscanf_l(f," %[<>=] \"%[^\"]\" %s)",*Clocale(), cond,vers,s);
 #else
	INT_CALL5(fscanf, f," %[<>=] \"%[^\"]\" %s)", cond, vers, s);
 #endif
#else
	return 0;
#endif
}

extern int sscanfCd(const char*line, int*x) {
#if _MSC_VER >= 1400
	return _sscanf_l(line, " %d", *Clocale(), x);
#else
#if !defined(NO_FILE)
	INT_CALL3(sscanf, line, " %d", x);
#else
	return 0;
#endif
#endif
}
extern int sscanfCd5(const char*line, int*a, int*b,int*c,int*d,int*e) {
#if _MSC_VER >= 1400
	return _sscanf_l(line, " %d %d %d %d %d", *Clocale(), a,b,c,d,e);
#else
#if !defined(NO_FILE)
	INT_CALL7(sscanf, line, " %d %d %d %d %d", a, b, c, d, e);
#else
	return 0;
#endif
#endif
}

extern int sscanfCd_minus3(const char*line, int*y,int*m,int*d) {
#if _MSC_VER >= 1400
	return _sscanf_l(line, "%d-%d-%d", *Clocale(), y, m, d);
#else
#if !defined(NO_FILE)
	INT_CALL5(sscanf, line, "%d-%d-%d", y, m, d);
#else
	return 0;
#endif
#endif
}
extern int sscanfClg_49s(const char*line, double*x, char*s) {
#if _MSC_VER >= 1400
	return _sscanf_l(line, "%lg %49s", *Clocale(), x, s);
#else
#if !defined(NO_FILE)
	INT_CALL4(sscanf, line, "%lg %49s", x, s);
#else
	return 0;
#endif
#endif
}

extern int sscanfCg(const char*line, float*x){
#if _MSC_VER >= 1400
	return _sscanf_l(line,  " %g", *Clocale(), x);
#else
#if !defined(NO_FILE)
	INT_CALL3(sscanf, line, " %g", x);
#else
	return 0;
#endif
#endif
}
extern int sscanfCx2_underscore(const char*line,unsigned int*a,unsigned int*b) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%x_%x", *Clocale(), a,b);
#else
#if !defined(NO_FILE)
	INT_CALL4(sscanf, line, "%x_%x", a, b);
#else
	return 0;
#endif
#endif
}
extern int sscanfClu(const char*line, unsigned int*a) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%u", *Clocale(), a);
#else
#if !defined(NO_FILE)
	INT_CALL3(sscanf, line, "%u", a);
#else
	return 0;
#endif
#endif
}



extern int sscanfCg_comma(const char*line, float*x){
#if _MSC_VER >= 1400
	return _sscanf_l(line,  " %g,", *Clocale(),x);
#else
#if !defined(NO_FILE)
	INT_CALL3(sscanf, line, " %g,", x);
#else
	return 0;
#endif
#endif
}

extern int sscanfClg(const char*line, double*x) {
#if _MSC_VER >= 1400
	return _sscanf_l(line, " %lg", *Clocale(), x);
#else
#if !defined(NO_FILE)
	INT_CALL3(sscanf, line, " %lg", x);
#else
	return 0;
#endif
#endif
}
extern int sscanfCcomp_s_par(const char*line, char*cond, char*vers) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  " %[<>=] %s)",*Clocale(), cond, vers);
#else
#if !defined(NO_FILE)
	INT_CALL4(sscanf, line, " %[<>=] %s)", cond, vers);
#else
	return 0;
#endif
#endif
}
extern int sscanfCu(const char*line, unsigned*x) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  " %u", *Clocale(),x);
#else
#if !defined(NO_FILE)
	INT_CALL3(sscanf, line, " %u", x);
#else
	return 0;
#endif
#endif
}
extern int sscanfCg_comma4(const char*line, float*a,float*b,float*c,float*d) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%g,%g,%g,%g,",*Clocale(), a,b,c,d);
#else
#if !defined(NO_FILE)
	INT_CALL6(sscanf, line, "%g,%g,%g,%g,", a, b, c, d);
#else
	return 0;
#endif
#endif
}
extern int sscanfCi_comma4(const char*line, int*a,int*b,int*c,int*d) {
#if _MSC_VER >= 1400
	return _sscanf_l(line, "%i,%i,%i,%i,", *Clocale(),  a,b,c,d);
#else
#if !defined(NO_FILE)
	INT_CALL6(sscanf, line, "%i,%i,%i,%i,", a, b, c, d);
#else
	return 0;
#endif
#endif
}
extern int sscanfCi(const char*line, int*a) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%i",*Clocale(),a);
#else
#if !defined(NO_FILE)
	INT_CALL3(sscanf, line, "%i",a);
#else
	return 0;
#endif
#endif
}
extern int sscanfClfc(const char*line, double*d, char*dummy) {
	#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%lg %c",*Clocale(), d, dummy);
#else
#if !defined(NO_FILE)
	INT_CALL4(sscanf, line, "%lg %c", d, dummy);
#else
	return 0;
#endif
#endif
}
extern int sscanfCtext_ssdd(const char*line, const char*fmt, char*a,char*b, int *c,int *d) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  fmt,*Clocale(), a,b,c,d);
#else
#if !defined(NO_FILE)
	INT_CALL6(sscanf, line, fmt, a, b, c, d);
#else
	return 0;
#endif
#endif
}
extern int sscanfCincludename(const char*line, char*s) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "#include \"%[^\"]\"",*Clocale(), s);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL3(sscanf, line, "#include \"%[^\"]\"", s);
#else
	return 0;
#endif
#endif
}
extern int sscanfCversion(const char*line,char*vers) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "( version = \"%[^\"]\" )",*Clocale(), vers);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL3(sscanf, line,"( version = \"%[^\"]\" )", vers);
#else
	return 0;
#endif
#endif
}

extern int sscanfCtext_d(const char*line, const char*txtWithPercentD, int*x) {
	#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), x);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL3(sscanf, line, txtWithPercentD, x);
#else
	return 0;
#endif
#endif
}
extern int sscanfCtext_d3(const char*line, const char*txtWithPercentD, int*r,int*g,int*b) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), r,g,b);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL5(sscanf, line, txtWithPercentD, r, g, b);
#else
	return 0;
#endif
#endif
}

extern int sscanfCtext_d4(const char*line, const char*txtWithPercentD, int*a,int*b,int*c,int*d) {
	#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), a,b,c,d);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL6(sscanf, line, txtWithPercentD, a, b, c, d);
#else
	return 0;
#endif
#endif
}
extern int sscanfCtext_d5(const char*line, const char*txtWithPercentD, int*a,int*b,int*c,int*d,int*e) {
	#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), a,b,c,d,e);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL7(sscanf, line, txtWithPercentD, a, b, c, d, e);
#else
	return 0;
#endif
#endif
}
extern int sscanfCi3_slash(const char*line,int*a,int*b,int*c) {
	#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%i/%i/%i",*Clocale(), a,b,c);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL5(sscanf, line, "%i/%i/%i", a, b, c);
#else
	return 0;
#endif
#endif
}
extern int sscanfCi2_slash(const char*line,int*a,int*b) {
	#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%i/%i",*Clocale(), a,b);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL4(sscanf, line, "%i/%i", a, b);
#else
	return 0;
#endif
#endif
}
extern int sscanfCi2_slashlash(const char*line,int*a,int*b) {
	#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%i//%i",*Clocale(), a,b);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL4(sscanf, line, "%i//%i", a, b);
#else
	return 0;
#endif
#endif
}
		
extern int sscanfC255s_n(const char*line, char*s,int*length) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%255s%n",*Clocale(), s, length);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL4(sscanf, line, "%255s%n", s, length);
#else
	return 0;
#endif
#endif
}
extern int sscanfC255s(const char*line, char*s) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  "%255s",*Clocale(), s);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL3(sscanf, line, "%255s", s);
#else
	return 0;
#endif
#endif
}

extern int sscanfCtext_s2(const char*line, const char*txtWithPercentD,char*a,char*b) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), a,b);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL4(sscanf, line, txtWithPercentD, a, b);
#else
	return 0;
#endif
#endif
}
extern int sscanfCtext_s4(const char*line, const char*txtWithPercentD,char*a,char*b,char*c,char*d) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), a,b,c,d);
#else
#if !defined(NO_FILE)
	INT_CALL6(sscanf, line, txtWithPercentD, a, b, c, d);
#else
	return 0;
#endif
#endif
}
extern int sscanfCtext_sd(const char*line, const char*txtWithPercentD,char*a,int*b) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), a,b);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL4(sscanf, line, txtWithPercentD, a, b);
#else
	return 0;
#endif
#endif
}
extern int sscanfCtext_s2d(const char*line, const char*txtWithPercentD,char*a,char*b,int*c) {
#if _MSC_VER >= 1400
	return _sscanf_l(line,  txtWithPercentD,*Clocale(), a,b,c);
#else
#if !defined(NO_FILE) && !defined(LABCAR)
	INT_CALL5(sscanf, line, txtWithPercentD, a, b, c);
#else
	return 0;
#endif
#endif
}
extern int sprintfC(char*s, const char*format, ...) {
	va_list extra;
	int res;
	va_start(extra, format);
#if _MSC_VER >= 1400
	res = _vsprintf_l(s, format, *Clocale(), extra);
#else
	char* oldLoc = setAndSaveLocale();
	res = vsprintf(s, format, extra);
	setlocale(LC_ALL, oldLoc);
#endif
	va_end(extra);
	return res;
}

extern int fprintfC(FILE*f, const char*format, ...) {
	va_list extra;
	int res;
	va_start(extra, format);
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	res = _vfprintf_l(f, format, *Clocale(), extra);
 #else
	char* oldLoc = setAndSaveLocale();
	res = vfprintf(f, format, extra);
	setlocale(LC_ALL, oldLoc);
 #endif
#else
	res = -1;
#endif
	va_end(extra);
	return res;
}

extern int vfprintfC(FILE*f, const char*format, va_list extra) {
	int res;
#if !defined(NO_FILE)
 #if _MSC_VER >= 1400
	res = _vfprintf_l(f, format, *Clocale(), extra);
 #else
	char* oldLoc = setAndSaveLocale();
	res = vfprintf(f, format, extra);
	setlocale(LC_ALL, oldLoc);
 #endif
#else
	res = -1;
#endif
	return res;
}

extern int vsnprintfC(char*buf,size_t buf_len,const char*fmt,va_list arg) {
  int res;
  /* Use len-1 to ensure that string will be nul-terminated. */
#if _MSC_VER >= 1400
  res=_vsnprintf_l(buf, buf_len-1, fmt, *Clocale(), arg);
#elif defined(_MSC_VER) && _MSC_VER >= 1200
  res=_vsnprintf(buf, buf_len-1, fmt, arg);
#else
  char* oldLoc = setAndSaveLocale();
  res = vsnprintf(buf, buf_len-1, fmt, arg);
  setlocale(LC_ALL, oldLoc);
#endif
  buf[buf_len-1] = 0;
  return res;
}
