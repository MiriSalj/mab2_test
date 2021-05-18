/*
 * acados_test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "acados_test".
 *
 * Model version              : 7.49
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue May 18 18:13:41 2021
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_acados_test_h_
#define RTW_HEADER_acados_test_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef acados_test_COMMON_INCLUDES_
#define acados_test_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* acados_test_COMMON_INCLUDES_ */

#include "acados_test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T y_ref_mat[686];
  real_T vy_pred[50];                  /* '<Root>/Delay' */
  real_T psidot_pred[50];              /* '<Root>/Delay' */
  real_T psi_pred[50];                 /* '<Root>/Delay' */
  real_T x_pred[50];                   /* '<Root>/Delay' */
  real_T y_pred[50];                   /* '<Root>/Delay' */
  real_T phidot_pred[50];              /* '<Root>/Delay' */
  real_T phi_pred[50];                 /* '<Root>/Delay' */
  real_T DigitalClock;                 /* '<Root>/Digital Clock' */
  real_T RateTransition2[50];          /* '<Root>/Rate Transition2' */
  real_T RateTransition1[50];          /* '<Root>/Rate Transition1' */
  real_T u0[6];                        /* '<S1>/S-Function' */
  real_T utraj[300];                   /* '<S1>/S-Function' */
  real_T xtraj[357];                   /* '<S1>/S-Function' */
  real_T SFunction_o4;                 /* '<S1>/S-Function' */
  real_T SFunction_o5;                 /* '<S1>/S-Function' */
  real_T x1[7];                        /* '<S1>/S-Function' */
  real_T SFunction_o7;                 /* '<S1>/S-Function' */
  real_T SFunction_o8;                 /* '<S1>/S-Function' */
  real_T RateTransition[50];           /* '<Root>/Rate Transition' */
  real_T y_ref[50];                    /* '<S4>/MATLAB Function' */
  real_T psi_ref[50];                  /* '<S4>/MATLAB Function' */
  real_T vy;                           /* '<S3>/MATLAB Function' */
  real_T psidot;                       /* '<S3>/MATLAB Function' */
  real_T psi;                          /* '<S3>/MATLAB Function' */
  real_T x;                            /* '<S3>/MATLAB Function' */
  real_T y;                            /* '<S3>/MATLAB Function' */
  real_T phidot;                       /* '<S3>/MATLAB Function' */
  real_T phi;                          /* '<S3>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionI[7];/* '<S6>/Referenz-Trajektorie' */
  real_T lbx0[7];                      /* '<S6>/Referenz-Trajektorie' */
  real_T ubx0[7];                      /* '<S6>/Referenz-Trajektorie' */
  real_T params_concatenated[153];     /* '<S6>/Referenz-Trajektorie' */
  real_T lbu_con[300];                 /* '<S6>/Referenz-Trajektorie' */
  real_T ubu_con[300];                 /* '<S6>/Referenz-Trajektorie' */
  real_T y_ref_0[14];                  /* '<S6>/Referenz-Trajektorie' */
  real_T y_ref_con[686];               /* '<S6>/Referenz-Trajektorie' */
  real_T y_ref_e[7];                   /* '<S6>/Referenz-Trajektorie' */
  real_T lbx[98];                      /* '<S6>/Referenz-Trajektorie' */
  real_T ubx[98];                      /* '<S6>/Referenz-Trajektorie' */
  real_T lbx_e[2];                     /* '<S6>/Referenz-Trajektorie' */
  real_T ubx_e[2];                     /* '<S6>/Referenz-Trajektorie' */
  real_T cost_W_0[196];                /* '<S6>/Referenz-Trajektorie' */
  real_T cost_W[196];                  /* '<S6>/Referenz-Trajektorie' */
  real_T cost_W_e[49];                 /* '<S6>/Referenz-Trajektorie' */
  real_T vy_pred_o[50];                /* '<S1>/MATLAB Function' */
  real_T psidot_pred_o[50];            /* '<S1>/MATLAB Function' */
  real_T psi_pred_h[50];               /* '<S1>/MATLAB Function' */
  real_T x_pred_p[50];                 /* '<S1>/MATLAB Function' */
  real_T y_pred_d[50];                 /* '<S1>/MATLAB Function' */
  real_T phidot_pred_o[50];            /* '<S1>/MATLAB Function' */
  real_T phi_pred_c[50];               /* '<S1>/MATLAB Function' */
  real_T st_pred[357];                 /* '<S1>/MATLAB Function' */
} B_acados_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_1_DSTATE[50];           /* '<Root>/Delay' */
  real_T Delay_2_DSTATE[50];           /* '<Root>/Delay' */
  real_T Delay_3_DSTATE[50];           /* '<Root>/Delay' */
  real_T Delay_4_DSTATE[50];           /* '<Root>/Delay' */
  real_T Delay_5_DSTATE[50];           /* '<Root>/Delay' */
  real_T Delay_6_DSTATE[50];           /* '<Root>/Delay' */
  real_T Delay_7_DSTATE[50];           /* '<Root>/Delay' */
} DW_acados_test_T;

/* Parameters (default storage) */
struct P_acados_test_T_ {
  real_T Delay_1_InitialCondition;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_2_InitialCondition;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_3_InitialCondition;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_4_InitialCondition;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_5_InitialCondition;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_6_InitialCondition;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_7_InitialCondition;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_acados_test_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct _ssPortInfo2 inputOutputPortInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[15];
      struct _ssInPortUnit inputPortUnits[15];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[15];
      real_T const *UPtrs0[7];
      real_T const *UPtrs1[7];
      real_T const *UPtrs2[153];
      real_T const *UPtrs3[14];
      real_T const *UPtrs4[686];
      real_T const *UPtrs5[7];
      real_T const *UPtrs6[98];
      real_T const *UPtrs7[98];
      real_T const *UPtrs8[2];
      real_T const *UPtrs9[2];
      real_T const *UPtrs10[300];
      real_T const *UPtrs11[300];
      real_T const *UPtrs12[196];
      real_T const *UPtrs13[196];
      real_T const *UPtrs14[49];
      struct _ssPortOutputs outputPortInfo[8];
      struct _ssOutPortUnit outputPortUnits[8];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[8];
    } Sfcn0;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (default storage) */
extern P_acados_test_T acados_test_P;

/* Block signals (default storage) */
extern B_acados_test_T acados_test_B;

/* Block states (default storage) */
extern DW_acados_test_T acados_test_DW;

/* Model entry point functions */
extern void acados_test_initialize(void);
extern void acados_test_output(void);
extern void acados_test_update(void);
extern void acados_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_acados_test_T *const acados_test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'acados_test'
 * '<S1>'   : 'acados_test/MPC-Regler'
 * '<S2>'   : 'acados_test/RTI Data'
 * '<S3>'   : 'acados_test/Subsystem'
 * '<S4>'   : 'acados_test/Subsystem1'
 * '<S5>'   : 'acados_test/MPC-Regler/MATLAB Function'
 * '<S6>'   : 'acados_test/MPC-Regler/Soll-Trajektorie'
 * '<S7>'   : 'acados_test/MPC-Regler/Soll-Trajektorie/Referenz-Trajektorie'
 * '<S8>'   : 'acados_test/RTI Data/RTI Data Store'
 * '<S9>'   : 'acados_test/RTI Data/RTI Data Store/RTI Data Store'
 * '<S10>'  : 'acados_test/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S11>'  : 'acados_test/Subsystem/MATLAB Function'
 * '<S12>'  : 'acados_test/Subsystem1/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_acados_test_h_ */
