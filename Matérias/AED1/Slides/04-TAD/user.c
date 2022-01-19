#include <stdio.h>
#include "racional.h"

int main(int argc, char *argv[])
{
    Racional *N1, *N2, *N3;
    int nu, de;

    N1=generate();
    N2=generate();

    if(N1==NULL||N2==NULL){
        fprintf(stderr,"\nNao foi possivel criar os numeros racionais.\n");
        return 1;
    }
    
    printf("\nDigite o numerador de o denominador do primeiro racional: ");
    scanf("%d",&nu);
    scanf("%d",&de);

    if(set_value(N1,nu,de)==0){
        printf("\nFalha ao preencher o primeiro racional\n");
        return 3;
    }

    printf("\nDigite o numerador de o denominador do segundo racional: ");
    scanf("%d",&nu);
    scanf("%d",&de);

    if(set_value(N2,nu,de)==0){
        fprintf(stderr,"\nFalha ao preencher o segundo racional\n");
        return 5;
    }

    N3=sum(N1,N2);
    
    if(N3==NULL){
        fprintf(stderr,"\nFalha ao somar os 2 numeros racionais.\n");
        return 7;
    }

    if(get_value(N3,&nu,&de)==0){
        fprintf(stderr,"\nFalha ao recuperar o numerador e o denominador resultante.\n");
        return 9;
    }

    printf("\nO resultado da soma eh: %d / %d .\n",nu,de);
    
    delete(&N1);
    delete(&N2);
    delete(&N3);

    return 0;  //Encerra o programa e retorna o valor 0
}