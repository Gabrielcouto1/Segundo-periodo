#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no{
    char info;
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

int push(Pilha *p, char elem){
    Pilha N=(Pilha)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    
    N->info=elem;
    N->prox=*p;
    *p=N;

    return 1;
}

int pop(Pilha *p, char *elem){
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

void mostra_pilha(Pilha p){
    if(pilha_vazia(p))
        printf("\nA pilha esta vazia.");

    else{
        Pilha aux=p;
        printf("\n");
        while(aux!=NULL){
            printf("%c\n",aux->info);
            aux=aux->prox;
        }
    }
}

int infixa_posfixa(char elem[]){
    int i,cont=0;
    char *saida;
    Pilha pilha1=cria_pilha();

    for(i=0;elem[i]!='\0';i++){
        if(elem[i]=='('||elem[i]=='['||elem[i]=='{')
            continue;

        if((elem[i]>='0'&&elem[i]<='9')||(elem[i]>='A'&&elem[i]<='Z')||(elem[i]>='a'&&elem[i]<='z')){
            saida[cont]=elem[i];
            cont++;
        }

        if(elem[i]=='-'||elem[i]=='+'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
            if(push(&pilha1,elem[i])==0)
                return 0;
            
        if(elem[i]==')'||elem[i]==']'||elem[i]=='}'){
            if(pop(&pilha1,&saida[cont])==0)
                return 0;
            else    
                cont++;
        }
    }

    if(pilha_vazia(pilha1)==1){
        printf("\nA expressao foi convertida com sucesso.\n");
        printf("\nForma infixa: %s",elem);
        printf("\nForma pos-fixa: %s",saida);
        return 1;
    }
    
    else
        return 0;
}