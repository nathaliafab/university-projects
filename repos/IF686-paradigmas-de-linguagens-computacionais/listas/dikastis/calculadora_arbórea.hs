-- https://www.dikastis.com.br/problems/01EK7TQ1WC7BHVT5P5MPAHVS74

data Ops = SUM | MUL | SUB
           deriving (Read)

data IntTree = Nilt Int |
               Node Ops IntTree IntTree
               deriving (Read)

evalTree :: IntTree -> Int
evalTree (Nilt t) = t
evalTree (Node SUM t1 t2) = evalTree t1 + evalTree t2
evalTree (Node SUB t1 t2) = evalTree t1 - evalTree t2
evalTree (Node MUL t1 t2) = evalTree t1 * evalTree t2

main = do
    s <- getLine
    let result = evalTree (read s)
    print result
