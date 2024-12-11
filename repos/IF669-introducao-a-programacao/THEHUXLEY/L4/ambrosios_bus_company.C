// https://www.thehuxley.com/problem/268

#include <stdio.h>

typedef struct
{
    int passagem;
    char data[10];
    char origem[50];
    char destino[50];
    char horario[5];
    int poltrona;
    int idade;
    char nome[100];
} Onibus;

int main()
{
    Onibus passageiro[44];
    int contador = 0, soma = 0;
    float media = 0;

    scanf("%d", &passageiro[0].passagem);

    while (passageiro[contador].passagem != -1 && contador < 44)
    {
        scanf("%s %49[^\n] %49[^\n] %s %d %d %99[^\n]", passageiro[contador].data, passageiro[contador].origem, passageiro[contador].destino, passageiro[contador].horario, &passageiro[contador].poltrona, &passageiro[contador].idade, passageiro[contador].nome);

        soma += passageiro[contador].idade;
        media = (float)soma / (contador+1);
        contador++;

        scanf("%d", &passageiro[contador].passagem);
    }
    
    for(int i = 0; i < contador; i++)
        if (passageiro[i].poltrona % 2 == 0 && passageiro[i].idade > media)
            printf("%s\n", passageiro[i].nome);

    return 0;
}
