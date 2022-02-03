#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

int main(){
    Caractere lista1,lista2,lista3;
    int op,qtd,i,pos,lst;
    char elem,c;

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
                printf("[7]: Remover as vogais;\n");
                printf("[8]: Remover um elemento pela posicao\n");
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
                        scanf("%c",&c);

                        for(i=0;i<qtd;i++){
                            printf("\nInsira o elemento: ");
                            scanf("%c",&elem);
                            scanf("%c",&c);

                            if(insere(lista1,elem)==0)
                                fprintf(stderr,"\nNao foi possivel inserir o elemento.");

                        }

                        break;
                    case 3:
                        printf("\nInsira o elemento que deseja remover da lista: ");
                        scanf("%c",&c);
                        scanf("%c",&elem);
                        scanf("%c",&c);

                        if(remove_elem(lista1,elem)==0)
                            printf("\nNao foi possivel remover o elemento da lista.\n");
                        break;
                    case 4:
                        mostra_lista(lista1);
                        break;
                    case 5:
                        printf("\nTamanho da lista: %d",tamanho_lista(lista1));
                        break;
                    case 6:
                        lista1=esvazia_lista(lista1);
                        if(lista1==NULL)
                            printf("\nNao foi possivel esvaziar a lista.");

                        break;
                    case 7:
                        if(remove_vogal(lista1)==0)
                            printf("\nNao foi possivel remover as vogais.");
                        else
                            printf("\nAs vogais foram removidas.");
                        break;
                    case 8:
                        printf("\nInsira a posicao que deseja remover: ");
                        scanf("%d",&pos);
                        if(remove_elem_pos(lista1,pos)==0)
                            printf("\nNao foi possivel remover o elemento da posicao inserida.");
                        
                        break;
                    case 9:
                        printf("\nInsira a posicao que deseja pegar o elemento: ");
                        scanf("%d",&pos);
                        if(get_elem_pos(lista1,pos,&elem)==0)
                            printf("\nNao foi possivel pegar o elemento dessa posicao.");
                        else    
                            printf("\nO elemento da posicao %d eh %c.",pos,elem);

                        break;
                    default:
                        fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 10 para as operacoes.\n");
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
                printf("[7]: Remover as vogais;\n");
                printf("[8]: Remover um elemento pela posicao\n");
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
                        scanf("%c",&c);

                        for(i=0;i<qtd;i++){
                            printf("\nInsira o elemento: ");
                            scanf("%c",&elem);
                            scanf("%c",&c);

                            if(insere(lista2,elem)==0)
                                fprintf(stderr,"\nNao foi possivel inserir o elemento.");

                        }

                        break;
                    case 3:
                        printf("\nInsira o elemento que deseja remover da lista: ");
                        scanf("%c",&c);
                        scanf("%c",&elem);
                        scanf("%c",&c);

                        if(remove_elem(lista2,elem)==0)
                            printf("\nNao foi possivel remover o elemento da lista.\n");
                        break;
                    case 4:
                        mostra_lista(lista2);
                        break;
                    case 5:
                        printf("\nTamanho da lista: %d",tamanho_lista(lista2));
                        break;
                    case 6:
                        lista2=esvazia_lista(lista2);
                        if(lista2==NULL)
                            printf("\nNao foi possivel esvaziar a lista.");

                        break;
                    case 7:
                        if(remove_vogal(lista2)==0)
                            printf("\nNao foi possivel remover as vogais.");
                        else
                            printf("\nAs vogais foram removidas.");
                        break;
                    case 8:
                        printf("\nInsira a posicao que deseja remover: ");
                        scanf("%d",&pos);
                        if(remove_elem_pos(lista2,pos)==0)
                            printf("\nNao foi possivel remover o elemento da posicao inserida.");
                        
                        break;
                    case 9:
                        printf("\nInsira a posicao que deseja pegar o elemento: ");
                        scanf("%d",&pos);
                        if(get_elem_pos(lista2,pos,&elem)==0)
                            printf("\nNao foi possivel pegar o elemento dessa posicao.");
                        else    
                            printf("\nO elemento da posicao %d eh %c.",pos,elem);

                        break;
                    default:
                        fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 10 para as operacoes.\n");
                        break;
                }
                break;
            case 3:
                lista3=intercalar(lista1,lista2);
                if(lista3==NULL)
                    printf("\nNao foi possivel intercalar as listas.");
                else{
                    printf("\nLista intercalada:\n");
                    mostra_lista(lista3);
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