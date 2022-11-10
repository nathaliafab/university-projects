-- https://www.dikastis.com.br/problems/01GAMCJAHA72Y6E6C3QH254M34

somarListas :: [Int] -> [Int] -> [Int]
somarListas [] [] = []
somarListas n1 n2 = makeList (show (makeSum (toString n1) (toString n2)))

toString :: [Int] -> String
toString [] = []
toString number = foldr ((++) . show) [] number

makeSum :: String -> String -> Int
makeSum n1 [] = read n1
makeSum [] n2 = read n2
makeSum n1 n2 = read n1 + read n2

makeList :: String -> [Int]
makeList [] = []
makeList str@(a:as) = map (\a -> read [a]) str

main :: IO ()
main = do
input1 <- getLine
input2 <- getLine
let result = somarListas (read input1 :: [Int])  (read input2 :: [Int])
print result
