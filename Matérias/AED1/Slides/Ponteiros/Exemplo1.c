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
    int a = 40;
    int *p;

    p=&a;

    printf("\nO valor da variavel a eh %d",*p);
    printf("\nO valor da variavel p eh %lu",p);
    printf("\nO endereco da variavel p eh %lu\n", &p);

    return 0;  //Encerra o programa e retorna o valor 0
}