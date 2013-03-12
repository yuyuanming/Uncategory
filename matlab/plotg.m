function plotg(a)
upper = 2*a/(1-2*a);
if (upper > 0.9999) upper = 0.9999;
end
b_range = [-upper:1e-3:upper];
plot(b_range, func_case1(b_range, ones(size(b_range))*a));