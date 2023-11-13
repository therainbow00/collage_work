/* ex9p3.pl  */
complexterm(X) :- nonvar(X) , functor(X, _ , A), A > 0. /* see bottom page 171  */ 
termtype(X,atom) :- atom(X).
termtype(X, number) :- number(X).
termtype(X,constant) :- atomic(X). %atom or number
termtype(X, variable) :- var(X).
termtype(X,simple_term) :- atom(X) ; atomic(X); var(X).  /* semicolon ; means or  */
termtype(X,complex_term) :-  complexterm(X).
termtype(X , term) :- termtype(X, simple_term) ; termtype(X , complex_term).