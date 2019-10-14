function [ alpha ] = myDot( x , y )
    if myCheckVector(x) > -1 && myCheckVector(x) == myCheckVector(y) && length(x) == length(y)
        if myCheckVector(x) == 1
            alpha = x * y';
        else
            alpha = x' * y;
        end
    else
        alpha = 'FAILED';
    end
end

