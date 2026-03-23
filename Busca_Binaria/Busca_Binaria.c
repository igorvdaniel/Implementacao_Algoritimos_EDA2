#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define EXECUCOES 1000000

int Busca_Binaria_Vetor_Recursivo(int *v, int valor, int final_vetor, int inicio_vetor)
{
    if(inicio_vetor < 0 || final_vetor == inicio_vetor)
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
        return Busca_Binaria_Vetor_Recursivo(v, valor, metade, inicio_vetor);
    }
}


int main()
{
    clock_t inicio, fim;
    int v[] = {
    -5, 0, 2, 3, 4, 5, 6, 7, 8, 10,
    11, 12, 13, 14, 15, 17, 19, 21, 
    22, 23, 27, 29, 31, 34, 37, 39, 
    42, 44, 45, 49, 50, 52, 55, 56,
    62, 63, 66, 67, 71, 74, 78, 80, 
    81, 84, 88, 89, 91, 95, 99
};
    printf("Valor existe: %d\n", Busca_Binaria_Vetor_Recursivo(v, 66, 49, 0));
    
    //for(int i = 0; i < 49; i++)
    //{
    //    if(v[i] == 66) printf("%d\n", i);
    //}

    printf("Valor não existe: %d\n", Busca_Binaria_Vetor_Recursivo(v, 113, 49, 0));

    return 0;
}