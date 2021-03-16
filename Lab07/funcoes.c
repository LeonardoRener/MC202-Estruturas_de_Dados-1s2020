#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

// Primeira parte do MergeSort, divide o vetor no meio:
void MergeSort(int *vetor, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio+1, fim);
        Merge(vetor, inicio, meio, fim);
    }

    return;
}

// Segunda parte, junta os vetores separados ordenando eles:
void Merge(int *vetor, int inicio, int meio, int fim){
    int i, j, k;
    int fim1 = 0, fim2 = 0;
    int p1 = inicio, p2 = meio+1;
    int tamanho = fim-inicio+1;

    // Vetor temporario:
    int *temp = (int *) malloc(tamanho*sizeof(int));
    if(!temp){
        exit(0);
    }

    for(i = 0; i < tamanho; i++){
        if(!fim1 && !fim2){
            if(vetor[p1] < vetor[p2]){
                temp[i] = vetor[p1];
                p1++;
            }

            else{
                temp[i] = vetor[p2];
                p2++;
            }

            // Verifica se o vetor acabou:
            if(p1 > meio)
                fim1 = 1;
            if(p2 > fim)
                fim2 = 1;
        }else{
            // Copia oque sobrar:
            if(!fim1)
                temp[i] = vetor[p1++];
            else
                temp[i] = vetor[p2++];
        }
    }

    // Copia do vetor temporario para o principal:
    for(j = 0, k = inicio; j < tamanho; j++, k++)
        vetor[k] = temp[j];

    free(temp);

    return;
}

