/*
 * File: my_quatmul.c
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
 * %%四元数相乘
 * Arguments    : const double q1[4]
 *                const double q2[4]
 *                double q[4]
 * Return Type  : void
 */
void my_quatmul(const double q1[4], const double q2[4], double q[4])
{
  /*     %%四元数相乘 */
  q[0] = ((q1[0] * q2[0] - q1[1] * q2[1]) - q1[2] * q2[2]) - q1[3] * q2[3];
  q[1] = ((q1[1] * q2[0] + q1[0] * q2[1]) - q1[3] * q2[2]) + q1[2] * q2[3];
  q[2] = ((q1[2] * q2[0] + q1[3] * q2[1]) + q1[0] * q2[2]) - q1[1] * q2[3];
  q[3] = ((q1[3] * q2[0] - q1[2] * q2[1]) + q1[1] * q2[2]) + q1[0] * q2[3];

  /*      %%进行归一化处理 */
  /*      normQ = norm(d); */
  /*      q = d/normQ; */
}

/*
 * File trailer for my_quatmul.c
 *
 * [EOF]
 */
