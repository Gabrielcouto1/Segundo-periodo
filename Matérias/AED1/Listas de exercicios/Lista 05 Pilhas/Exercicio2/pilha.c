#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "pilha.h"

struct no{
    long int matricula;
    char nome[tam];
    char setor;
    float salario;
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

int push(Pilha *p,long int matricula,char nome[tam],char setor,float salario){
    Pilha N=(Pilha)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    
    N->matricula=matricula;
    strcpy(N->nome,nome);
    N->setor=setor;
    N->salario=salario;
    
    N->prox=*p;
    *p=N;

    return 1;
}

const char * pop(Pilha *p,long int *matricula, char *setor, float *salario){
    if(pilha_vazia(*p))
        return "\0";
    
    char *elem;
    elem=malloc(sizeof(char)*tam);

    Pilha aux=*p;

    *matricula=aux->matricula;
    strcpy(elem,aux->nome);
    *setor=aux->setor;
    *salario=aux->salario;

    *p=aux->prox;

    free(aux);
    return elem;
}

const char * le_topo(Pilha *p,long int *matricula, char *setor, float *salario){
    if(pilha_vazia(*p))
        return "\0";

    char *elem;
    elem=malloc(sizeof(char)*tam);
    
    *matricula=(*p)->matricula;
    strcpy(elem,(*p)->nome);
    *setor=(*p)->setor;
    *salario=(*p)->salario;

    return elem;
}

int tam_pilha(Pilha *p){
    if(pilha_vazia(*p)==1)
        return 0;
    
    Pilha aux = *p;
    int tamanho=0;
    
    while(aux!=NULL){
        tamanho++;
        aux=aux->prox;
    }

    return tamanho;
}

Pilha esvazia_pilha(Pilha *p){
    if(*p==NULL)
        return *p;

    apaga_pilha(p);
    *p=cria_pilha();

    return *p;
}

void apaga_pilha(Pilha *p){
    while(*p!=NULL){
        Pilha aux=*p;
        *p=aux->prox;
        free(aux);
    }
}

void mostra_pilha(Pilha *p){
    if(*p==NULL)
        printf("\nA pilha esta vazia");
    
    else{
        Pilha aux=*p;

        while(aux!=NULL){
            printf("(%ld|%s|%c|%.2f)\n",aux->matricula,aux->nome,aux->setor,aux->salario);
            aux = aux->prox;
        }
    }
}