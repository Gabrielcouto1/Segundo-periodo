/*


    https://github.com/gabrielcouto1
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 

struct aluno{
    int num_aluno;
    float nota[3];
    float media;
};

int main(int argc, char *argv[])
{
    struct aluno joao, *pa;
    pa=&joao;

    joao.num_aluno=10;
    joao.nota[0]=10;
    joao.nota[1]=4.4;
    joao.nota[2]=7;
    joao.media=(joao.nota[0]+joao.nota[1]+joao.nota[2])/3.0;

    printf("\nNumero aluno: %d\n",pa->num_aluno);   //pa->num_aluno == (*pa).num_aluno
    printf("Nota 1: %.2f\n",pa->nota[0]);
    printf("Nota 2: %.2f\n",pa->nota[1]);
    printf("Nota 3: %.2f\n",pa->nota[2]);
    printf("Media: %.2f\n",pa->media);

    return 0;  //Encerra o programa e retorna o valor 0
}
