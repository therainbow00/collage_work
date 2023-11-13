--chap3.hs
-- pattern matching style
--page36
sayMe :: Int -> String
sayMe 1 = "One!"
sayMe 2 = "two"
sayMe x = "Not 1 0r 2"

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * (factorial (n - 1)) -- recursive but not tail recursive
-- a tail recursive function is one in which the recursive call is the last
-- thing done in the function


head' :: [a] -> a
head' [] = error "may not apply head' to an empty list"
head' (x:_) = x

bad :: Int -> Int -> Int
bad x x = 0 -- the same variable may not occur more than once in a pattern
bad x y = y x + y

notbad :: Int -> Int -> Int
notbad x y
    | x == y = 0
    | otherwise = x + y
