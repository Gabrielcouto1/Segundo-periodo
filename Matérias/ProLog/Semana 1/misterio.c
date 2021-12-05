#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

int misterio();
int main(int argc, char *argv[])
{
    int x=0;
    int y=0;
    int result=0;

    x= atoi(argv[1]);
    y= atoi(argv[2]);
    
    printf("\nx= %d\ny= %d\n",x,y);

    result=misterio(x,y);

    printf("\nResultado = %d\n",result);
    return 0;  //Encerra o programa e retorna o valor 0
}

int misterio(int x, int y){
    int temp=0;

    if (y==0)
        return 1;

    if (y==1)
        return x;

    if(y%2==0){
        temp = misterio(x,(y/2));
        return temp*temp;
    }

    temp = misterio(x,(y-1)/2);
    return temp*temp*x;
    }