#include <stdio.h>
#include "lista.h"

int main(){
    Lista lista1;
    int i,elem;

    lista1=cria_lista();

    if(lista1==NULL){
        fprintf(stderr,"\nNao foi possivel criar a lista.\n");
        return 1;
    }

    if(lista_vazia(lista1)==1)
        printf("\nA lista esta vazia.\n");
    else
        printf("\nA lista nao esta vazia\n.");
    
    for(i=0;i<max;i++){
        printf("\nInsira o elemento numero %d:",i+1);
        scanf("%d",&elem);
        insere_elem(lista1,elem);

    }

    if(lista_cheia(lista1)==1)
        printf("\nA lista esta cheia.\n");
    else   
        printf("\nA lista nao esta cheia.\n");
    
    printf("\nInsira um elemento para remover da lista:");
    scanf("%d",&elem);

    remove_elem(lista1,elem);

    mostra_lista(lista1);
    libera_lista(&lista1);

    return 0;
}