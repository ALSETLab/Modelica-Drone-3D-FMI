#ifndef amat_h
#define amat_h

/*
 * Copyright (C) 1997-2010 Dynasim AB.
 * All rights reserved.
 *
 */


/* To make functions and variabled static to allow several S-function blocks
	for real-time targets */
#if !defined(DYMOLA_STATIC)
#if defined(__cplusplus)
#define DYMOLA_STATIC extern
#elif defined(RT) && !defined(DYM2DS)
#define DYMOLA_STATIC static
#else
#define DYMOLA_STATIC
#endif
#endif

#if !defined(NO_FILE)
/* Realtime compilation. DB 1998-10-05 */
#include <stdio.h>
#endif
#include "f2c.h"
#include "amach.h"
#ifdef __cplusplus
extern "C" {
#endif
/* 
   Read/write numeric and/or character matrices from/to file.
   The numeric matrices may be stored in real or in double precision.
   The data may be stored in ASCII format or in Matlab binary format
   on file.

   A numeric matrix may be mapped to a desired type when reading
   the data (e.g. a matrix stored in double precision may be returned
   in real precision; in this case only storage for one real matrix
   is allocated).

   When numeric matrices are generated row-wise (e.g. during a simulation),
   every row of the matrix may be stored on file immediately after it is
   available. The row dimension of the matrix needs not to be known
   in advance. This feature requires a special opening of the output file
   (in this case, ALL matrices are stored row-wise, instead of the usual
   column-wise format, when the data is stored in binary format).


   Functions for reading matrices:
      amatRead      : Read one matrix from a file.
      amatReadAll   : Read all matrices from a file.
      amatReadAll2  : Read all matrices from a file
                      (amatGetOpen must be called before).

      amatGetOpen   : Open data file and return file identificator "file".
      amatGetClose  : Close file "file" and release allocated storage.
      amatGetError  : Inquire which type of error occured.
      amatGetDescr  : Get description text of file.
      amatGetVersion: Get version string of file.
      amatGetMatrix : Read next matrix from file "file". 
      amatGetMatrixP: Read next matrix from file "file". If matrix
                      is of type "real" or "doublereal" map type
                      to a desired one.
      amatGetHeaderP: Read only matrix header from file "file".
                      The matrix data is read by a subsequent amatGetMatrix


   Functions for writing matrices:
      amatWrite     : Write one matrix on file (open, put and close).
      amatWriteAll  : Write all matrices on file.

      amatPutOpen   : Open data file and return file identificator "file".
      amatPutClose  : Close file "file" and release allocated storage.
      amatPutMatrix : Write matrix on file "file".
      amatPutMatrixD: Write matrix on file "file" including a description text
                      for the matrix and optionally for all of its elements,
                      if data is stored in ASCII format.

      amatPutRinit  : Initialize row-wise writing of numeric matrix.
      amatPutRclose : Close row-wise writing of numeric matrix.
      amatPutRreal  : Write one row of a real matrix onto file.


   Utility functions:
      amatNew       : Allocate storage for a new Amatrix object and
                      initialize it.
      amatInit      : Initialize an Amatrix object.
      amatInitValue : Initialize an Amatrix object with specific values.
      amatDel       : Delete the storage allocated from an Amatrix object.

      amatTextGen   : Generate default text.
      amatTextResize: Resize text.
      amatTextDel   : Delete storage of text.
      amatTextFind  : Find string in text.
      amatTextIndex : Build index from two text objects. 


   Example 1 for reading (most simple usage):
      // File has three matrices "mat1, mat2, mat3". "mat1" has fixed 
      // dimensions, whereas "mat2" has variable dimensions and
      // "mat3" must have the same dimensions as "mat2".
         const int mat1 = 0;
         const int mat2 = 1;
         const int mat3 = 2;
         static real vec[5*5];
         Aclass      c[3] = { {{"mat1", 5, 5, realMatrix, vec }, 0, 0, 0},
                              {{"mat2", 0, 0, realMatrix, NULL}, 0, 0, 0},
                              {{"mat3", 0, 0, realMatrix, NULL}, 0, 1, 1}
                            };

      // Define, that "mat3" has the same dimensions as "mat2"
         c[mat3].rowIndex = mat2;
         c[mat3].colIndex = mat2;

      // Read the matrices from file
         if ( amatReadAll("temp.mat", "TestClass", "1.0", c, 3) != 0 ) {
            fprintf("stderr,"Error in program XXX:\n%s",amatError);
            exit(1):
         }

      // Use matrices
      //   "mat1" = c[mat1].matrix
      //   "mat2" = c[mat2].matrix
      //   "mat3" = c[mat3].matrix
 

   Example 2 for reading (usage of basic routines):
      AmatGetFile file;
      static real vec[5*5];
      Amatrix     mat1 = { "mat1", 5, 5, realMatrix, vec }
      Amatrix     mat2;
      char        *descr;

      // Initialize storage of matrix mat2
         amatInit (mat2);

      // The first matrix must have a specific name, type and dimension
      // as defined in the declaration above. No storage will be allocated
      // by amatGetMatrix, because the whole storage is already provided by mat1.
      // Only data is copied from file into "vec".
   
      // The second matrix must have just a specific name and type.
      // The matrix may be optionally empty.
         mat2.name = "mat2";
         mat2.type = realMatrix;

      // Read the two matrices mat1(5,5) and mat2(*,*) from file
         if ( amatGetOpen("temp.mat", "TestClass", "1.0", &file ) != 0 ) goto ERROR;
         if ( amatGetMatrix(&file, mat1) != 0 ) goto ERROR;
         if ( amatGetMatrix(&file, mat2) >  1 ) goto ERROR;
         descr= amatGetDescr(&file);
                printf(">>> read file temp.mat:\n%s\n", descr);
                free(descr);
         amatGetClose(&file);

      // Use matrices mat1, mat2
         ...

      // Free allocated storage of matrices (note: mat1.name, mat1.data and mat2.name
      // is static storage, whereas mat2.data is dynamic storage)
         free(mat2.data);
           
         return 0;

      // Error handling (amatError is a global variable, defined in "amat.h")
         ERROR: fprintf(stderr,"Error in program XXX:\n%s",amatError);
                amatGetClose(&file);
                free(mat2.data);
                return 1;


   Example for writing:
      AmatPutFile file;
      Amatrix     mat1;
      const int   ncol=10;
      real        row[ncol];
      integer     i;

      char        *descr;

      // Build object mat1
            ...

      // Open file and write object onto file
         if ( amatPutOpen("temp.mat", amatBinary, binTrans, 
                          "TestClass", "1.0", "This is a test", &file) != 0) goto ERROR;
         if ( amatPutMatrix(&file, mat1) != 0 ) goto ERROR;

      // Write matrix row-wise onto file in real precision 
         if ( amatPutRinit(&file, "mat2", ncol, realMatrix) != 0 ) goto ERROR;
         while(1) {
            // Compute row i of matrix matr2 and store it in "row".
               ...
            // Write row to file
               if ( amatPutRreal(&file, row) != 0 ) goto ERROR;
            
            // If computation ended, break
               ...
         }
         amatPutRclose(&file);

      // Close file
         amatPutClose(&file);
         return 0;

      // Error handling (amatError is pointer to thread-global variable, defined in "amat.h")
         ERROR: fprintf(stderr,"Error in program XXX:\n%s",amatError);
                amatPutClose(&file);
                return 1;
*/



/*---------- Error message --------------------------------------------------*/


#define NAMATERROR 1500
#include "libdssetup.h"
LIBDS_API char* amatErrorFunction(void);

#ifdef LIBDS_DLL
#define amatError (amatErrorFunction())
#else
DYMOLA_STATIC char amatError[NAMATERROR];
#endif
                               /* Pointer to error message of last error */
                               /* (message contains '\n')                */
                               /*   amatError							 */
							   /* Note: Without dll it is a plain char   */
							   /* array, but for dll it is a macro       */
							   /* multiple threads have different amatError*/

/*---------- Matrix data structure in program -------------------------------*/

/*
   A numeric matrix is stored in column-dense format, i.e.,
   the columns of a matrix are stored in consecutive order one after
   the other in a vector (= Fortran convention).

   A character matrix is stored as a vector of character pointers
   which is called "text".
*/





typedef enum {
   voidMatrix   ,     /* matrix type is not known or not needed */
                      /* (only used as required type option)    */
   integerMatrix,     /* matrix is of type integer              */
   realMatrix   ,     /* matrix is of type "real"               */
   doubleMatrix ,     /* matrix is of type "doublereal"         */
   charMatrix,        /* vector of character pointers           */
   realRowMatrix,     /* matrix is of type "real" and stored row-wise */
   doubleRowMatrix    /* matrix is of type "doublereal" and stored row-wise */
} AmatType;


typedef union {
   void        *v;    /* generic pointer                   */
   integer     *i;    /* pointer to integer    matrix      */
   real        *r;    /* pointer to real       matrix      */
   doublereal  *d;    /* pointer to doublereal matrix      */
   char       **c;    /* pointer to char matrix            */
                      /* (= vector of character pointers)  */
   real **rrow;       /* pointer to pointers of real */
   doublereal **drow; /* pointer to pointers of doublereal */
} AmatData;


typedef struct Amatrix {
   char       *name;  /* matrix name                                */
   integer     nrow;  /* number of rows (nrow=0 means empty matrix) */
   integer     ncol;  /* number of columns                          */
                      /* (if type=charMatrix then                   */
                      /*     ncol > 0: maximum number of characters */
                      /*               in a string                  */
                      /*     ncol = 0: maximum number not known     */
                      /*  endif)                                    */
   AmatType    type;  /* matrix type                                */
   AmatData    data;  /* matrix data                                */
   integer     nrowallocated; 
                      /* only used for doubleRowMatrix, used to avoid reallocation*/
   integer     nrowread; /* only used for doubleRowMatrix, and as internal variable for charMatrix */
} Amatrix;




/*---------- File structure -------------------------------------------------*/

typedef enum {
   amatASCII ,     /* ASCII format          */
   amatBinary      /* Matlab binary format  */
} AmatFileType;


typedef enum {
   binNormal,      /* normal storage of matrix                   */
   binTrans        /* if binary file format, matrix is stored in */
                   /* transposed format                          */ 
} AmatBinStruct;



/*---------- Matlab matrix file structure -----------------------------------*/

#define MATTYPE (0L)

#ifdef MSDOS_ONLY
#  undef  MATTYPE
#  define MATTYPE (0L)
#endif

#ifdef WIN32_ONLY
#  undef  MATTYPE
#  define MATTYPE (0L)
#endif

#if defined(UNIX) && defined(linux)
#  undef  MATTYPE
#  define MATTYPE (0L)
#endif

#if defined(UNIX) && !defined(linux)
#  undef  MATTYPE
#  define MATTYPE (1000L)
#endif

#ifdef VAXD
#  undef  MATTYPE
#  define MATTYPE (2000L)
#endif

#ifdef VAXG
#  undef  MATTYPE
#  define MATTYPE (3000L)
#endif


typedef struct {
   int type;   /* type = MOPT
                      M = 0  for PC's and other machines with Intel byte order,
                          1  for Sun's and other machines with Motorola byte order,
                          2  for VAX D-float,
                          3  for VAX G-float,
                          4  for Cray.
                      O = 0  reserved for future use
                      P = 0  64 bit floating point numbers
                        = 1  32 bit floating point numbers
                        = 2  32 bit signed integers
                        = 3  16 bit signed integers
                        = 4  16 bit signed integers
                        = 5  8-bit unsigned integers
                      T = 0  numeric matrix
                        = 1  text matrix
                */
   int mrows;  /* row dimension */
   int ncols;  /* column dimension */
   int imagf;  /* flag indicating imag part
                   = 0  matrix is real,    
                   = 1  matrix is not real.
                */
   int namlen; /* name length (including NULL) */
} Fmatrix;



/*---------- Functions to read matrices from file -------------------------- */

LIBDS_API int amatRead (const char *fileName, Amatrix *matrix);
   /* Read single matrix from a file (there is just one matrix on the file
      and now class description)
      -> fileName: File name. 
      -> matrix  : All components of matrix must be initialized on input (use amatInit).
                   Checks are applied in the following way:
                   matrix.name != NULL      : Required name of matrix
                   matrix.nrow > 0          : Required number of rows.
                               = 0          : Number of rows is arbitrary (>= 0)
                               < 0          : Number of rows must be less than or
                                              equal to abs(matrix.nrow).
                   matrix.ncol > 0          : Required number of columns.
                               = 0          : Number of columns is arbitrary (>= 0)
                               < 0          : Number of columns must be less than or
                                              equal to abs(matrix.ncol).
                   matrix.type != voidMatrix: Required matrix type
                   matrix.data != NULL      : Storage provided for matrix. This requires
                                              that nrow!=0, ncol!=0, type!=voidMatrix.
                                              For type=charMatrix, only storage for a 
                                              vector of pointers is provided.
      <- matrix  : Matrix stored on file.
      <- RETURN  : = 0 : no error occured.
                   else: an error occured; the error message is stored
                         as (static) string in global variable "amatError".
   */




typedef struct {
   Amatrix *matrix;   /* matrix on file                                */
   int      req;      /* = 0: matrix may or may not be present on file */
                      /* = 1: matrix must be present on file           */
   int      rowDim;   /* = 0: rowDim and rowIndex are ignored          */
                      /* = 1: element rowIndex of Aclass vector must   */
                      /*      have the same row dimension.             */
                      /* = 2: element rowIndex of Aclass vector must   */
                      /*      have the same column dimension.          */
   int      colDim;   /* = 0: colDim and colIndex are ignored          */
                      /* = 1: element colIndex of Aclass vector must   */
                      /*      have the same row dimension.             */
                      /* = 2: element colIndex of Aclass vector must   */
                      /*      have the same column dimension.          */
   integer  rowIndex; /* Aclass index, if rowDim = 1 or 2              */
   integer  colIndex; /* Aclass index, if colDim = 1 or 2              */
   int      onFile;   /* = 0: matrix is NOT present on file            */
                      /* = 1: matrix is present on file                */
} AclassRead;



LIBDS_API int amatReadAll (const char *fileName, const char *classReq, const char *versionReq, 
                        AclassRead c[], integer dim_c);
   /* Read all matrices from a file.
      -> fileName  : Name of file.
      -> classReq  : = non-empty string: Required class name.
                     = NULL            : Class name is not checked.
      -> versionReq: = non-empty string: Required version number.
                     = NULL            : Version number is not checked.
      -> c         : c[i].matrix.name != NULL: Required name of matrix
                     c[i].matrix.nrow > 0    : Required number of rows.
                                      = 0    : Number of rows is arbitrary (>= 0)
                                      < 0    : Number of rows must be less than or
                                               equal to abs(c[i].matrix.nrow).
                     c[i].matrix.ncol > 0    : Required number of columns.
                                      = 0    : Number of columns is arbitrary (>= 0)
                                      < 0    : Number of columns must be less than or
                                               equal to abs(c[i].matrix.ncol).
                     c[i].matrix.type != voidMatrix: Required matrix type
                     c[i].matrix.data != NULL: Storage provided for matrix. This requires
                                               that nrow!=0, ncol!=0, type!=voidMatrix.
                                               For type=charMatrix, only storage for a 
                                               vector of pointers is provided.
                     c[i].rowDim > 0         : Row dimension depends on dimension of 
                                               another matrix (see Aclass).
                     c[i].colDim > 0         : Column dimension depends on dimension of
                                               another matrix (see Aclass).
      <- c         : The matrix-data read from file
                     c[i].onFile = 0: c[i] was not stored on file (or dimension was zero)
                                 = 1: c[i] was read from file.
      -> dim_c     : Dimension of vector c, i.e., c[dim_c]
                     (= number of matrices to be read from file).
      <- RETURN    : = 0: no error occured.
                     > 0: an error occured; the error message is stored
                          as (static) string in global variable "amatError". 
                     = 1: The first matrix on file is not a class description object.
                     = 2: Class-name is not equal to required one.
                     = 3: Version number is not equal to required one.
                     = 4: EOF reached.
                     = 5: Other error.
   */




typedef struct {
   char          *name;        /* name of file (used in error message) */
   FILE          *fp;          /* stream pointer to file               */
   AmatFileType   format;      /* file format (amatASCII/amatBinary)   */
   AmatBinStruct  bstruct;     /* required matrix reading format       */
   Amatrix        classInfo;   /* class information                    */
   int            header;      /* 0/1 header not/already read          */
   int            prec;        /* precision flag of Matlab matrix      */
   Amatrix        matrix;      /* auxiliary storage for last matrix    */
} AmatGetFile;


LIBDS_API int amatGetOpen (const char *fileName, const char *classReq, const char *versionReq, AmatGetFile *file);
   /* Open file for reading of matrices 
      -> fileName  : Name of file.
      -> classReq  : = non-empty string: Required name of class.
                     = "NoClass"       : No class description is stored on file,
                                         just open file for further reading.
                     = NULL            : Class name is not checked.
      -> versionReq: = non-empty string: Required version number.
                     = NULL            : Version number is not checked.
      <- file      : File identificator. Storage for the struct has to
                     be provided in the calling routine.
      <- RETURN    : = 0: no error occured.
                     > 0: an error occured; the error message is stored
                          as (static) string in global variable "amatError". 
                     = 1: The first matrix on file is not a class description object.
                     = 2: Class-name is not equal to required one.
                     = 3: Version number is not equal to required one.
                     = 4: EOF reached.
                     = 5: Other error.
   */     



LIBDS_API int amatReadAll2 (AmatGetFile *file, AclassRead c[], integer dim_c);
   /* Read all matrices from file defined by amatGetOpen and close file
      afterwards by a call to amatGetClose. This allows opening with
      amatGetOpen and check of class- or/and version number.
      -> file      : file identificator from amatGetOpen.
      -> c         : c[i].matrix.name != NULL: Required name of matrix
                     c[i].matrix.nrow > 0    : Required number of rows.
                                      = 0    : Number of rows is arbitrary (>= 0)
                                      < 0    : Number of rows must be less than or
                                               equal to abs(c[i].matrix.nrow).
                     c[i].matrix.ncol > 0    : Required number of columns.
                                      = 0    : Number of columns is arbitrary (>= 0)
                                      < 0    : Number of columns must be less than or
                                               equal to abs(c[i].matrix.ncol).
                     c[i].matrix.type != voidMatrix: Required matrix type
                     c[i].matrix.data != NULL: Storage provided for matrix. This requires
                                               that nrow!=0, ncol!=0, type!=voidMatrix.
                                               For type=charMatrix, only storage for a 
                                               vector of pointers is provided.
                     c[i].rowDim > 0         : Row dimension depends on dimension of 
                                               another matrix (see Aclass).
                     c[i].colDim > 0         : Column dimension depends on dimension of
                                               another matrix (see Aclass).
      <- c         : The matrix-data read from file
                     c[i].onFile = 0: c[i] was not stored on file (or dimension was zero).
                                 = 1: c[i] was read from file.
      -> dim_c     : Dimension of vector c, i.e., c[dim_c]
                     (= number of matrices to be read from file).
      <- RETURN    : = 0: no error occured.
                     > 0: an error occured; the error message is stored
                          as (static) string in global variable "amatError". 
                     = 1: The first matrix on file is not a class description object.
                     = 2: Class-name is not equal to required one.
                     = 3: Version number is not equal to required one.
                     = 4: EOF reached.
                     = 5: Other error.
   */

LIBDS_API void amatGetClose (AmatGetFile *file);
   /* Close file and release allocated storage
      -> file: File identificator.
   */

 
LIBDS_API char *amatGetClass (AmatGetFile *file);
   /* Get class name stored on file (the string is only
      returned for the first call. For all subsequent calls on the same
      file, "" is returned). The storage of the string must be freed
      with "free", when no longer needed.
   */

 
LIBDS_API char *amatGetDescr (AmatGetFile *file);
   /* Get description string stored on file (the string is only
      returned for the first call. For all subsequent calls on the same
      file, "" is returned). The storage of the string must be freed
      with "free", when no longer needed.
   */


 
LIBDS_API char *amatGetVersion (AmatGetFile *file);
   /* Get version string stored on file (the string is only
      returned for the first call. For all subsequent calls on the same
      file, "" is returned). The storage of the string must be freed
      with "free", when no longer needed.
   */


LIBDS_API int amatGetMatrix  (AmatGetFile *file, Amatrix *matrix);
LIBDS_API int amatGetMatrixP (AmatGetFile *file, Amatrix *matrix, AmatType typeReq);
LIBDS_API int amatGetMatrixP2 (AmatGetFile *file, Amatrix *matrixReq, AmatType typeReq, const fpos_t*dataCont);
LIBDS_API int amatGetMatrixP3 (AmatGetFile *file, Amatrix *matrixReq, AmatType typeReq, const fpos_t*dataCont,int removeTrailingSpace);
   /* Read next matrix from file. 
      -> file   : File identificator.
      -> matrix : All components of matrix must be initialized on input (use amatInit).
                  Checks are applied in the following way:
                  matrix.name != NULL      : Required name of matrix
                                             (matrix.name will not be changed).
                  matrix.nrow != 0         : Required number of rows 
                                             (matrix.nrow will not be changed).
                  matrix.ncol != 0         : Required number of columns 
                                             (matrix.ncol will not be changed).
                  matrix.type != voidMatrix: Required matrix type
                                             (matrix.type will not be changed).
                  matrix.data != NULL      : Storage provided for matrix. This requires
                                             that nrow!=0, ncol!=0, type!=voidMatrix.
                                             For type=charMatrix, only storage for a 
                                             vector of pointers is provided.
      <- matrix : Next matrix from file.
      -> typeReq: If matrix.type == voidMatrix, read a "real" or "doublereal"
                  matrix in precision typeReq. Otherwise ignore this argument.
                  (typeReq = realMatrix/doubleMatrix).
      <- RETURN : = 0: No error occured.
                  > 0: An error occured. An error message is stored
                       as (static) string in global variable "amatError".
                  = 1: The matrix on file has zero dimensions (nrow*ncol=0)
                       (required matrix name and type already have been checked).
                  = 2: The matrix on file does not have the required attributes.
                  = 3: End-of-File reached (file was already at EOF when calling this
                       function).
                  = 4: Another error occured.
   */


LIBDS_API char *amatGetName (AmatGetFile *file, int *eof);
   /* Read name of next matrix from file. By a subsequent call of amatGetMatrix or
      amatGetMatrixP the rest of the next matrix is read. Hereby it is assumed
      that matrix.name points to the name given by amatGetName.
      -> file  : File identificator.
      <- eof   : = 0: No END-OF-FILE encountered.
                 = 1: END-OF-FILE encountered (file was already positioned at EOF
                      when calling this function).
      <- RETURN: Pointer to string containing the name of the next matrix.
                 The storage for the string is allocated in amatGetName.
                 An error occured when a NULL pointer is returned. An error message
                 is stored as (static) string in global variable "amatError".
   */



/*---------- Functions to write matrices to file --------------------------- */

LIBDS_API int amatWrite (char *fileName, AmatFileType ftype, Amatrix matrix);
   /* Write matrix on file
      -> fileName: Name of file.
      -> ftype   : Storage type on file (amatASCII or amatBinary).
      -> matrix  : Matrix to be stored on file.
      <- RETURN  : = 0 : no error occurs.
                   else: an error occured; the error message is stored
                         as (static) string in global variable "amatError".
   */



typedef struct {
   Amatrix *matrix;     /* matrix to be written to file                          */
   int      nblank;     /* Number of leading blanks (including comment sign '#') */
                        /* used for elemDescr. If nblank=0, no blanks and no     */
                        /* comment sign is written (the comment sign has to be   */
                        /* present in elemDescr).                                */
   const char   *const*elemDescr;  /* Vector of strings. Every string is written as comment */
                        /* after the corresponding element. Row dimension of     */
                        /* elemDescr = matrix.nrow.                              */
                        /* If elemDescr=NULL, no text is written.                */
   const char    *matDescr;   /* Text written as comment before declaration of matrix  */
} AclassWrite;


LIBDS_API int amatWriteAll (const char *fileName, AmatFileType ftype, char *className,
                         char *version, char *descr, AclassWrite c[], integer dim_c);
   /* Write all matrices on file.
      -> fileName : Name of file.
      -> ftype    : Storage type on file (amatASCII or amatBinary).
      -> className: Class name. If className="", no class description is stored 
                    on file.
      -> version  : Version number.
      -> descr    : Description text.
      -> c        : Matrices "c[i].matrix" are written on file.
      -> dim_c    : Dimension of vector c, i.e., c[dim_c]
                    (= number of matrices to be written to file).
      <- RETURN   : = 0 : no error occurs.
                    else: an error occured; the error message is stored
                          as (static) string in global variable "amatError".
   */




typedef struct {
   /* Defined by amatPutOpen (always needed) */
      char          *name;      /* Name of file (used in error message)       */
      FILE          *fp;        /* Pointer to stream                          */
      AmatFileType   format;    /* Desired file format                        */
      AmatBinStruct  bstruct;   /* Required matrix writing format             */
      int            noRow;     /* = 0/1 not/allowed to used amatPutRxxx      */

   /* Defined by amatPutRinit (row-wise writing of matrix) */
      Fmatrix        x;         /* Info about matrix needed from Matlab       */
      char          *matName;   /* Name of matrix (used in error message)     */
      fpos_t         posHead;   /* Position in stream, where header is placed */
      AmatType       type;      /* Matrix type                                */
      integer        ncol;      /* Number of output columns                   */
      integer        nrowAct;   /* Actual number of rows written to file      */
	  /* In order to also update end-time for terminated simulations */
	  int            updateEnd;  /* 0 no update, 1 catch time pos, 2 write it */
	  fpos_t         posEndTime;
	  double         endTime;
	  AmatType       endTimeType;
} AmatPutFile;


LIBDS_API int amatPutOpen (const char *fileName, AmatFileType ftype, AmatBinStruct bstruct,
                        char *className, char *version, char *descr, AmatPutFile *file);
   /* Open file for writing of matrices (amatPutOpen opens the file and writes
      the text matrix "Aclass" containing the classname, version-number and
      description text)
      -> fileName: Name of file to be opened. An existing file is destroyed.
                   If fileName="", output is done on standard output
                   (in this case functions amatputRxxx for row-wise writing 
                   of matrices cannot be used).
      -> ftype   : Storage type on file (amatASCII or amatBinary).
      -> bstruct : = binNormal: Normal storage of matrices.
                   = binTrans : Matrices are stored in transposed format.
                                This is a prerequisite in order to use amatPutRxxx
                                in binary storage mode.
      -> className: Class name. If className="", no class description is stored 
                   on file.
      -> version : Version number.
      -> descr   : Description text.
      <- file    : File identificator.
      <- RETURN  : = 0 : no error occurs.
                   else: an error occured; the error message is stored
                         as (static) string in global variable "amatError".
   */



LIBDS_API void amatPutClose (AmatPutFile *file);
   /* Close file and free allocated storage */


LIBDS_API void amatPutConnect(FILE *fp, char *fileName, AmatPutFile *file);
   /* Connect an open ASCII-stream to an AmatPutFile structure.
      After connecting, the other functions of this package can be
      used via "file". It is not allowed to use "amatPutClose".
      -> fp      : Open ASCII output stream.
      -> fileName: Name of output file.
      <- file    : Initialized matPutFile structure
                   (fp and fileName are referenced within file but not copied)
   */
               

LIBDS_API int amatPutMatrix (AmatPutFile *file, Amatrix matrix);
   /* Write matrix to file
      -> file  : File identificator
      -> matrix: Matrix to be written to file
      <- RETURN  : = 0 : no error occurs.
                   else: an error occured; the error message is stored
                         as (static) string in global variable "amatError".
   */

LIBDS_API int amatPutMatrixPadding(AmatPutFile *file, Amatrix matrix,char padForText);
   /* Write matrix to file
      -> file  : File identificator
      -> matrix: Matrix to be written to file
	  -> padForText: In binary mode for text: use this character for padding.
      <- RETURN  : = 0 : no error occurs.
                   else: an error occured; the error message is stored
                         as (static) string in global variable "amatError".
   */


LIBDS_API int amatPutMatrixD (AmatPutFile *file, Amatrix matrix, const char *matDescr,
                           const char *const elemDescr[], int nblank);
   /* Write matrix to file. If data is written in ASCII format, include
      a verbal description of the matrix and of its elements. The element description
      texts (elemDescr) are ignored for character matrices (matrix.type = charMatrix).
      -> file     : File identificator
      -> matrix   : Matrix to be written to file
      -> matDescr : Text written as comment before declaration of matrix
                    (if matDescr=NULL or matDescr="\0", no comment is written).
      -> elemDescr: Vector of strings. Every string is written as comment after the
                    corresponding element. Row dimension of elemDescr = matrix.nrow.
                    If elemDescr=NULL, no text is written.
      -> nblank   : Number of leading blanks (including comment sign '#') used
                    for elemDescr. If nblank=0, no blanks and no comment sign is 
                    written (the comment sign has to be present in elemDescr).
      <- RETURN   : = 0 : no error occurs.
                    else: an error occured; the error message is stored
                          as (static) string in global variable "amatError".
   */
      


LIBDS_API int amatPutRinit (AmatPutFile *file, const char *name, integer ncol, AmatType type);
   /* Initialize writing of numeric matrix row-wise to file
      -> file  : File identificator.
      -> name  : Name of matrix.
      -> ncol  : Column-dimension of matrix.
      -> type  : Type of matrix on file (realMatrix, doubleMatrix).
      <- RETURN: = 0 : no error occurs.
                 else: an error occured; the error message is stored
                       as (static) string in global variable "amatError".
   */
    


LIBDS_API int amatPutRclose (AmatPutFile *file);
   /* Close row-wise writing of matrix
      -> file  : File identificator.
      <- RETURN: = 0 : no error occurs.
                 else: an error occured; the error message is stored
                       as (static) string in global variable "amatError".
   */


LIBDS_API int amatPutRreal   (AmatPutFile *file, const real       row[]);
LIBDS_API int amatPutRdouble (AmatPutFile *file, const doublereal row[]);
   /* Write row to file
      -> file  : File identificator.
      -> row   : Row to be written to file. The dimension of the vector was
                 defined by argument ncol of amatPutRinit.
      <- RETURN: = 0 : no error occurs.
                 else: an error occured; the error message is stored
                       as (static) string in global variable "amatError".
   */




/*---------- Utility functions --------------------------------------------- */

DYMOLA_STATIC LIBDS_API_AFTER Amatrix *amatNew(void);
    /* Generate a new Amatrix object */


DYMOLA_STATIC LIBDS_API_AFTER void amatInit(Amatrix *mat);

    /* Initialize an Amatrix object */


DYMOLA_STATIC LIBDS_API_AFTER void amatInitValue(char *name, integer nrow, integer ncol,
                          AmatType type, AmatData data, Amatrix *mat);
    /* Initialize an Amatrix object with the specified values.
       -> name: stored in mat.name.
       -> nrow: stored in mat.nrow.
       -> ncol: stored in mat.ncol.
       -> type: stored in mat.type.
       -> data: stored in mat.data
       <- mat : initialized object
    */
    

DYMOLA_STATIC LIBDS_API_AFTER void amatDel (Amatrix *mat);
    /* Delete storage of the components of matrix mat */


DYMOLA_STATIC LIBDS_API_AFTER char **amatTextGen (char *name, integer nrow);

    /* Generate default text

       -> name  : Name used to build strings.
       -> nrow  : Required number of rows of text.
       <- RETURN: Vector of string pointers.
                  Element i of text gets the value "name<i+1>".
                   E.g. if name="col_", text[3]="col_4".
    */


DYMOLA_STATIC LIBDS_API_AFTER char **amatTextResize (char *text[], integer nrowIn, integer nrowOut,
                              char *name);
    /* Resize text

       -> text   : Text to be resized.
       -> nrowIn : Row dimension of text on entry.
       -> nrowOut: Desired row dimension of text on return;
       -> name   : Name used to build default names of new elements
                   (if text vector is enlarged).
       <- RETURN : Pointer to resized vector.
    */


DYMOLA_STATIC LIBDS_API_AFTER void amatTextDel (char *text[], integer nrow);
    /* Delete text

       -> text: Pointer to vector of string pointers.
                On return, the storage for the vector and for all of the
                strings is freed.
       -> nrow: Row dimension of vector.
    */


DYMOLA_STATIC LIBDS_API_AFTER int amatTextFind (Amatrix tmat, const char *str);

   /* Find C-index of string "str" within text field of "tmat".

      -> tmat  : Textmatrix.
      -> str   : String to be searched.
      <- RETURN: Returns index i >= 0, if tmat.data.c[i] = str, or
                 i=-1 if "str" is not contained in tmat.
   */ 


DYMOLA_STATIC LIBDS_API_AFTER integer *amatTextIndex(Amatrix tmat1, Amatrix tmat2, int message);
    /* Build index from two text objects. 

       -> tmat1  : Reference text object 
                   (row dimension >= row dimension of tmat2).
       -> tmat2  : Text object which contains a subset of the names stored
                   in "tmat1".
       -> message: = 0: if name tmat2[i] is not present in tmat1, set vec[i]=-1.
                   = 1: if name tmat2[i] is not present in tmat1 store an
                        error message in amatError and return NULL.
       <- RETURN : Pointer to integer vector (named "vec" in the following)
                   with the same row dimension as tmat2.
                   vec[i] is the row number of "tmat1" which has the 
                   same name as "tmat2" at row "i".
                   If an error occurred, NULL is returned.
    */

#ifdef __cplusplus
}
#endif
#endif
