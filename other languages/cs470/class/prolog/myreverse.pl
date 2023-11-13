%myreverse.pl
myappend([], A, A).
myappend([X | Y], B, [X | Z]) :- myappend(Y, B, Z).

myreverse([], []).
myreverse([X | Y], Z) :- reverse(Y, W), myappend(W, [X], Z). 
