#include <stdio.h>
#include "lista.h"

int main(){
    Bebida lista;
    int qntd,i,vol,op;
    float preco;
    char nome[tam],c;

    while(1){
        printf("\n\t\t-----------Menu------------\n");
        printf("\n\t\t O que deseja fazer?\n");
        printf("\t\t1: Inicializar uma lista;\n");
        printf("\t\t2: Inserir bebidas;\n");
        printf("\t\t3: Remover uma bebida;\n");
        printf("\t\t4: Imprimir a lista na tela;\n");
        printf("\t\t5: Pegar um elemento pela posicao;\n");
        printf("\t\t6: Esvaziar a lista e voltar para a posicao inicial;\n");
        printf("\t\t7: Encerrar o programa.\n");
        printf("\n\t\tInsira a operacao: ");
        scanf("%d",&op);

        if(op==7)
            break;
        switch(op){
            case 1:
                lista=cria_lista();
                break;
            case 2:
                printf("\nInsira quantas bebidas voce deseja inserir: ");
                scanf("%d",&qntd);

                for(i=0;i<qntd;i++){
                    scanf("%c",&c);
                    printf("\nInsira o nome da bebida: ");
                    scanf("%[^\n]%*c",nome);

                    printf("\nInsira o volume(mL) da bebida: ");
                    scanf("%d",&vol);

                    printf("\nInsira o preco da bebida: ");
                    scanf("%f",&preco);

                    if(insere_ord(lista,nome,vol,preco)==0){
                        fprintf(stderr,"\nNao foi possivel inserir a bebida na lista.\n");
                        break;
                    }
                }
                break;
            case 3:
                scanf("%c",&c);
                printf("\nInsira o nome da bebida que deseja remover: ");
                scanf("%[^\n]%*c",nome);
                
                if(remove_ord(lista,nome)==0)
                    fprintf(stderr,"\nNao foi possivel remover a bebida da lista.\n");
                    
                break;
            case 4:
                mostra_lista(lista);
                break;
            case 5:
                if(get_elem_pos(lista)==0)
                    fprintf(stderr,"\nNao foi possivel pegar a bebida da posicao inserida.\n");
                break;
            case 6:
                lista=cria_lista();
                break;
        }
    }
    printf("\nObrigado!\n");

    apaga_lista(&lista);
    
    return 0;
}