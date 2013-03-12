function env = lowEnv(x,y)
% find the lower (convex) envelope
% x is of size [m, n], where each row is a point 
% y is of size [m, 1], y = f(x)

y = uniqueMin(x,y);
% collinear test for function 'convhull'
if collinearTest(x,y); env = y; return; end;
%
warning('off','all');
if size(x,2) > 1;
    K = convhulln([x,y]); % ? * (dx+1) matrix
    nx = size(x,1);
    nk = size(K,1);
    xaug = [x ones(nx,1)];
    num = 1e7; % for memory limit
    if nx*nk < num;
        val = zeros(nx,nk);
        for i = 1:size(K,1);
            idxi = K(i,:);
            % extrapolation is NaN
            val(:,i) = interpfaceaug(idxi,xaug,y);
        end;
        env = min(val,[],2); % min(Inf,NaN) = Inf
    else
        ncol = floor(num/nx);
        env = Inf*ones(nx,1); % for lower convex envelope
        val = Inf*ones(nx,ncol+1);
        for i = 1:size(K,1);
            idxi = K(i,:);
            loc = i - ncol*floor(i/ncol) +1;
            val(:,loc) = interpfaceaug(idxi,xaug,y);
            if loc == 1;
                val(:,end) = env;
                env = min(val,[],2);
            end;
        end;
        if loc ~= 1;
            val(:,1) = env;
            env = min(val(:,1:loc),[],2);
        end;
    end;
else 
    K = convhull(x,y);
    env = y(:);
    for i = 1:numel(K)-1;
        Ki = K(i);
        Kj = K(i+1);
        if abs(Ki-Kj) > 1;
            xkt = x([Ki; Kj]);
            ykt = y([Ki; Kj]);
            s = sign(Kj-Ki);
            idxi = Ki+s : s : Kj-s;
            xi = x(idxi);
            yi = interp1(xkt,ykt,xi,'linear');
            env(idxi) = min([env(idxi)'; yi']); % lower envelope
        end;
    end;
end;

function y = uniqueMin(x,y)
% input x of size [m,n], make sure each row is a point
% input y of size [m,1]. is a 1-D real function of x

% find unique x, and the minimum (lower) y for each x
y = y(:);
[ya,idx] = sort(y,'ascend'); % sort y, for minimum
xa = x(idx,:);
[xu,idxf,idxb] = unique(xa,'rows','first');
yu = ya(idxf); % xu = xa(idxf)
ya = yu(idxb); % xa = xu(idxb)
y(idx) = ya;


function col = collinearTest(x,y)
% test collinear
% x of size [m, n], y [m, 1]
M = [x y];
M = M(2:end,:) - repmat(M(1,:),[size(M,1)-1,1]);
col = ( rank(M) <= size(x,2) ); % a face in high dimensional space

function y = interpfaceaug(indf,xaug,y)
% interpolation using one face on convex hull
% data xaug has already been augmented
indi = true(size(xaug,1),1);
indi(indf) = false; % points need to interpolate
% suppose xf is non-augmented data, following one is slower
% y = griddatan(xf,yf,x,'linear');

alpha = xaug / xaug(indf,:); % combination coefficient
idx = indi & all(alpha > -1e-24, 2); % convex combination
y(idx) = alpha(idx,:) * y(indf);

