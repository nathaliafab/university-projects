// https://www.thehuxley.com/problem/3676

#include <stdio.h>
#include <math.h>

int main()
{
    double orcamento, gas_1, pedagio_1, gas_2, pedagio_2;
    double distancia1, distancia2, gasto1, gasto2;
    double x, y, a, b, c, d;

    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &orcamento, &x, &y, &a, &b, &c, &d, &gas_1, &pedagio_1, &gas_2, &pedagio_2);

    distancia1 = sqrt(pow(x - a, 2) + pow(y - b, 2));
    distancia2 = sqrt(pow(x - c, 2) + pow(y - d, 2));

    gasto1 = ((distancia1) / 12) * gas_1 * 2 + pedagio_1;
    gasto2 = ((distancia2) / 12) * gas_2 * 2 + pedagio_2;

    if (orcamento < gasto1 && orcamento < gasto2)
        printf("Ele vai ficar em casa\n-1");

    else
    {
        if (orcamento >= gasto1 + gasto2)
            printf("Ele vai visitar os dois lugares\n%.2f", gasto1 + gasto2);

        else if (orcamento >= gasto1 && gasto1 == gasto2)
            printf("Tanto faz...\n%.2f", gasto1);

        else
            gasto1 > gasto2 ? printf("Ele vai para o destino 2\n%.2f", gasto2) : printf("Ele vai para o destino 1\n%.2f", gasto1);
    }

    return 0;
}
