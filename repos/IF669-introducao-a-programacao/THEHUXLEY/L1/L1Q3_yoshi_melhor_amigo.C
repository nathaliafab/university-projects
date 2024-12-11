// https://www.thehuxley.com/problem/2225

#include <stdio.h>

int main()
{
    int M, A, B, C, D;
    float custoBeneVr, custoBeneVm, custoBeneRx, custoBeneAm;

    scanf("%d %d %d %d %d", &M, &A, &B, &C, &D);

    custoBeneVr = (float)80 / A;
    custoBeneVm = (float)100 / B;
    custoBeneRx = (float)120 / C;
    custoBeneAm = (float)80 / D;

    if ((M < A) && (M < B) && (M < C) && (M < D))
        printf("Acho que vou a pe :(");

    else
    {
        if ((custoBeneVr >= custoBeneVm) && (custoBeneVr >= custoBeneRx) && (custoBeneVr >= custoBeneAm))
            printf("Verde");

        else if ((custoBeneVm > custoBeneVr) && (custoBeneVm >= custoBeneRx) && (custoBeneVm >= custoBeneAm))
            printf("Vermelho");

        else if ((custoBeneRx > custoBeneVr) && (custoBeneRx > custoBeneVm) && (custoBeneRx >= custoBeneAm))
            printf("Roxo");

        else
            printf("Amarelo");
    }

    return 0;
}
