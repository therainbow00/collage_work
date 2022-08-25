s(L, R, s(P1, P2)) :- np(L, T, P1), vp(T, R, P2).
np(L, R, np(P1, P2)) :- det(L, T, P1), n(T, R, P2).
vp(L, R, vp(P1, P2)) :- v(L, T, P1), np(T, R, P2).


det([the|L], L, det(the)).
det([a|L], L, det(a)).
n([snake|L], L, n(snake)).
n([rat|L], L, n(rat)).
v([chased|L], L, v(chased)).
v([saw|L], L, v(saw)).
