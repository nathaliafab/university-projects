-- https://www.dikastis.com.br/problems/01GAMBA01GY7W30W58P4E2MYQ7

fatPrime :: Int -> [Int] -> [Int]
fatPrime 0 _ = []
fatPrime 1 _ = []
fatPrime n primes@(p:ps) | n `mod` p == 0 = [p] ++ fatPrime (n `div` p) primes
                         | otherwise             = fatPrime n ps

makeTuples :: [Int] -> [(Int, Int)]
makeTuples [] = []
makeTuples list@(el:rest) = (el, contaOcorrencias el list) : makeTuples [el' | el' <- rest, el' /= el]

contaOcorrencias :: Int -> [Int] -> Int
contaOcorrencias x lista = length [y | y <- lista, x == y]

-- Crivo de Eratostenes
calc_primes :: [Int] -> [Int]
calc_primes (a:as) = a : (calc_primes [x | x <- as, mod x a /= 0])

-- Lista de primos
primes :: [Int]
primes = calc_primes [2..]

main :: IO ()
main = do
input <- getLine
let result = makeTuples (fatPrime(read input :: Int) primes)
print result
