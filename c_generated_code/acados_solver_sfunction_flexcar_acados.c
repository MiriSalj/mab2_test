/*
 * Copyright 2019 Gianluca Frison, Dimitris Kouzoupis, Robin Verschueren,
 * Andrea Zanelli, Niels van Duijkeren, Jonathan Frey, Tommaso Sartor,
 * Branimir Novoselnik, Rien Quirynen, Rezart Qelibari, Dang Doan,
 * Jonas Koenemann, Yutao Chen, Tobias Schöls, Jonas Schlagenhauf, Moritz Diehl
 *
 * This file is part of acados.
 *
 * The 2-Clause BSD License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.;
 */

#define S_FUNCTION_NAME acados_solver_sfunction_flexcar_acados
#define S_FUNCTION_LEVEL 2

#define MDL_START

// acados
#include "acados/utils/print.h"
#include "acados_c/sim_interface.h"
#include "acados_c/external_function_interface.h"

// example specific
#include "flexcar_acados_model/flexcar_acados_model.h"
#include "acados_solver_flexcar_acados.h"

#include "simstruc.h"

#define SAMPLINGTIME -1

static void mdlInitializeSizes (SimStruct *S)
{
    // specify the number of continuous and discrete states
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);  // specify the number of input ports
    if ( !ssSetNumInputPorts(S, 15) )
        return;

    // specify the number of output ports
    if ( !ssSetNumOutputPorts(S, 8) )
        return;

    // specify dimension information for the input ports
    // lbx_0
    ssSetInputPortVectorDimension(S, 0, 7);
    // ubx_0
    ssSetInputPortVectorDimension(S, 1, 7);
    // parameters
    ssSetInputPortVectorDimension(S, 2, (50+1) * 3);
    // y_ref_0
    ssSetInputPortVectorDimension(S, 3, 14);
    // y_ref
    ssSetInputPortVectorDimension(S, 4, 686);
    // y_ref_e
    ssSetInputPortVectorDimension(S, 5, 7);
    // lbx
    ssSetInputPortVectorDimension(S, 6, 98);
    // ubx
    ssSetInputPortVectorDimension(S, 7, 98);
    // lbx_e
    ssSetInputPortVectorDimension(S, 8, 2);
    // ubx_e
    ssSetInputPortVectorDimension(S, 9, 2);
    // lbu
    ssSetInputPortVectorDimension(S, 10, 300);
    // ubu
    ssSetInputPortVectorDimension(S, 11, 300);  
    // cost_W_0
    ssSetInputPortVectorDimension(S, 12, 196);  
    // cost_W
    ssSetInputPortVectorDimension(S, 13, 196);  
    // cost_W_e
    ssSetInputPortVectorDimension(S, 14, 49);/* specify dimension information for the OUTPUT ports */
    ssSetOutputPortVectorDimension(S, 0, 6 );
    ssSetOutputPortVectorDimension(S, 1, 300 );
    ssSetOutputPortVectorDimension(S, 2, 357 );
    ssSetOutputPortVectorDimension(S, 3, 1 );
    ssSetOutputPortVectorDimension(S, 4, 1 );
    ssSetOutputPortVectorDimension(S, 5, 7 ); // state at shooting node 1
    ssSetOutputPortVectorDimension(S, 6, 1);
    ssSetOutputPortVectorDimension(S, 7, 1 );

    // specify the direct feedthrough status
    // should be set to 1 for all inputs used in mdlOutputs
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortDirectFeedThrough(S, 8, 1);
    ssSetInputPortDirectFeedThrough(S, 9, 1);
    ssSetInputPortDirectFeedThrough(S, 10, 1);
    ssSetInputPortDirectFeedThrough(S, 11, 1);
    ssSetInputPortDirectFeedThrough(S, 12, 1);
    ssSetInputPortDirectFeedThrough(S, 13, 1);
    ssSetInputPortDirectFeedThrough(S, 14, 1);

    // one sample time
    ssSetNumSampleTimes(S, 1);
}


#if defined(MATLAB_MEX_FILE)

#define MDL_SET_INPUT_PORT_DIMENSION_INFO
#define MDL_SET_OUTPUT_PORT_DIMENSION_INFO

static void mdlSetInputPortDimensionInfo(SimStruct *S, int_T port, const DimsInfo_T *dimsInfo)
{
    if ( !ssSetInputPortDimensionInfo(S, port, dimsInfo) )
         return;
}

static void mdlSetOutputPortDimensionInfo(SimStruct *S, int_T port, const DimsInfo_T *dimsInfo)
{
    if ( !ssSetOutputPortDimensionInfo(S, port, dimsInfo) )
         return;
}

#endif /* MATLAB_MEX_FILE */


static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLINGTIME);
    ssSetOffsetTime(S, 0, 0.0);
}


static void mdlStart(SimStruct *S)
{
    nlp_solver_capsule *capsule = flexcar_acados_acados_create_capsule();
    flexcar_acados_acados_create(capsule);

    ssSetUserData(S, (void*)capsule);
}


static void mdlOutputs(SimStruct *S, int_T tid)
{
    nlp_solver_capsule *capsule = ssGetUserData(S);
    ocp_nlp_config *nlp_config = flexcar_acados_acados_get_nlp_config(capsule);
    ocp_nlp_dims *nlp_dims = flexcar_acados_acados_get_nlp_dims(capsule);
    ocp_nlp_in *nlp_in = flexcar_acados_acados_get_nlp_in(capsule);
    ocp_nlp_out *nlp_out = flexcar_acados_acados_get_nlp_out(capsule);

    InputRealPtrsType in_sign;            

    // local buffer
    real_t buffer[196];

    /* go through inputs */
    // lbx_0
    in_sign = ssGetInputPortRealSignalPtrs(S, 0);
    for (int i = 0; i < 7; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "lbx", buffer);
    // ubx_0
    in_sign = ssGetInputPortRealSignalPtrs(S, 1);
    for (int i = 0; i < 7; i++)
        buffer[i] = (double)(*in_sign[i]);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "ubx", buffer);
    // parameters - stage-variant !!!
    in_sign = ssGetInputPortRealSignalPtrs(S, 2);

    // update value of parameters
    for (int ii = 0; ii <= 50; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
            buffer[jj] = (double)(*in_sign[ii*3+jj]);
        flexcar_acados_acados_update_params(capsule, ii, buffer, 3);
    }

  
    // y_ref_0
    in_sign = ssGetInputPortRealSignalPtrs(S, 3);

    for (int i = 0; i < 14; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 0, "yref", (void *) buffer);

  
    // y_ref - for stages 1 to N-1
    in_sign = ssGetInputPortRealSignalPtrs(S, 4);

    for (int ii = 1; ii < 50; ii++)
    {
        for (int jj = 0; jj < 14; jj++)
            buffer[jj] = (double)(*in_sign[(ii-1)*14+jj]);
        ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, ii, "yref", (void *) buffer);
    }

  
    // y_ref_e
    in_sign = ssGetInputPortRealSignalPtrs(S, 5);

    for (int i = 0; i < 7; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 50, "yref", (void *) buffer);
    // lbx
    in_sign = ssGetInputPortRealSignalPtrs(S, 6);
    for (int ii = 1; ii < 50; ii++)
    {
        for (int jj = 0; jj < 2; jj++)
            buffer[jj] = (double)(*in_sign[(ii-1)*2+jj]);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "lbx", (void *) buffer);
    }
    // ubx
    in_sign = ssGetInputPortRealSignalPtrs(S, 7);
    for (int ii = 1; ii < 50; ii++)
    {
        for (int jj = 0; jj < 2; jj++)
            buffer[jj] = (double)(*in_sign[(ii-1)*2+jj]);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "ubx", (void *) buffer);
    }
    // lbx_e
    in_sign = ssGetInputPortRealSignalPtrs(S, 8);

    for (int i = 0; i < 2; i++)
        buffer[i] = (double)(*in_sign[i]);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 50, "lbx", buffer);
    // ubx_e
    in_sign = ssGetInputPortRealSignalPtrs(S, 9);

    for (int i = 0; i < 2; i++)
        buffer[i] = (double)(*in_sign[i]);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 50, "ubx", buffer);
    // lbu
    in_sign = ssGetInputPortRealSignalPtrs(S, 10);
    for (int ii = 0; ii < 50; ii++)
    {
        for (int jj = 0; jj < 6; jj++)
            buffer[jj] = (double)(*in_sign[ii*6+jj]);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "lbu", (void *) buffer);
    }
    // ubu
    in_sign = ssGetInputPortRealSignalPtrs(S, 11);
    for (int ii = 0; ii < 50; ii++)
    {
        for (int jj = 0; jj < 6; jj++)
            buffer[jj] = (double)(*in_sign[ii*6+jj]);
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "ubu", (void *) buffer);
    }  
    // cost_W_0
    in_sign = ssGetInputPortRealSignalPtrs(S, 12);
    for (int i = 0; i < 196; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 0, "W", buffer);  
    // cost_W
    in_sign = ssGetInputPortRealSignalPtrs(S, 13);
    for (int i = 0; i < 196; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 1; ii < 50; ii++)
        ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, ii, "W", buffer);  
    // cost_W_e
    in_sign = ssGetInputPortRealSignalPtrs(S, 14);
    for (int i = 0; i < 49; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 50, "W", buffer);

    /* call solver */
    int rti_phase = 0;
    ocp_nlp_solver_opts_set(nlp_config, capsule->nlp_opts, "rti_phase", &rti_phase);
    int acados_status = flexcar_acados_acados_solve(capsule);


    /* set outputs */
    // assign pointers to output signals
    real_t *out_u0, *out_utraj, *out_xtraj, *out_status, *out_sqp_iter, *out_KKT_res, *out_x1, *out_cpu_time;
    int tmp_int;
    out_u0 = ssGetOutputPortRealSignal(S, 0);
    ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 0, "u", (void *) out_u0);
    out_utraj = ssGetOutputPortRealSignal(S, 1);
    for (int ii = 0; ii < 50; ii++)
        ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, ii,
                        "u", (void *) (out_utraj + ii * 6));

  

    out_xtraj = ssGetOutputPortRealSignal(S, 2);
    for (int ii = 0; ii < 51; ii++)
        ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, ii,
                        "x", (void *) (out_xtraj + ii * 7));
    out_status = ssGetOutputPortRealSignal(S, 3);
    *out_status = (real_t) acados_status;
    out_KKT_res = ssGetOutputPortRealSignal(S, 4);
    *out_KKT_res = (real_t) nlp_out->inf_norm_res;
    out_x1 = ssGetOutputPortRealSignal(S, 5);
    ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 1, "x", (void *) out_x1);
    out_cpu_time = ssGetOutputPortRealSignal(S, 6);
    // get solution time
    ocp_nlp_get(nlp_config, capsule->nlp_solver, "time_tot", (void *) out_cpu_time);
    out_sqp_iter = ssGetOutputPortRealSignal(S, 7);
    // get sqp iter
    ocp_nlp_get(nlp_config, capsule->nlp_solver, "sqp_iter", (void *) &tmp_int);
    *out_sqp_iter = (real_t) tmp_int;

}

static void mdlTerminate(SimStruct *S)
{
    nlp_solver_capsule *capsule = ssGetUserData(S);

    flexcar_acados_acados_free(capsule);
    flexcar_acados_acados_free_capsule(capsule);
}


#ifdef  MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif
