/* csvutil.h
 *
 * Utility functions for reading simple CSV files ("comma separated values").
 * The declarations follow the Modelica specification for external functions.
 *
 * Copyright (c) 2004,2005 Dynasim AB.
 * All rights reserved.
 */

#ifndef CSVUTIL_H
#define CSVUTIL_H

#include <stddef.h>
#if defined(__cplusplus) && !defined(COMPILE_AS_CPLUSPLUS)
extern "C" {
#endif

/* readCSVsizes() - read sizes from a CSV text file */

extern void readCSVsizes(const char* filename /* File containing the data */,
                         int* sizes /* Returns number of rows, columns, row legends, column legends */,
                         size_t sizes_dim1);

/* readCSVdata() - read data from a text file with comma separated values */

extern void readCSVmatrixInternal(const char* filename /* File containing the data */,
                                int n_rows /* Number of rows */,
                                int n_columns /* Number of columns */,
                                double* data /* Read data, size n_rows*n_columns */,
                                size_t data_dim1,
                                size_t data_dim2);

extern void readCSVHeadersInternal(const char* filename /* File containing the data */,
                         int n_columns /* Number of columns */,
						 const char** data,const char*sAlloc(const char*)); /* Data must be initialized before call - if sAlloc returns null the value is not changed */

/* write CSV file */

int WriteCSVmatrixInternal(const char*fname, double*values, size_t rows, size_t columns, 
						   const char*const*headers, const char*separator, int quoteAll);

#if defined(__cplusplus) && !defined(COMPILE_AS_CPLUSPLUS)
}
#endif
#endif
