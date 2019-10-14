function [ type ] = myCheckVector( x )
% return 0 is scalar
% return 1 is row vector
% return 2 is collum vector
% return -1 is not vector
    [row,col] = size(x);
    onerow = (row == 1);
    onecol = (col == 1);
    if onerow && onecol 
        type = 0;
    elseif onerow 
        type = 1;
    elseif onecol
        type = 2;
    else
        type = -1;
    end
end

