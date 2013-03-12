function H = rowH(M)
% row entropy of matrix M
% input  : [M]: matrix M, elements better be non-negative
% output : [H]: entropy of each row of M

% calculate the entropy of each row
% if size of M is [n1, n2, n3, ...], size of H is [n1, 1, n3, ...]
% hence H has the same size as M except 2nd-D

% why choose row: for probability transition matrix p(Y|X)
% each row of p(Y|X) is p(Y|X=x)
% the entropy of each row is H(Y|X=x)
% hence H(Y|X) = p(X)*rowH(p(Y|X)), where p(X) is row

% do not check M's row sum = 1
% elements [<=0] and [NaN] are changed to 1 to make M > 0


M(M<=0) = 1;
% M(~(M>0)) = 1; % use this to avoid NaN, not use M(M<=0) = 1

H = - sum(M.*log(M), 2); % entropy definition

