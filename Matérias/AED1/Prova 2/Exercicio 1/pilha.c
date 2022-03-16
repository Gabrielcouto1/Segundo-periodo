#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha{
    char vetor[max];
    int topo;
};

Pilha cria_pilha(){
    Pilha p;
    p=(Pilha)malloc(sizeof(struct pilha));

    if(p!=NULL)
        p->topo=-1;
    
    return p;
}

int pilha_vazia(Pilha p){
    if(p->topo=1)
        return 1;

    return 0;
}

int pilha_cheia(Pilha p){
    if(p->topo==max-1)
        return 1;
    return 0;
}

int push(Pilha p, char elem){
    if(p==NULL||pilha_cheia(p)==1)
        return 0;

    p->topo++;
    p->vetor[p->topo]=elem;
    return 1;
}

int pop(Pilha p, char *elem){
    if(p==NULL||pilha_vazia(p)==1)
        return 0;
    
    *elem=p->vetor[p->topo];
    p->topo--;

    return 1;
}

int inverte_palavras(char elem[]){
    Pilha p1=cria_pilha();
    int i=0;
    char saida[max];

    while(elem[i]!='\0'){
        if(push(p1,elem[i])==0){
            printf("\nNao foi possivel inserir o elemento.");
            return 0;
        }
        i++;
    }

    i=0;

    whila(elem[i]!='\0'){
        if(pop(p1,&saida[i])==0){
            printf("\nNao foi possivel remover o elemento.");
            return 0;
        }
        i++;
    }

    printf("\nPalavras invertidas: %s",saida);

    return 1;
}