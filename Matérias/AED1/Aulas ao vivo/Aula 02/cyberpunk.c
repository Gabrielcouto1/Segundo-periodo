#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main(int argc, char *argv[]){
    for(int j=1;j<2077;j++){
        char nome[50];
        sprintf(nome,"Cyberpunk%d.txt",j);
        FILE *fp;
        fp=fopen(nome, "w+");
        fprintf(fp,"Eu tenho uma dúvida sobre Cyberpunk 2077.\nEu preciso jogar ");
        for (int i=1;i<2077;i++){
            fprintf(fp,"Cyberpunk %d, ",i);
        }
        fprintf(fp,"para poder jogar o cyberpunk 2077?\n");
        fclose(fp);
    }
    system("mkdir Cyberpunk");
    system("move *.txt Cyberpunk");
    return 0;
}