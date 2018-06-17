/*
 * File: ekf_func_quad_6dof.c
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
#include "norm.h"
#include "mrdivide.h"

/* Function Definitions */

/*
 * Arguments    : double X[7]
 *                double P[49]
 *                const double acc[3]
 *                const double gyro[3]
 *                const double mag[3]
 *                double dt
 *                const double Q[49]
 *                const double R[36]
 * Return Type  : void
 */
void ekf_func_quad_6dof(double X[7], double P[49], const double acc[3], const
  double gyro[3], const double mag[3], double dt, const double Q[49], const
  double R[36])
{
  double q0;
  double q1;
  double q2;
  double q3;
  double scale;
  double absxk;
  double t;
  double bx;
  double b_X;
  double c_X;
  double d_X;
  double e_X;
  double f_X;
  double g_X;
  double h_X;
  double i_X;
  double j_X;
  double k_X;
  double l_X;
  double m_X;
  double n_X;
  double o_X;
  double p_X;
  double q_X;
  double r_X;
  double s_X;
  double t_X;
  double u_X;
  int k;
  double PHI[49];
  signed char I[49];
  int i2;
  double b_PHI[49];
  double cbn[9];
  int i3;
  double x[2];
  double mR[3];
  double H[42];
  double K[42];
  double b_H[36];
  double b_bx[3];
  double c_H[42];
  double b_cbn[3];
  double c_cbn[6];
  double d_cbn[6];
  double b_acc[6];
  static const signed char b[3] = { 0, 0, -1 };

  static const signed char b_I[49] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 1 };

  q0 = X[0];
  q1 = X[1];
  q2 = X[2];
  q3 = X[3];

  /*  gyro bias */
  /*  传感器模型 */
  /*  系统观测模型 */
  scale = X[1];
  absxk = X[0];
  t = X[4];
  bx = X[3];
  b_X = X[5];
  c_X = X[2];
  d_X = X[6];
  e_X = X[2];
  f_X = X[3];
  g_X = X[4];
  h_X = X[0];
  i_X = X[5];
  j_X = X[1];
  k_X = X[6];
  l_X = X[3];
  m_X = X[2];
  n_X = X[4];
  o_X = X[1];
  p_X = X[5];
  q_X = X[0];
  r_X = X[6];
  s_X = X[4];
  t_X = X[5];
  u_X = X[6];
  X[0] = ((X[0] - X[1] * (gyro[0] - X[4]) * dt / 2.0) - X[2] * (gyro[1] - X[5]) *
          dt / 2.0) - X[3] * (gyro[2] - X[6]) * dt / 2.0;
  X[1] = ((scale + absxk * (gyro[0] - t) * dt / 2.0) - bx * (gyro[1] - b_X) * dt
          / 2.0) + c_X * (gyro[2] - d_X) * dt / 2.0;
  X[2] = ((e_X + f_X * (gyro[0] - g_X) * dt / 2.0) + h_X * (gyro[1] - i_X) * dt /
          2.0) - j_X * (gyro[2] - k_X) * dt / 2.0;
  X[3] = ((l_X - m_X * (gyro[0] - n_X) * dt / 2.0) + o_X * (gyro[1] - p_X) * dt /
          2.0) + q_X * (gyro[2] - r_X) * dt / 2.0;
  X[4] = s_X;
  X[5] = t_X;
  X[6] = u_X;

  /*  四元数归一化 */
  scale = norm(*(double (*)[4])&X[0]);
  for (k = 0; k < 4; k++) {
    X[k] /= scale;
  }

  /*  状态转移矩阵 */
  /*  四元数更新    */
  /*  观测协方差更新 */
  for (k = 0; k < 49; k++) {
    I[k] = 0;
  }

  PHI[0] = 0.0 * dt;
  PHI[7] = -gyro[0] / 2.0 * dt;
  PHI[14] = -gyro[1] / 2.0 * dt;
  PHI[21] = -gyro[2] / 2.0 * dt;
  PHI[28] = q1 / 2.0 * dt;
  PHI[35] = q2 / 2.0 * dt;
  PHI[42] = q3 / 2.0 * dt;
  PHI[1] = gyro[0] / 2.0 * dt;
  PHI[8] = 0.0 * dt;
  PHI[15] = gyro[2] / 2.0 * dt;
  PHI[22] = -gyro[1] / 2.0 * dt;
  PHI[29] = -q0 / 2.0 * dt;
  PHI[36] = q3 / 2.0 * dt;
  PHI[43] = -q2 / 2.0 * dt;
  PHI[2] = gyro[1] / 2.0 * dt;
  PHI[9] = -gyro[2] / 2.0 * dt;
  PHI[16] = 0.0 * dt;
  PHI[23] = gyro[0] / 2.0 * dt;
  PHI[30] = -q3 / 2.0 * dt;
  PHI[37] = -q0 / 2.0 * dt;
  PHI[44] = q1 / 2.0 * dt;
  PHI[3] = gyro[2] / 2.0 * dt;
  PHI[10] = gyro[1] / 2.0 * dt;
  PHI[17] = -gyro[0] / 2.0 * dt;
  PHI[24] = 0.0 * dt;
  PHI[31] = q2 / 2.0 * dt;
  PHI[38] = -q1 / 2.0 * dt;
  PHI[45] = -q0 / 2.0 * dt;
  for (k = 0; k < 7; k++) {
    I[k + 7 * k] = 1;
    PHI[4 + 7 * k] = 0.0 * dt;
    PHI[5 + 7 * k] = 0.0 * dt;
    PHI[6 + 7 * k] = 0.0 * dt;
  }

  for (k = 0; k < 7; k++) {
    for (i2 = 0; i2 < 7; i2++) {
      b_PHI[i2 + 7 * k] = (double)I[i2 + 7 * k] + PHI[i2 + 7 * k];
    }
  }

  for (k = 0; k < 7; k++) {
    for (i2 = 0; i2 < 7; i2++) {
      PHI[k + 7 * i2] = 0.0;
      for (i3 = 0; i3 < 7; i3++) {
        PHI[k + 7 * i2] += b_PHI[k + 7 * i3] * P[i3 + 7 * i2];
      }
    }
  }

  for (k = 0; k < 7; k++) {
    for (i2 = 0; i2 < 7; i2++) {
      scale = 0.0;
      for (i3 = 0; i3 < 7; i3++) {
        scale += PHI[k + 7 * i3] * b_PHI[i2 + 7 * i3];
      }

      P[k + 7 * i2] = scale + Q[k + 7 * i2];
    }
  }

  /* %%% 这一坨看不懂	 */
  my_quat2cbn(*(double (*)[4])&X[0], cbn);
  for (k = 0; k < 3; k++) {
    mR[k] = 0.0;
    for (i2 = 0; i2 < 3; i2++) {
      mR[k] += cbn[k + 3 * i2] * mag[i2];
    }
  }

  x[0] = mR[0];
  x[1] = mR[1];
  bx = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 2; k++) {
    absxk = fabs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      bx = 1.0 + bx * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      bx += t * t;
    }
  }

  bx = scale * sqrt(bx);

  /* 计算预测值 */
  H[0] = 2.0 * X[2];
  H[6] = -2.0 * X[3];
  H[12] = 2.0 * X[0];
  H[18] = -2.0 * X[1];
  H[24] = 0.0;
  H[30] = 0.0;
  H[36] = 0.0;
  H[1] = -2.0 * X[1];
  H[7] = -2.0 * X[0];
  H[13] = -2.0 * X[3];
  H[19] = -2.0 * X[2];
  H[25] = 0.0;
  H[31] = 0.0;
  H[37] = 0.0;
  H[2] = -2.0 * X[0];
  H[8] = 2.0 * X[1];
  H[14] = 2.0 * X[2];
  H[20] = -2.0 * X[3];
  H[26] = 0.0;
  H[32] = 0.0;
  H[38] = 0.0;
  H[3] = 2.0 * (-2.0 * mR[2] * X[2]);
  H[9] = 2.0 * (2.0 * mR[2] * X[3]);
  H[15] = 2.0 * (-4.0 * bx * X[2] - 2.0 * mR[2] * X[0]);
  H[21] = 2.0 * (-4.0 * bx * X[3] + 2.0 * mR[2] * X[1]);
  H[27] = 0.0;
  H[33] = 0.0;
  H[39] = 0.0;
  H[4] = 2.0 * (-2.0 * bx * X[3] + 2.0 * mR[2] * X[1]);
  H[10] = 2.0 * (2.0 * bx * X[2] + 2.0 * mR[2] * X[0]);
  H[16] = 2.0 * (2.0 * bx * X[1] + 2.0 * mR[2] * X[3]);
  H[22] = 2.0 * (-2.0 * bx * X[0] + 2.0 * mR[2] * X[2]);
  H[28] = 0.0;
  H[34] = 0.0;
  H[40] = 0.0;
  H[5] = 2.0 * (2.0 * bx * X[2]);
  H[11] = 2.0 * (2.0 * bx * X[3] - 4.0 * mR[2] * X[1]);
  H[17] = 2.0 * (2.0 * bx * X[0] - 4.0 * mR[2] * X[2]);
  H[23] = 2.0 * (2.0 * bx * X[1]);
  H[29] = 0.0;
  H[35] = 0.0;
  H[41] = 0.0;

  /*  更新卡尔曼增益 */
  for (k = 0; k < 7; k++) {
    for (i2 = 0; i2 < 6; i2++) {
      K[k + 7 * i2] = 0.0;
      for (i3 = 0; i3 < 7; i3++) {
        K[k + 7 * i2] += P[k + 7 * i3] * H[i2 + 6 * i3];
      }
    }
  }

  for (k = 0; k < 6; k++) {
    for (i2 = 0; i2 < 7; i2++) {
      c_H[k + 6 * i2] = 0.0;
      for (i3 = 0; i3 < 7; i3++) {
        c_H[k + 6 * i2] += H[k + 6 * i3] * P[i3 + 7 * i2];
      }
    }

    for (i2 = 0; i2 < 6; i2++) {
      scale = 0.0;
      for (i3 = 0; i3 < 7; i3++) {
        scale += c_H[k + 6 * i3] * H[i2 + 6 * i3];
      }

      b_H[k + 6 * i2] = scale + R[k + 6 * i2];
    }
  }

  mrdivide(K, b_H);

  /*  卡尔曼更新阶段，公式3-5 */
  b_bx[0] = bx;
  b_bx[1] = 0.0;
  b_bx[2] = mR[2];
  for (k = 0; k < 3; k++) {
    mR[k] = 0.0;
    b_cbn[k] = 0.0;
    for (i2 = 0; i2 < 3; i2++) {
      mR[k] += cbn[i2 + 3 * k] * (double)b[i2];
      b_cbn[k] += cbn[i2 + 3 * k] * b_bx[i2];
    }

    b_acc[k] = acc[k];
    b_acc[k + 3] = mag[k];
    d_cbn[k] = mR[k];
    d_cbn[k + 3] = b_cbn[k];
  }

  for (k = 0; k < 6; k++) {
    c_cbn[k] = d_cbn[k] - b_acc[k];
  }

  /* 得到估计状态 */
  for (k = 0; k < 7; k++) {
    scale = 0.0;
    for (i2 = 0; i2 < 6; i2++) {
      scale += K[k + 7 * i2] * c_cbn[i2];
    }

    X[k] -= scale;
    for (i2 = 0; i2 < 7; i2++) {
      scale = 0.0;
      for (i3 = 0; i3 < 6; i3++) {
        scale += K[k + 7 * i3] * H[i3 + 6 * i2];
      }

      PHI[k + 7 * i2] = (double)b_I[k + 7 * i2] - scale;
    }

    for (i2 = 0; i2 < 7; i2++) {
      b_PHI[k + 7 * i2] = 0.0;
      for (i3 = 0; i3 < 7; i3++) {
        b_PHI[k + 7 * i2] += PHI[k + 7 * i3] * P[i3 + 7 * i2];
      }
    }
  }

  for (k = 0; k < 7; k++) {
    for (i2 = 0; i2 < 7; i2++) {
      P[i2 + 7 * k] = b_PHI[i2 + 7 * k];
    }
  }

  /*  更新协方差矩阵 */
  /*  归一化四元数 */
  scale = norm(*(double (*)[4])&X[0]);
  for (k = 0; k < 4; k++) {
    X[k] /= scale;
  }
}

/*
 * File trailer for ekf_func_quad_6dof.c
 *
 * [EOF]
 */
