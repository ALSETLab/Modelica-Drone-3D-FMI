#ifndef USERTAB_H
#define USERTAB_H

/*
 * Copyright (C) 1997-2001 Dynasim AB.
 * All rights reserved.
 *
 */

#if defined(DYMOLA_DSPACE)
#include <dsdefs.h>
#else
#include <stdio.h>
#endif
#include <string.h>
#include "dymutil.h"
#include "dymtable.h"

typedef struct {
   char   *name;    /* Name of table                         */
   double *value;   /* Pointer to value matrix               */
   int     nipo;    /* = 0: 1D-table with time as abszissa   */
                    /* = 1: 1D-table                         */
                    /* = 2: 2D-table                         */
   int     dim[2];  /* Actual number of dimensions           */
} UsertabTableElement;


/* ------------------------------------------------------------------------- */
/* Static definitions of all tables. Adapt to your needs.                    */
/* ------------------------------------------------------------------------- */

/* Use at most 28 characters for the names of table vectors,                
   since this limit is imposed by Dymola for character strings

   A 1D-table is defined as a matrix where
     - the first column is the abszissa data
     - the other columns are the ordinate data to
       be interpolated with respect to the first column.
   A 1D-table with time as abszissa may have discontinuities, i.e.,
   the abszissa data needs to be only monotonically increasing.
   In all other cases, the abszissa data needs to be strict
   monotonically increasing.
     
   A 2D-table is defined as a matrix where
     - the first column (without first element), i.e., table(2:,1),
       is the first abscissa (u(1)),
     - the first row (without first element), i.e., table(1,2:),
       is the second abscissa (u(2)),
     - the other elements, i.e., table(i,j) with i>=2,j>=2,
       are the corresponding ordinate values.
*/

/* ------------------------------------------------------------------------ */

/* Definition of all value vectors */
      static double TestTable_1[] = {0.0,  0.0,          /* 1D-table */
                                     1.0,  1.0,
                                     2.0,  4.0,
                                     3.0,  9.0,
                                     4.0, 16.0,
                                     5.0, 25.0};

      static double TestTable_2[] = {0.0, 0.0, 0.0,      /* 1D-table */
                                     1.0, 2.0, 0.5,
                                     2.0, 4.0, 1.0,
                                     3.0, 6.0, 1.5};


      static double TestTable_3[] = {0.0, 0.0,  2.0,  4.0,   /* 2D-table */
                                     0.0, 0.0,  5.0, 15.0,
                                     1.0, 3.0, 10.0, 20.0,
                                     2.0, 6.0, 15.0, 25.0};

/* Definition of the tables 
       N_TABLEDEF: Number of tables.
       name      : Name of table.
       nipo      : = 0: time-table (first axis is time; discontinuous points
                                    are allowed).
                   = 1: 1D-table.
                   = 2: 2D-table.
       dim1      : Number of rows.
       dim2      : Number of columns.
  */

#define N_TABLEDEF  3
      static UsertabTableElement tableDef[N_TABLEDEF] = {
           /* name         pointer to value  nipo,  dim1, dim2 */
           {"TestTable_1", TestTable_1,        1,     {6,   2} }
          ,{"TestTable_2", TestTable_2,        1,     {4,   3} }
          ,{"TestTable_3", TestTable_3,        2,     {4,   4} }
      };

#endif
