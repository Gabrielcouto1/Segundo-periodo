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
    float a = 13.5, *p;
    int b = 15, *q;
    
    p=&a;
    q=&b;

    printf("\na=%.2f\nb=%d\n",a,b);
    printf("\np=&a=%p\nq=&b=%p\n",p,q);
    
    *q=7; // acessa o conteúdo da memória endereçado por q

    printf("\na=%.2f\nb=%d\n",a,b);

    return 0;  //Encerra o programa e retorna o valor 0
}