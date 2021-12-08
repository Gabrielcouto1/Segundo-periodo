/*
    Exercicio para entregar. Slide "Ponteiros".
    Por Gabriel Couto de Freitas - 12021BCC040

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
    double *p, *q, *r, A[5];
    int i;

    for (i=0;i<5;i++)   //Atribuicao de valores de 0 ate 4 para as respectivas posicoes do vetor A[5]
        A[i]=i;         //Somente para facilitar a verificacao no terminal

    p=A;    
    q=p+1;  
    r=q+2;  

    printf("\n&A[0] = %lu;  *r     = %.2lf;\n",&A[0],*r);//mostra o endereco inicial (0) do vetor A e o 
                                                         //conteudo da posicao 3 do vetor
    printf("p     = %lu;  *(A+1) = %.2lf;\n",p+1,*(A+1));//mostra o endereco de p e o conteudo da 
                                                         //posicao 1 do vetor
    
    r=p+4;
    p=q;

    printf("\np+1   = %lu;  *(r-2) = %.2lf;\n",p+1,*(r-2));//mostra o endereco de p+1 e o conteudo da 
                                                           //posicao 2 do vetor                                          
    printf("&A[4] = %lu;  *r     = %.2lf;\n",&A[4],*r);//mostra o endereco da posicao final (4) do vetor e o  
                                                       //conteudo da posicao 4 do vetor

    return 0;  //Encerra o programa e retorna o valor 0
}