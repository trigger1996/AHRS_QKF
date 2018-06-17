%%
% ˵��
% ����: �����ǣ����ȣ������ٶȣ���һ�������شţ���һ����
% ���: ��Ԫ����������ƫ��

%%
clear;
clc;
clear all;

%%
% ��ȡ����
load('data_AHRS_EKF\sensor.mat');

%%
% ����
g = 9.78;

% ������ʼ��
acc  = zeros(3, 1);
gyro = zeros(3, 1);
mag  = zeros(3, 1);
% dt = 0;										% dt ���ļ�������
X = zeros(7, 1);
P = ones(7, 7); P = P .* 1000;

%%
% ģ��������Ϣ����
wn_var  = 1e-6 * ones(1,4);% rot vel var
wbn_var = 1e-8* ones(1,3);% gyro bias change var
an_var  = 1e-1 * ones(1,3);% acc var
mn_var  = 1e-1 * ones(1,3);% mag var

% ���������������ù۲�����
Q = diag([wn_var, wbn_var]); 
R = diag([an_var, mn_var]); 

%%
% ����ʱ��
t_eof = size(IMU, 1);
%t_eof = 5;									% ������Դ����ʱ��ֻ��5��������ʱ��ע�ͱ���

%%
% ��ֵԤװ
q0 = 1; q1 = 0; q2 = 0; q3 = 0;
wx = 0; wy = 0; wz = 0;
bwx = 0; bwy = 0; bwz = 0;
X = [  q0 - (q1*(wx-bwx)*dt)/2 - (q2*(wy - bwy)*dt)/2 - (q3*(wz - bwz)*dt)/2;
	   q1 + (q0*(wx-bwx)*dt)/2 - (q3*(wy - bwy)*dt)/2 + (q2*(wz - bwz)*dt)/2;
	   q2 + (q3*(wx-bwx)*dt)/2 + (q0*(wy - bwy)*dt)/2 - (q1*(wz - bwz)*dt)/2;
	   q3 - (q2*(wx-bwx)*dt)/2 + (q1*(wy - bwy)*dt)/2 + (q0*(wz - bwz)*dt)/2;
                                                                         bwx;
                                                                         bwy;
                                                                         bwz];

%% 
% ������صı���
% EKF���
roll  = zeros(t_eof, 1);
pitch = zeros(t_eof, 1);
yaw   = zeros(t_eof, 1);
% �ο���
att_ins_ins  = zeros(t_eof, 3);
quat_ins_ins = zeros(t_eof, 4);
roll_ref  = zeros(t_eof, 1);
pitch_ref = zeros(t_eof, 1);
yaw_ref   = zeros(t_eof, 1);

att_ins_ins(1,:)  = IMU_Ref(1,1:3);
quat_ins_ins(1,:) = att2quat(att_ins_ins(1, :) * pi / 180);


%% ��ѭ��
for i = 2: t_eof
 	% ��������
	IMU(i, 4:6) = -(IMU(i,4:6)/10)*g;	
	gyro = IMU(i, 1 : 3) .* (pi / 180);				% ���������ݣ���������, ˳��: x, y, z
	acc  = IMU(i, 4 : 6)./norm(IMU(i, 4 : 6));		% ���ٶȣ���һ������
	mag  = IMU(i, 7 : 9)./norm(IMU(i, 7 : 9));		% �شţ�  ��һ������
	
 	% EKF����
 	[X, P] = ekf_func_quad_6dof(X, P, acc, gyro, mag, dt, Q, R);
	
	% ���
		% ��Ԫ��
	quat = X(1 : 4);
		% ������ƫ��
	gbias = X(5:7);	
	[roll(i), pitch(i), yaw(i)] = my_quat2att(quat);
	roll(i)  = roll(i) * (180 / pi);
	pitch(i) = pitch(i) * (180 / pi);
	yaw(i)   = yaw(i) * (180 / pi) - 8.3;
	
	% �ο�ֵ
	% ����Ĳο�ֵ��ͨ��IMUֱ�ӹ۲�õ���IMU_REF�����е�����ʵֵ
	quat_ins_ins(i, :) = my_quatmul(quat_ins_ins(i - 1, :), my_ang2quat(gyro'*dt)) .* 180 / pi;
	quat_ins_ins(i, :) = quat_ins_ins(i, :) ./ norm(quat_ins_ins(i, :));
	[roll_ref(i), pitch_ref(i), yaw_ref(i)] = my_quat2att(quat_ins_ins(i, :));
	roll_ref(i)  = roll_ref(i) * (180 / pi);
	pitch_ref(i) = pitch_ref(i) * (180 / pi);
	yaw_ref(i)   = yaw_ref(i) * (180 / pi);
end

%%
% ��ͼ
figure(1);
subplot(311);plot(roll, 'LineWidth',1.5);hold on;plot(roll_ref,  'r','LineWidth',1.5);plot(IMU_Ref(:,1),'m','LineWidth',1.5);legend('eskf simulator','pure nav','system');ylabel('roll');grid on;
subplot(312);plot(pitch,'LineWidth',1.5);hold on;plot(pitch_ref, 'r','LineWidth',1.5);plot(IMU_Ref(:,2),'m','LineWidth',1.5);grid on;ylabel('pitch');
subplot(313);plot(yaw,  'LineWidth',1.5);hold on;plot(yaw_ref,   'r','LineWidth',1.5);plot(IMU_Ref(:,3),'m','LineWidth',1.5);grid on;ylabel('yaw');

%%
