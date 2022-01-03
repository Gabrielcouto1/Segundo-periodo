#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

struct racional{
    int num,den;
};

Racional * generate(){
    Racional * p;
    p = (Racional *)malloc(sizeof(Racional));
    return p;
}

int set_value(Racional *p, int N, int D){
    if (p==NULL|| D==0)
        return 0;

    p->num=N;
    p->den=D;
}

int get_value(Racional *p, int *N, int *D){
    if(p==NULL)
        return 0;

    *N=p->num;
    *D=p->den;
    
    return 1;
}

Racional * sum(Racional *R1, Racional *R2){
    Racional *R3;
    R3= generate();

    if(R3!= NULL){
        R3->num=(R1->num*R2->den) + (R2->num*R1->den);
        R3->den=(R1->den*R2->den);
    }
    return R3;  //Sucesso ou falha
}

void delete(Racional ** p){
    free(*p);
    *p=NULL;
}