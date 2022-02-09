#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "lista.h"

struct no {
    int codigo;
    char nome[max];
    float preco;
    struct no * prox;
    struct no * ant;
};

Lista cria_lista(){
    return NULL;
}

int insere_produto(Lista *lst,int codigo, char nome[max],float preco){
    Lista N=(Lista)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;

    N->codigo=codigo;
    strcpy(N->nome,nome);
    N->preco=preco;

    if(*lst==NULL)
        *lst=N;

    else if((*lst)->codigo>=N->codigo){
        N->prox=*lst;
        N->prox->ant=N;
        *lst=N;
    }

    else{
        Lista aux=*lst;
        while(aux->prox!=NULL&&aux->prox->codigo<N->codigo)
            aux=aux->prox;

        N->prox=aux->prox;

        if(aux->prox!=NULL)
            N->prox->ant=N;

        aux->prox=N;
        N->ant=aux;
    }

return 1;

}      
void imprime_lista (Lista lst) {
    if(lst==NULL)
        printf("A lista esta vazia!\n");

    else {
        while (lst != NULL) {
            printf("\n{%d,%s,%.2f}", lst->codigo,lst->nome,lst->preco);
            lst = lst->prox;
        }
    printf("\n");
    }
}

int remove_elemento (Lista *lst, int codigo) {
    if (lista_vazia(*lst))
        return 0;
    Lista aux = *lst;

    while(aux->prox!=NULL&&aux->codigo!=codigo) 
        aux = aux->prox;

    if(aux->codigo!=codigo)
        return 0; 

    if(aux->prox!=NULL)
        (aux)->prox->ant=aux->ant;

    if(aux->ant!=NULL)
        (aux)->ant->prox=aux->prox;

    if(aux==*lst)
        *lst=aux->prox;

    free(aux);
    return 1;
}

int remove_menor(Lista *lst, int *codigo,char *nome[max],float *preco){
    if(*lst==NULL)
        return 0;

    Lista aux=*lst;
    int elem=aux->codigo;

    while (aux != NULL) {
        if(elem>aux->codigo){
            elem=aux->codigo;
            *codigo=aux->codigo;
            *preco=aux->preco;
            strcpy(&nome,aux->nome);
        }
        aux = aux->prox;
    }
    
    if(remove_elemento(lst,elem)==0)
        return 0;
    
    return 1;
}