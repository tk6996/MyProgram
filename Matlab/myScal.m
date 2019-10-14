function [ x_out ] = myScal( alpha , x )
    if myCheckVector(x) > -1 && myCheckVector(alpha) == 0
        x_out = alpha * x;
    else
        x_out = 'FAILED';
    end
end

