-- https://www.dikastis.com.br/problems/01EJ6XQ48PTRB83YYD35Q7PB0E

organiza :: String -> [(Int, String, String, Double)]
organiza str = makeTuples splitString
 where
  makeTuples [] = []
  makeTuples m = (read (m!!0) :: Int, m!!1, m!!2, read (m!!3) :: Double) : makeTuples (drop 4 m)
  splitString = words [if i == ';' then ' ' else i | i <- str]

--recebe uma String JAN, FEV, MAR ou ABR e uma String referente a uma fatura anual e retorna o total gasto no mês em questão.
logMes :: String -> String -> Double
logMes stmes str = foldl (+) 0 ([valor | (_, mes, _, valor) <- strOrg, mes == stmes])
 where
  strOrg = organiza str

main = do
    a <- getLine
    b <- getLine
    let result = logMes a b
    print result
