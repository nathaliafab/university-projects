-- https://www.dikastis.com.br/problems/01EK8F2B8KV7XJC1BTB1AQ7R1Q

data Tree t = Nilt |
               Node t (Tree t) (Tree t)
               deriving (Read, Show)

insertList :: Ord t => Tree t -> [t] -> Tree t
insertList tree [] = tree
insertList tree (a:as) = insertList (insertEl tree a) as

insertEl :: Ord t => Tree t -> t -> Tree t
insertEl Nilt el = Node el (Nilt) (Nilt)
insertEl (Node v t1 t2) el | el < v    = Node v (insertEl t1 el) t2
                           | otherwise = Node v t1 (insertEl t2 el)

main = do
       a <- getLine
       b <- getLine
       let result = insertList (read a::Tree Int) (read b)
       print result
