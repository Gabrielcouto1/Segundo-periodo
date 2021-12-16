/*
    O programa coleta dados de alunos (matricula, nome e nota) e os armazena em um
    vetor de struct. Apos isso, o programa passa os dados para um arquivo de texto.
    O nome do arquivo de texto e a quantidade de alunos sao passadas por argumentos 
    quando o usuario for executar o programa.

    Por Gabriel Couto de Freitas - https://github.com/gabrielcouto1
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
void preencheArquivo(struct Aluno a[100],int max,FILE *F);
int argsOK(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int qtd_aluno = 0;
    FILE *F = NULL;
    
    F = fopen(argv[1],"w"); //Abre o arquivo com a funcao de escrever

    if(argsOK(argc,argv)) 
        return 1;   //Se tiver um erro nos argumentos o programa encerra

    qtd_aluno = atoi(argv[2]);
    
    struct Aluno a[qtd_aluno];  //Inicia o vetor de struct com tamanho que o usuario passar como parametro 

    preencheDados(a,qtd_aluno); 
    preencheArquivo(a,qtd_aluno,F);

    fclose(F);//Fecha o arquivo aberto
    return 0;  //Encerra o programa e retorna o valor 0
}

void preencheDados(struct Aluno a[100],int max){//Coleta os dados a serem passados ao arquivo
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

void preencheArquivo(struct Aluno a[100],int max,FILE *F){ //Passa os dados coletados para o arquivo de texto
    int i;
    for(i=0;i<max;i++){
        fprintf(F,"Aluno %d-> Matricula: %s; Nome: %s; Nota: %.2f;\n",i+1,a[i].matricula,a[i].nome,a[i].nota);
    }
}

int argsOK(int argc, char *argv[]){  //Testa se os argumentos foram passados corretamente
    if (argc<3){
        fprintf(stderr,"\nVoce inseriu menos argumentos que o necessario.\n");
        fprintf(stderr,"\nInsira da forma ./programa arquivotexto.txt qtdAlunos .\n");
        return 3;
    }

    else if (argc>3){
        fprintf(stderr,"\nVoce inseriu mais argumentos que o necessario.\n");
        fprintf(stderr,"\nInsira da forma ./programa arquivotexto.txt qtdAlunos .\n");
        return 3;
    }

    char isInt = *argv[2];
    int qtd_aluno = 0;

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