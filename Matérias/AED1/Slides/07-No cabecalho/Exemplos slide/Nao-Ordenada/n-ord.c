#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no * prox;
};

Lista cria_lista(){
    Lista cab;

    cab = (Lista)malloc(sizeof(struct no));     //Aloca no cabecalho
    
    if(cab!=NULL){
        cab->prox = NULL;   //Coloca lista no estade de vazio, se a alocacao nao falhar
        cab->info = 0;  //Opcional: guardar qtde
    }

    return cab;
}

int lista_vazia(Lista lst){
    if(lst->prox==NULL)
        return 1;//Lista vazia

    return 0;
}

int insere_elem(Lista *lst,int elem){
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;//No nao alocado
    
    N->info = elem;//Insere o conteudo
    N->prox = lst->prox;//Aponta para o primeiro no da lista
    lst->prox = N;//Faz o no cabecalho apontar para o novo no

    lst->info++;//Opcional: incrementa qtde de nos na lista

    return 1;
}

int remove_elem(Lista *lst,int elem){
    if(lista_vazia(*lst))
        return 0;//Falha

    Lista aux = *lst;//Ponteiro para o no cabecalho

    if(elem==(*lst)->info){
        *lst=aux->prox;//Lista aponta para o segundo no
        free(aux);//libera memoria alocada
        return 1;//Sucesso
    }

    while(aux->prox!=NULL&&aux->prox->info!=elem)
        aux = aux->prox;

    if(aux->prox==NULL)
        return 0;//Nao foi possivel encontrar o elemento

    Lista aux2 = aux->prox;//Aponta no a ser removido
    aux->prox = aux2->prox;//Retira no da lista
    free(aux2);//Libera memoria

    *lst->info--;//Decrementa qtd de nos

    return 1;//Sucesso
}

int tam_lista(Lista lst){
    return lst->info;
}

void mostra_lista(Lista lst){
    Lista aux=lst->prox;

    while(aux!=NULL){
        printf("\n%d",lst->info);
        aux=aux->prox;
    }
}

int esvazia_lista(Lista *lst){
    if(lst==NULL)
        return 0;//parametro invalido

    while(*lst!=NULL){
        Lista aux = *lst;
        *lst = aux->prox;
        free(aux);
    }
    return 1;
}

int get_elem_pos(Lista lst, int pos, int *elem){
    if(lista_vazia||pos<=0||pos>lst->info)
        return 0;

    int cont=1;
    Lista aux = lst;

    while(aux->prox!=NULL&&cont<pos){
        aux = aux->prox;
        cont++;
    }
    *elem = aux->info;

    return 1;//Sucesso
}