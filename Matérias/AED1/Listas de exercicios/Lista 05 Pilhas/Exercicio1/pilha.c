#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "pilha.h"

struct pilha{
    char info[tam][max];
    int topo;
};

Pilha cria_pilha(){
    Pilha p;
    p=(Pilha)malloc(sizeof(struct pilha));

    if(p!=NULL){
        p->topo=-1;
        int i;
        for(i=0;i<max;i++)
            strcpy(p->info[i],"\0");
    }

    return p;
}

int pilha_vazia(Pilha p){
    if(p->topo==-1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha p){
    if(p->topo==max-1)
        return 1;
    return 0;
}

int push(Pilha p, char elem[tam]){
    if(p==NULL||pilha_cheia(p)==1)
        return 0;
    printf("\n%d\n",p->topo);
    p->topo++;
    printf("\n%d\n",p->topo);
    strcpy(p->info[p->topo],elem);

    return 1;
}

const char * pop(Pilha p){
    if(p==NULL)
        return "\0";
        
    char *elem;

    strcpy(elem,p->info[p->topo]);
    p->topo--;

    return elem;
}

const char * le_topo(Pilha p){
    if(p==NULL)
        return "\0";
        
    char *elem;

    strcpy(elem,p->info[p->topo]);

    return elem;
}

void apaga_pilha(Pilha *p){
    if(*p==NULL)  
        return;

    else{
        free(*p);
        *p=NULL;
    }
}

Pilha esvazia_pilha(Pilha *p){
    if(*p==NULL)
        return cria_pilha();
    apaga_pilha(p);

    *p=cria_pilha();

    return *p;
}

int tamanho_pilha(Pilha p){
    if(p==NULL)
        return -1;

    return p->topo+1;
}

void imprime_pilha(Pilha p){
    if(p==NULL||pilha_vazia(p))
        printf("\nA pilha esta vazia.");

    else{
        int i;
        for(i=p->topo;i>=0;i--)
            printf("\n%s",p->info[i]);
    }
}