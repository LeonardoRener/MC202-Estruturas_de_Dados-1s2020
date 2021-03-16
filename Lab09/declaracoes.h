#ifndef declaracoes

typedef struct node{

    int data;
    struct node *left;
    struct node *right;

}node;

typedef struct queue{
    node *entry;
    struct queue *next;
}queue;

node* insert(node** R_given, int x);
int AlturaTree(node *R);
void delete_tree(node **R_given);

#endif
