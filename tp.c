#include "arvore.h"


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
                tempNode = alocaArvore(tempPessoa);
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