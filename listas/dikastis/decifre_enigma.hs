-- https://www.dikastis.com.br/problems/01EJ4Y3C6A2GF5FHM2Z74M79RT

decEnigma :: String -> [(Char, Char)] -> String
decEnigma [] _ = []
decEnigma (x:xs) tuplas = [tb | (ta,tb) <- tuplas, ta == x] ++ decEnigma xs tuplas

main = do
    a <- getLine
    b <- getLine
    let result = decEnigma a (read b)
    print result
