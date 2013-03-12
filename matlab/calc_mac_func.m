function ret = calc_mac_func(beta, p)

ret = funcg(beta) - [(1+beta)/2 .* funcg((1-p).*beta + p) + (1-beta)/2 .* func g((1-p).*beta - p)];