#include <stdio.h>

extern void calcVol(float* vol, float r, float h);

int main (void){
    float raio, altura, volume;
    printf("Digite raio e altura: ");
    scanf("%f %f", &raio, &altura);
    calcVol(&volume, raio, altura);
    printf("\nO volume do cone eh %f", volume);
    return 0;
}