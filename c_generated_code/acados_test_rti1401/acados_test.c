/*
 * acados_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "acados_test".
 *
 * Model version              : 1.130
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Apr 28 15:53:24 2021
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "acados_test_trc_ptr.h"
#include "acados_test.h"
#include "acados_test_private.h"

/* Exported block states */
real_T pred_exec_time;                 /* '<S4>/Data Store Memory' */
real_T overall_exec_time;              /* '<Root>/Data Store Memory' */
real_T xmeasure_exec_time;             /* '<S3>/Data Store Memory' */
real_T mpc_exec_time;                  /* '<S1>/Data Store Memory' */
real_T traj_exec_time;                 /* '<S7>/Data Store Memory' */

/* Block signals (auto storage) */
B_acados_test_T acados_test_B;

/* Block states (auto storage) */
DW_acados_test_T acados_test_DW;

/* Real-time model */
RT_MODEL_acados_test_T acados_test_M_;
RT_MODEL_acados_test_T *const acados_test_M = &acados_test_M_;

/* Forward declaration for local functions */
static void acados_test_repmat(real_T b[63]);
static void acados_test_repmat_m(real_T b[120]);

/* Function for MATLAB Function: '<S7>/Referenz-Trajektorie' */
static void acados_test_repmat(real_T b[63])
{
  int32_T ibcol;
  int32_T itilerow;
  for (itilerow = 0; itilerow < 21; itilerow++) {
    ibcol = itilerow * 3;
    b[ibcol] = 100.0;
    b[ibcol + 1] = 0.315;
    b[ibcol + 2] = 10.0;
  }
}

/* Function for MATLAB Function: '<S7>/Referenz-Trajektorie' */
static void acados_test_repmat_m(real_T b[120])
{
  int32_T ibcol;
  int32_T itilerow;
  int32_T k;
  static const real_T a[6] = { -0.4014257279586958, -0.4014257279586958, -50.0,
    -50.0, -50.0, -50.0 };

  for (itilerow = 0; itilerow < 20; itilerow++) {
    ibcol = itilerow * 6;
    for (k = 0; k < 6; k++) {
      b[ibcol + k] = a[k];
    }
  }
}

/* Model output function */
void acados_test_output(void)
{
  static const real_T b[36] = { 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 3.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-7, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 3.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-7 };

  int32_T k;
  int32_T i;
  real_T *x;

  /* MATLAB Function 'Subsystem1/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:9' */
  /* '<S13>:1:7' */
  /* '<S13>:1:10' */
  /* '<S13>:1:8' */
  for (k = 0; k < 20; k++) {
    /* Memory: '<Root>/Memory' */
    acados_test_B.x_pred[k] = acados_test_DW.Memory_4_PreviousInput[k];

    /* MATLAB Function: '<S4>/MATLAB Function' */
    acados_test_B.y_ref[k] = 0.1 * acados_test_B.x_pred[k];
    acados_test_B.y_ref[k] = sin(acados_test_B.y_ref[k]);
    acados_test_B.psi_ref[k] = 0.1 * acados_test_B.x_pred[k];
    acados_test_B.psi_ref[k] = cos(acados_test_B.psi_ref[k]);
    acados_test_B.psi_ref[k] *= 0.1;

    /* Memory: '<Root>/Memory' */
    acados_test_B.vy_pred[k] = acados_test_DW.Memory_1_PreviousInput[k];
    acados_test_B.psidot_pred[k] = acados_test_DW.Memory_2_PreviousInput[k];
    acados_test_B.psi_pred[k] = acados_test_DW.Memory_3_PreviousInput[k];
    acados_test_B.y_pred[k] = acados_test_DW.Memory_5_PreviousInput[k];
    acados_test_B.phidot_pred[k] = acados_test_DW.Memory_6_PreviousInput[k];
    acados_test_B.phi_pred[k] = acados_test_DW.Memory_7_PreviousInput[k];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* MATLAB Function: '<S3>/MATLAB Function' */
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S12>:1' */
  /* '<S12>:1:3' */
  acados_test_B.vy = acados_test_B.vy_pred[1];

  /* '<S12>:1:4' */
  acados_test_B.psidot = acados_test_B.psidot_pred[1];

  /* '<S12>:1:5' */
  acados_test_B.psi = acados_test_B.psi_pred[1];

  /* '<S12>:1:6' */
  acados_test_B.x = acados_test_B.x_pred[1];

  /* '<S12>:1:7' */
  acados_test_B.y = acados_test_B.y_pred[1];

  /* '<S12>:1:8' */
  acados_test_B.phidot = acados_test_B.phidot_pred[1];

  /* '<S12>:1:9' */
  acados_test_B.phi = acados_test_B.phi_pred[1];

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outputs for Atomic SubSystem: '<Root>/MPC-Regler' */
  /* Outputs for Atomic SubSystem: '<S1>/Soll-Trajektorie' */
  /* SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S7>/Referenz-Trajektorie'
   */
  acados_test_B.TmpSignalConversionAtSFunctionI[0] = acados_test_B.vy;
  acados_test_B.TmpSignalConversionAtSFunctionI[1] = acados_test_B.psidot;
  acados_test_B.TmpSignalConversionAtSFunctionI[2] = acados_test_B.psi;
  acados_test_B.TmpSignalConversionAtSFunctionI[3] = acados_test_B.x;
  acados_test_B.TmpSignalConversionAtSFunctionI[4] = acados_test_B.y;
  acados_test_B.TmpSignalConversionAtSFunctionI[5] = acados_test_B.phidot;
  acados_test_B.TmpSignalConversionAtSFunctionI[6] = acados_test_B.phi;

  /* MATLAB Function: '<S7>/Referenz-Trajektorie' */
  /* MATLAB Function 'MPC-Regler/Soll-Trajektorie/Referenz-Trajektorie': '<S8>:1' */
  /* '<S8>:1:79' */
  /* '<S8>:1:84' */
  /* '<S8>:1:61' */
  /* '<S8>:1:51' */
  /* '<S8>:1:54' */
  /* '<S8>:1:4' */
  for (k = 0; k < 7; k++) {
    acados_test_B.lbx0[k] = acados_test_B.TmpSignalConversionAtSFunctionI[k];
  }

  /* '<S8>:1:5' */
  for (k = 0; k < 7; k++) {
    acados_test_B.ubx0[k] = acados_test_B.TmpSignalConversionAtSFunctionI[k];
  }

  /* '<S8>:1:15' */
  /* '<S8>:1:39' */
  acados_test_repmat(acados_test_B.params_concatenated);

  /* '<S8>:1:41' */
  acados_test_repmat_m(acados_test_B.lbu_con);

  /* '<S8>:1:42' */
  for (k = 0; k < 120; k++) {
    acados_test_B.ubu_con[k] = -acados_test_B.lbu_con[k];
  }

  /* '<S8>:1:46' */
  memset(&acados_test_B.y_ref_0[0], 0, 14U * sizeof(real_T));

  /* '<S8>:1:47' */
  acados_test_B.y_ref_0[2] = acados_test_B.psi_ref[0];

  /* '<S8>:1:48' */
  acados_test_B.y_ref_0[4] = acados_test_B.y_ref[0];

  /* '<S8>:1:49' */
  acados_test_B.y_ref_0[13] = 100.0;

  /* '<S8>:1:51' */
  memset(&acados_test_B.y_ref_mat[0], 0, 266U * sizeof(real_T));

  /* '<S8>:1:52' */
  /* '<S8>:1:53' */
  /* '<S8>:1:54' */
  for (k = 0; k < 19; k++) {
    acados_test_B.y_ref_mat[2 + 14 * k] = acados_test_B.psi_ref[1 + k];
    acados_test_B.y_ref_mat[4 + 14 * k] = acados_test_B.y_ref[1 + k];
    acados_test_B.y_ref_mat[13 + 14 * k] = 100.0;
  }

  /* '<S8>:1:55' */
  memcpy(&acados_test_B.y_ref_con[0], &acados_test_B.y_ref_mat[0], 266U * sizeof
         (real_T));

  /* '<S8>:1:57' */
  for (k = 0; k < 7; k++) {
    acados_test_B.y_ref_e[k] = 0.0;
  }

  /* '<S8>:1:58' */
  acados_test_B.y_ref_e[2] = acados_test_B.psi_ref[19];

  /* '<S8>:1:59' */
  acados_test_B.y_ref_e[4] = acados_test_B.y_ref[19];

  /* '<S8>:1:61' */
  memset(&acados_test_B.lbx[0], 0, 38U * sizeof(real_T));

  /* '<S8>:1:62' */
  memset(&acados_test_B.ubx[0], 0, 38U * sizeof(real_T));

  /* '<S8>:1:63' */
  for (k = 0; k < 19; k++) {
    acados_test_B.lbx[k << 1] = acados_test_B.y_ref_mat[14 * k + 2] -
      0.52359877559829882;
  }

  /* '<S8>:1:64' */
  for (k = 0; k < 19; k++) {
    acados_test_B.lbx[1 + (k << 1)] = acados_test_B.y_ref_mat[14 * k + 4] - 1.0;
  }

  /* '<S8>:1:65' */
  for (k = 0; k < 19; k++) {
    acados_test_B.ubx[k << 1] = acados_test_B.y_ref_mat[14 * k + 2] +
      0.52359877559829882;
  }

  /* '<S8>:1:66' */
  for (k = 0; k < 19; k++) {
    acados_test_B.ubx[1 + (k << 1)] = acados_test_B.y_ref_mat[14 * k + 4] + 1.0;
  }

  /* '<S8>:1:69' */
  /* '<S8>:1:70' */
  /* '<S8>:1:71' */
  acados_test_B.lbx_e[0] = acados_test_B.psi_ref[19];
  acados_test_B.lbx_e[1] = acados_test_B.y_ref[19];

  /* '<S8>:1:72' */
  acados_test_B.ubx_e[0] = acados_test_B.psi_ref[19];
  acados_test_B.ubx_e[1] = acados_test_B.y_ref[19];

  /* '<S8>:1:79' */
  memset(&acados_test_B.cost_W_0[0], 0, 196U * sizeof(real_T));

  /* '<S8>:1:82' */
  acados_test_B.cost_W_0[30] = 1.0;

  /* '<S8>:1:83' */
  acados_test_B.cost_W_0[60] = 0.0001;

  /* '<S8>:1:84' */
  for (k = 0; k < 6; k++) {
    for (i = 0; i < 6; i++) {
      acados_test_B.cost_W_0[(i + 14 * (7 + k)) + 7] = b[6 * k + i];
    }
  }

  /* '<S8>:1:85' */
  acados_test_B.cost_W_0[195] = 0.01;

  /* '<S8>:1:87' */
  /* '<S8>:1:90' */
  /* '<S8>:1:91' */
  for (k = 0; k < 14; k++) {
    memcpy(&acados_test_B.cost_W[k * 14], &acados_test_B.cost_W_0[k * 14], 14U *
           sizeof(real_T));
  }

  /* '<S8>:1:92' */
  for (k = 0; k < 7; k++) {
    for (i = 0; i < 7; i++) {
      acados_test_B.cost_W_e[i + 7 * k] = acados_test_B.cost_W_0[14 * k + i] *
        10.0;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/Soll-Trajektorie' */

  /* S-Function (acados_solver_sfunction_flexcar_acados): '<S1>/S-Function' */

  /* Level2 S-Function Block: '<S1>/S-Function' (acados_solver_sfunction_flexcar_acados) */
  {
    SimStruct *rts = acados_test_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* MATLAB Function 'MPC-Regler/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:5' */
  x = &acados_test_B.xtraj[0];

  /* '<S6>:1:7' */
  for (k = 0; k < 20; k++) {
    acados_test_B.vy_pred_j[k] = x[7 * k];
  }

  /* '<S6>:1:8' */
  for (k = 0; k < 20; k++) {
    acados_test_B.psidot_pred_f[k] = x[7 * k + 1];
  }

  /* '<S6>:1:9' */
  for (k = 0; k < 20; k++) {
    acados_test_B.psi_pred_a[k] = x[7 * k + 2];
  }

  /* '<S6>:1:10' */
  for (k = 0; k < 20; k++) {
    acados_test_B.x_pred_i[k] = x[7 * k + 3];
  }

  /* '<S6>:1:11' */
  for (k = 0; k < 20; k++) {
    acados_test_B.y_pred_g[k] = x[7 * k + 4];
  }

  /* '<S6>:1:12' */
  for (k = 0; k < 20; k++) {
    acados_test_B.phidot_pred_e[k] = x[7 * k + 5];
  }

  /* '<S6>:1:13' */
  for (k = 0; k < 20; k++) {
    acados_test_B.phi_pred_p[k] = x[7 * k + 6];
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */
  /* End of Outputs for SubSystem: '<Root>/MPC-Regler' */
}

/* Model update function */
void acados_test_update(void)
{
  /* Update for Memory: '<Root>/Memory' */
  memcpy(&acados_test_DW.Memory_4_PreviousInput[0], &acados_test_B.x_pred_i[0],
         20U * sizeof(real_T));
  memcpy(&acados_test_DW.Memory_1_PreviousInput[0], &acados_test_B.vy_pred_j[0],
         20U * sizeof(real_T));
  memcpy(&acados_test_DW.Memory_2_PreviousInput[0],
         &acados_test_B.psidot_pred_f[0], 20U * sizeof(real_T));
  memcpy(&acados_test_DW.Memory_3_PreviousInput[0], &acados_test_B.psi_pred_a[0],
         20U * sizeof(real_T));
  memcpy(&acados_test_DW.Memory_5_PreviousInput[0], &acados_test_B.y_pred_g[0],
         20U * sizeof(real_T));
  memcpy(&acados_test_DW.Memory_6_PreviousInput[0],
         &acados_test_B.phidot_pred_e[0], 20U * sizeof(real_T));
  memcpy(&acados_test_DW.Memory_7_PreviousInput[0], &acados_test_B.phi_pred_p[0],
         20U * sizeof(real_T));

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
    acados_test_M->Timing.sampleTimes[0] = (0.1);

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
  acados_test_M->Timing.stepSize0 = 0.1;
  acados_test_M->solverInfoPtr = (&acados_test_M->solverInfo);
  acados_test_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&acados_test_M->solverInfo, 0.1);
  rtsiSetSolverMode(&acados_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &acados_test_B), 0,
                sizeof(B_acados_test_T));

  /* states (dwork) */
  (void) memset((void *)&acados_test_DW, 0,
                sizeof(DW_acados_test_T));

  /* exported global states */
  pred_exec_time = 0.0;
  overall_exec_time = 0.0;
  xmeasure_exec_time = 0.0;
  mpc_exec_time = 0.0;
  traj_exec_time = 0.0;

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
            for (i1=0; i1 < 63; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 63);
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
            for (i1=0; i1 < 266; i1++) {
              sfcnUPtrs[i1] = &u4[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 266);
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
            for (i1=0; i1 < 38; i1++) {
              sfcnUPtrs[i1] = &u6[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 38);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs7;

          {
            int_T i1;
            const real_T *u7 = acados_test_B.ubx;
            for (i1=0; i1 < 38; i1++) {
              sfcnUPtrs[i1] = &u7[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 38);
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
            for (i1=0; i1 < 120; i1++) {
              sfcnUPtrs[i1] = &u10[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 10, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 120);
        }

        /* port 11 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &acados_test_M->NonInlinedSFcns.Sfcn0.UPtrs11;

          {
            int_T i1;
            const real_T *u11 = acados_test_B.ubu_con;
            for (i1=0; i1 < 120; i1++) {
              sfcnUPtrs[i1] = &u11[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 11, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 120);
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

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 6);
          ssSetOutputPortSignal(rts, 0, ((real_T *) acados_test_B.u0));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 120);
          ssSetOutputPortSignal(rts, 1, ((real_T *) acados_test_B.utraj));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 147);
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
      ssSetSampleTime(rts, 0, 0.1);
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

  /* Start for Atomic SubSystem: '<Root>/Subsystem' */
  /* Start for DataStoreMemory: '<S3>/Data Store Memory' */
  xmeasure_exec_time = acados_test_P.DataStoreMemory_InitialValue_p;

  /* End of Start for SubSystem: '<Root>/Subsystem' */

  /* Start for Atomic SubSystem: '<Root>/MPC-Regler' */
  /* Start for Atomic SubSystem: '<S1>/Soll-Trajektorie' */
  /* Start for DataStoreMemory: '<S7>/Data Store Memory' */
  traj_exec_time = acados_test_P.DataStoreMemory_InitialValue;

  /* End of Start for SubSystem: '<S1>/Soll-Trajektorie' */

  /* Start for S-Function (acados_solver_sfunction_flexcar_acados): '<S1>/S-Function' */
  /* Level2 S-Function Block: '<S1>/S-Function' (acados_solver_sfunction_flexcar_acados) */
  {
    SimStruct *rts = acados_test_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  mpc_exec_time = acados_test_P.DataStoreMemory_InitialValue_b;

  /* End of Start for SubSystem: '<Root>/MPC-Regler' */

  /* Start for DataStoreMemory: '<S4>/Data Store Memory' */
  pred_exec_time = acados_test_P.DataStoreMemory_InitialValue_e;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  overall_exec_time = acados_test_P.DataStoreMemory_InitialValue_h;

  {
    int32_T i;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    for (i = 0; i < 20; i++) {
      acados_test_DW.Memory_4_PreviousInput[i] =
        acados_test_P.Memory_4_InitialCondition;
      acados_test_DW.Memory_1_PreviousInput[i] =
        acados_test_P.Memory_1_InitialCondition;
      acados_test_DW.Memory_2_PreviousInput[i] =
        acados_test_P.Memory_2_InitialCondition;
      acados_test_DW.Memory_3_PreviousInput[i] =
        acados_test_P.Memory_3_InitialCondition;
      acados_test_DW.Memory_5_PreviousInput[i] =
        acados_test_P.Memory_5_InitialCondition;
      acados_test_DW.Memory_6_PreviousInput[i] =
        acados_test_P.Memory_6_InitialCondition;
      acados_test_DW.Memory_7_PreviousInput[i] =
        acados_test_P.Memory_7_InitialCondition;
    }

    /* End of InitializeConditions for Memory: '<Root>/Memory' */
  }
}

/* Model terminate function */
void acados_test_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/MPC-Regler' */

  /* Terminate for S-Function (acados_solver_sfunction_flexcar_acados): '<S1>/S-Function' */
  /* Level2 S-Function Block: '<S1>/S-Function' (acados_solver_sfunction_flexcar_acados) */
  {
    SimStruct *rts = acados_test_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/MPC-Regler' */
}
