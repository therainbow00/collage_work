% ex6p3, page 116

/* toptail(InList, OutList) :- length(InList, N) , N >= 2, !, work(InList, OutList).
work(InList, OutList) :- InList = [X | Y] , reverse(Y,Z), Z = [A|B] , reverse(B, OutList). */

toptail(I,O) :- length(I,N), N >= 2, help(I,O).
help(I,O) :- I = [X|Y], reverse(Y,Z), Z = [H|T] ,reverse(T,O).


