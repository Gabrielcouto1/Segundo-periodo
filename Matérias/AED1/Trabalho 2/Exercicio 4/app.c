#include <stdio.h> 
#include <stdlib.h> 
#include "fpa.h"

int main(){
    int op;

    printf("\n---------------Menu---------------\n");
    printf("\n     O que deseja fazer?\n");
    printf("[1]: Criar uma fila;\n");
    printf("[2]: Encerrar o programa.\n");
    scanf("%d",&op);
    if(op==2){
        printf("\nOrigado!\n");
        return 1;
    }

    Fila fila1=cria_fila();
    struct paciente pcnt1;
    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Inserir um paciente na fila;\n");
        printf("[2]: Remover o primeiro paciente;\n");
        printf("[3]: Mostrar a fila inteira;\n");
        printf("[4]: Excluir a fila;\n");
        printf("[5]: Esvaziar a fila;\n");
        printf("[6]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        setbuf(stdin, NULL);
        printf("\n----------------------------------\n");
        if(op==6)
            break;
        
        switch(op){
            case 1:
                printf("\nInsira o nome do paciente: ");
                scanf("%[^\n]%*c",pcnt1.nome);
                setbuf(stdin, NULL);

                printf("\nInsira a idade do paciente: ");
                scanf("%d",&pcnt1.idade);
                setbuf(stdin, NULL);

                printf("\nInsira o peso do paciente: ");
                scanf("%f",&pcnt1.peso);
                setbuf(stdin, NULL);

                printf("\nInsira a altura do paciente: ");
                scanf("%f",&pcnt1.altura);
                setbuf(stdin, NULL);

                printf("\nInsira o tipo da doenca: ");
                scanf("%c",&pcnt1.doenca);
                setbuf(stdin, NULL);

                printf("\nInsira a gravidade do paciente: ");
                scanf("%d",&pcnt1.gravidade);
                setbuf(stdin, NULL);

                if(insere_paciente(&fila1,pcnt1))
                    printf("\nO paciente foi inserido na fila com sucesso!");
                else
                    printf("\nNao foi possivel inserir o paciente.");

                break;
            case 2:
                if(remove_paciente(&fila1,&pcnt1)){
                    printf("\nPaciente removido com sucesso!");
                    mostra_paciente(pcnt1);
                }
                else
                    printf("\nNao foi possivel remover o paciente.");

                break;
            case 3:
                mostra_fila(fila1);

                break;
            case 4:
                if(exclui_fila(&fila1)){
                    printf("\nA fila foi excluida com sucesso. Deseja criar outra fila? [0/1]: ");
                    scanf("%d",&op);
                    if(op==0){
                        printf("\nObrigado!\n");
                        return 1;
                    }
                    else{
                        fila1=cria_fila();
                        printf("\nA fila foi criada com sucesso!");
                    }
                }
                else
                    printf("\nNao foi possivel excluir a fila");

                break;
            case 5:
                fila1=apaga_fila(&fila1);
                printf("\nA fila foi esvaziada com sucesso!");
                
                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 6 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}
