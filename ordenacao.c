#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include "pilha.h"

//tamanho para o quickSort decidir entre ordenar pelo insertSort ou fazer a partição
#define M 200 



void selectSort(int *v, int n){
    int i, j, posMenor, aux;
    for (i = 0; i < n-1;i++){
        posMenor = i;
        for (j = i + 1; j < n;j++){
            if(v[j]<v[posMenor]){
                posMenor = j;
            }
        }
        if (i!=posMenor){
            aux = v[i];
            v[i] = v[posMenor];
            v[posMenor] = aux;
        }
    }
}

void estabilidadeSelectSort(){
    typedef struct estabilidade{
        int chave;
        int ordem;
    } TEst;

    TEst e[5],aux;
    e[0].chave = 6;
    e[0].ordem = 1;
    e[1].chave = 5;
    e[1].ordem = 1;
    e[2].chave = 3;
    e[2].ordem = 1;
    e[3].chave = 5;
    e[3].ordem = 2;
    e[4].chave = 3;
    e[4].ordem = 2;


    int i, j, posMenor, n=5;
    for (i = 0; i < n-1;i++){
        posMenor = i;
        for (j = i + 1; j < n;j++){
            if(e[j].chave < e[posMenor].chave){
                posMenor = j;
            }
        }
        if (i!=posMenor){
            aux = e[i];
            e[i]= e[posMenor];
            e[posMenor] = aux;
        }

    }
    printf("\nEstabilidade select sort\n");
    for (i=0;i<5;i++)
    printf("%d.%d\t",e[i].chave,e[i].ordem);
    printf("\n\n");
}

void selectSortParcial(int *v, int n, int p){
    int i, j, posMenor, aux;
    for (i = 0; i < p;i++){
        posMenor = i;
        for (j = i + 1; j < n;j++){
            if(v[j]<v[posMenor]){
                posMenor = j;
            }
        }
        if (i!=posMenor){
            aux = v[i];
            v[i] = v[posMenor];
            v[posMenor] = aux;
        }
    }
}

void insertSort(int *v, int n){
    int i, k, aux;
    for (i = 1; i < n;i++){
        aux = v[i];
        k = i - 1;
            while(k>=0 && aux<v[k]){
                v[k+1]=v[k];
                k--;
            }
            v[k + 1] = aux;
    }
}

/* procuro o elemento e no vetor v[n] e retorna a posicao de e ou a posicao 
que ele deve ser inserido se ele nao for encontrado*/
int buscaBinaria(int *v, int inicio, int fim, int e){
    int meio;
    
    while(inicio <=fim){
        meio = inicio+(fim-inicio) / 2;

        if (v[meio] == e)
            return meio;
        else{
            if (v[meio]<e)
                inicio = meio+1;
            else
                fim = meio-1;
        }
    }
    return inicio;
}

void insertSortBinaria(int *v, int n){
    int i, j, posicao, aux;
    for (i = 1; i < n;i++){
        aux = v[i];
        posicao = buscaBinaria(v, 0, i-1, aux);
        for (j = i; j > posicao;j--){
            v[j] = v[j-1];
        }
        v[posicao] = aux;
    }
}

void insertSortParcial(int *v, int n, int p){
int i, k, j, aux,posicao;
    for (i = 1; i < p;i++){
        aux = v[i];
        k = i - 1;
        while(k>=0 && aux<v[k]){
            v[k+1]=v[k];
            k--;
        }
        v[k + 1] = aux;    
    }
    for (i = p; i < n;i++){
        if(v[i]<v[p-1]){
            aux = v[i];
            v[i] = v[p - 1];
            posicao = buscaBinaria(v, 0, i-1, aux);
            for (j = p-1; j > posicao;j--)
                v[j] = v[j-1];
            v[posicao] = aux;
        }
    }
}

void bubbleSort(int *v, int n){
    int i, j, aux;
    for (i = 0; i < n - 1;i++){
        for (j = 1; j < n - i;j++){
            if (v[j] < v[j-1] ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}

void bubbleSort2(int *v, int n){
    int j, aux, ultimaTroca, ultimaPosicao;
    ultimaPosicao = n;
    do{
        ultimaTroca = 0;
        for (j = 1; j < ultimaPosicao;j++){
            if (v[j] < v[j-1] ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                ultimaTroca = j;
            }            
        }
        ultimaPosicao = ultimaTroca;
    } while (ultimaPosicao > 0);
}

void bubbleSortParcial(int *v, int n, int p){
int  j, aux, cont=0;
    while(cont<=p){
        for (j = n-2; j >= 0 + cont ;j--){
            if (v[j] > v[j+1] ){
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            } 
        }
        cont++;
    }
}

void shellSort(int *v, int n){
    int i, j, h=1, aux;

    //encontra o valor máximo de h
    do  h = h * 3 + 1;  while (h < n);

    do{
        h /= 3;
        for (i = h; i < n; i++){
            j = i;
            aux = v[i];
            while(v[j-h]>aux){
                v[j] = v[j - h];
                j -= h;
                if(j<h)
                    break;
            }
            v[j] = aux;
        }
    } while (h != 1);
}

void particiona (int esq, int dir, int *v){
    int i, j, aux, pivo, meio, esquerda, direita;
    meio = v[(esq + dir) / 2];
    esquerda = v[esq];
    direita = v[dir];

// escolhe o pivo e elimina a possibilidade do pivo ser o > ou < elemento do vetor
    if (esquerda<meio && meio<direita)
        pivo = meio;
    else{
        if(meio<esquerda && esquerda<direita)
            pivo = esquerda;
        else
            pivo = direita;
    }
    i = esq;
    j = dir;
    do{
        while(v[i]<pivo) i++;
        while(v[j]>pivo) j--;
        if (i<=j){
            aux = v[i];
            v[i] = v[j];       
            v[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (esq<j)
        particiona(esq, j, v);
    if (dir>i)
        particiona(i, dir, v);
}

void particionaInsert(int esq, int dir, int *v){
    int tamanho = dir - esq;
    if (tamanho<M)
        insertSort(v, tamanho);
    else{
        int i, j, aux, pivo, meio, esquerda, direita;
        meio = v[(esq + dir) / 2];
        esquerda = v[esq];
        direita = v[dir];

// escolhe o pivo e elimina a possibilidade do pivo ser o > ou < elemento do vetor
        if (esquerda<meio && meio<direita)
            pivo = meio;
        else{
            if(meio<esquerda && esquerda<direita)
                pivo = esquerda;
            else
                pivo = direita;
        }
        i = esq;
        j = dir;
        do{
            while(v[i]<pivo) i++;
            while(v[j]>pivo) j--;
            if (i<=j){
                aux = v[i];
                v[i] = v[j];       
                v[j] = aux;
                i++;
                j--;
            }
        } while (i <= j);

        if (esq<j)
            particionaInsert(esq, j, v);
        if (dir>i)
            particionaInsert(i, dir, v);
    }
}

void particionaParcial (int esq, int dir, int *v, int p){
    int i, j, aux, pivo, meio, esquerda, direita;
    meio = v[(esq + dir) / 2];
    esquerda = v[esq];
    direita = v[dir];

// escolhe o pivo e elimina a possibilidade do pivo ser o > ou < elemento do vetor
    if (esquerda<meio && meio<direita)
        pivo = meio;
    else{
        if(meio<esquerda && esquerda<direita)
            pivo = esquerda;
        else
            pivo = direita;
    }
    i = esq;
    j = dir;
    do{
        while(v[i]<pivo) i++;
        while(v[j]>pivo) j--;
        if (i<=j){
            aux = v[i];
            v[i] = v[j];       
            v[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
   
    if (esq<j && j<=p)
        particiona(esq, j, v);
    if (dir>i && i<p)
        particiona(i, dir, v);

}

void quickSort(int *v, int n){
    particiona(0, n - 1, v);
}

void quickInsertSort(int *v, int n){
    particionaInsert(0, n - 1, v); 
}

void quickSortPilha(int *v, int n){
    pilha pi = criaPilha();
    if (pi){
        TElemento e,e1,e2;
        int i, j, aux, pivo, esq, dir, meio, esquerda, direita;
        esq = 0;
        dir = n - 1;
        e.chave = v;
        e.esq = esq;
        e.dir = dir;
        push(pi, e);
        while(tamanhoPilha(pi)>0){
            pop(pi, &e);
            if (e.esq < e.dir) {
                meio = v[(e.esq + e.dir) / 2];
                esquerda = v[e.esq];
                direita = v[e.dir];
// encontra a mediana e elimina a possibilidade do pivo ser o > ou < elemento do vetor
                if (esquerda<meio && meio<direita)
                    pivo = meio;
                else{
                    if(meio<esquerda && esquerda<direita)
                        pivo = esquerda;
                    else
                        pivo = direita;
                }
                i = e.esq;
                j = e.dir;
                do{
                    while(v[i]<pivo) i++;
                    while(v[j]>pivo) j--;
                    if (i<=j){
                        aux = v[i];
                        v[i] = v[j];       
                        v[j] = aux;
                        i++;
                        j--;
                    }
                } while (i <= j);
             
                if (e.esq<j){
                    e1.chave = v;
                    e1.esq = e.esq;
                    e1.dir = j;
                    push(pi,e1);
                }
                if (e.dir>i){
                    e2.chave = v;
                    e2.esq = i;
                    e2.dir = e.dir;
                    push(pi,e2);
                }
            }
        }
    }
}

void quickSortParcial(int *v, int n, int p){
     particionaParcial(0, n - 1, v, p);
}

void intercala (int *v, unsigned esq, unsigned meio, unsigned dir){
    unsigned i, j;
    unsigned cont = 0;
    unsigned tamEsq = meio - esq + 1;
    unsigned tamDir = dir - meio;
    int *ve = (int *)malloc(sizeof(int) * tamEsq);
    int *vd = (int *)malloc(sizeof(int) * tamDir);
    if (vd && ve){
        for (i = 0; i < tamEsq;i++)
            ve[i] = v[esq + i];
        for (i = 0; i < tamDir;i++)
            vd[i] = v[meio+ 1 + i];
        i = 0;
        j = 0;
        while(i<tamEsq && j<tamDir){
            if(ve[i]<vd[j]){
                v[esq + cont] = ve[i];
                i++;
            }
            else{
                v[esq + cont] = vd[j];
                j++;
            }
            cont++;
        }
        while(i<tamEsq){
            v[esq + cont] = ve[i];
            i++;
            cont++;
        }
        while(j<tamDir){
            v[esq + cont] = vd[j];
            j++;
            cont++;
        }
    }
    free(ve);
    free(vd);
}

void divide(int *v, unsigned esq, unsigned dir){
    unsigned meio;
    if (esq==dir)
        return;
    meio = (esq + dir) / 2;
    divide(v, esq, meio);
    divide(v, meio + 1, dir);

    intercala(v, esq, meio, dir);
    return;
}

void mergeSort(int *v, unsigned int n){
    divide(v, 0, n - 1);
}
 
void constroi(int  *v, int posicao, int fim){
    int h, trocou, aux;
    trocou = 1;
    do{
        if (2*posicao+1>fim)
            trocou = 0;
        
        //encontra o maior filho
        else{
            if((2*posicao+2)>fim)
                h = 2 * posicao+1;
            else
                if(v[2*posicao+1]>v[2*posicao+2])
                    h = 2 * posicao+1;
                else
                    h = 2 * posicao + 2;

        // compara o maior filho com o pai
        if (v[posicao]<v[h]){
            aux = v[h];
            v[h] = v[posicao];
            v[posicao] = aux;
            posicao = h;
        }
        else
            trocou = 0;
        }
    } while (trocou);
}

void heapSort(int *v, int n){
    int i, aux;

    //Construir a arvore heap
    for (i = (n-1) / 2; i >= 0;i--)
        constroi(v, i, n - 1);

    //Ordenar a partir da árvore heap
    for (i = n - 1; i > 0;i--){
        aux=v[0];
        v[0] = v[i];
        v[i] = aux;
        constroi(v, 0, i - 1);
    }
 }