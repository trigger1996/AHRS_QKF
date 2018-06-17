/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 17-Jun-2018 20:30:18
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "ekf_func_quad_6dof.h"
#include "my_ang2quat.h"
#include "my_calcH.h"
#include "my_quat2att.h"
#include "my_quat2cbn.h"
#include "my_quatmul.h"
#include "main.h"
#include "ekf_func_quad_6dof_terminate.h"
#include "ekf_func_quad_6dof_initialize.h"

/* Function Declarations */
static void argInit_1x3_real_T(double result[3]);
static void argInit_1x4_real_T(double result[4]);
static void argInit_3x1_real_T(double result[3]);
static void argInit_4x1_real_T(double result[4]);
static void argInit_6x6_real_T(double result[36]);
static void argInit_7x1_real_T(double result[7]);
static void argInit_7x7_real_T(double result[49]);
static void argInit_d4xd4_real_T(double result_data[], int result_size[2]);
static double argInit_real_T(void);
static void main_ekf_func_quad_6dof(void);
static void main_my_ang2quat(void);
static void main_my_calcH(void);
static void main_my_quat2att(void);
static void main_my_quat2cbn(void);
static void main_my_quatmul(void);

/* Function Definitions */

/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_1x3_real_T(double result[3])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 3; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[4]
 * Return Type  : void
 */
static void argInit_1x4_real_T(double result[4])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 4; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_3x1_real_T(double result[3])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[4]
 * Return Type  : void
 */
static void argInit_4x1_real_T(double result[4])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 4; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[36]
 * Return Type  : void
 */
static void argInit_6x6_real_T(double result[36])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 6; idx0++) {
    for (idx1 = 0; idx1 < 6; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 6 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[7]
 * Return Type  : void
 */
static void argInit_7x1_real_T(double result[7])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 7; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[49]
 * Return Type  : void
 */
static void argInit_7x7_real_T(double result[49])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 7; idx0++) {
    for (idx1 = 0; idx1 < 7; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 7 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_d4xd4_real_T(double result_data[], int result_size[2])
{
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 2;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result_data[idx0 + 2 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ekf_func_quad_6dof(void)
{
  double X[7];
  double P[49];
  double dv0[3];
  double dv1[3];
  double dv2[3];
  double dv3[49];
  double dv4[36];

  /* Initialize function 'ekf_func_quad_6dof' input arguments. */
  /* Initialize function input argument 'X'. */
  argInit_7x1_real_T(X);

  /* Initialize function input argument 'P'. */
  argInit_7x7_real_T(P);

  /* Initialize function input argument 'acc'. */
  /* Initialize function input argument 'gyro'. */
  /* Initialize function input argument 'mag'. */
  /* Initialize function input argument 'Q'. */
  /* Initialize function input argument 'R'. */
  /* Call the entry-point 'ekf_func_quad_6dof'. */
  argInit_1x3_real_T(dv0);
  argInit_1x3_real_T(dv1);
  argInit_1x3_real_T(dv2);
  argInit_7x7_real_T(dv3);
  argInit_6x6_real_T(dv4);
  ekf_func_quad_6dof(X, P, dv0, dv1, dv2, argInit_real_T(), dv3, dv4);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_my_ang2quat(void)
{
  double dv5[3];
  double q[4];

  /* Initialize function 'my_ang2quat' input arguments. */
  /* Initialize function input argument 'ang'. */
  /* Call the entry-point 'my_ang2quat'. */
  argInit_3x1_real_T(dv5);
  my_ang2quat(dv5, q);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_my_calcH(void)
{
  double H[42];

  /* Initialize function 'my_calcH' input arguments. */
  /* Call the entry-point 'my_calcH'. */
  my_calcH(argInit_real_T(), argInit_real_T(), argInit_real_T(), argInit_real_T(),
           argInit_real_T(), argInit_real_T(), H);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_my_quat2att(void)
{
  double q_data[16];
  int q_size[2];
  double roll;
  double pitch;
  double yaw;

  /* Initialize function 'my_quat2att' input arguments. */
  /* Initialize function input argument 'q'. */
  argInit_d4xd4_real_T(q_data, q_size);

  /* Call the entry-point 'my_quat2att'. */
  my_quat2att(q_data, q_size, &roll, &pitch, &yaw);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_my_quat2cbn(void)
{
  double dv6[4];
  double cbn[9];

  /* Initialize function 'my_quat2cbn' input arguments. */
  /* Initialize function input argument 'q'. */
  /* Call the entry-point 'my_quat2cbn'. */
  argInit_4x1_real_T(dv6);
  my_quat2cbn(dv6, cbn);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_my_quatmul(void)
{
  double dv7[4];
  double dv8[4];
  double q[4];

  /* Initialize function 'my_quatmul' input arguments. */
  /* Initialize function input argument 'q1'. */
  /* Initialize function input argument 'q2'. */
  /* Call the entry-point 'my_quatmul'. */
  argInit_1x4_real_T(dv7);
  argInit_4x1_real_T(dv8);
  my_quatmul(dv7, dv8, q);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  ekf_func_quad_6dof_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_ekf_func_quad_6dof();
  main_my_ang2quat();
  main_my_calcH();
  main_my_quat2att();
  main_my_quat2cbn();
  main_my_quatmul();

  /* Terminate the application.
     You do not need to do this more than one time. */
  ekf_func_quad_6dof_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
