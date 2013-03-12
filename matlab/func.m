function ret=func(a)
x1=(2*a)./(1-2*a);
x1 = (1+x1)/2;
x2=1-2*a;
x2=(1+x2)/2;
ret = bin_entropy(x1) + bin_entropy(x2) - bin_entropy(0.5);