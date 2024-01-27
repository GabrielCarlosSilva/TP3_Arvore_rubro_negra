#include "arvore.h"

//  Constantes que definem as cores do node
#define RED 1
#define BLACK 0

void desaloca(RBTree* node){
    if(node == NULL)
        return;
    desaloca(node->dir);
    desaloca(node->esq);
    free(node);
}


// Inserção na árvore binaria
RBTree* insersao(RBTree* X, RBTree* inserido){
    // Se a árvore é vazia retorna o novo node
    if(X == NULL)
        return inserido;

    // Caso contrário percorre a árvore
    if(inserido->info.idade < X->info.idade){
        X->esq = insersao(X->esq, inserido);
        X->esq->pai = X;
    } else if(inserido->info.idade > X->info.idade){
        X->dir = insersao(X->dir, inserido);
        X->dir->pai = X;
    }

    // Retorna o ponteiro sem alterações
    return X;
}

// Rotação a esquerda
void rotacionaEsquerda(RBTree* X, RBTree** raiz){
    RBTree* Y = X->dir;         // Cria ponteiro de node para a direita de X
    X->dir = Y->esq;            // Sub-Arvore a esquerda de Y passa para direita de X
    if(X->dir != NULL)          // Caso a direita de X não seja um nó folha (NULL) corrige o parentesco
        X->dir->pai = X;
    Y->pai = X->pai;            // Corrige o parentesco de Y
    if(X->pai == NULL)          // Se X for a raiz, atualiza o sentinela
        *raiz = Y;               
    else if(X == X->pai->esq)   // Corrige o ponteiro do pai caso X esteja a esquerda do pai
        X->pai->esq = Y;
    else                        // Corrige o ponteiro do pai caso X esteja a direita do pai
        X->pai->dir = Y;
    Y->esq = X;                 // Coloca X "abaixo" de Y
    X->pai = Y;                 // Corrige o parentesco
}

// Rotação a direita
void rotacionaDireita(RBTree* X, RBTree** raiz){
    RBTree* Y = X->esq;         // Cria ponteiro de node para a esquerda de X
    X->esq = Y->dir;            // Sub-Arvore a direita de Y passa para esquerda de X
    if(X->esq)                  // Caso a esquerda de X não seja um nó folha (NULL) corrige o parentesco
        X->esq->pai = X;
    Y->pai = X->pai;            // Corrige o parentesco de Y
    if(!X->pai)                 // Se X for a raiz, atualiza o sentinela
        *raiz = Y;
    else if(X == X->pai->esq)   // Corrige o ponteiro do pai caso X esteja a esquerda do pai
        X->pai->esq = Y;
    else
        X->pai->dir = Y;        // Corrige o ponteiro do pai caso X esteja a direita do pai
    Y->dir = X;                 // Coloca X "abaixo" de Y
    X->pai = Y;                 // Corrige o parentesco
}

// Balanceamento
void balanceamento(RBTree** raiz, RBTree* X){
    RBTree* pai_de_X = NULL;
    RBTree* avo_de_X = NULL;

    while ((X != *raiz) && (X->cor != BLACK) && (X->pai->cor == RED)){
        pai_de_X = X->pai;
        avo_de_X = X->pai->pai;

        if(pai_de_X == avo_de_X->esq){  // CASO 1: pai de X está a esquerda do avó de X
            RBTree* tio_de_X = avo_de_X->dir;
                                        // CASO 1.1: o tio é vermelho (apenas troca a cor)
            if((tio_de_X != NULL && tio_de_X->cor == RED)){
                avo_de_X->cor = RED;
                pai_de_X->cor = BLACK;
                tio_de_X->cor = BLACK;
                X = avo_de_X;
            } else { 
                if(X == pai_de_X->dir){ // CASO 1.2: X é o filho a direita (rotação a esquerda necessária)
                    rotacionaEsquerda(pai_de_X, raiz);
                    X = pai_de_X;
                    pai_de_X = X->pai;
                }
                                        // CASO 1.3: X é o filho a esquerda (Rotação a direita necessária)
                rotacionaDireita(avo_de_X, raiz);
                int temp = pai_de_X->cor;
                pai_de_X->cor = avo_de_X->cor;
                avo_de_X->cor = temp;
                X = pai_de_X;
            }        
        }else{                          // CASO 2: pai de X está a direita do avó de X
            RBTree* tio_de_X = avo_de_X->esq;
                                        // CASO 2.1: o tio é vermelho (apenas troca a cor)
            if((tio_de_X != NULL && tio_de_X->cor == RED)){
                avo_de_X->cor = RED;
                pai_de_X->cor = BLACK;
                tio_de_X->cor = BLACK;
                X = avo_de_X;  
            } else {
                if(X == pai_de_X->esq){ // CASO 2.2: X é o filho a esquerda (rotação a direita necessária)
                    rotacionaDireita(pai_de_X, raiz);
                    X = pai_de_X;
                    pai_de_X = X->pai;
                }
                                        // CASO 2.3: X é o filho a direita (rotação a esquerda necessária)
                rotacionaEsquerda(avo_de_X, raiz);
                int temp = pai_de_X->cor;
                pai_de_X->cor = avo_de_X->cor;
                avo_de_X->cor = temp;
                X = pai_de_X;   
            } 
        }
    }
    (*raiz)->cor = BLACK;
}

// Imprime o tipo pessoa segundo os parametros
void imprimePessoa(Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
}

//  Função que imprime em ordem
void inOrder(RBTree* X){
    if(X == NULL)
        return;
    inOrder(X->esq);
    imprimePessoa((*X).info);
    inOrder(X->dir);
}


Pessoa getPessoa(){
    Pessoa temp;
    scanf("%s", temp.nome);
    scanf("%d", &temp.idade);
    return temp;
}

void transferData(Pessoa* i1, Pessoa i2){
    i1->idade = i2.idade;
    strcpy(i1->nome, i2.nome);
}

RBTree* leArvore(Pessoa Temp){
    RBTree* X = (RBTree*)malloc(sizeof(RBTree));
    X->dir = NULL;
    X->esq = NULL;
    X->pai = NULL;
    X->cor = 1;
    transferData(&X->info, Temp);
    return X;
}
