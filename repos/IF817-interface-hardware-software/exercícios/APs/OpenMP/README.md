# Usando [OpenMP](https://www.openmp.org/resources/tutorials-articles/)
## Instalação

`sudo apt install libomp-dev`


## Compilação

`gcc -fopenmp openmpTest.c -o openmpTest`

- Incluir no início do programa a biblioteca omp.h.
`#include <omp.h>`

# Funções do OpenMP

- **omp_set_num_threads(int num_threads):** configura a quantidade de threads a serem usadas.
- **omp_get_num_procs():** retorna a quantidade de processadores disponíveis no sistema.
- **omp_get_wtime():** retorna o tempo de relógio decorrido em segundos.
- **omp_get_thread_num():** retorna o ID da thread em execução.
- **omp_get_num_threads():** retorna o número de threads em execução.
- <strong>omp_set_lock(omp_lock_t* lock), omp_unset_lock(omp_lock_t* lock), omp_test_lock(omp_lock_t* lock):</strong> usadas para manipular semáforos.
