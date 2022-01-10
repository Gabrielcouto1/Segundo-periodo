#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "esfera.h"

struct ponto{
    float X,Y,Z;
};

Ponto * cria_esfera(float x, float y,float z){
    Ponto *p;
    p=(Ponto *)malloc(sizeof(Ponto));

    if(p!=NULL){
        p->X=x;
        p->Y=y;
        p->Z=z;
    }

    return p;
}

void libera_esfera (Ponto **p){
    free(*p);
    *p=NULL;
}

float raio(Ponto *p1, Ponto *p2){
    if(p1==NULL||p2==NULL)
        return 1;
    
    return sqrt((pow((p1->X-p2->X),2))+(pow((p1->Y-p2->Y),2))+(pow((p1->Z-p2->Z),2)));
}

float area(Ponto *p1, Ponto *p2, float raio){
    return (4*3.14159265358979*(pow(raio,2)));
}

float volume(Ponto *p1, Ponto*p2, float raio){
    return((4*3.14159265358979*(pow(raio,3)))/3);
}