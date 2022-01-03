#include <stdio.h> 
#include <stdlib.h>  

int main(int argc, char *argv[])
{
    FILE *F[2077];
    int i,j;
    
    
    fprintf(F[i],"Eu tenho uma dúvida sobre Cyberpunk 2077.\nEu preciso jogar ");
    for (i=1;i<=2077;i++){
        F[i]=fopen(argv[1]+i,"w");
        for(j=0;j<2077;j++){
            fprintf(F[i],"Cyberpunk %d, ",j);
        }
        fprintf(F[i],"para poder jogar o cyberpunk 2077?\n");
        fclose(F[i]);
    }
    

    
    return 0;  //Encerra o programa e retorna o valor 0
}