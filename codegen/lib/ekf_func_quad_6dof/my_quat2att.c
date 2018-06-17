/*
 * File: my_quat2att.c
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

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * Arguments    : const double q_data[]
 *                const int q_size[2]
 *                double *roll
 *                double *pitch
 *                double *yaw
 * Return Type  : void
 */
void my_quat2att(const double q_data[], const int q_size[2], double *roll,
                 double *pitch, double *yaw)
{
  double q11;
  double q22;
  double q33;
  double q44;
  (void)q_size;
  q11 = q_data[0] * q_data[0];
  q22 = q_data[1] * q_data[1];
  q33 = q_data[2] * q_data[2];
  q44 = q_data[3] * q_data[3];
  *roll = rt_atan2d_snf(2.0 * (q_data[0] * q_data[1] + q_data[2] * q_data[3]),
                        ((q11 - q22) - q33) + q44);
  *pitch = asin(2.0 * (q_data[0] * q_data[2] - q_data[1] * q_data[3]));
  *yaw = rt_atan2d_snf(2.0 * (q_data[1] * q_data[2] + q_data[0] * q_data[3]),
                       ((q11 + q22) - q33) - q44);
}

/*
 * File trailer for my_quat2att.c
 *
 * [EOF]
 */
