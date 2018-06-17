function q =  my_quatmul(q1,q2)

    %%四元数相乘

    %%四元数相乘
	d   = zeros(4, 1);
    d(1) = q1(1)*q2(1) - q1(2)*q2(2) - q1(3)*q2(3) - q1(4)*q2(4);
	d(2) = q1(2)*q2(1) + q1(1)*q2(2) - q1(4)*q2(3) + q1(3)*q2(4);
	d(3) = q1(3)*q2(1) + q1(4)*q2(2) + q1(1)*q2(3) - q1(2)*q2(4);
	d(4) = q1(4)*q2(1) - q1(3)*q2(2) + q1(2)*q2(3) + q1(1)*q2(4);
    
 
    
%     %%进行归一化处理
%     normQ = norm(d);
%     q = d/normQ;

    q = d;



end