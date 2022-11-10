// Nome: Nathalia Fernanda de Araújo Barbosa
// Login: nfab
// Data: 12/08/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float pReal;
    float pImag;
} Complexo;

/*esta função recebe a pilha como 1o parâmetro, o número complexo a empilhar como 2o parâmetro e o tamanho da pilha como 3o parâmetro. Coloca o número complexo no topo da pilha, alocando o espaço correspondente na pilha, e aumenta seu tamanho.
*/
void empilhe(Complexo **cPilha, Complexo umC, int *tPilha)
{
    Complexo **cPilhaTemp = NULL;

    (*tPilha)++;

    cPilhaTemp = (Complexo **)realloc(*cPilha, (*tPilha) * sizeof(Complexo *));

    if (cPilhaTemp == NULL)
        exit(1);

    cPilha = cPilhaTemp;

    cPilha[(*tPilha) - 1] = &umC;
}

/*esta função recebe a pilha como 1o parâmetro e o tamanho da pilha como 2o parâmetro. Remove o número complexo do topo da pilha, retornando-o como resultado da função, e desaloca o espaço correspondente na pilha, diminuindo seu tamanho;
*/
Complexo desempilhe(Complexo **cPilha, int *tPilha)
{
    Complexo retorno, **cPilhaTemp;

    retorno = *(cPilha)[(*tPilha) - 1];

    (*tPilha)--;

    cPilhaTemp = (Complexo **)realloc(*cPilha, (*tPilha) * sizeof(Complexo *));
    if (cPilhaTemp == NULL)
        exit(1);

    cPilha = cPilhaTemp;

    return retorno;
}

/*esta função recebe a pilha como
1o parâmetro e o tamanho da pilha como 2o parâmetro. Retorna o número
complexo do topo da pilha como resultado da função, sem modificar a pilha e
nem seu tamanho;*/
Complexo *topo(Complexo *cPilha, int tPilha)
{
    Complexo *retorno;
    retorno = &cPilha[tPilha - 1];

    return retorno;
}

/*esta função recebe a pilha como 1o
parâmetro e o tamanho da pilha como 2o parâmetro. Retorna o estado da pilha
(cPilha == NULL ou tPilha==0 então retorna 1. Caso contrário, retorna 0);*/
int pilhaVazia(Complexo *cPilha, int tPilha)
{
    if (cPilha == NULL || tPilha == 0)
        return 1;

    else
        return 0;
}

/*esta função recebe a pilha como 1o
parâmetro e o tamanho da pilha como 2o parâmetro. Salva a pilha (usando w)
em arquivo binário (nome pilha.bin), onde o 1o registro do arquivo será o
tamanho da pilha e o resto o conteúdo da pilha*/
void salvePilha(Complexo *cPilha, int tPilha)
{
    FILE *arquivo = NULL;
    arquivo = fopen("pilha.bin", "wb");

    if (arquivo != NULL)
    {
        fwrite(&tPilha, sizeof(int), 1, arquivo);
        fwrite(cPilha, sizeof(Complexo), tPilha, arquivo);

        fclose(arquivo);
    }

    else
        printf("Nao foi possivel abrir o arquivo.\n");
}

/*esta função recebe o tamanho da pilha
como parâmetro. Lê o conteúdo do arquivo binário pilha.bin, retornando-o
como resultado da função e atualizando o tamanho da pilha*/
Complexo *recuperePilha(int *tPilha)
{
    Complexo *cPilha = NULL;
    FILE *arquivo = NULL;
    arquivo = fopen("pilha.bin", "rb");

    if (arquivo != NULL)
    {
        fread(tPilha, sizeof(int), 1, arquivo);
        fread(cPilha, sizeof(Complexo), (*tPilha), arquivo);

        fclose(arquivo);
    }

    else
        printf("Nao foi possivel abrir o arquivo.\n");

    return cPilha;
}

int main()
{
    Complexo *cPilha = NULL, complexo, *top = NULL;
    int tPilha = 0;

    if (pilhaVazia(cPilha, tPilha))
    {
        printf("Tudo certo com a pilha inicial.\n");
        complexo.pReal = 2.5;
        complexo.pImag = 3.5;

        empilhe(&cPilha, complexo, &tPilha);

        complexo.pReal = -1.5;
        complexo.pImag = 2.0;
        empilhe(&cPilha, complexo, &tPilha);

        top = topo(cPilha, tPilha);
        if (top->pReal == -1.5 && top->pImag == 2.0)
        {
            salvePilha(cPilha, tPilha);
            desempilhe(&cPilha, &tPilha);
            desempilhe(&cPilha, &tPilha);

            recuperePilha(&tPilha);
            desempilhe(&cPilha, &tPilha);
            desempilhe(&cPilha, &tPilha);

            if (cPilha[1].pReal == -1.5 && cPilha[1].pImag == 2.0)
                printf("Conteudo condizente.\n");
            if (cPilha[0].pReal == 2.5 && cPilha[0].pImag == 3.5)
                printf("Conteudo condizente.\n");
        }

        free(cPilha);
    }
    return 0;
}
