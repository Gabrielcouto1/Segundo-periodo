#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

struct no{
    int info;
    struct no * prox;
    struct no * ant;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst==NULL)
        return 1;
    return 0;
}

int insere_elemento(Lista *lst, int elem){
    Lista N=(Lista)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    
    N->info=elem;

    N->ant=NULL;

    N->prox=*lst;
        
    if(lista_vazia(*lst)==0)
        (*lst)->ant=N;
    *lst=N;

    return 1;
}

int remove_elemento(Lista *lst,int elem){
    if(lista_vazia(*lst))
        return 0;

    Lista aux=*lst;

    while(aux->prox!=NULL&&aux->info!=elem)
        aux=aux->prox;
    
    if(aux->info!=elem)
        return 0;
    
    if(aux->prox!=NULL)
        aux->prox->ant=aux->ant;
    if(aux->ant!=NULL)
        aux->ant->prox=aux->prox;
    if(aux==*lst)
        *lst=aux->prox;

    free(aux);
    return 1;
}

void mostra_lista(Lista *lst){
    if(*lst==NULL||lista_vazia(*lst))
        printf("\nA lista esta vazia.");
    else{   
        Lista aux;
        while(*lst!= NULL){
            aux=*lst;
            *lst=(*lst)->prox;
        }
        while(aux!=NULL){
            printf("%d\n",aux->info);
            aux=aux->ant;
        }
    }
}