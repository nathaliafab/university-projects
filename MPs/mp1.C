//Nome: Nathalia Fernanda de Araújo Barbosa
//Login: nfab
//Data: 15/07/2021
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char mat[10];   //matricula
    float vetor[5]; //notas
    int faltas;
} Aluno;

typedef struct
{
    int qtd; //qt de alunos
    char professor[20];
    char id[5];
    Aluno *alunos; //lista de alunos
} Turma;

int main(void)
{
    int operacao, i, k = 0, flag = 0;
    char idzin[5];
    float media = 0;
    Turma *turma = NULL, *turmaAux = NULL;
    Aluno procura, *alunosAux = NULL;

    turma = (Turma *)malloc(sizeof(Turma));
    turma[k].alunos = (Aluno *)malloc(sizeof(Aluno));

    while (1)
    {
        scanf("%d", &operacao);

        switch (operacao)
        {
        case 1:
            do
            {
                turmaAux = (Turma *)realloc(turma, sizeof(Turma));

                if (turmaAux == NULL)
                    exit(1);

                turma[k] = turmaAux[k];
                printf("\nQt de alunos, professor e id:\n");
                scanf("%d %s %s", &turma[k].qtd, turma[k].professor, turma[k].id);

                if (turma[k].qtd == 0)
                    break;

                alunosAux = (Aluno *)realloc(turma[k].alunos, turma[k].qtd * sizeof(Aluno));

                if (alunosAux == NULL)
                    exit(1);

                turma[k].alunos = alunosAux;

                for (i = 0; i < (turma[k].qtd); i++)
                {
                    printf("\nNome e matricula:\n");
                    scanf("%s %s", turma[k].alunos[i].nome, turma[k].alunos[i].mat);

                    printf("\n5 notas:\n");
                    for (int j = 0; j < 5; j++)
                        scanf("%f", &turma[k].alunos[i].vetor[j]);

                    printf("\nFaltas:\n");
                    scanf("%d", &turma[k].alunos[i].faltas);
                }

                k++;
            } while (turma[k].qtd != 0);

            break;

        case 2:
            printf("\nNome e matricula:\n");
            scanf("%s %s", procura.nome, procura.mat);
            for (int p = 0; !flag && p < k; p++)
            {
                for (i = 0; i < !flag && turma[p].qtd; i++)
                {
                    if (strcmp(turma[p].alunos[i].nome, procura.nome) == 0 && strcmp(turma[p].alunos[i].mat, procura.mat) == 0)
                    {
                        flag = 1;
                        strcpy(turma[p].alunos[i].nome, "");
                        strcpy(turma[p].alunos[i].mat, "");
                    }
                }
            }

            flag = 0;

            break;

        case 3:
            printf("\nId:\n");
            scanf("%s", idzin);

            for (int p = 0; p < k; p++)
            {
                if (strcmp(turma[p].id, idzin) == 0)
                {
                    for (i = 0; i < (turma[p].qtd); i++)
                    {
                        for (int j = 0; j < 5; j++)
                            media += turma[p].alunos[i].vetor[j];

                        media /= 5;

                        if (media >= 7 && strcmp(turma[p].alunos[i].nome, "") != 0)
                            printf("%s passou com media %.1f.\n", turma[p].alunos[i].nome, media);

                        media = 0;
                    }
                }
            }

            break;

        case 4:
            printf("\nId:\n");
            scanf("%s", idzin);

            for (int p = 0; p < k; p++)
            {
                if (strcmp(turma[p].id, idzin) == 0)
                {
                    for (i = 0; i < (turma[p].qtd); i++)
                    {
                        for (int j = 0; j < 5; j++)
                            media += turma[p].alunos[i].vetor[j];

                        media /= 5;

                        if (media < 3 && strcmp(turma[p].alunos[i].nome, "") != 0)
                            printf("%s reprovou com media %.1f.\n", turma[p].alunos[i].nome, media);

                        media = 0;
                    }
                }
            }

            break;

        case 5:
            for (int p = 0; p < k; p++)
            {
                printf("%s\n", turma[p].professor);
                for (i = 0; i < turma[p].qtd; i++)
                {
                    for (int l = 0; l < turma[p].qtd - 1; l++)
                    {
                        if (strcmp(turma[p].alunos[l].nome, turma[p].alunos[l + 1].nome) > 0)
                        {
                            strcpy(procura.nome, turma[p].alunos[l].nome);
                            strcpy(turma[p].alunos[l].nome, turma[p].alunos[l + 1].nome);
                            strcpy(turma[p].alunos[l + 1].nome, procura.nome);
                        }
                    }
                }

                for (i = 0; i < turma[p].qtd; i++)
                    if (strcmp(turma[p].alunos[i].nome, "") != 0)
                        printf("%s\n", turma[p].alunos[i].nome);
            }
            break;
        }
    }

    for (i = 0; i < k; i++)
        free(turma[i].alunos);

    free(turma);

    return 0;
}
