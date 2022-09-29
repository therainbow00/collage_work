-- tailrec.hs
-- convert a non-tail recursive function to a tail recursive function
-- using the method of accumulating parameters

factorial :: Int -> Int
factorial n
    | n == 0 = 1
    | otherwise = n * (factorial (n - 1))

help :: Int -> Int -> Int
--help is clearly tail recursive
--sofar should always equal the factorial
--of a
help n sofar
    | n == 0 = sofar
    | otherwise = help (n - 1) (n * sofar)

ftr :: Int -> Int
--ftr is the tail recursive version of the factorial function,
--becasue its help fuction is tail recursive
ftr n = help n 1

sumton :: Int -> Int
--sunton n returns the sum of all integers from 0 to n, n >= 0
sumton n
    | n == 0 = 0
    | otherwise = n + (sumton (n - 1))

help2 n sofar
    | n == 0 = sofar
    | otherwise = help2 (n - 1) (n + sofar)
sumtontr n = help2 n 0

mylen :: [a] -> Int
mylen x
    | (null x) = 0
    | otherwise = 1 + mylen (tail x)

help3 x sofar
    | (null x) = 0
    | otherwise = help3 (tail x ) (1 + sofar)
mylentr :: [a] -> Int
mylentr x = help3 x 0

--myreverse :: [a] -> [a]
