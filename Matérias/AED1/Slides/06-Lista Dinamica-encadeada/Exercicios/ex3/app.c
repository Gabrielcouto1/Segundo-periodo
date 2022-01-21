#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    Bebida lista1;
    int i, qtd, op, vol;
    float preco;
    char nome[20],c;

    lista1=cria_lista();

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Inserir um registro;\n");
        printf("[2]: Remover o ultimo registro;\n");
        printf("[3]: Imprimir a lista na tela;\n");
        printf("[4]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");

        if(op==4)
            break;
        
        switch(op){
            case 1:
                printf("\nInsira quantas bebidas deseja inserir na lista: ");
                scanf("%d",&qtd);

                for(i=0;i<qtd;i++){
                    scanf("%c",&c);
                    printf("\nInsira o nome da bebida: ");
                    scanf("%[^\n]%*c",nome);

                    printf("\nInsira o volume(mL) da bebida: ");
                    scanf("%d",&vol);

                    printf("\nInsira o preco da bebida: ");
                    scanf("%f",&preco);

                    if(insere_elem(&lista1,nome,vol,preco)==0)
                        fprintf(stderr,"\n\t\t\tNao foi possivel inserir o elemento desejado.\n");

                    else   
                        printf("\n\t\t\tO elemento foi inserido com sucesso!");
                }

                break;
            case 2:
                if(remove_ultimo(&lista1)==0)
                    fprintf(stderr,"\n\t\t\tNao foi possivel remover o ultimo elemento.\n");
                else
                    printf("\n\t\t\tO ultimo elemento foi excluido com sucesso!\n");

                break;
            case 3:
                mostra_lista(&lista1);

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");

                break;
        }
    }
    printf("\nObrigado!\n");
    apaga_lista(&lista1);

    return 1;
}