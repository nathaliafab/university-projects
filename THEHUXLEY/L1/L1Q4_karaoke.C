// https://www.thehuxley.com/problem/2423

#include <stdio.h>
#include <math.h>

int main()
{
    int N, M, T1, V1, T2, V2, T3, V3, vergonha;
    float Nideal;

    scanf("%d %d %d %d %d %d %d %d", &N, &M, &T1, &V1, &T2, &V2, &T3, &V3);

    Nideal = sqrt(N);

    if (Nideal > M)
        printf("N�o cantarei, desculpa.");

    else
    {
        V1 = T1 * T1 * V1;
        V2 = T2 * T2 * V2;
        V3 = T3 * T3 * V3;

        if (V1 <= V2 && V1 <= V3)
            vergonha = 1;

        else if (V2 < V1 && V2 <= V3)
            vergonha = 2;

        else
            vergonha = 3;

        printf("Voc� deve cantar a m�sica %d, boa sorte!", vergonha);
    }

    return 0;
}
