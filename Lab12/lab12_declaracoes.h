
typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist);
void menorCaminho_Grafo2(Grafo *gr, int ini, int *ant, float *dist, int minimo);
