
canfly(X) :- bird(X), neg(ostrich(X)).
%this avoids floundering
neg(X) :- X, !, fail.
neg(X).
/*
confly(X) :- neg(ostrich(X)), brid(X).
this avoids floundering

canfly(X) :- neg(ostrich(X)), bird(X).
*/
bird(a).
bird(b).
%ostrich(a).
ostrich(b).
