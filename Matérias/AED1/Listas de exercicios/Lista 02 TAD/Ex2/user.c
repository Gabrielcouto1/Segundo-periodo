#include <stdio.h>
#include "pontos.h"

int main(int argc,char *argv[]){
    Ponto *p1,*p2;
    float x,y,z;

    //***           Leitura dos pontos para calcular a distancia no espaco      ***//
    //cria o primeiro ponto
    printf("\nDigite as coordenadas (X,Y,Z), respectivamente, do primeiro ponto:\n");
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    p1=cria_pt(x,y,z);

    if(p1==NULL){
        fprintf(stderr,"\nHouve um erro na hora de criar o primeiro ponto.\n");
        return 1;
    }
    //cria o segundo ponto
    printf("\nDigite as coordenadas (X,Y,Z), respectivamente, do segundo ponto:\n");
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    p2=cria_pt(x,y,z);

    if(p1==NULL){
        fprintf(stderr,"\nHouve um erro na hora de criar o segundo ponto.\n");
        return 2;
    }

    //***           Calcula a distancia entre os dois pontos informados       ***//

    float dist;
    dist=distancia(p1,p2);

    if (dist<0){
        fprintf(stderr,"\nNao foi possivel calcular a distancia.\n");
        return 3;
    }

    printf("\nA distancia entre os dois pontos inseridos eh: %.2f\n",dist);
    
    //***               Apaga as instancias dos pontos na memoria             ***//
    apaga_pto(&p1);
    apaga_pto(&p2);

    return 0;
}