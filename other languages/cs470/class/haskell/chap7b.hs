--chap7b.hs

data Point = Point Float Float deriving (Show)
data Shape = Circle Point Float | Rectangle Point Point deriving (Show)

area :: Shape -> Float
area (Circle _ r) = pi * r ^ 2
area (Rectangle (Point x1 y1) (Point x2 y2)) = (abs (x2 - x1)) * (abs (y2 - y1))

data Person = Person { firstName :: String,
                       lastName ::  String,
                       age :: Int,
                       height :: Float,
                       phoneNumber :: String,
                       flavor :: String } deriving (Show)

data Car = Car { company :: String,
                 model :: String,
                 year :: Int } deriving (Show)


       