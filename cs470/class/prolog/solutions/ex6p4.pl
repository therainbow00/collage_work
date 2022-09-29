% ex6p4.pl, page 116

/*

last(List,X) :- length(List, N) , N > 0, !, work(List,X).
work([A],A):- !.
work([X|Y], B) :- last(Y,B).

*/

/*
last(List,X) :- length(List, N) , N > 0, !, work(List,X).
work(List,X) :- reverse(List,A), A = [B|D], X = B.

*/
