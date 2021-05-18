%
% Copyright 2019 Gianluca Frison, Dimitris Kouzoupis, Robin Verschueren,
% Andrea Zanelli, Niels van Duijkeren, Jonathan Frey, Tommaso Sartor,
% Branimir Novoselnik, Rien Quirynen, Rezart Qelibari, Dang Doan,
% Jonas Koenemann, Yutao Chen, Tobias Schöls, Jonas Schlagenhauf, Moritz Diehl
%
% This file is part of acados.
%
% The 2-Clause BSD License
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
% 1. Redistributions of source code must retain the above copyright notice,
% this list of conditions and the following disclaimer.
%
% 2. Redistributions in binary form must reproduce the above copyright notice,
% this list of conditions and the following disclaimer in the documentation
% and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.;
%

SOURCES = { ...
            'flexcar_acados_model/flexcar_acados_expl_ode_fun.c', ...
            'flexcar_acados_model/flexcar_acados_expl_vde_forw.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_0_fun.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_0_fun_jac_ut_xt.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_0_hess.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_fun.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_fun_jac_ut_xt.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_hess.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_e_fun.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_e_fun_jac_ut_xt.c',...
            'flexcar_acados_cost/flexcar_acados_cost_y_e_hess.c',...
            'acados_solver_sfunction_flexcar_acados.c', ...
            'acados_solver_flexcar_acados.c'
          };

INC_PATH = 'D:\acados\examples\acados_matlab_octave\..\../include';

INCS = {['-I', fullfile(INC_PATH, 'blasfeo', 'include')], ...
        ['-I', fullfile(INC_PATH, 'hpipm', 'include')], ...
        ['-I', fullfile(INC_PATH, 'acados')], ...
        ['-I', fullfile(INC_PATH)]};



CFLAGS = 'CFLAGS=$CFLAGS';
LDFLAGS = 'LDFLAGS=$LDFLAGS';



LIB_PATH = ['-L', fullfile('D:\acados\examples\acados_matlab_octave\..\../lib')];

LIBS = {'-lacados', '-lhpipm', '-lblasfeo'};

% acados linking libraries and flags
CFLAGS = [CFLAGS ' '];
LDFLAGS = [LDFLAGS ' '];
LIBS{end+1} = '';
LIBS{end+1} = '';
LIBS{end+1} = '-losqp';

mex('-v', '-O', CFLAGS, LDFLAGS, INCS{:}, ...
    LIB_PATH, LIBS{:}, SOURCES{:}, ...
    '-output', 'acados_solver_sfunction_flexcar_acados' );

fprintf( [ '\n\nSuccessfully created sfunction:\nacados_solver_sfunction_flexcar_acados', '.', ...
    eval('mexext')] );


%% print note on usage of s-function
fprintf('\n\nNote: Usage of Sfunction is as follows:\n')
input_note = 'Inputs are:\n';
i_in = 1;
input_note = strcat(input_note, num2str(i_in), ') lbx_0 - lower bound on x for stage 0,',...
                    ' size [7]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') ubx_0 - upper bound on x for stage 0,',...
                    ' size [7]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') parameters - concatenated for all shooting nodes 0 to N+1,',...
                    ' size [153]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') y_ref_0, size [14]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') y_ref - concatenated for shooting nodes 1 to N-1,',...
                    ' size [686]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') y_ref_e, size [7]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') lbx for shooting nodes 1 to N-1, size [98]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') ubx for shooting nodes 1 to N-1, size [98]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') lbx_e (lbx at shooting node N), size [2]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') ubx_e (ubx at shooting node N), size [2]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') lbu for shooting nodes 0 to N-1, size [300]\n ');
i_in = i_in + 1;
input_note = strcat(input_note, num2str(i_in), ') ubu for shooting nodes 0 to N-1, size [300]\n ');
i_in = i_in + 1;  
input_note = strcat(input_note, num2str(i_in), ') cost_W_0 in column-major format, size [196]\n ');
i_in = i_in + 1;  
input_note = strcat(input_note, num2str(i_in), ') cost_W in column-major format, that is set for all intermediate shooting nodes: 1 to N-1, size [196]\n ');
i_in = i_in + 1;  
input_note = strcat(input_note, num2str(i_in), ') cost_W_e in column-major format, size [49]\n ');
i_in = i_in + 1;

fprintf(input_note)

disp(' ')

output_note = 'Outputs are:\n';
i_out = 0;
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') u0, control input at node 0, size [6]\n ');
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') utraj, control input concatenated for nodes 0 to N-1, size [300]\n ');
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') xtraj, state concatenated for nodes 0 to N, size [357]\n ');
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') acados solver status (0 = SUCCESS)\n ');
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') KKT residual\n ');
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') x1, state at node 1\n ');
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') CPU time\n ');
i_out = i_out + 1;
output_note = strcat(output_note, num2str(i_out), ') SQP iterations\n ');

fprintf(output_note)
