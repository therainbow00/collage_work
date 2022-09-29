% ex6p5.pl, page 116

%assume List1 has at least 2 elements

swapfl(List1, List2) :- length(List1, N) , N > 1, !, work(List1, List2).

work(List1, List2) :- List1 = [A | B] , reverse(B, D), D = [P | R] , reverse(R, Q), append([P],Q,T), 
                         append(T, [A] , List2).