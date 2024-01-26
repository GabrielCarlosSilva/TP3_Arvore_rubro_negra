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

void trocaCor(RBTree** no){
    (*no)->cor = !(*no)->cor;
    if((*no)->esq != NULL)
        (*no)->esq->cor = !(*no)->esq->cor;
    if((*no)->dir != NULL)
        (*no)->dir->cor = !(*no)->dir->cor;
}

int itemChecker(Pessoa i1, Pessoa i2){
    if(!strcmp(i1.nome, i2.nome) || i1.idade == i2.idade)
        return 1;
    return 0;
}

void transferData(Pessoa *p1, Pessoa p2){
    strcpy(p1->nome, p2.nome);
    p1->idade = p2.idade;
}

RBTree* criaNo(Pessoa insert){
    RBTree* temp = (RBTree*) malloc(sizeof(RBTree));
    transferData(&temp->info, insert);
    temp->cor = BLACK;
    temp->dir = NULL;
    temp->esq = NULL;
    return temp;
}

int balanceamento(RBTree** raiz){
    if(cor((*raiz)->dir) == RED && cor((*raiz)->dir->dir) == RED) // Dois vermelhos seguidos na direita
        *raiz = rotacionaEsquerda(*raiz);
    if(cor((*raiz)->esq) == RED && cor((*raiz)->esq->esq) == RED) // Dois vermelhos seguidos na esquerda
        *raiz = rotacionaDireita(*raiz);
    if(cor((*raiz)->esq) == RED && cor((*raiz)->dir) == RED)      // Ambos os filhos vermelhos
        trocaCor(raiz);    
}

bool insercao(RBTree** raiz, Pessoa inserido){
    if(*raiz == NULL){
        *raiz = criaNo(inserido);
        return true;
    }else if(itemChecker(inserido, (*raiz)->info)){
        return false;
    }else if(inserido.idade < (*raiz)->info.idade){
        if(insercao(&(*raiz)->esq, inserido)){
            if(balanceamento(raiz))
                return false ;
            else
                return true ;
        }
    }else if(inserido.idade > (*raiz)->info.idade){
        if(insercao(&(*raiz)->dir, inserido)){
            if(balanceamento(raiz))
                return false ;
            else
                return true ;
        }
    }
    return false;
}

void imprimePessoa(Pessoa temp){
    printf("Nome: %s\n", temp.nome);
    printf("Idade: %d\n", temp.idade);
}

void printInOrder(RBTree* raiz){
    if(raiz == NULL)
        return;
    printInOrder(raiz->esq);
    imprimePessoa(raiz->info);

    if(raiz->cor = BLACK)
        printf("PRETO\n");
    else
        printf("VERMELHO\n");


    printInOrder(raiz->dir);
}