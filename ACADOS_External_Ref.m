%% Set Up ACADOS
import casadi.*

model_path = fullfile('d:\', 'acados', 'examples', 'acados_matlab_octave', ...
    'getting_started'); %"Check acados requirements" is there
addpath(model_path);

env = fullfile('d:\', 'acados', 'examples', 'acados_matlab_octave', ...
    'acados_env_variables_windows.m');

run(env);
check_acados_requirements()

% system dimensions
n = 7; % state dimension
nu = 6; % input dimension

vmax = 36/3.6;

T = 0.5; % Time horizon
delta = 0.01; %Discretization steps

N = T/delta; % number of control intervals

%% Declare CASADI Variables
% Declare state variables
x1 = SX.sym('x1');
x2 = SX.sym('x2');
x3 = SX.sym('x3');
x4 = SX.sym('x4');
x5 = SX.sym('x5');
x6 = SX.sym('x6');
x7 = SX.sym('x7');

x = [x1; x2; x3; x4; x5; x6; x7];

% Declare state derivative variables
x1dot = SX.sym('x1dot');
x2dot = SX.sym('x2dot');
x3dot = SX.sym('x3dot');
x4dot = SX.sym('x4dot');
x5dot = SX.sym('x5dot');
x6dot = SX.sym('x6dot');
x7dot = SX.sym('x7dot');

xdot = [x1dot; x2dot; x3dot; x4dot; x5dot; x6dot; x7dot];

% Declare Input Variables
u1 = SX.sym('u1');
u2 = SX.sym('u2');
u3 = SX.sym('u3');
u4 = SX.sym('u4');
u5 = SX.sym('u5');
u6 = SX.sym('u6');
u = [u1; u2; u3; u4; u5; u6];

% Declare Parameters
% p1 = SX.sym('p1', 10, 1); %for X
% p2 = SX.sym('p2', 10, 1); %for Y
% p3 = SX.sym('p3', 10, 1); %for Psi
p1 = SX.sym('p1'); %for REF_Fx
p2 = SX.sym('p2'); %for rdyn
% p3 = SX.sym('p3'); %for Q11_normal
% p4 = SX.sym('p4'); %for Q22_normal
% p5 = SX.sym('p5'); %for Q33_normal
% p6 = SX.sym('p6'); %for R11_normal
% p7 = SX.sym('p7'); %for R22_normal
% p8 = SX.sym('p8'); %for R33_normal
% p9 = SX.sym('p9'); %for R44_normal
% p10 = SX.sym('p10'); %for R55_normal
% p11 = SX.sym('p11'); %for R66_normal
p3 = SX.sym('p3'); %for vx
% % p16 = SX.sym('p16', 10, 1); %Reference for X
% % p17 = SX.sym('p17', 10, 1); %Reference for Y
% % p18 = SX.sym('p18', 10, 1); %Reference for Psi
% % p = [p1; p2; p3; p4; p5; p6; p7; p8; p9; p10; p11; p12; p13; p14; p15; p16; p17; p18];
p = vertcat(p1, p2, p3);
% p = [p1; p2; p3; p4; p5];
% p = [p1; p2];

%Init params
p0 = [10; 0.315; 10];

% % Declare Spline for the Reference Trajectory
% % see: casadi.sourceforge.net/api/html/de/dbe/group__interpolant.html
% N_refpath = 11;
% xgrid = 1:delta:N;
% y_wp = SX.sym('y_traj', N_refpath, 1); %Waypoints for Y
% psi_wp = SX.sym('psi_traj', N_refpath, 1); %Waypoints for Y
% initial conditions
% t_0 = 0.0;
% x_init = 0.0*ones(7, 1);


%% Discretization
% compile_interface = 'auto';
codgen_model = 'true';
%nlp_solver = 'sqp_rti'; % sqp, sqp_rti
nlp_solver = 'sqp';
qp_solver = 'partial_condensing_hpipm';
% full_condensing_hpipm, partial_condensing_hpipm, full_condensing_qpoases
nlp_solver_exact_hessian = 'false'; % false=gauss_newton, true=exact    
qp_solver_cond_N = 5; % for partial condensing
% integrator type
sim_method = 'erk'; % erk, irk, irk_gnsf
%Model equations
model = vehicle_model(x, xdot, u, p, N, T, delta, n, nu);

nx = model.nx;
nu = model.nu;

xmeasure = model.x0;

%% get available simulink_opts with default options
simulink_opts = get_acados_simulink_opts;

% manipulate simulink_opts
simulink_opts.samplingtime = '-1';
    % 't0' (default) - use time step between shooting node 0 and 1
    % '-1' - inherit sampling time from other parts of simulink model
% inputs
simulink_opts.inputs.y_ref = 1;
simulink_opts.inputs.lbx = 1;
simulink_opts.inputs.ubx = 1;
simulink_opts.inputs.lbx_e = 1;
simulink_opts.inputs.ubx_e = 1;
simulink_opts.inputs.cost_W_0 = 1;
simulink_opts.inputs.cost_W = 1;
simulink_opts.inputs.cost_W_e = 1;

% simulink_opts.inputs.cost_W = eye(14);
% simulink_opts.inputs.cost_W_e = eye(7);

% outputs
simulink_opts.outputs.utraj = 1;
simulink_opts.outputs.xtraj = 1;

%% model to create the solver
ocp_model = acados_ocp_model();
model_name = 'flexcar_acados';

%% acados ocp model
ocp_model.set('name', model_name);
ocp_model.set('T', T);

% dynamics
if (strcmp(sim_method, 'erk'))
    ocp_model.set('dyn_type', 'explicit');
    ocp_model.set('dyn_expr_f', model.expr_f_expl);
else % irk irk_gnsf
    ocp_model.set('dyn_type', 'implicit');
    ocp_model.set('dyn_expr_f', model.expr_f_impl);
end

% symbolics
ocp_model.set('sym_x', model.sym_x);
ocp_model.set('sym_u', model.sym_u);
ocp_model.set('sym_xdot', model.sym_xdot);
ocp_model.set('sym_p', model.sym_p);

ny = nx + nu;
ny_e = nx;
n_Mx = 1; %in order to track required, total torque to meet the reference velocity

%% Cost
W = ones(14, 14);
W_e = ones(7, 7);

ocp_model.set('cost_type', 'nonlinear_ls');
ocp_model.set('cost_type_e', 'nonlinear_ls');
% set intial references
y_ref = zeros(nx+nu+n_Mx,1);
y_ref_e = zeros(nx,1);

ocp_model.set('cost_expr_y', model.cost_expr_y);
ocp_model.set('cost_expr_y_e', model.cost_expr_y_e);
ocp_model.set('cost_W', W);
ocp_model.set('cost_W_e', W_e);
% ocp_model.set('sym_p', p0);
% ocp_model.set('cost_y_ref', y_ref);
% ocp_model.set('cost_y_ref_e', y_ref_e);

% W_x = simulink_opts.inputs.cost_W(1:nx, 1:nx);
% W_u = simulink_opts.inputs.cost_W(nx+1:nx+nu, nx+1:nx+nu);
% W_Mx = simulink_opts.inputs.cost_W(nx+nu+1:nx+nu+n_Mx, nx+nu+1:nx+nu+n_Mx);

% [expr_ext_cost_e, expr_ext_cost] = cost_constraint_function(...
%     nx,  model.cost_expr_y, p, ocp_model, W_x, W_u, W_Mx);
% ocp_model.set('cost_expr_ext_cost', expr_ext_cost);
% ocp_model.set('cost_expr_ext_cost_e', expr_ext_cost_e);

%% constraints
ocp_model.set('constr_type', 'auto');
ocp_model.set('constr_expr_h', model.expr_h);
U_max = [deg2rad(23); deg2rad(23); 50*ones(4, 1)]; %23 deg for steering, 50Nm Torque Limit for each e drive
ocp_model.set('constr_uh', U_max);  % upper bound on h
ocp_model.set('constr_lh', -U_max); % lower bound on h
%X = [vy, psidot, psi, X, Y, phidot, phi]
X_max = [inf; deg2rad(10); inf; inf; inf; inf; inf];
%             ocp_model.set('constr_lbx', -X_max); %% TODO: Implement constraints properly 
%             ocp_model.set('constr_ubx', X_max);
ocp_model.set('constr_lbx_0', -X_max);
ocp_model.set('constr_ubx_0', X_max);
ocp_model.set('constr_x0', xmeasure);
% ... see ocp_model.model_struct to see what other fields can be set

nbx = 2;
Jbx = zeros(nbx,nx);
Jbx(1,3) = 1;      %For psi
Jbx(2,5) = 1;      %For Y
lbx = [y_ref(3) - deg2rad(1); y_ref(5) - 0.1];
ubx = [y_ref(3) + deg2rad(1); y_ref(5) + 0.1];
ocp_model.set('constr_Jbx', Jbx);
ocp_model.set('constr_lbx', lbx);
ocp_model.set('constr_ubx', ubx);

Jbx_e = Jbx;       
lbx_e = [y_ref(3) - deg2rad(0.1); y_ref(5) - 0.05];
ubx_e = [y_ref(3) + deg2rad(0.1); y_ref(5) + 0.05];
ocp_model.set('constr_Jbx_e', Jbx_e);
ocp_model.set('constr_lbx_e', lbx_e);
ocp_model.set('constr_ubx_e', ubx_e);

%% acados ocp set opts
ocp_opts = acados_ocp_opts();
% ocp_opts.set('compile_interface', compile_interface);
%ocp_opts.set('codgen_model', codgen_model);
ocp_opts.set('param_scheme_N', N);
ocp_opts.set('nlp_solver', nlp_solver);
%ocp_opts.set('nlp_solver_exact_hessian', nlp_solver_exact_hessian); 
ocp_opts.set('sim_method', sim_method);
ocp_opts.set('qp_solver', qp_solver);
ocp_opts.set('qp_solver_cond_N', qp_solver_cond_N);
%ocp_opts.set('regularize_method', 'no_regularize');
% ocp_opts.set('nlp_solver_tol_stat', 1e-4);
% ocp_opts.set('nlp_solver_tol_eq', 1e-4);
% ocp_opts.set('nlp_solver_tol_ineq', 1e-4);
% ocp_opts.set('nlp_solver_tol_comp', 1e-4);
% ... see ocp_opts.opts_struct to see what other fields can be set


%% create ocp solver
ocp = acados_ocp(ocp_model, ocp_opts);
% 
% for jj = 0:N
%     ocp.set('p', p0, jj);
% end


%% Acados sim model
sim_model = acados_sim_model();
% dims
sim_model.set('dim_nx', nx);
sim_model.set('dim_nu', nu);
sim_model.set('dim_np', 3);
% symbolics
sim_model.set('sym_x', model.sym_x);
sim_model.set('sym_u', model.sym_u);
% sim_model.set('sym_z', model.sym_z);
sim_model.set('sym_xdot', model.sym_xdot);
sim_model.set('sym_p', model.sym_p);

% model
sim_model.set('T', N);
if (strcmp(sim_method, 'erk'))
    sim_model.set('dyn_type', 'explicit');
    sim_model.set('dyn_expr_f', model.expr_f_expl);
else % irk
    sim_model.set('dyn_type', 'implicit');
    sim_model.set('dyn_expr_f', model.expr_f_impl);
end

%% acados sim opts
sim_opts = acados_sim_opts();
% sim_opts.set('compile_interface', compile_mex);
% sim_opts.set('codgen_model', codgen_model);
% sim_opts.set('num_stages', sim_num_stages);
% sim_opts.set('num_steps', sim_num_steps);
% sim_opts.set('method', sim_method);
% sim_opts.set('sens_forw', sim_sens_forw);

%% acados sim
% create sim
% sim = acados_sim(sim_model, sim_opts);

x_traj_init = 0.01*ones(nx, N+1);
u_traj_init = 0.001*ones(nu, N);

% set trajectory initialization
ocp.set('init_x', x_traj_init);
ocp.set('init_u', u_traj_init);
ocp.set('p', p0);

% solve
ocp.solve();
% get solution
utraj = ocp.get('u');
xtraj = ocp.get('x');


% %% Create warmstart for next iteration
% x_traj_init = [xtraj(:, 2:end), xtraj(:, end)];
% u_traj_init = [utraj(:, 2:end), utraj(:, end)];

% Generate C-Code
ocp.generate_c_code(simulink_opts);

%             'flexcar_acados_cost/flexcar_acados_cost_y_0_fun.c ',...
%             'flexcar_acados_cost/flexcar_acados_cost_y_0_fun_jac_ut_xt.c ',...
%             'flexcar_acados_cost/flexcar_acados_cost_y_0_hess.c ',...

