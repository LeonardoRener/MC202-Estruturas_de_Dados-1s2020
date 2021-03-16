#ifndef declaracoes

struct list{

    int myvalue;
    struct list *next;

};

typedef struct list list;

int N,R;    //dados do problema.
int *keys;  //vetor com as chaves que seram usadas 3 vezes, uma para cada metodo.

void read_input();                              //le a entrada e salva os R's em um vetor (keys) para serem usados depois.
list* new_node_end(list **L_given,int value);   //cria um node no final da lista e insere um valor neste node, se a lista estiver vazia, inicia uma lista.
list* delete_list(list **L_given);              //limpa a lista, dando free em todos os elementos.
list* create_list(list **L_given,int SIZE);     //cria uma lista de tamanho SIZE, com chaves de referencia de 1 ate SIZE.
list* reset_list(list **L_given, int SIZE);     //apaga uma lista e cria uma nova para ser usada na prox fucao.
int MTF(list **L_given,int *ref_keys);          //calcula o custo do MTF.
int TR(list **L_given,int *ref_keys);           //calcula o custo do TR.
int Count(list **L_given,int *ref_keys);        //calcula o custo do C.

#endif
