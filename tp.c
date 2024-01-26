#include "arvore.h"

void impPessoa(Pessoa temp){
    printf("Nome: %s\n", temp.nome);
    printf("Data de Nascimento: %s\n", temp.nasc);
    printf("Idade: %d\n", temp.idade);
}

Pessoa getPessoa(){
    Pessoa temp;
    scanf("%s", temp.nome);
    scanf("%s", temp.nasc);
    scanf("%d", &temp.idade);
    return temp;
}

int main(){

    RBTree* raiz = alocarArvore();
    Pessoa temp;
    int n, entry, flag = 0;    
    int fault;
    do{
        scanf("%d", &entry);
        switch(entry){
        case 1:
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                temp = getPessoa();
                insercao(raiz, temp);
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

    desalocarArvore(raiz);
    return 0;
}