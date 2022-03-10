#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no{
    int info;
    struct no * prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p==NULL)
        return 1;

    return 0;
}

int push(Pilha *p, int elem){
    Pilha N=(Pilha)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    
    N->info=elem;
    N->prox=*p;
    *p=N;

    return 1;
}

int pop(Pilha *p, int *elem){
    if(pilha_vazia(*p))
        return 0;
    
    Pilha aux=*p;

    *elem=aux->info;
    *p=aux->prox;

    free(aux);

    return 1;
}   

int le_topo(Pilha *p, int *elem){
    if(pilha_vazia(*p))
        return 0;
    
    *elem=(*p)->info;

    return 1;
}

void mostra_pilha(Pilha p){
    if(pilha_vazia(p))
        printf("\nA pilha esta vazia.");

    else{
        Pilha aux=p;
        printf("\n");
        while(aux!=NULL){
            printf("%d\n",aux->info);
            aux=aux->prox;
        }
    }
}

int decimal_binario(int num){
    if(num<0)
        return 0;

    Pilha binario=cria_pilha();
    int res;

    while(num!=0){
        res=num%2;
        if(push(&binario,res)==0)
            return 0;
        num/=2;
    }
    
    printf("Numero decimal: %d\nNumero binario: ",num);
    
    while(binario!=NULL){
        printf("%d",binario->info);
        binario=binario->prox;
    }
    return 1;
}