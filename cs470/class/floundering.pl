canfly(X) :- neg(ostrich(X)), bird(X).
%this causes floundering

neg(X) :- X, !, fail.
neg(X).

bird(a).
bird(b).
ostrich(b).
