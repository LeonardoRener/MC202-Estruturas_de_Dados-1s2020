// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    //Cria a matriz:
    int matriz[n][n];
    //Preenche a matriz:
    for(int a = 0; a < n; a++)
        for(int i = 0; i < n; i++){
            scanf("%d", &matriz[a][i]);
        }

    int resultado = 0, quantidade = 0;
//=========================================================================//
    // Soma os elementos da diagonal principal.
    for(int i = 0; i < n; i++){
        resultado = resultado + matriz[i][i];
    }
    printf("%d ", resultado);

    // Soma os elementos da diagonal secundaria.
    resultado = 0;
    int a = 0;
    for(int i = n-1; i >= 0; i--){
        resultado = resultado + matriz[a][i];
        a++;
    }
    printf("%d ", resultado);
//=========================================================================//
    // Soma todos os elementos das colunas e imprime a quantidade
    // de colunas com soma par.
    resultado = 0;
    quantidade = 0;
    for(int a = 0; a < n; a++){
        for(int i = 0; i < n; i++){
            resultado = resultado + matriz[i][a];
        }
        //Se o resto da divisao por 2 eh igual a 0 entao o resultado eh par:
        if(resultado % 2 == 0)
            quantidade++;
        resultado = 0;
    }
    printf("%d ", quantidade);
//=========================================================================//
    // Soma todos os elementos das linha e imprime a quantidade
    // de linhas com soma impar.
    resultado = 0;
    quantidade = 0;
    for(int a = 0; a < n; a++){
        for(int i = 0; i < n; i++){
            resultado = resultado + matriz[a][i];
        }
        //Se o resto da divisao por 2 eh diferente de 0 entao o resultado eh impar:
        if(resultado % 2 != 0)
            quantidade++;
        resultado = 0;
    }
    printf("%d", quantidade);


    return 0;
}
