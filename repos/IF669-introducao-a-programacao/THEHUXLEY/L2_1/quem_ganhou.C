// https://www.thehuxley.com/problem/3690

/*Quem ganhou? Essa � a pergunta que n�o quer calar. Em toda a cidade esse � o assunto mais comentado,
todo mundo quer saber o resultado final. Todos querem extrair o m�ximo de informa��o de todo lugar para
chegar na resposta. Voc�, assim como todo mundo, quer saber quem ganhou. Para isso, voc� ir� analisar o
dados da partida e as regras do jogo para dizer o resultado para todo mundo.

Regras: 
No jogo existem duas equipes de n participantes e n rodadas. 
Em cada rodada, cada um dos participantes participa de um duelo com outro da equipe advers�ria.

Um duelo consiste no seguinte: Cada um dos duelistas escolhe uma carta de uma caixa, essa carta possui
um valor num�rico qualquer. Depois de escolhida a carta, os duelistas comparam os valores e verificam
quem vence o round.
O jogador pontua para sua equipe se a quantidade de divisores do valor igual a soma dos d�gitos do
n�mero da carta for par.
Fazendo essa opera��o para os n duelos, calcula-se a pontua��o final da equipe. No entanto,

se a soma dos d�gitos da pontua��o de alguma equipe for um primo par, a equipe perde 4 pontos
se for um primo �mpar, a equipe ganha 3 pontos.
A pontua��o de uma equipe pode ser negativa.
Se a pontua��o no final de tudo for igual, � somado 1 ponto para uma das equipes.

Sabendo das regras, responda quem ganhou.

N -> N�mero de rounds

Cada uma das N linhas:
A -> Valor da carta do jogador de uma equipe
B -> Valor da carta do jogador da outra equipe

Na primeira linha:  "Quem ganhou foi aquele time."
Na segunda linha a diferen�a de pontos entre as equipes.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int round, A, B, j;
    int tempA = 0, divA = 0, tempB = 0, divB = 0;
    int pontA = 0, pontB = 0, pontAt = 0, pontBt = 0;

    scanf("%d", &round);

    for (int i = 1; i <= round; i++)
    {
        scanf("%d %d", &A, &B);

        while (A != 0)
        {
            tempA += A % 10;
            A /= 10;
        }

        while (B != 0)
        {
            tempB += B % 10;
            B /= 10;
        }

        for (j = 1; j <= tempA; j++)
            if (tempA % j == 0)
                divA++;

        if (divA % 2 == 0)
            pontA++;

        for (j = 1; j <= tempB; j++)
            if (tempB % j == 0)
                divB++;

        if (divB % 2 == 0)
            pontB++;

        tempA = 0;
        tempB = 0;
        divA = 0;
        divB = 0;
    }

    pontAt = pontA;
    pontBt = pontB;

    while (pontAt != 0)
    {
        tempA += pontAt % 10;
        pontAt /= 10;
    }

    if (tempA == 2)
        pontA -= 4;

    else if (tempA == 3 || tempA == 5 || tempA == 7)
        pontA += 3;

    while (pontBt != 0)
    {
        tempB += pontBt % 10;
        pontBt /= 10;
    }

    if (tempB == 2)
        pontB -= 4;

    else if (tempB == 3 || tempB == 5 || tempB == 7)
        pontB += 3;

    if (pontA == pontB)
        pontA++;

    printf("Quem ganhou foi aquele time.\n%d", abs(pontA - pontB));

    return 0;
}
