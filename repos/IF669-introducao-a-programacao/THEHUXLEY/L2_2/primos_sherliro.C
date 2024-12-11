// https://www.thehuxley.com/problem/3689

#include <stdio.h>

int main()
{
    long long int sinal, sinalTemp, k, j;
    int count, flag = 0, isPrime;
    float sum;

    for (int i = 0; i < 3; i++)
    {
        scanf("%lld", &sinal);
        sinalTemp = sinal;
        sum = 0.0;
        count = 0;

        if (!flag)
        {
            for (j = 3; j <= sinalTemp; j += 2)
            {
                isPrime = 1;

                for (k = 3; isPrime && k <= j / 2; k += 2)
                    if (j % k == 0)
                        isPrime = 0;

                while (isPrime && sinalTemp % j == 0)
                {
                    sum += (float)j / ++count;
                    sinalTemp /= j;
                }
            }

            if (sum == sinal || sinal < 3)
                flag = 1;

            else
            {
                if (sum > (int)sum)
                    sum = (int)sum + 1;

                if ((int)sum % 2 != 0)
                {
                    flag = 1;

                    for (int i = 3; flag && i <= sum / 2; i += 2)
                        if ((int)sum % i == 0)
                            flag = 0;
                }
            }

            flag ? printf("SHERLIRO SALVOU MULITTLE\n") : printf("ERRO\n");
        }

        else
            printf("SINAL OFF\n");
    }

    return 0;
}
