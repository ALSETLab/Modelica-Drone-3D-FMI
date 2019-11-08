#ifndef DYMOSIM_DLLDATA
#define DYMOSIM_DLLDATA
/* For aprint.c */
#include "stdio.h"
#include <stddef.h>



/* For delay.c */
#ifndef DELAYSTRUCT_H
#define DELAYSTRUCT_H
typedef struct {    /* struct for storing the delay/derivative information */
  double *x;        /* column of time values */
  double *y;        /* column of values, which belong to time values of
		               same row */
  double timedelay; /* value of timedelay (used for delays only) */
  int nx;           /* buffersize of the system = number of columns */
  int first;        /* column of first value in the buffer */
  int old;          /* column of last interpolation step */
  int add;          /* column of last value added to the buffer */
} delayStruct;     
#endif

enum ImpulseType {NoImpulse=0,PositiveOne=1,SymmetricOne=2,DiracDeActive=3,DiracActive=4};

typedef struct  {
	int Dymola_totalImpulses;
	int Dymola_activateImpulses;
    double *Impulsev1;
    double *Impulsev2;
	double *Savev1;
	double *Savev2;
	double *Lambda;

	double *SaveF;
	double *SaveDFFirst;
	double *SaveXLast;
	double *SaveXStart;
	double *M;
	double *N1;
	double *N1M;
	double *N2;
	double *N2M;

	int ImpulseCalled;
	int EqCalled;

	int *condv;
	int *typeImpulse;
	int *symImpulseComp;
	int *ipiv;
	int DebugImpulse ;
	int FreezeCond;
	int ActivateDirac;
	int IsActive;
	int nStates;
	double fractionOfDiracStep;
} DYNImpulseStruct;



/* --------------------------------------- */

/* For aadsm4_ */

/* --------------------------------------- */

/* For dsadd.c */
#define NTYP  6
#define NTYPA 7
#include "adymosim.h"
#include "atraj.h"
typedef char         *vec;             /* vec is pointer to char              */ 
typedef struct {
  short    isConstant;
  short    storeIn;     /* = 0: don't store signal                         */
                        /* = 1: store signal in matrix data_1 (constant)   */
                        /* = 2: store signal in matrix data_2 (continuous) */
  integer    icol;      /* Fortran-Index with respect to result            */
                        /* data matrix data_1 or data_2                    */
  integer    vectorIndex;
} sigInfoTyp;


typedef struct {
  integer  offset;  /* Index with respect to table vector (C-index) */
                   /* = -1, if wrong alias signal (don't use)      */
  short    type;   /* Type of signal 0/1/2/3/4/5/6 X/U/Y/Z/W/XD/P  */
  short sign ;     /* Sign of reference vector +1/-1 if >/<0.      */
} aliasInfoTyp;

typedef struct {
  dsBaseType basetype;  /* type of signal      */
  dsCategory category : 8;
  char locallyAllocatedName;
  union {
	  sigInfoTyp sigInfo;
	  aliasInfoTyp aliasInfo;
  } info;
  char*name;
  char*description;
} combinedInfoTyp;


struct DsAddInfo {
integer       nSignals;        /* Total number of signal elements     */
                                       /* ns = 1 +nx + nu + ny + nz + nw + nx+np */
integer       na;              /* Total number of alias elements      */
integer       nres;            /* Number of result variables          */
                                       /* including Time                      */
integer      *resIndex;        /* Result indices with respect to      */
                                       /* Signal vector "table".              */
                                       /*   allocated storage: resIndex[ns]   */
                                       /*   storage used     : resIndex[nres] */
                                       /* Signals table[ resIndex[i] ],       */
                                       /* i=0,1,...,nres-1 are stored on file */ 
Atrajectory  *traj;            /* Trajectory to be stored on file     */

combinedInfoTyp   *combinedInfo;    
									   /* Pointer to signal information      */
                                       /* (= combinedInfo[ns+na])                    */
integer combinedInfoIndex;
integer combinedInfoNonAliasIndex;

integer       lastSignal;    /* Last stored signal in table        */
integer       lastTyp;      /* Last stored signal type            */
integer       nlast;         /* Number of last stored signals      */


integer*      (tableNrLookup[NTYP+1]);
                                       /* Go from e.g. state number to number in tableSignals */
integer*      (tableNrNonAliasLookup[NTYP+1]);
                                       /* Same excluding alias */
integer       tableIndex[NTYP+1];
									   /* Where we are in tableNrLookup */
                                       /*      [0] < nx                      */
                                       /*      [1] < nu                      */
                                       /*      [2] < ny                      */
                                       /*      [3] < nz                      */
                                       /*      [4] < nw                      */
                                       /*      [5] < nxd                     */
									   /*      [6] < np						 */

integer       tableDim[NTYP+1];     /* Dimensions of signals              */
                                       /*  ndim[0] = nx                      */
                                       /*      [1] = nu                      */
                                       /*      [2] = ny                      */
                                       /*      [3] = nz                      */
                                       /*      [4] = nw                      */
                                       /*      [5] = nxd                     */
                                       /*      [6] = np                      */

integer tableOffset[NTYP+1];

vec          *resName ;   /* Vector of result names             */
                                       /* resName[ns+na]                     */
vec          *resDtext;   /* Vector of result descriptions      */
                                       /* resDtext[ns+na]                    */
integer      *resCol;     /* Vector of result info matrix       */
                                       /* resCol[TRAJ_NINFO*(ns+na)]         */

integer       np;              /* total number of parameters          */
integer       nsp;			  /* and string parameters */
integer       actualsp; 

integer       ni;              /* dimension of iname vector               */
vec          *iname;      /* Pointer to initial variable name vector */
                                       /* (the elements of the vector point to    */
                                       /*  the names stored in table and pname).  */
    vec          *idesc;      /* Similar for description string */
	AdymosimInitial *ivalue;      /* ivalue[ni]; memory for initial data     */
};
/* --------------------------------------- */

#ifndef DYMOSIM_SEVERITY_H
#define DYMOSIM_SEVERITY_H
enum Dymosim_Severity {Dymosim_Message,Dymosim_Warning,Dymosim_Error};
#endif
/* Dymosim2.c*/
struct Dymosim2Setup {
   const char *simfinal;   /* final input file    */
   int finalBinary;
   const char *resfile;
   integer simStart;
   int     oldInputFormat;
   Adymosim adymosim; /* Used for new routines */
   integer  isFMU;    /* Flag to signal that it is an FMU sim   */
};
	struct aadsm3Struct {
    integer lprec, lx, lxd, lu, ly, lz, lw, la, lperf, levent, lres, lshare, 
	    lform;
	};
/* --------------------------------------- */

/* From dsres.c */
/* For error stat */
struct errcounter {
	int limiter;
	int dominating;
	int exceeds10p;
};
struct DymosimModel;
struct DymosimSimulator;
struct DymosimVariableHandle;
struct DymosimLinearization;
struct SimulatorFunctions {
	int (*mainModel)(int, char *[], const struct DymosimModel*);
	struct DymosimSimulator* (*newf)(const char*,const char*,const char*,void*,void*,void(*Err)(enum Dymosim_Severity,const char*),int);
	struct DymosimSimulator* (*newf2)(const char*,const char*,const char*,void*,void*,void(*Err)(enum Dymosim_Severity,const char*),int, const char*,int);
	int (*run)(struct DymosimSimulator*,double);
	int (*runTo)(struct DymosimSimulator*,double);
	int (*load)(struct DymosimSimulator*,const char*);
	int (*save)(struct DymosimSimulator*,const char*);
	int (*terminateAndFree)(struct DymosimSimulator*,int,const char*,int);

	AdymosimExperiment (*getExperiment)(struct DymosimSimulator*);
	void (*setExperiment)(struct DymosimSimulator*,AdymosimExperiment);
	AdymosimMethod (*getMethod)(struct DymosimSimulator*);
	void (*setMethod)(struct DymosimSimulator*,AdymosimMethod);
	AdymosimSettings (*getSettings)(struct DymosimSimulator*);
	void (*setSettings)(struct DymosimSimulator*,AdymosimSettings);

	void (*print)(struct DymosimSimulator*,int , const char*);
	int (*licensing)(struct DymosimSimulator*,const char*);
	int (*initialize)(struct DymosimSimulator*);
	int (*linearize)(struct DymosimSimulator*,struct DymosimLinearization*);

	int (*enumerateVariables)(struct DymosimSimulator*,struct DymosimVariableHandle*,integer*);
	int (*enumerateAliases)(struct DymosimSimulator*,struct DymosimVariableHandle*,const char**,integer*,integer*);
	int (*enumerateAll)(struct DymosimSimulator*,struct DymosimVariableHandle*,const char**,integer*,integer*);
	int (*findVariableByName)(struct DymosimSimulator*,const char*,struct DymosimVariableHandle*);
	int (*findVariableByNumber)(struct DymosimSimulator*,dsCategory,integer,struct DymosimVariableHandle*);
	int (*variablesNr)(struct DymosimSimulator*,dsCategory);
	const char*(*variablesName)(struct DymosimSimulator*,dsCategory,integer);
	double (*getValue)(struct DymosimSimulator*,dsCategory,integer);
	int (*setValue)(struct DymosimSimulator*,dsCategory,integer,double);

	double (*getTime)(struct DymosimSimulator*);
	int ext;
	const char* (*getDescription)(struct DymosimSimulator*,dsCategory,integer);
	int (*runToEvent)(struct DymosimSimulator*,double*,int);
	int (*resetModel)(struct DymosimSimulator*,int okTerminate);
	const char* (*getDescription2)(struct DymosimSimulator*,dsCategory,integer,integer);
	const char* (*getString)(struct DymosimSimulator*,dsCategory,integer);
	int (*setString)(struct DymosimSimulator*,dsCategory,integer,const char*);
	int (*getDirectionalDerivatives)(struct DymosimSimulator*,const unsigned int[],
		const integer, const unsigned int[],const integer, const double [], double[]);
	int (*getFMUState)(struct DymosimSimulator*, void**);
	int (*setFMUState)(struct DymosimSimulator*, void*);
	void (*freeFMUState)(struct DymosimSimulator*, void**);
	int(*setRealInputDerivatives)(struct DymosimSimulator*, const int[], size_t, const int[], const double[]);
	int (*getRealOutputDerivatives)(struct DymosimSimulator*, const unsigned int [], size_t, const int [], double []);
	int(*serializedFMUstateSize)(struct DymosimSimulator*sim, void * fmuState, size_t *size);
	int(*serializeFMUstate)(struct DymosimSimulator* sim, void* FMUstate, char* serializedState, size_t size);
	int(*deSerializeFMUstate)(struct DymosimSimulator* sim, const char serializedState[], size_t size, void** FMUstate);
};
#include "dsblock.h"

struct DymosimSimulator { 
	/* From aprint.c */
	FILE *fp_out;
	FILE *fp_err;
	const char *log_name; /* log file name */
	const char *pName;  /* program name          */
	int   share; /* multiple processes    */
	int   noFileBasedMessages; /* don't create files when delivering a message */
	
	/* From aadsm1.h */
	struct {
		doublereal t0, tend, dtco, tolr, hfix, hmax, hmin, h0, teps, eveps, 
			delaym, tscale;
		integer ncom, imeth, nt, evuord, pdebug, fmax, ordmax, eviter, memkey, 
			icpdum, grid, dense, evgrid, evu, error, jac, xd0c, f3, f4, f5, 
			debug, fexcep, shared;
	} aadsm1_;
	
	/* From aadsm2.h */
	struct {
		ptrdiff_t iatg;
		integer tgpts;
		ptrdiff_t iax0, iaxd0, iaxscl;
	} aadsm2_;
	
	/* From aadsm3.h, dscom.h, dssim1.c */
	struct aadsm3Struct aadsm3_;
	
	/* From aadsm4.h and dsaux.c: */
	struct {
		doublereal time, tcp, dperf[4];
		integer nxm, nx, nu, ny, nzm, nz, nw, nf[9], nfsim[9], nfm, nfmsim, nsig, 
			niter, ftime, fstate, fstep, ftimeu, fcomm, fevent, fstore, 
			fprior;
		ptrdiff_t iax, iau, iay, iaz, iaw, iaxd, iasig, iax2, iau2, iay2, 
			iaz2, iaw2, iaxd2, iasig2;
		integer ndu, niu, ncu;
		ptrdiff_t iaiter;
		integer cgOffset, gcOffset;
		doublereal tcp_init, tbegin;
	} aadsm4_;
	
	/* From dssim1b.c, dscom.h, dssim1.c */
	struct {
		doublereal dhmin, dhmax;
		integer nkev, ngridp, nstep, nfev, nhev, njev, nte, nue, nse, noe, kmax, 
			nee, nfev_excl_Jac_evals;
	} aadsm5_;
	
	/* From aadsm6.h, dssim1b.c, dscom.h, dssim1.c */
	struct {
		integer inttyp, intord;
		logical introo, intmod, intmin, intjac, intres, intfix;
	} aadsm6_;
	
	/* From aadsm7.h, dssim1b.c, dssim1.c */
	struct {
		doublereal epsd, told, tbeg, tfin, ten[2], dextra[20], toldh, toldn, 
			tnext, dhmin0, tgn, tfin2, dtco2, tuev, ttev[2];
		integer idblo, ftype, istep, jacobi;
		ptrdiff_t iaf, iaxs, iaxds;
		integer gu;
		ptrdiff_t iagui;
		integer gxd, 
			kxd, icall[15], evn;
		ptrdiff_t iaiwi;
		integer niwi;
		ptrdiff_t iadwi;
		integer ndwi, infi[25], iextra[
			30];
		ptrdiff_t iaroot;
		integer neq[3];
		ptrdiff_t iadir;
		logical icalhh;
		integer ngrid;
		ptrdiff_t iatgn;
		integer cfmax, err[12], itopt, idrsu, fuev, ftev, ftuev, 
			iduev[4], action;
		logical tcom;
		ptrdiff_t iata, iatr;
	} aadsm7_;
	
	/* From aadsm8.h, dssim1b.c, dssim1.c */
	struct {
		char dtexti[132], host[8], method[8], cgrid[8], cdense[8], cegrid[8], 
			cevu[8], cerror[8], cjac[8], cxd0c[8], cf3[8], cf4[8], cf5[8], 
			cdebug[8];
	} aadsm8_;
	
	/* From dssim1b.c, dssim1.c */
	struct {
		integer sgopt, iasdb, ias1;
	} aadsm9_;
	
	/* From aadum1.h,  dscom.h */
	struct {
		ptrdiff_t iadpp, iaipp, ialpp;
		integer ndp, nip, nlp;
	} aadum1_;
	
	/* From dscom.h, dsusei1.c */
	struct {
		doublereal gdval[5], pdval[8], gdstep;
		integer ht1def, ht2def, shelp1[31], shelp2[31], smodel[31], sres[31], 
			swork[31], gival[4], pival[6], jatola;
		ptrdiff_t jaxscl;
		integer nxscl, gut, iaguit,
			gxdt, kxdt, gistep;
	} aaduib_;
	
	/* From dscom.h, dsusei1.c */
	struct {
		char dtext1[132], vers1[8], file1[255], dtext2[132], vers2[8], file2[255],
			filew[255], filem[255];
	} aaduic_;
	
	/* From dsusei1.c, dymosim2.c, rsyaux.c, rsyaux2.h */
	union {
		struct {
			char cv[8];
		} _1;
		struct {
			char csp[8];
		} _2;
	} rsycv_;
	
	/* From dscom.h */
	struct {
		char block[8];
	} aaduin_;
	
	/* From dscom.h, dsusei1.c */
	struct {
		integer npmax, idimmx[5], dimma2, sigerr, nstore, npac, idim[5], idblo;
			ptrdiff_t ianame, iaidt, ialdt, iatype, iandim, iadim, iabeg, iamin, iamax, 
			iadmin, iadmax;
	} aaduip_;
	
	/* From dscom.h, dsusei1.c */
	struct {
		integer isig[7], idim[7], isigmx[7], idimmx[7];
		ptrdiff_t ianame[6], iaidt[6], 
			ialdt[6], iandim[6], iadim[6], iabeg[6];
		integer sigerr, nstore, nsarr, 
			nselem, nsacc[6];
		ptrdiff_t icname, icidt, icldt, icndim, icdim, icbeg1, 
			icbeg2, icrmin, icrmax;
	} aaduis_;
	
	/* From dscom.h, dsint3.c */
	union {
		struct {
			doublereal told4, urd, fac1, fac2, safe2, safe3, hmax, errold;
		} _1;
		struct {
			doublereal told4, uround, fac1, fac2, safe2, safe3, hmax, errold;
		} _2;
	} errcom_;
	
	/* From dscom.h, dsint3.c */
	struct {
		logical reject, fail;
	} logcom_;
	
	/* From dscom.h */
	struct {
		integer istu9, istu10, lcv;
	} memcsu_;
	
	/* From dsint4.c, dsint6.c, dsint7.c, dscom.h */
	union {
		struct {
			doublereal conit, crate, el[13], elco[156]	/* was [13][12] */, 
				hold, rmax, tesco[36]	/* was [3][12] */, ccmax, el0, h, 
				hmin, hmxi, hu, rc, tn, uround;
			integer iownd[14], ialth, ipup, lmax, meo, nqnyh, nslp, icf, ierpj, 
				iersl, jcur, jstart, kflag, l, meth, miter, maxord, maxcor, 
				msbp, mxncf, n, nq, nst, nfe, nje, nqu;
		} _1;
		struct {
			doublereal rowns[209], ccmax, el0, h, hmin, hmxi, hu, rc, tn, uround;
			integer iownd[14], iowns[6], icf, ierpj, iersl, jcur, jstart, kflag, 
				l, meth, miter, maxord, maxcor, msbp, mxncf, n, nq, nst, nfe, 
				nje, nqu;
		} _2;
		struct {
			doublereal rowns[209], ccmax, el0, h, hmin, hmxi, hu, rc, tn, uround;
			integer illin, init, lyh, lewt, lacor, lsavf, lwm, liwm, mxstep, 
				mxhnil, nhnil, ntrep, nslast, nyh, iowns[6], icf, ierpj, 
				iersl, jcur, jstart, kflag, l, meth, miter, maxord, maxcor, 
				msbp, mxncf, n, nq, nst, nfe, nje, nqu;
		} _3;
	} rpcld1_;
	
	
	/* From dscom.h, dsint4.c */
	union {
		struct {
			doublereal rownr3[2], t0, tlast, toutc;
			integer lg0, lg1, lgx, iownr3[2], irfnd, itaskc, ngc, nge;
		} _1;
		struct {
			doublereal rownr3[2], t0, tlast, toutc;
			integer iownd3[3], iownr3[2], irfnd, itaskc, ngc, nge;
		} _2;
		struct {
			doublereal alpha, x2, rdum3[3];
			integer iownd3[3], imax, last, idum3[4];
		} _3;
	} rpcld2_;
	
	/* From dscom.h, dsint4.c, dsint5.c */
	union {
		struct {
			doublereal tsw, rowns2[20], pdnorm;
			integer insufr, insufi, ixpr, iowns2[2], jtyp, mused, mxordn, mxords;
		} _1;
		struct {
			doublereal rownd2, pdest, pdlast, ratio, cm1[12], cm2[5], pdnorm;
			integer iownd2[3], icount, irflag, jtyp, mused, mxordn, mxords;
		} _2;
	} rpcld3_;
	
	/* From dscom.h, dsint1.c, dsint2.c */
	struct {
		integer npd, ntemp, inorm, lml, lmu, lmxord, lny, lm1, lmtype, lnst, lnre,
			lnje, letf, lctf, lipvt;
	} rpcld4_;
	
	/* From dscom.h, dsaux.c */
	struct {
		integer iierr;
	} rperr_;
	
	/* From dscom.h */
	struct {
		integer izchar, ilchar, maxint;
		/*real reamax, reamin;*/
		integer lfrec;
	} rsychr_;
	
	/* From dscom.h, rsyaux2.h */
	struct {
		integer istsp, laesp, istsf, laesf;
	} rsycsp_;
	
	/* From dscom.h, rsyaux2.h */
	struct {
		char ttx[132];
	} rsyoch_;
	
	/* From dscom.h */
	struct {
		integer nfe, nje, nstep, nrejct, nocon, irejct;
	} stat_;
	
	/* From dscom.h */
	struct {
		doublereal c_scjold__, c_s__, c_h__, c_alphas__, c_uround__;
		integer c_neq__, c_neq_x__, c_jcalc__, c_maxit__, c_ntemp__, c_ires__, 
			iavc, iascj, iawt, iae, nsf, iawt2, iadel;
	} rpdazc_;
	
	/* From dscom.h */
	
	struct {
		/* struct used in SQP method */
		int nerr, igo;
		char name[7];
	} fehler_;
	
	/* From dscom.h, dsinit.c, dsadd.c, dssim1.c, dsuse1.c, dsusei1.c */
	
	struct {
		ptrdiff_t iadp, iaip, ialp, iadu, iaiu, ialu;
	} aadcco_;
	
	/* From dsblocks.c, dssim1.c, dssim1b.c, dsuse1.c, dsusei1.c, dymosim2.c, rsyaux.c, rsyaux2.h, rsysp.h*/
	struct {
		doublereal dsp[1];
	} rsysp_;
	
	/* All data for dsadd.c */
	struct DsAddInfo dsaddInfo;
	/* All data for dymosim2.c */
	struct Dymosim2Setup dymosim2Setup;
	int installedSignalHander;
	
	/* from dsres.c */
	
	struct  {
		AmatPutFile  file     ;    /* File identificator              */
		real        *rres;    /* Pointer to real   result vector */
		doublereal  *dres;    /* Pointer to double result vector */
		int          ResOpen;    /* = 0: not result file opened     */
		/* = 1: result file opened         */
		int          ResStart;   /* = 0: simulation not yet started */
		/* = 1: simulation started         */
		Atrajectory *trajSig;      /* Trajectory to be stored on file */
		integer      nresSig;      /* Number of result signals        */
		/* including time                  */
		integer     *resSigIndex;  /* Result signal index;            */
		/* resSigIndex[nresSig]                  */
		
		
		int have_written_to_dsres;
		/* For error stat */
		
		struct errcounter*errcount;			/* Should be free'd */
		int errcountsize;

		int diagnostics_file_initialized;
		FILE * fp_diagnostics;
		int last_diagnostics_flush;

		int event_type;
		int event_log_file_initialized;
		FILE * fp_event_log;
		int event_iteration;
		struct {
			int time_event;
			int state_event;
			int step_event;
		} event_log;
		int event_iteration_failed;
		char **iteration_variable_names;
		double *iteration_variable_nominals;
		int current_iteration_variable;
		int nx_orig;
		int last_event_flush;
		char **nonlinear_equation_system_tags;
		int num_nonlinear_equation_systems;
		int num_nonlinear_tags_stored;
		
		void *diagnostics_utils;
	} dsRes;
	
	/* From dsrs.c */
	struct {
		int          uzero;     /* 1/0 no/u-signals                        */
		int          nu;        /* dimension of u signal                   */
		Atrajectory *utraj;  /* pointer to trajectory containing u-data */
	} dsRs;
	
	/* From mess.c */
	struct {
		double audioOutputFrequency;
		int simulation_is_terminated;
		int is_dymosim_realtime;
		int dymosim_communicate_through_request;
		unsigned int  global_sequence_number;
		int isStopped;
		int outputcount;
		int handleRequestNew;
	} messData;
	/* From dssim1.c */
	struct {
		struct {
			integer nfevpe;
		} aads11_;
	} dssim1Data;
	
	/* From dsusei1.c */
	struct {
		struct {
			integer mjac, mdim[16];
			integer msig[6];
			integer mstep;
			char mblock[8];
			integer mftype, mstore;
		} aadclb_0_;
		struct {
			integer ndimp, dimpp[3];
		} aadcpb_0_;
	} dsusei1Data;
	
	/* From dssim1b.c */
	struct {
		struct {
			doublereal tbeg3;
			doublereal dtco3;
			integer info2;
			integer ngrid3;
			doublereal tsnext;
			integer restart;
		} aadsbs_;
	} dssim1bData;
	
	/* From dsopt.c */
	struct {
		struct {
			doublereal f, h;
			integer i, m;
			doublereal hf;
			integer je, jf, jg, me, mf, mg;
			doublereal fp, fs;
			integer iag, ldg;
			doublereal sum;
			integer iadf, iadg, iaie, iaif, iaig;
			char char_[60];
			integer iagp, ircd, iags, irco, iaxl, ldum, ipri, iaxu, iadum;
			integer iaidum, maxold, itrmax;
		} rpmmos_;
		struct {
			integer j;
			doublereal del, xtmpj, stepsz;
		} rpmmo1_;
		struct {
			integer j;
			doublereal del, xtmpj, stepsz;
		} rpmmo2_;
		struct {
			integer i, m1, n1, mi, is, iu, iv, iw, icd, idcl, ivmu, idclf, 
				itest;
		} rpsls1_; 
		struct {
			integer i, j, i1, m1, il, mn, nn, iw, iw1;
			doublereal dbd;
			integer iac, ibc, iec, lam;
			doublereal dfs;
			integer irc, lds, nni, i9876, nnn, iwm, ixl;
			doublereal sum;
			integer ixu;
			char name[6];
			doublereal fold;
			integer line;
			doublereal fpen;
			
			integer ierr, nnni;
			doublereal zeta, fpen0;
			
			doublereal alpha, dhilf;
			
			doublereal delta, theta;
			integer itermx;
		} rpsls2_;
		
		
	} dsoptData;
	
	/* From dsint1.c */
	struct {
		struct {
			doublereal h;
			integer i;
			doublereal r;
			integer le, lk;
			doublereal ho, rh, tn;
			integer lpd, lns, lwm, lwt;
			logical done;
			doublereal dval[2];
			integer ival[2];
			doublereal hmax;
			integer ires, lphi;
			doublereal hmin;
			integer liwm, icall[3], lkold;
			doublereal atoli;
			integer leniw, itemp, nzflg, lenrw;
			doublereal tdist;
			integer mxord;
			doublereal rtoli;
			integer lnstl;
			doublereal tnext, tstop;
			integer ljcalc, lcheck, ercode, lphase, lencor;
			doublereal uround, ypnorm;
		} rpdac1_;
	} dsint1Data;
	
	/* From dsint2.c */
	struct {
		struct {
			integer i, j;
			doublereal r;
			integer j1, m1;
			doublereal ck;
			integer m1d, km1, kp1, kp2, ncf, nef;
			doublereal erk, err, est;
			integer nsp1;
			doublereal hnew;
			integer ires;
			doublereal terk, xold;
			integer knew;
			doublereal erkm1, erkm2, erkp1, temp1, temp2;
			integer kdiff, iretc;
			doublereal enorm, alpha0;
			doublereal terkm1, terkm2;
			doublereal terkp1, alphas;
			logical convgd;
			doublereal cjlast;
		} rpdac2_,rpdad2_;
		struct {
			integer nsf;
		} rpdac3_;
	} dsint2Data;
	
	/* From dsint3.c */
	struct {
		struct {
			doublereal a[12], h;
			integer i, j, k;
			doublereal w[12], h1, t1;
			integer kc;
			doublereal hh[12], cx, wt;
			integer iex;
			doublereal err, tol;
			integer ijac;
			doublereal pfac;
			logical last;
			integer itol, kopt, ityp[3], icall[3];
			doublereal scale;
			doublereal tolmin, uround;
		} rpdae2_;
		struct {
			doublereal dxold;
		} rpdae5_;
	} dsint3Data;
	
	/* From dsint4.c */
	struct {
		struct {
			integer lf0;
		} rpdoc1_;
	} dsint4Data;
	
	/* From dsint5.c */
	struct {
		struct {
			integer lfirst;
		} rpdol2_;
		struct {
			integer inflop;
		} rpdoa1_;
	} dsint5Data;
	
	/* From dsint6.c */
	struct {
		struct {
			integer lfirst;
		} rpdom2_;
	} dsint6Data;
	
	/* From dsint9.c */
	struct {
		struct {
			integer i, j, m;
			doublereal y;
			integer je, ii;
			doublereal del;
			integer ier;
			doublereal scj;
			integer jwt, jwt2, njac, jdel;
			doublereal rate;
			integer ipar[2], nfev;
			doublereal rpar[2];
			integer jump, nrow;
			doublereal squr, temp1;
			doublereal ysave, pnorm, delnrm, delinv, oldnrm;
			doublereal h_yprime__;
		} rpdazi_;
	} dsint9Data;
	
	/* From dymola source */
	struct {
		struct BasicDDymosimStruct*basicD;
		struct BasicIDymosimStruct*basicI;
		void**basicV;
		double initialTime;
		double isEvent;

		void (*errHandler)(enum Dymosim_Severity,const char*msg); /* For DLL. Can be 0 */
		struct DymosimModel functions;

	} modelData;

	struct LicenseDataDLL {
		double valMult; /* Default 0 */
		int c;			/* Default 0 */
		unsigned int v_TEA_License_ref[2];
		unsigned int v_TEA_License[2];
		unsigned int w_TEA_License[2];
		unsigned int TEA_ok; /* True if licKey as given on command line is correct, Default 0 */
		unsigned int TEA_ok2; /* True if internal structures are correct, Default 0 */
	} licenseData;

	void (*LoadSnapshotHook)(struct Adymosim*);
	void (*SaveSnapshotHook)(struct Adymosim*);

	DYNImpulseStruct impulseStruct;
	const char*const*dlls;
	void**handles;

	integer anyNonEvent;
	logical ignoreStopTime;
	integer useFixedStepFix;
	double fixedStepTime;
	integer additionalData[6];
	struct stringParameters {
		size_t nsp;
		char ** sParameters;
	} stringParameters;
	struct fmiOutputDers {
		size_t ny;
		double * lastY;
		double lastTime;
		int fixStepCrossComputed;
	} fmiOutputDers;

	struct fmiJacobian {
		double* fmiJacA;
		double* fmiJacB;
		double* fmiJacC;
		double* fmiJacD;
		double* dxPert;
		double* dxPert2;
		double* yPert;
		double* yPert2;
		double* orig_dx;
		double* orig_y;
		double* delta;
		double* delta2;
		size_t jnx;
		size_t jnu;
		size_t jny;
		int updateJacobian;
	} fmiJacobian;

	struct fmiInputExtr {
		double *uder; /*Starts with zeroth order i.e first col is equal to u at t0*/
		double *uTaylor; /*Tailor expantion of u*/
		size_t nu;
		int highestInputDer;
		double t0;
		double preExtrTime;
	} fmiInputExtr;

	void *superlu_data;
	int superlu_first_factorization;
	int superlu_first_analytic_build;

	struct EqRememberAcceptedStruct {
		int is_set;
		double set_time;
	} eq_remember_accepted;

	struct ExtraSizeData {
		size_t szIax0;
		size_t szIaxd0;
		size_t szDuser;
		size_t szIuser;
		size_t ndp; 
		size_t nip; 
		size_t nlp; 

	} extraSizeData;
};
struct DymosimSimulatorBackup {
	struct DymosimSimulator simCpy;
	struct DYNInstanceData* did;
	doublereal* iaisigDataBlock; 
	doublereal* iaisig2DataBlock; 
	doublereal* iaDataBlock[5]; 
	integer* iadirDataBlock; 
	integer* iarootDataBlock; 
	integer* iaiwiDataBlock; 
	doublereal* iadwiDataBlock; 
	doublereal* iax0DataBlock; 
	doublereal* iaxd0DataBlock; 
	doublereal* iaxscl0DataBlock; 
	doublereal* iaduDataBlock; 
	integer* iaiuDataBloack; 
	integer* iaaduipDataBlock[7];
	doublereal* daaduipDataBlock[2];
	doublereal* iadpDataBlock;
	integer* iaipDataBlock;
	integer* ialpDataBlock;
	integer* iaaduisDataBlock[5];
	real* faaduisDataBlock[2];
	doublereal * delData;
	size_t nbrIaisig; 
	size_t nbrIaisig2; 
	size_t lf0; 
	size_t nmx; 
	size_t nzm; 
	size_t niwi; 
	size_t ndwi; 
	size_t niax0;
	size_t niaxd0;
	size_t niadu; 
	size_t niaiu;
	size_t npmax; 
	size_t ndp; 
	size_t nip; 
	size_t nlp; 
	size_t nsarr;
	size_t nDel;
	size_t nDelData;
};
#ifdef __cplusplus
extern "C" {
#endif
void initializeThreadDymosimSimulator(); /* Call after dymosimSetThreadData */
void initializeThreadDymosimSimulator2(int); /* Call after dymosimSetThreadData */

#ifdef LIBDS_DLL
LIBDS_API_AFTER void dymosimSetThreadData(struct DymosimSimulator*);
LIBDS_API_AFTER struct DymosimSimulator* dymosimGetThreadData();
static void dymosimUnSetThreadData(struct DymosimSimulator*data) {
	dymosimSetThreadData(0);
}
#else
#if defined(RT) || defined(FMU)
DYMOLA_STATIC struct DymosimSimulator dataNoDll = {0,0,"?????","?????",FALSE_};
DYMOLA_STATIC struct DymosimSimulator*dataNoDllPtr = 0;
#else
extern struct DymosimSimulator dataNoDll;
extern struct DymosimSimulator*dataNoDllPtr;
#endif
static struct DymosimSimulator* dymosimGetThreadData() {
	return dataNoDllPtr ? dataNoDllPtr : &dataNoDll;
}
static void dymosimSetThreadData(struct DymosimSimulator*data) {
	/* if (data) memcpy(&dataNoDll,data,sizeof(struct DymosimSimulator)); */
	dataNoDllPtr = data;
}
static void dymosimUnSetThreadData(struct DymosimSimulator*data) {
	/* if (data) memcpy(data,&dataNoDll,sizeof(struct DymosimSimulator)); */
	dataNoDllPtr = 0;
}
#endif
#ifdef __cplusplus
}
#endif
#endif
