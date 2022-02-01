#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

struct no{
    int info;
    struct no * prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst==NULL)
        return 1;//Lista vazia

    return 0;
}

int insere_final(Lista *lst,int elem){
    Lista N= (Lista)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    N->info=elem;

    if(lista_vazia(*lst)==1){
        N->prox=N;//Faz o novo no apontar para ele mesmo
        *lst=N;//Faz a lista apontar para o novo no(ultimo no)
    }
    else{
        N->prox=(*lst)->prox;//Faz o novo apontar o primeiro no
        (*lst)->prox=N;//Faz o ultimo no apontar para o novo no
        *lst=N;//Faz a lista apontar para o novo no(ultimo no)
    }
    return 1;//Sucesso
}

int remove_inicio(Lista *lst,int *elem){
    if(lista_vazia(*lst)==1)
        return 0;//Falha
    
    Lista aux=(*lst)->prox;
    *elem=aux->info;//Retorna valor do no a ser reemovido
    if(*lst==(*lst)->prox)
        *lst=NULL;
    else
        (*lst)->prox=aux->prox;
    free(aux);
    return 1;
}

void mostra_lista(Lista lst){
    Lista aux=lst;

    while(aux!=lst){
        aux=lst;
        printf("%d\n",aux->info);
        aux=aux->prox;
    }
}

int get_elem_pos(Lista lst,int pos, int *elem){
    if(lista_vazia(lst)||pos<=0)
        return 0;

    int cont=1;
    Lista aux;

    while(aux->prox!=lst&&cont<pos){
        aux=lst
    }
}