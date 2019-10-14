function [ A_out ] = mySymmetrizeLower( A )
    for i = 1:size(A,1)
        for j = 1:i-1
            A(j,i) = A(i,j);
        end
    end
    A_out = A;
end

