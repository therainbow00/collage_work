--lazyprimes.hs


intsfrom2 :: [Integer]
intsfrom2 = 2: (map (+1) intsfrom2)

odds :: [Integer]
odds  = 1: (map (+2) odds)

--take 5 intsfrom2
--take 5 odds
--take 5 [2..]

--page 105 of "Haskell Road to Logic Maths and Programming"
--Sieve of Eratosthenes

sieve :: [Integer] -> [Integer]
sieve (0 : xs) = sieve xs
sieve (n : xs) = n : sieve (mark xs 1 n)
  where 
  mark :: [Integer] -> Integer -> Integer -> [Integer]
  mark (y:ys) k m | k == m    =  0 : (mark ys  1    m)
                  | otherwise =  y : (mark ys (k+1) m)

primes :: [Integer]
primes = sieve [2..]

--take  5  primes


myprimes :: [Integer]
myprimes = sieve intsfrom2
--take 5 myprimes
