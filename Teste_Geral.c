#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAMANHO 10000
#define EXECUCOES 1000000
#define TAM_PARTICAO 100

typedef struct indice {
    int valor;
    int *p;
} Indice;


int Busca_Sequencial(int valor, int *v, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        if(v[i] == valor) return i;
    }
    return -1;
}

int Busca_Binaria_Vetor_Recursivo(int *v, int valor, int inicio_vetor, int final_vetor) {
    if(inicio_vetor > final_vetor) return -1;

    int metade = (final_vetor + inicio_vetor) / 2;
    
    if(v[metade] == valor) return metade;
    else if(v[metade] < valor) {
        return Busca_Binaria_Vetor_Recursivo(v, valor, metade + 1, final_vetor);
    } else {
        return Busca_Binaria_Vetor_Recursivo(v, valor, inicio_vetor, metade - 1);
    }
}

int Busca_Sequencial_Index(int valor, Indice *v_idx, int n_indices, int tamanho_particao) {
    int i = 0;
    while(i < n_indices && v_idx[i].valor <= valor) {
        i++;
    }

    if(i == 0) return -1; 
    return Busca_Sequencial(valor, v_idx[i-1].p, tamanho_particao);
}

int main() {
    clock_t inicio, fim;
    
    int *vetor = malloc(sizeof(int) * TAMANHO);
    for(int i = 0; i < TAMANHO; i++) {
        vetor[i] = i * 2; 
    }

    int n_indices = TAMANHO / TAM_PARTICAO;
    Indice *vetor_indexacao = malloc(sizeof(Indice) * n_indices);

    for(int i = 0, j = 0; i < TAMANHO; i += TAM_PARTICAO, j++) {
        vetor_indexacao[j].valor = vetor[i];
        vetor_indexacao[j].p = &vetor[i];
    }

    int alvo = (TAMANHO - 1) * 2; 

    printf("--- Iniciando Benchmark (%d execuções) ---\n", EXECUCOES);

    // 1. Teste Busca Sequencial
    inicio = clock();
    for(int i = 0; i < EXECUCOES; i++) {
        Busca_Sequencial(alvo, vetor, TAMANHO);
    }
    fim = clock();
    printf("Tempo Busca Sequencial:          %.4f s\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // 2. Teste Busca Indexada
    inicio = clock();
    for(int i = 0; i < EXECUCOES; i++) {
        Busca_Sequencial_Index(alvo, vetor_indexacao, n_indices, TAM_PARTICAO);
    }
    fim = clock();
    printf("Tempo Busca Sequencial Indexada: %.4f s\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // 3. Teste Busca Binária
    inicio = clock();
    for(int i = 0; i < EXECUCOES; i++) {
        Busca_Binaria_Vetor_Recursivo(vetor, alvo, 0, TAMANHO - 1);
    }
    fim = clock();
    printf("Tempo Busca Binária Recursiva:   %.4f s\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    // Limpeza
    free(vetor);
    free(vetor_indexacao);

    return 0;
}