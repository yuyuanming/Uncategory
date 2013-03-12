function pmfs = pmfSamplesNoBnd(step,sizep)
% sample points as a pmf, not considering boundary points
% sample step: step
% pmf of size: sizep
% pmfs(i,sizep) is the i-th sample
cardp = prod(sizep); % cardinality
p = step:step:1; p = p(p<1);
p = p(:);
pmfs = p;
np = numel(p);
op = ones(np,1);
for i = 1:cardp-2; % free p
    pmfs = [kron(p,ones(size(pmfs,1),1)) kron(op,pmfs)]; % candidate p
    pmfs = pmfs(sum(pmfs,2)<1,:); % valid pmf's, to save memory
end;
pmfs = [pmfs, 1-sum(pmfs,2)];
% reshape to sizep
if numel(sizep)>1;
    ns = size(pmfs,1);
    pmfs = reshape(pmfs,[ns,sizep(:)']);
end;