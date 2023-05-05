s = serialport('COM5', 115200);

position = animatedline('Color', 'black', 'MaximumNumPoints', 100);
while 1>0
fopen(s);
fscanf(s);
disp(ans)
view(3)

theta1 = str2double(extractBefore(ans, ' '));
theta2 = str2double(extractBetween(ans, ' ',','));
dist = str2double(extractAfter(ans, ','));
theta1 = deg2rad(theta1);
theta2 = deg2rad(theta2);
[x, y, z] = pol2cart(theta1, theta2, dist);

addpoints(position, x, y, z);
drawnow
end




