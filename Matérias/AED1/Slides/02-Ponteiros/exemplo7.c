/*


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
    int x = 10;
    int *p = &x;    //p aponta para um inteiro e endereca x
    int **q = &p;   //q aponda para um ponteiro de inteiro e endereca p

    printf("\nq=%p\n",q);   //Retorna o conteudo de q
    printf("q=%p\n",*q);    //Retorna o conteudo da posicao apontada por q
    printf("q=%d\n",**q);   //Retorna o conteudo da posicao apontada por p

    return 0;  //Encerra o programa e retorna o valor 0
}