-- https://www.dikastis.com.br/problems/01GAMANBTZB1CZ1YD1EP8JEAVY

data Tree t = Node t (Tree t) (Tree t) | Nilt
  deriving (Read, Show)

dna1 :: Tree Int -> [Int]
dna1 Nilt = []
dna1 (Node a t1 t2) = dna1 t1 ++ ((a `mod` 5) : (dna1 t2))

splitIn8 :: String -> [String]
splitIn8 [] = []
splitIn8 str = let (st1, st2) = splitAt 8 str
               in st1 : splitIn8 st2

translate :: [Int] -> String
translate [] = []
translate (a:as) | show a == "0" = "E" ++ (translate as)
                 | show a == "1" = "M" ++ (translate as)
                 | show a == "2" = "A" ++ (translate as)
                 | show a == "3" = "C" ++ (translate as)
                 | show a == "4" = "S" ++ (translate as)

func :: Tree Int -> [String]
func tree = splitIn8 (translate (dna1 tree))

main :: IO ()
main = do
  input <- getLine
  let result = func (read input :: Tree Int)
  print result
