function model = vehicle_model(x, xdot, u, p, N, T, delta, nx, nu)
        import casadi.*
        sym_x = vertcat(x(1), x(2), x(3), x(4), x(5), x(6), x(7));
        sym_u = vertcat(u(1), u(2), u(3), u(4), u(5), u(6));
        sym_xdot = vertcat(xdot(1), xdot(2), xdot(3), xdot(4), xdot(5), xdot(6), xdot(7));
        sym_p = vertcat(p(1), p(2), p(3));
        rdyn = sym_p(2);
        sym_Fx = sum(u(3:6))/rdyn;
        vx = sym_p(3);

        m = 1000;                                                       %Masse [kg]
        Izz = 1.7183e3;                                                 %Trägheitsmoment um z-Achse [kg * m^2]
        lF = 1.25;                                                      %Schwerpunkt-Vorderachse Länge [m]
        lR = 1.25;                                                      %Schwerpunkt-Hinterachse Länge [m]
        sF = 1.5;                                                       %Spurweite Front Axle [m]
        sR = 1.5;                                                       %Spurweite Rear Axle [m]
        EST_cF = 1.5349e+05;                                            %Cornering-Stiffness Front [N/rad]
        EST_cR = 1.56618e+05;                                           %Cornering-Stiffness Rear [N/rad]
        EST_zw   = 0.3775;                                              %Wankhebelarm [m]

        Ixx  = 400;                                                     %Wankträgheitsmoment  [kg * m^2]
        cw   = 7.8027e+04;                                              %Wanksteifigkeit
        dw   = 1850;                                                    %Wankdämpfung
        R    = -17.4194;                                                %Lenkuebersetzung

        % ESTM (roll extented single-track model); 
        % x_ESTM =[psidot, beta, phi , phidot]  
        % xdot_ESTM =[psiddot, betadot, phidot, phiddot]
        % u_ESTM = [deltaF, deltaR] mit vy = beta * vx <--> beta = vy/vx
        A_ESTM = [ -(EST_cF*lF^2 + EST_cR*lR^2)/(Izz*vx),          -(EST_cF*lF - EST_cR*lR)/Izz,        0,          -(EST_zw*(EST_cF*lF - EST_cR*lR))/(Izz*vx);
                   -(m*vx^2 + EST_cF*lF - EST_cR*lR)/(m*vx^2),     -(EST_cF + EST_cR)/(m*vx),           0,          -(EST_zw*(EST_cF + EST_cR))/(m*vx^2);
                    0,                                              0,                                  0,          1;
                   -(EST_zw*(EST_cF*lF - EST_cR*lR))/(Ixx*vx),     -(EST_zw*(EST_cF + EST_cR))/Ixx,     -cw/Ixx,    -(dw*vx + EST_cF*EST_zw^2 + EST_cR*EST_zw^2)/(Ixx*vx)];

        B_ESTM = [(EST_cF*lF)/Izz,      -(EST_cR*lR)/Izz ,      1/Izz;
                   EST_cF/(m*vx),       EST_cR/(m*vx),          0;
                   0,                   0,                      0;
                  (EST_cF*EST_zw)/Ixx,  (EST_cR*EST_zw)/Ixx,    0];

              
        % Total Yaw Moment  
        Mz_TV = -(u(3)/rdyn)*sF/2 + (u(4)/rdyn)*sF/2 -(u(5)/rdyn)*sR/2 + (u(6)/rdyn)*sR/2;

        xdot_ESTM = A_ESTM * [x(2);x(1)/vx;x(7);x(6)] + B_ESTM*[u(1); u(2); Mz_TV]; 

        vxdot_ESTM = 0;

        %vydot = betadot * vx + beta * vxdot; 
        f_expl = [   cos(x(1)/vx)*xdot_ESTM(2)*vx + x(1)/vx * vxdot_ESTM ;
                     xdot_ESTM(1) ;                                     % x  = [vy, psidot, psi, X, Y, phidot, phi];
                     x(2);                                              % xdot = [vydot, psiddot, psidot, Xdot, Ydot, phiddot, phidot] 
                     vx * cos(x(3)) - x(1) * sin(x(3));
                     vx * sin(x(3)) + x(1) * cos(x(3));
                     xdot_ESTM(4);
                     xdot_ESTM(3);
                            ];
                 
        %% constraints
        expr_h = vertcat(sym_u); %constraints on u only
        %% cost
        % nonlinear least squares
        cost_expr_y = vertcat(sym_x, sym_u, sym_Fx);

        x0 = 0.01*ones(nx, 1);
     
        %% populate structure
        model = struct();
        
        model.nx = nx;
        model.nu = nu;
        model.x0 = x0;
        model.sym_x = sym_x;
        model.sym_xdot = sym_xdot;
        model.sym_u = sym_u;
        model.sym_p = sym_p;

        model.expr_f_impl = f_expl - sym_xdot;
        model.expr_f_expl = f_expl;
        model.expr_h = expr_h;

        model.cost_expr_y = cost_expr_y;
        model.cost_expr_y_e = sym_x;

        model.T = T;
        model.N = N;
        model.delta = delta;
        model.vmax = vx;
        model.m = m; 
        model.Iz = Izz; 
        model.lf = lF; 
        model.lr = lR;
        model.Caf = EST_cF; 
        model.Car = EST_cR;

end            