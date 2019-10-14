function [ X_out ] = mySetIdentity( X )
    if size(X,1) == size(X,2)
        X_out = mySetZero(X);
        for index = 1:length(X)
            X_out(index,index) = 1;
        end
    else
        X_out = 'FAILED';
    end
end

