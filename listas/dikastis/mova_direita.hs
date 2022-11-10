-- https://www.dikastis.com.br/problems/01EJ1VZYR11JR59CDKK3FB996E

addEspacos :: Int -> String
addEspacos n    | n == 0    = ""
                | otherwise = " " ++ addEspacos (n-1)

paraDireita :: Int -> String -> String
paraDireita n st = addEspacos n ++ st

parseInput str = let [n, s] = words str
                 in (read n, s)
main :: IO()
main = interact $ uncurry paraDireita . parseInput
