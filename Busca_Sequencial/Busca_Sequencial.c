#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define EXECUCOES 1000000

int Busca_Sequencial(int valor, int *v, int tamanho)
{
  for(int i = 0; i < tamanho; i++)
    {
        if(v[i] == valor)
        {
            return i;
        }
    }

    return -1;

}

int Busca_Sequencial_c_Sentinela(int valor, int *v, int tamanho)
{
    v[tamanho] = valor;
    int i;
    for(i = 0; i < tamanho && v[i] != valor; i++);

    if(i == tamanho)
    {
        return -1;
    }

    return i;
}




int main()
{
    clock_t inicio, fim;
    int v[] = {
    23, 5, 89, 12, 45, 67, 2, 91, 34, 78,
    11, 56, 3, 80, 29, 44, 7, 62, 19, 99,
    0, -5, 14, 37, 52, 81, 10, 22, 63, 4,
    71, 15, 88, 31, 49, 6, 95, 27, 50, 13,
    84, 17, 39, 66, 8, 55, 21, 74, 42
};

    int *vetor = malloc(sizeof(int)*50);
    memcpy(vetor, v, 50 * sizeof(int));

    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        Busca_Sequencial(21, vetor, 50);
    }

    fim = clock();

    printf("Tempo busca_sequencial: %lf\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    
    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        Busca_Sequencial(21, vetor, 50);
    }

    fim = clock();

    printf("Tempo busca_sequencial com sentinela: %lf\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    free(vetor);
    return 0;
}