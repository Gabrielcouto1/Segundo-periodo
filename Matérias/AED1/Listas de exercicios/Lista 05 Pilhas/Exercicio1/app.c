#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "pilha.h"

int main(){
    int op,tamanho;
    char elem[tam];
    Pilha pilha=NULL;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma pilha;\n");
        printf("[2]: Inserir um elemento;\n");
        printf("[3]: Remover o ultimo elemento;\n");
        printf("[4]: Imprimir a pilha;\n");
        printf("[5]: Ler o topo da pilha;\n");
        printf("[6]: Retornar o tamanho da pilha;\n");
        printf("[7]: Esvaziar a pilha;\n");
        printf("[8]: Apagar a pilha;\n");
        printf("[9]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        setbuf(stdin, NULL);
        printf("\n----------------------------------\n");
        if(op==9)
            break;
        
        switch(op){
            case 1:
                pilha=cria_pilha();
                if(pilha==NULL)
                    printf("\nNao foi possivel criar a pilha.");
                
                break;
            case 2:
                printf("\nInsira a string que quer colocar na pilha: ");
                scanf("%[^\n]%*c",elem);
                setbuf(stdin, NULL);
                
                if(push(pilha,elem)==0)
                    printf("\nNao foi possivel inserir a string na pilha.");

                break;
            case 3:
                strcpy(elem,pop(pilha));

                if(strcmp(elem,"\0")==0)
                    printf("\nNao foi possivel remover o elemento");
                else    
                    printf("\nO elemento do topo (%s) foi removido com sucesso!",elem);

                break;
            case 4:
                imprime_pilha(pilha);

                break;
            case 5:
                strcpy(elem,le_topo(pilha));
                if(strcmp(elem,"\0")==0)
                    printf("\nNao foi possivel pegar o elemento do topo.");
                else    
                    printf("\nO elemento do topo eh: %s",elem);
                
                break;
            case 6:
                tamanho=tamanho_pilha(pilha);

                if(tam==-1)
                    printf("\nNao foi possivel pegar o tamanho da pilha.");
                else
                    printf("\nO tamanho da pilha eh: %d",tamanho);

                break;
            case 7:
                pilha=esvazia_pilha(&pilha);

                break;
            case 8:
                apaga_pilha(&pilha);

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 9 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}