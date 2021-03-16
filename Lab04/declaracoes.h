#ifndef declaracoes

typedef struct List{
    int valor;
    struct List* prox;
}List;

void transforma_char_em_int(int* vetor, int tamanho, char* texto);

List* new_node_end(List **L_given, int valor);

List* create_list(List **L_given, int vetor[], int primeiro, int ultimo);

void delete_node(List **L_givn, int elemento);

List* delete_list(List **L_given);

int ordena(List **L_given, int k);

void insertion(int array[], int tamanho);


#endif

