/*
 * File: mrdivide.c
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
#include "mrdivide.h"

/* Function Definitions */

/*
 * Arguments    : double A[42]
 *                const double B[36]
 * Return Type  : void
 */
void mrdivide(double A[42], const double B[36])
{
  double b_A[36];
  int k;
  int j;
  signed char ipiv[6];
  int c;
  int jAcol;
  int jy;
  int ix;
  double smax;
  int iy;
  int i;
  double s;
  memcpy(&b_A[0], &B[0], 36U * sizeof(double));
  for (k = 0; k < 6; k++) {
    ipiv[k] = (signed char)(1 + k);
  }

  for (j = 0; j < 5; j++) {
    c = j * 7;
    jAcol = 0;
    ix = c;
    smax = fabs(b_A[c]);
    for (k = 2; k <= 6 - j; k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        jAcol = k - 1;
        smax = s;
      }
    }

    if (b_A[c + jAcol] != 0.0) {
      if (jAcol != 0) {
        ipiv[j] = (signed char)((j + jAcol) + 1);
        ix = j;
        iy = j + jAcol;
        for (k = 0; k < 6; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      k = (c - j) + 6;
      for (i = c + 1; i + 1 <= k; i++) {
        b_A[i] /= b_A[c];
      }
    }

    iy = c;
    jy = c + 6;
    for (jAcol = 1; jAcol <= 5 - j; jAcol++) {
      smax = b_A[jy];
      if (b_A[jy] != 0.0) {
        ix = c + 1;
        k = (iy - j) + 12;
        for (i = 7 + iy; i + 1 <= k; i++) {
          b_A[i] += b_A[ix] * -smax;
          ix++;
        }
      }

      jy += 6;
      iy += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jy = 7 * j;
    jAcol = 6 * j;
    for (k = 1; k <= j; k++) {
      iy = 7 * (k - 1);
      if (b_A[(k + jAcol) - 1] != 0.0) {
        for (i = 0; i < 7; i++) {
          A[i + jy] -= b_A[(k + jAcol) - 1] * A[i + iy];
        }
      }
    }

    smax = 1.0 / b_A[j + jAcol];
    for (i = 0; i < 7; i++) {
      A[i + jy] *= smax;
    }
  }

  for (j = 5; j >= 0; j--) {
    jy = 7 * j;
    jAcol = 6 * j;
    for (k = j + 1; k + 1 < 7; k++) {
      iy = 7 * k;
      if (b_A[k + jAcol] != 0.0) {
        for (i = 0; i < 7; i++) {
          A[i + jy] -= b_A[k + jAcol] * A[i + iy];
        }
      }
    }
  }

  for (jAcol = 4; jAcol >= 0; jAcol--) {
    if (ipiv[jAcol] != jAcol + 1) {
      iy = ipiv[jAcol] - 1;
      for (jy = 0; jy < 7; jy++) {
        smax = A[jy + 7 * jAcol];
        A[jy + 7 * jAcol] = A[jy + 7 * iy];
        A[jy + 7 * iy] = smax;
      }
    }
  }
}

/*
 * File trailer for mrdivide.c
 *
 * [EOF]
 */
