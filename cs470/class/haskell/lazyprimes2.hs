--lazyprimes2.hs

--lazy lists and lazy evaluation in Haskell
-- strict verses lazy evaluation
--ML uses strict evaluation
--Haskell uses lazy evaluation
intsfrom :: Integer -> [Integer]
intsfrom n = n: intsfrom (n+1)
--intsfrom 4
--creates an infinite list, use ctrl-c to stop
--take 5 (intsfrom 4) 
--a = intsfrom 4
--take 6 a
--b = [4..]
--take 5 b

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


mysieve :: [Integer] -> [Integer]
mysieve (0:xs) = mysieve xs
mysieve (1:xs) = mysieve xs
mysieve (n:xs) = n: (mysieve (rm n xs))

rm :: Integer -> [Integer] -> [Integer] 
-- (rm k x )removes multiples of k in list x
rm k [] = []
rm k (m:xs) | (mod m k) == 0 = (rm k xs)
              | otherwise = m: (rm k xs)

myprimes :: [Integer] 
myprimes = mysieve [2..]

--take 5 myprimes
--take 5 (mysieve  (intsfrom 2) ) 
