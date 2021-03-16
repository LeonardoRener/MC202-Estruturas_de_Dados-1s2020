// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int main() {

    int cost_MTF = 0,cost_TR = 0,cost_Count = 0;
    list *L = NULL;

    read_input();

    L = create_list(&L,N);

    cost_MTF = MTF(&L,keys);

    L = reset_list(&L,N);

    cost_TR = TR(&L,keys);

    L = reset_list(&L,N);

    cost_Count = Count(&L,keys);

    /*=============================================*/
    printf("%d %d %d\n",cost_MTF,cost_TR,cost_Count);
    /*=============================================*/

    L = delete_list(&L);
    free(keys);

    return 0;
}
