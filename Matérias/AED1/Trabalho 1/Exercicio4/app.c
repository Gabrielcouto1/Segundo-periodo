#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    Lista lista1,lista2,lista3,lista4,lista5;
    int op,qtd,i,pos,lst,elem;
    

    while (1){
        printf("\n---------------Menu---------------\n");
                printf("\n     O que deseja fazer?\n");
                printf("[1]: Manipular lista 1;\n");
                printf("[2]: Manipular lista 2;\n");
                printf("[3]: Intercalar;\n");
                printf("[4]: Encerrar o programa\n");
        scanf("%d",&lst);
        if(lst==4)
            break;

        switch(lst){
            case 1:
                printf("\n---------------Menu---------------\n");
                printf("\n     O que deseja fazer?\n");
                printf("[1]: Criar uma lista;\n");
                printf("[2]: Inserir elementos na lista;\n");
                printf("[3]: Remover um elemento da lista;\n");
                printf("[4]: Mostrar a lista na tela;\n");
                printf("[5]: Mostrar o tamanho da lista;\n");
                printf("[6]: Esvaziar a lista;\n");
                printf("[7]: Remover o maior elemento da lista;\n");
                printf("[8]: Inverter a lista;\n");
                printf("[9]: Pegar o elemento pela posicao;\n");
                printf("[10]: Voltar.\n");
                printf("\tInsira a operacao: ");
                scanf("%d",&op);
                printf("\n----------------------------------\n");
                if(op==10)
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
                            scanf("%d",&elem);

                            if(insere_elem(&lista1,elem)==0)
                                fprintf(stderr,"\nNao foi possivel inserir o elemento.");

                        }

                        break;
                    case 3:
                        printf("\nInsira o elemento que deseja remover da lista: ");
                        scanf("%d",&elem);

                        if(remove_elem(&lista1,elem)==0)
                            printf("\nNao foi possivel remover o elemento da lista.\n");
                        break;
                    case 4:
                        mostra_lista(&lista1);
                        break;
                    case 5:
                        printf("\nTamanho da lista: %d",tam_lista(lista1));
                        break;
                    case 6:
                        if(esvazia_lista(&lista1)==0)
                            printf("\nNao foi possivel esvaziar a lista.");

                        break;
                    case 7:
                        if(remove_maior(&lista1)==0)
                            printf("\nNao foi possivel remover o elemento.");
                        else
                            printf("\nO elemento foi removido.");
                        break;
                    case 8:
                        lista3=(inverter(lista1));
                        if(lista3==NULL)
                            printf("\nNao foi possivel inverter a lista.");
                        else{
                            printf("\nLista invertida: \n");
                            mostra_lista(&lista3);
                        }
                        break;
                    case 9:
                        printf("\nInsira a posicao que deseja pegar o elemento: ");
                        scanf("%d",&pos);
                        if(get_elem_pos(lista1,pos,&elem)==0)
                            printf("\nNao foi possivel pegar o elemento dessa posicao.");
                        else    
                            printf("\nO elemento da posicao %d eh %d.",pos,elem);

                        break;
                    default:
                        fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                        break;
                }
                break;
            case 2:
                printf("\n---------------Menu---------------\n");
                printf("\n     O que deseja fazer?\n");
                printf("[1]: Criar uma lista;\n");
                printf("[2]: Inserir elementos na lista;\n");
                printf("[3]: Remover um elemento da lista;\n");
                printf("[4]: Mostrar a lista na tela;\n");
                printf("[5]: Mostrar o tamanho da lista;\n");
                printf("[6]: Esvaziar a lista;\n");
                printf("[7]: Remover o maior elemento da lista;\n");
                printf("[8]: Inverter a lista;\n");
                printf("[9]: Pegar o elemento pela posicao;\n");
                printf("[10]: Voltar.\n");
                printf("\tInsira a operacao: ");
                scanf("%d",&op);
                printf("\n----------------------------------\n");
                if(op==10)
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
                            scanf("%d",&elem);

                            if(insere_elem(&lista2,elem)==0)
                                fprintf(stderr,"\nNao foi possivel inserir o elemento.");

                        }

                        break;
                    case 3:
                        printf("\nInsira o elemento que deseja remover da lista: ");
                        scanf("%d",&elem);

                        if(remove_elem(&lista2,elem)==0)
                            printf("\nNao foi possivel remover o elemento da lista.\n");
                        break;
                    case 4:
                        mostra_lista(&lista2);
                        break;
                    case 5:
                        printf("\nTamanho da lista: %d",tam_lista(lista2));
                        break;
                    case 6:
                        if(esvazia_lista(&lista2)==0)
                            printf("\nNao foi possivel esvaziar a lista.");

                        break;
                    case 7:
                        if(remove_maior(&lista2)==0)
                            printf("\nNao foi possivel remover o elemento.");
                        else
                            printf("\nO elemento foi removido.");
                        break;
                    case 8:
                        lista4=(inverter(lista2));
                        if(lista4==NULL)
                            printf("\nNao foi possivel inverter a lista.");
                        else{
                            printf("\nLista invertida: \n");
                            mostra_lista(&lista4);
                        }
                        break;
                    case 9:
                        printf("\nInsira a posicao que deseja pegar o elemento: ");
                        scanf("%d",&pos);
                        if(get_elem_pos(lista2,pos,&elem)==0)
                            printf("\nNao foi possivel pegar o elemento dessa posicao.");
                        else    
                            printf("\nO elemento da posicao %d eh %d.",pos,elem);

                        break;
                    default:
                        fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 5 para as operacoes.\n");
                        break;
                }
                break;
            case 3:
                lista5=intercalar(lista1,lista2);
                if(lista5==NULL)
                    printf("\nNao foi possivel intercalar as listas.");
                else{
                    printf("\nLista intercalada:\n");
                    mostra_lista(&lista5);
                }
                break;
            default:
                printf("\nInsira operadores de 1 a 4.");
                break;
        }
        
    }
    printf("\nObrigado!\n");

    return 1;
}