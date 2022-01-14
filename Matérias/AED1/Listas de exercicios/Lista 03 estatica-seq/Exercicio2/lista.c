#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct bebidas{
    char nome[max][tam];
    int volume[max];
    float preco[max];
    int Fim,qtd;
};

Bebida cria_lista(){
    Bebida bebida;

    bebida=(Bebida)malloc(sizeof(struct bebidas));

    if(bebida!=NULL){
        bebida->Fim=0;
        bebida->qtd=0;
    }

    return bebida;
}

int lista_vazia(Bebida bebida){
    if(bebida->Fim==0)
        return 1;//a lista esta vazia
    
    return 0;//nao esta vazia
}

int lista_cheia(Bebida bebida){
    if(bebida->Fim==max)
        return 1;//a lista esta cheia

    return 0;//a lista nao esta cheia
}

int insere_ord(Bebida bebida,char nome[max],int vol,float preco){
    if(bebida==NULL||lista_cheia(bebida)==1)
        return 0;
    
    if(lista_vazia(bebida)==1||(strcmp(nome,bebida->nome[bebida->Fim-1])>0)||(strcmp(nome,bebida->nome[bebida->Fim-1])==0)){
        strcpy(bebida->nome[bebida->Fim],nome);
        bebida->volume[bebida->Fim]=vol;
        bebida->preco[bebida->Fim]=preco;
    }

    else{
        int i,aux=0;

        while(strcmp(nome,bebida->nome[aux])>0||strcmp(nome,bebida->nome[aux])==0){
            aux++;
        }
        
        for(i=bebida->Fim;i>aux;i--){
            strcpy(bebida->nome[i],bebida->nome[i-1]);
            bebida->volume[i]=bebida->volume[i-1];
            bebida->preco[i]=bebida->preco[i-1];
        }
        strcpy(bebida->nome[aux],nome);
        bebida->volume[aux]=vol;
        bebida->preco[aux]=preco;
    }
    bebida->Fim++;
    bebida->qtd++;

    return 1;    
}

int remove_ord(Bebida bebida, char nome[max]){
    if(bebida==NULL||lista_vazia(bebida)==1||strcmp(nome,bebida->nome[0])<0||strcmp(nome,bebida->nome[bebida->Fim-1])>0)
        return 0;
    
    int i,aux=0;

    while(aux<bebida->Fim&&strcmp(nome,bebida->nome[aux])>0)
        aux++;
    
    if(aux==bebida->Fim||strcmp(bebida->nome[aux],nome)>0)
        return 0;
    
    for(i=aux+1;i<bebida->Fim;i++){
        strcpy(bebida->nome[i-1],bebida->nome[i]);
        bebida->volume[i-1]=bebida->volume[i];
        bebida->preco[i-1]=bebida->preco[i];
    }

    strcpy(bebida->nome[bebida->Fim-1],"\0");
    bebida->volume[bebida->Fim-1]=0;
    bebida->preco[bebida->Fim-1]=0;

    return 1;
}

int get_elem_pos(Bebida bebida){
    int pos;

    printf("\nInsira a posicao que deseja pegar o elemento: ");
    scanf("%d",&pos);

    if(pos>=bebida->Fim||pos>max)
        return 0;//Posicao invalida
    

    printf("\n\t\t\tNome da bebida:   %s",bebida->nome[pos]);
    printf("\n\t\t\tVolume da bebida: %d",bebida->volume[pos]);
    printf("\n\t\t\tPreco da bebida:  %.2f",bebida->preco[pos]);
    printf("\n");
    return 1;//sucesso
}

Bebida esvazia_lista(Bebida bebida){
    apaga_lista(&bebida);
    bebida=cria_lista();

    return bebida;
}

void apaga_lista(Bebida *bebida){
    free(*bebida);
    *bebida=NULL;
}

void mostra_lista(Bebida bebida){
    int i;
    printf("\n");
    for(i=0;i<max;i++){
        printf("\tNome da bebida numero %d: %s",i,bebida->nome[i]);
        printf("\tVolume da bebida numero %d: %d",i,bebida->volume[i]);
        printf("\tPreco da bebida numero %d: %.2f",i,bebida->preco[i]);
        printf("\n");
    }
}