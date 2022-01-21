#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "lista.h"

struct no{
    char nome[20];
    int vol;
    float preco;
    struct no * prox;
};

Bebida cria_lista(){
    return NULL;
}

int lista_vazia(Bebida lst){
    if(lst==NULL)
        return 1;//Lista vazia
    
    return 0;//Lista nao vazia
}

int insere_elem(Bebida *lst,char nome[20],int vol,float preco){
    Bebida N=(Bebida)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;//No nao foi alocado

    strcpy(N->nome,nome);
    N->vol=vol;
    N->preco=preco;
    N->prox=*lst;
    *lst=N;

    return 1;//Sucesso
}

int remove_ultimo(Bebida *lst){
    if (lista_vazia(*lst)==1)
        return 0;//Falha
    
    Bebida aux=*lst;

    while(aux->prox->prox!=NULL)
        aux=aux->prox;
    
    Bebida aux2=aux->prox;
    aux->prox=aux2->prox;
    free(aux2);

    return 1;
}

void mostra_lista(Bebida *lst){
    Bebida aux=*lst;

    while(aux!=NULL){
        printf("Nome da bebida: %s\t",aux->nome);
        printf("Volume da bebida: %i\t",aux->vol);
        printf("Preco da bebida: %.2f\n",aux->preco);
        aux = aux->prox;
    }
}

int esvazia_lista(Bebida *lst){
    if(lst==NULL)//parametro invalido
        return 0;//Falha
    
    while(*lst!=NULL){
        Bebida aux=*lst;
        *lst=aux->prox;
        free(aux);
    }

    return 1;//Sucesso
}

int apaga_lista(Bebida *lst){
    return (esvazia_lista(lst));
}