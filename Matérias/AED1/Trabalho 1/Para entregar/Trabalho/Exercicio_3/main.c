#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista lista1=NULL,lista2=NULL,lista3=NULL;
    int op,qtd,i,pos,lst;
    float elem,tam;

    while (1){
        printf("\n---------------Menu---------------\n");
                printf("\n     O que deseja fazer?\n");
                printf("[1]: Manipular lista 1;\n");
                printf("[2]: Manipular lista 2;\n");
                printf("[3]: Comparar 2 listas;\n");
                printf("[4]: Encerrar o programa\n");
        scanf("%d",&lst);
        if(lst==4)
            break;

        switch(lst){
            case 1:
                while(1){
                    printf("\n---------------Menu---------------\n");
                    printf("\n     O que deseja fazer?\n");
                    printf("[1]: Criar uma lista;\n");
                    printf("[2]: Inserir elementos na lista;\n");
                    printf("[3]: Remover um elemento da lista;\n");
                    printf("[4]: Mostrar a lista na tela;\n");
                    printf("[5]: Mostrar o tamanho da lista;\n");
                    printf("[6]: Esvaziar a lista;\n");
                    printf("[7]: Pegar um elemento pela posicao;\n");
                    printf("[8]: Remover um elemento pela posicao;\n");
                    printf("[9]: Voltar.\n");
                    printf("\tInsira a operacao: ");
                    scanf("%d",&op);
                    printf("\n----------------------------------\n");
                    if(op==9)
                        break;

                    switch(op){
                        case 1:
                            lista1=cria_lista();
                            printf("\n\t\t\tA lista foi criada com sucesso!");

                            break;
                        case 2:
                            printf("\nInsira a quantidade de elementos que deseja colocar na lista: ");
                            scanf("%d",&qtd);

                            for(i=0;i<qtd;i++){
                                printf("\nInsira o elemento: ");
                                scanf("%f",&elem);

                                if(insere_ord(&lista1,elem)==0)
                                    fprintf(stderr,"\nNao foi possivel inserir o elemento.");

                            }

                            break;
                        case 3:
                            printf("\nInsira o elemento que deseja remover da lista: ");
                            scanf("%f",&elem);

                            if(remove_ord(&lista1,elem)==0)
                                printf("\nNao foi possivel remover o elemento da lista.\n");
                            break;
                        case 4:
                            mostra_lista(lista1);
                            break;
                        case 5:
                            tam=tam_lista(lista2);
                            if(tam==-1)
                                printf("\nNao foi possivel pegar o tamanho da lista.");
                            else
                                printf("\nTamanho da lista: %.0f",tam_lista(lista1));
                            break;
                        case 6:
                            if(esvazia_lista(&lista1)==0)
                                printf("\nNao foi possivel esvaziar a lista.");

                            break;
                        case 7:
                            printf("\nInsira a posicao que deseja pegar o elemento: ");
                            scanf("%d",&pos);
                            if(get_elem_pos(lista1,pos,&elem)==0)
                                printf("\nNao foi possivel pegar o elemento dessa posicao.");
                            else
                                printf("\nO elemento da posicao %d eh %.2f.",pos,elem);

                            break;
                        case 8:
                            printf("\nInsira a posicao que deseja remover: " );
                            scanf("%d",&pos);

                            elem=remove_posicao(&lista1,pos);

                            if(elem==-1)
                                printf("\nNao foi possivel remover o elemento da posicao inserida.");
                            else
                                printf("\nElemento (%.2f) removido com sucesso.",elem);
                            break;
                        default:
                            fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                            break;
                    }
                }

                break;
            case 2:
                while(1){
                    printf("\n---------------Menu---------------\n");
                    printf("\n     O que deseja fazer?\n");
                    printf("[1]: Criar uma lista;\n");
                    printf("[2]: Inserir elementos na lista;\n");
                    printf("[3]: Remover um elemento da lista;\n");
                    printf("[4]: Mostrar a lista na tela;\n");
                    printf("[5]: Mostrar o tamanho da lista;\n");
                    printf("[6]: Esvaziar a lista;\n");
                    printf("[7]: Pegar um elemento pela posicao;\n");
                    printf("[8]: Remover um elemento pela posicao;\n");
                    printf("[9]: Voltar.\n");
                    printf("\tInsira a operacao: ");
                    scanf("%d",&op);
                    printf("\n----------------------------------\n");
                    if(op==9)
                        break;

                    switch(op){
                        case 1:
                            lista2=cria_lista();
                            printf("\n\t\t\tA lista foi criada com sucesso!");

                            break;
                        case 2:
                            printf("\nInsira a quantidade de elementos que deseja colocar na lista: ");
                            scanf("%d",&qtd);

                            for(i=0;i<qtd;i++){
                                printf("\nInsira o elemento: ");
                                scanf("%f",&elem);

                                if(insere_ord(&lista2,elem)==0)
                                    fprintf(stderr,"\nNao foi possivel inserir o elemento.");

                            }

                            break;
                        case 3:
                            printf("\nInsira o elemento que deseja remover da lista: ");
                            scanf("%f",&elem);

                            if(remove_ord(&lista2,elem)==0)
                                printf("\nNao foi possivel remover o elemento da lista.\n");
                            break;
                        case 4:
                            mostra_lista(lista2);
                            break;
                        case 5:
                            tam=tam_lista(lista2);
                            if(tam==-1)
                                printf("\nNao foi possivel pegar o tamanho da lista.");
                            else
                                printf("\nTamanho da lista: %.0f",tam_lista(lista2));
                            break;
                        case 6:
                            if(esvazia_lista(&lista2)==0)
                                printf("\nNao foi possivel esvaziar a lista.");

                            break;
                        case 7:
                            printf("\nInsira a posicao que deseja pegar o elemento: ");
                            scanf("%d",&pos);
                            if(get_elem_pos(lista2,pos,&elem)==0)
                                printf("\nNao foi possivel pegar o elemento dessa posicao.");
                            else
                                printf("\nO elemento da posicao %d eh %.2f.",pos,elem);

                            break;
                        case 8:
                            printf("\nInsira a posicao que deseja remover: " );
                            scanf("%d",&pos);

                            elem=remove_posicao(&lista2,pos);

                            if(elem==-1)
                                printf("\nNao foi possivel remover o elemento da posicao inserida.");
                            else
                                printf("\nElemento (%.2f) removido com sucesso.",elem);
                            break;
                        default:
                            fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                            break;
                    }
                }

                break;
            case 3:
                printf("\n---------------Menu---------------\n");
                printf("\n     O que deseja fazer?\n");
                printf("[1]: Verificar se sao iguais;\n");
                printf("[2]: Intercalar as listas e imprimir na tela;\n");
                printf("[3]: Voltar;\n");
                scanf("%d",&op);

                switch(op){
                    case 1:
                        if(iguais(lista1,lista2)==0)
                            printf("\nAs listas nao sao iguais.");
                        else
                            printf("\nAs listas sao iguais!");
                        break;
                    case 2:
                        lista3=intercala(lista1,lista2);

                        if(lista3==NULL)
                            printf("\nNao foi possivel intercalar as listas.");

                        else{
                            printf("\nLista intercalada: \n");
                            mostra_lista(lista3);
                        }

                        break;
                    default:
                        fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 3 para as operacoes.\n");
                        break;

                }
                break;
            default:
                fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 2 para as listas.\n");
                break;

        }

    }
    printf("\nObrigado!\n");

    return 1;
}
