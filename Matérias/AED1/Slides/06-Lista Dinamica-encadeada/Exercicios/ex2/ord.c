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
        return 1;
    
    return 0;
}

int insere_ord(Lista *lst,int elem){
    Lista N= (Lista) malloc(sizeof(struct no));

    if(N==NULL)
        return 0;//No nao alocado(falha)
    
    N->info=elem;
    if(lista_vazia(*lst)||elem<=(*lst)->info){
        N->prox=*lst;//Aponta para o primeiro no atual da lista
        *lst=N;//Faz a lista apontar para o novo no
        return 1;//Sucessi
    }
    
    Lista aux=*lst;
    while(aux->prox!=NULL&&aux->prox->info<elem)
        aux=aux->prox;

    N->prox=aux->prox;
    aux->prox=N;

    return 1;//Sucesso
}

int remove_ord(Lista *lst,int elem){
    if(lista_vazia(*lst)==1||elem<(*lst)->info)
        return 0;//Falha
    
    Lista aux=*lst;

    if(elem==(*lst)->info){
        *lst=aux->prox;
        free(aux);
        return 1;//Sucesso
    }
    
    while(aux->prox!=NULL&&aux->prox->info<elem)
        aux=aux->prox;
    
    if(aux->prox==NULL||aux->prox->info>elem)
        return 0;//Falha
    
    Lista aux2=aux->prox;
    aux->prox=aux2->prox;
    free(aux2);

    return 1;//Sucesso
}

void mostra_lista(Lista *lst){
    Lista aux=*lst;

    while(aux!=NULL){
        printf("%d\n",aux->info);
        aux = aux->prox;
    }
}

int tam_lista(Lista *lst){
    if(lista_vazia(*lst)==1)
        return 0;
    
    Lista aux = *lst;
    int tam=0;
    
    while(aux!=NULL){
        tam++;
        aux=aux->prox;
    }

    return tam;
}

int esvazia_lista(Lista *lst){
    if(lst==NULL)//parametro invalido
        return 0;//Falha
    
    while(*lst!=NULL){
        Lista aux=*lst;
        *lst=aux->prox;
        free(aux);
    }

    return 1;//Sucesso
}

int apaga_lista(Lista *lst){
    return (esvazia_lista(lst));
}

int get_elem_pos(Lista lst, int pos, int *elem){
    if(lista_vazia(lst)||pos<=0||pos>tam_lista(&lst))
        return 0;//Falha

    int cont=1;
    Lista aux=lst;

    while(aux->prox!=NULL&&cont<pos){
        aux=aux->prox;
        cont++;
    }

    *elem=aux->info;
    return 1;//Sucesso
}
