max(X, Y, Z) :- X =< Y, Y = Z. %red cut
max(X, Y, X).
