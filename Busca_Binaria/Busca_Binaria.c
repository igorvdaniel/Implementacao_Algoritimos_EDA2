#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAMANHO 10000
#define EXECUCOES 1000000

int Busca_Binaria_Vetor_Recursivo(int *v, int valor, int final_vetor, int inicio_vetor)
{
    if(inicio_vetor < 0 || final_vetor < inicio_vetor)
    {
        return -1;
    }
    int metade = (final_vetor + inicio_vetor)/2;
    if(v[metade] == valor) return metade;
    else if(v[metade] < valor)
    {
        return Busca_Binaria_Vetor_Recursivo(v, valor, final_vetor, metade + 1);
    }
    else{
        return Busca_Binaria_Vetor_Recursivo(v, valor, metade - 1, inicio_vetor);
    }
}

typedef struct NO
{
    int dado;
    struct NO *pai;
    struct NO *filho_esq;
    struct NO *filho_dir;
} no;

no* Add_ABB(no *raiz, int valor)
{
    if(raiz == NULL)
    {
        no *novo = malloc(sizeof(no));  
        novo->dado = valor;
        novo->filho_esq = NULL;
        novo->filho_dir = NULL;
        return novo;
    }
    if(valor > raiz->dado)
    {
        raiz->filho_dir = Add_ABB(raiz->filho_dir, valor);
    }
    else{
        raiz->filho_esq = Add_ABB(raiz->filho_esq, valor);
    }
    return raiz;
}


no *Busca_ABB(no *raiz, int valor)
{
    if(raiz == NULL) return raiz;
    if(raiz->dado == valor) return raiz;
    else if(valor > raiz->dado) return Busca_ABB(raiz->filho_dir, valor);
    else return Busca_ABB(raiz->filho_esq, valor);
}



int main()
{
    clock_t inicio, fim;
    int *v = malloc(sizeof(int) * TAMANHO);

    no *raiz = NULL;

    for(int i = 0; i < TAMANHO; i++) {
        int valor = rand() % 100000;
        v[i] = i * 2;
        raiz = Add_ABB(raiz, valor);
    }
    int alvo = (TAMANHO - 1) * 2;

    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        Busca_Binaria_Vetor_Recursivo(v, alvo, TAMANHO - 1, 0);
    }

    fim = clock();

    printf("Tempo busca_binária_vetor_recursiva: %lf\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);



    inicio = clock();

    for(int i = 0; i < EXECUCOES; i++)
    {
        Busca_ABB(raiz, alvo);
    }

    fim = clock();

    printf("Tempo busca_binária na ABB: %lf\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    free(v);

    return 0;
}