#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    Lista lista1;
    int op,qtd,elem,i;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma lista;\n");
        printf("[2]: Inserir elementos na lista;\n");
        printf("[3]: Remover um elemento da lista;\n");
        printf("[4]: Mostrar a lista na tela;\n");
        printf("[5]: Mostrar o tamanho da lista;\n");
        printf("[6]: Esvaziar a lista;\n");
        printf("[7]: Pegar um elemento pela posicao;\n");
        printf("[8]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==8)
            break;
        
        switch(op){
            case 1:
                lista1=cria_lista();
                printf("\n\t\t\tA lista foi criada com sucesso!");

                break;
            case 2:
                printf("\nInsira a quantidade de elementos que deseja colocar na lista: ");
                scanf("%d",qtd);

                for(i=0;i<qtd;i++){
                    printf("\nInsira o elemento: ");
                    scanf("%d",elem);

                    if(insere_elem(&lista1,elem)==0)
                        fprintf(stderr,"\nNao foi possivel inserir o elemento.");
                    else 
                        printf("\nO elemento foi inserido com sucesso!");
                }

                break;
            case 3:
                printf("\nInsira o elemento que deseja remover da lista: ");
                scanf("%d",elem);

                if(remove_elem(&lista1,elem));

                break;
            case 4:
                

                break;
            case 5:
                
                
                break;
            case 6:
                

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");
    //apaga_lista(&lista1);

    return 1;
}