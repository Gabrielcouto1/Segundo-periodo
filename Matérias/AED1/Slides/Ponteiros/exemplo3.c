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
    int *p = 0x5DC;

    printf("\np=%p",p);

    p++;// avança um inteiro (4 bytes)

    printf("\np=%p",p);

    p+=15;// avança 15 inteiros (4x15 = 60 bytes)

    printf("\np=%p",p);

    p-=2;// retrocepe 2 inteiros (4x2 = 8 bytes)

    printf("\np=%p\n",p);

    return 0;  //Encerra o programa e retorna o valor 0
}