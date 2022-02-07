#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    int elem,op,pos,tam;
    Lista lista;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma lista;\n");
        printf("[2]: Inserir no inicio;\n");
        printf("[3]: Inserir no final;\n");
        printf("[4]: Mostrar a lista;\n");
        printf("[5]: Remover no inicio;\n");
        printf("[6]: Remover no final;\n");
        printf("[7]: Inserir um elemento em uma posicao especifica;\n");
        printf("[8]: Remover todos os elementos pares;\n");
        printf("[9]: Retorna o tamanho da lista;\n");
        printf("[10]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==10)
            break;
        
        switch(op){
            case 1:
                lista=cria_lista();
                printf("\nA lista foi criada com sucesso!");
                
                break;
            case 2:
                printf("\nInsira o elemento que deseja inserir no inicio: ");
                scanf("%d",&elem);
                if(insere_inicio(&lista,elem)==0)
                    printf("\nNao foi possivel inserir o elemento no inicio.");
                else
                    printf("\nO elemento foi inserido com sucesso!");

                break;
            case 3:
                printf("\nInsira o elemento que deseja inserir no final: ");
                scanf("%d",&elem);
                if(insere_final(&lista,elem)==0)
                    printf("\nNao foi possivel inserir o elemento no final.");
                else
                    printf("\nO elemento foi inserido com sucesso!");

                break;
            case 4:
                mostra_lista(lista);

                break;
            case 5:
                if(remove_inicio(&lista,&elem)==0)
                    printf("\nNao foi possivel remover o elemento do inicio.");
                else
                    printf("\nO elemento do inicio (%d) foi removido com sucesso!",elem);
                
                break;
            case 6:
                if(remove_final(&lista,&elem)==0)
                    printf("\nNao foi possivel remover o elemento do final.");
                else
                    printf("\nO elemento final (%d) foi removido com sucesso!",elem);

                break;
            case 7:
                printf("\nInsira a posicao que deseja inserir um elemento: ");
                scanf("%d",&pos);
                printf("\nInsira o elemento que deseja inserir na posicao %d: ",pos);
                scanf("%d",&elem);

                if(insere_elem_pos(&lista,pos,elem)==0)
                    printf("\nNao foi possivel inserir o elemento.");
                else
                    printf("\nO elemento foi inserido com sucesso!");

                break;
            case 8:

                break;
            case 9:
                tam=tamanho_lista(lista);
                if(tam==-1)
                    printf("\nNao foi possivel verificar o tamanho da lista.");
                else    
                    printf("\nTamanho da lista: %d.",tam);
                    
                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 9 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}