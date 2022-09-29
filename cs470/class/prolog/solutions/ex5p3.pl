%ex5p3.pl ,  page 102
/* Write a predicate addone/2 whose first argument is a list of integers,
    and whose second argument is the list of integers obtained by adding 1 
    to each integer in the first list  */

addone([], []).
addone([X | Y] , [A | B]) :- A is X + 1, addone(Y, B).
 