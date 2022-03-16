#include <stdlib.h> 
#include "lista.h"

struct no{
    double info;
    struct no * prox;
};

Fila cria_deque(){
    return NULL;
}

int deque_vazio(Fila f){
    if(f==NULL)
        return 1;//Lista vazia

    return 0;
}

int insere_final(Fila *f,double elem){
    Fila N=(Fila)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    N->info=elem;

    if(deque_vazio(*f)==1){
        N->prox=N;
        *f=N;
    }
    else{
        N->prox=(*f)->prox;
        (*f)->prox=N;
        *f=N;
    }
    return 1;
}

int insere_inicio(Fila *f, double elem){
    Fila N=(Fila)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;
    
    if(*f==NULL){
        N->info=elem;
        N->prox=N;
        *f=N;
    }
    else{
        N->info=elem;
        N->prox=(*f)->prox;
        (*f)->prox=N;
    }

    return 1;
}

int remove_inicio(Fila *f,double *elem){
    if(deque_vazio(*f)==1)
        return 0;
    
    Fila aux=(*f)->prox;
    *elem=aux->info;
    if(*f==(*f)->prox)
        *f=NULL;
    else
        (*f)->prox=aux->prox;
    free(aux);
    return 1;
}

int remove_final(Fila *f, double *elem){
    if(lst==NULL||deque_vazio(*f))
        return 0;

    Fila aux=(*f)->prox;

    while(aux->prox!=(*f))
        aux=aux->prox;
    
    *elem=aux->prox->info;

    aux->prox=(*f)->prox;
    (*f)=aux;

    return 1;    
}

int apaga_deque(Fila *f){
    if(*f==NULL)
        return 0;
    
    while(*f!=NULL){
        Lista aux=*f;
        *f=aux->prox;
        free(aux);
    }
    return 1;
}