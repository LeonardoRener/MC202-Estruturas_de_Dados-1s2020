// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int main(){

    int N;              //Quantidade de elementos da arvore.
    int x;              //Variavel para o dado.
    int altura[2];      //Altura da arvore.

    scanf(" %d", &N);

    for(int i = 0; i < 2; i++){

        node *tree = NULL;  //Criar arvore vazia.

        //Preenche a arvore:
        for(int j = 0; j < N; j++){
            scanf(" %d", &x);
            tree = insert(&tree, x);
        }

        altura[i] = AlturaTree(tree);  //Encontra a altura da arvore atual.
        delete_tree(&tree);             //Liberar memoria da arvore atual.
    }

    printf("%d %d\n", altura[0], altura[1]);

    return 0;
}
