#ifndef delay_h
#define delay_h

/*
 * Copyright (C) 1995-2006 Dynasim AB.
 * All rights reserved.
 *
 */

/* first implementation:
         Dieter Moormann (DLR), till Nov 14, 1995  */
/* modfied for use with derivatives also:
         Dieter Moormann (DLR), till May 24, 1996  */
/* improvements made for Dymola Version 3.1:
         Dieter Moormann (DLR), April 2, 1998  */
/* improvements made for Dymola Version 3.1b:
         Dag Bruck, Dynasim AB, October 5, 1998  */

/* These functions are to be used together with the Dymola model
   classes <FixDelay>, <VarDelay>, and <Derivative>. 

   The time <Time> and the input <u> are written into a circular buffer.
                                                             
Delay:
   At start time the <Time> is set to the negative value of the
   delaytime, which is specified by the parameter <DelayTime>, <u> is 
   given its initial value.

   After the start of the integration, only pairs of <Time> and <u>
   are stored in the buffer, when the time has increased from the
   last value. If the integrator has move backwards, the old (now
   invalid) values will be overwritten by the new ones. This guarantees,
   that the time is allways increasing ( = that the history of the 
   buffer is always correct).

   If the end of the buffer is reached, the new pair of <Time> and <u>
   is stored at the first postion of the buffer (circular buffer).


   The output <y> is interpolated from the buffer at the <Time> reduced
   by the <DelayTime> by linear interpolation.

     DelayedTime = Time - DelayTime
 
   At that time <DelayedTime>, the interpolation is performed:

                                             ( u(t_up) - ul(t_low) )
     y = u(t_low) + (DelayedTime - t_low) * ------------------------
                                             (   t_up  -  t_low    )

     with:    t_low  <  DelayedTime  <=  t_up

   If the <DelayedTime> is smaller than the lowest time in the buffer,
   the value is extrapolated from the two lowest values of the buffer.

   If the <DelayedTime> is bigger than the highest time in the buffer,
   the value is extrapolated from the two highest values of the buffer.
   This can happen, when the delaytime is negative ("extrapolation into
   future")

   The buffersize is fixed to the value specified by the parameter 
   <Buffersize> in the Dymola model class <Delay>.

   In the current version the Delay Block is realized as SISO system.

Derivative:

          ( u(t_up) - ul(t_low) )
     y =  ------------------------
          (   t_up  -  t_low    )

   In the current version the Derivative block is realized as SISO system.
*/
#include "libdssetup.h"
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

DYMOLA_STATIC LIBDS_API_AFTER int delayIni2(delayStruct * del, int delayID, double delaytime, int buffer, double startTime, double u);

/* Function is called from the Dymola generated code for each <Delay>
during initialisation. It allocates the storage for each delay of the model
and sets its inital conditions.
*/

DYMOLA_STATIC LIBDS_API_AFTER double delayFunction2(delayStruct * del, int idd, double delaytime, double maxDelayTime, double t, double u, const char*str);
/* Function is called from the Dymola generated code for each <Delay>.
It puts the current value of Time <t> and Input <u> in the buffer
of the Delay with the identifyer <idd>. It returns the interpolated
value of the delayed time
*/

DYMOLA_STATIC LIBDS_API_AFTER double delayWrite2(delayStruct * del, int id, double t, double u);
/* Function is called from <delayfunc>.
It puts the current value of Time <t> and Input <u> in the buffer
of the Delay with the identifyer <idd>. The function returns the
unchanged input <u>.
*/

DYMOLA_STATIC LIBDS_API_AFTER double delayRead2(delayStruct * del, int id, double delaytime, double t);
/* Function is called from <delayfunc>.
It returns the interpolated value of the Delay with the
identifyer <idd> of the delayed time.
*/

DYMOLA_STATIC LIBDS_API_AFTER double delayDDFunction2(delayStruct * del, double expr, double dt, int *isAllocated, int delayId, int BufferSize, double Time, int Event, int*timed);
DYMOLA_STATIC LIBDS_API_AFTER double delayDCFunction2(delayStruct * del, double expr, double dt, int *isAllocated, int delayId, int BufferSize, double Time, int Event,
	double*rel, double*qp, double*qn, int*qen, double*qz2, int*AnyEvent);

DYMOLA_STATIC LIBDS_API_AFTER int transportIni2(delayStruct * del, int delayID, int buffer, double startX, double u);
DYMOLA_STATIC LIBDS_API_AFTER void transportGet2(delayStruct * del, double T1, double T2, double x, int vs, int id, double*Tf1, double*Tf2);
DYMOLA_STATIC LIBDS_API_AFTER void transportPut2(delayStruct * del, double T1, double T2, double x, int vs, int id);
#if 0
DYMOLA_STATIC LIBDS_API_AFTER void transportFunction(delayStruct * del, double T1, double T2, double x, int vs, int id, double*Tf1, double*Tf2);
#endif
DYMOLA_STATIC LIBDS_API_AFTER void transportFunction3(delayStruct * del, double T1, double T2, double x, int vs, int id, double*Tf1, double*Tf2, int doStore);
DYMOLA_STATIC LIBDS_API_AFTER int copyDelay(delayStruct tgt[], delayStruct src[], const int nbrDel);
DYMOLA_STATIC LIBDS_API_AFTER void freeDelay(delayStruct* del, const size_t nbrDel);
DYMOLA_STATIC LIBDS_API_AFTER int allocDelayBuffers(delayStruct* del, const size_t nbrDel, const int buffer);
#endif
