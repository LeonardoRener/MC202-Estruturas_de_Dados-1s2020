// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int main()
{
    int N, K;
    scanf(" %d %d", &N, &K);

    // Cria o vetor com os N amigos e depois recebe os valores:
    int lista[N];

    for(int i = 0; i < N; i++){
        scanf(" %d", &lista[i]);
    }

    // Ordena o vetor:
    MergeSort(lista, 0, N-1);

    // Imprime o numero K:
    printf("%d\n", lista[K - 1]);

    return 0;
}
