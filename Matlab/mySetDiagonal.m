function [ A_Out ] = mySetDiagonal( A , x )
    A_Out = mySetIdentity(A);
    if myCheckVector(x) < 0
        return
    end
    rowvec = (myCheckVector(x) == 1);
    for index = 1:length(x)
        if rowvec 
            A_Out(index,index) = x(1,index);
        else
            A_Out(index,index) = x(index,1);
        end
    end
end

