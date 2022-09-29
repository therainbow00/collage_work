--fixpointsqrt2.hs

absdiff :: Float -> Float -> Float
absdiff x y
    |(x< y) = y-x
    |otherwise = x-y

appequal :: Float -> Float -> Bool
appequal x y
    | (absdiff x y) < 0.000001  = True
    | otherwise = False  


fixpoint :: (Float -> Float) -> Float -> Float

fixpoint f inv 
    |appequal inv (f inv)  = inv
    |otherwise        = fixpoint f (f inv)

forsqrt2 :: Float -> Float
forsqrt2 x = 1.5 * x  - (x ^ 3)/4




fixpointSort :: ([Int] -> [Int]) -> [Int] -> [Int]
fixpointSort f inv 
    |inv ==  (f inv)  = inv
    |otherwise        = fixpointSort f (f inv)   



onepass :: [Int] -> [Int]
onepass a
    | a == [] = []
    |(tail a) == [] = a
    |(head a) <= (head (tail a)) = (head a) : (onepass (tail a)) 
    |otherwise= (head (tail a)): onepass ((head a) : (tail (tail a)))

mysort :: [Int] -> [Int]
mysort x = fixpointSort onepass x    

--mysort  [3,1,4,9,7]











 