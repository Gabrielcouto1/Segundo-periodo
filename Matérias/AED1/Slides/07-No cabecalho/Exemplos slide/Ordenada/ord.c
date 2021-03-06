#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

struct no{
    int info;
    struct no * prox;
};

Lista cria_lista(){
    Lista cab;

    cab = (Lista)malloc(sizeof(struct no));     //Aloca no cabecalho
    
    if(cab!=NULL){
        cab->prox = NULL;   //Coloca lista no estade de vazio, se a alocacao nao falhar
        cab->info = 0;  //Opcional: guardar qtde
    }

    return cab;
}

int lista_vazia(Lista lst){
    if(lst->prox==NULL)
        return 1;//Lista vazia

    return 0;
}

int insere_ord(Lista *l,int elem){
    Lista N,aux;

    N=(Lista)malloc(sizeof(struct no));

    if (N==NULL)
        return 0;

    N->info = elem;
    aux = *l;

    while (aux->prox!=NULL&&(aux->prox)->info<elem)
        aux=aux->prox;

    N->prox=aux->prox;
    aux->prox=N;
    (*l)->info++;

    return 1;
}

int remove_ord(Lista *lst,int elem){
    if(lista_vazia(*lst)==1)
        return 0;

    Lista N,aux;
    N=*lst;

    while(N->prox!=NULL&&(N->prox)->info<elem)
        N=N->prox;

    if(N->prox==NULL||(N->prox)->info<elem)
        return 0;

    aux=N->prox;
    N->prox=aux->prox;
    free(aux);
    (*lst)->info--;

    return 1;
}

int tam_lista(Lista lst){
    return lst->info;
}

void mostra_lista(Lista lst){
    Lista aux=lst->prox;

    while(aux!=NULL){
        printf("\n%d",aux->info);
        aux=aux->prox;
    }
}

int esvazia_lista(Lista *lst){
    if(lst==NULL)
        return 0;//parametro invalido

    while(*lst!=NULL){
        Lista aux = *lst;
        *lst = aux->prox;
        free(aux);
    }
    return 1;
}

int get_elem_pos(Lista lst, int pos, int *elem){
    if(lista_vazia(lst)||pos<=0||pos>tam_lista(lst))
        return 0;

    int cont=1;
    Lista aux = lst;

    while(aux->prox!=NULL&&cont<pos){
        aux = aux->prox;
        cont++;
    }
    *elem = aux->info;

    return 1;//Sucesso
}