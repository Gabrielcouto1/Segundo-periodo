/*
    tamanho em bytes ocupados por certas variaveis

    https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

int main(int argc, char *argv[])
{
    int idade=19;
    char nome[10]="Maria";
    double peso = 70;
    double altura = 1.65;
    int casada = 0;
    float miopia[2];
    long unsigned int tamanho_total = 0;
    
    miopia[0]=2.75;  //olho esquerdo
    miopia[1]=3;    //olho direito

    tamanho_total=sizeof(idade)+sizeof(nome)+sizeof(peso)+sizeof(altura)+sizeof(casada)\
                  +sizeof(miopia);

    printf("\nTamanho total ocupado em bytes: %lu",tamanho_total);
    return 0;  //Encerra o programa e retorna o valor 0
}