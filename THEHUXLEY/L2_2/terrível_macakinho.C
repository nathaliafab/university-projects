// https://www.thehuxley.com/problem/3687

#include <stdio.h>

int main()
{
    int quant, isPrime = 1;
    int i, j, k, u;
    double sum = 0.0;

    scanf("%d", &quant);

    for (i = 1, k = 1; i <= quant; i++)
    {
        do
        {
            k++;
            j = 2;

            while (j <= k)
            {
                if (k == j)
                {
                    isPrime = 1;
                    break;
                }

                else if (k % j == 0)
                {
                    isPrime = 0;
                    break;
                }

                j++;
            }

            if (isPrime)
            {
                for (u = 2, k = k + 2; u < k; u++)
                {
                    if (k % u == 0)
                    {
                        isPrime = 0;
                        break;
                    }
                }

                if (isPrime)
                    sum += (1.0 / j) + (1.0 / k);

                k -= 2;
            }
        } while (!isPrime);
    }

    printf("%.10lf", sum);

    return 0;
}
