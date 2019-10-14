function [ y_out ] = myAXPY( alpha, x, y )
    if myCheckVector(alpha) == 0 && (all(size(x) == size(y)))
        y_out = alpha * x + y;
    else
        y_out = 'FAILED';
    end

end

