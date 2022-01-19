/*
    Sizeof: tamanho em bytes dos tipos de dados

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

    printf("\nTamanho em bytes de um char: %lu", sizeof(char));
    printf("\nTamanho em bytes de um int: %lu", sizeof(int));
    printf("\nTamanho em bytes de um float: %lu", sizeof(float));
    printf("\nTamanho em bytes de um double: %lu\n", sizeof(double));

    int num_aluno;
    printf("Tamanho em bytes de num_aluno= %lu\n",sizeof num_aluno);

    char nome[40];
    printf("Tamanho em bytes de nome[40]= %lu\n",sizeof(nome));

    double notas[60];
    printf("Tamanho em bytes de notas[60]= %lu\n",sizeof notas);

    return 0;  //Encerra o programa e retorna o valor 0
}