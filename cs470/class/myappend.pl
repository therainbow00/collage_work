%myappend.pl
myappend([], A, A).
myappend([X | Y], B, [X | Z]) :- myappend(Y, B, Z).
