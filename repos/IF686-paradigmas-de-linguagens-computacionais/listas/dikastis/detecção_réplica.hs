-- https://www.dikastis.com.br/problems/01EJ50KMHA1Z6AXFSX5CQHFEEN

criaString :: Int -> Char -> String
criaString 0 _ = []
criaString n x = (x : criaString (n-1) x)

isReplica :: String -> Int -> Char -> Bool
isReplica xs n x | xs == criaString n x = True
                 | otherwise = False

main = do
    a <- getLine
    b <- getLine
    c <- getChar
    let result = isReplica a (read b) c
    print result
