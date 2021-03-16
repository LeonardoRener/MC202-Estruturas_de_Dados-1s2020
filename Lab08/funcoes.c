#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int list_size = 0;

/*=================================================================*/

node* insert_on_list(node **lista){

    node *L = *lista;
    node *curr_node;
    node *prev_node;
    node *aux;
    int pos;
    double value;

    scanf(" %d %lf",&pos,&value);

    if(pos>list_size)
        pos = list_size;

    if(pos == 0){

        aux = malloc(sizeof(node));
        aux->data = value;
        aux->b = L->b;
        aux->a = L;
        if((L->b)->a == L){
            (L->b)->a = aux;
        }else if((L->b)->b == L){
            (L->b)->b = aux;
        }
        L->b = aux;
        list_size++;
    }else{
        curr_node = L->b;
        prev_node = L;

        for(int i = 0;i < pos-1;i++){
            if(curr_node->b != prev_node){
                prev_node = curr_node;
                curr_node = curr_node->b;
            }else if(curr_node->a != prev_node){
                prev_node = curr_node;
                curr_node = curr_node->a;
            }
        }

        aux = malloc(sizeof(node));
        aux->data = value;
        list_size++;

        if(curr_node->b != prev_node){
            aux->b = curr_node->b;
            aux->a = curr_node;

            if((curr_node->b)->b == curr_node){
                (curr_node->b)->b = aux;
            }else if((curr_node->b)->a == curr_node){
                (curr_node->b)->a = aux;
            }

            curr_node->b = aux;

        }else if(curr_node->a != prev_node){
            aux->b = curr_node->a;
            aux->a = curr_node;

            if((curr_node->a)->b == curr_node){
                (curr_node->a)->b = aux;
            }else if((curr_node->a)->a == curr_node){
                (curr_node->a)->a = aux;
            }

            curr_node->a = aux;
        }

    }

    return L;
}

/*=================================================================*/

node* reverse_list(node **lista){

    node *L = *lista;
    node *prev_node_start = L;
    node *curr_node_start = L->b;
    node *prev_node_end = L;
    node *curr_node_end = L->b;
    node* aux = NULL;
    int start,end;

    scanf(" %d %d",&start,&end);

    if(start == end || list_size == 0)
        return L;

    for(int i = 0;i<start;i++){

        if(curr_node_start->b != prev_node_start){
            prev_node_start = curr_node_start;
            curr_node_start = curr_node_start->b;
        }else if(curr_node_start->a != prev_node_start){
            prev_node_start = curr_node_start;
            curr_node_start = curr_node_start->a;
        }
    }

    for(int i = 0;i<end;i++){

        if(curr_node_end->b != prev_node_end){
            prev_node_end = curr_node_end;
            curr_node_end = curr_node_end->b;
        }else if(curr_node_end->a != prev_node_end){
            prev_node_end = curr_node_end;
            curr_node_end = curr_node_end->a;
        }
    }

    if(prev_node_start->b == curr_node_start){
        prev_node_start->b = curr_node_end;
    }else if(prev_node_start->a == curr_node_start){
        prev_node_start->a = curr_node_end;
    }

    if(curr_node_end->b != prev_node_end){
        aux = curr_node_end->b;
        curr_node_end->b = prev_node_start;
    }else if(curr_node_end->a != prev_node_end){
        aux = curr_node_end->a;
        curr_node_end->a = prev_node_start;
    }

    if(curr_node_start->a == prev_node_start){
        curr_node_start->a = aux;
    }else if(curr_node_start->b == prev_node_start){
        curr_node_start->b = aux;
    }

    if(aux->a == curr_node_end){
        aux->a = curr_node_start;
    }else if(aux->b == curr_node_end){
        aux->b = curr_node_start;
    }

    return L;
}

/*=================================================================*/

node* delete_list(node **lista){

    node *L = *lista;
    node *freed_node = L;
    node *prev_node = L->b;
    node *curr_node = NULL;

    if(list_size == 0){
        free(freed_node);
        free(prev_node);
        return L;
    }

    if(prev_node->a != freed_node){
        curr_node = prev_node->a;
    }else if(prev_node->b != freed_node){
        curr_node = prev_node->b;
    }


    for(int i = 0; i < list_size-1; i++){
        free(freed_node);

        freed_node = prev_node;

        if(curr_node->a != prev_node){
            prev_node = curr_node;
            curr_node = curr_node->a;
        }else if(curr_node->b != prev_node){
            prev_node =  curr_node;
            curr_node = curr_node->b;
        }
    }

    free(freed_node);
    free(prev_node);
    free(curr_node);

    return L;

}

/*=================================================================*/

void print_list(node **lista){

    if(list_size > 0){

        node *L = *lista;
        node *prev_node = L;
        node *curr_node = L->b;

        for(int i = 0; i < list_size ; i++){

            printf("%.4f ",curr_node->data);

            if(curr_node->b != prev_node){
                prev_node = curr_node;
                curr_node = curr_node->b;
            }else if(curr_node->a != prev_node){
                prev_node = curr_node;
                curr_node = curr_node->a;
            }
        }

    }

    printf("\n");

}
