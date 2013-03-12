function H = colH(M)
% column entropy of matrix M
% input  : [M]: matrix M, elements better be non-negative
% output : [H]: entropy of each column of M

% calculate the entropy of each column
% if size of M is [n1, n2, n3, ...], size of H is [1, n2, n3, ...]
% hence H has the same size as M except 1st-D

% do not check if M's each column is a pmf
% elements [<=0] and [NaN] are changed to 1 to make M > 0


M(~(M>0)) = 1; % use this to avoid NaN, 
% M(M<=0)=1, faster, use when no NaN element

H = - sum(M.*log(M), 1); % entropy definition
