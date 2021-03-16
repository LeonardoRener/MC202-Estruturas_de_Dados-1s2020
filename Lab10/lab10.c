// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>
#include "lab10_declaracoes.h"

int main()
{
    int N;              // Tamanho da tabela / Quantidade de elementos
    scanf(" %d", &N);

    int entrada;        // Variavel para ler os inteiros
    int colisoes = 0;   // Armazena o numero de colisoes

    int tabela[N];      // Vetor com N elemento para armazenar a tabela
    for(int i = 0; i < N; i++)
        tabela[i] = -9;

    for(int i = 0; i < N; i++){

        scanf(" %d", &entrada);
        colisoes += hashDN(tabela, entrada, N);

    }

    printf("%d\n", colisoes);


    return 0;
}
