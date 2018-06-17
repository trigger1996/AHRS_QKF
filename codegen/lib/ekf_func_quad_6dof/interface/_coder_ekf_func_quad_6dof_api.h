/*
 * File: _coder_ekf_func_quad_6dof_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 17-Jun-2018 20:30:18
 */

#ifndef _CODER_EKF_FUNC_QUAD_6DOF_API_H
#define _CODER_EKF_FUNC_QUAD_6DOF_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_ekf_func_quad_6dof_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void ekf_func_quad_6dof(real_T X[7], real_T P[49], real_T acc[3], real_T
  gyro[3], real_T mag[3], real_T dt, real_T Q[49], real_T R[36]);
extern void ekf_func_quad_6dof_api(const mxArray *prhs[8], const mxArray *plhs[2]);
extern void ekf_func_quad_6dof_atexit(void);
extern void ekf_func_quad_6dof_initialize(void);
extern void ekf_func_quad_6dof_terminate(void);
extern void ekf_func_quad_6dof_xil_terminate(void);
extern void my_ang2quat(real_T ang[3], real_T q[4]);
extern void my_ang2quat_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
extern void my_calcH(real_T bx, real_T bz, real_T q0, real_T q1, real_T q2,
                     real_T q3, real_T H[42]);
extern void my_calcH_api(const mxArray * const prhs[6], const mxArray *plhs[1]);
extern void my_quat2att(real_T q_data[], int32_T q_size[2], real_T *roll, real_T
  *pitch, real_T *yaw);
extern void my_quat2att_api(const mxArray * const prhs[1], const mxArray *plhs[3]);
extern void my_quat2cbn(real_T q[4], real_T cbn[9]);
extern void my_quat2cbn_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
extern void my_quatmul(real_T q1[4], real_T q2[4], real_T q[4]);
extern void my_quatmul_api(const mxArray * const prhs[2], const mxArray *plhs[1]);

#endif

/*
 * File trailer for _coder_ekf_func_quad_6dof_api.h
 *
 * [EOF]
 */
