function [ y_out ] = myCopy( x , y )
    if (myCheckVector(x) > -1 && myCheckVector(y) > -1) && (length(x) == length(y))
        y_out = reshape(x,size(y));
    else
        y_out = 'FAILED';
    end
end

