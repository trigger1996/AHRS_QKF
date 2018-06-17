/*
 * File: my_ang2quat.c
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
 * %%旋转矢量转换为四元数
 * Arguments    : const double ang[3]
 *                double q[4]
 * Return Type  : void
 */
void my_ang2quat(const double ang[3], double q[4])
{
  double b_norm;
  int i;
  double f;
  b_norm = 0.0;
  for (i = 0; i < 3; i++) {
    b_norm += ang[i] * ang[i];
  }

  b_norm = sqrt(b_norm);
  if (b_norm > 1.0E-40) {
    f = sin(b_norm / 2.0) / b_norm;
  } else {
    f = 0.5;
  }

  q[0] = cos(b_norm / 2.0);
  for (i = 0; i < 3; i++) {
    q[i + 1] = f * ang[i];
  }
}

/*
 * File trailer for my_ang2quat.c
 *
 * [EOF]
 */
