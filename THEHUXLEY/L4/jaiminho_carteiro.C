// https://www.thehuxley.com/problem/3767

#include <stdio.h>
#include <string.h>

typedef struct
{
    int numero;
    int andar;
    int apt;
    char morador[50];
    char sexo;
    char dataNasc[10];
} Edificio;

typedef struct
{
    int numero;
    char morador[50];
    char sexo;
    char dataNasc[10];
} Casa;

typedef struct
{
    char nomeRua[50];
    Casa casas[200];
    Edificio edificios[200];
} Rua;

int main()
{
    int operacao, ruaAtual = 0, i = 0, j, k = 0, c = 0, e = 0, contador = 0, novaRua, pVez = 1;
    char decidir, nomeDaPessoa[50], nomeRuaTemp[50];
    Rua ruas[50];

    scanf("%d", &operacao);

    while (1)
    {
        if (operacao == 1)
        {
            novaRua = 0;

            scanf(" %[^\n]", nomeRuaTemp);
            scanf(" %c", &decidir);

            if (ruaAtual == 0 && pVez)
            {
                strcpy(ruas[0].nomeRua, nomeRuaTemp);
                pVez = 0;
            }

            else
            {
                for (ruaAtual = 0; ruaAtual <= k; ruaAtual++)
                {
                    if (strcmp(nomeRuaTemp, ruas[ruaAtual].nomeRua) == 0)
                    {
                        novaRua = 0;
                        break;
                    }

                    else
                        novaRua = 1;
                }

                if (novaRua)
                {
                    k++;
                    ruaAtual = k;
                    strcpy(ruas[ruaAtual].nomeRua, nomeRuaTemp);
                }
            }

            if (decidir == 'c')
            {
                scanf("%d", &ruas[ruaAtual].casas[c].numero);
                scanf(" %[^\n]", ruas[ruaAtual].casas[c].morador);
                scanf(" %c", &ruas[ruaAtual].casas[c].sexo);
                scanf(" %s", ruas[ruaAtual].casas[c].dataNasc);

                c++;
            }

            else
            {
                scanf("%d %d %d", &ruas[ruaAtual].edificios[e].numero, &ruas[ruaAtual].edificios[e].andar, &ruas[ruaAtual].edificios[e].apt);
                scanf(" %[^\n]", ruas[ruaAtual].edificios[e].morador);
                scanf(" %c", &ruas[ruaAtual].edificios[e].sexo);
                scanf(" %s", ruas[ruaAtual].edificios[e].dataNasc);

                e++;
            }

            ruaAtual++;
        }

        else if (operacao == 2)
        {
            if (pVez)
                return 0;

            scanf(" %[^\n]", nomeDaPessoa);
            scanf(" %[^\n]", nomeRuaTemp);
            contador = 0;

            for (i = 0; i < 5; i++)
                if (strcmp(ruas[i].nomeRua, nomeRuaTemp) == 0)
                    break;

            if (strcmp(ruas[i].nomeRua, nomeRuaTemp) == 0)
            {
                for (j = 0; j < c; j++)
                    if (strcmp(ruas[i].casas[j].morador, nomeDaPessoa) == 0)
                    {
                        printf("Casa: %d | Sexo: %c | Nascimento: %s\n", ruas[i].casas[j].numero, ruas[i].casas[j].sexo, ruas[i].casas[j].dataNasc);
                        contador++;
                    }

                for (j = 0; j < e; j++)
                    if (strcmp(ruas[i].edificios[j].morador, nomeDaPessoa) == 0)
                    {
                        printf("Edificio: %d | Andar: %d | Numero do apt.: %d | Sexo: %c | Nascimento: %s\n", ruas[i].edificios[j].numero, ruas[i].edificios[j].andar, ruas[i].edificios[j].apt, ruas[i].edificios[j].sexo, ruas[i].edificios[j].dataNasc);
                        contador++;
                    }
            }

            if (contador)
                printf("Foram encontradas %d instancias de pessoas chamadas \"%s\" em \"%s\", relatadas acima.\n", contador, nomeDaPessoa, nomeRuaTemp);

            else
                printf("Sem dados de \"%s\" em \"%s\"!\n", nomeDaPessoa, nomeRuaTemp);
        }

        else if (operacao == 3)
        {
            printf("O programa sera fechado, obrigado por fazer uso dele. Lembre-se de evitar a fadiga!\n");
            return 0;
        }

        else
            printf("Opcao invalida. Por favor, digite uma opcao valida.\n");
        scanf("%d", &operacao);
    }

    return 0;
}
