#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct item Pessoa;
typedef struct node RBTree;

struct item{
    int idade;
    char nome[23];
};

struct node{
    Pessoa info;
    struct node *pai;
    struct node *esq;
    struct node *dir;
    int cor;
};

RBTree* insersao(RBTree*, RBTree*);
void desaloca(RBTree*);
void balanceamento(RBTree**, RBTree*);
void inOrder(RBTree*);

#endif