// https://www.thehuxley.com/problem/3762

#include <stdio.h>
#include <math.h>

int main()
{
    int n, k;
    int soma = 0;
    char numero[20];

    scanf("%d", &n);

    for (int j = 0; j < n; j++)
    {
        scanf("%s", numero);
        k = 5;

        if (numero[0] == '-')
            for (int i = 1; i <= 5; i++)
                soma -= (numero[i] - '0') * pow(10, --k);

        else
            for (int i = 0; i < 5; i++)
                soma += (numero[i] - '0') * pow(10, --k);
    }

    printf("%d00000000000000", soma);

    return 0;
}
