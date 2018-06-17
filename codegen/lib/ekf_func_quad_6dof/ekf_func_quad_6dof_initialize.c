/*
 * File: ekf_func_quad_6dof_initialize.c
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
#include "ekf_func_quad_6dof_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void ekf_func_quad_6dof_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

/*
 * File trailer for ekf_func_quad_6dof_initialize.c
 *
 * [EOF]
 */
