function [ B_out ] = mySetTranspose( A , B )
    for i = 1:size(A,1)
        for j = 1:size(A,2)
            B(j,i) = A(i,j);
        end
    end
    B_out = B;
end

