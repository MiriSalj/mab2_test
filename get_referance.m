function [x_ref, x_upper_bound, x_lower_bound, Y_ref, Psi_ref] = get_referance()
shape = 2.4;
d_x1 = 25;
d_x2 = 21.95;
d_y1 = 4.05; 
d_y2 = 5.7; 
Xs1 = 27.19; 
Xs2 = 56.46;

Psi_ref = @(X) atan(d_y1 * (1./cosh(shape/d_x1 * (X - Xs1) - shape/2)).^2 ...
            * (1.2/d_x1) - d_y2 * (1./cosh(shape/d_x2 * (X - Xs2) - shape/2)).^2 ...
            * (1.2/d_x2));
Psi_upper = @(X) atan(d_y1 * (1./cosh(shape/d_x1 * (X - Xs1) - shape/2)).^2 ...
            * (1.2/d_x1) - d_y2 * (1./cosh(shape/d_x2 * (X - Xs2) - shape/2)).^2 ...
            * (1.2/d_x2)) + deg2rad(30);    %max. = +5 deg. deviation from Psi_ref
Psi_lower = @(X) atan(d_y1 * (1./cosh(shape/d_x1 * (X - Xs1) - shape/2)).^2 ...
            * (1.2/d_x1) - d_y2 * (1./cosh(shape/d_x2 * (X - Xs2) - shape/2)).^2 ...
            * (1.2/d_x2)) - deg2rad(30);    %min. = -5 deg. deviation from Psi_ref
        
                
Y_ref = @(X) d_y1/2 * (1+tanh(shape/d_x1 * (X - Xs1) - shape/2)) ...
            - d_y2/2 * (1+tanh(shape/d_x2 * (X - Xs2) - shape/2));
Y_upper = @(X) d_y1/2 * (1+tanh(shape/d_x1 * (X - Xs1) - shape/2)) ...
            - d_y2/2 * (1+tanh(shape/d_x2 * (X - Xs2) - shape/2)) + 0.2; %max. =  +0.1m deviation from Y_ref       
Y_lower = @(X) d_y1/2 * (1+tanh(shape/d_x1 * (X - Xs1) - shape/2)) ...
            - d_y2/2 * (1+tanh(shape/d_x2 * (X - Xs2) - shape/2)) - 0.2; %min. =  -0.1m deviation from Y_ref       

     
x_ref = {Y_ref; Psi_ref};   

x_upper_bound = {Y_upper; Psi_upper};

x_lower_bound = {Y_lower; Psi_lower};   

end
