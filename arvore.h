#ifndef ARVORE.H
#define ARVORE.H

typedef struct item Item;

struct item{
    int idade;
    char nasc[11];
    char nome[23];
};

typedef struct RBTree{
    Item info;
    struct RBTree* dir;
    struct RBTree* esq;
    int cor;
}RBTree;


RBTree* rotacionaEsquerda(RBTree*);
RBTree* rotacionaDireita(RBTree*);


RBTree alocarArvore();
void desalocarArvore(RBTree* t);
void leArvore(RBTree* t);
void insercao();
void balanceamento();
void printInOrder();

#endif;