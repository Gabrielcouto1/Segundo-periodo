#include <stdlib.h>
#include "pilha.h"

struct no{
    char info;
    struct no * prox;
};

Pilha cria_pilha(){
    return NUll;
}

int pilha_vazia(Pilha p){
    if(p==NULL)
        return 1;
    return 0;
}

int push(Pilha *p,char elem){
    Pilha N=(Pilha)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    
    N->info=elem;
    N->prox=*p;
    *p=N;

    return 1;
}

int pop(Pilha *p,char *elem){
    if(pilha_vazia(*p))
        return 0;
    
    Pilha aux=*p;
    *elem=aux->info;
    *p=aux->prox;

    free(aux);
    return 1;
}

int le_topo(Pilha *p, char *elem){
    if(pilha_vazia(*p))
        return 0;
    
    *elem=(*p)->info;

    return 1;
}

int apaga_pilha(Pilha *p){
    if(*p==NULL)
        return 0;
    
    while(*p!=NULL){
        Pilha aux=*p;
        *p=aux->prox;
        free(aux);
    }

    return 1;
}