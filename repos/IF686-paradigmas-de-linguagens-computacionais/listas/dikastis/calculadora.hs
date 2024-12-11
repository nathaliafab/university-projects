-- https://www.dikastis.com.br/problems/01EJ4TJV7XT8F6XFQMMNFZT445

type Comando = String
type Valor = Int

member :: (Comando, Valor) -> [(Comando, Valor)] -> Bool
member (c, v) [] = False
member (c, v) (a:as) | c == (fst a) && v == (snd a) = True
                     | otherwise                    = member (c, v) as

executa :: [(Comando, Valor)] -> Int
executa [] = 0
executa (a:as) | c1 == "Soma"              = executa as + v1
               | c1 == "Subtrai"           = executa as - v1
               | c1 == "Multiplica"        = executa as * v1
               | c1 == "Divide" && v1 /= 0 = executa as `div` v1
               | otherwise                 = executa as
 where
  c1 = fst a
  v1 = snd a

initial :: [(Comando, Valor)] -> [(Comando, Valor)]
initial [] = []
initial (a:as) | member ("Divide", 0) (a:as) = [("Soma", -666)]
               | c1 == "Multiplica"          = as
               | c1 == "Divide" && v1 /= 0   = as
               | otherwise                   = (a:as)
 where
  c1 = fst a
  v1 = snd a

main = do
    a <- getLine
    let result = executa (reverse(initial(read a)))
    print result
