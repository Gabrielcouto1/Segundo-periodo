#include <stdio.h> 
#include <stdlib.h> 
#include "lista_ord.h"

int main(){
    int op=0;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Inicializa uma lista;\n");
        printf("[2]: Insere elementos;\n");
        printf("[3]: Remove um elemento;\n");
        printf("[4]: Remove as vogais;\n");
        printf("[5]: Pega um elemento pela posicao;\n");
        printf("[6]: Remove um elemento pela posicao;\n");
        printf("[6]: Remove um elemento pela posicao;\n");
        printf("[7]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==7)
            break;
        
        switch(op){
            case 1:
                
                
                break;
            case 2:
                

                break;
            case 3:
                

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