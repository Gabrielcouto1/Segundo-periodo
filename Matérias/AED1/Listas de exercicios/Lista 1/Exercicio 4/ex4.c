/*
    https://github.com/gabrielcouto1
*/

#include <stdio.h> 

int main(int argc, char *argv[])
{
    FILE *F = NULL;

    F = fopen(argv[1],"w");

    if (argc<3){
        fprintf(stderr,"\nVoce nao inseriu a quantidade suficiente de argumentos.\n");
        fprintf(stderr,"\nInsira da forma ./programa arquivotexto.txt .\n");
        return 1;
    }
    else if (argc>3){
        fprintf(stderr,"\nVoce inseriu mais argumentos que o necessario.\n");
        fprintf(stderr,"\nInsira da forma ./programa arquivotexto.txt .\n");
        return 3;
    }
    else if(F==NULL){
        fprintf(stderr,"\nNao foi possivel abrir ou criar o arquivo com o nome inserido.\n\n");
        return 5;
    }


    fclose(F);
    return 0;  //Encerra o programa e retorna o valor 0
}