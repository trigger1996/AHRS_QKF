/*
 * File: ekf_func_quad_6dof.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 17-Jun-2018 20:30:18
 */

#ifndef EKF_FUNC_QUAD_6DOF_H
#define EKF_FUNC_QUAD_6DOF_H

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
extern void ekf_func_quad_6dof(double X[7], double P[49], const double acc[3],
  const double gyro[3], const double mag[3], double dt, const double Q[49],
  const double R[36]);

#endif

/*
 * File trailer for ekf_func_quad_6dof.h
 *
 * [EOF]
 */
