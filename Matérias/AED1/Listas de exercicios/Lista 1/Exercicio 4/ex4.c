/*
    https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <ctype.h>
#include <stdlib.h>

struct Aluno{
    char matricula[100];
    char nome[100];
    float nota;
};
void preencheDados(struct Aluno a[100],int qtd_aluno);
void passaArquivo(struct Aluno a[100],int max,FILE *F);
int argsOK(int argc, char *argv[], int qtd_aluno);

int main(int argc, char *argv[])
{
    int qtd_aluno = 0;
    FILE *F = NULL;

    F = fopen(argv[1],"w");
    qtd_aluno = atoi(argv[2]);

    if(argsOK(argc,argv,qtd_aluno))
        return 1;

    struct Aluno a[qtd_aluno];

    preencheDados(a,qtd_aluno);
    passaArquivo(a,qtd_aluno,F);

    fclose(F);
    return 0;  //Encerra o programa e retorna o valor 0
}

void preencheDados(struct Aluno a[100],int max){
    int i;
    char c;

    for(i=0;i<max;i++){
        printf("\nInsira a matricula do aluno %d: ",i+1);
        scanf("%[^\n]%*c",a[i].matricula);
        
        
        printf("\nInsira o nome do aluno %d: ",i+1);
        scanf("%[^\n]%*c",a[i].nome);

        printf("\nInsira a nota do aluno %d: ",i+1);
        scanf("%f",&a[i].nota);
        scanf("%c",&c);     //Coleta de residuo da ultima coleta do teclado
        printf("\n");
    }
}

void passaArquivo(struct Aluno a[100],int max,FILE *F){
    int i;
    for(i=0;i<max;i++){
        fprintf(F,"Matricula: %s; Nome: %s; Nota: %.2f;\n",a[i].matricula,a[i].nome,a[i].nota);
    }
}

int argsOK(int argc, char *argv[], int qtd_aluno){
    char isInt = *argv[2];

    if (argc<3){
        fprintf(stderr,"\nVoce nao inseriu a quantidade suficiente de argumentos.\n");
        fprintf(stderr,"\nInsira da forma ./programa arquivotexto.txt qtdAlunos .\n");
        return 1;
    }

    else if (argc>3){
        fprintf(stderr,"\nVoce inseriu mais argumentos que o necessario.\n");
        fprintf(stderr,"\nInsira da forma ./programa arquivotexto.txt qtdAlunos .\n");
        return 3;
    }

    if (isdigit(isInt)){
        qtd_aluno = atoi(argv[2]);
    }

    if(isdigit(isInt)==0||(qtd_aluno<=0)||(qtd_aluno>100)) {
        fprintf(stderr,"\nVoce inseriu uma quantidade de alunos invalida.\n");
        fprintf(stderr,"\nInsira da forma ./programa arquivotexto.txt qtdAlunos .\n");
        return 7;
    }

    return 0;
}
