function ret=func_check(a)
x1=(2*a)./(1-2*a);
x2=1-2*a;
ret = funcg(x1) + funcg(x2) - funcg(0);