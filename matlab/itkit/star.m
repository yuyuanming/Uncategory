function y = star(a,b)
% star multiplication
% input : [a]: scalar or of the same size as b
%       : [b]: scalar or of the same size as a
% output: y = a*(1-b) + (1-a)*b

y = a + b - 2*a.*b;
