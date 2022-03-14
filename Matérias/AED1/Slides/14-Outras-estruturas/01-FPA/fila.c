#include <stdio.h> 
#include <stdlib.h> 
#include "fila.h"

struct no{
    int info;
    int prioridade;
    struct no * prox;
};

Fila cria_fila(){
    return NULL;
}

int fila_vazia(Fila f){
    if(f==NULL)
        return 1;
    return 0;
}

//int insere_elem(Fila *f, int elem, int p){
//    Fila N=(Fila)malloc(sizeof(struct no));
//
//    if(N==NULL)
//        return 0;
//
//    N->info=elem;
//    N->prioridade=p;
//    if(fila_vazia(*f)){
//        N->prox=N;
//        *f=N;
//    }
//    else{
//        Fila aux=*f;
//        while(aux->prox!=*f){
//            if(aux->prox->prioridade<=p)
//                break;
//            aux=aux->prox;
//        }
//            aux=aux->prox;
//        N->prox=aux->prox;
//        aux->prox=N;
//    }
//    return 1;
//}

//int insere_elem(Fila *f,int elem,int prioridade){
//    Fila N=(Fila)malloc(sizeof(struct no));
//    if(N==NULL)
//        return 0;
//
//    N->prioridade=prioridade;
//    N->info=elem;
//
//    if(fila_vazia(*f)){
//        N->prox=N;
//        *f=N;
//    }
//    else{
//        Fila aux=(*f)->prox;
//        while(aux->prox!=*f){
//            if(aux->prox->prioridade<prioridade)
//                break;
//            aux=aux->prox;
//        }
//        N->prox=aux->prox;
//        aux->prox=N;
//    }
//
//    return 1;
//}

int insere_elem(Fila *f, int elem, int prioridade)
{
    Fila aux=*f;
    Fila N=(Fila)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;

    N->info=elem;
    N->prioridade=prioridade;

    if (aux==NULL){
        N->prox=N;
        *f=N;
    }
    
    // Case 2 of the above algo
    else if(aux->info>=N->info){
      /* If value is smaller than head's value then
        we need to change prox of last node */
        while(aux->prox!=*f)
            aux=aux->prox;
        aux->prox=N;
        N->prox=*f;
        *f=N;
    }
    
    // Case 3 of the above algo
    else{
      /* Locate the node before the point of insertion */
      while (aux->prox!=*f&&aux->prox->info<N->info)
        aux=aux->prox;
    
      N->prox=aux->prox;
      aux->prox=N;
    }

    return 1;
}

int remove_ini(Fila *f, int *elem){
    if(f==NULL||fila_vazia(*f))
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

void mostra_fila(Fila f){
    if(f==NULL||fila_vazia(f))
        printf("\nA fila esta vazia");
    else{
        Fila aux=f->prox;
        do{
            printf("\n%d",aux->info);
            aux=aux->prox;
        }while(aux!=f->prox);
    }
}