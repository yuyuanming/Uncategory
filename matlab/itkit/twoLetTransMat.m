function XXtYY = twoLetTransMat(XtY)
% two letter transition matrix
% the size squares in each dimension
% XtY can be multi-D, say 4-D [n1 n2 n3 n4]
% then XXtYY is 4-D [n1^2, n2^2, n3^2, n4^2]

% when XtY is 2-d, this is actually 
%              XXtYY = kron(XtY,XtY)
% but when XtY > 2-D, kron() just return 2-D matrix and can't be directly 
% reshaped to correct form

ns = size(XtY);
for k = 1:numel(ns);
    m = ns(k);
    seqk = 1:m;
    seqk1 = seqk(ones(m,1),:); % alphabet-order in each row
    seqk2 = seqk1'; % alphabet-order in each column
    % say p(u), then p(seqk1).*p(seqk2) gives p(u1u2)
    
    seq1.(['fn',num2str(k)]) = seqk1;
    seq2.(['fn',num2str(k)]) = seqk2;
end;

% arg1 = (seq1.fn1, seq1.fn2, seq1.fn3, ...)
arg1 = '(seq1.fn1'; % this holds even if XtY = [], as seqk = []
for k = 2:numel(ns);
    arg1 = [arg1, ',seq1.fn', num2str(k)];
end;
arg1 = [arg1,')'];

% arg2 = (seq2.fn1, seq2.fn2, seq2.fn3, ...)
arg2 = '(seq2.fn1'; 
for k = 2:numel(ns);
    arg2 = [arg2, ',seq2.fn', num2str(k)];
end;
arg2 = [arg2,')'];

% evaluate
XXtYY = eval(['XtY',arg1]).*eval(['XtY',arg2]);
