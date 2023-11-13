--SolutionA8.hs

--Write a Haskell function to find the height of a 
--binary search tree defined as follows: 
data Tree a = EmptyTree | Node a (Tree a) (Tree a)  deriving (Show)
--Assume EmptyTree has height zero(0). 

--Create a tree and use your function to compute
--and print the height of the tree.

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

--nums = [8,6,4,1,7,3,5]
--let numsTree2 = foldl treeInsert EmptyTree nums
--numsTree = foldr treeInsert EmptyTree nums





height ::  Tree a -> Integer

height EmptyTree = 0
height (Node x left right) = 1 + (max (height left) (height right))

--height numsTree
--height numsTree2
