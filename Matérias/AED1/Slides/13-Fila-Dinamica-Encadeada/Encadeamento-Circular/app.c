#include <stdio.h> 
#include <stdlib.h> 
#include "fila.h"

int main(){
    int op,elem;
    Fila fila1=NULL;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar uma fila;\n");
        printf("[2]: Insrerir um elemento;\n");
        printf("[3]: Remover um elemento;\n");
        printf("[4]: Mostrar a fila;\n");
        printf("[5]: Excluir a fila;\n");
        printf("[6]: ;\n");
        printf("[7]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==7)
            break;
        
        switch(op){
            case 1:
                fila1=cria_fila();
                printf("\nA fila foi criada com sucesso!");

                break;
            case 2:
                printf("\nInsira um elemento para colocar na fila: ");
                scanf("%d",&elem);

                if(insere_fim(&fila1,elem))
                    printf("\nO elemento foi inserido com sucesso!");
                else
                    printf("\nNao foi possivel inserir o elemento.");

                break;
            case 3:
                if(remove_ini(&fila1,&elem))
                    printf("\nO elemento %d foi removido da fila!",elem);
                else    
                    printf("\nNao foi possivel remover o elemento da fila");

                break;
            case 4:
                mostra_fila(fila1);

                break;
            case 5:
                if(exclui_fila(&fila1))
                    printf("\nA fila foi excluida!");
                else
                    printf("\nA fila ja tinha sido excluido ou nao foi criada.");
                
                break;
            case 6:
                

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 7 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}
