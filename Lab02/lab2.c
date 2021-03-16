// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>

void adicionar(int *vetor_x, int *vetor_y, int tamanho, int cont, int x, int y);
void consultar(int *vetor_x, int *vetor_y, int cont, int x, int y);

int main()
{

// Variaveis usadas no programa.
    int tamanho = 5, cont = 0;
    int P, operacao, x, y;

// Cria os vetores, aloca memoria e verifica se obteve sucesso.
    int *vetor_x, *vetor_y;
    if(!(vetor_x = malloc(tamanho * sizeof(int)))){
        exit(0);
    }
    if(!(vetor_y = malloc(tamanho * sizeof(int)))){
        exit(0);
    }

// Recebe o valor "P" do teclado e realiza "P" operacoes no for.
    scanf("%d", &P);

    for(int i = 0; i < P; i++){

        scanf(" %d %d %d", &operacao, &x, &y);
// Se a entrada "operacao" for igual a 0 entra no primeiro if.
        if(!operacao){
// Se cont for igual/maior que o tamanho atual do vetor realoca o dobro de memoria.
            if(cont >= tamanho){
                tamanho = tamanho * 2;
                if(!(vetor_x = realloc(vetor_x, tamanho * sizeof(int)))){
                    exit(0);
                }
                if(!(vetor_y = realloc(vetor_y, tamanho * sizeof(int)))){
                    exit(0);
                }
            }
// Adiciona os valores nos vetores atravez da funcao "adicionar" e incrementa o cont.
            adicionar(vetor_x, vetor_y, tamanho, cont, x, y);
            cont++;

// Se a entrada nao for 0 (nesse caso sera 1) executa o else.
        }else{
// Imprime o valor correspondente apravez da funcao "consultar".
            consultar(vetor_x, vetor_y, cont, x, y);
        }
    }

    free(vetor_x);
    free(vetor_y);

    return 0;
}

//================================================================================
/*                                  Funções                                     */

// Adiciona X casos de corona virus para pacientes com idade Y.
void adicionar(int *vetor_x, int *vetor_y, int tamanho, int cont, int x, int y){

    for(int i = 0; i < tamanho; i++){

// O primeiro if verifica se o paciente ja existe, se sim aumenta o numero de casos.
        if(vetor_y[i] == y){
            vetor_x[i] = vetor_x[i] + x;
            return;
        }

// O segundo if adiciona X casos para idade Y que ainda nao avia sido adicionada.
        if(i == cont){
            vetor_x[i] = x;
            vetor_y[i] = y;
            return;
        }
    }

}

// Imprime quantos casos de corona virus existem em pacientes com a idade no intervalo.
void consultar(int *vetor_x, int *vetor_y, int cont, int x, int y){

    int casos = 0;
    for(int i = 0; i < cont; i++){
        if((vetor_y[i] >= x) && (vetor_y[i] <= y)){
            casos = casos + vetor_x[i];
        }
    }

    printf("%d\n", casos);

}
