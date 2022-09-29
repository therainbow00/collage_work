--perfect.hs

-- a perfect number is a positive integer that is equal to the sum of its proper positive divisors
--6, 28, 496, 8128 , .....

pn :: Integer -> Bool
pn n 
    | (n == (sumpdiv n)) = True
    | otherwise = False

sumpdiv :: Integer -> Integer
sumpdiv n = (help1 1 n 0)

help1 :: Integer -> Integer -> Integer -> Integer
help1 f n sofar 
    | (f == n) = sofar
    | (pdiv f n) = help1 (f + 1) n (sofar + f)
    | otherwise = help1 (f+1) n sofar

mymod :: Integer -> Integer -> Integer
mymod n d 
    | (n == d) = 0
    | (n > d) = mymod (n - d) d
    | otherwise = n

pdiv :: Integer -> Integer -> Bool
pdiv f n
     | (f >= n) = False
     | otherwise = (if  ( (mymod n f) == 0 ) then True else False)



