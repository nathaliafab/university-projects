#include <stdio.h>
#include <stdlib.h>

extern void calcularPI(float *pi, int *n);

int main(void) {
    float pi;
    int n;

    printf("Digite o número de iterações: ");
    calcularPI(&pi, &n);
    printf("PI = %f", pi);

    return 0;
}