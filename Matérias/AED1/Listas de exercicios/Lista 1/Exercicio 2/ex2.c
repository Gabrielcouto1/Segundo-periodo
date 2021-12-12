/*


    https://github.com/gabrielcouto1
*/

#include <stdio.h>

long double fatorial(int num);
int arranjoSimples(int n, int p);

int main(int argc, char *argv[])
{
    long double x = 0;
    int n=0;
    int p=0;
    int resultado=0;

    printf("\nInsira um valor inteiro e maior que 0 para n: ");
    scanf("%d",&n);

    if (n<0){   //Se n for menor que 0, encerra o programa devido a erro matematico
        fprintf(stderr,"\nVoce inseriu um valor para n menor que 0.\n\n");
        return 1;
    }

    printf("\nInsira um valor inteiro e maior que 0 para p, sendo que n>p: ");
    scanf("%d",&p);

    if (p<0){  //Se p for menor que 0 o programa encerra devido a um erro matematico
        fprintf(stderr,"\nVoce inseriu um valor para p menor que 0.\n\n");
        return 3;
    }

    if (p>n){   //Se n for menor que p, o programa encerra devido a um erro matematico
        fprintf(stderr,"\nVoce inseriu um valor de p maior que o valor de n. Erro matematico.\n\n");
        return 5;
    }

    resultado = arranjoSimples(n,p);    //chama a funcao que calcula o arranjo simples de n elementos p a p
    printf("\n\n\nResultado = %d\n\n",resultado);

    return 0;  //Encerra o programa e retorna o valor 0
}

long double fatorial(int n){
    int i;
    long double fat = 1;

    for(i=1;i<=n;i++){  
        fat*=i;
    }
    return fat;     //Retorna o fatorial do numero inserido na funcao (n!)
}

int arranjoSimples(int n, int p){
    int k=0;

    k=n-p;

    return ((fatorial(n))/(fatorial(k)));   //Atraves da funcao fatorial, aplica a formula do arranjo simples
}