function [x_post, P_post] = kalman_f(x_hat, P, meas, Q, R, t)



Phi = [eye(3) t*eye(3); zeros(3) eye(3)];

x_pri = Phi*x_hat - [0;0;t;0;0;t^2/2]*9.81;

P_pri = Phi*P*Phi' + Q;



H = [eye(3) zeros(3)];

K = P*H'/(H*P*H' + R);

x_post = x_pri + K*(meas-H*x_hat);

P_post = P_pri - K*H*P_pri;

end