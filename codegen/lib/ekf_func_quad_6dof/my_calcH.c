/*
 * File: my_calcH.c
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
 * CALCH
 *     H = CALCH(BX,BZ,Q0,Q1,Q2,Q3)
 * Arguments    : double bx
 *                double bz
 *                double q0
 *                double q1
 *                double q2
 *                double q3
 *                double H[42]
 * Return Type  : void
 */
void my_calcH(double bx, double bz, double q0, double q1, double q2, double q3,
              double H[42])
{
  double t2;
  double t3;
  double t4;
  double t13;
  double t5;
  double t8;
  double t9;
  double t12;
  double t14;
  double b_t3[42];
  int i0;
  int i1;

  /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
  /*     17-Jun-2018 00:29:49 */
  t2 = q0 * 2.0;
  t3 = q2 * 2.0;
  t4 = bz * q1 * 2.0;
  t13 = bx * q3 * 2.0;
  t5 = t4 - t13;
  t8 = bx * q1 * 2.0 + bz * q3 * 2.0;
  t9 = bx * q0 * 2.0;
  t12 = bx * q2 * 2.0 + bz * q0 * 2.0;
  t14 = bz * q2 * 2.0;
  b_t3[0] = t3;
  b_t3[1] = q1 * -2.0;
  b_t3[2] = -t2;
  b_t3[3] = t9 - bz * q2 * 2.0;
  b_t3[4] = t5;
  b_t3[5] = t12;
  b_t3[6] = q3 * -2.0;
  b_t3[7] = -t2;
  b_t3[8] = q1 * 2.0;
  b_t3[9] = t8;
  b_t3[10] = t12;
  b_t3[11] = -t4 + t13;
  b_t3[12] = t2;
  b_t3[13] = q3 * -2.0;
  b_t3[14] = t3;
  b_t3[15] = bx * q2 * -2.0 - bz * q0 * 2.0;
  b_t3[16] = t8;
  b_t3[17] = t9 - t14;
  b_t3[18] = q1 * -2.0;
  b_t3[19] = -t3;
  b_t3[20] = q3 * -2.0;
  b_t3[21] = t5;
  b_t3[22] = -t9 + t14;
  b_t3[23] = t8;
  memset(&b_t3[24], 0, 18U * sizeof(double));
  for (i0 = 0; i0 < 7; i0++) {
    for (i1 = 0; i1 < 6; i1++) {
      H[i1 + 6 * i0] = b_t3[i1 + 6 * i0];
    }
  }
}

/*
 * File trailer for my_calcH.c
 *
 * [EOF]
 */
