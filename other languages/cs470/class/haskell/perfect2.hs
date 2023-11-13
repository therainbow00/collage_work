--perfect2.hs

-- a perfect number is a positive integer that is equal to the sum of its proper positive divisors
--6, 28, 496, 8128 , .....

pn :: Integer -> Bool

pn n  -- precondition n >= 2
   | (n == (sumpdiv n)) = True
   | otherwise = False 

sumpdiv :: Integer -> Integer
sumpdiv n = sum [m |  m <- [1..n-1] , (mod n m) == 0 ]