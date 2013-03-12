function XtY = randTransMat(nx,ny)
% random transition matrix X to Y, size [nx,ny]
XtY = rand(nx,ny);
pX = sum(XtY,2);
XtY = XtY./pX(:,ones(1,ny));