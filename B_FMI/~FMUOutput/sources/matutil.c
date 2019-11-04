/* MatUtil.c

   Utility routines for matrix handling in Dymola.

   Author: Hilding Elmqvist, Dynasim AB, 1995-10-01
   Version: 1.6, 1998-06-08
            1.7, 1998-10-05: modified for realtime
            1.8, 1998-12-01: allowed several files for matrices
            1.9, 1999-02-01: fixed test of value returned by SearchMatrix (HO)

*/
/*
 * Copyright (C) 1995-2001 Dynasim AB.
 * All rights reserved.
 *
 */

/* DLL-status: This file is has static data which is sometimes included with
the model. In addition it does not deallocate files */

#include <math.h>
/* #include <malloc.h> */
#if !defined(NO_FILE)
#include <stdio.h>
#endif
#include <string.h>
#include <stdlib.h>
#include "dymutil.h"
#include "matutil.h"
#include "amat.h"


typedef Amatrix* AmatrixP;
#define MaxMatrices 1000
static AmatrixP* Matrices;
static char * MatrixFiles[MaxMatrices];
static int nMatrices;

typedef struct table {
  int Used;
  Amatrix *dim, *grid, *table;
} table;
 
static table Tables[MaxMatrices];


#ifndef NO_FILE

static int ReadMatrices (char *fileName) { 

   /* Read matrices from a file. */
      AmatGetFile file;
      int status;
      char mess[1000];

      if ( amatGetOpen(fileName, "NoClass", "", &file ) != 0 ) return 1;
      while (1) { 
         Matrices[nMatrices] = amatNew();
         if (Matrices[nMatrices] == 0) {
           DymosimError("Simulator could not allocate space for matrix.");
           return 1;
         }
         status = amatGetMatrix(&file, Matrices[nMatrices]);
         if (status == 3) 
           break;
         if (status > 0) {
           sprintf(mess, "Error reading matrix:\n%s\n", amatError);
           DymosimError(mess);
           return 1;
         }

         MatrixFiles[nMatrices] = malloc(strlen(fileName)+1);
         strcpy(MatrixFiles[nMatrices], fileName);

         nMatrices = nMatrices + 1;

         if (nMatrices >= MaxMatrices) {
           DymosimError("Simulator is not able to read all matrices from data file.");
           amatGetClose(&file);
           return 2;
         }
      }
      amatGetClose(&file);
      return 0;
}

static void InitMatrices() {
  static int INIT=1;
  int i;

  if (INIT) {
    Matrices = (AmatrixP *) malloc(sizeof(AmatrixP) * MaxMatrices);
    INIT = 0;

    for (i=0;i<MaxMatrices;i++) {
      Tables[i].Used = 0;
    }
    nMatrices = 0;
  }  
}


/*
static void FreeMatrices() {
  int i;

  for (i=0;i<nMatrices;i++) {
    free(Matrices[i]->data.d); 
  }

  free(Matrices);
  
  for (i=0;i<nMatrices;i++) {
    if(Tables[i].Used) {
      free(Tables[i].dim->data.d); 
      free(Tables[i].grid->data.d); 
      free(Tables[i].table->data.d); 

      free(Tables[i].dim); 
      free(Tables[i].grid); 
      free(Tables[i].table); 
	}
  }  
}
*/

static int SearchMatrix(char *fileName, char *MatrixName, 
    AmatType type, Amatrix **matrix) {
  int i;
  char mess[1000];

  for (i=0;i<nMatrices;i++) {
    if (strcmp(Matrices[i]->name, MatrixName) == 0 &&
        strcmp(MatrixFiles[i], fileName) == 0) {
      *matrix = Matrices[i];
      if (Matrices[i]->type != type) {
        sprintf(mess, "Matrix %s has wrong type in file %s.", MatrixName, fileName);
        DymosimError(mess);
        return -1;
      }        
      return i;
    }
  }
  return -2;
}


static int LocateMatrix(char *MatrixName, AmatType type, Amatrix **matrix) {
  int status;
  char filename[300];
  char * name;
  char * delim;
  char mess[1000];
 
  /* Split name into file name and matrix name. */
  strcpy(filename, MatrixName);
  delim = strrchr(filename, '/');
  if (delim == 0) {
    name = MatrixName;
    strcpy(filename, "dsdata.mat");
  } else {
    * delim = '\0';
    name = delim + 1;
  }

  status = SearchMatrix(filename, name, type, matrix);

  if (status >= 0) return status;

  if (ReadMatrices(filename) == 1) {
    sprintf(mess, "Simulator could not find the data file %s.", filename);
    DymosimError(mess);
    return -1;
  }

  status = SearchMatrix(filename, name, type, matrix);

  if (status >= 0) return status;

  sprintf(mess, "Simulator could not find matrix %s in file %s.", name, filename);
  DymosimError(mess);
  return -1;
}

static AmatrixP CreateDoubleMatrix(int nx, int ny) { 
  AmatrixP m;

    m = amatNew();
    if (m == 0) {
      DymosimError("Simulator is unfortunately out of memory.");
      return 0;
      }
    m->nrow = nx;
    m->ncol = ny;
    m->data.d = malloc(nx*ny*sizeof(double));
    if (m->data.d == 0) {
      DymosimError("Simulator is unfortunately out of memory.");
      return 0;
      }
    return m;
}


double ReadMatrix(char name[], double M[], int n1, int n2) {
/* Reads an external matrix named in name into matrix M. */

  Amatrix* mat = 0;
  int i, j, matind;
  char mess[1000];

  InitMatrices();

  matind = LocateMatrix(name, doubleMatrix, &mat);
  if (matind < 0 || !mat) {
    return 0.0;
    }

  if (mat->nrow != n1 || mat->ncol != n2) {
    sprintf(mess, "Incompatible dimension of matrix: %s\n", mat->name);
    return DymosimError(mess);
  }

  for (i = 0; i<n1; i++) 
    for (j = 0; j<n2; j++) 
      M[i*n2 + j] = mat->data.d[j*n1 + i];

  free(mat->data.d);
  free(mat);
  return 1.0;
}



double WriteMatrix(char name[], double M[], int n1, int n2) {
/* Writes matrix M into an matrix named name in file named name.mat. */

  Amatrix mat;
  int i, j, status;
  char filename[80];
  char mess[1000];

  amatInit(&mat);

  mat.name = malloc(strlen(name)+1);
  mat.data.d = (doublereal *) malloc( n1*n2*sizeof(doublereal) );
  if (mat.name == NULL || mat.data.d == NULL) {
	  if (mat.name) free(mat.name);
	  if (mat.data.d) free(mat.data.d);
	  sprintf(mess, "Simulator is unfortunately out of memory.\n");
      return DymosimError(mess);
  }
  strcpy(mat.name, name);
  mat.type = doubleMatrix;
  mat.nrow = n1;
  mat.ncol = n2;

  for (i = 0; i<n1; i++) 
    for (j = 0; j<n2; j++) 
      mat.data.d[i*n2 + j] = M[j*n1 + i];

  strncpy(filename, mat.name, 75);
  filename[75] = '\0';   /* to ensure nul-termination */
  strcat(filename, ".mat");

  status = amatWrite(filename, amatBinary, mat);

  if (status != 0) {
    sprintf(mess, "Error writing matrix: %s\n%s\n", mat.name, amatError);
    return DymosimError(mess);
  }

  free(mat.name);
  free(mat.data.d);
  return 1.0;
}
#else
DYMOLA_STATIC double ReadMatrix(char name[], double M[], int n1, int n2) {
   return 0.0;
}

DYMOLA_STATIC double WriteMatrix(char name[], double M[], int n1, int n2) {
   return 0.0;
}
#endif



DYMOLA_STATIC int SearchGrid(double x, const double xval[], int Mxval) {
/* Calculates index in xval according to:
  below = 0;
  while (x > xval[below+1]) 
    below = below + 1;
  return below;

  A more efficient search is done by calculating a better start 
  value based on the assumption of approximately equidistant
  grid.
*/
  int below;
  double xlow, xhigh;

  xlow = xval[0];
  xhigh = xval[Mxval-1];

  /* Calculate start approximation for below. */

  below = (int) ( (double)(Mxval-2) * (x-xlow) / (xhigh-xlow) );

  /* Check bounds to take care of roundoff errors. */
  if (below < 0)
    below = 0;
  else if (below > Mxval-2)   
	below = Mxval-2;          /* Not the last value. */

  /* Modify below if too low. */
  while (x > xval[below+1]) 
    below = below + 1;

  /* Modify below if too high. */
  while (x < xval[below]) 
    below = below - 1;

  return below;
}


DYMOLA_STATIC double Interpolate1(double x, const double xval[], int Mxval, int Nxval, 
                              const double yval[], int Myval, int Nyval) {   
/*  Linear interpolation in one dimension: y=f(x). 
    F is defined by points (xval[i], yval[i]). */
  int below;
  int Kxval, Kyval;

  if ((Mxval != 1 && Nxval != 1) || (Myval != 1 && Nyval != 1)) {
    return DymosimError("Arguments to Interpolate1 must be vectors.");
    }
    
  Kxval = Mxval > 1 ? Mxval : Nxval;
  Kyval = Myval > 1 ? Myval : Nyval;
                   
  if (Kxval != Kyval) {
    return DymosimError("The x and y vectors must have the same length in Interpolate1.");  
    }
  else if (x <= xval[0])
    return (yval[0]);
  else if (x >= xval[Kxval-1])
    return (yval[Kxval-1]);
  else { 
    below = SearchGrid(x, xval, Kxval);

    return ( yval[below] + (yval[below+1]-yval[below]) * (x-xval[below]) / 
             (xval[below+1]-xval[below]));
  }
}

DYMOLA_STATIC void Interpolate1DerS(double* res, double* res_d, double x, const double xval[], int Mxval, int Nxval, 
                              const double yval[], int Myval, int Nyval, double dx) {   
/*  Linear interpolation in one dimension: y=f(x). 
    F is defined by points (xval[i], yval[i]). */
  int below;
  int Kxval, Kyval;
  *res = 0;
  *res_d = 0;

  if ((Mxval != 1 && Nxval != 1) || (Myval != 1 && Nyval != 1)) {
    DymosimError("Arguments to Interpolate1 must be vectors.");
	return;
    }
    
  Kxval = Mxval > 1 ? Mxval : Nxval;
  Kyval = Myval > 1 ? Myval : Nyval;
                   
  if (Kxval != Kyval) {
    DymosimError("The x and y vectors must have the same length in Interpolate1.");  
	return;
    }
  else if (x <= xval[0]) {
    *res = (yval[0]);
	*res_d = 0;
  } else if (x >= xval[Kxval-1]) {
    *res = (yval[Kxval-1]);
	*res_d = 0;
  } else { 
    below = SearchGrid(x, xval, Kxval);

    *res=( yval[below] + (yval[below+1]-yval[below]) * (x-xval[below]) / 
             (xval[below+1]-xval[below]));
	*res_d=((yval[below+1]-yval[below])*dx/(xval[below+1]-xval[below]));
  }
}

DYMOLA_STATIC double Interpolate(const double dim[], int Mdim, int Ndim,
                   const double xval[], int Mxval, int Nxval, 
                   const double yval[], int Myval, int Nyval,
                   const double x[], int Mx, int Nx) {  
                   
/*  Linear interpolation in n dimensions: y=f(x1, x2, ..., xn). 
    The dim vector gives the number of grid points for each argument.
    The grid points are stored in xval: 
      [x1[1], x1[2], ... x1[dim[1]],
      [x2[1], x2[2], ... x2[dim[2]],
    
      [xn[1], xn[2], ... xn[dim[n]].
    
    The corresponding function values are stored in yval:
    
      f[1,1, ..., 1], f[1,1, ..., 2], ..., f[1,1, ..., dim[n]],
      ...
      f[1,2, ..., 1], f[1,2, ..., 2], ..., f[1,2, ..., dim[n]],

      f[dim[1],dim[2], ..., 1], f[dim[1],dim[2], ..., 2], ..., f[dim[1],dim[2], ..., dim[n]] 
              
    Interpolate can be used as follows in Modelica:

  model m 
    Real x[3, 1]=Modelica.Math.sin([3*time; 5*time; 7*time]) "Input";
    parameter Real dim[3, 1]=[3; 2; 2] "Sizes for the dimensions";
    parameter Real xval[3 + 2 + 2, 1]=[-1;0;1; -1;1; -1;1] 
      "Grid values in the dimensions";
    parameter Real yval[3*2*2, 1]=[1;2; 3;4;  11;12; 13;14;  15;16; 17;18] 
      "Table values";
    output Real y;
  equation 
    y = Interpolate(dim, xval, yval, x);
   end m;

      
    The interpolation is done recursively:
     - search among grid points for this argument
     - interpolate the remaining arguments for grid points above and below
     - interpolate in result from the two interpolations
    */                  
    
  int below;
  double ybelow, yabove;
  int i, dimsum, dimprod; 
  int Kx, Kdim, Kxval, Kyval;

  if ((Mx != 1 && Nx != 1) || (Mdim != 1 && Ndim != 1)) {
    return DymosimError("Arguments to Interpolate must be vectors.");
    } 
  Kx = Mx > 1 ? Mx : Nx;
  Kdim = Mdim > 1 ? Mdim : Ndim;
  Kxval = Mxval * Nxval;
  Kyval = Myval * Nyval;

  if (Kx != Kdim) {
    return DymosimError("The size of the argument vector is not the same as\n"
                 "  the dimension vector of a table.");
    }   
    
  /* Calculate the size of a table for the rest of the arguments. */
  dimsum = 0;
  dimprod = 1;   
  for (i=0;i<Kdim;i++) {
    if (dim[i] != floor(dim[i])) {
      return DymosimError("The dimension vector of a table must only contain "
                   "integers.");
      }
    dimsum = dimsum + (int) dim[i];   
    dimprod = dimprod * (int) dim[i];   
    }
  if (Kxval != dimsum) {
    return DymosimError("The size of the grid vector is not consistent with\n"
                 "  information in the dimension vector of a table.");
    } 
  if (Kyval != dimprod) {
    return DymosimError("The size of the table value vector is not\n"
                 "  consistent with information in the dimension vector.");
    } 

  if (Kdim <= 1) 
    return Interpolate1(x[0], xval, Kxval, 1, yval, Kyval, 1);
  else if (x[0] <= xval[0]) {
    below = 0;  /* Use lowest data set. */
    return Interpolate(&dim[1], Kdim-1, 1,
                       &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                       &yval[below*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                       &x[1], Kx-1, 1);
    }
  else if (x[0] >= xval[(int)dim[0]-1])  {
    below = (int)dim[0]-1;
    return Interpolate(&dim[1], Kdim-1, 1,
                       &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                       &yval[below*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                       &x[1], Kx-1, 1);
    }
  else {   
    below = SearchGrid(x[0], xval, (int)dim[0]);
    
    /* Interpolate the rest of the arguments for the grid points below and above. */
    ybelow = Interpolate(&dim[1], Kdim-1, 1,
                         &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                         &yval[below*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                         &x[1], Kx-1, 1);
    yabove = Interpolate(&dim[1], Kdim-1, 1,
                         &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                         &yval[(below+1)*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                         &x[1], Kx-1, 1);

    /* Interpolate this argument. */
    return ( ybelow + (yabove-ybelow) * (x[0]-xval[below]) / 
             (xval[below+1]-xval[below]));
  }
}




DYMOLA_STATIC void InterpolateDerS(double* res, double* d_res,const double dim[], int Mdim, int Ndim,
                   const double xval[], int Mxval, int Nxval, 
                   const double yval[], int Myval, int Nyval,
                   const double x[], int Mx, int Nx, const double dx[]) {
                   
/*  Derivative of linear interpolation in n dimensions: y=f(x1, x2, ..., xn). 
    The dim vector gives the number of grid points for each argument.
    The grid points are stored in xval: 
      [x1[1], x1[2], ... x1[dim[1]],
      [x2[1], x2[2], ... x2[dim[2]],
    
      [xn[1], xn[2], ... xn[dim[n]].
    
    The corresponding function values are stored in yval:
    
      f[1,1, ..., 1], f[1,1, ..., 2], ..., f[1,1, ..., dim[n]],
      ...
      f[1,2, ..., 1], f[1,2, ..., 2], ..., f[1,2, ..., dim[n]],

      f[dim[1],dim[2], ..., 1], f[dim[1],dim[2], ..., 2], ..., f[dim[1],dim[2], ..., dim[n]] 
              
    Interpolate can be used as follows in Modelica:

  model m 
    Real x[3, 1]=Modelica.Math.sin([3*time; 5*time; 7*time]) "Input";
    parameter Real dim[3, 1]=[3; 2; 2] "Sizes for the dimensions";
    parameter Real xval[3 + 2 + 2, 1]=[-1;0;1; -1;1; -1;1] 
      "Grid values in the dimensions";
    parameter Real yval[3*2*2, 1]=[1;2; 3;4;  11;12; 13;14;  15;16; 17;18] 
      "Table values";
    output Real y;
  equation 
    y = Interpolate(dim, xval, yval, x);
   end m;
      
    The interpolation is done recursively:
     - search among grid points for this argument
     - interpolate the remaining arguments for grid points above and below
     - interpolate in result from the two interpolations
    */                  
    
  int below;

  int i, dimsum, dimprod; 
  int Kx, Kdim, Kxval, Kyval;
  *res = 0;
  *d_res = 0;

  if ((Mx != 1 && Nx != 1) || (Mdim != 1 && Ndim != 1)) {
    DymosimError("Arguments to Interpolate must be vectors.");
	return ;
    } 
  Kx = Mx > 1 ? Mx : Nx;
  Kdim = Mdim > 1 ? Mdim : Ndim;
  Kxval = Mxval * Nxval;
  Kyval = Myval * Nyval;

  if (Kx != Kdim) {
    DymosimError("The size of the argument vector is not the same as\n"
                 "  the dimension vector of a table.");
	return;
    }   
    
  /* Calculate the size of a table for the rest of the arguments. */
  dimsum = 0;
  dimprod = 1;   
  for (i=0;i<Kdim;i++) {
    if (dim[i] != floor(dim[i])) {
      DymosimError("The dimension vector of a table must only contain "
                   "integers.");
	  return;
      }
    dimsum = dimsum + (int) dim[i];   
    dimprod = dimprod * (int) dim[i];   
    }
  if (Kxval != dimsum) {
    DymosimError("The size of the grid vector is not consistent with\n"
                 "  information in the dimension vector of a table.");
	return;
    } 
  if (Kyval != dimprod) {
    DymosimError("The size of the table value vector is not\n"
                 "  consistent with information in the dimension vector.");
	return;
    } 

  if (Kdim <= 1) {
    Interpolate1DerS(res,d_res,x[0], xval, Kxval, 1, yval, Kyval, 1, dx[0]);
	return;
  } else if (x[0] <= xval[0]) {
    below = 0;  /* Use lowest data set. */
    InterpolateDerS(res,d_res,&dim[1], Kdim-1, 1,
                       &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                       &yval[below*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                       &x[1], Kx-1, 1,&dx[1]);
	return;
    } else if (x[0] >= xval[(int)dim[0]-1])  {
    below = (int)dim[0]-1;
    InterpolateDerS(res,d_res,&dim[1], Kdim-1, 1,
                       &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                       &yval[below*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                       &x[1], Kx-1, 1,&dx[1]);
	return;
    }
  else {   
	    double ybelow, yabove;
		double ybelow_d, yabove_d;

    below = SearchGrid(x[0], xval, (int)dim[0]);
    
    /* Interpolate the rest of the arguments for the grid points below and above. */
    InterpolateDerS(&ybelow,&ybelow_d,&dim[1], Kdim-1, 1,
                         &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                         &yval[below*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                         &x[1], Kx-1, 1,&dx[1]);
    InterpolateDerS(&yabove,&yabove_d,&dim[1], Kdim-1, 1,
                         &xval[(int)dim[0]], Kxval-(int)dim[0], 1,
                         &yval[(below+1)*dimprod/(int)dim[0]], Kyval/(int)dim[0], 1,
                         &x[1], Kx-1, 1,&dx[1]);

    /* Interpolate this argument. */

    *res=( ybelow + (yabove-ybelow) * (x[0]-xval[below]) / 
             (xval[below+1]-xval[below]));
	*d_res=((yabove-ybelow)*dx[0]/(xval[below+1]-xval[below]))+
		(ybelow_d+(yabove_d-ybelow_d)*(x[0]-xval[below]) / (xval[below+1]-xval[below]));
	return;
  }
}

DYMOLA_STATIC double InterpolateDer(const double dim[], int Mdim, int Ndim,
                   const double xval[], int Mxval, int Nxval, 
                   const double yval[], int Myval, int Nyval,
                   const double x[], int Mx, int Nx, const double dx[]) {
	double res,d_res;
	InterpolateDerS(&res,&d_res,dim,Mdim,Ndim,xval,Mxval,Nxval,yval,Myval,Nyval,x,Mx,Nx,dx);
	return d_res;
}

#ifndef NO_FILE

double ExternalTable(char *dimname, char *gridname, char *tablename, 
  double x[], int Mx, int Nx) {
/* Interpolation in n dimensions utilizing external matrices dimname,
   gridname and tablename. */
  static Amatrix* dim = 0, *grid = 0, *table = 0;

  int matind;
  double retur;

    InitMatrices();

    matind = LocateMatrix(dimname, doubleMatrix, &dim);
    if (matind < 0 || !dim) {
      return 0.0;
    }

    matind = LocateMatrix(gridname, doubleMatrix, &grid);
    if (matind < 0 || !grid) {
      return 0.0;
    }

    matind = LocateMatrix(tablename, doubleMatrix, &table);
    if (matind < 0 || !table) {
      return 0.0;
    }

    retur = Interpolate(dim->data.d,    dim->nrow,   dim->ncol,
                        grid->data.d,   grid->nrow,  grid->ncol,
                        table->data.d,  table->nrow, table->ncol,
                        x,              Mx,          Nx);

    return retur;
}

double ExternalTable1(char *gridname, char *tablename, double x) {
/* Interpolation in one dimension utilizing external matrices
   gridname and tablename. */

  static Amatrix *dim=0, *grid=0, *table=0;

  int matind;
  double retur;
  double arg[1];

    InitMatrices();

    arg[0] = x;

    matind = LocateMatrix(gridname, doubleMatrix, &grid);
    if (matind < 0 || !grid) {
      return 0.0;
      }

    matind = LocateMatrix(tablename, doubleMatrix, &table);
    if (matind < 0 || !table) {
      return 0.0;
      }

    dim = CreateDoubleMatrix(1, 1);
    if (dim == 0) 
      return 0.0;
    dim->data.d[0] = grid->nrow*grid->ncol;

    retur = Interpolate(dim->data.d,  dim->nrow,   dim->ncol,
                       grid->data.d,  grid->nrow,  grid->ncol,
                       table->data.d, table->nrow, table->ncol,
                       arg,           1,           1);

    free(dim->data.d); 
    free(dim); 

    return retur;
}

double ExternalTable2(char* MatrixName, double x, double y) {

/* Interpolation in 2 dimensions utilizing external matrix MatrixName. 
   First column is grid for x and first row is grid for y. */

  static Amatrix* mat = 0, *dim = 0, *grid = 0, *table = 0;

  int matind;
  double retur;
  int nx, ny, i, j;
  double arg[2];

    InitMatrices();

    matind = LocateMatrix(MatrixName, doubleMatrix, &mat);
    if (matind < 0 || !mat) {
      return 0.0;
    }

    arg[0] = x;
    arg[1] = y;

	if (! Tables[matind].Used) {
      Tables[matind].Used = 1;

      Tables[matind].dim = CreateDoubleMatrix(2, 1);
      if (Tables[matind].dim == 0) 
        return 0.0;
      nx = mat->nrow - 1;
      ny = mat->ncol - 1;
      Tables[matind].dim->data.d[0] = nx;
      Tables[matind].dim->data.d[1] = ny;

      Tables[matind].grid = CreateDoubleMatrix(nx + ny, 1);
      if (Tables[matind].grid == 0) 
        return 0.0;
      for (i=0; i<nx; i++)
        Tables[matind].grid->data.d[i] = mat->data.d[i+1];  
          /* First column except first element. */
      for (i=0; i<ny; i++)
        Tables[matind].grid->data.d[nx + i] = mat->data.d[(i+1)*mat->nrow];  
          /* First row except first element. */

      Tables[matind].table = CreateDoubleMatrix(nx*ny, 1);
      if (Tables[matind].table == 0) 
        return 0.0;
      for (i=0; i<nx; i++)
        for (j=0; j<ny; j++)
          Tables[matind].table->data.d[i*ny+j] = mat->data.d[(i+1) + (j+1)*mat->nrow]; 
	} 

    dim = Tables[matind].dim;
    grid = Tables[matind].grid;
    table = Tables[matind].table;
	
	if (!dim || !grid || !table) return 0.0; /* Null-pointer check */
    retur = Interpolate(dim->data.d, dim->nrow, dim->ncol,
                       grid->data.d,  grid->nrow,  grid->ncol,
                       table->data.d, table->nrow, table->ncol,
                       arg,           2,           1);
/*
    free(dim->data.d); 
    free(grid->data.d); 
    free(table->data.d); 

    free(dim); 
    free(grid); 
    free(table); 
*/
    return retur;
  }

#else
DYMOLA_STATIC double ExternalTable(char *dimname, char *gridname, char *tablename, 
  double x[], int Mx, int Nx) {
  return 0.0;
}

DYMOLA_STATIC double ExternalTable1(char *gridname, char *tablename, double x) {
  return 0.0;
}

DYMOLA_STATIC double ExternalTable2(char *MatrixName, double x, double y) {
  return 0.0;
}
#endif

