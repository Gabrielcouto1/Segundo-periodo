#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    Lista lista1;
    int qtd,i,op;
    unsigned int matricula;
    char nome[20],c;
    float media;
    int faltas;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma lista;\n");
        printf("[2]: Inserir elementos;\n");
        printf("[3]: Remover um elemento;\n");
        printf("[4]: Imprimir a lista;\n");
        printf("[5]: Esvaziar a lista;\n");
        printf("[6]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==6)
            break;
        
        switch(op){
            case 1:
                lista1=cria_lista();                
                break;
            case 2:
                printf("\nQuantos elementos deseja inserir: ");
                scanf("%d",&qtd);

                for(i=0;i<qtd;i++){
                    printf("\n\nInsira a codigo: ");
                    scanf("%d",&matricula);

                    scanf("%c",&c);
                    printf("\nInsira o nome: ");
                    scanf("%[^\n]%*c",nome);

                    printf("\nInsira o preco: ");
                    scanf("%f",&media);

                    if(insere_produto(&lista1,matricula,nome,media)==0)
                        printf("\nNao foi possivel inserir.\n");
                }

                break;
            case 3:
                if(remove_menor(&lista1,&matric)==0)
                    printf("\nNao foi possivel remover o aluno.");

                break;
            case 4:
                imprime_lista(lista1);
                break;
            //case 5:
            //    if(esvazia_lista(&lista1)==0)
            //        printf("\nNao foi possivel esvaziar a lista.\n");                
            //    break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 6 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");
   // esvazia_lista(&lista1);

    return 1;
}