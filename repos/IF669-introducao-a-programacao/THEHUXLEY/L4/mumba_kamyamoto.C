// https://www.thehuxley.com/problem/3766

#include <stdio.h>
#include <math.h>

typedef struct
{
    int x, y, z;
} Caixa;

int main()
{
    int quantidade, i, idMenor;
    double menorDist;

    while (scanf("%d", &quantidade) != EOF)
    {
        Caixa caixa[quantidade], coordAtual = {0, 0, 0};
        double distancia[quantidade];
        int idGasto[quantidade], count = quantidade;

        for (i = 0; i < quantidade; i++)
        {
            scanf("%d %d %d", &caixa[i].x, &caixa[i].y, &caixa[i].z);
            idGasto[i] = 0;
        }

        while (count > 0)
        {
            menorDist = 1e37;
            idMenor = 0;

            for (i = 0; i < quantidade; i++)
            {
                if (idGasto[i])
                    continue;

                distancia[i] = sqrt(pow(caixa[i].x - coordAtual.x, 2) + pow(caixa[i].y - coordAtual.y, 2) + pow(caixa[i].z - coordAtual.z, 2));

                if (i == 0)
                    menorDist = distancia[i];

                else if (distancia[i] < menorDist)
                {
                    menorDist = distancia[i];
                    idMenor = i;
                }
            }

            coordAtual = caixa[idMenor];
            idGasto[idMenor] = 1;

            printf("%d", idMenor + 1);

            count--;
            if (count)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}
