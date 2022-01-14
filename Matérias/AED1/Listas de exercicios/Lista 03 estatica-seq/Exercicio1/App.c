#include <stdio.h>
#include "lista.h"

int main(){
    Lista lista1;
    int op,pos,qtd,i;
    char elem[tam];
    char c;

    printf("\n\t\t-----------Menu------------\n");
    while(1){
        printf("\n\t\t O que deseja fazer?\n");
        printf("\t\t1: Inicializar uma lista;\n");
        printf("\t\t2: Inserir elementos;\n");
        printf("\t\t3: Remover um elemento;\n");
        printf("\t\t4: Imprimir a lista na tela;\n");
        printf("\t\t5: Pegar um elemento pela posicao;\n");
        printf("\t\t6: Esvaziar a lista e voltar para a posicao inicial;\n");
        printf("\t\t7: Encerrar o programa.\n");
        printf("\n\t\tInsira a operacao: ");
        scanf("%d",&op);

        if(op==7)
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
                scanf("%c",&c);
                for(i=0;i<qtd;i++){
                    printf("\nInsira o elemento: ");
                    scanf("%[^\n]%*c",elem);
                    if(insere_elem(lista1,elem)==0){
                        fprintf(stderr,"\nHouve um erro ao inserir o elemento.\n");
                        break;
                    }
                } 
                break;
            case 3:   
                scanf("%c",&c);            
                printf("\nInsira o elemento que deseja remover: ");
                scanf("%[^\n]%*c",elem);
                if(remove_elem(lista1,elem)==0){
                    fprintf(stderr,"\n Nao foi possivel remover esse elemento.\n");
                    break;
                }
                else
                    continue;
                break;
            case 4:
                mostra_lista(lista1);
                break;
            case 5:
                if(get_elem_pos(lista1)==0)
                    fprintf(stderr,"\nA posicao inseridao nao tem um elemento, ou eh invalida.\n");
                break;
            case 6:
                esvazia_lista(lista1);
                break;
        }   
    }
    printf("\nObrigado!\n");

    libera_lista(&lista1);
    
    return 0;
}