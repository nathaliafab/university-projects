// https://www.thehuxley.com/problem/239

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char cor[50];
    char tamanho;
} Camisetas;

int main()
{
    Camisetas turma[60];
    Camisetas turmaTemp;
    int quantidade, i, j;

    while (scanf("%d", &quantidade) != EOF)
    {
        for (i = 0; i < quantidade; i++)
            scanf(" %49[^\n]  %s  %c", turma[i].nome, turma[i].cor, &turma[i].tamanho);

        for (i = 0; i < quantidade; i++)
            for (j = 0; j < quantidade - 1; j++)
            {
                if (strcmp(turma[j].cor, turma[j + 1].cor) > 0)
                {
                    turmaTemp = turma[j];
                    turma[j] = turma[j + 1];
                    turma[j + 1] = turmaTemp;
                }

                if (strcmp(turma[j].cor, turma[j + 1].cor) == 0)
                {
                    if (turma[j].tamanho < turma[j + 1].tamanho)
                    {
                        turmaTemp = turma[j];
                        turma[j] = turma[j + 1];
                        turma[j + 1] = turmaTemp;
                    }

                    else if (turma[j].tamanho == turma[j + 1].tamanho && strcmp(turma[j].nome, turma[j + 1].nome) > 0)
                    {
                        turmaTemp = turma[j];
                        turma[j] = turma[j + 1];
                        turma[j + 1] = turmaTemp;
                    }
                }
            }

        for (i = 0; i < quantidade; i++)
            printf("%s %c %s\n", turma[i].cor, turma[i].tamanho, turma[i].nome);

        printf("\n");
    }

    return 0;
}
