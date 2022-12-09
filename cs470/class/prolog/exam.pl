r(A,B) :- p(A,C) , q(C,B).
p(1,2).
q(2,3).
s(A,B) :- s(B,A).
s(1,2).
t(a).
t(b).
u(L) :-  findall(A,t(A), L).
pp(a).
neg(A) :- A, ! , fail.
neg(A).
d  :- A = suc(A).
qq( B, f(B) ).
g :- qq( f(A) , A).
e(B,D) :- assertz(count(0)) , retract(count(A)) , B is A + 1 , assertz(count(B)) , D is B + 1.
