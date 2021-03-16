#ifndef declaracoes

typedef struct node{

    double data;
    struct node *a;
    struct node *b;

}node;

node* insert_on_list(node **lista);
node* reverse_list(node **lista);
node* delete_list(node **lista);
void print_list(node **lista);

#endif
