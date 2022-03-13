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
        f->ini=0;
        f->fim=0;
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
    
    f->vetor[f->fim]=elem;
    f->fim=(f->fim+1)%max;
    return 1;
}

int remove_ini(Fila f, int *elem){
    if(f==NULL||fila_vazia(f)==1)
        return 0;
    
    *elem=f->vetor[f->ini];
    f->vetor[f->ini]=0;
    f->ini=(f->ini+1)%max;

    return 1;
}

void mostra_fila(Fila f){
    if(f==NULL||fila_vazia(f))
        printf("\nA fila esta vazia.");
    else{
        int i;
        for(i=0;i<f->fim;i++)
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