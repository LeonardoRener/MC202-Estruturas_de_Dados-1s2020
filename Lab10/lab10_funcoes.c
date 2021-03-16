#include <stdio.h>
#include <stdlib.h>
#include "lab10_declaracoes.h"

int hashDN(int *tabela, int entrada, int N){
    int colisoes = 0;
    int h = entrada % N;

    while(1){
        if(tabela[h] == -9){
            tabela[h] = entrada;
            return colisoes;
        }

        h++;

        if(h > N-1)
            h = 0;

        colisoes++;

    }

    return colisoes;
}
