#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    int op=0;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: ;\n");
        printf("[2]: ;\n");
        printf("[3]: ;\n");
        printf("[4]: ;\n");
        printf("[5]: ;\n");
        printf("[6]: ;\n");
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

    return 1;
}