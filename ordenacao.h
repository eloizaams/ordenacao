#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

// fixa a primeira posição e percorre o vetor, encontra o menor elemento e troca
void selectSort(int *v, int n);

//testa o metodo selectSort demonstrando que ele é instável
void estabilidadeSelectSort();

//implementa o selectSort apenas para os P primeiros elementos
void selectSortParcial(int *v, int n, int p);

//ideia das cartas de baralho
void insertSort(int *v, int n);

//implementa o insertSort apenas para os p primeiros elementos
void insertSortParcial(int *v, int n, int p);

//implementação com busca binaria na parte do vetor ja ordenada
void insertSortBinaria(int *v, int n);

//vai levando o maior elemento para o final
void bubbleSort(int *v, int n);

//considerando uma pré-ordenação do vetor
void bubbleSort2(int *v, int n);

//implementa o bubbleSort apenas para os p primeiros elementos
void bubbleSortParcial(int *v, int n, int p);

//ideia do insertShort, mas usando um "passo" maior, representado por h
void shellSort(int *v, int n);

/*Escolhe um pivô e divide o vetor em 2, de modo que a esquerda do pivô
  tenham elemento menores que ele e a direita somente elementos maiores.
  Usa função recursiva "particiona" para implementar*/
void quickSort(int *v, int n);

/*implementação do quickSort, onde caso o vetor seja menor do que M elementos
  será utilizado o algoritmo do insertSort. */
void quickInsertSort(int *v, int n);

/*Escolhe um pivô e divide o vetor em 2, de modo que a esquerda do pivô
  tenham elemento menores que ele e a direita somente elementos maiores.
  Usa pilha para implementar*/
void quickSortPilha(int *v, int n);

//implementa o quickeSort apenas para os p primeiros elementos
void quickSortParcial(int *v, int n, int p);

/*Divide o vetor ao meio até ficar com apenas 1 elemento, depois volta juntando de
dois em dois de forma ordenada.*/
void mergeSort(int *v, unsigned int n);

void heapSort(int *v, int n);

#endif // ORDENACAO_H_INCLUDED