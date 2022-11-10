-- https://www.dikastis.com.br/problems/01EK7WFHV0SPW3XXB9AJ4HP5TC

data Tree t = Nilt |
              Node t (Tree t) (Tree t)
              deriving (Read)

isBST :: Ord t => Tree t -> Bool
isBST Nilt = True
isBST (Node v t1 t2) | null l1 && null l2                                                 = isBST t1 && isBST t2
                     | not (null l2) && v < minimum l2                                    = isBST t1 && isBST t2
                     | not (null l1) && v > maximum l1                                    = isBST t1 && isBST t2
                     | not (null l1) && v > maximum l1 && not (null l2) && v < minimum l2 = isBST t1 && isBST t2
                     | otherwise                                                          = False
 where
  nodeList Nilt = []
  nodeList (Node v' t1' t2') = (v' : nodeList t1') ++ nodeList t2'

  l1 = nodeList t1
  l2 = nodeList t2

main = do
       s <- getLine
       let result = isBST (read s::Tree Int)
       print result
