function puxy = jointpmf(pux,nu,XtY,ny)
% pux of size [nu,nx]
% XtY of size [nx,ny]
% puxy of size [nu,nx,ny]

puxy = repmat(shiftdim(XtY,-1),[nu,1,1]).*repmat(pux,[1,1,ny]);