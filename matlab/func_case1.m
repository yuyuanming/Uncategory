function y=func_case1(b, a)

y = (1+b)/2 .* (1-2*a).*(1-b)./((1-2*a).*(1-b)-b) .* (funcg(b) - funcg((1-2*a).*(1-b))) + (1-b)/2 .* (1-2*a).*(1+b)./((1-2*a).*(1+b)+b) .* (funcg(b) - funcg((1-2*a).*(1+b)));