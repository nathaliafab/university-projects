-- https://www.dikastis.com.br/problems/01EJ6YNXGMRZC31AQ90AFFK5V6

organiza :: String -> [(Int, String, String, Double)]
organiza str = makeTuples splitString
 where
  makeTuples [] = []
  makeTuples m = (read (m!!0) :: Int, m!!1, m!!2, read (m!!3) :: Double) : makeTuples (drop 4 m)
  splitString = words [if i == ';' then ' ' else i | i <- str]

somenteValor :: [(Int, String, String, Double)] -> [Double]
somenteValor lista = [d | (a,b,c,d) <- lista]

minMaxCartao :: String -> (Double, Double)
minMaxCartao str = (minNum a, maxNum a)
 where
  a = somenteValor(organiza str)
  maxNum :: [Double] -> Double
  maxNum [x] = x
  maxNum (x:xs) | (maxNum xs) >= x = maxNum xs
                | otherwise = x

  minNum :: [Double] -> Double
  minNum [x] = x
  minNum (x:xs) | (minNum xs) <= x = minNum xs
                | otherwise = x

main = do
    a <- getLine
    let result = minMaxCartao a
    print result
