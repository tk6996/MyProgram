function [ y_out ] = mySymeticmXVector( A , x , y)
    for i = 1:size(A,1)
        for j = i+1:size(A,2)
            y(i,1) = A(i,j)*x(j,1) + y(i,1);
            y(j,1) = A(i,j)*x(i,1) + y(j,1);
        end
        y(i,1) = A(i,i)*x(i,1) + y(i,1);
    end
    y_out = y;
end
