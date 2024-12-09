#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#define N 20 // tamanho do vetor
#define P 8 // tamanho da ordenaçao parcial
int main(){
int i, *vet;
time_t inicio, fim;
vet=(int*)malloc(sizeof(int)*N);
srand(1);
for(i=0;i<N;i++)
    vet[i] = rand()%100;
inicio = time (NULL);

insertSortParcial(vet,N,P);

printf("\nElementos ordenados 8 primeiros\n");
for (i=0;i<N;i++)
    printf("%d. %d\n",i+1, vet[i]);
fim = time (NULL);
printf("\nTempo parcial ins = %f\n", difftime(fim,inicio));

//estabilidadeSelectSort();
free(vet);
return 0;
}