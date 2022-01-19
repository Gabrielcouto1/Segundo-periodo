/*
    strutct 

    https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

struct dados_pacientes{
    int idade,e_civil;
    char nome[50];
    double peso,altura;
    float grau_miopia[2];
}

int main(int argc, char *argv[])
{
    struct dados_pacientes paciente;

    strcpy(paciente.nome,"José");
    paciente.altura=1.25;
    paciente.peso=73;
    paciente.e_civil=1; //0= solteiro, 1= casado, 2= outro
    paciente.grau_miopia[0]=1.75;
    paciente.grau_miopia[1]=0;

    return 0;  //Encerra o programa e retorna o valor 0
}