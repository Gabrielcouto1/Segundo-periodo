#include <stdio.h>
#include "lista.h"

int main(){
    Lista lista1;
    int op,pos,qtd,i;
    double elem;

    printf("\n\t\t-----------Menu------------\n");
    while(1){
        printf("\n\t\t O que deseja fazer?\n");
        printf("\t\t1: Inicializar uma lista;\n");
        printf("\t\t2: Inserir elementos;\n");
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
                if(lista1==NULL){
                    fprintf(stderr,"\nNao foi possivel criar a lista.\n");
                }
                break;
            case 2:
                printf("\nQuantos elementos deseja inserir?: ");
                scanf("%d",&qtd);
                for(i=0;i<qtd;i++){
                    printf("\nInsira o elemento: ");
                    scanf("%lf",&elem);
                    if(insere_elem(lista1,elem)==0){
                        fprintf(stderr,"\nHouve um erro ao inserir o elemento.\n");
                        break;
                    }
                } 
                break;
            case 3:               
                printf("\nInsira o elemento que deseja remover: ");
                scanf("%lf",&elem);
                if(remove_elem(lista1,elem)==0){
                    fprintf(stderr,"\n Nao foi possivel remover esse elemento.\n");
                    break;
                }
                else
                    continue;
                break;
            case 4:
                obtem_valor_elem(lista1);
        }   
    }
    printf("\nObrigado!\n");

    libera_lista(&lista1);
    
    return 0;
}