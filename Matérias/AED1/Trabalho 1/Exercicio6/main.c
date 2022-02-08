#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){


    Lista lst=NULL, lst1=NULL;
    double x,elem;
    int op, pos, n;


    while(1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("\n[1]: Manipular lista ;\n");
        printf("[2]: Encerrar o programa\n");
        scanf("%d",&op);
        setbuf(stdin, NULL);
        if(op==2)
            break;

        switch(op){
            case 1:
                while(1){
                    printf("\n[1] Criar lista\n");
                    printf("[2] Imprimir Lista\n");
                    printf("[3] Insere elemento\n");
                    printf("[4] Remove Elemento\n");
                    printf("[5] Insere na posicao\n");
                    printf("[6] Remove Menor\n");
                    printf("[7] Inverte Lista\n");
                    printf("[8] Remove ocorrencias\n");
                    printf("[9] Voltar\n");
                    scanf("%d", &n);
                    setbuf(stdin, NULL);
                    if(n==9)
                        break;

                    switch(n){
                        case 1:
                            lst = cria_lista();
                            if(&lst == NULL){
                                printf("Lista ainda n�o foi criada\n");
                            }else
                                printf("Lista criada!\n");
                            break;

                        case 2:
                            imprime_lista(lst);

                         break;

                        case 3:
                            printf("\nDigite o elemento a ser inserido\n");
                            scanf("%lf", &elem);
                            insere_elemento(&lst, elem);
                            break;

                        case 4:
                            printf("\nDigite o elemento a ser removido\n");
                            scanf("%lf", &x);
                            remove_elemento(&lst, x);
                            printf("\nElemento removido\n");

                            break;

                        case 5:
                            printf("\nDigite o elemento a ser inserido\n");
                            scanf("%lf", &elem);
                            printf("\nDigite a posicao a ser inserido\n");
                            scanf("%d", &pos);
                            insere_pos(&lst, elem, pos);

                            break;

                        case 6:
                            remove_menor(&lst);
                            printf("\nMenor elemento removido\n");
                            break;

                        case 7:
                            lst1 = cria_lista();
                            inverte_lista(&lst, &lst1);
                            printf("\nLista invertida\n");
                            imprime_lista(lst1);
                            break;

                        case 8:
                             printf("Digite valor a ser removido e suas ocorrencias\n");
                             scanf("%lf", &elem);
                             remove_ocorrencias(&lst,elem);
                             printf("Ocorrencias removidas\n");
                            break;

                        default:
                            printf("Opcao invalida, selecione uma op��o de 1 a 9\n");
                            break;
                    }

                }
                break;
            default:
                printf("\nInsira operacoes de 1 ou 2.");
                break;
        }
    }
    printf("\nObrigado\n");
    return 0;
}
