#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaex2.h"

struct lista{
    char info[max][tam];
    int Fim;
};

Lista cria_lista(){
    Lista lst;

    lst=(Lista)malloc(sizeof(struct lista));

    if(lst!=NULL){
        lst->Fim=0;
    }

    return lst;
}

int lista_vazia(Lista lst){
    if(lst->Fim==0)
        return 1;//a lista esta vazia
    
    return 0;//nao esta vazia
}

int lista_cheia(Lista lst){
    if(lst->Fim==max)
        return 1;//a lista esta cheia

    return 0;//a lista nao esta cheia
}

int insere_elem(Lista lst,char elem[tam]){
    if(lst==NULL||lista_cheia(lst))
        return 0;
    
    strcpy(lst->info[lst->Fim],elem);
    lst->Fim++;

    return 1;   
}

int remove_elem(Lista lst, char elem[tam]){
    //if(lst==NULL||lista_vazia(lst))
    //    return 0;

    int i,aux=0;

    while(aux<lst->Fim&&(strcmp(lst->info[aux],elem)!=0))
        aux++;
    
    //if(aux==lst->Fim)
    //    return 0;

    for(i=aux+1;i<lst->Fim;i++)
        strcpy(lst->info[i-1],lst->info[i]);

    strcpy(lst->info[lst->Fim-1],"\0");
    lst->Fim--;

    return 1;
}

char *get_elem_pos(Lista lst,int pos){
    if(pos>=lst->Fim||pos>max||pos<=0)
        return "\0";//Posicao invalida

    return lst->info[pos];
}

Lista esvazia_lista(Lista lst){
    apaga_lista(&lst);
    lst=cria_lista();

    return lst;
}

void apaga_lista(Lista *lst){
    free(*lst);
    *lst=NULL;
}

void mostra_lista(Lista lst){
    int i;

    for(i=0;i<max;i++){
        if(strcmp(lst->info[i],"\0")!=0)
            printf("%s\n",lst->info[i]);
    }
        
}

int insere_elem_pos(Lista lst, int pos, char elem[tam]){
    if(lst==NULL||pos<=0||pos>max)
        return 0;

    strcpy(lst->info[pos],elem);

    return 1;
}

int remove_menor(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        return 0;

    int i,cont=0;
    char aux[tam];
    strcpy(aux,lst->info[0]);

    for(i=0;i<max;i++)
        if(strcmp(lst->info[i],aux)<0){
            strcpy(aux,lst->info[i]);
            cont++;
        }

    for(i=cont;i<lst->Fim;i++)
        strcpy(lst->info[i-1],lst->info[i]);

    strcpy(lst->info[lst->Fim-1],"\0");
    lst->Fim--;
    
    return 1;
}

int tamanho_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        return 0;
    
    return lst->Fim;
}

Lista concatenar(Lista lst1, Lista lst2){
    if(lst1==NULL||lst2==NULL||lista_vazia(lst1)||lista_vazia(lst2))
        return NULL;

    //if((tamanho_lista(lst1)+tamanho_lista(lst2))>max)
    //    return NULL;

    Lista lst3=cria_lista();
    //if(lst3==NULL)
    //    return NULL;
    int i;

    for(i=0;i<max;i++){
        if(strcpy(lst1->info[i],"\0")!=0)
            if(insere_elem(lst3,lst1->info[i])==0)
                return NULL;
    }

    for(i=0;i<max;i++){
        if(strcpy(lst2->info[i],"\0")!=0)
            if(insere_elem(lst3,lst2->info[i])==0)
                return NULL;
    }

    return lst3;
}