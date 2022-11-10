// https://www.thehuxley.com/problem/3333

#include <stdio.h>

int main()
{
    char letra;
    int comparador, comparador2, value = 65, flag = 0;

    scanf("%c", &letra);

    comparador = letra - 64;
    comparador2 = comparador - 1;

    for (int i = 1; i <= comparador; i++)
    {
        for (int j = 1; j <= comparador * 2 - 1; j++)
        {
            if (comparador2 != 0 && (j <= comparador2 || j > comparador2 + 2 * i - 1))
                printf(".");
            else
            {
                if (flag == 0 && value < 64 + i)
                    printf("%c", value++);

                else
                {
                    flag = 1;
                    printf("%c", value--);
                }
            }
        }

        comparador2--;
        value = 65;
        flag = 0;
        printf("\n");
    }

    return 0;
}
