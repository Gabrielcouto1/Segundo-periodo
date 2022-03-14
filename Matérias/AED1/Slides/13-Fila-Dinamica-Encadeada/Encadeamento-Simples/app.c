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
        printf("[2]: Inserir um elemento;\n");
        printf("[3]: Remover um elemento;\n");
        printf("[4]: Mostrar a fila;\n");
        printf("[5]: ;\n");
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
                if(fila1==NULL)
                    printf("\nNao foi possivel criar a fila");
                else
                    printf("\nA fila foi criada!");

                break;
            case 2:
                printf("\nInsira o elemento que deseja inserir: ");
                scanf("%d",&elem);
                if(insere_fim(fila1,elem)==0)
                    printf("\nNao foi possivel inserir o elemento.");
                else
                    printf("\nO elemento foi inserido com sucesso.");

                break;
            case 3:
                if(remove_ini(fila1,&elem)==0)
                    printf("\nNao foi possivel remover o primeiro elemento");
                else    
                    printf("\nO elemento %d foi removido.",elem);

                break;
            case 4:
                mostra_fila(fila1);

                break;
            case 5:
                if(exclui_fila(&fila1)==0)
                    printf("\nNao foi possivel excluir a fila");
                else
                    printf("\nA fila foi excluida");
                
                break;
            case 6:
                fila1=apaga_fila(&fila1);
                
                if(fila1==NULL)
                    printf("\nNao foi possivel criar a fila");
                else
                    printf("\nA fila foi criada!");

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 7 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");

    return 1;
}
