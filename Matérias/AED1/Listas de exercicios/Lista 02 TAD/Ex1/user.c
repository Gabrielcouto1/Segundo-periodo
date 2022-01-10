#include <stdio.h>
#include "num_complexo.h"

int main(){
    Complexo *C1,*C2,*C3,*CR;
    int R,I;
    //***           Cria a instancia em memoria dos numeros complexos   ***//
    C1=cria_nro();
    C2=cria_nro();
    C3=cria_nro();

    if(C1==NULL||C2==NULL||C3==NULL){
        fprintf(stderr,"\nNao foi possivel criar os numeros complexos.\n");
        return 1;
    }
    //***           Coleta os valores dos numeros complexos         ***//
    //Coleta dos dados do 1º ponto

    printf("\nDigite a parte real e, em seguida a parte imaginaria do primeiro numero complexo(C1): ");
    scanf("%d", &R);
    scanf("%d", &I);

    if(set_nro(C1,R,I)){
        fprintf(stderr,"\nFalha ao preencher o primeiro numero complexo.\n");
        return 2;
    }

    //Coleta dos dados do 2º ponto
    printf("\nDigite a parte real e, em seguida a parte imaginaria do segundo numero complexo(C2): ");
    scanf("%d", &R);
    scanf("%d", &I);

    if(set_nro(C2,R,I)){
        fprintf(stderr,"\nFalha ao preencher o segundo numero complexo.\n");
        return 3;
    }

    //Coleta dos dados do 3º ponto
    printf("\nDigite a parte real e, em seguida a parte imaginaria do terceiro numero complexo(C3): ");
    scanf("%d", &R);
    scanf("%d", &I);

    if(set_nro(C3,R,I)){
        fprintf(stderr,"\nFalha ao preencher o terceiro numero complexo.\n");
        return 3;
    }
    //***           Calcula a operacao pedida no exercicio      ***//
    //(C1-C3)
    CR=sub(C1,C3);

    if(CR==NULL){
        fprintf(stderr,"\nFalha ao subtrair os numeros complexos.\n");
        return 6;
    }
    //(C1-C3)*C2
    CR=mult(CR,C2);

    if(CR==NULL){
        fprintf(stderr,"\nFalha ao multiplicar os numeros complexos.\n");
        return 6;
    }

    //Coleta o valor da operacao
    if(get_nro(CR,&R,&I)){
        fprintf(stderr,"\nFalha ao recuperar o resultado final.\n");
        return 7;
    }

    printf("\nO resultado da operacao ((C1-C3)*C2) eh: Z=%d+%di.\n",R,I);

    //***           Libera as instancias criadas dos numeros complexos      ***//
    libera_nro(&C1);
    libera_nro(&C2);
    libera_nro(&C3);
    libera_nro(&CR);
    
    return 0;
}