/*  programa em C usando OpenMP para calcular em série e paralelo a
    multiplicação de matrizes de ordem N (definida no código)
    e a quantidade de valores pares que existem na matriz resultado.
    Printando no programa quanto tempo durou e a quantidade de números pares de cada execução.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 6

void printMatrix(int matrix[N][N], char * nome) {
    printf("\nMatriz %s:\n", nome);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void preencheMatriz(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main(void) {
        void printMatrix(int matrix[N][N], char * nome);
        void preencheMatriz(int matrix[N][N]);

        int tid;
        int matrixA[N][N];
        int matrixB[N][N];
        int res[N][N];
        int i, j, contaPar = 0;
        double time = omp_get_wtime(), total_time;

        // preenchendo a matrizes com valores "aleatórios"
        preencheMatriz(matrixA);
        preencheMatriz(matrixB);

        // printando as matrizes
        printMatrix(matrixA, "A");
        printMatrix(matrixB, "B");

        // calculando a multiplicação de matrizes em série
        printf("\n-------------- Calculando a multiplicação de matrizes em série\n\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                tid = omp_get_thread_num();
                res[i][j] = matrixA[i][j] * matrixB[i][j];
                total_time = omp_get_wtime() - time;
                printf("Thread %d calculou o valor res[%d][%d]=%d\n==> Tempo: %lf\n", tid, i, j, res[i][j], total_time);
            }
        }

        printf("\nTempo de execução total: %lf\n", total_time);

        tid = 0;
        time = total_time + time;

        // calculando a multiplicação de matrizes em paralelo
        printf("\n-------------- Calculando a multiplicação de matrizes em paralelo\n\n");
        #pragma omp parallel for private(j, tid)
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                tid = omp_get_thread_num();
                res[i][j] = matrixA[i][j] * matrixB[i][j];
                total_time = omp_get_wtime() - time;
                printf("Thread %d calculou o valor res[%d][%d]=%d\n==> Tempo: %lf\n", tid, i, j, res[i][j], total_time);
            }
        }

        printf("\nTempo de execução total: %lf\n", total_time);

        // printando a quantidade de números pares na matriz resultado
        #pragma omp parallel private(i, tid)
        {
            #pragma omp sections reduction(+: contaPar)
            {
                #pragma omp section
                {
                    for (i = 0; i < N / 2; i++)
                        for (j = 0; j < N; j++)
                            if (res[i][j] % 2 == 0)
                                contaPar++;
                }

                #pragma omp section
                {
                    for (i = N / 2; i < N; i++)
                        for (j = 0; j < N; j++)
                            if (res[i][j] % 2 == 0)
                                contaPar++;
                }
            }
        }

        printf("\nQuantidade de pares = %d\n", contaPar);

        return 0;
}