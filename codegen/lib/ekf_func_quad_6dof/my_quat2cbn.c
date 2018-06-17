/*
 * File: my_quat2cbn.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 17-Jun-2018 20:30:18
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "ekf_func_quad_6dof.h"
#include "my_ang2quat.h"
#include "my_calcH.h"
#include "my_quat2att.h"
#include "my_quat2cbn.h"
#include "my_quatmul.h"

/* Function Definitions */

/*
 * Arguments    : const double q[4]
 *                double cbn[9]
 * Return Type  : void
 */
void my_quat2cbn(const double q[4], double cbn[9])
{
  double q11;
  double q12;
  double q13;
  double q14;
  double q22;
  double q23;
  double q24;
  double q33;
  double q34;
  double q44;
  q11 = q[0] * q[0];
  q12 = q[0] * q[1];
  q13 = q[0] * q[2];
  q14 = q[0] * q[3];
  q22 = q[1] * q[1];
  q23 = q[1] * q[2];
  q24 = q[1] * q[3];
  q33 = q[2] * q[2];
  q34 = q[2] * q[3];
  q44 = q[3] * q[3];
  cbn[0] = ((q11 + q22) - q33) - q44;
  cbn[3] = 2.0 * (q23 - q14);
  cbn[6] = 2.0 * (q24 + q13);
  cbn[1] = 2.0 * (q23 + q14);
  cbn[4] = ((q11 - q22) + q33) - q44;
  cbn[7] = 2.0 * (q34 - q12);
  cbn[2] = 2.0 * (q24 - q13);
  cbn[5] = 2.0 * (q34 + q12);
  cbn[8] = ((q11 - q22) - q33) + q44;
}

/*
 * File trailer for my_quat2cbn.c
 *
 * [EOF]
 */
