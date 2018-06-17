function [X, P]=ekf_func_quad_6dof(X, P, acc, gyro, mag, dt, Q, R)

    q0 = X(1);    q1 = X(2);    q2 = X(3);    q3 = X(4);
	wx = gyro(1); wy = gyro(2); wz = gyro(3);
	bwx = X(5);   bwy = X(6);   bwz = X(7);					% gyro bias
	
	% ������ģ��
	Z = [acc, mag];
	
	% ϵͳ�۲�ģ��
    X = [  q0 - (q1*(wx-bwx)*dt)/2 - (q2*(wy - bwy)*dt)/2 - (q3*(wz - bwz)*dt)/2;
		   q1 + (q0*(wx-bwx)*dt)/2 - (q3*(wy - bwy)*dt)/2 + (q2*(wz - bwz)*dt)/2;
		   q2 + (q3*(wx-bwx)*dt)/2 + (q0*(wy - bwy)*dt)/2 - (q1*(wz - bwz)*dt)/2;
		   q3 - (q2*(wx-bwx)*dt)/2 + (q1*(wy - bwy)*dt)/2 + (q0*(wz - bwz)*dt)/2;
                                                                             bwx;
                                                                             bwy;
                                                                             bwz];
    % ��Ԫ����һ��
	X(1:4) = X(1:4) / norm(X(1:4));
	
	% ״̬ת�ƾ���
	F = [  0,       - wx/2,       - wy/2,       - wz/2,  q1/2,  q2/2,  q3/2;
        wx/2,            0,         wz/2,       - wy/2, -q0/2,  q3/2, -q2/2;
        wy/2,       - wz/2,            0,         wx/2, -q3/2, -q0/2,  q1/2;
        wz/2,         wy/2,       - wx/2,            0,  q2/2, -q1/2, -q0/2;
           0,            0,            0,            0,     0,     0,     0;
           0,            0,            0,            0,     0,     0,     0;
           0,            0,            0,            0,     0,     0,     0];

	% ��Ԫ������   
	q0 = X(1); q1 = X(2); q2 = X(3); q3 = X(4);
	
	% �۲�Э�������
	PHI = eye(7) + F * dt;
    P = PHI * P * PHI' + Q;
	
%%%% ��һ�翴����	
	quat = X(1:4);
	cbn  = my_quat2cbn(quat);
	mR = cbn*mag';
    bx = norm([mR(1),mR(2)]);
    bz = mR(3);
	
	h = [cbn'*[0;0;-1];cbn'*[bx;0;bz]];%%����Ԥ��ֵ
	innov = h - Z'; 
    
    H = my_calcH(bx,bz,q0,q1,q2,q3);

    Hk_1 = [  2*q2, -2*q3, 2*q0, -2*q1, 0, 0, 0;
             -2*q1, -2*q0,-2*q3, -2*q2, 0, 0, 0;
             -2*q0,  2*q1, 2*q2, -2*q3, 0, 0, 0];

    Hk_2 = 2*[ -2*bz*q2,            2*bz*q3,            -4*bx*q2-2*bz*q0,      -4*bx*q3+2*bz*q1 0 0 0;
               -2*bx*q3+2*bz*q1,	2*bx*q2+2*bz*q0,	2*bx*q1+2*bz*q3,       -2*bx*q0+2*bz*q2 0 0 0;
                2*bx*q2,            2*bx*q3-4*bz*q1,	2*bx*q0-4*bz*q2,       2*bx*q1  0 0 0];
  
    H = [Hk_1;Hk_2];
	
	% ���¿���������
	S = H*P*H' + R;
    K = P*H'/S;
	
	% ���������½׶Σ���ʽ3-5
	X = X - K * innov;			%%�õ�����״̬
    I = eye(length(P));
    P = (I - K * H)*P;          % ����Э�������

	% ��һ����Ԫ��
	X(1:4) = X(1:4)/norm(X(1:4));
	
end