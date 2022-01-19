#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

struct no{
    int info;
    struct no * prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst==NULL)
        reutrn 1;
    
    return 0;
}

int insere_elem(Lista *lst,int elem){
    Lista N=(Lista)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;//No nao alocado- falha

    N->info=elem;//Insere o valor do elem
    N->prox=*lst;//Aponta para o primeiro no atual da lista
    *lst=N;//Faz a lista apontar para o novo no

    return 1;
}

int remove_elem(Lista *lst,int elem){
    if (lista_vazia(lst)==1)
        return 0;//Falha

    Lista aux=*lst; //Ponteiro aux para o primeiro no 
    //Trata elemento=primeiro no da lista

    if(elem==(*lst)->info){
        *lst=aux->prox;//Lista aponta par ao segundo no 
        free(aux);//Libera memoria
        return 1;
    }
    while(aux->prox!=NULL&&aux->prox->info!=elem)
        aux=aux->prox;//percorrimento ate achar o elemento ou o final da lista
    
    if(aux->prox==NULL) //Trata do final da lista
        return 0;//Falha
    
    Lista aux2=aux->prox;//Aponta o no a ser removido
    aux->prox=aux2->prox;//Retura o no da lista
    free(aux2);//Libera a lista auxiliar

    return 1;//Sucesso
}

//tem que esvaziar a lista e colocar pra imprimir na tela