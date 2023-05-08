s = serialport('COM5', 115200); % read serialport for data

% uncertainties in meaasurements (a guess)
sigma_r = 0.1; 
sigma_azimuth = 0.1;
sigma_elevation = 0.1; 

% kalman inputs
t = 0.1;
v = [sigma_r^2, sigma_azimuth^2, sigma_elevation^2];
R = diag(v);
Q = eye(6, 6) * t^2; 
P = blkdiag(eye(3) * sigma_r^2, eye(3) * sigma_r^2/10);

% set up plots
position = animatedline('Color', 'black', 'MaximumNumPoints', 10);
predicted = animatedline('Color', 'r', 'MaximumNumPoints', 10);

% go into main loop
while 1>0
    % read serial port
fopen(s);
fscanf(s);
disp(ans)

% initial guess for position
x_prev = 0;
y_prev = 0;
z_prev = 0;

% get actual data from serialport and convert to numerical
pos_prev = [x_prev, y_prev, z_prev];
theta1 = str2double(extractBefore(ans, ' '));
theta2 = str2double(extractBetween(ans, ' ',','));
dist = str2double(extractAfter(ans, ','));
theta1 = deg2rad(theta1);
theta2 = deg2rad(theta2);
[x, y, z] = pol2cart(theta1, theta2, dist);
pos = [x, y, z];
 
% get velo
vx = (x - x_prev)/0.1;
vy = (y-y_prev)/0.1;
vz = (z-z_prev)/0.1;
%x_pred = x + vx*t;
%y_pred = y +vy*t;
%z_pred = z +vz * t;
%pos_pred = [x_pred, y_pred, z_pred];


x_hat = [x; y; z; vx; vy; vz;]; % state space vector
% call kalman to predict position
[x_post, P_post] = kalman_f(x_hat, P, pos, Q, R, t); 

% plot everything
figure(1)
view(3);
addpoints(position, x, y, z);
hold on
addpoints(predicted, x_post(1), x_post(2), x_post(3));
drawnow


end




