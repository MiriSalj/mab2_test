/*********************** dSPACE target specific file *************************

   Header file acados_test_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.10 (02-May-2018)
   Wed May 19 15:48:56 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_acados_test_trc_ptr_h_
#define RTI_HEADER_acados_test_trc_ptr_h_

/* Include the model header file. */
#include "acados_test.h"
#include "acados_test_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_acados_test_real_T_0;
EXTERN_C volatile real_T *p_1_acados_test_real_T_0;
EXTERN_C volatile real_T *p_2_acados_test_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void acados_test_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_acados_test_trc_ptr_h_ */
