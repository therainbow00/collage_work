--LazyQuiz.hs

intsfrom2 :: [Integer]
intsfrom2 = 2: (map (+1) intsfrom2)

odds :: [Integer]
odds  = 1: (map (+2) odds)

--take 5 intsfrom2
--take 5 odds
--take 5 [2..]

--Generate the following infinite lists:
--factlist = [1,1,2,6,24,120,720,.....]
--fiblist = [0,1,1,2,3,5,8,13,21,....]
--Fib(0) = 0
--Fib(1) = 1 
--Fib(n) = Fib(n-1) + Fib(n-2) ,

fact :: Integer -> Integer
fact n
    | n == 0 = 1
    |otherwise = n * fact (n-1)
factlist = map fact [0..]

--take 5 factlist

fib :: Integer -> Integer
fib 0 = 0
fib 1 = 1
fib n = fib (n-1)   +  fib (n-2)
fiblist = map fib [0..]
--take 5 fiblist


factsFrom  :: Integer -> [Integer]
factsFrom  n = (fact n) : (factsFrom (n + 1) )
factlist2 = factsFrom 0

--take 10 (factsFrom 0)
--take 10 factlist2


fibsFrom  :: Integer -> [Integer]
fibsFrom  n = (fib n) : (fibsFrom (n + 1) )
fiblist2 = fibsFrom 0

--take 10 (fibsFrom 0)
--take 10 fiblist2


  

 