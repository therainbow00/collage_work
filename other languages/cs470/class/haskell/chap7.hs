--chap7.hs


data Shape = Circle Float Float Float | Rectangle Float Float Float Float
              deriving (Show)
-- Circle xcenter ycenter radius
-- Rectangle topleftx toplefty bottomrightx  bottomrighty
area :: Shape -> Float
area (Circle _ _ r) = pi * r ^ 2
area (Rectangle x1 y1 x2 y2) = (abs (x2 - x1)) * (abs (y2 - y1)) 

--let c1 = Circle 0 0 5
--area c1





--recursive data type Tree

data Tree a = EmptyTree | Node a (Tree a) (Tree a)  deriving (Show)
--Here think of 'a' as a type variable, 
--and EmptyTree, Tree, Node as Value constructors
--Node root leftsubtree rightsubtree

singleton  :: a -> Tree a
singleton x = Node  x  EmptyTree  EmptyTree

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert  x  EmptyTree  = singleton x
treeInsert x (Node a left right)
      | x == a = Node x left right
      | x < a   = Node a (treeInsert x left) right
      | x > a = Node a left (treeInsert x right)


treeElem :: Ord a => a -> Tree a -> Bool  
treeElem   x   EmptyTree = False 
treeElem x (Node a left right) 
    | x == a = True
    | x < a = treeElem x left
    | x > a = treeElem x right

--let nums = [8,6,4,1,7,3,5]
--let numsTree = foldr treeInsert EmptyTree nums
--numsTree
--treeElem 9 numsTree
--treeElem 4 numsTree


treeInsert2 :: (Ord a) => Tree a -> a -> Tree a
treeInsert2  EmptyTree  x = singleton x
treeInsert2 (Node a left right) x
      | x == a = Node x left right
      | x < a   = Node a (treeInsert2 left x ) right
      | x > a = Node a left (treeInsert2 right x)


--let nums = [8,6,4,1,7,3,5]
--let numsTree2 = foldl treeInsert2 EmptyTree nums
--numsTree2
--treeElem 9 numsTree2
--treeElem 4 numsTree2




 
