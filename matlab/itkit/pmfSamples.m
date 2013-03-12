function pmfs = pmfSamples(step,sizep)
% sample points as a pmf
% sample step: step
% pmf of size: sizep
% pmfs(i,:,:,...) is the i-th sample

cardp = prod(sizep); % cardinality
p = 0:step:1;
p = p(:);
pmfs = p;
np = numel(p);
op = ones(np,1);
for i = 1:cardp-2; % possible free p
    pmfs = [kron(p,ones(size(pmfs,1),1)) kron(op,pmfs)]; % candidate p
    pmfs = pmfs(sum(pmfs,2)<=1,:); % to save memory
end;
pmfs = [pmfs, 1-sum(pmfs,2)];
%idx = (pmfs(:,end) >= 0);
%pmfs = pmfs(idx,:); % valid pmf's
% reshape to sizep
if numel(sizep)>1;
    ns = size(pmfs,1);
    pmfs = reshape(pmfs,[ns,sizep(:)']);
end;