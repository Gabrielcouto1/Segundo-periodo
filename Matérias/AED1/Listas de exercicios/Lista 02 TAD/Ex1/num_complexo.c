#include <stdio.h>
#include <stdlib.h>
#include "num_complexo.h"

struct complexo{
    int real;
    int imaginario;
};

Complexo * cria_nro(){
    Complexo *num;
    num = (Complexo *)malloc(sizeof(Complexo));
    return num;
}

int set_nro(Complexo *num,int R, int I){
    if(num==NULL)
        return 1;

    num->real=R;
    num->imaginario=I;
    
    return 0;
}

int get_nro(Complexo *num, int *R, int *I){
    if(num==NULL)
        return 1;

    *R=num->real;
    *I=num->imaginario;
    
    return 0;
}

void libera_nro(Complexo ** num){
    free(*num);
    *num=NULL;
}

Complexo * soma(Complexo *N1,Complexo *N2){
    Complexo *N3;
    N3 = cria_nro();

    if(N3!=NULL){
        N3->real=(N1->real+N2->real);
        N3->imaginario=(N1->imaginario+N2->imaginario);
    }
    return N3;
}

Complexo * sub(Complexo *N1,Complexo *N2){
    Complexo *N3;
    N3 = cria_nro();

    if(N3!=NULL){
        N3->real=(N1->real-N2->real);
        N3->imaginario=(N1->imaginario-N2->imaginario);
    }
    return N3;
}

Complexo * mult(Complexo *N1, Complexo *N2){
    Complexo *N3;
    N3=cria_nro();

    if(N3!=NULL){
        N3->real=(N1->real*N2->real)-(N1->imaginario*N2->imaginario);
        N3->imaginario=(N1->real*N2->imaginario)+(N2->real*N1->imaginario);
    }
    
    return N3;
}