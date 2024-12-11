// https://www.thehuxley.com/problem/331

#include <stdio.h>

typedef struct
{
    int idade;
    char nome[50];
    char sexo;
    char estado;
    int amigos;
    int fotos;
} WOOF;

int main()
{
    int quantidade;
    WOOF pessoa;

    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++)
    {
        scanf("%d %49[^\n] %c %c %d %d", &pessoa.idade, pessoa.nome, &pessoa.sexo, &pessoa.estado, &pessoa.amigos, &pessoa.fotos);

        printf("Idade: %d\nNome: %s\nSexo: %c\nEstado Civil: %c\nNumero de amigos: %d\nNumero de fotos: %d\n", pessoa.idade, pessoa.nome, pessoa.sexo, pessoa.estado, pessoa.amigos, pessoa.fotos);

        printf("\n");
    }

    return 0;
}
