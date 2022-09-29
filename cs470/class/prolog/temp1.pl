p(a).
p(b).
c(L) :- findall(x, p(x), L).

neg(X) :- X, !, fail
neg(X).
