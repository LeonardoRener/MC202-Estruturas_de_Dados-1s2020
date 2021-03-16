// Autor: Leonardo Rener de Oliveira RA: 201270

#include <stdio.h>

void peneira(int *vet, int raiz, int fundo);

void heapsort(int *vet, int n);

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf(" %d", &vetor[i]);
    }

	heapsort(vetor,n);

	printf("%d\n", vetor[k-1]);
	return(0);
}

void heapsort(int *vet, int n) {

	int temp; //usado pra fazer trocas

	for (int i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (int i = n-1; i >= 1; i--) {
		temp = vet[0];
		vet[0] = vet[i];
		vet[i] = temp;
		peneira(vet, 0, i-1);
	}
}

void peneira(int *vet, int raiz, int fundo) {

	int test, filhoMax, x;

	test = 0;
	while ((raiz*2 <= fundo) && (!test)){
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		x = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = x;
		raiz = filhoMax;
    }
	else {
      test = 1; //Para o while.
	}
  }
}
