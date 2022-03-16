#include <stdio.h> 
#include <stdlib.h> 
#include "fila.h"

struct no{
    int codigo;
    float valor;
    float percentual;
    char risco;
    struct no * prox;
};

struct fila{
    struct no * ini;
    struct no * fim;
};

Fila cria_fila(){
    Fila f;
    f=(Fila)malloc(sizeof(struct fila));

    if(f!=NULL){
        f->ini=NULL;
        f->fim=NULL;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f==NULL||f->ini==NULL)
        return 1;
    return 0;
}

int insere_fim(Fila f, int codigo, float valor, float percentual, char risco){
    struct no * N;
    N=(struct no *)malloc(sizeof(struct no));
    
    if(N==NULL) 
        return 0;

    N->codigo=codigo;
    N->valor=valor;
    N->percentual=percentual;
    N->risco=risco;
    N->prox=NULL;

    if(fila_vazia(f))
        f->ini=N;
    else 
        (f->fim)->prox=N;

    f->fim=N;

    return 1;
}

int remove_ini(Fila f, int *codigo, float *valor, float *percentual, char *risco){
    if(f==NULL||fila_vazia(f))
        return 0;

    struct no * aux=f->ini;
    *codigo=aux->codigo;
    *valor=aux->valor;
    *percentual=aux->percentual;
    *risco=aux->risco;

    if(f->ini==f->fim)
        f->fim==NULL;
    
    f->ini=aux->prox;
    free(aux);

    return 1;
}

void mostra_fila(Fila f){
    if(fila_vazia(f))
        printf("\nA fila esta vazia.");
    else{
        struct no * aux=f->ini;
        while(aux!=NULL){
            printf("\n%d",aux->info);
            aux=aux->prox;
        }
    }
}

int exclui_fila(Fila *f){
    if(*f==NULL)
        return 0;
    while(*f!=NULL){
        int elem;
        struct no * aux=(*f)->ini;
        if(remove_ini(*f,&elem)==0)
            break;
        aux=aux->prox;
    }
    return 1;
}

Fila apaga_fila(Fila *f){
    exclui_fila(f);
    return cria_fila();
}