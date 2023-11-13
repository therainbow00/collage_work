--chap2.hs

--p.24
removeNonUppercase :: [Char] -> [Char]
removeNonUppercase st = [c | c <- st , c `elem` ['A'..'Z']]

--p25
addThree :: Int -> Int -> Int -> Int
addThree x y z = x + y + z


--p25
factorial :: Integer -> Integer
factorial n = product [1..n]


--p25
circumference :: Float -> Float
circumference r = 2 * pi * r
