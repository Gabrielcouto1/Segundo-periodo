#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    Lista lista1;
    int elem,pos,op=0;

    while (1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Inicializar uma lista;\n");
        printf("[2]: Inserir um elementos;\n");
        printf("[3]: Remover um elemento;\n");
        printf("[4]: Imprimir a lista na tela;\n");
        printf("[5]: Mostra o tamanho da lista;\n");
        printf("[6]: Pega um elemento da lista;\n");
        printf("[7]: Encerrar o programa.\n");
        printf("\tInsira a operacao: ");
        scanf("%d",&op);
        printf("\n----------------------------------\n");
        if(op==7)
            break;
        
        switch(op){
            case 1:
                lista1=cria_lista();
                printf("\n\t\t\tA lista foi criada com sucesso!");
                break;
            case 2:
                printf("\nInsira o elemento que deseja colocar na lista: ");
                scanf("%d",&elem);

                if(insere_elem(&lista1,elem)==0)
                    fprintf(stderr,"\n\t\t\tNao foi possivel inserir o elemento desejado.\n");

                else   
                    printf("\n\t\t\tO elemento foi inserido com sucesso!");

                break;
            case 3:
                printf("\nInsira o elemento que deseja remover da lista: ");
                scanf("%d",&elem);

                if(remove_elem(&lista1,elem)==0)
                    fprintf(stderr,"\n\t\t\tNao foi possivel remore o elemento da lista.\n");
                else   
                    printf("\n\t\t\tO elemento foi removido com sucesso!\n");
                break;
            case 4:
                mostra_lista(&lista1);
                break;
            case 5:
                printf("\nTamanho da lista: %d",tam_lista(&lista1));
                break;
            case 6:
                remove_ultimonegativo(&lista1,&elem);
                printf("\nUltimo negativo:%d",elem);

                //printf("\nInsira a posicao do elemento que deseja pegar: ");
                //scanf("%d",&pos);
//
                //if(get_elem_pos(lista1,pos,&elem)==0)
                //    fprintf(stderr,"\n\t\t\tNao foi possivel pegar o elemento da posicao inserida.\n");
//
                //else   
                //    printf("\n\t\t\tO elemento da posicao %d eh: %d",pos,elem);

                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                break;
        }
    }
    printf("\nObrigado!\n");
    apaga_lista(&lista1);

    return 1;
}