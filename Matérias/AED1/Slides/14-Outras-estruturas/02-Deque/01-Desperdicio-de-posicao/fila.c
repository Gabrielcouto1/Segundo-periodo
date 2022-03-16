#include <stdio.h> 
#include <stdlib.h> 
#include "fila.h"

struct fila{
    int vetor[max];
    int ini,fim;
};

Fila cria_fila(){
    Fila f;
    f=(Fila)malloc(sizeof(struct fila));

    if(f!=NULL){
        f->ini=max-1;
        f->fim=max-1;
    }

    return f;
}

int fila_vazia(Fila f){
    if(f==NULL||f->ini==f->fim)
        return 1;
    return 0;
}

int fila_cheia(Fila f){
    if(f==NULL)
        return 0;
    if(f->ini==(f->fim+1)%max)
        return 1;
    return 0;
}

int insere_fim(Fila f, int elem){
    if(f==NULL||fila_cheia(f)==1)
        return 0;

    f->fim=(f->fim+1)%max;
    f->vetor[f->fim]=elem;

    return 1;
}

int remove_ini(Fila f, int *elem){
    if(f==NULL||fila_vazia(f)==1)
        return 0;

    f->ini=(f->ini+1)%max;
    *elem=f->vetor[f->ini];
    f->vetor[f->ini]=0;

    return 1;
}

int insere_ini(Fila f, int elem){
    if(f==NULL||fila_cheia(f))
        return 0;

    f->vetor[f->ini]=elem;
    f->ini=(f->ini-1)%max;

    return 1;
}

int remove_fim(Fila f, int *elem){
    if(f==NULL||fila_vazia(f))
        return 0;

    *elem=f->vetor[f->fim];
    f->vetor[f->fim]=0;
    f->fim=(f->fim-1)%max;

    return 1;
}

void mostra_fila(Fila f){
    if(f==NULL||fila_vazia(f))
        printf("\nA fila esta vazia.");
    else{
        int i;
        for(i=0;i<max;i++)
            printf("\n%d",f->vetor[i]);
    }
}

void exclui_fila(Fila *f){
    free(*f);
    *f=NULL;
}

Fila apaga_fila(Fila *f){
    exclui_fila(f);
    return cria_fila();
}