/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) flexcar_acados_cost_ext_cost_fun_jac_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

static const casadi_int casadi_s0[11] = {7, 1, 0, 7, 0, 1, 2, 3, 4, 5, 6};
static const casadi_int casadi_s1[10] = {6, 1, 0, 6, 0, 1, 2, 3, 4, 5};
static const casadi_int casadi_s2[15] = {11, 1, 0, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static const casadi_int casadi_s3[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s4[17] = {13, 1, 0, 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

/* flexcar_acados_cost_ext_cost_fun_jac:(i0[7],i1[6],i2[11])->(o0,o1[13]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a3, a4, a5, a6, a7, a8, a9;
  a0=1.0000000000000001e-001;
  a1=arg[0]? arg[0][2] : 0;
  a2=(a0*a1);
  a3=(a2*a1);
  a4=9.9999999999999995e-008;
  a5=arg[0]? arg[0][3] : 0;
  a6=(a4*a5);
  a7=(a6*a5);
  a3=(a3+a7);
  a7=1.2538213631654671e-006;
  a8=arg[2]? arg[2][0] : 0;
  a9=arg[1]? arg[1][2] : 0;
  a10=arg[1]? arg[1][3] : 0;
  a11=(a9+a10);
  a12=arg[1]? arg[1][4] : 0;
  a11=(a11+a12);
  a13=arg[1]? arg[1][5] : 0;
  a11=(a11+a13);
  a14=arg[2]? arg[2][1] : 0;
  a11=(a11/a14);
  a8=(a8-a11);
  a11=(a7*a8);
  a15=(a11*a8);
  a3=(a3+a15);
  a15=(a0*a1);
  a16=(a15*a1);
  a17=(a4*a5);
  a18=(a17*a5);
  a16=(a16+a18);
  a18=10.;
  a19=arg[1]? arg[1][0] : 0;
  a20=(a18*a19);
  a21=(a20*a19);
  a16=(a16+a21);
  a21=arg[1]? arg[1][1] : 0;
  a22=(a18*a21);
  a23=(a22*a21);
  a16=(a16+a23);
  a23=1.1432725591073070e-006;
  a24=(a23*a9);
  a25=(a24*a9);
  a16=(a16+a25);
  a25=(a23*a10);
  a26=(a25*a10);
  a16=(a16+a26);
  a26=(a23*a12);
  a27=(a26*a12);
  a16=(a16+a27);
  a27=(a23*a13);
  a28=(a27*a13);
  a16=(a16+a28);
  a3=(a3+a16);
  if (res[0]!=0) res[0][0]=a3;
  a19=(a18*a19);
  a20=(a20+a19);
  if (res[1]!=0) res[1][0]=a20;
  a18=(a18*a21);
  a22=(a22+a18);
  if (res[1]!=0) res[1][1]=a22;
  a9=(a23*a9);
  a24=(a24+a9);
  a7=(a7*a8);
  a11=(a11+a7);
  a11=(a11/a14);
  a24=(a24-a11);
  if (res[1]!=0) res[1][2]=a24;
  a10=(a23*a10);
  a25=(a25+a10);
  a25=(a25-a11);
  if (res[1]!=0) res[1][3]=a25;
  a12=(a23*a12);
  a26=(a26+a12);
  a26=(a26-a11);
  if (res[1]!=0) res[1][4]=a26;
  a23=(a23*a13);
  a27=(a27+a23);
  a27=(a27-a11);
  if (res[1]!=0) res[1][5]=a27;
  a27=0.;
  if (res[1]!=0) res[1][6]=a27;
  if (res[1]!=0) res[1][7]=a27;
  a11=(a0*a1);
  a15=(a15+a11);
  a15=(a15+a2);
  a0=(a0*a1);
  a15=(a15+a0);
  if (res[1]!=0) res[1][8]=a15;
  a15=(a4*a5);
  a17=(a17+a15);
  a17=(a17+a6);
  a4=(a4*a5);
  a17=(a17+a4);
  if (res[1]!=0) res[1][9]=a17;
  if (res[1]!=0) res[1][10]=a27;
  if (res[1]!=0) res[1][11]=a27;
  if (res[1]!=0) res[1][12]=a27;
  return 0;
}

CASADI_SYMBOL_EXPORT int flexcar_acados_cost_ext_cost_fun_jac(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int flexcar_acados_cost_ext_cost_fun_jac_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int flexcar_acados_cost_ext_cost_fun_jac_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void flexcar_acados_cost_ext_cost_fun_jac_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int flexcar_acados_cost_ext_cost_fun_jac_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void flexcar_acados_cost_ext_cost_fun_jac_release(int mem) {
}

CASADI_SYMBOL_EXPORT void flexcar_acados_cost_ext_cost_fun_jac_incref(void) {
}

CASADI_SYMBOL_EXPORT void flexcar_acados_cost_ext_cost_fun_jac_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int flexcar_acados_cost_ext_cost_fun_jac_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int flexcar_acados_cost_ext_cost_fun_jac_n_out(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_real flexcar_acados_cost_ext_cost_fun_jac_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* flexcar_acados_cost_ext_cost_fun_jac_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* flexcar_acados_cost_ext_cost_fun_jac_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* flexcar_acados_cost_ext_cost_fun_jac_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    case 2: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* flexcar_acados_cost_ext_cost_fun_jac_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int flexcar_acados_cost_ext_cost_fun_jac_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
