doubleMe x = x + x
doubleUs x y = doubleMe x + doubleMe y
doubleSmallNumber x = if x > 100 then x else x * 2

triples = [(a, b, c)  |  c  <-  [1..10],  a  <-  [1..10],  b  <-  [1..10]]
rightTringles = [(a, b, c)  |  (a, b, c ) <-  triples, a ^ 2 + b^ 2 == c ^ 2, a + b + c == 24]
