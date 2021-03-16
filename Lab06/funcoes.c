#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

void read_input(){

    scanf("%d %d ",&N,&R);

    keys = malloc(R*sizeof(int));

    for(int i=0;i<R;i++){
        scanf(" %d",&keys[i]);
    }
}

list* new_node_end(list **L_given,int value){

    list *L;
    L = *L_given;
    list *p = L;

    if(L == NULL){
        L = malloc(sizeof(list));
        L->myvalue = value;
        L->next = NULL;

    }else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = malloc(sizeof(list));
        p = p->next;
        p->myvalue = value;
        p->next = NULL;

    }
    return L;
}

list* create_list(list **L_given,int SIZE){

    list *L = *L_given;

    for(int i=0;i<SIZE;i++){
        L = new_node_end(&L,i+1);
    }
    return L;
}

int MTF(list **L_given,int *ref_keys){

    list *L = *L_given;
    list *p;
    list *aux;
    int cost=0;

    if(L == NULL)
        return 0;

    for(int i = 0;i<R;i++){

        p = L;

        if(L->myvalue == ref_keys[i]){
            cost++;

        }else{
            cost++;
            while(p->next->myvalue != ref_keys[i]){
                p = p->next;
                cost++;
            }
            cost++;
            aux = p->next;
            p->next = aux->next;
            aux->next = L;
            L = aux;
        }
    }
    return cost;
}

int TR(list **L_given,int *ref_keys){

    list *L = *L_given;
    list *p = L;
    list *q = p;
    list *aux;
    int cost=0;

    if(L == NULL)
        return 0;

    for(int i = 0;i<R;i++){

        p = L;
        q = p;

        if(L->myvalue == ref_keys[i]){
            cost++;

        }else{
            cost++;
            while(p->next->myvalue != ref_keys[i]){
                q = p;
                p = p->next;
                cost++;
            }

            cost++;
            aux = p->next;
            p->next = aux->next;
            aux->next = p;
            if(q != p)
                q->next = aux;
            else
                L = aux;

        }
    }
    return cost;
}

int Count(list **L_given,int *ref_keys){

    list *L = *L_given;
    list *p = L;
    list *q = p;
    list *aux;
    int *counter;
    int cost = 0;
    int swap;

    if(L == NULL)
        return 0;

    counter = calloc(N,sizeof(int));

    for(int i = 0;i<R;i++){

        p = L;

        if(L->myvalue == ref_keys[i]){
            cost++;
            counter[0]++;

        }else{
            cost++;
            int j = 1;
            while(p->next->myvalue != ref_keys[i]){
                p = p->next;
                cost++;
                j++;
            }
            cost++;
            counter[j]++;


            int k = j-1;
            while(counter[j]>=counter[k] && k>=0){
                swap = counter[j];
                counter[j] = counter[k];
                counter[k] = swap;

                k--;
                j--;
            }

            q = L;
            while(j>1){
                q = q->next;
                j--;
            }

            aux = p->next;
            p->next = aux->next;


            if(q != L || j == 1){
                aux->next = q->next;
                q->next = aux;
            }else{
                aux->next = L;
                L = aux;
            }

        }
    }
    free(counter);

    return cost;
}

list* delete_list(list **L_given){

    list *L = *L_given;
    list *aux;

    if(L != NULL){
        while(L->next != NULL){

            aux = L->next;
            free(L);
            L = aux;

        }
        free(L);
    }
    L = NULL;
    return L;
}

list* reset_list(list **L_given, int SIZE){

    list *L = *L_given;

    L = delete_list(&L);
    L = create_list(&L,SIZE);

    return L;
}
