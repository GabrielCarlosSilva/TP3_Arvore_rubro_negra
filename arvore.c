#include "arvore.h"

#define RED 1
#define BLACK 0

RBTree* alocarArvore(){
    RBTree* raiz = (RBTree*) malloc(sizeof(RBTree));
    if(raiz != NULL)
        raiz = NULL;
    return raiz;
}

void liberaNo(RBTree* no){
    if(no == NULL)
        return;
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
    no = NULL;    
}

void desalocarArvore(RBTree* raiz){ 
    if(raiz == NULL)
        return;
    liberaNo(raiz);
    free(raiz);
}

// Implementação: no = rotaciona(no)
RBTree* rotacionaEsquerda(RBTree* no){
    if(no == NULL) return NULL;
    RBTree *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    aux->cor = no->cor;
    no->cor = RED;
    return aux;
}

// Implementação: no = rotaciona(no)
RBTree* rotacionaDireita(RBTree* no){
    if(no == NULL) return NULL;
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

int itemChecker(Pessoa i1, Pessoa i2){
    if(!strcmp(i1.nome, i2.nome) || !strcmp(i1.nasc, i2.nasc) || i1.idade == i2.idade)
        return 1;
    return 0;
}

RBTree* insereNO(RBTree* raiz, Pessoa inserido, int *sucesso){
    if(raiz == NULL){
        RBTree* novo = (RBTree*) malloc(sizeof(RBTree));
        if(novo == NULL){
            *sucesso = 0;
            return NULL; 
        }
        novo->info = inserido;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *sucesso = 1;
        return novo;
    }
    if(itemChecker(inserido, raiz->info)){
        *sucesso = 0;
    } else {
        if(inserido.idade < raiz->info.idade){
            raiz->esq = insereNO(raiz->esq, inserido, sucesso);
        }else{
            raiz->dir = insereNO(raiz->dir, inserido, sucesso);
        }
    }
    if(cor(raiz->dir) == RED && cor(raiz->dir->dir) == RED) // Dois vermelhos seguidos na direita
        raiz = rotacionaEsquerda(raiz);
    if(cor(raiz->esq) == RED && cor(raiz->esq->esq) == RED) // Dois vermelhos seguidos na esquerda
        raiz = rotacionaDireita(raiz);
    if(cor(raiz->esq) == RED && cor(raiz->dir) == RED)      // Ambos os filhos vermelhos
        trocaCor(raiz);    

    return raiz;
}

int insercao(RBTree* raiz, Pessoa inserido){
    int sucesso;
    raiz = insereNO(raiz, inserido, &sucesso);
    if(raiz != NULL)
        raiz->cor = BLACK;

    return sucesso;
}


void imprimePessoa(Pessoa temp){
    printf("Nome: %s\n", temp.nome);
    printf("Data de Nascimento: %s\n", temp.nasc);
    printf("Idade: %d\n", temp.idade);
}

void printInOrder(RBTree* raiz){
    if(raiz == NULL)
        return;

    printInOrder(raiz->esq);
    imprimePessoa(raiz->info);
    printInOrder(raiz->dir);
}