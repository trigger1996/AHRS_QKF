function q = my_ang2quat(ang)

    %%��תʸ��ת��Ϊ��Ԫ��
    
    [m,n] = size(ang);
    
    if m==3 
        norm = sqrt(ang'*ang);
    end
    if n==3
        norm = sqrt(ang*ang');
    end
    
    if norm > 1e-40
        f = sin(norm/2)/norm;
    else 
        f = 1/2;
    end
    
    q = [cos(norm/2);f*ang];
   
end
