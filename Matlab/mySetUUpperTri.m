function [ A_out ] = mySetUUpperTri( A )
    A_out = triu(A,1) + eye(size(A));
end
