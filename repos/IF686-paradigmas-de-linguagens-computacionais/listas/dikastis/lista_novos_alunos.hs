-- https://www.dikastis.com.br/problems/01GAMBHHQWP02P97HNRE4RPJT5

bSort :: [String] -> [String]
bSort [] = []
bSort (nome:nomes) = [v | v <- bSort nomes, v <= nome] ++ [nome] ++ [v | v <- bSort nomes, v > nome]

main = do
       a <- getLine
       let result = bSort (read a :: [String])
       print result
