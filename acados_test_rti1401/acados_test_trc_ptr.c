/***************************************************************************

   Source file acados_test_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 7.10 (02-May-2018)
   Wed May 19 16:01:36 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "acados_test_trc_ptr.h"
#include "acados_test.h"
#include "acados_test_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_acados_test_real_T_0 = NULL;
volatile real_T *p_1_acados_test_real_T_0 = NULL;
volatile real_T *p_2_acados_test_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_acados_test_real_T_0 = &acados_test_B.vy_pred[0];
  p_1_acados_test_real_T_0 = &acados_test_P.Delay_1_InitialCondition;
  p_2_acados_test_real_T_0 = &acados_test_DW.Delay_1_DSTATE[0];
}

void acados_test_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
