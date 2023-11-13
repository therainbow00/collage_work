%ex5p2.pl,  p. 101

/* Define a 2-place predicate 'increment' that holds only when its second argument 
is an integer one larger than its first argument. For example, increment(4,5) should hold, but increment(4,6)
should not. */

increment(X,Y) :- Y is X + 1.
increment2(X,Y) :- X + 1 =:= Y.  %another solution, not exactly the same

/* Define a 3-place predicate sum that holds only when its third argument is the sum of the first two
    aguments. For example, sum(4,5,9) should hold, but sum(4,6,12) should not. */

sum(X,Y,Z) :- Z is X + Y.
sum2(X,Y,Z) :- X + Y =:= Z.  %another solution, not exactly the same.


