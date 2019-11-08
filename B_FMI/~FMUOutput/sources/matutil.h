/* MatUtil.h

   Utility routines for matrix handling in Dymola.

   Author: Hilding Elmqvist, Dynasim AB, 1995-10-01
   Version: 1.4, 1996-05-24

*/
/*
 * Copyright (C) 1995-2001 Dynasim AB.
 * All rights reserved.
 *
 */

#ifndef MATUTIL_H
#define MATUTIL_H
#include "libdssetup.h"
DYMOLA_STATIC LIBDS_API_AFTER double ReadMatrix(char name[], double M[], int n1, int n2);

/* Reads an external matrix named in name into matrix M. */


DYMOLA_STATIC LIBDS_API_AFTER double WriteMatrix(char name[], double M[], int n1, int n2);

/* Writes matrix M into an matrix named name in file named name.mat. */


DYMOLA_STATIC LIBDS_API_AFTER double Interpolate1(double x, const double xval[], int Mxval, int Nxval, 
                                     const double yval[], int Myval, int Nyval);  
 
/*  Linear interpolation in one dimension: y=f(x). 
    F is defined by points (xval[i], yval[i]). */


DYMOLA_STATIC LIBDS_API_AFTER double Interpolate(const double dim[], int Mdim, int Ndim,
                          const double xval[], int Mxval, int Nxval, 
                          const double yval[], int Myval, int Nyval,
                          const double x[], int Mx, int Nx);  
                   
/*  Linear interpolation in n dimensions: y=f(x1, x2, ..., xn). */

DYMOLA_STATIC LIBDS_API_AFTER double InterpolateDer(const double dim[], int Mdim, int Ndim,
                   const double xval[], int Mxval, int Nxval, 
                   const double yval[], int Myval, int Nyval,
                   const double x[], int Mx, int Nx, const double dx[]);

DYMOLA_STATIC LIBDS_API_AFTER double ExternalTable(char *dimname, char *gridname, char *tablename, 
  double x[], int Mx, int Nx);
/* Interpolation in n dimensions utilizing external matrices dimname,
   gridname and tablename. */


DYMOLA_STATIC LIBDS_API_AFTER double ExternalTable1(char *gridname, char *tablename, double x);
/* Interpolation in one dimension utilizing external matrices
   gridname and tablename. */


DYMOLA_STATIC LIBDS_API_AFTER double ExternalTable2(char *MatrixName, double x, double y);

/* Interpolation in 2 dimensions utilizing external matrix MatrixName. 
   First column is grid for x and first row is grid for y. */

#endif
