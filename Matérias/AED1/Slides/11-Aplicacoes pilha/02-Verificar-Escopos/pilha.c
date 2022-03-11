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

int verificar_escopo(char elem[]){
    int i;
    char aux;
    Pilha pilha1=cria_pilha();

    for(i=0;elem[i]!='\0';i++){
        if(elem[i]=='{'||elem[i]=='['||elem[i]=='(')
            if(push(&pilha1,elem[i])==0)
                return 0;

        if(elem[i]=='}'||elem[i]==']'||elem[i]==')'){
            if(pop(&pilha1,&aux)==0)
                return 0;
                
            switch(aux){
                case '(':
                    if(elem[i]!=')')
                        return 0;
                    break;
                case '[':
                    if(elem[i]!=']')
                        return 0;
                    break;
                case '{':
                    if(elem[i]!='}')
                        return 0;
                    break;
                default: 
                    break;
            }
        }
    }

    if(pilha_vazia(pilha1)==1)
        return 1;
    else 
        return 0;

}