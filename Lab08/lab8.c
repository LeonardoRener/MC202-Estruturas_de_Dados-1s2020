#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int main(){

    node *list;
    list = malloc(sizeof(node));
    list->a = NULL;
    list->b = malloc(sizeof(node));
    (list->b)->a = list;
    (list->b)->b = NULL;

    char input;

    do{

        scanf(" %c", &input);

        if(input == 'i'){       //Include in List
            list = insert_on_list(&list);

        }else if(input == 'v'){ //Reverse List
            list = reverse_list(&list);

        }else if(input == 'p'){ //Print List
            print_list(&list);
        }

    }while(input != 't');

    list = delete_list(&list);  //Release memory

    return 0;
}
