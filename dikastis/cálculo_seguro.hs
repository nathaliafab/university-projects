-- https://www.dikastis.com.br/problems/01EMBWYKP4KNJR1X64N8017Z9K

{-
input:  xOPy; x e y são números naturais e OP é uma operação (sum, sub, mul e div)
output: Just + resultado
* o resultado pode ser um número negativo;
* no caso de divisão por 0, o resultado deverá ser Nothing.
-}

import Prelude hiding (Maybe (..))

data Maybe a = Just a |
               Nothing
               deriving(Show)

makeTuple :: String -> (Int, String, Int)
makeTuple str = (read n, op, read n2)
 where
  n  = takeWhile (\x -> (x >='0' && x<='9') || (x == '-')) str
  op = takeWhile (\x -> x > '9') (drop (length n) str)
  n2 = takeWhile (\x -> (x >='0' && x<='9') || (x == '-')) (drop (length (n++op)) str)

makeOperation :: (Int, String, Int) -> Maybe Int
makeOperation (n, op, n2) | op == "sum" = Just (n + n2)
                          | op == "sub" = Just (n - n2)
                          | op == "mul" = Just (n * n2)
                          | op == "div" && n2 /= 0 = Just (n `div` n2)
                          | otherwise = Nothing

safeCalc :: String -> IO ()
safeCalc str = print (makeOperation(makeTuple str))

main = do
       a <- getLine
       safeCalc a
