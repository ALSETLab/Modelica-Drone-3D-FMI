/*
   Functions to define and interpolate in tables by a Dymola model.

   Author : Martin Otter, DLR.
   Release: 1997-09-07: implemented and tested
            1997-11-26:
            1998-06-08: includes stdlib.h instead of malloc.h
            1998-10-05: modified for realtime
            2000-11-18: time function interpolation:
                        - startTime introduced
                        - optionally hold last/first table point outside
                          of time range.
                        - optionally periodic interpolation
            2001-03-31: bug fixed for time interpolation with respect to time,
                        when table is read from file and start time of integration
                        is not within the first interval of the table.
*/

/*
 * Copyright (C) 1997-2001 DLR and Dynasim AB.
 * All rights reserved.
 *
 */


#include <string.h>
#include <math.h>

#ifndef NO_FILE
#   include <stdio.h>
#   include <ctype.h>
#   include <stdlib.h>
#   include "amat.h"
#endif

#include "dymutil.h"
#include "dymtable.h"
/* DLL-status: This file is has static data which is sometimes included with
the model.  */

/* Internal memory of the table class ------------------------------------- */

#define MAX_TABLE_DIMENSIONS 3
#define MAX_TABLE 800

typedef struct {
   const char    *tableName;               /* name of table                 */
   const char    *fileName;                /* name of file                  */
                                           /* (names used for print output) */
   double  *table;                         /* table values                  */
   double   startTime;                     /* only for nipo=1:              */
                                           /* start time of interpolation   */
   double   t_offset;                      /* only for nipo=1, expoType=2:  */
                                           /* time - t_offset is ipo-time   */
   int      colWise;                       /* = 0: row-wise storage         */
                                           /* = 1: column-wise storage      */
   int      nipo;                          /* = 0: Time-interpolation       */
                                           /* = 1: 1D-interpolation         */
                                           /* = 2: 2D-interpolation         */
                                           /* = 3: 3D-interpolation         */
   int      expoType;                      /* extrapolation for nipo=0:     */
                                           /* = 0: last/first point         */
                                           /* = 1: last/first 2 points ipo. */
                                           /* = 2: repeat table periodicaly */
   int      ipoType;                       /* only for nipo=0,nipo=1,nipo=2 */
                                           /* = 0 linear */
                                           /* = 1 Spline */
   int      ipoPoint;                      /* only for nipo=0               */
                                           /* = 0: within table range       */
                                           /* = 1: time < startTime         */
                                           /* = 2: time < tmin              */
                                           /* = 3: time > tmax              */
   int      dim  [MAX_TABLE_DIMENSIONS];   /* dimensions of table           */
   int      last [MAX_TABLE_DIMENSIONS];   /* last used lower grid index    */

} DymTable;

static DymTable dymTable[MAX_TABLE];       /* All table definitions           */
static int      lastTableID = -1;          /* table is filled upto this index */


typedef struct DymMatrixListStruct {
   struct DymMatrixListStruct *next;      /* next matrix on same file */
   Amatrix                     matrix;    /* matrix of file           */
} DymMatrixList;

typedef struct DymFileListStruct {
   char                     *name;         /* name of file                    */
   struct DymFileListStruct *next;         /* pointer to next list element    */
   DymMatrixList            *firstMatrix;  /* pointer to first matrix on file */
} DymFileList;

static DymFileList *fileList = NULL;      /* pointer to all the tables stored */
                                          /* on all files                     */
#ifndef NO_FILE
   static DymFileList* dymTableLocateFile  (const char *fileName, int *ierr);
   static Amatrix*     dymTableLocateMatrix(const DymFileList *file, const char *uName,
                                            AmatType matrixType);
   static int dymTableTranspose( Amatrix *matrix, char *fileName );
#endif


/* definitions internal to file ------------------------------------------- */
   typedef enum {
     TABLE_ERROR        ,   /* error                              */
     TABLE_FROM_FIELD   ,   /* table is defined by explicit field */
     TABLE_FROM_FUNCTION,   /* table is defined in a function     */
     TABLE_FROM_FILE        /* table is defined on file           */
   } TableType;

   static int       dymTableCheckName(const char *name);
   static int       dymTableSearch   (double const *table, int nt1, int nt2, int colWise, int last, double u);
   static TableType dymTableType     (const char *tableName, const char *fileName);


#define round(x) (x >= 0.0 ? (int) (x+0.5) : (int) (x-0.5));



/* externally accessible functions ---------------------------------------- */

DYMOLA_STATIC void dymTableClearMini(void) {
 	lastTableID = -1;
}

DYMOLA_STATIC void dymTableClear(void) {

   /* Clear the complete table datastructure and remove all
      allocated memory
   */
#ifndef NO_FILE
      DymFileList   *nextFile  , *lastFile;
      DymMatrixList *nextMatrix, *lastMatrix;

      nextFile = fileList;
      while ( nextFile ) {
         nextMatrix = nextFile->firstMatrix;
         while ( nextMatrix ) {
			 amatDel(&(nextMatrix->matrix));
            lastMatrix = nextMatrix;
            nextMatrix = nextMatrix->next;
            free( lastMatrix );
         }
         lastFile = nextFile;
         nextFile = nextFile->next;
         free( lastFile );
      }
#endif
      lastTableID = -1;
      fileList    = NULL;
}



/* Access table element (row- or column-wise storage).

   It is assumed that the variables "nt1,nt2" (table dimensions)
   and "colWise" are defined. The access indices are 1..nt1, 1..nt2,
   i.e., an engineering type of matrix access where the first index
   is 1 and not 0 as in C.
*/
#define tableGet(i,j) (colWise ? (table[(i-1) + (j-1)*nt1]) : (table[(j-1) + (i-1)*nt2]))



DYMOLA_STATIC double dymTableInit(double nipoIn, double ipoTypeIn, const char *tableName,
                    const char *fileName, double const *tableIn, long nt1In, long nt2In,
                    double colWiseIn) {

   /* Initialize table interpolation */
#ifndef NO_FILE
      DymFileList *file;
      Amatrix     *tableMatrix;
      int          ierr;
#endif
      TableType    tType;
      double      *table;
      double       u1, u2;
      int          nipo, nipotype, nt1, nt2, colWise;
      int          dim[MAX_TABLE_DIMENSIONS];
      int          tableID;
      int          i, ibeg;

   /* Check nipo and whether the maximum number of table entries is reached */
      nipo   = round(nipoIn);
	  nipotype = round(ipoTypeIn);
      if ( nipo < 0 || nipo > 2 ) {
         sprintf(amatError,"Argument 1 (nipo=%d) of function \"dymTableInit\"\n"
                           "has to be 0 (time-interpolation), 1 (1D-interpolation)\n"
                           "or 2 (2D-interpolation).\n",
                           nipo);
         DymosimError(amatError);
         goto ERROR_;
	  } else if (nipotype<0 || nipotype>1) {
        sprintf(amatError,"Argument 1 (nipoType=%d) of function \"dymTableInit\"\n"
                           "has to be 0 (linear), or 1 (spline)\n",
                           nipotype);
         DymosimError(amatError);
         goto ERROR_;
      }else if ( lastTableID >= MAX_TABLE-1 ) {
         sprintf(amatError,"The maximum number of tables (= %d) is reached.\n"
                           "No more table memory is available\n", (int) MAX_TABLE);
         DymosimError(amatError);
         goto ERROR_;
      }
      tableID = lastTableID + 1;

   /* Determine, in which way the table values are defined */
      tType = dymTableType(tableName, fileName);
      if ( tType == TABLE_ERROR ) goto ERROR_;

   /* Action according to table type */
      if ( tType == TABLE_FROM_FIELD ) {
         table   = (double *) tableIn;
         nt1     = (int) nt1In;
         nt2     = (int) nt2In;
         colWise = round(colWiseIn);

      } else if ( tType == TABLE_FROM_FUNCTION ) {
         if ( usertab((char *) tableName, nipo, dim, &colWise, &table) != 0 )
            goto ERROR_;
         nt1 = dim[0];
         nt2 = dim[1];

      } else {
#ifdef NO_FILE
         /* tType is already appropriately set. If the code is correct,
            it is not possible to arrive at this place
         */
            DymosimError("unexpected error in function \"dymTableInit1a\".");
            goto ERROR_;
#else
         /* Tables are stored on file; read matrices from file and
            find the desired ones
         */
            file = dymTableLocateFile(fileName, &ierr);
            if ( ierr != 0 ) goto ERROR_;
            tableMatrix = dymTableLocateMatrix(file, tableName, doubleMatrix);
            if ( tableMatrix == NULL ) goto ERROR_;
            table   = tableMatrix->data.d;
            nt1     = tableMatrix->nrow;
            nt2     = tableMatrix->ncol;
            colWise = 1;
#endif
      }

   /* Check dimensions */
      if ( nipo == 0 && (nt1 < 1  ||  nt2 < 2) ) {
         sprintf(amatError, "Table matrix \"%s(%d,%d)\" does not have appropriate\n"
                            "dimensions for time interpolation.\n",
                             tableName, nt1, nt2);
         DymosimError(amatError);
         goto ERROR_;
      } else if ( nipo == 1 && (nt1 < 1  ||  nt2 < 2) ) {
         sprintf(amatError, "Table matrix \"%s(%d,%d)\" does not have appropriate\n"
                            "dimensions for 1D interpolation.\n",
                             tableName, nt1, nt2);
         DymosimError(amatError);
         goto ERROR_;
      } else if ( nipo == 2 && (nt1 < 2  ||  nt2 < 2) ) {
         sprintf(amatError, "Table matrix \"%s(%d,%d)\" does not have appropriate\n"
                            "dimensions for 2D interpolation.\n",
                             tableName, nt1, nt2);
         DymosimError(amatError);
         goto ERROR_;
      }


   /* Check, whether first column values are monotonically (nipo=1) or
      strict monotonically (nipo=1,2) increasing
   */
      if ( nipo == 0 ) {
         for (i=1; i<nt1; i++) {
            u1 = tableGet(i  ,1);
            u2 = tableGet(i+1,1);
            if ( u1 > u2 ) {
               sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                                 "NOT monotonically increasing because\n"
                                 "   %s(%d,1) (=%23.15e) >\n"
                                 "   %s(%d,1) (=%23.15e).\n",
                                 tableName, nt1, nt2, tableName, i  , u1,
                                                      tableName, i+1, u2 );
               DymosimError(amatError);
               goto ERROR_;
            }
         }
      } else {
         ibeg = (nipo==1) ? 1 : 2;
         for (i=ibeg; i<nt1; i++) {
            u1 = tableGet(i  ,1);
            u2 = tableGet(i+1,1);
            if ( u1 >= u2 ) {
               sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                                 "NOT STRICT monotonically increasing because\n"
                                 "   %s(%d,1) (=%23.15e) >=\n"
                                 "   %s(%d,1) (=%23.15e).\n",
                                 tableName, nt1, nt2, tableName, i  , u1,
                                                      tableName, i+1, u2 );
               DymosimError(amatError);
               goto ERROR_;
            }
         }
      }


   /* Check, whether first row values are strict monotonically increasing */
      if ( nipo == 2 ) {
         for (i=2; i<nt2; i++) {
            u1 = tableGet(1,i  );
            u2 = tableGet(1,i+1);
            if ( u1 >= u2 ) {
               sprintf(amatError,"The values of the first row of table \"%s(%d,%d)\" are\n"
                                 "NOT STRICT monotonically increasing because\n"
                                 "   %s(1,%d) (=%23.15e) >=\n"
                                 "   %s(1,%d) (=%23.15e).\n",
                                 tableName, nt1, nt2, tableName, i  , u1,
                                                      tableName, i+1, u2 );
               DymosimError(amatError);
               goto ERROR_;
            }
         }
      }


   /* Store data in internal datastructure */
      for (i=0; i<MAX_TABLE_DIMENSIONS; i++) {
         dymTable[tableID].dim [i] = 0;
         if ( nipo == 2 ) {
           dymTable[tableID].last[i] = 2;
         } else {
           dymTable[tableID].last[i] = 1;
         }
      }
      dymTable[tableID].tableName = tableName;
      dymTable[tableID].fileName  = fileName;
      dymTable[tableID].table     = (double *) table;
      dymTable[tableID].colWise   = colWise;
      dymTable[tableID].nipo      = nipo;
      dymTable[tableID].dim [0]   = nt1;
      dymTable[tableID].dim [1]   = nt2;
      dymTable[tableID].expoType  = 1;
      dymTable[tableID].startTime = 0.0;
      dymTable[tableID].t_offset  = 0.0;
	  dymTable[tableID].ipoType   = nipotype;
      lastTableID = tableID;
      return tableID;

   /* Error handling */
      ERROR_: return (-2.0);    /* tableID < lastTableID required and the */
                               /* default for lastTableID is -1          */

}



/* Macro for linear interpolation */
#define linearIpo(x,x1,x2,y1,y2) ( y1 + (y2-y1) * (x - x1) / (x2 - x1 ) )

DYMOLA_STATIC double dymTableSpline(double q[4],double*table,int iu,int icol,int colWise,int nt1,int nt2) {
  int last=nt1;
  int j;
  double m1,m2,m3,m4,m5;
  double t3,t4;
  double a2,a3,a4;
  double wleft,wright,sw;
  double p0;

  j = (iu<2) ? 2 : (iu > last) ? last : iu;
  
  a3 = tableGet(j, 1) - tableGet(j-1, 1);
  m3 = (tableGet(j, icol)-tableGet(j-1,icol))/a3;
  p0 = tableGet(j-1, 1);
  q[0] = tableGet(j-1, icol);

  if (last != 2) {
      if (j != 2) {
        a2 = tableGet(j-1, 1)-tableGet(j-2, 1);
        m2 = (tableGet(j-1, icol)-tableGet(j-2, icol))/a2;
        if (j != last) {
          a4 = tableGet(j+1, 1)-tableGet(j,1);
          m4 = (tableGet(j+1, icol)-tableGet(j,icol))/a4;
        } else {
          a4 = 1;
          m4 = m3 + m3 - m2;
        }
	  } else {
        a2 = 1;
        /* To work around a potential bug in the original algorithm (no hard cases found)*/
        a4 = tableGet(j+1,1)-tableGet(j,1);
        m4 = (tableGet(j+1, icol)-tableGet(j,icol))/a4;
        m2 = m3 + m3 - m4;
      }
  } else {
      a2 = 1;
      /* To work around a bug in the original algorithm for interval=3, last=2. */
      a4 = 1;
      /* To work around a bug in the original algorithm for interval=1, last=2 */
      m2 = m3;
      m4 = m3;
  }

  if (j > 3) {
    m1 = (tableGet(j-2,icol)-tableGet(j-3,icol))/(tableGet(j-2,1)-tableGet(j-3,1));
  } else {
      m1 = m2 + m2 - m3;
  }
  if (j < last - 1) {
    m5 = (tableGet(j+2,icol)-tableGet(j+1,icol))/(tableGet(j+2,1)-tableGet(j+1,1));
  } else {
    m5 = m4 + m4 - m3;
  }
  if (iu < last + 1) {
    wleft = fabs(m4 - m3);
    wright = fabs(m2 - m1);
    sw = wleft + wright;
    if (sw == 0) {
      wleft = 0.5;
      wright = 0.5;
      sw = 1.0;
    }
    t3 = (wleft*m2 + wright*m3)/sw;
    if (iu > 1) {
        wleft = fabs(m5 - m4);
        wright = fabs(m3 - m2);
        sw = wleft + wright;
    	if (sw == 0) {
          wleft = 0.5;
          wright = 0.5;
          sw = 1.0;
        }
        t4 = (wleft*m3 + wright*m4)/sw;
	} else {
        t4 = t3;
        t3 = 0.5*(m1 + m2 - a4*(a3 - a4)*(m3 - m4)/((a3 + a4)*(a3+a4)));
        p0 = tableGet(j-1,1) - a4;
        q[0] = tableGet(j-1,icol) - m2*a4;
        a3 = a4;
        m3 = m2;
	}
  } else {
      wleft = fabs(m5 - m4);
      wright = fabs(m3 - m2);
      sw = wleft + wright;
      if (sw == 0) {
        wleft = 0.5;
        wright = 0.5;
        sw = 1.0;
      }
      t4 = (wleft*m3 + wright*m4)/sw;
      t3 = t4;
      t4 = 0.5*(m4 + m5 - a2*(a2 - a3)*(m2 - m3)/((a2 + a3)*(a2+a3)));
      p0 = tableGet(j,1);
      q[0] = tableGet(j,icol);
      m3 = m4;
      a3 = a2;
  }
  q[1] = t3;
  q[2] = (2.0*(m3 - t3) + m3 - t4)/a3;
  q[3] = (-m3 - m3 + t3 + t4)/(a3*a3);
  return p0;
}

DYMOLA_STATIC double dymTableIpo1DerDerDer(double tableID, double icolIn, double u, double ud, double udd, double uddd) {

   /* Interpolation in the table "tableID" defined via "dymTableInit" */
      int     ID, nt1, nt2, icol, nipo, colWise, iu, iuMax;
      double *table, u1, u2, y1, y2;

   /* Check tableID */
      icol = round(icolIn);
      ID   = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Check table */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;

      icol = round(icolIn);

      if ( nipo != 1 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for 1D-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      } else if ( icol < 2  ||  icol > nt2 ) {
          sprintf(amatError, "DerDerDer: Table \"%s(%d,%d)\" is used for 1D-interpolation\n"
                            "in column %d, which is out of range.\n",
                            dymTable[ID].tableName, nt1, nt2, icol);
         goto ERROR_;
      }

   /* If table has only one value, return ZERO */
      if ( nt1 <= 1 ) return ( 0 );

   /* Search interval */
      iu    = dymTable[ID].last[0];

	  if (dymTable[ID].ipoType==1) {
		  iuMax = nt1 +1;
		  while ( iu < iuMax  &&  u > tableGet(iu,1) ) iu++;
		  while ( iu > 1      &&  u < tableGet(iu-1  ,1) ) iu--;
		  
		  dymTable[ID].last[0] = iu;
		  {
			  /* Spline interpolation */
			  double q[4];
			  double p0=dymTableSpline(q,table,iu,icol,colWise,nt1,nt2);
			  double dx = u - p0;
		      return ( 6*q[3]*ud*ud*ud +  (2*q[2]+6*dx*q[3])*2*ud*udd + uddd*(q[1]+dx*(2*q[2]+3*dx*q[3])) + udd*ud*(2*q[2]+6*dx*q[3]));
                         
		  }
	  }

      iuMax = nt1 - 1;
      while ( iu < iuMax  &&  u > tableGet(iu+1,1) ) iu++;
      while ( iu > 1      &&  u < tableGet(iu  ,1) ) iu--;

   /* Store lower grid index in datastructure */
      dymTable[ID].last[0] = iu;

   /* Get interpolation data */
      u1 = tableGet(iu  ,   1);
      u2 = tableGet(iu+1,   1);
      y1 = tableGet(iu  ,icol);
      y2 = tableGet(iu+1,icol);



   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1 >= u2 ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%e) >=\n"
                           "   %s(%d,1) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu, u1, dymTable[ID].tableName, iu+1, u2 );
         goto ERROR_;
      }

   /* Interpolate and return */
      return 0;

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;

}
















DYMOLA_STATIC double dymTableIpo1DerDer(double tableID, double icolIn, double u, double ud, double udd) {

   /* Interpolation in the table "tableID" defined via "dymTableInit" */
      int     ID, nt1, nt2, icol, nipo, colWise, iu, iuMax;
      double *table, u1, u2, y1, y2;

   /* Check tableID */
      icol = round(icolIn);
      ID   = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Check table */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;

      icol = round(icolIn);

      if ( nipo != 1 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for 1D-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      } else if ( icol < 2  ||  icol > nt2 ) {
          sprintf(amatError, "DerDer: Table \"%s(%d,%d)\" is used for 1D-interpolation\n"
                            "in column %d, which is out of range.\n",
                            dymTable[ID].tableName, nt1, nt2, icol);
         goto ERROR_;
      }

   /* If table has only one value, return ZERO */
      if ( nt1 <= 1 ) return ( 0 );

   /* Search interval */
      iu    = dymTable[ID].last[0];

	  if (dymTable[ID].ipoType==1) {
		  iuMax = nt1 +1;
		  while ( iu < iuMax  &&  u > tableGet(iu,1) ) iu++;
		  while ( iu > 1      &&  u < tableGet(iu-1  ,1) ) iu--;
		  
		  dymTable[ID].last[0] = iu;
		  {
			  /* Spline interpolation */
			  double q[4];
			  double p0=dymTableSpline(q,table,iu,icol,colWise,nt1,nt2);
			  double dx = u - p0;
		      return ( udd*(q[1]+dx*(2*q[2]+3*dx*q[3])) + ud*ud*(2*q[2]+6*dx*q[3]) );
		  }
	  }

      iuMax = nt1 - 1;
      while ( iu < iuMax  &&  u > tableGet(iu+1,1) ) iu++;
      while ( iu > 1      &&  u < tableGet(iu  ,1) ) iu--;

   /* Store lower grid index in datastructure */
      dymTable[ID].last[0] = iu;

   /* Get interpolation data */
      u1 = tableGet(iu  ,   1);
      u2 = tableGet(iu+1,   1);
      y1 = tableGet(iu  ,icol);
      y2 = tableGet(iu+1,icol);



   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1 >= u2 ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%e) >=\n"
                           "   %s(%d,1) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu, u1, dymTable[ID].tableName, iu+1, u2 );
         goto ERROR_;
      }

   /* Interpolate and return */
      return 0;

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;

}

DYMOLA_STATIC double dymTableIpo1Der(double tableID, double icolIn, double u,double ud) {

   /* Interpolation in the table "tableID" defined via "dymTableInit" */
      int     ID, nt1, nt2, icol, nipo, colWise, iu, iuMax;
      double *table, u1, u2, y1, y2;

   /* Check tableID */
      icol = round(icolIn);
      ID   = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Check table */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;
      if ( nipo != 1 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for 1D-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      } else if ( icol < 2  ||  icol > nt2 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is used for 1D-interpolation\n"
                            "in column %d, which is out of range.\n",
                            dymTable[ID].tableName, nt1, nt2, icol);
         goto ERROR_;
      }

   /* If table has only one value, return ZERO */
      if ( nt1 <= 1 ) return ( 0 );

   /* Search interval */
      iu    = dymTable[ID].last[0];

	  if (dymTable[ID].ipoType==1) {
		  iuMax = nt1 +1;
		  while ( iu < iuMax  &&  u > tableGet(iu,1) ) iu++;
		  while ( iu > 1      &&  u < tableGet(iu-1  ,1) ) iu--;
		  
		  dymTable[ID].last[0] = iu;
		  {
			  /* Spline interpolation */
			  double q[4];
			  double p0=dymTableSpline(q,table,iu,icol,colWise,nt1,nt2);
			  double dx = u - p0;
		      return ud*(q[1]+dx*(2*q[2]+3*dx*q[3]));
		  }
	  }

      iuMax = nt1 - 1;
      while ( iu < iuMax  &&  u > tableGet(iu+1,1) ) iu++;
      while ( iu > 1      &&  u < tableGet(iu  ,1) ) iu--;

   /* Store lower grid index in datastructure */
      dymTable[ID].last[0] = iu;

   /* Get interpolation data */
      u1 = tableGet(iu  ,   1);
      u2 = tableGet(iu+1,   1);
      y1 = tableGet(iu  ,icol);
      y2 = tableGet(iu+1,icol);



   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1 >= u2 ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%e) >=\n"
                           "   %s(%d,1) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu, u1, dymTable[ID].tableName, iu+1, u2 );
         goto ERROR_;
      }

   /* Interpolate and return */
      return (y1-y2)/(u1-u2)*ud;

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;
}




DYMOLA_STATIC double dymTableIpo1(double tableID, double icolIn, double u) {

   /* Interpolation in the table "tableID" defined via "dymTableInit" */
      int     ID, nt1, nt2, icol, nipo, colWise, iu, iuMax;
      double *table, u1, u2, y1, y2;

   /* Check tableID */
      icol = round(icolIn);
      ID   = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Check table */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;
      if ( nipo != 1 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for 1D-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      } else if ( icol < 2  ||  icol > nt2 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is used for 1D-interpolation\n"
                            "in column %d, which is out of range.\n",
                            dymTable[ID].tableName, nt1, nt2, icol);
         goto ERROR_;
      }

   /* If table has only one value, return this value */
      if ( nt1 <= 1 ) return ( tableGet(1,icol) );

   /* Search interval */
      iu    = dymTable[ID].last[0];


	  if (dymTable[ID].ipoType==1) {
		  iuMax = nt1 +1;
		  while ( iu < iuMax  &&  u > tableGet(iu,1) ) iu++;
		  while ( iu > 1      &&  u < tableGet(iu-1  ,1) ) iu--;
		  
		  dymTable[ID].last[0] = iu;
		  {
			  /* Spline interpolation */
			  double q[4];
			  double p0=dymTableSpline(q,table,iu,icol,colWise,nt1,nt2);
			  double dx = u - p0;
			  return q[0]+dx*(q[1]+dx*(q[2]+dx*q[3]));
		  }
	  }

      iuMax = nt1 - 1;
      while ( iu < iuMax  &&  u > tableGet(iu+1,1) ) iu++;
      while ( iu > 1      &&  u < tableGet(iu  ,1) ) iu--;

   /* Store lower grid index in datastructure */
      dymTable[ID].last[0] = iu;
	  if (dymTable[ID].ipoType==1) {
		  {
			  /* Spline interpolation */
			  double q[4];
			  double p0=dymTableSpline(q,table,iu+1,icol,colWise,nt1,nt2);
			  double dx = u - p0;
			  return q[0]+dx*(q[1]+dx*(q[2]+dx*q[3]));
		  }
	  }

   /* Get interpolation data */
      u1 = tableGet(iu  ,   1);
      u2 = tableGet(iu+1,   1);
      y1 = tableGet(iu  ,icol);
      y2 = tableGet(iu+1,icol);



   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1 >= u2 ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%e) >=\n"
                           "   %s(%d,1) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu, u1, dymTable[ID].tableName, iu+1, u2 );
         goto ERROR_;
      }


   /* Interpolate and return */
      return linearIpo(u,u1,u2,y1,y2);

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;
}


#ifndef NDEBUG
#define tableGetX(i) (!(i>=1&&i<nt1)&&DymosimError("X"),tableGet(i+1,1))
#define tableGetY(i) (!(i>=1&&i<nt2)&&DymosimError("Y"),tableGet(1,i+1))
#define tableGetZ(i,j) (!(i>=1&&i<nt1)&&DymosimError("Z(x)"),!(j>=1&&j<nt2)&&DymosimError("Z(y)"),tableGet(i+1,j+1))
#else
#define tableGetX(i) tableGet(i+1,1)
#define tableGetY(i) tableGet(1,i+1)
#define tableGetZ(i,j) tableGet(i+1,j+1)
#endif

/* Subroutine */ DYMOLA_STATIC int itplbv_(integer ixin,double uk,integer iyin,double vk,
		double*table,int nt1,int nt2,int colWise,double*result,int derOrder,double ukD,double vkD)
{
    /* System generated locals */
    double r__1=0;
    double equiv_9[10]={0,0,0,0,0,0,0,0,0,0}, equiv_19[10]={0,0,0,0,0,0,0,0,0,0},
		equiv_28[9]={0,0,0,0,0,0,0,0,0}, equiv_41[1]={1};
    integer jx, jy, jx1, jy1, jxm2, jym2;
    double dx, dy, equiv_73[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, equiv_78[16]={
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
		equiv_85[1]={0}, equiv_86[1]={0}, equiv_88[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    /* Local variables */
	integer lx0,lxm1,lxm2,lxp1;
	integer ly0,lym1,lym2,lyp1;
	integer ix,iy;
#define a (equiv_73 + 1)
#define b (equiv_73 + 4)
#define c__ (equiv_73 + 7)
#define d__ (equiv_78 + 1)
#define e (equiv_78 + 13)
#define a1 (equiv_73 + 1)
#define b1 (equiv_73 + 1)
#define a2 (equiv_73 + 4)
#define a4 (equiv_73 + 7)
#define a5 (equiv_73 + 1)
#define b5 (equiv_73 + 1)
#define b2 (equiv_78 + 1)
#define b4 (equiv_78 + 13)
    double a3=0, b3=0;
#define q0 (equiv_73 + 1)
#define q1 (equiv_73 + 4)
#define q2 (equiv_73 + 7)
#define q3 (equiv_78 + 1)
#define w1 (equiv_86)
#define w2 (equiv_85)
#define x2 (equiv_73 + 2)
#define y2 (equiv_73 + 13)
#define x4 (equiv_73 + 8)
#define x5 (equiv_73 + 11)
#define y4 (equiv_78 + 2)
#define y5 (equiv_73 + 14)
#define w4 (equiv_85)
#define w3 (equiv_86)
#define w5 (equiv_86)
    double x3=0, y3=0;
#define p00 (equiv_41)
#define p01 (equiv_78 + 5)
#define p10 (equiv_73 + 5)
#define p11 (equiv_88 + 5)
#define p02 (equiv_73 + 14)
#define p03 (equiv_78 + 4)
#define p12 (equiv_78 + 7)
#define p13 (equiv_78 + 8)
#define p20 (equiv_78 + 11)
#define p21 (equiv_78 + 14)
#define p22 (equiv_88 + 1)
#define za (equiv_9)
#define zb (equiv_19)
#define z33 (equiv_41)

#define z23 (equiv_78 + 4)
#define z24 (equiv_78 + 7)
#define z32 (equiv_78 + 8)
#define z34 (equiv_78 + 11)
#define z35 (equiv_78 + 14)
#define z42 (equiv_88 + 1)
#define z43 (equiv_88 + 4)
#define p23 (equiv_88 + 4)
#define z44 (equiv_88 + 2)
#define zx (equiv_73)
#define zy (equiv_78)
#define p30 (equiv_88 + 2)
#define z45 (equiv_88 + 7)
#define p31 (equiv_88 + 7)
#define z53 (equiv_88 + 8)
#define p32 (equiv_88 + 8)
#define z54 (equiv_88 + 11)
#define p33 (equiv_88 + 11)
    double sw=0;
#define wx2 (equiv_88 + 13)
#define wy2 (equiv_85)
#define wy3 (equiv_86)
#define wx3 (equiv_88 + 14)
#define zab (equiv_28)
#define z3a1 (equiv_9)
#define z3a2 (equiv_9 + 1)
#define z3a3 (equiv_9 + 2)
#define z3a4 (equiv_9 + 3)
#define z3a5 (equiv_9 + 4)
#define z4a1 (equiv_9 + 5)
#define z4a2 (equiv_9 + 6)
#define z4a3 (equiv_9 + 7)
#define z4a4 (equiv_9 + 8)
#define z4a5 (equiv_9 + 9)
#define z3b1 (equiv_19)
#define z3b2 (equiv_19 + 2)
#define z3b3 (equiv_19 + 4)
#define z3b4 (equiv_19 + 6)
#define z3b5 (equiv_19 + 8)
#define z4b1 (equiv_19 + 1)
#define z4b2 (equiv_19 + 3)
#define z4b3 (equiv_19 + 5)
#define z4b4 (equiv_19 + 7)
#define z4b5 (equiv_19 + 9)
#define zx33 (equiv_73 + 5)
#define zx43 (equiv_73 + 6)
#define zx34 (equiv_73 + 9)
#define zx44 (equiv_73 + 10)
#define zy33 (equiv_78 + 5)
#define zy43 (equiv_78 + 6)
#define zy34 (equiv_78 + 9)
#define zy44 (equiv_78 + 10)
#define zxy (equiv_88)
#define a3sq (equiv_73 + 2)
#define b3sq (equiv_78 + 2)
#define za2b2 (equiv_28)
#define za3b2 (equiv_28 + 1)
#define za4b2 (equiv_28 + 2)
#define za2b3 (equiv_28 + 3)
#define za3b3 (equiv_28 + 4)
#define za4b3 (equiv_28 + 5)
#define za2b4 (equiv_28 + 6)
#define za3b4 (equiv_28 + 7)
#define za4b4 (equiv_28 + 8)
    double zx3b3=0;
    integer jxml, jyml;
    double zx4b3=0, zy3a3=0, zy4a3=0;
#define zxy33 (equiv_88 + 5)
#define zxy43 (equiv_88 + 6)
#define zxy34 (equiv_88 + 9)
#define zxy44 (equiv_88 + 10)

/* BIVARIATE INTERPOLATION */
/* THIS SUBROUTINE INTERPOLATES, FROM VALUES OF THE FUNCTION */
/* GIVEN AT INPUT GRID POINTS IN AN X-Y PLANE AND FOR A GIVEN */
/* SET OF POINTS IN THE PLANE, THE VALUES OF A SINGLE-VALUED */
/* BIVARIATE FUNCTION Z = Z(X,Y). */
/* THE METHOD IS BASED ON A PIECE-WISE FUNCTION COMPOSED OF */
/* A SET OF BICUBIC POLYNOMIALS IN X AND Y.  EACH POLYNOMIAL */
/* IS APPLICABLE TO A RECTANGLE OF THE INPUT GRID IN THE X-Y */
/* PLANE.  EACH POLYNOMIAL IS DETERMINED LOCALLY. */
/* THE INPUT PARAMETERS ARE */
/* LX  = NUMBER OF INPUT GRID POINTS IN THE X COORDINATE */
/*       (MUST BE 2 OR GREATER) */
/* LY  = NUMBER OF INPUT GRID POINTS IN THE Y COORDINATE */
/*       (MUST BE 2 OR GREATER) */
/* X   = ARRAY OF DIMENSION LX STORING THE X COORDINATES */
/*       OF INPUT GRID POINTS (IN ASCENDING ORDER) */
/* Y   = ARRAY OF DIMENSION LY STORING THE Y COORDINATES */
/*       OF INPUT GRID POINTS (IN ASCENDING ORDER) */
/* Z   = DOUBLY-DIMENSIONED ARRAY OF DIMENSION (LX,LY) */
/*       STORING THE VALUES OF THE FUNCTION (Z VALUES) */
/*       AT INPUT GRID POINTS */
/* N   = NUMBER OF POINTS AT WHICH INTERPOLATION OF THE */
/*       Z VALUE IS DESIRED (MUST BE 1 OR GREATER) */
/* U   = ARRAY OF DIMENSION N STORING THE X COORDINATES */
/*       OF DESIRED POINTS */
/* V   = ARRAY OF DIMENSION N STORING THE Y COORDINATES */
/*       OF DESIRED POINTS */
/* THE OUTPUT PARAMETER IS */
/* W   = ARRAY OF DIMENSION N WHERE THE INTERPOLATED Z */
/*       VALUES AT DESIRED POINTS ARE TO BE DISPLAYED */
/*       SOME VARIABLES INTERNALLY USED ARE */
/* ZA  = DIVIDED DIFFERENCE OF Z WITH RESPECT TO X */
/* ZB  = DIVIDED DIFFERENCE OF Z WITH RESPECT TO Y */
/* ZAB = SECOND ORDER DIVIDED DIFFERENCE OF Z WITH */
/*       RESPECT TO X AND Y */
/* ZX  = PARTIAL DERIVATIVE OF Z WITH RESPECT TO X */
/* ZY  = PARTIAL DERIVATIVE OF Z WITH RESPECT TO Y */
/* ZXY = SECOND ORDER PARTIAL DERIVATIVE OF Z WITH */
/*       RESPECT TO X AND Y */
/* DECLARATION STATEMENTS */
/* PRELIMINARY PROCESSING */
/* SETTING OF SOME INPUT PARAMETERS TO LOCAL VARIABLES */

    /* Function Body */
    lx0 = nt1-1;
    lxm1 = lx0 - 1;
    lxm2 = lxm1 - 1;
    lxp1 = lx0 + 1;
    ly0 = nt2-1;
    lym1 = ly0 - 1;
    lym2 = lym1 - 1;
    lyp1 = ly0 + 1;
/* ERROR CHECK */
    if (lxm2 < 0) {
	goto L710;
    }
    if (lym2 < 0) {
	goto L720;
    }
/* MAIN DO-LOOP */
 
	ix = ixin-1;
	iy = iyin-1;
/* ROUTINES TO PICK UP NECESSARY X, Y, AND Z VALUES, TO */
/* COMPUTE THE ZA, ZB, AND ZAB VALUES, AND TO ESTIMATE THEM */
/* WHEN NECESSARY */
	jx = ix;
	if (jx == 1) {
	    jx = 2;
	}
	if (jx == lxp1) {
	    jx = lx0;
	}
	jy = iy;
	if (jy == 1) {
	    jy = 2;
	}
	if (jy == lyp1) {
	    jy = ly0;
	}
	jxm2 = jx - 2;
	jxml = jx - lx0;
	jym2 = jy - 2;
	jyml = jy - ly0;
/* IN THE CORE AREA, I.E., IN THE RECTANGLE THAT CONTAINS */
/* THE DESIRED POINT */
	x3 = tableGetX(jx-1);
	*x4 = tableGetX(jx);
	a3 = 1.f / (*x4 - x3);
	y3 = tableGetY(jy - 1);
	*y4 = tableGetY(jy);
	b3 = 1.f / (*y4 - y3);
	*z33 = tableGetZ(jx-1,jy-1);
	*z43 = tableGetZ(jx,jy-1);
	*z34 = tableGetZ(jx - 1,jy);
	*z44 = tableGetZ(jx,jy);
	*z3a3 = (*z43 - *z33) * a3;
	*z4a3 = (*z44 - *z34) * a3;
	*z3b3 = (*z34 - *z33) * b3;
	*z4b3 = (*z44 - *z43) * b3;
	*za3b3 = (*z4b3 - *z3b3) * a3;
/* IN THE X DIRECTION */
	if (lxm2 == 0) {
	    goto L230;
	}
	if (jxm2 == 0) {
	    goto L170;
	}
	*x2 = tableGetX(jx - 2);
	*a2 = 1.f / (x3 - *x2);
	*z23 = tableGetZ(jx - 2,jy - 1);
	*z24 = tableGetZ(jx - 2,jy);
	*z3a2 = (*z33 - *z23) * *a2;
	*z4a2 = (*z34 - *z24) * *a2;
	if (jxml == 0) {
	    goto L180;
	}
L170:
	*x5 = tableGetX(jx + 1);
	*a4 = 1.f / (*x5 - *x4);
	*z53 = tableGetZ(jx + 1,jy - 1);
	*z54 = tableGetZ(jx + 1,jy);
	*z3a4 = (*z53 - *z43) * *a4;
	*z4a4 = (*z54 - *z44) * *a4;
	if (jxm2 != 0) {
	    goto L190;
	}
	*z3a2 = *z3a3 + *z3a3 - *z3a4;
	*z4a2 = *z4a3 + *z4a3 - *z4a4;
	goto L190;
L180:
	*z3a4 = *z3a3 + *z3a3 - *z3a2;
	*z4a4 = *z4a3 + *z4a3 - *z4a2;
L190:
	*za2b3 = (*z4a2 - *z3a2) * b3;
	*za4b3 = (*z4a4 - *z3a4) * b3;
	if (jx <= 3) {
	    goto L200;
	}
	*a1 = 1.f / (*x2 - tableGetX(jx - 3));
	*z3a1 = (*z23 - tableGetZ(jx - 3,jy - 1)) * *a1;
	*z4a1 = (*z24 - tableGetZ(jx - 3,jy)) * *a1;
	goto L210;
L200:
	*z3a1 = *z3a2 + *z3a2 - *z3a3;
	*z4a1 = *z4a2 + *z4a2 - *z4a3;
L210:
	if (jx >= lxm1) {
	    goto L220;
	}
	*a5 = 1.f / (tableGetX(jx + 2) - *x5);
	*z3a5 = (tableGetZ(jx + 2, jy - 1) - *z53) * *a5;
	*z4a5 = (tableGetZ(jx + 2, jy) - *z54) * *a5;
	goto L240;
L220:
	*z3a5 = *z3a4 + *z3a4 - *z3a3;
	*z4a5 = *z4a4 + *z4a4 - *z4a3;
	goto L240;
L230:
	*z3a2 = *z3a3;
	*z4a2 = *z4a3;
	goto L180;
/* IN THE Y DIRECTION */
L240:
	if (lym2 == 0) {
	    goto L310;
	}
	if (jym2 == 0) {
	    goto L250;
	}
	*y2 = tableGetY(jy - 2);
	*b2 = 1.f / (y3 - *y2);
	*z32 = tableGetZ(jx - 1,jy - 2);
	*z42 = tableGetZ(jx,jy - 2);
	*z3b2 = (*z33 - *z32) * *b2;
	*z4b2 = (*z43 - *z42) * *b2;
	if (jyml == 0) {
	    goto L260;
	}
L250:
	*y5 = tableGetY(jy + 1);
	*b4 = 1.f / (*y5 - *y4);
	*z35 = tableGetZ(jx - 1, jy + 1);
	*z45 = tableGetZ(jx ,jy + 1);
	*z3b4 = (*z35 - *z34) * *b4;
	*z4b4 = (*z45 - *z44) * *b4;
	if (jym2 != 0) {
	    goto L270;
	}
	*z3b2 = *z3b3 + *z3b3 - *z3b4;
	*z4b2 = *z4b3 + *z4b3 - *z4b4;
	goto L270;
L260:
	*z3b4 = *z3b3 + *z3b3 - *z3b2;
	*z4b4 = *z4b3 + *z4b3 - *z4b2;
L270:
	*za3b2 = (*z4b2 - *z3b2) * a3;
	*za3b4 = (*z4b4 - *z3b4) * a3;
	if (jy <= 3) {
	    goto L280;
	}
	*b1 = 1.f / (*y2 - tableGetY(jy - 3));
	*z3b1 = (*z32 - tableGetZ(jx - 1,jy - 3)) * *b1;
	*z4b1 = (*z42 - tableGetZ(jx, jy - 3)) * *b1;
	goto L290;
L280:
	*z3b1 = *z3b2 + *z3b2 - *z3b3;
	*z4b1 = *z4b2 + *z4b2 - *z4b3;
L290:
	if (jy >= lym1) {
	    goto L300;
	}
	*b5 = 1.f / (tableGetY(jy + 2) - *y5);
	*z3b5 = (tableGetZ(jx - 1,jy + 2) - *z35) * *b5;
	*z4b5 = (tableGetZ(jx, jy + 2) - *z45) * *b5;
	goto L320;
L300:
	*z3b5 = *z3b4 + *z3b4 - *z3b3;
	*z4b5 = *z4b4 + *z4b4 - *z4b3;
	goto L320;
L310:
	*z3b2 = *z3b3;
	*z4b2 = *z4b3;
	goto L260;
/* IN THE DIAGONAL DIRECTIONS */
L320:
	if (lxm2 == 0) {
	    goto L400;
	}
	if (lym2 == 0) {
	    goto L410;
	}
	if (jxml == 0) {
	    goto L350;
	}
	if (jym2 == 0) {
	    goto L330;
	}
	*za4b2 = ((*z53 - tableGetZ(jx + 1,jy - 2)) * *b2 - *z4b2) * 
		*a4;
	if (jyml == 0) {
	    goto L340;
	}
L330:
	*za4b4 = ((tableGetZ(jx + 1, jy + 1) - *z54) * *b4 - *z4b4) * 
		*a4;
	if (jym2 != 0) {
	    goto L380;
	}
	*za4b2 = *za4b3 + *za4b3 - *za4b4;
	goto L380;
L340:
	*za4b4 = *za4b3 + *za4b3 - *za4b2;
	goto L380;
L350:
	if (jym2 == 0) {
	    goto L360;
	}
	*za2b2 = (*z3b2 - (*z23 - tableGetZ(jx - 2, jy - 2)) * *b2) * 
		*a2;
	if (jyml == 0) {
	    goto L370;
	}
L360:
	*za2b4 = (*z3b4 - (tableGetZ(jx - 2, jy + 1) - *z24) * *b4) * 
		*a2;
	if (jym2 != 0) {
	    goto L390;
	}
	*za2b2 = *za2b3 + *za2b3 - *za2b4;
	goto L390;
L370:
	*za2b4 = *za2b3 + *za2b3 - *za2b2;
	goto L390;
L380:
	if (jxm2 != 0) {
	    goto L350;
	}
	*za2b2 = *za3b2 + *za3b2 - *za4b2;
	*za2b4 = *za3b4 + *za3b4 - *za4b4;
	goto L420;
L390:
	if (jxml != 0) {
	    goto L420;
	}
	*za4b2 = *za3b2 + *za3b2 - *za2b2;
	*za4b4 = *za3b4 + *za3b4 - *za2b4;
	goto L420;
L400:
	*za2b2 = *za3b2;
	*za4b2 = *za3b2;
	*za2b4 = *za3b4;
	*za4b4 = *za3b4;
	goto L420;
L410:
	*za2b2 = *za2b3;
	*za2b4 = *za2b3;
	*za4b2 = *za4b3;
	*za4b4 = *za4b3;
/* NUMERICAL DIFFERENTIATION   ---   TO DETERMINE PARTIAL */
/* DERIVATIVES ZX, ZY, AND ZXY AS WEIGHTED MEANS OF DIVIDED */
/* DIFFERENCES ZA, ZB, AND ZAB, RESPECTIVELY */
L420:
	for (jy = 2; jy <= 3; ++(jy)) {
	    for (jx = 2; jx <= 3; ++(jx)) {
		*w2 = (r__1 = za[jx + 2 + (jy - 1) * 5 - 6] - za[jx + 1 + (
			jy - 1) * 5 - 6], dabs(r__1));
		*w3 = (r__1 = za[jx + (jy - 1) * 5 - 6] - za[jx - 1 + (jy 
			- 1) * 5 - 6], dabs(r__1));
		sw = *w2 + *w3;
		if (sw == 0.f) {
			*wx2 = .5f;
			*wx3 = .5f;
		} else {
			*wx2 = *w2 / sw;
			*wx3 = *w3 / sw;
		}
		zx[jx + (jy << 2) - 5] = *wx2 * za[jx + (jy - 1) * 5 - 6] 
			+ *wx3 * za[jx + 1 + (jy - 1) * 5 - 6];
		*w2 = (r__1 = zb[jx - 1 + (jy + 2 << 1) - 3] - zb[jx - 1 + 
			(jy + 1 << 1) - 3], dabs(r__1));
		*w3 = (r__1 = zb[jx - 1 + (jy << 1) - 3] - zb[jx - 1 + (
			jy - 1 << 1) - 3], dabs(r__1));
		sw = *w2 + *w3;
		if (sw == 0.f) {
			*wy2 = .5f;
			*wy3 = .5f;
		} else {
			*wy2 = *w2 / sw;
			*wy3 = *w3 / sw;
		}
		zy[jx + (jy << 2) - 5] = *wy2 * zb[jx - 1 + (jy << 1) - 3]
			 + *wy3 * zb[jx - 1 + (jy + 1 << 1) - 3];
		zxy[jx + (jy << 2) - 5] = *wy2 * (*wx2 * zab[jx - 1 + (jy 
			- 1) * 3 - 4] + *wx3 * zab[jx + (jy - 1) * 3 - 4]) 
			+ *wy3 * (*wx2 * zab[jx - 1 + jy * 3 - 4] + *wx3 * 
			zab[jx + jy * 3 - 4]);
/* L470: */
	    }
/* L480: */
	}
/* WHEN (U(K).LT.X(1)).OR.(U(K).GT.X(LX)) */
	if (ix == lxp1) {
	    goto L530;
	}
	if (ix != 1) {
	    goto L590;
	}
	*w2 = *a4 * (a3 * 3.f + *a4);
	*w1 = a3 * 2.f * (a3 - *a4) + *w2;
	for (jy = 2; jy <= 3; ++(jy)) {
	    zx[(jy << 2) - 4] = (*w1 * za[(jy - 1) * 5 - 5] + *w2 * za[(jy 
		    - 1) * 5 - 4]) / (*w1 + *w2);
	    zy[(jy << 2) - 4] = zy[(jy << 2) - 3] + zy[(jy << 2) - 3] - zy[
		    (jy << 2) - 2];
	    zxy[(jy << 2) - 4] = zxy[(jy << 2) - 3] + zxy[(jy << 2) - 3] - 
		    zxy[(jy << 2) - 2];
	    for (jx1 = 2; jx1 <= 3; ++(jx1)) {
		jx = 5 - jx1;
		zx[jx + (jy << 2) - 5] = zx[jx - 1 + (jy << 2) - 5];
		zy[jx + (jy << 2) - 5] = zy[jx - 1 + (jy << 2) - 5];
		zxy[jx + (jy << 2) - 5] = zxy[jx - 1 + (jy << 2) - 5];
/* L490: */
	    }
/* L500: */
	}
	x3 -= 1.f / *a4;
	*z33 -= *z3a2 / *a4;
	for (jy = 1; jy <= 5; ++(jy)) {
	    zb[(jy << 1) - 1] = zb[(jy << 1) - 2];
/* L510: */
	}
	for (jy = 2; jy <= 4; ++(jy)) {
	    zb[(jy << 1) - 2] -= zab[(jy - 1) * 3 - 3] / *a4;
/* L520: */
	}
	a3 = *a4;
	jx = 1;
	goto L570;
L530:
	*w4 = *a2 * (a3 * 3.f + *a2);
	*w5 = a3 * 2.f * (a3 - *a2) + *w4;
	for (jy = 2; jy <= 3; ++(jy)) {
	    zx[(jy << 2) - 1] = (*w4 * za[(jy - 1) * 5 - 2] + *w5 * za[(jy 
		    - 1) * 5 - 1]) / (*w4 + *w5);
	    zy[(jy << 2) - 1] = zy[(jy << 2) - 2] + zy[(jy << 2) - 2] - zy[
		    (jy << 2) - 3];
	    zxy[(jy << 2) - 1] = zxy[(jy << 2) - 2] + zxy[(jy << 2) - 2] - 
		    zxy[(jy << 2) - 3];
	    for (jx = 2; jx <= 3; ++(jx)) {
		zx[jx + (jy << 2) - 5] = zx[jx + 1 + (jy << 2) - 5];
		zy[jx + (jy << 2) - 5] = zy[jx + 1 + (jy << 2) - 5];
		zxy[jx + (jy << 2) - 5] = zxy[jx + 1 + (jy << 2) - 5];
/* L540: */
	    }
/* L550: */
	}
	x3 = *x4;
	*z33 = *z43;
	for (jy = 1; jy <= 5; ++(jy)) {
	    zb[(jy << 1) - 2] = zb[(jy << 1) - 1];
/* L560: */
	}
	a3 = *a2;
	jx = 3;
L570:
	za[2] = za[jx];
	for (jy = 1; jy <= 3; ++(jy)) {
	    zab[jy * 3 - 2] = zab[jx + jy * 3 - 4];
/* L580: */
	}
/* WHEN (V(K).LT.Y(1)).OR.(V(K).GT.Y(LY)) */
L590:
	if (iy == lyp1) {
	    goto L630;
	}
	if (iy != 1) {
	    goto L680;
	}
	*w2 = *b4 * (b3 * 3.f + *b4);
	*w1 = b3 * 2.f * (b3 - *b4) + *w2;
	for (jx = 2; jx <= 3; ++(jx)) {
	    if (jx == 3 && ix == lxp1) {
		goto L600;
	    }
	    if (jx == 2 && ix == 1) {
		goto L600;
	    }
	    zy[jx - 1] = (*w1 * zb[jx - 2] + *w2 * zb[jx]) / (*w1 + *w2);
	    zx[jx - 1] = zx[jx + 3] + zx[jx + 3] - zx[jx + 7];
	    zxy[jx - 1] = zxy[jx + 3] + zxy[jx + 3] - zxy[jx + 7];
L600:
	    for (jy1 = 2; jy1 <= 3; ++(jy1)) {
		jy = 5 - jy1;
		zy[jx + (jy << 2) - 5] = zy[jx + (jy - 1 << 2) - 5];
		zx[jx + (jy << 2) - 5] = zx[jx + (jy - 1 << 2) - 5];
		zxy[jx + (jy << 2) - 5] = zxy[jx + (jy - 1 << 2) - 5];
/* L610: */
	    }
/* L620: */
	}
	y3 -= 1.f / *b4;
	*z33 -= *z3b2 / *b4;
	*z3a3 -= *za3b2 / *b4;
	*z3b3 = *z3b2;
	*za3b3 = *za3b2;
	b3 = *b4;
	goto L670;
L630:
	*w4 = *b2 * (b3 * 3.f + *b2);
	*w5 = b3 * 2.f * (b3 - *b2) + *w4;
	for (jx = 2; jx <= 3; ++(jx)) {
	    if (jx == 3 && ix == lxp1) {
		goto L640;
	    }
	    if (jx == 2 && ix == 1) {
		goto L640;
	    }
	    zy[jx + 11] = (*w4 * zb[jx + 4] + *w5 * zb[jx + 6]) / (*w4 + *
		    w5);
	    zx[jx + 11] = zx[jx + 7] + zx[jx + 7] - zx[jx + 3];
	    zxy[jx + 11] = zxy[jx + 7] + zxy[jx + 7] - zxy[jx + 3];
L640:
	    for (jy = 2; jy <= 3; ++(jy)) {
		zy[jx + (jy << 2) - 5] = zy[jx + (jy + 1 << 2) - 5];
		zx[jx + (jy << 2) - 5] = zx[jx + (jy + 1 << 2) - 5];
		zxy[jx + (jy << 2) - 5] = zxy[jx + (jy + 1 << 2) - 5];
/* L650: */
	    }
/* L660: */
	}
	y3 = *y4;
	*z33 += *z3b3 / b3;
	*z3a3 += *za3b3 / b3;
	*z3b3 = *z3b4;
	*za3b3 = *za3b4;
	b3 = *b2;
L670:
	if (ix != 1 && ix != lxp1) {
	    goto L680;
	}
	jx = ix / lxp1 + 2;
	jx1 = 5 - jx;
	jy = iy / lyp1 + 2;
	jy1 = 5 - jy;
	zx[jx + (jy << 2) - 5] = zx[jx1 + (jy << 2) - 5] + zx[jx + (jy1 
		<< 2) - 5] - zx[jx1 + (jy1 << 2) - 5];
	zy[jx + (jy << 2) - 5] = zy[jx1 + (jy << 2) - 5] + zy[jx + (jy1 
		<< 2) - 5] - zy[jx1 + (jy1 << 2) - 5];
	zxy[jx + (jy << 2) - 5] = zxy[jx1 + (jy << 2) - 5] + zxy[jx + (
		jy1 << 2) - 5] - zxy[jx1 + (jy1 << 2) - 5];
/* DETERMINATION OF THE COEFFICIENTS OF THE POLYNOMIAL */
L680:
	zx3b3 = (*zx34 - *zx33) * b3;
	zx4b3 = (*zx44 - *zx43) * b3;
	zy3a3 = (*zy43 - *zy33) * a3;
	zy4a3 = (*zy44 - *zy34) * a3;
	*a = *za3b3 - zx3b3 - zy3a3 + *zxy33;
	*b = zx4b3 - zx3b3 - *zxy43 + *zxy33;
	*c__ = zy4a3 - zy3a3 - *zxy34 + *zxy33;
	*d__ = *zxy44 - *zxy43 - *zxy34 + *zxy33;
	*e = *a + *a - *b - *c__;
	*a3sq = a3 * a3;
	*b3sq = b3 * b3;
	*p02 = ((*z3b3 - *zy33) * 2.f + *z3b3 - *zy34) * b3;
	*p03 = (*z3b3 * -2.f + *zy34 + *zy33) * *b3sq;
	*p12 = ((zx3b3 - *zxy33) * 2.f + zx3b3 - *zxy34) * b3;
	*p13 = (zx3b3 * -2.f + *zxy34 + *zxy33) * *b3sq;
	*p20 = ((*z3a3 - *zx33) * 2.f + *z3a3 - *zx43) * a3;
	*p21 = ((zy3a3 - *zxy33) * 2.f + zy3a3 - *zxy43) * a3;
	*p22 = ((*a + *e) * 3.f + *d__) * a3 * b3;
	*p23 = (*e * -3.f - *b - *d__) * a3 * *b3sq;
	*p30 = (*z3a3 * -2.f + *zx43 + *zx33) * *a3sq;
	*p31 = (zy3a3 * -2.f + *zxy43 + *zxy33) * *a3sq;
	*p32 = (*e * -3.f - *c__ - *d__) * b3 * *a3sq;
	*p33 = (*d__ + *e + *e) * *a3sq * *b3sq;
/* COMPUTATION OF THE POLYNOMIAL */
L690:
	dy = vk - y3;
	*q0 = *p00 + dy * (*p01 + dy * (*p02 + dy * *p03));
	*q1 = *p10 + dy * (*p11 + dy * (*p12 + dy * *p13));
	*q2 = *p20 + dy * (*p21 + dy * (*p22 + dy * *p23));
	*q3 = *p30 + dy * (*p31 + dy * (*p32 + dy * *p33));
	dx = uk - x3;
	if (derOrder==1) {
		*result = ukD*( *q1 + dx * (2* *q2+3*dx* *q3));
		*q0 = vkD*(*p01+dy*(2* *p02 + 3*dy* *p03));
		*q1 = vkD*(*p11+dy*(2* *p12 + 3*dy* *p13));
		*q2 = vkD*(*p21+dy*(2* *p22 + 3*dy* *p23));
		*q3 = vkD*(*p31+dy*(2* *p32 + 3*dy* *p33));
		*result += *q0 + dx * (*q1 + dx * (*q2 + dx * *q3));
		return 0;
	}
	*result = *q0 + dx * (*q1 + dx * (*q2 + dx * *q3));
/* L700: */
/* NORMAL EXIT */
    return 0;
/* ERROR EXIT */
L710:
	DymosimError("Number of x values <= 1");
	return 1;
L720:
	DymosimError("Number of y values <= 1");
    return 1;
/* FORMAT STATEMENTS */
} /* itplbv_ */

#undef zxy44
#undef zxy34
#undef zxy43
#undef zxy33
#undef za4b4
#undef za3b4
#undef za2b4
#undef za4b3
#undef za3b3
#undef za2b3
#undef za4b2
#undef za3b2
#undef za2b2
#undef lyp1
#undef lym2
#undef lxp1
#undef lym1
#undef lxm2
#undef lxm1
#undef b3sq
#undef a3sq
#undef zxy
#undef zy44
#undef zy34
#undef zy43
#undef zy33
#undef zx44
#undef zx34
#undef zx43
#undef zx33
#undef z4b5
#undef z4b4
#undef z4b3
#undef z4b2
#undef z4b1
#undef z3b5
#undef z3b4
#undef z3b3
#undef z3b2
#undef z3b1
#undef z4a5
#undef z4a4
#undef z4a3
#undef z4a2
#undef z4a1
#undef z3a5
#undef z3a4
#undef z3a3
#undef z3a2
#undef z3a1
#undef zab
#undef wx3
#undef wy3
#undef wy2
#undef wx2
#undef p33
#undef z54
#undef p32
#undef z53
#undef p31
#undef z45
#undef p30
#undef zy
#undef zx
#undef z44
#undef p23
#undef z43
#undef z42
#undef z35
#undef z34
#undef z32
#undef z24
#undef z23
#undef vk
#undef jy
#undef jx
#undef iy
#undef ix
#undef z33
#undef zb
#undef za
#undef p22
#undef p21
#undef p20
#undef p13
#undef p12
#undef p03
#undef p02
#undef p11
#undef p10
#undef p01
#undef p00
#undef w5
#undef w3
#undef w4
#undef y5
#undef y4
#undef x5
#undef x4
#undef y2
#undef x2
#undef w2
#undef w1
#undef q3
#undef q2
#undef q1
#undef q0
#undef b4
#undef b2
#undef b5
#undef a5
#undef a4
#undef a2
#undef b1
#undef a1
#undef e
#undef d__
#undef c__
#undef b
#undef a

DYMOLA_STATIC double dymTableIpo2DerDer(double tableID, double u1, double u2,double ud1,double ud2,double udd1,double udd2) {

   /* Interpolation in the table "tableID" defined via "dymTableInit" */
      int     ID, nt1, nt2, nipo, colWise, iu1, iu2, iuMax;
      double *table, u1a, u1b, u2a, u2b;
      double  y1a, y1b, y1c, y1d, y2a, y2b, yd2a, yd2b, ydd2a, ydd2b, ydd;

   /* Check tableID */
      ID = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Check table */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;
      if ( nipo != 2 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for 2D-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      }

   /* If table has only one value, return ZERO */
      if ( nt1 <= 2 && nt2 <= 2 ) return ( 0 );

	  if (dymTable[ID].ipoType==1) {
		  iu1 = dymTable[ID].last[0];
		  iuMax = nt1 +1;
		  while ( iu1 < iuMax  &&  u1 > tableGet(iu1,1) ) iu1++;
		  while ( iu1 > 2      &&  u1 < tableGet(iu1-1  ,1) ) iu1--;
		  dymTable[ID].last[0] = iu1;
			  
		  iu2 = dymTable[ID].last[1];
		  iuMax = nt2 +1;
		  while ( iu2 < iuMax  &&  u2 > tableGet(1, iu2) ) iu2++;
		  while ( iu2 > 2      &&  u2 < tableGet(1, iu2-1) ) iu2--;
		  dymTable[ID].last[1] = iu2;
	  

		  {
			  double res=0;
			  itplbv_(iu1,u1,iu2,u2,table,nt1,nt2,colWise,&res,1,ud1,ud2);
			  return res;
		  }
	  }

   /* Search u1 interval */
      iu1   = dymTable[ID].last[0];
      iuMax = nt1 - 1;
      while ( iu1 < iuMax  &&  u1 > tableGet(iu1+1,1) ) iu1++;
      while ( iu1 > 2      &&  u1 < tableGet(iu1  ,1) ) iu1--;

   /* Search u2 interval */
      iu2   = dymTable[ID].last[1];
      iuMax = nt2 - 1;
      while ( iu2 < iuMax  &&  u2 > tableGet(1,iu2+1) ) iu2++;
      while ( iu2 > 2      &&  u2 < tableGet(1,iu2  ) ) iu2--;

   /* Get interpolation data */
      u1a = tableGet(iu1  ,   1  );
      u1b = tableGet(iu1+1,   1  );
      u2a = tableGet(  1  , iu2  );
      u2b = tableGet(  1  , iu2+1);

      y1a = tableGet(iu1  , iu2  );
      y1b = tableGet(iu1+1, iu2  );
      y1c = tableGet(iu1  , iu2+1);
      y1d = tableGet(iu1+1, iu2+1);

   /* Store lower grid indices in datastructure */
      dymTable[ID].last[0] = iu1;
      dymTable[ID].last[1] = iu2;

   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1a >= u1b ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%e) >=\n"
                           "   %s(%d,1) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu1, u1a, dymTable[ID].tableName, iu1+1, u1b );
         goto ERROR_;
      } else if ( u2a >= u2b ) {
         sprintf(amatError,"The values of the first row of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(1,%d) (=%e) >=\n"
                           "   %s(1,%d) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu2, u2a, dymTable[ID].tableName, iu2+1, u2b );
         goto ERROR_;
      }

   /* Interpolate */
      y2a = linearIpo(u1, u1a,u1b,y1a,y1b);
	  yd2a = ud1*(y1b-y1a)/(u1b-u1a);
	  ydd2a = udd1*(y1b-y1a)/(u1b-u1a);
      y2b = linearIpo(u1, u1a,u1b,y1c,y1d);
	  yd2b = ud1*(y1d-y1c)/(u1b-u1a);
	  ydd2b = udd2*(y1d-y1c)/(u1b-u1a);
	  ydd = udd2*(y2b-y2a)/(u2b-u2a)+2*ud2*(yd2a-yd2b)/(u2b-u2a)+linearIpo(u2, u2a ,u2b, ydd2a, ydd2b);

   /* Interpolate and return */
      return ydd;

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;
}

DYMOLA_STATIC double dymTableIpo2Der(double tableID, double u1, double u2,double ud1,double ud2) {

   /* Interpolation in the table "tableID" defined via "dymTableInit" */
      int     ID, nt1, nt2, nipo, colWise, iu1, iu2, iuMax;
      double *table, u1a, u1b, u2a, u2b;
      double  y1a, y1b, y1c, y1d, y2a, y2b, yd2a, yd2b, yd;

   /* Check tableID */
      ID = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Check table */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;
      if ( nipo != 2 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for 2D-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      }

   /* If table has only one value, return ZERO */
      if ( nt1 <= 2 && nt2 <= 2 ) return ( 0 );

	  if (dymTable[ID].ipoType==1) {
		  iu1 = dymTable[ID].last[0];
		  iuMax = nt1 +1;
		  while ( iu1 < iuMax  &&  u1 > tableGet(iu1,1) ) iu1++;
		  while ( iu1 > 2      &&  u1 < tableGet(iu1-1  ,1) ) iu1--;
		  dymTable[ID].last[0] = iu1;
			  
		  iu2 = dymTable[ID].last[1];
		  iuMax = nt2 +1;
		  while ( iu2 < iuMax  &&  u2 > tableGet(1, iu2) ) iu2++;
		  while ( iu2 > 2      &&  u2 < tableGet(1, iu2-1) ) iu2--;
		  dymTable[ID].last[1] = iu2;
	  

		  {
			  double res=0;
			  itplbv_(iu1,u1,iu2,u2,table,nt1,nt2,colWise,&res,1,ud1,ud2);
			  return res;
		  }
	  }

   /* Search u1 interval */
      iu1   = dymTable[ID].last[0];
      iuMax = nt1 - 1;
      while ( iu1 < iuMax  &&  u1 > tableGet(iu1+1,1) ) iu1++;
      while ( iu1 > 2      &&  u1 < tableGet(iu1  ,1) ) iu1--;

   /* Search u2 interval */
      iu2   = dymTable[ID].last[1];
      iuMax = nt2 - 1;
      while ( iu2 < iuMax  &&  u2 > tableGet(1,iu2+1) ) iu2++;
      while ( iu2 > 2      &&  u2 < tableGet(1,iu2  ) ) iu2--;

   /* Get interpolation data */
      u1a = tableGet(iu1  ,   1  );
      u1b = tableGet(iu1+1,   1  );
      u2a = tableGet(  1  , iu2  );
      u2b = tableGet(  1  , iu2+1);

      y1a = tableGet(iu1  , iu2  );
      y1b = tableGet(iu1+1, iu2  );
      y1c = tableGet(iu1  , iu2+1);
      y1d = tableGet(iu1+1, iu2+1);

   /* Store lower grid indices in datastructure */
      dymTable[ID].last[0] = iu1;
      dymTable[ID].last[1] = iu2;

   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1a >= u1b ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%e) >=\n"
                           "   %s(%d,1) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu1, u1a, dymTable[ID].tableName, iu1+1, u1b );
         goto ERROR_;
      } else if ( u2a >= u2b ) {
         sprintf(amatError,"The values of the first row of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(1,%d) (=%e) >=\n"
                           "   %s(1,%d) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu2, u2a, dymTable[ID].tableName, iu2+1, u2b );
         goto ERROR_;
      }

   /* Interpolate */
      y2a = linearIpo(u1, u1a,u1b,y1a,y1b);
	  yd2a = ud1*(y1b-y1a)/(u1b-u1a);
      y2b = linearIpo(u1, u1a,u1b,y1c,y1d);
	  yd2b = ud1*(y1d-y1c)/(u1b-u1a);
      yd   = (y2b-y2a)*ud2/(u2b-u2a)+linearIpo(u2, u2a,u2b,yd2a,yd2b);

   /* Interpolate and return */
      return yd;

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;
}

DYMOLA_STATIC double dymTableIpo2(double tableID, double u1, double u2) {

   /* Interpolation in the table "tableID" defined via "dymTableInit" */
      int     ID, nt1, nt2, nipo, colWise, iu1, iu2, iuMax;
      double *table, u1a, u1b, u2a, u2b;
      double  y1a, y1b, y1c, y1d, y2a, y2b, y;

   /* Check tableID */
      ID = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Check table */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;
      if ( nipo != 2 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for 2D-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      }

   /* If table has only one value, return this value */
      if ( nt1 <= 2 && nt2 <= 2 ) return ( tableGet(2,2) );

  	  if (dymTable[ID].ipoType==1) {
		  iu1 = dymTable[ID].last[0];
		  iuMax = nt1 +1;
		  while ( iu1 < iuMax  &&  u1 > tableGet(iu1,1) ) iu1++;
		  while ( iu1 > 2      &&  u1 < tableGet(iu1-1  ,1) ) iu1--;
		  dymTable[ID].last[0] = iu1;
			  
		  iu2 = dymTable[ID].last[1];
		  iuMax = nt2 +1;
		  while ( iu2 < iuMax  &&  u2 > tableGet(1, iu2) ) iu2++;
		  while ( iu2 > 2      &&  u2 < tableGet(1, iu2-1) ) iu2--;
		  dymTable[ID].last[1] = iu2;
	  

		  {
			  double res=0;
			  itplbv_(iu1,u1,iu2,u2,table,nt1,nt2,colWise,&res,0,0,0);
			  return res;
		  }
	  }


   /* Search u1 interval */
      iu1   = dymTable[ID].last[0];
      iuMax = nt1 - 1;
      while ( iu1 < iuMax  &&  u1 > tableGet(iu1+1,1) ) iu1++;
      while ( iu1 > 2      &&  u1 < tableGet(iu1  ,1) ) iu1--;

   /* Search u2 interval */
      iu2   = dymTable[ID].last[1];
      iuMax = nt2 - 1;
      while ( iu2 < iuMax  &&  u2 > tableGet(1,iu2+1) ) iu2++;
      while ( iu2 > 2      &&  u2 < tableGet(1,iu2  ) ) iu2--;

   /* Get interpolation data */
      u1a = tableGet(iu1  ,   1  );
      u1b = tableGet(iu1+1,   1  );
      u2a = tableGet(  1  , iu2  );
      u2b = tableGet(  1  , iu2+1);

      y1a = tableGet(iu1  , iu2  );
      y1b = tableGet(iu1+1, iu2  );
      y1c = tableGet(iu1  , iu2+1);
      y1d = tableGet(iu1+1, iu2+1);

   /* Store lower grid indices in datastructure */
      dymTable[ID].last[0] = iu1;
      dymTable[ID].last[1] = iu2;

   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1a >= u1b ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%e) >=\n"
                           "   %s(%d,1) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu1, u1a, dymTable[ID].tableName, iu1+1, u1b );
         goto ERROR_;
      } else if ( u2a >= u2b ) {
         sprintf(amatError,"The values of the first row of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(1,%d) (=%e) >=\n"
                           "   %s(1,%d) (=%e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu2, u2a, dymTable[ID].tableName, iu2+1, u2b );
         goto ERROR_;
      }

   /* Interpolate */
      y2a = linearIpo(u1, u1a,u1b,y1a,y1b);
      y2b = linearIpo(u1, u1a,u1b,y1c,y1d);
      y   = linearIpo(u2, u2a,u2b,y2a,y2b);

   /* Interpolate and return */
      return y;

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;
}



DYMOLA_STATIC void registerTimeEvent(const double);

DYMOLA_STATIC double dymTableTimeIni(double time, double ipoType,
                       const char *tableName, const char *fileName,
                       double const *tableIn, long nt1In, long nt2In,
                       double colWiseIn) {

   /* Initialize table for time interpolation */
      double *table;
      double  tableID, nextTime;
      int     ID, iu, iuMax, nt1, nt2;
      int     colWise = round(colWiseIn);

   /* General Initialization of table */
      tableID = dymTableInit(0.0, ipoType, tableName, fileName, tableIn, nt1In, nt2In,
                             colWiseIn);
      ID      = round(tableID);
      if ( ID < 0 ) return tableID;

   /* Get table information */
      table   = dymTable[ID].table;
      colWise = dymTable[ID].colWise;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];

   /* Find correct interval of time function */
      iu    = 1;
      iuMax = nt1 - 1;
      while ( iu < iuMax  &&  time >= tableGet(iu+1,1) ) iu++;
      while ( iu > 1      &&  time <  tableGet(iu  ,1) ) iu--;

   /* Store index of interval */
      dymTable[ID].last[0] = iu;

   /* Determine next time event */
      if ( iu < iuMax ) {
         nextTime      = tableGet(iu+1,1);
		 registerTimeEvent(nextTime);
      }
      return tableID;
}



DYMOLA_STATIC double dymTableTimeIpol(double tableID, double icolIn, double time, int event) {

   /* Time interpolation in the table "tableID" defined via "dymTableTimeInit" */
      int          ID, nt1, nt2, nipo, icol, colWise, iu, iuMax;
      double      *table;
      double       nextTime, u1, u2, y1, y2;
      const double TIME_EPS = 1.E-6;

   /* Check tableID */
      icol = round(icolIn);
      ID   = round(tableID);
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Get table data and check it */
      colWise = dymTable[ID].colWise;
      nipo    = dymTable[ID].nipo;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      table   = dymTable[ID].table;
      if ( nipo != 0 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for time-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      } else if ( icol < 2  ||  icol > nt2 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is used for time-interpolation\n"
                            "in column %d, which is out of range.\n",
                            dymTable[ID].tableName, nt1, nt2, icol);
         goto ERROR_;
      }


   /* If table has only one value, return this value */
      if ( nt1 <= 1 ) return ( tableGet(1,icol) );


   /* At an event instant, set next time event */
      iu    = dymTable[ID].last[0];
      iuMax = nt1 - 1;
      if ( event && iu < iuMax ) {
         nextTime = tableGet(iu+1,1);

         if ( time >= (nextTime - TIME_EPS*fabs(nextTime)) ) {
            /* Set new time event (remember, that two consecutive time instants
               in the table may be identical due to a discontinuous point)
            */
               iu++;
               while ( iu < iuMax  &&  time >= tableGet(iu+1,1)- TIME_EPS*fabs(tableGet(iu+1,1)) ) iu++;
               dymTable[ID].last[0] = iu;

               if ( iu < iuMax ) {
                  nextTime      = tableGet(iu+1,1);
                  registerTimeEvent(nextTime);
               }
         } else {
            /* Set current time event again */
               registerTimeEvent(nextTime);
         }
      }


   /* Get interpolation data */
      iu = dymTable[ID].last[0];
	  if (dymTable[ID].ipoType==1) {
		  {
			  /* Spline interpolation */
			  double q[4];
			  double p0=dymTableSpline(q,table,iu+1,icol,colWise,nt1,nt2);
			  double dx = time - p0;
			  return q[0]+dx*(q[1]+dx*(q[2]+dx*q[3]));
		  }
	  }
      u1 = tableGet(iu  ,   1);
      u2 = tableGet(iu+1,   1);
      y1 = tableGet(iu  ,icol);
      y2 = tableGet(iu+1,icol);

   /* Check for zero division (should not be possible, because already checked,
      whether abszissa values are strict monotonically increasing)
   */
      if ( u1 >= u2 ) {
         sprintf(amatError,"The values of the first column of table \"%s(%d,%d)\" are\n"
                           "NOT STRICT monotonically increasing because\n"
                           "   %s(%d,1) (=%23.15e) >=\n"
                           "   %s(%d,1) (=%23.15e).\n",
                           dymTable[ID].tableName, nt1, nt2, dymTable[ID].tableName,
                           iu, u1, dymTable[ID].tableName, iu+1, u2 );
         goto ERROR_;
      }

   /* Interpolate and return */
      return linearIpo(time,u1,u2,y1,y2);

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;
}


#define timeLimit(nextTime) ( nextTime - 1.E-6*fabs(nextTime) )

DYMOLA_STATIC double initialTime(void);
DYMOLA_STATIC int dymTableTimeIni2(double time, double startTime, int ipoType,
                      int expoType, const char *tableName, const char *fileName,
                      double const *tableIn, int nt1In, int nt2In, int colWiseIn) {

   /* Initialize table for time interpolation */
      double *table;
      double  tableID, nextTime, tmin, tmax, t_offset, table_time;
      int     ID, iu, colWise, nt1, nt2;
      double  T, iv;


	  time=initialTime();

   /* General Initialization of table */
      tableID = dymTableInit(0.0, ipoType, tableName, fileName, tableIn, nt1In, nt2In,
                             colWiseIn);
      ID = round(tableID);
      if ( ID < -1 ) return ID;

   /* Check expoType argument */
      if ( expoType < 0 || expoType > 2 ) {
         sprintf(amatError,"Extrapolation argument for table \"%s(%d,%d)\"\n"
                           "is %d, which is wrong (should be 0, 1 or 2).\n",
                           dymTable[ID].tableName, nt1In, nt2In, expoType);
         DymosimError(amatError);
         return (-2);
      }
      dymTable[ID].expoType  = expoType;
      dymTable[ID].startTime = startTime;
      dymTable[ID].last[0]   = 1;
      dymTable[ID].ipoPoint  = 0;
      table   = dymTable[ID].table;
      colWise = dymTable[ID].colWise;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];

   /* Determine table time */
      tmin = tableGet(1,1);
      tmax = tableGet(nt1,1);
      if ( tmax > tmin && expoType == 2 ) {
         /* periodic signal */
         T = tmax - tmin;
         iv = (time - startTime - tmin) / T;
         t_offset = startTime + floor(iv)*T;
      } else {
         t_offset = startTime;
      }
      dymTable[ID].t_offset = t_offset;
      table_time = time - t_offset;

   /* Handle startTime */
      if ( time < timeLimit(startTime) ) {
         dymTable[ID].ipoPoint = 1;
         registerTimeEvent(startTime);
         return ID;
      }

   /* Handle case, when table has only one entry */
      if ( nt1 <= 1 ) {
         dymTable[ID].last[0] = 1;
         return ID;
      }

   /* Find correct interval of time function, sucht that iu is at most nt1-1 */
      iu = 1;
	  while ( iu < nt1-1  &&  table_time >= timeLimit(tableGet(iu+1,1))-((expoType==2) ? 1e-6*(tmax-tmin):0)) iu++;


   /* Store index of interval */
      dymTable[ID].last[0] = iu;

   /* Determine next time event */
      if ( expoType == 0 ) {
         if ( table_time < timeLimit(tmin) ) {
            nextTime = t_offset + tmin;
            registerTimeEvent(nextTime);
            dymTable[ID].ipoPoint = 2;

         } else if ( table_time > timeLimit(tmax) ) {
            dymTable[ID].ipoPoint = 3;

         } else {
            nextTime = t_offset + tableGet(iu+1,1);
            registerTimeEvent(nextTime);
            dymTable[ID].ipoPoint = 0;
         }
      } else if ( expoType == 1 ) {
         if ( table_time <= timeLimit(tmax) ) {
            nextTime = t_offset + tableGet(iu+1,1);
            registerTimeEvent(nextTime);
         }
      } else {  /* expoType == 2 (periodic)*/
         nextTime = t_offset + tableGet(iu+1,1);
         registerTimeEvent(nextTime);
      }
      return ID;
}

DYMOLA_STATIC double dymTableTimeTmin(int ID) {

   /* Return minimum time value in table */
      double *table, tmin;
      int colWise, nt1, nt2;

   /* Check table ID */
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         return 0.0;
      }

   /* Get tmin */
      table   = dymTable[ID].table;
      colWise = dymTable[ID].colWise;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      tmin    = tableGet(1,1);
      return tmin;
}

DYMOLA_STATIC double dymTableTimeTmax(int ID) {

   /* Return maximum time value in table */
      double *table, tmax;
      int colWise, nt1, nt2;

   /* Check table ID */
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         return 0.0;
      }

   /* Get tmin */
      table   = dymTable[ID].table;
      colWise = dymTable[ID].colWise;
      nt1     = dymTable[ID].dim[0];
      nt2     = dymTable[ID].dim[1];
      tmax    = tableGet(nt1,1);
      return tmax;
}


DYMOLA_STATIC int isModelicaEvent(void);

DYMOLA_STATIC double dymTableTimeIpo2(int ID, int icol, double time) {

   /* Time interpolation in the table "tableID" defined via "dymTableTimeIni2" */
      int          nt1, nt2, nipo, colWise, iu, expoType, ipoPoint;
      long event = isModelicaEvent();
      double      *table;
      double       nextTime, u1, u2, y1, y2, t_offset, table_time, tmin, tmax;
      double       startTime, iv, T;

   /* Check table ID */
      if ( ID < 0  ||  ID > lastTableID ) {
         sprintf(amatError, "ID (= %d) of a table is not in the range 0 .. %d\n",
                 ID, (int) Dymola_max(0,lastTableID));
         goto ERROR_;
      }

   /* Get table data and check it */
      colWise    = dymTable[ID].colWise;
      nipo       = dymTable[ID].nipo;
      nt1        = dymTable[ID].dim[0];
      nt2        = dymTable[ID].dim[1];
      table      = dymTable[ID].table;
      expoType   = dymTable[ID].expoType;
      t_offset   = dymTable[ID].t_offset;
      startTime  = dymTable[ID].startTime;
      table_time = time - t_offset;
      if ( nipo != 0 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is not defined for time-interpolation\n"
                            "(table defined for %dD-interpolation).\n",
                            dymTable[ID].tableName, nt1, nt2, nipo);
         goto ERROR_;
      } else if ( icol < 2  ||  icol > nt2 ) {
         sprintf(amatError, "Table \"%s(%d,%d)\" is used for time-interpolation\n"
                            "in column %d, which is out of range.\n",
                            dymTable[ID].tableName, nt1, nt2, icol);
         goto ERROR_;
      }

   /* Determine minimum and maximum table values */
      tmin = tableGet(1,1);
      tmax = tableGet(nt1,1);

   /* At an event instant, set next time event */
      iu = dymTable[ID].last[0];
      if ( event ) {
         /* Handle startTime */
            if ( time < timeLimit(startTime) ) {
               registerTimeEvent(startTime);
               return 0.0;
            }

         /* Handle case, when table has only one entry */
            if ( nt1 <= 1 ) {
               y1 = tableGet(1,icol);
               return y1;
            }
            dymTable[ID].ipoPoint = 0;

         /* Find next interval for periodic functions */
            if ( (expoType == 2) && (table_time >= timeLimit(tmax)) ) {
               T = tmax - tmin;
               iv = (time - startTime - tmin) / T;
               t_offset = startTime + (floor(iv)-1)*T;
               table_time = time - t_offset;
			   while (table_time>=timeLimit(tmax)) {
				   t_offset +=T;
				   table_time = time - t_offset;
				   dymTable[ID].t_offset = t_offset;
			   }
			   dymTable[ID].t_offset = t_offset;
               iu = 1;
               dymTable[ID].last[0] = iu;
            }
			

        /* Find correct interval of time function, sucht that iu is at most nt1-1 */
			while ( iu < nt1-1  &&  table_time >= timeLimit(tableGet(iu+1,1))-((expoType==2) ? 1e-6*(tmax-tmin):0)) iu++;

        /* Store index of interval */
           dymTable[ID].last[0] = iu;

        /* Determine next time event */
           if ( expoType == 0 ) {
              if ( table_time < timeLimit(tmin) ) {
                 nextTime = t_offset + tmin;
                 registerTimeEvent(nextTime);
                 dymTable[ID].ipoPoint = 2;

              } else if ( table_time > timeLimit(tmax) ) {
                dymTable[ID].ipoPoint = 3;

              } else {
                nextTime = t_offset + tableGet(iu+1,1);
                registerTimeEvent(nextTime);
                dymTable[ID].ipoPoint = 0;
              }
           } else if ( expoType == 1 ) {
              if ( table_time <= timeLimit(tmax) ) {
                 nextTime = t_offset + tableGet(iu+1,1);
                 registerTimeEvent(nextTime);
              }
           } else {  /* expoType == 2 (periodic) */
              nextTime = t_offset + tableGet(iu+1,1);
              registerTimeEvent(nextTime);
           }
      }

   /* Handle startTime and constant extrapolation */
      ipoPoint = dymTable[ID].ipoPoint;
      if ( ipoPoint == 1 ) {
         return 0.0;
      } else if ( ipoPoint == 2 || nt1 <= 1 ) {
         y1 = tableGet(1,icol);
         return y1;
      } else if ( ipoPoint == 3 ) {
         y1 = tableGet(nt1,icol);
         return y1;
      }

   /* Get interpolation data */
      iu = dymTable[ID].last[0];
	  if (dymTable[ID].ipoType==1) {
		  {
			  /* Spline interpolation */
			  double q[4];
			  double p0=dymTableSpline(q,table,iu+1,icol,colWise,nt1,nt2);
			  double dx = table_time - p0;
			  return q[0]+dx*(q[1]+dx*(q[2]+dx*q[3]));
		  }
	  }
      u1 = tableGet(iu  ,   1);
      u2 = tableGet(iu+1,   1);
      y1 = tableGet(iu  ,icol);
      y2 = tableGet(iu+1,icol);

   /* Check for zero division
      (only possible, if the last two time values in the table are identical)
   */
      if ( u1 >= timeLimit(u2) ) {
         return y2;
      }

   /* Interpolate and return */
      return linearIpo(table_time,u1,u2,y1,y2);

   /* An error occured */
      ERROR_: DymosimError(amatError);
             return 0.0;
}



DYMOLA_STATIC void dymTablePrint(void) {
   /* Print actual definition of tables to log-file. Output format:

      table          (123,123,123)   fileName
      123456789012345                123456789012345
   */
      char mess[500], format[20], *str;
      int  ilen, i, j, lentab, lenfile, ndim;

   /* Determine maximum tableName length */
      lentab  = 1;
      lenfile = 1;
      for (i=0; i<=lastTableID; i++) {
         ilen    = (int) strlen( dymTable[i].tableName );
         lentab  = Dymola_max(lentab, ilen);
         ilen    = (int) strlen( dymTable[i].fileName );
         lenfile = Dymola_max(lenfile, ilen);
      }


   /* Print heading */
      ilen = (int) strlen( "file name" );
      lenfile = Dymola_max(lenfile, ilen);

      sprintf(format," %%-%ds  table", (int) lenfile);
      sprintf(mess, format, "file name" );
      DymosimMessage( mess );
      ilen = (int) strlen(mess);
      str  = &mess[1];
      for (i=1; i<ilen; i++) {sprintf(str,"_"); str++;};
      sprintf(str,"\n");
      DymosimMessage( mess );

   /* Print table entries */
      sprintf(format," %%-%ds  %%-%ds(%%d", lenfile, lentab);
      ndim = 2;
      for (i=0; i<=lastTableID; i++) {
         sprintf(mess, format, dymTable[i].fileName,
                               dymTable[i].tableName, dymTable[i].dim[0]);
         ilen = (int) strlen(mess);
         for (j=1; j<ndim; j++) {
             str = &mess[ilen];
             ilen = sprintf(str, ",%d", dymTable[i].dim[j]);
             if ( ilen > 0 ) {
                str = &str[ilen];
             } else { /* error */
                sprintf(mess," ????");
                goto LABEL1;
             }
         }
         sprintf(str,")");
         LABEL1: DymosimMessage(mess);
      }
      DymosimMessage(" ");
}






/* Internal functions of this file ---------------------------------------- */

static int dymTableCheckName(const char *name) {

   /* Check the type of name. Return 0, if name is NULL, contains
      only blank strings or "NoName". Otherwise return 1.
   */
      int i=0;
      if ( name == NULL )               return 0;
      if ( strcmp(name,"NoName") == 0 ) return 0;

      while ( *name ) {
         if ( *name != ' ' ) {i = 1; break; }
         name++;
      }
      return i;
}



static TableType dymTableType(const char *tableName, const char *fileName) {

   /* Determine in which way the table values are defined */
      TableType tType;
      int       tableNameGiven, fileNameGiven;

   /* Determine which names are provided */
      tableNameGiven = dymTableCheckName(tableName);
      fileNameGiven  = dymTableCheckName(fileName);

   /* Determine in which way the table values are defined */
      if ( tableNameGiven == 0 ) {
         /* No table name is given */
            if ( fileNameGiven != 0 ) {
               sprintf(amatError,"The file name for a table (= \"%s\") is defined,\n"
                                 "but not the corresponding table name (tableName).\n",
                                 fileName);
               goto ERROR_;
            }
            tType = TABLE_FROM_FIELD;

      } else {
         /* A tableName is given */
#ifdef NO_FILE
            if ( fileNameGiven != 0 ) {
               sprintf(amatError,"The file name (= \"%s\") for a table (= \"%s\") is defined. \n"
                                 "Since dymosim is used in an environment where storage cannot\n"
                                 "be allocated (#define NO_FILE), tables\n"
                                 "CANNOT be read from file.\n",
                                 fileName, tableName);
               goto ERROR_;
            }
            tType = TABLE_FROM_FUNCTION;
#else
            tType = fileNameGiven == 0 ? TABLE_FROM_FUNCTION : TABLE_FROM_FILE;
#endif
      }
      return tType;

   /* Error handling */
      ERROR_:  DymosimError(amatError);
              return TABLE_ERROR;
}



#ifndef NO_FILE
static int strcaselesscmp(const char*f1,const char*f2) {
	int cf1,cf2; /* Use int since toupper returns int */
	for(;(cf1=toupper(*f1))==(cf2=toupper(*f2)) && cf1 && cf2;++f1,++f2);
	return cf1<cf2 ? -1: cf1==cf2? 0: 1;
}
static DymFileList* dymTableLocateFile(const char* fileName, int* ierr) {

   /* Read all matrices stored on file "fileName"
      -> fileName: name of file
      <- ierr    : = 0: no error occured.
                   = 1: an error occured (message already printed).
      <- RETURN  : pointer to header of file list
                   (if NULL is returned then an error occured).
   */
      DymFileList    *nextFile   = fileList;
      DymFileList   **lastFile   = &fileList;
      DymMatrixList  *nextMatrix = NULL;
      DymMatrixList **lastMatrix = NULL;
      Amatrix        *matrix;
      AmatGetFile     file;
      int             status;
      char            mess[500];

   /* Transform file name in lower case letters on Windows System
      in order to get a unique filename and not to read the file
      several times if a different spelling is given
   */

   /* If this file is already stored in memory, return the file header */
      if (!ierr) return 0; /* Null-pointer check */
	  *ierr = 0;
      while ( nextFile ) {
#ifdef WIN32_ONLY
		  if (strcaselesscmp(nextFile->name,fileName)==0) {
#else
         if ( strcmp(nextFile->name, fileName) == 0 ) {
#endif
            return nextFile;
         }
         lastFile = &(nextFile->next);
         nextFile = nextFile->next;
      }

   /* Print info message, that file is loaded */
      sprintf(mess,"... \"%s\" loading (tables for interpolation)", fileName);
      DymosimMessage(mess);

   /* Open file */
      if ( amatGetOpen((char *) fileName, "NoClass", NULL, &file ) != 0 ) {
         DymosimError(amatError);
         *ierr = 1;
         return NULL;
      }

   /* Allocate storage for a fileList element */
      nextFile = (DymFileList *) malloc( sizeof(DymFileList) );
      if ( nextFile == NULL ) {
         sprintf(amatError,"Not enough storage available to read matrices\n"
                           "from file \"%s\".\n", fileName);
         DymosimError(amatError);
         amatGetClose(&file);
         *ierr = 1;
         return NULL;
      }
      nextFile->name        = (char *) fileName;
      nextFile->next        = NULL;
      nextFile->firstMatrix = NULL;
      *lastFile             = nextFile;

   /* Read all matrices from file */
      lastMatrix = &(nextFile->firstMatrix);
      for(;;) {
         /* Allocate storage for a new matrix list element and initialize it */
            nextMatrix = (DymMatrixList *) malloc( sizeof(DymMatrixList) );
            if ( nextMatrix == NULL ) {
               sprintf(amatError,"Not enough storage available to read matrix\n"
                                 "from file \"%s\".\n", fileName);
               goto ERROR_;
            }
            nextMatrix->next = NULL;
            matrix = &(nextMatrix->matrix);
            amatInit( matrix );

         /* Read next matrix from file and break if EOF reached */
            status = amatGetMatrix(&file, matrix);
            if ( status == 3 ) break;  /* EOF */
            if ( status != 0 ) goto ERROR_;

         /* Store matrix in file data structure */
            *lastMatrix = nextMatrix;
             lastMatrix = &(nextMatrix->next);
      }

   /* Close file */
      amatGetClose(&file);
      return nextFile;

   /* Error handling */
      ERROR_ : DymosimError(amatError);
              amatGetClose(&file);
              free( nextMatrix );
              *ierr = 1;
              return NULL;
}



static Amatrix* dymTableLocateMatrix(const DymFileList *file, const char *tableName,
                                     AmatType matrixType) {

   /* Locate matrix "tableName" in file list "file".
      Matrix has to be of type "matrixType".
      Return a pointer to the matrix.
   */
      DymMatrixList *matrixList = 0;
      if (!file) return 0; /* Error */
      matrixList = file->firstMatrix;

   /* Search matrix */
      while ( matrixList ) {
         if ( strcmp(matrixList->matrix.name, tableName) == 0 ) {
            /* Check matrix type */
               if ( matrixList->matrix.type != matrixType ) {
                  sprintf(amatError,"Table matrix \"%s\" has not the required datatype\n",
                                    tableName);
                  DymosimError(amatError);
                  return NULL;
               }
            return &(matrixList->matrix);
         }
         matrixList = matrixList->next;
      }

   /* Error */
      sprintf(amatError, "Matrix \"%s\" not found on file \"%s\".\n",
              tableName, file->name);
      DymosimError(amatError);
      return NULL;
}



#if 0
static int dymTableTranspose( Amatrix *matrix, char *fileName ) {

   /* Transpose the data of the matrix,
      if it is of type doubleMatrix
   */
      double *m2, *m1;
      int     nrow = matrix->nrow;
      int     ncol = matrix->ncol;
      int     i, j;

   /* Return, if matrix need not to be transposed */
      if ( matrix->type != doubleMatrix || nrow <= 1 || ncol <= 1 ) return 0;

   /* Allocate storage for new matrix data */
      m1 = matrix->data.d;
      m2 = (double *) malloc( sizeof(double)*((size_t) nrow*ncol) );
      if ( m2 == NULL ) {
         sprintf(amatError,"Not enough storage available to read matrix\n"
                           "from file \"%s\".\n", fileName);
         return 1;
      }

   /* Copy old matrix to new matrix and transpose it */
      for (i=0; i<nrow; i++) {
         for (j=0; j<ncol; j++) {
            m2[j + i*ncol] = m1[i + j*nrow];
         }
      }

   /* Remove old storage */
      free( m1 );
      matrix->data.d = m2;
      return 0;
}
#endif

#endif

