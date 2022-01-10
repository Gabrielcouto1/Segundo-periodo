#include <stdio.h>
#include "esfera.h"

int main(int argc,char *argv[]){
    Ponto *p1,*p2;
    float x,y,z;

    //***           Leitura dos pontos para calcular as dimensoes da esfera      ***//
    //cria o primeiro ponto
    printf("\nDigite as coordenadas (X,Y,Z), respectivamente, do primeiro ponto:\n");
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    p1=cria_esfera(x,y,z);

    if(p1==NULL){
        fprintf(stderr,"\nHouve um erro na hora de criar o primeiro ponto.\n");
        return 1;
    }
    //cria o segundo ponto
    printf("\nDigite as coordenadas (X,Y,Z), respectivamente, do segundo ponto:\n");
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    p2=cria_esfera(x,y,z);

    if(p1==NULL){
        fprintf(stderr,"\nHouve um erro na hora de criar o segundo ponto.\n");
        return 2;
    }

    //***               Calcula o raio da esfera                               ***//

    float r;
    r= raio(p1,p2);

    if (r<=0){
        fprintf(stderr,"\nNao foi possivel calcular o raio da esfera.\n");
        return 3;
    }

    //***               Calcula a area da esfera                                ***//
    float a=area(p1,p2,r);

    //***               Calcula o volume da esfera                              ***//
    float v=volume(p1,p2,r);

    //***               Escreve na tela os resultados                           ***//
    printf("\n\tRaio da esfera:%.2f\n\tArea da esfera:%.2f\n\tVolume da esfera:%.2f\n\n",r,a,v);

    //***               Apaga as instancias dos pontos na memoria               ***//
    
    libera_esfera(&p1);
    libera_esfera(&p2);

    return 0;
}