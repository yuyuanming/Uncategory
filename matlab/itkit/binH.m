function h = binH(p)
% binary entropy function (base e)
% input : [p]: probability matrix, better be within [0,1]
% output: [h]: binary entropy of each element of p

% check: 0 <= p <= 1
% h(p) = NaN, if p not in [0,1]
% h(p) = 0, if p = 0,1
% h(p) = -p*log(p) - (1-p)*log(1-p), if p in (0,1)


% p not in [0,1]
h = NaN*zeros(size(p));

% p = 0, 1
idx = p==0|p==1;
h(idx) = 0;

% 0 < p < 1
p = p(:);
idx = p>0 & p<1;
M = [p(idx) 1-p(idx)];
h(idx) = - sum( M.*log(M), 2);

