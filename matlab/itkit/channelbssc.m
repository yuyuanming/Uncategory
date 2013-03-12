function [XtY,XtZ] = channelbssc
% transition matrices of BSSC channel
XtY = [ .5 .5;
        0   1 ];
XtZ = [ 1   0;
        .5 .5 ];