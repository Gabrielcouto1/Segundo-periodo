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
    int vet[5] = {1,2,3,4,5};   

    int *p = vet;

    printf("\n%d\n", *p);
    printf("%d\n",*(p+2));

    p=&vet[2];
    printf("%p\n",p);

    return 0;  //Encerra o programa e retorna o valor 0
}