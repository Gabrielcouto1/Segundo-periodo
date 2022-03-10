#include <stdio.h> 
#include <stdlib.h> 
#include "pilha.h"

int main(){
    Pilha pilha1;
    int op,elem;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma pilha;\n");
        printf("[2]: Inserir um elemento ;\n");
        printf("[3]: Remover o topo;\n");
        printf("[4]: Imprimir o topo;\n");
        printf("[5]: Imprimir a pilha completa;\n");
        printf("[6]: Converter um numero decimal para binario;\n");
        printf("[7]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==7)
            break;
        
        switch(op){
            case 1:
                pilha1=cria_pilha();
                
                break;
            case 2:
                printf("\nInsira o elemento que deseja inserir: ");
                scanf("%d",&elem);

                if(push(&pilha1,elem))
                    printf("\nElemento inserido com sucesso.");
                else    
                    printf("\nNao foi possivel inserir o elemento.");

                break;
            case 3:
                if(pop(&pilha1,&elem))
                    printf("\nO elemento %d foi removido da pilha.",elem);
                else
                    printf("\nNao foi possivel remover o elemento da pilha.");

                break;
            case 4:
                if(le_topo(&pilha1,&elem))
                    printf("\nElemento do topo: %d",elem);
                else
                    printf("\nNao foi possivel ler o elemento do topo.");

                break;
            case 5:
                mostra_pilha(pilha1);
                
                break;
            case 6:
                printf("\nInsira o numero decimal para fazer a conversao: ");
                scanf("%d",&elem);

                if(decimal_binario(elem)==0)
                    printf("\nNao foi possivel conerter o numero solicitado.");
                    
                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 7 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}
