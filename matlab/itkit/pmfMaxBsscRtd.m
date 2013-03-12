function pwuvx = pmfMaxBsscRtd
% pmf that maximizes BSSC RTD

a = .5 - sqrt(105)/30; % a = .158438;
b = 1-a;
W = [.5 .5]';
WtX = [ a b; b a ];
WX = W(:,ones(1,2)).*WtX;
%
pwuvx = zeros(2,2,2,2);
% W=0, U=X
w = 1; v = 1;
for k = 1:2; pwuvx(w,k,v,k) = WX(w,k); end;
% W=1, V=X
w = 2; u = 1;
for k = 1:2; pwuvx(w,u,k,k) = WX(w,k); end;