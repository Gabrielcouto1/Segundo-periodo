#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

struct no{
    unsigned int matricula;
    char nome[20];
    float media;
    int faltas;
    struct no *prox;
};

//apaga_lista

Aluno cria_lista(){
    return NULL;
}

int lista_vazia(Aluno lst){
    if(lst==NULL)
        return 1;//Lista vazia
    else
        return 0;//Lista nao vazia
}

int insere_ord(Aluno *lst, unsigned int matricula, char nome[20], float media, int faltas){
    Aluno N=(Aluno)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;//falha

    N->matricula=matricula;
    N->media=media;
    N->faltas=faltas;
    strcpy(N->nome,nome);

    if(lista_vazia(*lst)==1||matricula<=(*lst)->matricula){
        N->prox=*lst;
        *lst=N;
        return 1;//Sucesso
    }

    Aluno aux=*lst;

    while(aux->prox!=NULL&&aux->prox->matricula<matricula)
        aux=aux->prox;

    N->prox = aux->prox;
    aux->prox=N;

    return 1;//Sucesso
}

int remove_ord(Aluno *lst,unsigned int matricula){
    if(lista_vazia(*lst)==1||matricula<(*lst)->matricula)
        return 0;//Falha
    
    Aluno aux=*lst;

    if(matricula==(*lst)->matricula){
        *lst=aux->prox;
        free(aux);
        return 1;//Sucesso
    }

    while(aux->prox!=NULL&&aux->prox->matricula<matricula)
        aux=aux->prox;

    if(aux->prox==NULL||aux->prox->matricula>matricula)
        return 0;//Nao tem na lista
    
    Aluno aux2=aux->prox;
    aux->prox=aux2->prox;
    free(aux2);

    return 1;//Sucesso
}

int get_elem_pos(Aluno lst,int pos, unsigned int *matricula){
    if(lista_vazia(lst)||pos<=0)
        return 0;//Falha

    int cont=1;
    Aluno aux=lst;

    while(aux->prox!=NULL&&cont<pos){
        aux=aux->prox;
        cont++;
    }

    *matricula=aux->matricula;

    return 1;//Sucesso
}

int esvazia_lista(Aluno *lst){
    if(lst==NULL)
        return 0;//Falha

    while(*lst!=NULL){
        Aluno aux=*lst;
        *lst=aux->prox;
        free(aux);
    }

    return 1;//Sucesso
}

void mostra_lista(Aluno lst){
    Aluno aux=lst;

    while(aux!=NULL){
        printf("\nMatricula: %d\t",aux->matricula);
        printf("Nome: %s\t",aux->nome);
        printf("Media: %.2f\t",aux->media);
        printf("Faltas: %d",aux->faltas);
        aux=aux->prox;
    }
}