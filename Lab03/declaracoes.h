#ifndef declaracoes

typedef struct List{
    int cliente;
    struct List* prox;
    struct List* ante;
}List;

List* new_node_end(List **L_given, int value);

List* create_list(List **L_given, int n);

List* delete_node(List **L_givn, int cliente);

#endif
