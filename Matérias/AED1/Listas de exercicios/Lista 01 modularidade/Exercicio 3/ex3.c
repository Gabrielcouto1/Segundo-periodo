/*
    O programa coleta N numeros inteiros e os organiza em um vetor em ordem crescente.
    A quantidade N de numeros eh passada pelo usuario por argumento da funcao main.
    A funcao sortArray organiza em tempo real e descobre em qual lugar o novo numero
    inserido deve ficar e reorganiza os outros elementos do vetor.

    https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

int sortArray(int array[],int t,int max, int *cont);
void showArray(int array[],int max);

int main(int argc, char *argv[])
{
    int max=0;//quantidade de numeros a serem digitados
    int t=0;//novo numero que sera digitado
    int i,j;
    int cont=0;//Contador que mostra quantos elementos ja foram digitados
    char isInt;

    if(argc<2){
        fprintf(stderr,"\nVoce inseriu menos argumentos que o necessario.\n");
        fprintf(stderr,"\nInsira da forma ./programa N .\n");
        return 1;
    }
    if(argc>2){
        fprintf(stderr,"\nVoce inseriu mais argumentos que o necessario.\n");
        fprintf(stderr,"\nInsira da forma ./programa N .\n");
        return 2;
    }
    isInt==*argv[1];
    if(isdigit(isInt)){
        fprintf(stderr,"\nVoce inseriu o argumento de numeros erroneamente.\n");
        fprintf(stderr,"\nInsira entre 2 e 30 numeros.\n");
        return 3;
    }
    else 
        max=atoi(argv[1]);
    if(max<2||max>30||max<0){
        fprintf(stderr,"\nVoce inseriu uma quantidade de numeros invalida.\n");
        fprintf(stderr,"\nInsira entre 2 e 30 numeros.\n");
        return 4;
    }

    int array[max];

    for (i=0;i<max;i++){
        printf("\nInsira o proximo valor a ser inserido: ");
        scanf("%d",&t);

        sortArray(array,t,max,&cont);
    }
    showArray(array,max);
    
    return 0;  //Encerra o programa e retorna o valor 0
}
//A funcao sortArray descobre em qual lugar o novo numero digitado deve ser inserido, e se tiver
//algum numero a sua direita, todos eles sao "empurrados" uma casa a direita, atraves da logica a seguir:
int sortArray(int array[],int t,int max, int *cont){    
    int i,j;

    if(*cont==0){
        array[0]=t;
        (*cont)++;
        return 0;
    }

    for (i=0;i<(*cont);i++)
        if(array[i]>t){
            break;
        }

    for(j=(*cont);j>i;j--)
        array[j]=array[j-1];

    array[i]=t;
    (*cont)++;
    return 0;
}
//Imprime o array em ordem crescente na tela
void showArray(int array[],int max){
    int i;

    printf("\nO array digitado e em ordem crescente é: \n");
    for(i=0;i<max;i++)
        printf(" %d ",array[i]);
    printf("\n");
}