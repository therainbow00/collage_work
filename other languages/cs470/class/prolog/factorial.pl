fact(0, 1) :- !.
fact(N, F) :- M is N-1, fact(M, B), F is N * B.
