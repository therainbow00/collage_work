boy(b1).
boy(b2).
girl(g1).
girl(g2).
    %(if) = :-
date(X,Y) :- boy(X), girl(Y).
