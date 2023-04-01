#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void) {
    int A[3][3] = {{5, 0, 1}, {-2, 3, 4}, {0, 2, -1}};
    int sarrus[3][5] = {{5, 0, 1, 5, 0}, {-2, 3, 4, -2, 3}, {0, 2, -1, 0, 2}};
    int i, j, det = 0;
    int tid;
    
    omp_set_num_threads(2);

    /*CÓDIGO PARALELO*/
    #pragma omp parallel private (j, tid)
    {
       #pragma omp for
        for (j = 0; j < 3; j++) {
            det += sarrus[0][j] * sarrus[1][j+1] * sarrus[2][j+2];
            tid = omp_get_thread_num();
            printf("THREAD %d | DET. PARCIAL = %d\n", tid, det);
        }

        #pragma omp for
        for (j = 0; j < 3; j++) {
            det -= sarrus[2][j] * sarrus[1][j+1] * sarrus[0][j+2];
            tid = omp_get_thread_num();
            printf("THREAD %d | DET. PARCIAL = %d\n", tid, det);
        }
    }

    /*CÓDIGO SEQUENCIAL*/
    printf("\nMatriz A:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
                printf(" %d ", A[i][j]);
        }
        printf("\n");
    }

    printf("O determinante da matriz A é %d\n", det);

    return 0;
}