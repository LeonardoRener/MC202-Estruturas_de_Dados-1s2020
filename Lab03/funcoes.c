#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

List* create_list(List **L_given, int n){

    List *L = *L_given;

// Cria "n" nos (clientes) na lista encadeada.
    for(int i=0;i < n; i++){
        L = new_node_end(&L,i);
    }

    List* aux = L;

// Avanca ate o ultimo elemento e liga ele ao primeiro.
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = L;
    L->ante = aux;

    return L;
}

List* new_node_end(List **L_given, int value){

    List *L;
    L = *L_given;
    List *p = L;

// Se a lista estiver vazia, cria o primeiro no e retorna.
    if(L == NULL){
        L = malloc(sizeof(List));
        L->cliente = value;
        L->prox = NULL;
        L->ante = NULL;

// Se nao for o primeiro elemento avanca ate o ultimo elemento da lista:
    }else{
        while(p->prox != NULL){
            p = p->prox;
        }
        List* aux = p;
        p->prox = malloc(sizeof(List));
        p = p->prox;

        p->cliente = value;
        p->prox = NULL;
        p->ante = aux;

    }
    return L;
}

List* delete_node(List **L_given, int cliente){

    List *L;
    List *proximo;
    List *anterior;
    L = *L_given;
    while(L->cliente != cliente){
        L = L->prox;
    }
    if(L->prox == L){
        free(L);
        L = NULL;
        return L;
    }

    proximo = L->prox;
    anterior = L->ante;

    anterior->prox = proximo;
    proximo->ante = anterior;

    free(L);

    return *L_given;
}
