-- Aluna: Nathalia Fernanda de AraÃºjo Barbosa
-- Login: nfab

--1) Resultados de cada urna: uma tupla com o nÃºmero da urna e uma lista de pares com o nome de cada candidato e seus votos.
type Urna = (Int, [(String, Int)])

teste :: [Urna]
teste = [(99, [("Cand1", 89), ("Cand2", 93), ("Cand3", 99), ("Cand4", 91)]),
         (98, [("Cand1", 85), ("Cand2", 98), ("Cand3", 89), ("Cand4", 90)]),
         (97, [("Cand1", 97), ("Cand2", 93), ("Cand3", 99), ("Cand4", 92)])]

totalize :: [Urna] -> [(String, Int)]
totalize [] = []
totalize urna@((_, cands):us) = [(st, num) | st <- [fst x | x <- cands], num <- [contabilize urna st]]

contabilize :: [Urna] -> String -> Int
contabilize [] n = 0
contabilize ((a, ((nome, qtd):as)):bs) n | nome == n = qtd + contabilize bs n
                                         | otherwise = contabilize ((a, as):bs) n


--2)
ordena :: [(String, Int)] -> [(String, Int)]
ordena [] = []
ordena ((nome, num):as) = [(st, qtd) | (st, qtd) <- ordena as, qtd >= num] ++ [(nome, num)] ++ [(st, qtd) | (st, qtd) <- ordena as, qtd < num]

--3)
frequencia :: String -> [(String, Int)]
frequencia [] = []
frequencia string = [x | x <- frequenciaAux string, snd x > 1]

frequenciaAux :: String -> [(String, Int)]
frequenciaAux [] = []
frequenciaAux string = (st, count st string) : (frequenciaAux (drop 1 string))
 where st = take 2 string

count :: String -> String -> Int
count _ [] = 0
count [] _ = 0
count st s@(string:strings) | st == take 2 s = 1 + count st strings
                            | otherwise      = count st strings
                            
--tentativa (falha) de remover os pares de strings jÃ¡ contabilizados:
--count st [x | x <- strings, x /= st]

--da forma que estÃ¡, o resultado Ã©:
--[("es",2),("st",2),("te",5),(" t",3),("te",4),(" t",2),("te",3),("m ",2),("te",2)]
--deveria ser:
--[("es",2),("st",2),("te",5),(" t",3),("m ",2)]

--4)
data Chaves = No Int String Chaves Chaves | Folha

chaveTeste :: Chaves
chaveTeste = No 6 "te" (No 4 " t" Folha (No 5 "m " Folha Folha))
                       (No 8 "st" (No 7 "es" Folha Folha) Folha)


descompacta :: Chaves -> String -> String
descompacta chaves [] = []
descompacta chaves (a:as) | a >= '0' && a < '9' = buscaArvore (read [a] :: Int) chaves ++ descompacta chaves as
                          | otherwise = (a : descompacta chaves as)

buscaArvore :: Int -> Chaves -> String
buscaArvore n Folha = []
buscaArvore n (No num st t1 t2) | n == num  = st
                                | otherwise = buscaArvore n t1 ++ buscaArvore n t2
