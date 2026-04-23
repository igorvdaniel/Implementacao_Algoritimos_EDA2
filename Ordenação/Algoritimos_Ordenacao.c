#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define EXECUCOES 1000000

void selection_sort(int *v, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        int menor = v[i];
        int indice = i;
        for(int j = i + 1; j < tamanho; j++)
        {
            if(v[j] < menor)
            {
               menor = v[j];
               indice = j;
            } 
        }
        v[indice] = v[i];
        v[i] = menor;
    }
}

void insertion_sort(int *v, int tamanho)
{
    int aux;
    for(int i = 1; i < tamanho; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(v[j] < v[j - 1])
            {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
            else j = -1;
        }
    }
}

void bubble_sort(int *v, int tamanho)
{
    int flag = 1;
    int aux;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i < tamanho - 1; i++)
        {
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i+1] = aux;
                flag = 1;
            }
        }

    }
}

void shell_sort(int *v, int tamanho)
{
    for(int gap = tamanho/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < tamanho; i ++)
        {
            int temp = v[i];
            int j;

            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) 
            {
                v[j] = v[j - gap];
            }

            v[j] = temp;
        }
    }
}

int main()
{
    clock_t inicio, fim;
    int v[] = {
        84, 15, 34, 0, 71, 95, 23, 6, 44, 11, 
        55, -5, 63, 29, 81, 14, 50, 39, 4, 91, 
        21, 66, 8, 45, 17, 31, 74, 52, 13, 89, 
        27, 5, 88, 49, 10, 78, 12, 19, 67, 2, 
        99, 42, 37, 56, 80, 22, 62, 7, 3
    };
    
    int n = sizeof(v) / sizeof(v[0]); 
    int *vetor = malloc(sizeof(int) * n);

    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        memcpy(vetor, v, n * sizeof(int));
        selection_sort(vetor, n);
    }

    fim = clock();

    printf("Tempo total para %d execucoes: %lf segundos\n", EXECUCOES, ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    printf("Vetor ordenado pelo selection sort: ");
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");

    printf("\n");

    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        memcpy(vetor, v, n * sizeof(int));
        insertion_sort(vetor, n);
    }

    fim = clock();

    printf("Tempo total para %d execucoes: %lf segundos\n", EXECUCOES, ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    printf("Vetor ordenado pelo insertion sort: ");
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");

    printf("\n");

    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        memcpy(vetor, v, n * sizeof(int));
        bubble_sort(vetor, n);
    }

    fim = clock();

    printf("Tempo total para %d execucoes: %lf segundos\n", EXECUCOES, ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    printf("Vetor ordenado pelo bubble sort: ");
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");

    printf("\n");

    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        memcpy(vetor, v, n * sizeof(int));
        shell_sort(vetor, n);
    }

    fim = clock();

    printf("Tempo total para %d execucoes: %lf segundos\n", EXECUCOES, ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    printf("Vetor ordenado pelo shell sort: ");
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");

    free(vetor);
    return 0;
}