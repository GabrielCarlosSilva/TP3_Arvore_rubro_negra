#include "arvore.h"

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

RBTree* criaNo(Pessoa Temp){
    RBTree* X = (RBTree*)malloc(sizeof(RBTree));
    X->dir = NULL;
    X->esq = NULL;
    X->pai = NULL;
    X->cor = 1;
    transferData(&X->info, Temp);
    return X;
}

int main(){
    RBTree* raiz = NULL;    
    RBTree* tempNode;

    Pessoa tempPessoa;

    int n, entry, flag = 0;
    do{
        scanf("%d", &entry);
        switch(entry){
        case 1:
            scanf("%d", &n);
            for (int i = 0; i < n; i++){
                tempPessoa = getPessoa();
                tempNode = criaNo(tempPessoa);
                raiz = insersao(raiz, tempNode);
                balanceamento(&raiz, tempNode);
            }
            break;
        case 2:
            printf("Dados inOrder:\n");
            inOrder(raiz);
            break;
        default:
            flag = 1;
            break;
        }
    }while(flag != 1);
    

    desaloca(raiz);
    return 0;
}