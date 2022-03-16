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
        N->prox=N;
        *lst=N;
    }
    else{
        N->prox=(*lst)->prox;
        (*lst)->prox=N;
        *lst=N;
    }
    return 1;
}

int insere_inicio(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;
    
    if(*lst==NULL){
        N->info=elem;
        N->prox=N;
        *lst=N;
    }
    else{
        N->info=elem;
        N->prox=(*lst)->prox;
        (*lst)->prox=N;
    }

    return 1;
}

int remove_inicio(Lista *lst,int *elem){
    if(lista_vazia(*lst)==1)
        return 0;
    
    Lista aux=(*lst)->prox;
    *elem=aux->info;
    if(*lst==(*lst)->prox)
        *lst=NULL;
    else
        (*lst)->prox=aux->prox;
    free(aux);
    return 1;
}

int remove_final(Lista *lst, int *elem){
    if(lst==NULL||lista_vazia(*lst))
        return 0;

    Lista aux=(*lst)->prox;

    while(aux->prox!=(*lst))
        aux=aux->prox;
    
    *elem=aux->prox->info;

    aux->prox=(*lst)->prox;
    (*lst)=aux;

    return 1;    
}

void mostra_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        printf("\nA lista esta vazia.\n");

    else{
        Lista aux=lst->prox;
        do{
            printf("%d\n",aux->info);
            aux=aux->prox;
        }while(aux!=lst->prox);
    }
}