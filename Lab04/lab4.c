#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "declaracoes.h"

int main()
{
    char N[23];                     // Entrada em forma de string
    int k;                          // Quantidade de digitos que sera removido.
    int ultimo = 0;                 // Variavel que guarda a ultima posicao do vetor de strings.
    int primeiro = 0;               // Variavel que guarda a primeira posicao do vetor de inteiros.
    int aux = 0;                    // Variavel auxiliar para valores temporarios.

    scanf(" %s %d", N, &k);

    while(N[aux]){
        ultimo++;                   // Encontra a ultima posicao da string de entrada (N).
        aux++;
    }

    if(ultimo <= 1){
        printf("%s", N);
        return 0;
    }

// Transforma a string "N" em um vetor de inteiros "vetor":
    int vetor[ultimo];
    transforma_char_em_int(vetor, ultimo, N);

//================================================================
// Realiza a primeira mudanca no numero, faz o vetor iniciar no menor numero retirando ate "k" elementos:

    for(int i = 0; i < k; i++){
        if(vetor[i] < vetor[primeiro]){
            primeiro = i;
        }else if(vetor[primeiro] == 0){
            primeiro = i;
        }
        if(vetor[i] == 0){
            k++;
        }
    }

    k = k - primeiro;               // Nova quantidade de numeros que podem ser retirados.

// Se "k" eh igual a 0 o vetor ja esta ordenado, o numero eh printado e retorna.
    if(k == 0){
        for(int i = primeiro; i < ultimo; i++){
            printf("%d", vetor[i]);
        }
        return 0;
    }
//================================================================
// Se "k" eh diferente de 0 a ordenacao continua:

    List* lista = NULL;
    List* lista_aux = NULL;
    lista = create_list(&lista, vetor, primeiro, ultimo);

    int tamanho = (ultimo - primeiro) - k;  // O tamanho da lista sera o numero de elementos menos os "k" digitos retirados.

//================================================================
    k = ordena(&lista, k);
//================================================================
    if(k > 0){
        tamanho = tamanho + k;
        int vetor_ordenado[tamanho];
        lista_aux = lista;

        for(int i = 0; i < tamanho; i++){
            vetor_ordenado[i] = lista_aux->valor;
            lista_aux = lista_aux->prox;
        }

        insertion(vetor_ordenado, tamanho);

        for(int i = 0; i < k; i++){
            delete_node(&lista, vetor_ordenado[i]);
        }
    }
//================================================================
    lista_aux = lista;

    aux = 0;

    while(lista_aux != NULL){
        if(!aux){
            if(lista_aux->valor == 0){
                lista_aux = lista_aux->prox;
            }else{
                printf("%d", lista_aux->valor);
                lista_aux = lista_aux->prox;
                aux++;
            }
        }else{
            printf("%d", lista_aux->valor);
            lista_aux = lista_aux->prox;
        }
    }

    if(!aux){
        printf("0");
    }

    lista = delete_list(&lista);

    return 0;
}
