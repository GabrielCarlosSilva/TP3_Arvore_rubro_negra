#ifndef ARVORE_H 
#define ARVORE_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item Pessoa;

struct item{
    int idade;
    char nasc[11];
    char nome[23];
};

typedef struct rbtree{
    Pessoa info;
    struct rbtree* dir;
    struct rbtree* esq;
    int cor;
}RBTree;

RBTree* alocarArvore();
void desalocarArvore(RBTree*);
void leArvore(RBTree*);
int insercao(RBTree*, Pessoa);

RBTree* rotacionaEsquerda(RBTree*);
RBTree* rotacionaDireita(RBTree*);


void balanceamento();
void printInOrder(RBTree*);

#endif