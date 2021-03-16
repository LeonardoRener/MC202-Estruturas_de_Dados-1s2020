// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int main()
{
    int N;
    long long int inversoes = 0;
    scanf(" %d", &N);

    // Cria o vetor com os N amigos e depois recebe os valores:
    int lista[N];

    for(int i = 0; i < N; i++){
        scanf(" %d", &lista[i]);
    }

    // Ordena o vetor e recebe a quantidade de inversoes realizadas:
    inversoes = MergeSort(lista, 0, N-1);

    // Imprime o numero de inversoes:
    printf("%lld\n", inversoes);

    return 0;
}
