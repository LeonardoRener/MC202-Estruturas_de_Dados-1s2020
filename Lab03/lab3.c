// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>
#include "declaracoes.h"

int main()
{
    int N, C, k, l;
    scanf("%d %d %d %d", &N, &C, &k, &l);

// Cria a lista duplamente encadeada com N cliente:
    List* lista = NULL;
    lista = create_list(&lista, N);

// Coloca o inicio da lista como o cliente "C":
    for(int i = 0; i < C; i++){
        lista = lista->prox;
    }

//======================================================================
    List* atendente1 = lista;       // Atendente 1, frequencia k.
    List* atendente2 = lista;       // Atendente 1, frequencia l.
    int excluir;                    // Cliente que sera excluido.

    while(lista != NULL){           // Continua ate a lista ficar vazia.
        for(int i = 0; i < k; i++){ // Avanca "k" posicoes na fila.
            atendente1 = atendente1->prox;
        }
        for(int i = 0; i < l; i++){ // Avanca "l" posicoes na fila.
            atendente2 = atendente2->ante;
        }

        printf("%d %d\n", atendente1->cliente, atendente2->cliente);

// Se os atendentes atendem o mesmo cliente, somente um no eh excluido:
        if((atendente1->cliente) == (atendente2->cliente)){
            excluir = atendente1->cliente;  // Guarda o cliente a ser excluido.
            atendente1 = atendente1->ante;  // Volta para o cliente anterior.
            atendente2 = atendente2->prox;  // Volta para o cliente anterior.
            lista = delete_node(&lista, excluir);   // Exclui o no.

// Caso sejam clientes diferentes dois seram excluidos:
        }else{
            // Exclui o cliente atendido pelo primeiro atendente:
            excluir = atendente1->cliente;  // Guarda o cliente a ser excluido.
            atendente1 = atendente1->ante;  // Volta para o cliente anterior.
            lista = delete_node(&lista, excluir);   // Exclui o no.

            // Exclui o cliente atendido pelo segundo atendente:
            excluir = atendente2->cliente;  // Guarda o cliente a ser excluido.
            atendente2 = atendente2->prox;  // Volta para o cliente anterior.
            lista = delete_node(&lista, excluir);   // Exclui o no.
        }
    }

    return 0;
}
