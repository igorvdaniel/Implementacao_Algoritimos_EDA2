#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define EXECUCOES 1000000

typedef struct indice {
    int valor;
    int *p;
} Indice;

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
    for(i = 0;v[i] != valor; i++);

    if(i == tamanho)
    {
        return -1;
    }

    return i;
}

int Busca_Sequencial_Index(int valor, Indice *v, int tamanho_vetor, int tamanho_particao)
{
    Indice *ultimo = &v[0];
    for(int i = 1; (valor >= ultimo->valor && valor <= v[i].valor) && i < tamanho_vetor;)
    {
        if(valor >= ultimo->valor)
        {
            ultimo = &v[i];
            i++;
        }
    }

    return Busca_Sequencial(valor, ultimo->p, tamanho_particao);

}






int main()
{
    clock_t inicio, fim;
    int v[] = {
    -5, 0, 2, 3, 4, 5, 6, 7, 8, 10,
    11, 12, 13, 14, 15, 17, 19, 21, 22, 23,
    27, 29, 31, 34, 37, 39, 42, 44, 45, 49,
    50, 52, 55, 56, 62, 63, 66, 67, 71, 74,
    78, 80, 81, 84, 88, 89, 91, 95, 99
};

    int *vetor = malloc(sizeof(int)*50);
    memcpy(vetor, v, 50 * sizeof(int));
    
    Indice *vetor_indexacao = malloc(sizeof(Indice)*5);

    for(int i = 0, j = 0; i < 50; i += 10, j++)
    {
        vetor_indexacao[j].valor = vetor[i];
        vetor_indexacao[j].p = &vetor[i];
    }

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

        inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        Busca_Sequencial_Index(21, vetor_indexacao, 5, 10);
    }

    fim = clock();

    printf("Tempo busca_sequencial com index: %lf\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    free(vetor);
    free(vetor_indexacao);
    return 0;
}