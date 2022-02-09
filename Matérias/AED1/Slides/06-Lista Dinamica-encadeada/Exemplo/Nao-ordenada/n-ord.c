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
        return 1;
    
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
    if (lista_vazia(*lst)==1)
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

void mostra_lista(Lista *lst){
    Lista aux=*lst;

    while(aux!=NULL){
        printf("%d\n",aux->info);
        aux = aux->prox;
    }
}

int tam_lista(Lista *lst){
    if(lista_vazia(*lst)==1)
        return 0;
    
    Lista aux = *lst;
    int tam=0;
    
    while(aux!=NULL){
        tam++;
        aux=aux->prox;
    }

    return tam;
}

int esvazia_lista(Lista *lst){
    if(lst==NULL)//parametro invalido
        return 0;//Falha
    
    while(*lst!=NULL){
        Lista aux=*lst;
        *lst=aux->prox;
        free(aux);
    }

    return 1;//Sucesso
}

int apaga_lista(Lista *lst){
    return (esvazia_lista(lst));
}

int get_elem_pos(Lista lst, int pos, int *elem){
    if(lista_vazia(lst)||pos<=0||pos>tam_lista(&lst))
        return 0;//Falha

    int cont=1;
    Lista aux=lst;

    while(aux->prox!=NULL&&cont<pos){
        aux=aux->prox;
        cont++;
    }

    *elem=aux->info;
    return 1;//Sucesso
}

int remove_ultimopar(Lista *lst,int *elem){
    if(*lst==NULL)
        return 0;
    
    Lista aux=*lst;
    int par;
    
    par=aux->info;

    while(aux!=NULL){
        if((aux->info%2)==0){
            par=aux->info;
            *elem=par;
        }
        aux=aux->prox;
    }

    if(remove_elem(lst,par))
}