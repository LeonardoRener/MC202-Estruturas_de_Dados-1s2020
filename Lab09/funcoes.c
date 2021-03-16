#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "declaracoes.h"

//===========================================================//
// Insere os dados na arvore:
node* insert(node** R_given, int x){

    node *R = *R_given;                 //R == tree.

    node* z = malloc(sizeof(node));     //Cria o novo no.

    if(!z){                             //Verifica se foi possivel alocar memoria.
        exit(0);
    }

    z->right = z->left = NULL;
    z->data = x;

    node* u = R;
    node* p = NULL;


    while(u){                           //Descobre a possicao para o no.

        p = u;

        if (x < u->data)
            u = u->left;
        else
            u = u->right;
    }

    if (p == NULL){                     //Se p == NULL a arvore estava vazia.
        R = z;
    }else {

        if (x < p->data){
            p->left = z;
        }else{
            p->right = z;
        }
    }

    return R;
}

//===========================================================//
//
int AlturaTree(node *R){

    // Testa se esta vazio
    if(R == NULL)
        return 0;

    int alt_esq = AlturaTree(((R)->left));
    int alt_dir = AlturaTree(((R)->right));

    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);

}

//===========================================================//
// Deleta a arvore:
void delete_tree(node **R_given){
    node *R = *R_given;

    //Caso a lista ja esteja vazia:
    if(!R)
        return;

    //Deleta tudo recursivamente:
    if(R->left != NULL)
        delete_tree(&(R->left));

    if(R->right != NULL)
        delete_tree(&(R->right));

    free(R);

}
