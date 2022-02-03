#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaex2.h"

int main(){

    int ativo = 0, n = 0;
    Lista lst1,lst2,lst3;
    int x,qtd,pos,i,op;
    char elem[tam];

    while(1){
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("\n[1]: Manipular lista 1;\n");
        printf("[2]: Manipular lista 2;\n");
        printf("[3]: Concatenar as duas listas;\n");
        printf("[4]: Encerrar o programa\n");
        scanf("%d",&op);
        setbuf(stdin, NULL);
        if(op==4)
            break;

        switch(op){
            case 1:
                while(1){
                    printf("\n[1] Criar lista\n");
                    printf("[2] Inserir uma string na lista\n");
                    printf("[3] Remover uma string na lista\n");
                    printf("[4] Imprimir Lista\n");
                    printf("[5] Limpar Lista\n");
                    printf("[6] Apagar Lista\n");
                    printf("[7] Pegar elemento pela posicao\n");
                    printf("[8] Inserir na posicao\n");
                    printf("[9] Remover menor\n");
                    printf("[10] Mostrar tamanho da lista\n");
                    printf("[11] Voltar\n");
                    scanf("%d", &n);
                    setbuf(stdin, NULL);
                    if(n==11)
                        break;

                    switch(n){
                        case 1:
                            lst1 = cria_lista();
                            if(lst1 == NULL){
                                printf("Lista ainda não foi criada\n");
                            }else
                                printf("Lista criada!\n");
                            break;

                        case 2:
                            printf("\nInsira a quantidade de elementos que deseja inserir: ");
                            scanf("%d",&qtd);
                            setbuf(stdin, NULL);

                            for(i=0;i<qtd;i++){
                                printf("\nInsira a string que quer colocar na lista: ");
                                scanf("%[^\n]%*c",elem);
                                setbuf(stdin, NULL);

                                if(insere_elem(lst1,elem)==0)
                                    printf("\nNao foi possivel inserir o elemento");
                                else    
                                    printf("\nO elemento foi inserido!");
                            }

                         break;

                        case 3:
                            printf("\nInsira a string que quer remover da lista: ");
                            scanf("%[^\n]%*c",elem);
                            setbuf(stdin, NULL);

                            if(remove_elem(lst1,elem)==0)
                                printf("\nNao foi possivel remover o elemento");
                            else 
                                printf("\nO elemento foi removido!");
                            break;

                        case 4:
                            mostra_lista(lst1);
                            break;

                        case 5:
                        lst1=esvazia_lista(lst1);
                        if(lst1 == NULL){
                            printf("Lista não foi limpada\n");
                        }else{
                            printf("Lista limpa!\n");
                        }
                            break;

                        case 6:
                        apaga_lista(&lst1);
                        if(lst1 == NULL)
                            printf("Lista apagada!");
                            break;

                        case 7:
                            printf("\nInsira a posicao que deseja pegar o elemnto: ");
                            scanf("%d",&pos);
                            setbuf(stdin, NULL);

                            strcpy(elem,get_elem_pos(lst1,pos));
                            if(strcpy(elem,"\0")==0)
                                printf("\nNao foi possivel pegar o elemento.");
                            else    
                                printf("\nO elemento da posicao %d eh %s.",pos,elem);
                            break;
                        case 8:
                            printf("\nInsira a posicao que deseja inserir o elemnto: ");
                            scanf("%d",&pos);
                            setbuf(stdin, NULL);

                            printf("\nInsira a string que quer colocar na lista: ");
                            scanf("%[^\n]%*c",elem);
                            setbuf(stdin, NULL);

                            if(insere_elem_pos(lst1,pos,elem)==0)
                                printf("\nNao foi possivel inserir o elemento.");
                            else
                                printf("\nO elemento foi inserido.");
                            break;
                        case 9:
                            if(remove_menor(lst1)==0)
                                printf("\nNao foi possivel remover o menor elemento.");
                            else
                                printf("\nO menor elemento foi removido.");
                            break;
                        case 10:
                            printf("\nTamanho da lista: %d",tamanho_lista(lst1));
                            break;
                        default:
                            printf("Opção inválida, selecione uma opção de 1 a 11\n");
                            break;
                    }

                }   
                break;  
            case 2: 
                while(1){
                    printf("\n[1] Criar lista\n");
                    printf("[2] Inserir uma string na lista\n");
                    printf("[3] Remover uma string na lista\n");
                    printf("[4] Imprimir Lista\n");
                    printf("[5] Limpar Lista\n");
                    printf("[6] Apagar Lista\n");
                    printf("[7] Pegar elemento pela posicao\n");
                    printf("[8] Inserir na posicao\n");
                    printf("[9] Remover menor\n");
                    printf("[10] Mostrar tamanho da lista\n");
                    printf("[11] Voltar\n");
                    scanf("%d", &n);
                    setbuf(stdin, NULL);
                    if(n==11)
                        break;

                    switch(n){
                        case 1:
                            lst2 = cria_lista();
                            if(lst2 == NULL){
                                printf("Lista ainda não foi criada\n");
                            }else
                                printf("Lista criada!\n");
                            break;

                        case 2:
                            printf("\nInsira a quantidade de elementos que deseja inserir: ");
                            scanf("%d",&qtd);
                            setbuf(stdin, NULL);

                            for(i=0;i<qtd;i++){
                                printf("\nInsira a string que quer colocar na lista: ");
                                scanf("%[^\n]%*c",elem);
                                setbuf(stdin, NULL);

                                if(insere_elem(lst2,elem)==0)
                                    printf("\nNao foi possivel inserir o elemento");
                                else    
                                    printf("\nO elemento foi inserido!");
                            }

                         break;

                        case 3:
                            printf("\nInsira a string que quer remover da lista: ");
                            scanf("%[^\n]%*c",elem);
                            setbuf(stdin, NULL);

                            if(remove_elem(lst2,elem)==0)
                                printf("\nNao foi possivel remover o elemento");
                            else 
                                printf("\nO elemento foi removido!");
                            break;

                        case 4:
                            mostra_lista(lst2);
                            break;

                        case 5:
                        lst2=esvazia_lista(lst2);
                        if(lst2 == NULL){
                            printf("Lista não foi limpada\n");
                        }else{
                            printf("Lista limpa!\n");
                        }
                            break;

                        case 6:
                        apaga_lista(&lst2);
                        if(lst2 == NULL)
                            printf("Lista apagada!");
                            break;

                        case 7:
                            printf("\nInsira a posicao que deseja pegar o elemnto: ");
                            scanf("%d",&pos);
                            setbuf(stdin, NULL);

                            strcpy(elem,get_elem_pos(lst2,pos));
                            if(strcpy(elem,"\0")==0)
                                printf("\nNao foi possivel pegar o elemento.");
                            else    
                                printf("\nO elemento da posicao %d eh %s.",pos,elem);

                            break;
                        case 8:
                            printf("\nInsira a posicao que deseja inserir o elemnto: ");
                            scanf("%d",&pos);
                            setbuf(stdin, NULL);

                            printf("\nInsira a string que quer colocar na lista: ");
                            scanf("%[^\n]%*c",elem);
                            setbuf(stdin, NULL);

                            if(insere_elem_pos(lst2,pos,elem)==0)
                                printf("\nNao foi possivel inserir o elemento.");
                            else
                                printf("\nO elemento foi inserido.");
                            break;
                        case 9:
                            if(remove_menor(lst2)==0)
                                printf("\nNao foi possivel remover o menor elemento.");
                            else
                                printf("\nO menor elemento foi removido.");
                            break;
                        case 10:
                            printf("\nTamanho da lista: %d",tamanho_lista(lst2));
                            break;
                        default:
                            printf("Opção inválida, selecione uma opção de 1 a 11\n");
                            break;
                    }

                }   
                break; 
            case 3:
                lst3=concatenar(lst1,lst2);
                if(lst3==NULL)
                    printf("\nNao foi possivel concatenar as duas listas.");
                else{
                    printf("\nLista concatenada:\n");
                    mostra_lista(lst3);
                }
                break;
            default:
                printf("\nInsira operacoes de 1 a 4.");
                break;
        }
    }
    printf("\nObrigado\n");
    return 0;
}