
--chap5.hs

--higher order functions

add2 :: Int -> Int
add2 x = x + 2

multThree :: Int -> Int -> Int -> Int
multThree  x y z = x * y * z


applyTwice :: (a -> a) -> a -> a
--applyTwice is a higher order function
--applyTwice takes 2 arguments
--the first argument is a function, the second argument 
-- is not a function
applyTwice f x = f (f x)

--read about map, filter

--anonymous function : lambda expressions
--(\x -> x + 3)

anothersum :: (Num a) => [a] -> a
anothersum [] = 0
anothersum (x:xs) = x + (anothersum xs)



--sum' is to work just like sum  (page 74 of free book)
-- in foldl, acc is on the left in the binary function
-- values in xs are consumed from the left
 
sum' :: (Num a) => [a] -> a
sum' xs = foldl (\acc x  -> acc + x)  0 xs

--sum' [1,2,3,4]

--foldr is similar to foldl except that foldr eats up
-- the values in xs from the right, not the left
-- and acc occurs on the right in the binary function
sum'' :: (Num a) => [a] -> a
sum'' xs = foldr (\x acc -> acc + x)  0 xs
--sum'' [1,2,3,4]

--foldr is similar to foldl
map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> (f x) : acc) [] xs


map'' ::(a -> b) -> [a] -> [b]
map'' f xs = foldl (\acc x -> acc ++ [f x]) [] xs 


--try
--filter even [1,2,3,4]

filter' :: (a -> Bool) -> [a] -> [a]
filter' f xs = foldr (\x acc -> if (f x) then x:acc else acc) []  xs 

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' f xs = foldl (\acc x -> if (f x) then acc ++ [x] else acc) []  xs 