/*
    Utilizando a estrutura abaixo, faça um programa para ler
    o número e as 3 notas de 10 alunos. Calcule a média para
    cada aluno e armazene na estrutura.

    struct aluno {
        int num_aluno;
        float nota1, nota2, nota3;
        float media;
    };

    https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

struct aluno {
        char nome[50];
        float nota1, nota2, nota3;
        float media;
};
const int max=3;
int main(int argc, char *argv[])
{
    struct aluno a[max];
    int i;

    for(i=0;i<max;i++){
        printf("\n Insira o nome do aluno: ");
        scanf("%[^\n]%*c",a[i].nome);

        printf("\nInsira a primeira nota: ");
        scanf("%f",&a[i].nota1);

        printf("\nInsira a segunda nota: ");
        scanf("%f",&a[i].nota2);

        printf("\nInsira a terceira nota: ");
        scanf("%f",&a[i].nota3);

        a[i].media=(a[i].nota1+a[i].nota2+a[i].nota3)/3.0;
        printf("\nMedia final do aluno %s: %.2f",a[i].nome,a[i].media);
    }
    return 0;  //Encerra o programa e retorna o valor 0
}