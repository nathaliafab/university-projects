-- https://www.dikastis.com.br/problems/01EJ4RW7VX84CGDP1WR22PDSVN

btoi :: String -> Int
btoi [] = 0
btoi (x:[]) = read [x] :: Int
btoi (x:xs) = (read [x] :: Int)*(2^(length(x:xs) - 1)) + btoi xs

main = do
    s <- getLine
    let result = btoi s
    print result
