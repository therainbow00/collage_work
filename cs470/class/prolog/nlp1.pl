s(L, R) :- np(L, T), vp(T, R).
np(L, R) :- det(L, T), n(T, R).
vp(L, R) :- v(L, T), np(T, R).

det([the|L], L).
det([a|L], L).
n([snake|L], L).
n([rat|L], L).
v([chased|L], L).
v([saw|L], L).
