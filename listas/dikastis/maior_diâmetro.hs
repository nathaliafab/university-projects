-- https://www.dikastis.com.br/problems/01GAMBR9JE3DB64QZN133VAH6S

data Tree t = Nilt |
              Node t (Tree t) (Tree t)
              deriving (Read)

depth :: Tree t -> Int
depth Nilt = 1
depth (Node a t1 t2) = 1 + max (depth t1) (depth t2)

maiorDiametro :: Ord t => Tree t -> Int
maiorDiametro tree = foldl1 (max) (listAlturas tree)

listAlturas :: Ord t => Tree t -> [Int]
listAlturas Nilt = [0]
listAlturas (Node a t1 t2) = listAlturas t1 ++ [depth t1 + depth t2 - 1] ++ listAlturas t2

main = do
       s <- getLine
       let result = maiorDiametro (read s::Tree Int)
       print result
