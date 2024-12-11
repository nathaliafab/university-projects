// https://www.thehuxley.com/problem/3343

#include <stdio.h>

int main()
{
  int j, seqAtual, seqMaior, comecoAtual, comecoMaior;
  int casos, tam;
  int vetor[500];

  scanf("%d", &casos);

  for (int i = 0; i < casos; i++)
  {
    scanf("%d", &tam);
    seqAtual = 0;
    seqMaior = 0;
    comecoAtual = 0;
    comecoMaior = 0;

    for (j = 0; j < tam; j++)
      scanf("%d", &vetor[j]);

    for (j = 0; j < tam - 1; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        seqAtual++;

        if (seqAtual == 1)
          comecoAtual = j;

        if (seqAtual + 1 > seqMaior)
        {
          seqMaior = seqAtual + 1;
          comecoMaior = comecoAtual;
        }
      }

      else
        seqAtual = 0;
    }

    printf("%d\n", seqMaior);

    if (seqMaior > 0)
    {
      for (j = comecoMaior; j < seqMaior + comecoMaior; j++)
        printf("%d ", vetor[j]);
    }

    printf("\n");
  }

  return 0;
}
