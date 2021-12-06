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
    int i;
    int a = 5;
    int b = 10;
    int c[5] = {'A','b','8','d','|'};

    printf("\nValor de a: %d\n",a);
    printf("Endereco de a: %p\n",&a);
    
    printf("\n Valor de b: %d\n",b);
    printf("Endereco de b: %p\n\n",&b);

    for (i=0;i<5;i++){
        printf("Valor de c[%d]:%c\n",i,*(c+i));//*(c+i) == c[i]
        printf("Endereco de c[%d]: %p\n",i,c+i);//c+i == &c[i]    
    }   

    return 0;  //Encerra o programa e retorna o valor 0
}