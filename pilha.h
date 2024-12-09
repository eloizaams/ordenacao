#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
typedef int *TChave;
typedef struct{
   TChave chave;
   int esq;
   int dir;
}TElemento;

typedef struct TPilha *pilha;

pilha criaPilha();
void terminaPilha(pilha);
int push(pilha,TElemento);
int pop(pilha,TElemento*);
int pilhaCheia();
int pilhaVazia(pilha);
int tamanhoPilha(pilha);
#endif // PILHA_H_INCLUDED
