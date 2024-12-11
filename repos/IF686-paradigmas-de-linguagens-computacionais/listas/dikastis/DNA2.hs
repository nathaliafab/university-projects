-- https://www.dikastis.com.br/problems/01GAMAV0ZXGV86Z8BFXTQTDD4E

data Animal = Cisnal | Iguanoide | Narvale | Null
  deriving (Eq, Show)

dna2 :: [String] -> [String] -> [Int]
dna2 [] _ = [0,0,0]
dna2 _ [] = [0,0,0]
dna2 st1 st2 = [countCisnal prob, countIguanoide prob, countNarvale prob]
 where prob = probabilidade st1 st2

probabilidade :: [String] -> [String] -> [Float]
probabilidade [] _ = []
probabilidade _ [] = []
probabilidade (a:as) (b:bs) = (cmp / alt) : probabilidade as bs
 where
  cmp = strcmp a b
  alt = fromIntegral (max (length a) (length b)) :: Float

countCisnal list    = length [x | x <- list, x >= 0.1 && x <= 0.3]
countIguanoide list = length [x | x <- list, x >= 0.4 && x <= 0.7]
countNarvale list   = length [x | x <- list, x >= 0.8]

strcmp :: String -> String -> Float
strcmp [] _ = 0.0
strcmp _ [] = 0.0
strcmp (a:as) (b:bs) | a == b    = 1.0 + strcmp as bs
                     | otherwise = strcmp as bs

main = do
  firstExtract <- words <$> getLine
  secondExtract <- words <$> getLine
  let result = dna2 firstExtract secondExtract
  print result
