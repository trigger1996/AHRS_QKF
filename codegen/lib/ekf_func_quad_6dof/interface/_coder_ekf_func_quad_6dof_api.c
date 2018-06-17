/*
 * File: _coder_ekf_func_quad_6dof_api.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 17-Jun-2018 20:30:18
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_ekf_func_quad_6dof_api.h"
#include "_coder_ekf_func_quad_6dof_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "ekf_func_quad_6dof",                /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7];
static void b_emlrt_marshallOut(const real_T u[49], const mxArray *y);
static real_T (*bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P, const
  char_T *identifier))[49];
static const mxArray *c_emlrt_marshallOut(const real_T u[4]);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[49];
static const mxArray *d_emlrt_marshallOut(const real_T u[42]);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *acc,
  const char_T *identifier))[3];
static const mxArray *e_emlrt_marshallOut(const real_T u);
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[7];
static void emlrt_marshallOut(const real_T u[7], const mxArray *y);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static const mxArray *f_emlrt_marshallOut(const real_T u[9]);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dt, const
  char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R, const
  char_T *identifier))[36];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[36];
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ang,
  const char_T *identifier))[3];
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q, const
  char_T *identifier))[4];
static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4];
static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q1,
  const char_T *identifier))[4];
static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4];
static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7];
static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[49];
static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[36];
static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[4]
 */
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  real_T (*ret)[4];
  static const int32_T dims[1] = { 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[7]
 */
  static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[7]
{
  real_T (*y)[7];
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[49]
 *                const mxArray *y
 * Return Type  : void
 */
static void b_emlrt_marshallOut(const real_T u[49], const mxArray *y)
{
  static const int32_T iv1[2] = { 7, 7 };

  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, iv1, 2);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[4]
 */
static real_T (*bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  real_T (*ret)[4];
  static const int32_T dims[2] = { 1, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *P
 *                const char_T *identifier
 * Return Type  : real_T (*)[49]
 */
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P,
  const char_T *identifier))[49]
{
  real_T (*y)[49];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(P), &thisId);
  emlrtDestroyArray(&P);
  return y;
}

/*
 * Arguments    : const real_T u[4]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u[4])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv2[1] = { 0 };

  static const int32_T iv3[1] = { 4 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv2, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv3, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[49]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[49]
{
  real_T (*y)[49];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u[42]
 * Return Type  : const mxArray *
 */
  static const mxArray *d_emlrt_marshallOut(const real_T u[42])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv4[2] = { 0, 0 };

  static const int32_T iv5[2] = { 6, 7 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv4, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, iv5, 2);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *acc
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *acc,
  const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(acc), &thisId);
  emlrtDestroyArray(&acc);
  return y;
}
/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
  static const mxArray *e_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *X
 *                const char_T *identifier
 * Return Type  : real_T (*)[7]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[7]
{
  real_T (*y)[7];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(X), &thisId);
  emlrtDestroyArray(&X);
  return y;
}
/*
 * Arguments    : const real_T u[7]
 *                const mxArray *y
 * Return Type  : void
 */
  static void emlrt_marshallOut(const real_T u[7], const mxArray *y)
{
  static const int32_T iv0[1] = { 7 };

  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, iv0, 1);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u[9]
 * Return Type  : const mxArray *
 */
  static const mxArray *f_emlrt_marshallOut(const real_T u[9])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv6[2] = { 0, 0 };

  static const int32_T iv7[2] = { 3, 3 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, iv7, 2);
  emlrtAssign(&y, m3);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *dt
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dt, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(dt), &thisId);
  emlrtDestroyArray(&dt);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *R
 *                const char_T *identifier
 * Return Type  : real_T (*)[36]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R, const
  char_T *identifier))[36]
{
  real_T (*y)[36];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(R), &thisId);
  emlrtDestroyArray(&R);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[36]
 */
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[36]
{
  real_T (*y)[36];
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *ang
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ang,
  const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(ang), &thisId);
  emlrtDestroyArray(&ang);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
  static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *q
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(q), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&q);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r1;
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *q
 *                const char_T *identifier
 * Return Type  : real_T (*)[4]
 */
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q, const
  char_T *identifier))[4]
{
  real_T (*y)[4];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(q), &thisId);
  emlrtDestroyArray(&q);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[4]
 */
  static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[4]
{
  real_T (*y)[4];
  y = ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *q1
 *                const char_T *identifier
 * Return Type  : real_T (*)[4]
 */
static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *q1,
  const char_T *identifier))[4]
{
  real_T (*y)[4];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = r_emlrt_marshallIn(sp, emlrtAlias(q1), &thisId);
  emlrtDestroyArray(&q1);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[4]
 */
  static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[4]
{
  real_T (*y)[4];
  y = bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[7]
 */
static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7]
{
  real_T (*ret)[7];
  static const int32_T dims[1] = { 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[7])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[49]
 */
  static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[49]
{
  real_T (*ret)[49];
  static const int32_T dims[2] = { 7, 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[49])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
  static real_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[36]
 */
static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[36]
{
  real_T (*ret)[36];
  static const int32_T dims[2] = { 6, 6 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[36])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
  static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[1] = { 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 4, 4 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv8[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv8);
  ret_size[0] = iv8[0];
  ret_size[1] = iv8[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray *prhs[8]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void ekf_func_quad_6dof_api(const mxArray *prhs[8], const mxArray *plhs[2])
{
  real_T (*X)[7];
  real_T (*P)[49];
  real_T (*acc)[3];
  real_T (*gyro)[3];
  real_T (*mag)[3];
  real_T dt;
  real_T (*Q)[49];
  real_T (*R)[36];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, true, -1);

  /* Marshall function inputs */
  X = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X");
  P = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "P");
  acc = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "acc");
  gyro = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "gyro");
  mag = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "mag");
  dt = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "dt");
  Q = c_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "Q");
  R = i_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "R");

  /* Invoke the target function */
  ekf_func_quad_6dof(*X, *P, *acc, *gyro, *mag, dt, *Q, *R);

  /* Marshall function outputs */
  emlrt_marshallOut(*X, prhs[0]);
  plhs[0] = prhs[0];
  b_emlrt_marshallOut(*P, prhs[1]);
  plhs[1] = prhs[1];
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void ekf_func_quad_6dof_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  ekf_func_quad_6dof_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void ekf_func_quad_6dof_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void ekf_func_quad_6dof_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void my_ang2quat_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  real_T (*q)[4];
  real_T (*ang)[3];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  q = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));

  /* Marshall function inputs */
  ang = k_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "ang");

  /* Invoke the target function */
  my_ang2quat(*ang, *q);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*q);
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void my_calcH_api(const mxArray * const prhs[6], const mxArray *plhs[1])
{
  real_T (*H)[42];
  real_T bx;
  real_T bz;
  real_T q0;
  real_T q1;
  real_T q2;
  real_T q3;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  H = (real_T (*)[42])mxMalloc(sizeof(real_T [42]));

  /* Marshall function inputs */
  bx = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "bx");
  bz = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "bz");
  q0 = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "q0");
  q1 = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "q1");
  q2 = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "q2");
  q3 = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "q3");

  /* Invoke the target function */
  my_calcH(bx, bz, q0, q1, q2, q3, *H);

  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*H);
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void my_quat2att_api(const mxArray * const prhs[1], const mxArray *plhs[3])
{
  real_T (*q_data)[16];
  int32_T q_size[2];
  real_T roll;
  real_T pitch;
  real_T yaw;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  m_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "q", (real_T **)&q_data, q_size);

  /* Invoke the target function */
  my_quat2att(*q_data, q_size, &roll, &pitch, &yaw);

  /* Marshall function outputs */
  plhs[0] = e_emlrt_marshallOut(roll);
  plhs[1] = e_emlrt_marshallOut(pitch);
  plhs[2] = e_emlrt_marshallOut(yaw);
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void my_quat2cbn_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  real_T (*cbn)[9];
  real_T (*q)[4];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  cbn = (real_T (*)[9])mxMalloc(sizeof(real_T [9]));

  /* Marshall function inputs */
  q = o_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "q");

  /* Invoke the target function */
  my_quat2cbn(*q, *cbn);

  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(*cbn);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void my_quatmul_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  real_T (*q)[4];
  real_T (*q1)[4];
  real_T (*q2)[4];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  q = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));

  /* Marshall function inputs */
  q1 = q_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "q1");
  q2 = o_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "q2");

  /* Invoke the target function */
  my_quatmul(*q1, *q2, *q);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*q);
}

/*
 * File trailer for _coder_ekf_func_quad_6dof_api.c
 *
 * [EOF]
 */
