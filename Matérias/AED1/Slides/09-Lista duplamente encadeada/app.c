#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    int op,elem,qtd,i;
    Lista lista;
    
    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma lista;\n");
        printf("[2]: Inserir elementos;\n");
        printf("[3]: Remover um elemento;\n");
        printf("[4]: Mostrar a lista;\n");
        printf("[5]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==5)
            break;
        
        switch(op){
            case 1:
                lista=cria_lista();
                printf("\nLista criada com sucesso!");
                
                break;
            case 2:
                printf("\nInsira quantos elementos deseja inserir: ");
                scanf("%d",&qtd);
                for(i=0;i<qtd;i++){
                    printf("\nInsira o elemento: ");
                    scanf("%d",&elem);
                    if(insere_elemento(&lista,elem)==0)
                        printf("\nNao foi possivel inserir o elemento.");
                }

                break;
            case 3:
                printf("\nInsira o elemento que deseja remover: ");
                scanf("%d",&elem);
                if(remove_elemento(&lista,elem)==0)
                    printf("\nNao foi possivel remover o elemento.");

                break;
            case 4:
                mostra_lista(&lista);

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}
