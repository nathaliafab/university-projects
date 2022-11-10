-- https://www.dikastis.com.br/problems/01EJ1RWY5SK0QQH1S4HRBN9D5V

sumTo :: Int -> Int
sumTo 0 = 0
sumTo n = n + sumTo (n-1)

main :: IO()
main = interact $ show . sumTo . read
