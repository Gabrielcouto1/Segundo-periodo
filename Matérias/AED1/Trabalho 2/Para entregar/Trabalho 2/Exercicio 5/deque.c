#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

struct fila{
    char info[max][tam];
    int ini,fim;
};

Fila cria_fila(){
    Fila f;
    f=(Fila)malloc(sizeof(struct fila));

    if(f!=NULL){
        f->ini=max-1;
        f->fim=max-1;
        int i;
        for(i=0;i<max;i++)
            strcpy(f->info[i],"\0");
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

int insere_fim(Fila f, char elem[tam]){
    if(f==NULL||fila_cheia(f))
        return 0;

    f->fim=(f->fim+1)%max;
    strcpy(f->info[f->fim],elem);

    return 1;
}

int remove_ini(Fila f, char elem[]){
    if(f==NULL||fila_vazia(f))
        return 0;

    f->ini=(f->ini+1)%max;
    strcpy(elem,f->info[f->ini]);
    strcpy(f->info[f->ini],"\0");

    return 1;
}

int insere_ini(Fila f, char elem[tam]){
    if(f==NULL||fila_cheia(f))
        return 0;

    strcpy(f->info[f->ini],elem);
    f->ini=(f->ini-1)%max;

    return 1;
}

int remove_fim(Fila f, char elem[]){
    if(f==NULL||fila_vazia(f))
        return 0;

    strcpy(elem,f->info[f->fim]);
    strcpy(f->info[f->fim],"\0");
    f->fim=(f->fim-1)%max;

    return 1;
}

void mostra_fila(Fila f){
    if(f==NULL||fila_vazia(f))
        printf("\nA fila esta vazia.");
    else{
        int i;
        for(i=0;i<max;i++)
            printf("\n%s",f->info[i]);
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
