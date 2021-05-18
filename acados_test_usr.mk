# =============================================================================
#  Make include file acados_test_usr.mk:
#
#   RTI1401 7.10 (02-May-2018)
#   Sat Apr 24 13:44:57 2021
#
#   Copyright 2018, dSPACE GmbH. All rights reserved. Brand names
#   or product names are trademarks or registered trademarks of their
#   respective companies or organizations.
# =============================================================================

# =============================================================================
# ===== Define file version macro. Never change this value. ===================
# =============================================================================
USER_MAKEFILE_VERSION = 2
# =============================================================================

# -----------------------------------------------------------------------------
# Macros for user-specific settings.
#
# All macros below may list several items (files or directories). You can
# separate multiple items with blanks or list them on several lines using
# the \ (backslash) as line continuation character.
#
# The directory names may include absolute or partial path
# descriptions, e.g., ".\project1\sources"
#
# If path names contain white space characters they need to be set
# in double quotes (").
# White space characters and double quotes are not supported
# with file names like "my source.c".
#
# Note that white space characters and double quotes with path
# names are available since RTI/RTI-MP of dSPACE Release 6.0.
# Such paths do not work with previous versions of RTI/RTI-MP.
#
# Examples:
#
# USER_SRCS = file1.c file2.c file3.c
#
# USER_SRCS = \
#   file1.c \
#   file2.c \
#   file3.c
#
# SFCN_DIR = \
#   "\project one\sfcns" \
#   "\project two\sfcns"
#
# -----------------------------------------------------------------------------

# Directories where S-Function C source files are stored.
SFCN_DIR = \
"\c_generated_code" \
"\c_generated_code\flexcar_acados_model" \
"\c_generated_code\flexcar_acados_cost" 

# Additional C source files to be compiled (file name extension .c).
USER_SRCS = \
flexcar_acados_expl_ode_fun.c \
flexcar_acados_expl_vde_forw.c \
flexcar_acados_cost_y_fun.c \
flexcar_acados_cost_y_fun_jac_ut_xt.c \
flexcar_acados_cost_y_hess.c \
flexcar_acados_cost_y_e_fun.c \
flexcar_acados_cost_y_e_fun_jac_ut_xt.c \
flexcar_acados_cost_y_e_hess.c \
flexcar_acados_cost_y_0_fun.c \
flexcar_acados_cost_y_0_fun_jac_ut_xt.c \
flexcar_acados_cost_y_0_hess.c \
acados_solver_flexcar_acados.c \
acados_sim_solver_flexcar_acados.c 

# Additional assembler source files to be compiled (file name extension .asm).
USER_ASM_SRCS =

# Directories where additional C and assembler source files are stored.
USER_SRCS_DIR =

# Path names for user include files.
USER_INCLUDES_PATH = \
"include" \
"include\blasfeo\include" \
"include\hpipm\include"

# Additional user object files to be linked.
USER_OBJS =

# Additional user libraries to be linked.
USER_LIBS = \
lib\blasfeo.lib \
lib\hpipm.lib \
lib\acados.lib

# EOF -------------------------------------------------------------------------
