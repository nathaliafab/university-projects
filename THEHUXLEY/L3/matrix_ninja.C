// https://www.thehuxley.com/problem/3763

#include <stdio.h>

int main()
{
    int i, j, linha, coluna, temp;
    char direcao;

    scanf("%c %d %d", &direcao, &linha, &coluna);
    int matriz[linha][coluna];

    for (i = 0; i < linha; i++)
        for (j = 0; j < coluna; j++)
            scanf("%d", &matriz[i][j]);

    if (direcao == 'H')
    {
        for (i = linha / 2; i < linha; i++)
            for (j = 0; j < coluna / 2; j++)
            {
                temp = matriz[i][j];
                matriz[i][j] = matriz[i][coluna - j - 1];
                matriz[i][coluna - j - 1] = temp;
            }
    }

    else if (direcao == 'V')
    {
        for (i = 0; i < linha / 2; i++)
            for (j = coluna / 2; j < coluna; j++)
            {
                temp = matriz[i][j];
                matriz[i][j] = matriz[linha - i - 1][j];
                matriz[linha - i - 1][j] = temp;
            }
    }

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
            printf("%02d ", matriz[i][j]);

        printf("\n");
    }

    return 0;
}
