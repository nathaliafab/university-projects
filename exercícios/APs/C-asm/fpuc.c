#include <stdio.h>

extern float calc_volume_cone(float, float);

int main(void){
    float raio, altura, resultado;

    printf("Digite o raio e a altura do cone: ");
    scanf("%f %f", &raio, &altura);

    resultado = calc_volume_cone(raio, altura);

    printf("O volume do cone é: %f\n", resultado);

    return 0;
}