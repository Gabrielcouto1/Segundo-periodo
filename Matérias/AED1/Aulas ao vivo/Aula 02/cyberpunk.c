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
    FILE *F = NULL;
    int i;
    F=fopen("cyberpunk.txt","w");
    
    fprintf(F,"Eu tenho uma dúvida sobre Cyberpunk 2077.\nEu preciso jogar ");
    for (i=1;i<=2077;i++){
        fprintf(F,"Cyberpunk %d, ",i);
    }
    fprintf(F,"para poder jogar o cyberpunk 2077?\n");

    fclose(F);
    return 0;  //Encerra o programa e retorna o valor 0
}