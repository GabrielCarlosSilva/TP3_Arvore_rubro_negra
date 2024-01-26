#ifndef ARVORE_H 
#define ARVORE_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct item Pessoa;

struct item{
    int idade;
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
bool insercao(RBTree**, Pessoa);

RBTree* rotacionaEsquerda(RBTree*);
RBTree* rotacionaDireita(RBTree*);


int balanceamento(RBTree**);
void printInOrder(RBTree*);

#endif