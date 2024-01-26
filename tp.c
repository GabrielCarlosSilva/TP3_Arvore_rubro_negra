#include "arvore.h"

Pessoa getPessoa(){
    Pessoa temp;
    scanf("%s", temp.nome);
    scanf("%d", &temp.idade);
    return temp;
}

int main(){

    RBTree* raiz = alocarArvore();
    Pessoa temp;
    int n, entry, flag = 0;    
    do{
        scanf("%d", &entry);
        switch(entry){
        case 1:
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                temp = getPessoa();
                insercao(&raiz, temp);
            }
            break;
        case 2:
            printf("Dados inOrder:\n");
            printInOrder(raiz);
            break;
        default:
            flag = 1;
            break;
        }
    }while(flag != 1);

    //desalocarArvore(raiz);
    return 0;
}