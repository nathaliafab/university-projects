// https://www.thehuxley.com/problem/3332

#include <stdio.h>

int main()
{
    int A, B, i, j, quant = 0;
    int primoMenor, primoMaior, pZeca;
    int isPrime, primeiraVezA = 1, primeiraVezB = 1;

    scanf("%d %d", &A, &B);

    pZeca = (A / 2) - 1;

    while (pZeca <= B)
    {
        for (i = pZeca + 1; i <= 2 * B; i++)
        {
            isPrime = 1;

            if (i < 2)
                isPrime = 0;

            for (j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }

            if (!isPrime)
                continue;

            if (isPrime && primeiraVezA)
            {
                primoMenor = i;
                primeiraVezA = 0;
                continue;
            }

            if (isPrime && primeiraVezB)
            {
                pZeca = i;
                primeiraVezB = 0;
                continue;
            }

            if (isPrime && !primeiraVezA && !primeiraVezB)
            {
                primoMaior = i;
                break;
            }
        }

        if (pZeca >= A && pZeca == (primoMaior + primoMenor) / 2.0)
            quant++;

        primoMenor = pZeca;
        pZeca = primoMaior;
    }

    printf("%d", quant);

    return 0;
}
