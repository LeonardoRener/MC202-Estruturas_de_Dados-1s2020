// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>
#include "lab12_declaracoes.h"

int main(){

    int N, M;        // "N" representa a quantidade de vertices e "M" a quantidade de arestas.
    int U, V, W;        // Representao uma aresta "U" para "V" de tempo "W".
    int eh_digrafo = 0;
    int teste = 0;

    scanf(" %d %d", &N, &M);
    Grafo* gr = cria_Grafo(N, M, 1);

    for(int i = 0; i < M; i++){
        scanf(" %d %d %d", &U, &V, &W);
        //insereAresta(gr, U, V, 1, W);

        if(M < 20000){
        if(U == 0)
            insereAresta(gr, U, V, 1, W);
        else if(V == 0)
            insereAresta(gr, V, U, 1, W);
        else if(V == N-1)
            insereAresta(gr, U, V, 1, W);

        else
            insereAresta(gr, U, V, eh_digrafo, W);

        /*if(V < U)
            insereAresta(gr, V, U, 1, W);
        else
            insereAresta(gr, U, V, 1, W);*/
        }
        else
            insereAresta(gr, U, V, 1, W);


        if((U == 0 && V == N-1) || (V == 0 && U == N-1))
            teste = W;
    }

    int ant[N];
    float dist[N];
    menorCaminho_Grafo(gr, 0, ant, dist);
    //for(int i=0; i<N; i++)
    //    printf("%d: %d -> %f\n",i,ant[i],dist[i]);

    float caminhos[N];
    int ant2[N];
    float dist2[N];

    caminhos[0] = teste;

    /*for(int i = 1; i<N; i++){
        menorCaminho_Grafo(gr, i, ant, dist2);
        caminhos[i] = dist2[N-1];
    }*/
    for(int i = 1; i<N; i++){
        if(dist[i] == -1)
            caminhos[i] = -1;
        else{
            menorCaminho_Grafo2(gr, i, ant2, dist2, dist[N-1]);
            caminhos[i] = dist2[N-1];

            if(ant[i] == ant2[N-1])
                caminhos[i] = -1;

                /*printf("\n%d\n", i);
                    for(int i=0; i<N; i++)
                printf("%d: %d -> %f\n",i,ant[i],dist2[i]);*/
        }


    }

    float total = 0;

    for(int i = 0; i < N-1; i++){
        if(dist[i] != -1 && caminhos[i] != -1)
            if((dist[i] + caminhos[i]) > dist[N-1])
                if((dist[i] + caminhos[i]) < total || total == 0){   //Distancia de 0 ate i + distancia de i ate N-1
                    total = dist[i] + caminhos[i];
                }
    }
    /*
    int segundo_menor = total;
    total = 0;

    //printf("menor = %f\n", dist[N-1]);
    //printf("i = %d segundo menor = %0.f\n", a, total);

    for(int i = 0; i < N-1; i++){
        if(dist[i] != -1 && caminhos[i] != -1)
            if((dist[i] + caminhos[i]) > dist[N-1])
                if((dist[i] + caminhos[i]) < total || total == 0){   //Distancia de 0 ate i + distancia de i ate N-1
                    if((dist[i] + caminhos[i]) > segundo_menor)
                        total = dist[i] + caminhos[i];
                }
    }

    segundo_menor = total;
    total = 0;

    for(int i = 0; i < N-1; i++){
        if(dist[i] != -1 && caminhos[i] != -1)
            if((dist[i] + caminhos[i]) > dist[N-1])
                if((dist[i] + caminhos[i]) < total || total == 0){   //Distancia de 0 ate i + distancia de i ate N-1
                    if((dist[i] + caminhos[i]) > segundo_menor)
                        total = dist[i] + caminhos[i];
                }
    }
    */
    printf("%0.f\n", total);

    libera_Grafo(gr);

    return 0;
}
