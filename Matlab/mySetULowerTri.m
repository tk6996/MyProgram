function [ A_out ] = mySetULowerTri( A )
    A_out = tril(A,-1) + eye(size(A));
end

