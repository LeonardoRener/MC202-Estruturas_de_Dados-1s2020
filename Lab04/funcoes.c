#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

void transforma_char_em_int(int* vetor, int tamanho, char* texto){

    int aux;
    char temp[2];
    for(int i = 0; i < tamanho; i++){
        temp[0] = texto[i];
        aux = atoi(temp);
        vetor[i] = aux;
    }

    return;
}

List* create_list(List **L_given, int vetor[23], int primeiro, int ultimo){

    List *L = *L_given;

// Cria "n" nos (clientes) na lista encadeada.
    for(int i = primeiro; i < ultimo; i++){
        L = new_node_end(&L, vetor[i]);
    }

    return L;
}

List* new_node_end(List **L_given, int valor){

    List *L;
    L = *L_given;
    List *p = L;

// Se a lista estiver vazia, cria o primeiro no e retorna.
    if(L == NULL){
        L = malloc(sizeof(List));
        L->valor = valor;
        L->prox = NULL;

// Se nao for o primeiro elemento avanca ate o ultimo elemento da lista:
    }else{
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = malloc(sizeof(List));
        p = p->prox;

        p->valor = valor;
        p->prox = NULL;
    }

    return L;
}

void delete_node(List **L_given, int elemento){

    List *L;
    List *aux;
    L = *L_given;
    aux = *L_given;
    while(L->valor != elemento){
        aux = L;
        L = L->prox;
    }
    if(L == aux){

        *L_given = L->prox;
        free(L);

    }else{

    aux->prox = L->prox;
    free(L);
    }

    return;
}

List* delete_list(List **L_given){

    List *L = *L_given;
    List *aux;

    if(L != NULL){
        while(L->prox != NULL){

            aux = L->prox;
            free(L);
            L = aux;

        }
        free(L);
    }
    L = NULL;
    return L;
}

int ordena(List **L_given, int k){

    List *L = *L_given;
    int cont = 0;

    while(k > 0){
        while(L->prox != NULL && k > 0){
            if(L->valor > L->prox->valor){
                delete_node(&*L_given, L->valor);
                k--;
                cont++;
                break;
        }else{
            L = L->prox;
            }
        }
        if(cont == 0){
            return k;
        }
        cont = 0;
        L = *L_given;
    }

    return k;
}

void insertion(int array[], int tamanho){

      int i, j, aux;
      for (i = 1; i < tamanho; i++){
            j = i;
            while (j > 0 && array[j - 1] < array[j]){
                  aux = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = aux;
                  j--;
            }
      }
}
