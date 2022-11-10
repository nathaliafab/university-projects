// https://www.thehuxley.com/problem/1068

#include <stdio.h>

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);

    if (x == 0)
        (y != 0) ? printf("Sobre o eixo y") : printf("Sobre a origem");

    else if (y == 0)
        printf("Sobre o eixo x");

    else if (x > 0)
        (y > 0) ? printf("Primeiro Quadrante") : printf("Quarto Quadrante");

    else
        (y > 0) ? printf("Segundo Quadrante") : printf("Terceiro Quadrante");

    return 0;
}
