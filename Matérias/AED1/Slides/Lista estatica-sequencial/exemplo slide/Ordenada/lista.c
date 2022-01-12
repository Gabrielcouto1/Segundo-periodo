#include <stdio.h>
#include <stdlib.h>
#include "listaa.h"

struct lista{
    int no[max];
    int Fim;
};

Lista cria_lista(){
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));

    if (lst != NULL)
        lst->Fim=0;
    
    return lst;
}

int lista_vazia(Lista lst){
    if (lst->Fim==0)
        return 1;
    else 
        return 0;
}

int lista_cheia(Lista lst){
    if(lst->Fim==max)
        return 1;
    else 
        return 0;
}

int insere_ord(Lista lst, int elem){
    if(lst==NULL||lista_cheia(lst)==1)
        return 0;

    if(lista_vazia(lst)==1||elem>=lst->no[lst->Fim-1])
        lst->no[lst->Fim]=elem;
    else{
        int i,aux=0;

        while(elem>=lst->no[aux])
            aux++;

        for(i=lst->Fim;i>aux;i--)
            lst->no[i]=lst->no[i-1];
        lst->no[aux]=elem;
    }
    lst->Fim++;
    return 1;
}

int remove_ord(Lista lst,int elem){
    
    if(lst==NULL||lista_vazia(lst)==1||elem<lst->no[0]||elem>lst->no[lst->Fim-1])
        return 0;
    
    int i,aux=0;

    while(aux<lst->Fim&&lst->no[aux]<elem)
        aux++;
    
    if(aux==lst->Fim||lst->no[aux]>elem)
        return 0;
    
    for(i=aux+1;i<lst->Fim;i++)
        lst->no[i-1]=lst->no[i];
    
    return 1;
}

void mostra_lista(Lista lst){
    int i;
    printf("\n Lista completa:\n\n");
    for(i=0;i<max;i++){
        printf("%d\n",lst->no[i]);
    }
}

void libera_lista(Lista *lst){
    free(*lst);
    *lst=NULL;
}