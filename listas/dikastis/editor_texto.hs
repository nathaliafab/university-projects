-- https://www.dikastis.com.br/problems/01EK8KZDTMK13T8RGSVMJ0NBE0

{-
Cursor X: anda o cursor X casas para frente (números positivos) ou para trás (números negativos). No início o cursor está na posição 0 e aponta para o primeiro caractere na String de entrada. O valor do cursor é sempre não negativo e nunca é maior que o tamanho da String de entrada. Para simplificar, nenhuma operação vai violar os limites da posição do cursor.

Backspace X: Apaga X caracteres atrás do cursor (não inclui o caractere apontado pelo cursor). Tenha em mente que esse operador também muda a posição do cursor

Delete X: Apaga X caracteres na frente do cursor (inclui o caractere apontado pelo cursor).

Insert S: Insere a String S na posição do cursor (o caractere apontado pelo cursor vai aparecer imediatamente depois de S). O cursor vai passar a apontar para o começo da String inserida
-}

data Cmd = Cursor Int
           | Backspace Int
           | Delete Int
           | Insert String
           deriving (Read)

editText :: (String, Int) -> [Cmd] -> String
editText (str, _) [] = str
editText (str, state) (c:cs) = editText (doCmd (str, state) c) cs 

doCmd :: (String, Int) -> Cmd -> (String, Int)
doCmd (str, state) (Cursor n)    = (str, state + n)
doCmd (str, state) (Backspace n) = (take (state - n) str ++ drop state str, state - n)
doCmd (str, state) (Delete n)    = (take state str ++ drop (n+state) str, state)
doCmd (str, state) (Insert s)    = (take state str ++ s ++ drop state str, state)

main = do
       a <- getLine
       b <- getLine
       let result = editText (a, 0) (read b)
       print result
