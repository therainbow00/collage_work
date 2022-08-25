plus(0, X, X).
plus(s(X), Y, s(Z)) :- plus(X, Y, Z).

times(0, A, 0).
times(s(A), B, Z) :- times(A, B, Y), plus(Y, B, Z).
