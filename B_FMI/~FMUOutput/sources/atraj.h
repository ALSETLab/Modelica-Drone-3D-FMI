#ifndef atraj_h
#define atraj_h

#if defined (GCC) && defined(GODESS)
/* gcc does not always seem to handle #include statement within 'extern "C"-block', so add another block here */
extern "C" {
#endif

/*
 * Copyright (C) 1997-2010 Dynasim AB.
 * All rights reserved.
 *
 */

/* 
   Write object of class "Atrajectory" to file.
   Read object of class "Atrajectory" from file. 
   The following possibilities exist:

   1. The file contains the following matrices:
         Aclass              : Information about class (class name,
                               version number="1.1", description text).
         name       (nName,*): String matrix of names.
         description(nName,*): String matrix of description text for each name.
         info       (nName,5): Information matrix which defines how the
                               trajectory is defined:
                               info(i,1) = j: name i data is stored in matrix
                                              "data_j".
                               info(i,2) = k: name i data is stored in column
                                              abs(k) of matrix data_j with
                                              sign(k) used as sign.
                               info(i,3) = 0   : linear interpolation
                                         = 1..4: polygon spline which is 
                                                 differentiable upto order 1..4.
                               info(i,4) =-1: not defined outside of time range.
                                         = 0: keep first/last point 
                                              outside of time range.
                                         = 1: interpolate through first/last
                                              two points outside of time range.
                                         = 2: keep first point outside of
                                              minimum time and periodically 
                                              repeating the signal outside
                                              of right time range
                                              (not yet implemented)
                               info(i,5) = offset of signal (this columns is only
                                           available on file. After reading the
                                           file, the offset is added to the data
                                           matrices.
                               info(1,1) = 0 means, that column info(1,2)
                               is the abscissa data "name(1,*)"
                               of ALL data matrices. This is usually "time".
                               This special rule is necessary, since otherwise
                               the abscissa name has to be repeated in "name"
                               and the names in "name" would be no longer unique.
         data_1     (nt1,nc1): First data matrix.
         data_2     (nt2,nc2): Second data matrix.
              ...
         data_n     (ntn,ncn): N-th data matrix.

   2. The file contains the following 3 matrices:
         Aclass         : Information about class (class name,
                          version number="1.0", description text).
         names(nName,*) : String matrix of names
         data (nt,nName): Numeric data. Time is stored in the first column.

   3. The file contains one numeric matrix. In this case a default
      signal name matrix is build automatically.

   The trajectory data may be retrieved in float or in double precision.
   It is always returned in "column-dense" format, i.e. all columns 
   of a matrix are stored in consecutive order one after the other in a
   vector (= FORTRAN storage format). Every column of the matrix corresponds 
   to one trajectory signal. The first column is the time vector.

   When writing an Atrajectory object to file, ONE of the data matrices
   can be stored without knowing the number of rows in advance
   (= the matrix is stored one row after the other).

   Functions:
      atrajRead   : Read trajectory data from file
                    (object of class Atrajectory or single matrix).
      atrajWrite  : Write trajectory object to file.

      atrajWinit  : Initialize row-wise writing of trajectory object to file.
      atrajWclose : Close row-wise writing of trajectory object.
      atrajWreal  : Write one row of a real       matrix to file.
      atrajWdouble: Write one row of a doublereal matrix to file.

      atrajNew    : Allocate storage for a new trajectory object
                    and initialize it (set all components to NULL).
      atrajInit   : Initialize a trajectory object 
                    (set all components to NULL).
      atrajDel    : Delete the contents of a trajectory object
                    (and set all components to NULL).

   Example:
      Atrajectory *traj;
      char        *file = "temp.mat";
      
      // Read trajectory "traj" from file 
         if ( (traj = atrajRead(file, realPrec)) == NULL ) goto ERROR;
         printf("Read trajectory from file \"%s\n"
                "(\"%s\")\n", file, traj.title;
           ...
         atrajDel(traj); 
         return;

      // Error handling (amatError is a global variable, defined in "amat.h")
         ERROR: fprintf(stderr,"Error in program XXX:\n%s",amatError);
                return 1;
*/

#include "amat.h"


/* Trajectory format of version 1.1

   Note, that the indices of arrays stored in "info" are with respect
   to the storage format on File (= Matlab, Fortran format) and NOT with
   respect to C-arrays (= matrix indices start with 1).
*/

extern const int TRAJ_NINFO;      /* Column number of traj.info matrix */
extern const int TRAJ_IPO_MIN;    /* Minimum interpolation number      */
extern const int TRAJ_IPO_MAX;    /* Maximum interpolation number      */
extern const int TRAJ_EXPO_MIN;   /* Minimum extrapolation number      */
extern const int TRAJ_EXPO_MAX;   /* Maximum extrapolation number      */

typedef struct {
  AmatData   time;    /* Pointer to time vector of data matrix i     */
                      /*   real/double time[ntime]                   */
  int        ntime;   /* Number of time points                       */
  AmatType   prec;    /* Precision of data (real/double)             */
  int        ibeg;    /* C-index of begin of actual interval         */
  int        iend;    /* C-index of end of actual interval           */
                      /*   time[i] < time[i+1] for i=ibeg..iend-1    */
  int        ilast;   /* C-index of last interpolation interval      */
                      /* (at time[ilast..ilast+1])                   */
  int        ijump;   /* = 0: last interval (no discontinuous        */
                      /*      point anymore).                        */
                      /* = 1: tjump is the next discontinuous        */
                      /*      point.                                 */               
  doublereal tjump;   /* Time instant of next discontinuous point    */
                      /* if ijump=1.                                 */
                      
                      /* The following flags indicate whether        */
                      /* information about the time vector has       */
                      /* already been stored.                        */
  int        tindex;  /* C-index of actual time vector               */
                      /* (0..IDeval->nData). If -1, this structure   */ 
                      /* is not yet initialized.                     */
  int        tdata;   /* C-index of actual time vector with          */
                      /* respect to traj, i.e., traj.data[tdata]     */
                      /* contains the actual time vector             */   
} AtrajInfoTime;


typedef struct {
  AtrajInfoTime *tinfo; /* Pointer to abscissa data.           */
                        /* If Null, no signal is defined.      */
  AmatData       sig;   /* Pointer to signal vector.           */
                        /*   real/double sig[tptr->ntime]      */
                        /* If Null, no signal is defined       */
  int            ipo;   /* Interpolation method                */
  int            expo;  /* Extrapolation method                */
  int            sign;  /* Sign of signal (+1/-1)              */
  char          *name;  /* Name of signal                      */
  int            offset; /* used for doubleRowMatrix           */
} AtrajInfoSignal;


typedef struct {
   AtrajInfoTime   *tinfo;  /* Information of abscissa data              */
                            /*   tinfo[ntMax]                            */
   AtrajInfoSignal *sinfo;  /* Information of data to be interpolated    */
                            /*   sinfo[nsig]                             */
   AmatType         prec;   /* Precision of data (real/double)           */
   int              ntMax;  /* Maximum number of different time vectors  */   
   int              nt;     /* Number of utilized time vectors           */   
   int              nsig;   /* Number of signals to be interpolated      */
   int              ijump;  /* = 0: last interval (no discontinuous      */
                            /*      point anymore).                      */
                            /* = 1: tjump is the next discontinuous      */
                            /*      point.                               */               
   doublereal       tjump;  /* Time instant of next discontinuous point  */
                            /* if ijump=1.                               */
} AtrajEval;


typedef struct Atrajectory {
   char      *title;        /* description text of trajectory                  */
   int        nData;        /* number of data matrices (>= 1)                  */
   Amatrix    name;         /* names of trajectories; char name(nName)         */
                            /* The names should be unique identifiers          */
   Amatrix    description;  /* description text for names;                     */
                            /* char description(nName); may have zero rows,    */
                            /* if no description texts are provided            */
   Amatrix    info;         /* int info(Name,4); column dense storage format.  */
                            /* Information in which data_i matrix the data is  */
                            /* stored and how it has to be interpreted.        */
                            /* Details see description at top of file          */
   Amatrix   *data;         /* data[nData] numeric (float/double) matrices;    */
   AtrajEval *eval;         /* information build-up to allow fast              */
                            /* evaluation of the signals; this structure       */
                            /* contains redundant information and is           */
                            /* mainpulated by the atrajEvalXXX functions       */
   int        npoints;      /* number of points used for spline interpolation  */
} Atrajectory;

typedef enum {
   realReq,        /* data required in real precision       */
   doubleReq,      /* data required in doublereal precision */
   realRowReq,     /* data required in real precision, and row variant */
   doubleRowReq    /* data required in doublereal precision, and row variant */
} AmatPrec;

typedef struct AtrajectoryRemember {
	fpos_t headerStart;
	fpos_t dataEnd;
	AmatGetFile getFile;
	Atrajectory *traj;
} AtrajectoryRemember;

/* ----------------- Reading trajectory objects from file ----------------- */

extern Atrajectory* atrajRead (const char *fileName, AmatPrec prec);
   /* Read trajectory from file. It is checked, whether the read object
      is a valid Atrajectory object.
      -> fileName: Name of file
      -> prec    : Desired precision (realReq or doubleReq)
      <- RETURN  : Trajectory read from file. If NULL is returned, an
                   error occured and the error message is stored
                   as (static) string in global variable "amatError".
   */



extern Atrajectory* atrajReadRemember(const char *fileName, AmatPrec prec, AtrajectoryRemember*remember);
   /* Extended variant. if remember is non-NULL one must close this with atrajCloseRemember*/

void atrajCloseRemember(AtrajectoryRemember*remember);
/* Must be called if atrajReadRemember have been called */
/* Note that you should first call atrajMoreRemember */

int atrajMoreRemember(AtrajectoryRemember*remember);
/* for reading more data from the file. Returns true if something was read */

/* ----------------- Writing trajectory objects to file ------------------- */

extern int atrajWrite (const char *fileName, Atrajectory *traj, AmatFileType ftype);
   /* Write trajectory to file. It is NOT checked, whether Atrajectory
      is a valid Atrajectory object.
      -> fileName    : Name of file.
      -> Atrajectory : Trajectory.
      -> AmatFileType: File type (amatASCII, amatBinary)
      <- RETURN      : = 0 : no error occurs.
                       else: an error occured; the error message is stored
                             as (static) string in global variable "amatError".
   */



extern int atrajWinit (const char *fileName, Atrajectory *traj, integer rowMatrixIndex,
                       AmatFileType ftype, AmatPutFile *file);
   /* Initialize row-wise writing of trajectory to file.
      It is NOT checked, whether Atrajectory is a valid Atrajectory object.
      -> fileName      : Name of file.
      -> Atrajectory   : Trajectory (numeric data is ignored).
      -> rowMatrixIndex: traj.data[0..rowMatrixIndex-1] is already stored on file
                         by this call. Matrix traj.data[rowMatrixIndex] is not
                         provided and is stored by atrajReal, atrajDouble.
                         If rowMatrixIndex=-1, the complete traj-object is stored
                         and the file is closed. That is no call to atrajWclose
                         should be made.
      -> AmatFileType  : File type (amatASCII, amatBinary)
      <- file          : File identificator.
      <- RETURN        : = 0 : no error occurs.
                         else: an error occured; the error message is stored
                               as (static) string in global variable "amatError".
   */



extern int atrajWclose (AmatPutFile *file, Atrajectory *traj, integer rowMatrixIndex);
   /* Close row-wise writing of trajectory
      -> file          : File identificator.
      -> traj          : Remaining matrices to be stored on file.
      -> rowMatrixIndex: Matrices traj.data[rowMatrixIndex+1,...] are stored on 
                         file before closing the file.
      <- RETURN: = 0   : no error occurs.
                 else  : an error occured; the error message is stored
                         as (static) string in global variable "amatError".
   */

extern int atrajWreal   (AmatPutFile *file, real       row[]);
extern int atrajWdouble (AmatPutFile *file, doublereal row[]);
   /* Write row of trajectory to file
      -> file  : File identificator.
      -> row   : Row to be written to file. The dimension of the vector was
                 defined by "traj.data[rowMatrixIndex].nrow" of atrajWinit.
      <- RETURN: = 0 : no error occurs.
                 else: an error occured; the error message is stored
                       as (static) string in global variable "amatError".
   */



/* ------------ Utility functions to plot trajectory objects -------------- */

extern void atrajSetNpoints(Atrajectory* traj, int npoints);
   /* Set number of points "npoints" used for spline interpolation.
      If not called, a reasonable default for npoints is used.

      <> traj   : Trajectory.
      -> npoints: Number of points used for spline interpolation.
   */


extern int atrajGetNsig(Atrajectory* traj);
   /* Get total number of signals 
      -> traj  : Trajectory.
      <- return: Total number of signals (>= 0).
   */


extern const char* atrajGetName(Atrajectory* traj, int i);
   /* Inquire name of signal i. A pointer
      to the name is returned (the name is NOT copied).

      -> traj  : Trajectory.
      -> i     : Signal index (0 <= i < nsig (from atrajGetNsig)).
                 i=0 characterizes the abscissa value (Time).
      <- return: Pointer to name of signal i. If NULL, i is out of range.
   */

extern const char* atrajGetDescription(Atrajectory* traj, int i);
   /* Inquire description of signal i. A pointer
      to the description is returned (the description is NOT copied).

      -> traj  : Trajectory.
      -> i     : Signal index (0 <= i < nsig (from atrajGetNsig)).
                 i=0 characterizes the abscissa value (Time).
      <- return: Pointer to name of signal i. 
	  If NULL, i is out of range, or no descriptions are available.
   */


extern int atrajGetYdataR (Atrajectory* traj, const char* yName,
                           int* n, real** x, real** y);

extern int atrajGetYdataD (Atrajectory* traj, const char* yName,
                           int* n, doublereal** x, doublereal** y);

extern int atrajGetXYdataR(Atrajectory* traj, const char* xName, const char* yName,
                           int* n, real** x, real** y);

extern int atrajGetXYdataD(Atrajectory* traj, const char* xName, const char* yName,
                           int* n, doublereal** x, doublereal** y);
   /* Get trajectory data as a polygon. 

      <> traj   : Trajectory.
      -> xName  : Abscissa signal name.
                  (for atrajGetYData this is the first signal in the trajectory,
                  i.e. usually time; the name of the abscissa can be inquired
                  via atrajGetTimeName).
      -> yName  : Ordinate signal name.
      <- n      : Number of signal points.
      <- x      : Vector of abscissa values, x[n].
      <- y      : Vector of ordinate values, y[n].
      <- return : = 0: x,y are pointers to internal data of traj.
                  = 1: x,y is stored in newly allocated memory (malloc)
                       The calling routine is responsible for this memory.
                  = 2: An error occured and an error message is stored as
                       static string in global variable amatError.
   */

extern int atrajGetXYdataDiOnline(Atrajectory* traj, const char* xName, int ix, const char* yName, int iy,
                    int* n, doublereal** x, doublereal** y,double onlineWindow);
extern int atrajGetXYdataDi(Atrajectory* traj, const char* xName, int ix, const char* yName, int iy,
							int* n, doublereal**x, doublereal** y);
/* See above for description
    ix and iy are precomputed index of the variables xName and yName
	*/

extern int atrajGetRowDim(Atrajectory* traj);
   /* Inquire number of rows of matrix traj->data[1] matrix if 2 matrices 
      or traj->data[0] if 1 matrix

      -> traj  : Trajectory
      <- return: >= 0: Number of rows (time points) of traj->data[1 or 0] matrix.
                  =-1: Error. The error message is stored as static string
                       in global variable amatError.
   */


extern double atrajGetTimeMin(Atrajectory* traj);
extern double atrajGetTimeMax(Atrajectory* traj);
/*   Return min and max time-values for the trajectory.
*/

extern int atrajGetRowR(Atrajectory* traj, int irow, real       row[]);
extern int atrajGetRowD(Atrajectory* traj, int irow, doublereal row[]);
   /* Get row "irow" of data matrices. 
      The values of all signals are stored in "row" in the same order
      as the signals are defined in traj.name. In "row" the values
      of row 1 of traj.data[0] matrix and of row "irow" of traj.data[1] 
      matrix are stored (or only traj.data[0], if only one matrix).
 
      -> traj  : Trajectory.
      -> irow  : Row to be inquired
                 (0 <= irow < nsig; nsig from atrajGetNsig).
      <- row   : Data of row "irow"; row[nsig] (nsig from atrajGetNsig).
      <- return: = 0: No error.
                 = 1: Error. The error message is stored as static string
                      in global variable amatError.
   */

extern int atrajGetRowDsub(Atrajectory* traj, int irow, doublereal *row, int ifrom, int ito);
extern int atrajGetRowRsub(Atrajectory* traj, int irow, real *row, int ifrom, int ito);
    /* Get part of row "irow" of data matrices */
    /* Similar as the above, but for a limited part of the number of signals */
	/* Get Row data from [ifrom,ito) I.e. row[0]=data[ifrom], ... row[..]=data[ito-1] */



/* ------------ Generating/destroying trajectory objects ------------------ */

extern Atrajectory *atrajNew(integer nData, AmatPrec prec);
    /* Generate a new Atrajectory object with nData data objects.
       -> nData : Number of numeric data-objects contained in traj
                  (nData >= 0 required).
       -> prec  : Precision of numeric data matrices (= realReq or doubleReq).
       <- RETURN: > 0: Pointer to new trajectory object.
                  = 0: an error occured; the error message is stored
                       as (static) string in global variable "amatError".
    */


extern int atrajInit(Atrajectory *traj, integer nData, AmatPrec prec);
    /* Initialize an Atrajectory object with nData data objects.
       <> traj  : On entry non-initialized, empty trajectory object.
                  On return, an initialized trajectory object with nData
                  data objects.
       -> nData : Number of numeric data matrices (>= 0 required).
       -> prec  : Precision of numeric data matrices (= realReq or doubleReq).
       <- RETURN: = 0: No error occured.
                  = 1: An error occured.
    */


extern int atrajResize(Atrajectory *traj, integer nDataNew, AmatPrec prec);
    /* Resize an Atrajectory object.
       <> traj    : On entry actual trajectory object with traj->nData=0.
                    On return, the trajectory object has nDataNew
                    numeric data objects.
       -> nDataNew: Number of numeric data matrices (>= 0 required).
       -> prec    : Precision of new data matrices (= realReq or doubleReq).
       <- RETURN  : = 0: No error occured.
                    = 1: An error occured.
    */


extern void atrajDel (Atrajectory *traj);
   /* Delete internal storage of an Atrajectory object (but not traj itself) */


extern void atrajDelAll (Atrajectory *traj);
   /* Delete complete storage in an Atrajectory object (traj=NULL afterwards)*/




/* ------------ Fast interpolation of trajectory objects ------------------ */

/* The following functions "atrajEvalXXX" are designed to evaluate a 
   trajectory during simulation, i.e., the actual values have to be evaluated
   at many given time instants which are not known in advance, but which are
   essentially given in quasi monotonically increasing order (sometimes
   going back in time, but never before the previous discontinuous point).

   Trajectories may be discontinuous at certain points in time. 
   In order to be able to generate an event, it is necessary to inquire
   these discontinuous points in advance. It is assumed, that in an
   interval between two discontinuous time instants, a time instant
   outside of this interval is never inquired. A function is provided
   to move from one such interval to the next one.

   The most time consuming part is to search for the actual time instant.
   Therefore internally the position of the last inquirey is stored
   and the search for the next time interval starts from this position.
*/


extern int atrajEvalInit(Atrajectory* traj, const char*const* sigName, int nsig, 
                         doublereal tStart);
   /* Initialize evaluation of trajectory data. 
      Note, that all trajectory data matrices must have the same precision
      (either real or double precision).

      <> traj   : Trajectory object to be evaluated at given time instants. 
      -> sigName: Vector of names (= Vector of string pointers) which
                  characterize the signals to be evaluated (sigName[nsig]).
                  if sigName = NULL, all signals in traj are evaluated.
      -> nsig   : Number of names in "sigName". If sigName=NULL, nsig is ignored
                  and internally the dimension traj->name.nrow is used.
      -> tStart : First time instant where the trajectory will be 
                  interpolated.
      <- return : = 0: Initialization correct.
                  = 1: At least one name in sigName is not contained in traj.
                       All the missing names are stored in appropriate form
                       in (static) string amatError. This allows printing of
                       a warning message of the form:
                         if ( ... == 1)
                            fprintf(stderr, "Warning: The following model input signals are "
                                            "not defined and are set to zero:\n%s",amatError);
                  = 2: Initialization failed. An error message is stored in amatError.
   */


extern void atrajEvalClear(Atrajectory* traj);
   /* Clear evaluation of fast evaluation data structure in the trajectory.

      <> traj: Trajectory.
   */


extern void atrajEvalNextInterval(Atrajectory* traj);
   /* Move to next evaluation interval, i.e., after the next
      discontinuous point in the current interval. Afterwards it is only
      possible to evaluate the trajectory at bigger time instants.

      <> traj: Trajectory.
   */


extern doublereal atrajEvalNextJump(Atrajectory* traj, int *info);
   /* Inquire next discontinuous time instant
   
      <> traj  : Trajectory.
      <- info  : = 0: There is no discontinuous time instant any more.
                 = 1: The next discontinuous time instant in the current
                      interval.
      <- RETURN: If info=0: 0.0.
                 If info=1: Next discontinuous time instant.
   */
   
extern int atrajEvalRowR(Atrajectory* traj, doublereal time, doublereal sig[]);
extern int atrajEvalRowD(Atrajectory* traj, doublereal time, doublereal sig[]);
extern int atrajEvalR (Atrajectory* traj, real time, real sig[]);
extern int atrajEvalD (Atrajectory* traj, doublereal time, doublereal sig[]);
   /* Interpolate the trajectory signals at time instant "time"
      (real and double precision version).
      If trajectory has "real"      matrices, atrajEvalR must be used.
      If trajectory has "double"    matrices, atrajEvalD must be used.
      If trajectory has "doublerow" matrices, atrajEvalRowD must be used.


      <> traj  : Trajectory.
      -> time  : Actual time instant.
      <- sig   : Interpolated trajectory signals at "time".
                 (sig[nsig], where nsig is defined by atrajEvalInit).
                 In case of error, sig[i]=0.
      <- return: = 0: No error.
                 = 1: An error occured. The error message is stored as 
                      static string in global variable amatError.
                      The signal (sig) is returned as 0.0.
   */

#if defined (GCC) && defined(GODESS)
}
#endif

#endif
