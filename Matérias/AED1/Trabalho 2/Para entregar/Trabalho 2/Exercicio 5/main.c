#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){
    int op=0,continua;
    char elem[tam];
    Fila fila1;

    while(1){
        if(op==8)
            break;
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma fila;\n");
        printf("[2]: Encerrar o programa.\n");
        scanf("%d",&op);
        if(op==2)
            break;

        if(op==1){
            fila1=cria_fila();
            if(fila1==NULL)
                printf("\nNao foi possivel criar a fila.");
            else{
                printf("\nA fila foi criada!");
                continua=1;
            }
        }
        else
            printf("Insira 1 ou 2 para as operações.");

        while (1){
            printf("\n---------------Menu---------------\n");
            printf("\n     O que deseja fazer?\n");
            printf("[1]: Inserir um elemento no inicio;\n");
            printf("[2]: Inserir um elemento no final;\n");
            printf("[3]: Remover um elemento no inicio;\n");
            printf("[4]: Remover um elemento no fim;\n");
            printf("[5]: Mostrar a fila;\n");
            printf("[6]: Excluir a fila;\n");
            printf("[7]: Apagar a fila;\n");
            printf("[8]: Encerrar o programa.\n");
            printf("\tInsira a operacao: ");
            scanf("%d",&op);
            printf("\n----------------------------------\n");
            if(op==8)
                break;
            switch(op){
                case 1:
                    printf("\nInsira o elemento que deseja inserir no inicio: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]%*c",elem);
                    if(insere_ini(fila1,elem))
                        printf("\nO elemento foi inserido com sucesso!");
                    else
                        printf("\nNao foi possivel inserir o elemento.");
                    break;
                case 2:
                    printf("\nInsira o elemento que deseja inserir no fim: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]%*c",elem);
                    if(insere_fim(fila1,elem))
                        printf("\nO elemento foi inserido com sucesso!");
                    else
                        printf("\nNao foi possivel inserir o elemento.");
                    break;
                case 3:
                    if(remove_ini(fila1,elem))
                        printf("\nO elemento (%s) foi removido do inicio da fila!",elem);
                    else
                        printf("\nNao foi possivel remover o elemento.");
                    break;
                case 4:
                    if(remove_fim(fila1,elem))
                        printf("\nO elemento (%s) foi removido do fim da fila!",elem);
                    else
                        printf("\nNao foi possivel remover o elemento.");
                    break;
                case 5:
                    mostra_fila(fila1);
                    break;
                case 6:
                    exclui_fila(&fila1);
                    if(fila1==NULL){
                        printf("\nA fila foi excluida com sucesso!");
                        continua=0;
                    }
                    else
                        printf("\nA fila nao foi excluida.");
                    break;
                case 7:
                    fila1=apaga_fila(&fila1);
                    if(fila1!=NULL)
                        printf("\nA fila foi apagada e criada novamente!");
                    else
                        printf("\nNao foi possivel apagar a fila e cria-la novamente.");
                    break;
                default:
                    fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 8 para as operacoes.\n");
                    break;
            }
            if(continua==0)
                break;
        }
    }

    printf("\nObrigado!\n");

    return 1;
}
