// https://www.thehuxley.com/problem/3761

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, contador = 0;
    int andares, limite, solicitacoes;
    int andar, andarAnterior = 0, quantidade;

    scanf("%d %d %d", &andares, &limite, &solicitacoes);

    int elevador[andares];

    for (i = 0; i < andares; i++)
        elevador[i] = 0;

    for (i = 0; i < solicitacoes; i++)
    {
        scanf("%d %d", &andar, &quantidade);

        elevador[andar] += elevador[andarAnterior] + quantidade;
        contador += abs(andar - andarAnterior);
        andarAnterior = andar;

        while (elevador[andar] >= limite) //se igualar ou passar o limite
        {
            elevador[andar] -= limite;
            contador += andar; //ele desce

            if (elevador[andar] > 0) //se sobrar gente, ele sobe
            {
                contador += andar;

                if (i == solicitacoes - 1) //se for o �ltimo, ele desce dnv
                {
                    contador += andar;
                    elevador[andar] -= limite;

                    while (elevador[andar] > 0) //se ainda sobrar gente
                    {
                        contador += 2 * andar; //sobe e desce
                        elevador[andar] -= limite;
                    }
                }
            }

            else if (elevador[andar] == 0 && i < solicitacoes - 1) //se nao sobrar ngm mas ainda faltarem solicitacoes, ele sobe
                contador += andar;
        }
    }

    printf("%d", contador);

    return 0;
}
