function [ y_out ] = myMultiplication( A , x , y )
    y_out = mySetZero(y);
    for i = 1:size(A,1)
        y_out(i,1) = A(i,:) * x + y(i,1) ;
    end
end

