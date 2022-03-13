#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "pilha.h"

int main(){
    int op;
    int continuar=0;
    char elem[255],pos_fix[255];

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\nInsira a expressao na forma infixa: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]%*c",elem);
        
        if(strcmp(elem,"FIM")==0)
            break;

        strcpy(pos_fix,elem);

        switch(verificar_escopo(elem)){
            case 0:
                printf("\nA expressao eh invalida.");
                printf("\nHouve um erro ao colocar ou retirar um elemento na pilha.");
                break;
            case 1: 
                printf("\nA expressao eh valida!");
                continuar=1;
                break;
            case 2:
                printf("\nA expressao eh invalida.");
                printf("\nChaves nao podem ser usadas dentros de colchetes ou parenteses, e ");
                printf("colchetes nao podem estar dentro de parenteses.");
                break;
            case 3:
                printf("\nA expressao eh invalida.");
                printf("\nA ordem de fechamento dos delimitadores esta errada.");
        }

        if(continuar==1){
            if(infixa_posfixa(pos_fix)==0){
                printf("\nNao foi possivel converter a expressao para sua forma pos-fixa.");
                continuar=0;
            }
            else
                printf("\nExpressao convertida para a forma pos-fixa: %s",pos_fix);
        }
        if(continuar==1){
            
        }
    }
    printf("\nObrigado!\n");

    return 1;
}
