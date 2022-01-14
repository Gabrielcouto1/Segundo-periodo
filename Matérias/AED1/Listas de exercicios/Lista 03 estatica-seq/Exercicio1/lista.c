#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
    char nome[max][tam];
    int Fim;
};

Lista cria_lista(){
    Lista lst;

    lst = (Lista)malloc(sizeof(struct lista));

    if (lst!=NULL)
        lst->Fim=0;
    
    return lst;
}

int lista_vazia(Lista lst){
    if(lst->Fim==0)
        return 1;//lista vazia

    return 0;//lista nao vazia
}

int lista_cheia(Lista lst){
    if(lst->Fim==max)
        return 1;//lista cheia
    
    return 0;//lista nao cheia
}

int insere_elem(Lista lst, char elem[tam]){
    if(lst==NULL||lista_cheia(lst)==1)
        return 0;//Falha ao criar a lista ou lista cheia

    strcpy(lst->nome[lst->Fim],elem);
    lst->Fim++;

    return 1;//Sucesso
}

int remove_elem(Lista lst, char elem[tam]){
    if(lst==NULL||lista_vazia(lst)==1)
        return 0;//Falha ao criar a lista ou lista vazia
    int i,aux=0;

    while(aux<lst->Fim&&(strcmp(lst->nome[aux],elem))!=0)
        aux++;
    
    if(aux==lst->Fim)
        return 0;//nao existe o elemento inserido
    
    for(i=aux+1;i<lst->Fim;i++)
        strcpy(lst->nome[i-1],lst->nome[i]);
    strcpy(lst->nome[lst->Fim-1],"\0");
    lst->Fim--;
    return 1;//sucesso
}

void mostra_lista(Lista lst){
    int i;
    printf("\nLista completa:\n");
    for(i=0;i<max;i++){
        printf("%s\n",lst->nome[i]);
    }
}

void libera_lista(Lista *lst){
    free(*lst);
    *lst=NULL;
}

Lista esvazia_lista(Lista lst){
    libera_lista(&lst);
    lst=cria_lista();

    return lst;
}

int get_elem_pos(Lista lst){
    int pos;

    printf("\nInsira a posicao que deseja pegar o elemento: ");
    scanf("%d",&pos);

    if(pos>=lst->Fim||pos>max){
        return 0;//Posicao invalida
    }

    printf("\nElemento: %s",lst->nome[pos]);
    return 1;//sucesso
}