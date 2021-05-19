/*
 * acados_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "acados_test".
 *
 * Model version              : 7.53
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed May 19 16:01:36 2021
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "acados_test_trc_ptr.h"
#include "acados_test.h"
#include "acados_test_private.h"

/* Block signals (default storage) */
B_acados_test_T acados_test_B;

/* Block states (default storage) */
DW_acados_test_T acados_test_DW;

/* Real-time model */
static RT_MODEL_acados_test_T acados_test_M_;
RT_MODEL_acados_test_T *const acados_test_M = &acados_test_M_;

/* Forward declaration for local functions */
static void acados_test_repmat(real_T b[153]);
static void acados_test_repmat_b(real_T b[300]);

/* Function for MATLAB Function: '<S6>/Referenz-Trajektorie' */
static void acados_test_repmat(real_T b[153])
{
  int32_T ibcol;
  int32_T itilerow;
  for (itilerow = 0; itilerow < 51; itilerow++) {
    ibcol = itilerow * 3;
    b[ibcol] = 100.0;
    b[ibcol + 1] = 0.315;
    b[ibcol + 2] = 10.0;
  }
}

/* Function for MATLAB Function: '<S6>/Referenz-Trajektorie' */
static void acados_test_repmat_b(real_T b[300])
{
  static const real_T a[6] = { -0.4014257279586958, -0.4014257279586958, -50.0,
    -50.0, -50.0, -50.0 };

  int32_T ibcol;
  int32_T itilerow;
  int32_T k;
  for (itilerow = 0; itilerow < 50; itilerow++) {
    ibcol = itilerow * 6;
    for (k = 0; k < 6; k++) {
      b[ibcol + k] = a[k];
    }
  }
}

/* Model output function */
void acados_test_output(void)
{
  static const real_T b[50] = { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4, 0.5,
    0.60000000000000009, 0.70000000000000007, 0.8, 0.9, 1.0, 1.1,
    1.2000000000000002, 1.3, 1.4000000000000001, 1.5, 1.6, 1.7000000000000002,
    1.8, 1.9000000000000001, 2.0, 2.1, 2.2, 2.3000000000000003,
    2.4000000000000004, 2.5, 2.6, 2.7, 2.8000000000000003, 2.9000000000000004,
    3.0, 3.1000000000000005, 3.2, 3.3000000000000003, 3.4000000000000004, 3.5,
    3.6000000000000005, 3.7, 3.8000000000000003, 3.9000000000000004, 4.0,
    4.1000000000000005, 4.2, 4.3000000000000007, 4.4, 4.5, 4.6000000000000005,
    4.7, 4.8000000000000007, 4.9 };

  static const real_T b_0[36] = { 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-7, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-7 };

  int32_T i;
  int32_T i_0;

  /* DigitalClock: '<Root>/Digital Clock' */
  /* :  vy = vy_pred(2); */
  /* :  psidot = psidot_pred(2); */
  /* :  psi = psi_pred(2); */
  /* :  x = x_pred(2); */
  /* :  y = y_pred(2); */
  /* :  phidot = phidot_pred(2); */
  /* :  phi = phi_pred(2); */
  acados_test_B.DigitalClock = acados_test_M->Timing.t[0];
  for (i = 0; i < 50; i++) {
    /* Delay generated from: '<Root>/Delay' */
    acados_test_B.vy_pred[i] = acados_test_DW.Delay_1_DSTATE[i];

    /* Delay generated from: '<Root>/Delay' */
    acados_test_B.psidot_pred[i] = acados_test_DW.Delay_2_DSTATE[i];

    /* Delay generated from: '<Root>/Delay' */
    acados_test_B.psi_pred[i] = acados_test_DW.Delay_3_DSTATE[i];

    /* Delay generated from: '<Root>/Delay' */
    acados_test_B.x_pred[i] = acados_test_DW.Delay_4_DSTATE[i];

    /* Delay generated from: '<Root>/Delay' */
    acados_test_B.y_pred[i] = acados_test_DW.Delay_5_DSTATE[i];

    /* Delay generated from: '<Root>/Delay' */
    acados_test_B.phidot_pred[i] = acados_test_DW.Delay_6_DSTATE[i];

    /* Delay generated from: '<Root>/Delay' */
    acados_test_B.phi_pred[i] = acados_test_DW.Delay_7_DSTATE[i];

    /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
     *  Delay generated from: '<Root>/Delay'
     */
    acados_test_B.psi_ref[i] = acados_test_B.x_pred[i];
  }

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Delay generated from: '<Root>/Delay'
   */
  acados_test_B.vy = acados_test_B.vy_pred[1];
  acados_test_B.psidot = acados_test_B.psidot_pred[1];
  acados_test_B.psi = acados_test_B.psi_pred[1];
  acados_test_B.x = acados_test_B.x_pred[1];
  acados_test_B.y = acados_test_B.y_pred[1];
  acados_test_B.phidot = acados_test_B.phidot_pred[1];
  acados_test_B.phi = acados_test_B.phi_pred[1];

  /* MATLAB Function: '<S4>/MATLAB Function' */
  /* :  if t < 0.025 */
  if (acados_test_B.DigitalClock < 0.025) {
    /* :  x_pred = 0:0.1:4.9; */
    memcpy(&acados_test_B.psi_ref[0], &b[0], 50U * sizeof(real_T));
  }

  /* :  Y_ref = @(x) sin(0.1*x); */
  /* :  Psi_ref = @(x) 0.1*cos(0.1*x); */
  /* :  y_ref = Y_ref(x_pred); */
  /* :  psi_ref = Psi_ref(x_pred); */
  for (i = 0; i < 50; i++) {
    acados_test_B.y_ref[i] = 0.1 * acados_test_B.psi_ref[i];
    acados_test_B.y_ref[i] = sin(acados_test_B.y_ref[i]);
    acados_test_B.psi_ref[i] *= 0.1;
    acados_test_B.psi_ref[i] = cos(acados_test_B.psi_ref[i]);
    acados_test_B.psi_ref[i] *= 0.1;
  }

  /* SignalConversion generated from: '<S7>/ SFunction ' incorporates:
   *  MATLAB Function: '<S6>/Referenz-Trajektorie'
   */
  acados_test_B.TmpSignalConversionAtSFunctionI[0] = acados_test_B.vy;
  acados_test_B.TmpSignalConversionAtSFunctionI[1] = acados_test_B.psidot;
  acados_test_B.TmpSignalConversionAtSFunctionI[2] = acados_test_B.psi;
  acados_test_B.TmpSignalConversionAtSFunctionI[3] = acados_test_B.x;
  acados_test_B.TmpSignalConversionAtSFunctionI[4] = acados_test_B.y;
  acados_test_B.TmpSignalConversionAtSFunctionI[5] = acados_test_B.phidot;
  acados_test_B.TmpSignalConversionAtSFunctionI[6] = acados_test_B.phi;

  /* MATLAB Function: '<S6>/Referenz-Trajektorie' incorporates:
   *  SignalConversion generated from: '<S7>/ SFunction '
   */
  /* :  lbx0 = xmeasure; */
  for (i = 0; i < 7; i++) {
    acados_test_B.lbx0[i] = acados_test_B.TmpSignalConversionAtSFunctionI[i];
  }

  /* :  ubx0 = xmeasure; */
  for (i = 0; i < 7; i++) {
    acados_test_B.ubx0[i] = acados_test_B.TmpSignalConversionAtSFunctionI[i];
  }

  /* :  lbu = [-deg2rad(23),-deg2rad(23), -50, -50, -50, -50]'; */
  /* :  param = [1.5349e+05, 1.56618e+05, 0.3775, 100, 0.315, 1, 1e-4, 1e-2, 2, 2, 3e-7, 3e-7, 3e-7, 3e-7, 10]; */
  /* :  nx = 7; */
  /* :  nu = 6; */
  /* :  n_M = 1; */
  /* :  nz = 0; */
  /* :  N = 50; */
  /* :  Fx_ref = param(4); */
  /* :  rdyn = param(5); */
  /* :  vx = param(15); */
  /* :  Q_11 = param(6); */
  /* :  Q_22 = param(7); */
  /* :  Q_33 = param(8); */
  /* :  R_11 = param(9); */
  /* :  R_22 = param(10); */
  /* :  R_33 = param(11); */
  /* :  R_44 = param(12); */
  /* :  R_55 = param(13); */
  /* :  R_66 = param(14); */
  /* :  param0 = [Fx_ref; rdyn; vx]; */
  /* :  params_concatenated = repmat(param0, N+1, 1)'; */
  acados_test_repmat(acados_test_B.params_concatenated);

  /* :  lbu_con = repmat(lbu, N, 1); */
  acados_test_repmat_b(acados_test_B.lbu_con);

  /* :  ubu_con = -lbu_con; */
  for (i = 0; i < 300; i++) {
    acados_test_B.ubu_con[i] = -acados_test_B.lbu_con[i];
  }

  /* :  y_ref_0 = zeros(nx+nu+n_M, 1); */
  for (i = 0; i < 14; i++) {
    acados_test_B.y_ref_0[i] = 0.0;
  }

  /* :  y_ref_0(3) = psi_ref(1); */
  acados_test_B.y_ref_0[2] = acados_test_B.psi_ref[0];

  /* :  y_ref_0(5) = y_ref(1); */
  acados_test_B.y_ref_0[4] = acados_test_B.y_ref[0];

  /* :  y_ref_0(end) = Fx_ref; */
  acados_test_B.y_ref_0[13] = 100.0;

  /* :  y_ref_mat = zeros(nx+nu+n_M, N-1); */
  for (i = 0; i < 686; i++) {
    acados_test_B.y_ref_mat[i] = 0.0;
  }

  /* :  y_ref_mat(3, :) = psi_ref(2:end); */
  /* :  y_ref_mat(5, :) = y_ref(2:end); */
  /* :  y_ref_mat(end, :) = Fx_ref * ones(1, N-1)'; */
  for (i = 0; i < 49; i++) {
    acados_test_B.y_ref_mat[14 * i + 2] = acados_test_B.psi_ref[i + 1];
    acados_test_B.y_ref_mat[14 * i + 4] = acados_test_B.y_ref[i + 1];
    acados_test_B.y_ref_mat[14 * i + 13] = 100.0;
  }

  /* :  y_ref_con = reshape(y_ref_mat, (nx+nu+n_M)*(N-1), 1); */
  memcpy(&acados_test_B.y_ref_con[0], &acados_test_B.y_ref_mat[0], 686U * sizeof
         (real_T));

  /* :  y_ref_e = zeros(nx, 1); */
  for (i = 0; i < 7; i++) {
    acados_test_B.y_ref_e[i] = 0.0;
  }

  /* :  y_ref_e(3) = psi_ref(end); */
  acados_test_B.y_ref_e[2] = acados_test_B.psi_ref[49];

  /* :  y_ref_e(5) = y_ref(end); */
  acados_test_B.y_ref_e[4] = acados_test_B.y_ref[49];

  /* :  Y_ref_lb = zeros(2, N-1); */
  for (i = 0; i < 98; i++) {
    acados_test_B.lbx[i] = 0.0;
  }

  /* :  Y_ref_ub = zeros(2, N-1); */
  for (i = 0; i < 98; i++) {
    acados_test_B.ubx[i] = 0.0;
  }

  /* :  Y_ref_lb(1, :) = y_ref_mat(3, :) - deg2rad(30); */
  for (i = 0; i < 49; i++) {
    acados_test_B.lbx[i << 1] = acados_test_B.y_ref_mat[14 * i + 2] -
      0.52359877559829882;
  }

  /* :  Y_ref_lb(2, :) = y_ref_mat(5, :) - 1; */
  for (i = 0; i < 49; i++) {
    acados_test_B.lbx[(i << 1) + 1] = acados_test_B.y_ref_mat[14 * i + 4] - 1.0;
  }

  /* :  Y_ref_ub(1, :) = y_ref_mat(3, :) + deg2rad(30); */
  for (i = 0; i < 49; i++) {
    acados_test_B.ubx[i << 1] = acados_test_B.y_ref_mat[14 * i + 2] +
      0.52359877559829882;
  }

  /* :  Y_ref_ub(2, :) = y_ref_mat(5, :) + 1; */
  for (i = 0; i < 49; i++) {
    acados_test_B.ubx[(i << 1) + 1] = acados_test_B.y_ref_mat[14 * i + 4] + 1.0;
  }

  /* :  lbx = reshape(Y_ref_lb, 1, 2*(N-1)); */
  /* :  ubx = reshape(Y_ref_ub, 1, 2*(N-1)); */
  /* :  lbx_e = [y_ref_e(3), y_ref_e(5)]; */
  acados_test_B.lbx_e[0] = acados_test_B.psi_ref[49];
  acados_test_B.lbx_e[1] = acados_test_B.y_ref[49];

  /* :  ubx_e = [y_ref_e(3), y_ref_e(5)]; */
  acados_test_B.ubx_e[0] = acados_test_B.psi_ref[49];
  acados_test_B.ubx_e[1] = acados_test_B.y_ref[49];

  /* :  COST_W_0 = zeros(nx+nu+n_M, nx+nu+n_M); */
  for (i = 0; i < 196; i++) {
    acados_test_B.cost_W_0[i] = 0.0;
  }

  /* :  COST_W_e = zeros(nx, nx); */
  /* :  COST_W_0(3, 3) = Q_11; */
  acados_test_B.cost_W_0[30] = 1.0;

  /* :  COST_W_0(5, 5) = Q_22; */
  acados_test_B.cost_W_0[60] = 0.0001;

  /* :  COST_W_0(8:13, 8:13) = diag([R_11, R_22, R_33, R_44, R_55, R_66]); */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      acados_test_B.cost_W_0[(i_0 + 14 * (i + 7)) + 7] = b_0[6 * i + i_0];
    }
  }

  /* :  COST_W_0(14, 14) = Q_33; */
  acados_test_B.cost_W_0[195] = 0.01;

  /* :  COST_W_e = 10*COST_W_0(1:nx, 1:nx); */
  /* :  cost_W_0 = reshape(COST_W_0, 1, (nx+nu+n_M)*(nx+nu+n_M)); */
  /* :  cost_W = cost_W_0; */
  memcpy(&acados_test_B.cost_W[0], &acados_test_B.cost_W_0[0], 196U * sizeof
         (real_T));

  /* :  cost_W_e = reshape(COST_W_e, 1, nx*nx); */
  for (i = 0; i < 7; i++) {
    for (i_0 = 0; i_0 < 7; i_0++) {
      acados_test_B.cost_W_e[i_0 + 7 * i] = acados_test_B.cost_W_0[14 * i + i_0]
        * 10.0;
    }
  }

  /* S-Function (acados_solver_sfunction_flexcar_acados): '<S1>/S-Function' */

  /* Level2 S-Function Block: '<S1>/S-Function' (acados_solver_sfunction_flexcar_acados) */
  {
    SimStruct *rts = acados_test_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* :  N = 50; */
  /* :  st_pred = reshape(state_pred, 7, N+1); */
  /* :  vy_pred = st_pred(1, 1:N); */
  for (i = 0; i < 50; i++) {
    acados_test_B.vy_pred_o[i] = acados_test_B.xtraj[7 * i];
  }

  /* :  psidot_pred = st_pred(2, 1:N); */
  for (i = 0; i < 50; i++) {
    acados_test_B.psidot_pred_o[i] = acados_test_B.xtraj[7 * i + 1];
  }

  /* :  psi_pred = st_pred(3, 1:N); */
  for (i = 0; i < 50; i++) {
    acados_test_B.psi_pred_h[i] = acados_test_B.xtraj[7 * i + 2];
  }

  /* :  x_pred = st_pred(4, 1:N); */
  for (i = 0; i < 50; i++) {
    acados_test_B.x_pred_p[i] = acados_test_B.xtraj[7 * i + 3];
  }

  /* :  y_pred = st_pred(5, 1:N); */
  for (i = 0; i < 50; i++) {
    acados_test_B.y_pred_d[i] = acados_test_B.xtraj[7 * i + 4];
  }

  /* :  phidot_pred = st_pred(6, 1:N); */
  for (i = 0; i < 50; i++) {
    acados_test_B.phidot_pred_o[i] = acados_test_B.xtraj[7 * i + 5];
  }

  /* :  phi_pred = st_pred(7, 1:N); */
  for (i = 0; i < 50; i++) {
    acados_test_B.phi_pred_c[i] = acados_test_B.xtraj[7 * i + 6];
  }

  memcpy(&acados_test_B.st_pred[0], &acados_test_B.xtraj[0], 357U * sizeof
         (real_T));

  /* End of MATLAB Function: '<S1>/MATLAB Function' */
}

/* Model update function */
void acados_test_update(void)
{
  /* Update for Delay generated from: '<Root>/Delay' */
  memcpy(&acados_test_DW.Delay_1_DSTATE[0], &acados_test_B.vy_pred_o[0], 50U *
         sizeof(real_T));

  /* Update for Delay generated from: '<Root>/Delay' */
  memcpy(&acados_test_DW.Delay_2_DSTATE[0], &acados_test_B.psidot_pred_o[0], 50U
         * sizeof(real_T));

  /* Update for Delay generated from: '<Root>/Delay' */
  memcpy(&acados_test_DW.Delay_3_DSTATE[0], &acados_test_B.psi_pred_h[0], 50U *
         sizeof(real_T));

  /* Update for Delay generated from: '<Root>/Delay' */
  memcpy(&acados_test_DW.Delay_4_DSTATE[0], &acados_test_B.x_pred_p[0], 50U *
         sizeof(real_T));

  /* Update for Delay generated from: '<Root>/Delay' */
  memcpy(&acados_test_DW.Delay_5_DSTATE[0], &acados_test_B.y_pred_d[0], 50U *
         sizeof(real_T));

  /* Update for Delay generated from: '<Root>/Delay' */
  memcpy(&acados_test_DW.Delay_6_DSTATE[0], &acados_test_B.phidot_pred_o[0], 50U
         * sizeof(real_T));

  /* Update for Delay generated from: '<Root>/Delay' */
  memcpy(&acados_test_DW.Delay_7_DSTATE[0], &acados_test_B.phi_pred_c[0], 50U *
         sizeof(real_T));

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++acados_test_M->Timing.clockTick0)) {
    ++acados_test_M->Timing.clockTickH0;
  }

  acados_test_M->Timing.t[0] = acados_test_M->Timing.clockTick0 *
    acados_test_M->Timing.stepSize0 + acados_test_M->Timing.clockTickH0 *
    acados_test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void acados_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)acados_test_M, 0,
                sizeof(RT_MODEL_acados_test_T));
  rtsiSetSolverName(&acados_test_M->solverInfo,"FixedStepDiscrete");
  acados_test_M->solverInfoPtr = (&acados_test_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = acados_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    acados_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    acados_test_M->Timing.sampleTimes = (&acados_test_M->
      Timing.sampleTimesArray[0]);
    acados_test_M->Timing.offsetTimes = (&acados_test_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    acados_test_M->Timing.sampleTimes[0] = (10.0);

    /* task offsets */
    acados_test_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(acados_test_M, &acados_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = acados_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    acados_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(acados_test_M, -1);
  acados_test_M->Timing.stepSize0 = 10.0;
  acados_test_M->solverInfoPtr = (&acados_test_M->solverInfo);
  acados_test_M->Timing.stepSize = (10.0);
  rtsiSetFixedStepSize(&acados_test_M->solverInfo, 10.0);
  rtsiSetSolverMode(&acados_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_B.vy_pred[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.psidot_pred[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.psi_pred[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.x_pred[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.y_pred[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.phidot_pred[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.phi_pred[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      acados_test_B.u0[i] = 0.0;
    }

    for (i = 0; i < 300; i++) {
      acados_test_B.utraj[i] = 0.0;
    }

    for (i = 0; i < 357; i++) {
      acados_test_B.xtraj[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      acados_test_B.x1[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.y_ref[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.psi_ref[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      acados_test_B.TmpSignalConversionAtSFunctionI[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      acados_test_B.lbx0[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      acados_test_B.ubx0[i] = 0.0;
    }

    for (i = 0; i < 153; i++) {
      acados_test_B.params_concatenated[i] = 0.0;
    }

    for (i = 0; i < 300; i++) {
      acados_test_B.lbu_con[i] = 0.0;
    }

    for (i = 0; i < 300; i++) {
      acados_test_B.ubu_con[i] = 0.0;
    }

    for (i = 0; i < 14; i++) {
      acados_test_B.y_ref_0[i] = 0.0;
    }

    for (i = 0; i < 686; i++) {
      acados_test_B.y_ref_con[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      acados_test_B.y_ref_e[i] = 0.0;
    }

    for (i = 0; i < 98; i++) {
      acados_test_B.lbx[i] = 0.0;
    }

    for (i = 0; i < 98; i++) {
      acados_test_B.ubx[i] = 0.0;
    }

    for (i = 0; i < 196; i++) {
      acados_test_B.cost_W_0[i] = 0.0;
    }

    for (i = 0; i < 196; i++) {
      acados_test_B.cost_W[i] = 0.0;
    }

    for (i = 0; i < 49; i++) {
      acados_test_B.cost_W_e[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.vy_pred_o[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.psidot_pred_o[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.psi_pred_h[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.x_pred_p[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.y_pred_d[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.phidot_pred_o[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      acados_test_B.phi_pred_c[i] = 0.0;
    }

    for (i = 0; i < 357; i++) {
      acados_test_B.st_pred[i] = 0.0;
    }

    acados_test_B.DigitalClock = 0.0;
    acados_test_B.SFunction_o4 = 0.0;
    acados_test_B.SFunction_o5 = 0.0;
    acados_test_B.SFunction_o7 = 0.0;
    acados_test_B.SFunction_o8 = 0.0;
    acados_test_B.vy = 0.0;
    acados_test_B.psidot = 0.0;
    acados_test_B.psi = 0.0;
    acados_test_B.x = 0.0;
    acados_test_B.y = 0.0;
    acados_test_B.phidot = 0.0;
    acados_test_B.phi = 0.0;
    acados_test_B.lbx_e[0] = 0.0;
    acados_test_B.lbx_e[1] = 0.0;
    acados_test_B.ubx_e[0] = 0.0;
    acados_test_B.ubx_e[1] = 0.0;
  }

  /* states (dwork) */
  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_2_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_3_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_4_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_5_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_6_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_7_DSTATE[i] = 0.0;
    }
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &acados_test_M->NonInlinedSFcns.sfcnInfo;
    acados_test_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(acados_test_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &acados_test_M->Sizes.numSampTimes);
    acados_test_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(acados_test_M)
      [0]);
    rtssSetTPtrPtr(sfcnInfo,acados_test_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(acados_test_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(acados_test_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(acados_test_M));
    rtssSetStepSizePtr(sfcnInfo, &acados_test_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(acados_test_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &acados_test_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &acados_test_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &acados_test_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &acados_test_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &acados_test_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &acados_test_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &acados_test_M->solverInfoPtr);
  }

  acados_test_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&acados_test_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    acados_test_M->childSfunctions =
      (&acados_test_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    acados_test_M->childSfunctions[0] =
      (&acados_test_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: acados_test/<S1>/S-Function (acados_solver_sfunction_flexcar_acados) */
    {
      SimStruct *rts = acados_test_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = acados_test_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = acados_test_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = acados_test_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &acados_test_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &acados_test_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, acados_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &acados_test_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &acados_test_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &acados_test_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &acados_test_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &acados_test_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 15);
        ssSetPortInfoForInputs(rts,
          &acados_test_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &acados_test_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        ssSetInputPortUnit(rts, 4, 0);
        ssSetInputPortUnit(rts, 5, 0);
        ssSetInputPortUnit(rts, 6, 0);
        ssSetInputPortUnit(rts, 7, 0);
        ssSetInputPortUnit(rts, 8, 0);
        ssSetInputPortUnit(rts, 9, 0);
        ssSetInputPortUnit(rts, 10, 0);
        ssSetInputPortUnit(rts, 11, 0);
        ssSetInputPortUnit(rts, 12, 0);
        ssSetInputPortUnit(rts, 13, 0);
        ssSetInputPortUnit(rts, 14, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &acados_test_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);
        ssSetInputPortIsContinuousQuantity(rts, 4, 0);
        ssSetInputPortIsContinuousQuantity(rts, 5, 0);
        ssSetInputPortIsContinuousQuantity(rts, 6, 0);
        ssSetInputPortIsContinuousQuantity(rts, 7, 0);
        ssSetInputPortIsContinuousQuantity(rts, 8, 0);
        ssSetInputPortIsContinuousQuantity(rts, 9, 0);
        ssSetInputPortIsContinuousQuantity(rts, 10, 0);
        ssSetInputPortIsContinuousQuantity(rts, 11, 0);
        ssSetInputPortIsContinuousQuantity(rts, 12, 0);
        ssSetInputPortIsContinuousQuantity(rts, 13, 0);
        ssSetInputPortIsContinuousQuantity(rts, 14, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = acados_test_B.lbx0;
            for (i1=0; i1 < 7; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 7);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs1;

          {
            int_T i1;
            const real_T *u1 = acados_test_B.ubx0;
            for (i1=0; i1 < 7; i1++) {
              sfcnUPtrs[i1] = &u1[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 7);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = acados_test_B.params_concatenated;
            for (i1=0; i1 < 153; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 153);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs3;

          {
            int_T i1;
            const real_T *u3 = acados_test_B.y_ref_0;
            for (i1=0; i1 < 14; i1++) {
              sfcnUPtrs[i1] = &u3[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 14);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs4;

          {
            int_T i1;
            const real_T *u4 = acados_test_B.y_ref_con;
            for (i1=0; i1 < 686; i1++) {
              sfcnUPtrs[i1] = &u4[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 686);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs5;

          {
            int_T i1;
            const real_T *u5 = acados_test_B.y_ref_e;
            for (i1=0; i1 < 7; i1++) {
              sfcnUPtrs[i1] = &u5[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 7);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs6;

          {
            int_T i1;
            const real_T *u6 = acados_test_B.lbx;
            for (i1=0; i1 < 98; i1++) {
              sfcnUPtrs[i1] = &u6[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 98);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs7;

          {
            int_T i1;
            const real_T *u7 = acados_test_B.ubx;
            for (i1=0; i1 < 98; i1++) {
              sfcnUPtrs[i1] = &u7[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 98);
        }

        /* port 8 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs8;
          sfcnUPtrs[0] = acados_test_B.lbx_e;
          sfcnUPtrs[1] = &acados_test_B.lbx_e[1];
          ssSetInputPortSignalPtrs(rts, 8, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 2);
        }

        /* port 9 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs9;
          sfcnUPtrs[0] = acados_test_B.ubx_e;
          sfcnUPtrs[1] = &acados_test_B.ubx_e[1];
          ssSetInputPortSignalPtrs(rts, 9, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 9, 1);
          ssSetInputPortWidth(rts, 9, 2);
        }

        /* port 10 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs10;

          {
            int_T i1;
            const real_T *u10 = acados_test_B.lbu_con;
            for (i1=0; i1 < 300; i1++) {
              sfcnUPtrs[i1] = &u10[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 10, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 300);
        }

        /* port 11 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs11;

          {
            int_T i1;
            const real_T *u11 = acados_test_B.ubu_con;
            for (i1=0; i1 < 300; i1++) {
              sfcnUPtrs[i1] = &u11[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 11, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 300);
        }

        /* port 12 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs12;

          {
            int_T i1;
            const real_T *u12 = acados_test_B.cost_W_0;
            for (i1=0; i1 < 196; i1++) {
              sfcnUPtrs[i1] = &u12[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 12, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 12, 1);
          ssSetInputPortWidth(rts, 12, 196);
        }

        /* port 13 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs13;

          {
            int_T i1;
            const real_T *u13 = acados_test_B.cost_W;
            for (i1=0; i1 < 196; i1++) {
              sfcnUPtrs[i1] = &u13[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 13, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 13, 1);
          ssSetInputPortWidth(rts, 13, 196);
        }

        /* port 14 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs14;

          {
            int_T i1;
            const real_T *u14 = acados_test_B.cost_W_e;
            for (i1=0; i1 < 49; i1++) {
              sfcnUPtrs[i1] = &u14[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 14, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 14, 1);
          ssSetInputPortWidth(rts, 14, 49);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &acados_test_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);
        _ssSetPortInfo2ForOutputUnits(rts,
          &acados_test_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        ssSetOutputPortUnit(rts, 7, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &acados_test_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 6, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 7, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 6);
          ssSetOutputPortSignal(rts, 0, ((real_T *) acados_test_B.u0));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 300);
          ssSetOutputPortSignal(rts, 1, ((real_T *) acados_test_B.utraj));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 357);
          ssSetOutputPortSignal(rts, 2, ((real_T *) acados_test_B.xtraj));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &acados_test_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &acados_test_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 7);
          ssSetOutputPortSignal(rts, 5, ((real_T *) acados_test_B.x1));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &acados_test_B.SFunction_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &acados_test_B.SFunction_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "acados_test/MPC-Regler/S-Function");
      ssSetRTModel(rts,acados_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      acados_solver_sfunction_flexcar_acados(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 10.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);
      _ssSetInputPortConnected(rts, 8, 1);
      _ssSetInputPortConnected(rts, 9, 1);
      _ssSetInputPortConnected(rts, 10, 1);
      _ssSetInputPortConnected(rts, 11, 1);
      _ssSetInputPortConnected(rts, 12, 1);
      _ssSetInputPortConnected(rts, 13, 1);
      _ssSetInputPortConnected(rts, 14, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
      ssSetInputPortBufferDstPort(rts, 8, -1);
      ssSetInputPortBufferDstPort(rts, 9, -1);
      ssSetInputPortBufferDstPort(rts, 10, -1);
      ssSetInputPortBufferDstPort(rts, 11, -1);
      ssSetInputPortBufferDstPort(rts, 12, -1);
      ssSetInputPortBufferDstPort(rts, 13, -1);
      ssSetInputPortBufferDstPort(rts, 14, -1);
    }
  }

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    acados_test_rti_init_trc_pointers();
  }

  /* Start for S-Function (acados_solver_sfunction_flexcar_acados): '<S1>/S-Function' */
  /* Level2 S-Function Block: '<S1>/S-Function' (acados_solver_sfunction_flexcar_acados) */
  {
    SimStruct *rts = acados_test_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  {
    int32_T i;

    /* InitializeConditions for Delay generated from: '<Root>/Delay' */
    for (i = 0; i < 50; i++) {
      acados_test_DW.Delay_1_DSTATE[i] = acados_test_P.Delay_1_InitialCondition;
      acados_test_DW.Delay_2_DSTATE[i] = acados_test_P.Delay_2_InitialCondition;
      acados_test_DW.Delay_3_DSTATE[i] = acados_test_P.Delay_3_InitialCondition;
      acados_test_DW.Delay_4_DSTATE[i] = acados_test_P.Delay_4_InitialCondition;
      acados_test_DW.Delay_5_DSTATE[i] = acados_test_P.Delay_5_InitialCondition;
      acados_test_DW.Delay_6_DSTATE[i] = acados_test_P.Delay_6_InitialCondition;
      acados_test_DW.Delay_7_DSTATE[i] = acados_test_P.Delay_7_InitialCondition;
    }

    /* End of InitializeConditions for Delay generated from: '<Root>/Delay' */
  }
}

/* Model terminate function */
void acados_test_terminate(void)
{
  /* Terminate for S-Function (acados_solver_sfunction_flexcar_acados): '<S1>/S-Function' */
  /* Level2 S-Function Block: '<S1>/S-Function' (acados_solver_sfunction_flexcar_acados) */
  {
    SimStruct *rts = acados_test_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}
