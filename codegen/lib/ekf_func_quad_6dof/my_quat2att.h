/*
 * File: my_quat2att.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 17-Jun-2018 20:30:18
 */

#ifndef MY_QUAT2ATT_H
#define MY_QUAT2ATT_H

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
extern void my_quat2att(const double q_data[], const int q_size[2], double *roll,
  double *pitch, double *yaw);

#endif

/*
 * File trailer for my_quat2att.h
 *
 * [EOF]
 */
