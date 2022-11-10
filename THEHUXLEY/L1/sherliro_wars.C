// https://www.thehuxley.com/problem/3677

#include <stdio.h>

int main()
{
    float dTotal, precoA, precoB, divida, maior = 0, menor = 0, gasto = 0;
    int flag1, flag2;

    scanf("%f %i %i %f %f %f", &dTotal, &flag1, &flag2, &precoA, &precoB, &divida);

    if (flag1 == 1 && flag2 == 1)
    {
        if (precoA > precoB)
        {
            maior = precoA;
            menor = precoB;
        }

        else
        {
            maior = precoB;
            menor = precoA;
        }

        maior *= 0.88;
        gasto = maior + menor;
    }

    else if (flag1 == 1)
        gasto = precoA;

    else if (flag2 == 1)
        gasto = precoB;

    if (dTotal >= gasto + divida)
        printf("Sherliro livre do Jabbavitz e podendo voar");

    else if (dTotal >= gasto)
        printf("Sherliro consertou mas ta lascado com o Jabbavitz\nfaltam %.2f Napoleocoins", gasto + divida - dTotal);

    else
        printf("Sherliro vai ser perseguido hoje e ainda ta sem nave\nfaltam %.2f Napoleocoins", gasto + divida - dTotal);

    return 0;
}
