clear
clc

load('NAV');

d2r = pi/180;
r2d = 180/pi;
g = 9.7803253361;

NAV = NAV;

Freq = 50;

dt = 0.02;                      %%����Ƶ��

IMU(:,1:3) = NAV(:,12:14)*r2d;      %%��������(deg/s)
IMU(:,4:6) = -NAV(:,9:11)*10;       %%�ӱ�����(g)
IMU(:,7:9) = NAV(:,15:17);      %%����������

IMU_Ref(:,1:3) = NAV(:,30:32)*r2d;  %%��̬��
IMU_Ref(:,4:6) = NAV(:,21:23);  %%�ٶ�
IMU_Ref(:,7) = NAV(:,19);  %%λ��
IMU_Ref(:,8) = NAV(:,18);  %%λ��
IMU_Ref(:,9) = NAV(:,20);  %%λ��

GNSS(:,1:3) = NAV(:,6:8);       %%GNSS�ٶ�
GNSS(:,4) = NAV(:,3);       %%GNSSλ��
GNSS(:,5) = NAV(:,2);       %%GNSSλ��
GNSS(:,6) = NAV(:,4);       %%GNSSλ��
GNSS(:,7) = NAV(:,5);           %%��ѹ�߶�

save sensor.mat IMU IMU_Ref GNSS dt Freq;