/* ex7p2.pl , page 135 */

/* DCG for one or more a's followed by an equal number of b's. */



s --> [a] , [b].
s --> [a], s, [b].


/*  ?-s([a,a,b,b],[]).  */




