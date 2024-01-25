#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define RED 1
#define BLACK 0


RBTree* rotacionaEsquerda(RBTree* no){
    if(no == NULL) return;
    RBTree *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    aux->cor = no->cor;
    no->cor = RED;
    return aux;
}

RBTree* rotacionaDireita(RBTree* no){
    if(no == NULL) return;
    RBTree *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    aux->cor = no->cor;
    no->cor = RED;
    return aux;
}

int cor(RBTree* no){
    if(no == NULL)
        return BLACK;
    return no->cor;
}

void trocaCor(RBTree* no){
    no->cor = !no->cor;
    if(no->esq != NULL)
        no->esq->cor = !no->esq->cor;
    if(no->dir != NULL)
        no->dir->cor = !no->dir->cor;
}


