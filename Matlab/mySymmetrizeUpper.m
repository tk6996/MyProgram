function [ A_out ] = mySymmetrizeUpper( A )
    for i = 1:size(A,1)
        for j = 1:i-1
            A(i,j) = A(j,i);
        end
    end
    A_out = A;
end
