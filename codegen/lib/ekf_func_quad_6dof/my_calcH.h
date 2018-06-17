/*
 * File: my_calcH.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 17-Jun-2018 20:30:18
 */

#ifndef MY_CALCH_H
#define MY_CALCH_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ekf_func_quad_6dof_types.h"

/* Function Declarations */
extern void my_calcH(double bx, double bz, double q0, double q1, double q2,
                     double q3, double H[42]);

#endif

/*
 * File trailer for my_calcH.h
 *
 * [EOF]
 */
