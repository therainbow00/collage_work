combine1([],[],[]).

combine1([X|Y],[A|B],[X,A|W]) :- combine1(Y,B,W).
