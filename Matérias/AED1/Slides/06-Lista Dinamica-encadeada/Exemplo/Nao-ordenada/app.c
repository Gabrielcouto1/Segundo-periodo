#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    Lista lista1;
    int elem,op=0;

    printf("---------------Menu---------------\n");

    while (1){
        printf("\n\t\t O que deseja fazer?\n");
        printf("\t\t1: Inicializar uma lista;\n");
        printf("\t\t2: Inserir um elementos;\n");
        printf("\t\t3: Remover um elemento;\n");
        printf("\t\t4: Imprimir a lista na tela;\n");
        printf("\t\t5: Encerrar o programa.\n");
        printf("\n\t\tInsira a operacao: ");
        scanf("%d",&op);
    
        if(op==5)
            break;
        
        switch(op){
            case 1:
                lista1=cria_lista();
                printf("\n\t\t\tA lsita foi criada com sucesso!");
                break;
            case 2:
                printf("\nInsira o elemento que deseja colocar na lista: ");
                scanf("%d",&elem);

                if(insere_elem(&lista1,elem)==0)
                    fprintf(stderr,"\n\t\t\tNao foi possivel inserir o elemento desejado.\n");

                else   
                    printf("\n\t\t\tO elemento foi inserido com sucesso!");

                break;
            case 3:
                printf("\nInsira o elemento que deseja remover da lista.\n");
                scanf("%d",&elem);

                if(remove_elem(&lista1,elem)==0)
                    fprintf(stderr,"\n\t\t\tNao foi possivel remore o elemento da lista.\n");
                else   
                    printf("\n\t\t\tO elemento foi removido com sucesso!\n");
                break;
            case 4:
                continue;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                break;
        }
    }
}