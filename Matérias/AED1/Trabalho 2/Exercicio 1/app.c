#include <stdio.h> 
#include <stdlib.h> 
#include "pilha.h"

int main(){
    int num;
    char op;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\nInsira o numero que deseja fazer a conversao: ");
        scanf("%d",&num);
        setbuf(stdin, NULL);

        if(num<0)
            break;

        printf("\nInsira o sistema para qual deseja converter o numero %d: \n",num);
        printf("[B]: Binario ;\n");
        printf("[O]: Octal ;\n");
        printf("[H]: Hexadecimal ;\n");
        printf("\tInsira a operacao: ");
        scanf("%c",&op);
        printf("\n----------------------------------\n");
        
        switch(op){
            case 'B':
                if(decimal_binario(num)==0)
                    printf("\nNao foi possivel converter o numero.");
                
                break;
            case 'O':
                if(decimal_octal(num)==0)
                    printf("\nNao foi possivel converter o numero.");

                break;
            case 'H':
                if(decimal_hexadecimal(num)==0)
                    printf("\nNao foi possivel converter o numero.");

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira as operacoes B, O ou H.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}
