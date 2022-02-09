#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
    char info[max];
    int Fim;
};

Lista cria_lista(){
    Lista lst;

    lst = (Lista)malloc(sizeof(struct lista));

    if(lst!= NULL){
        lst->Fim=0;
        int i;
        for(i=0;i<max;i++)
            lst->info[i]='\0';
    }
    return lst;
}


void apaga_lista(Lista *lst){
    free(*lst);
    *lst=NULL;
}

Lista intercalar(Lista lst1, Lista lst2){
    if(lst1==NULL||lst2==NULL||lst1->Fim==0||lst2->Fim==0)
        return 0;
    
    Lista lst3=cria_lista();
    int i;
    char elem1,elem2;

    for(i=0;i<max;i++){
        elem1=lst1->info[i];
        elem2=lst2->info[i];
        if(elem1!='\0')
            if(insere_elem(lst3,elem1)==0)
                return NULL;
            
        if(elem2!='\0')
            if(insere_elem(lst3,elem2)==0)
                return NULL;
    }   

    return lst3;
}

int insere_elem(Lista lst, char elem){
    if(lst==NULL||lst->Fim==max) 
        return 0;

    lst->info[lst->Fim]=elem;
    lst->Fim++;

    return 1;
}

void mostra_lista(Lista car){
    if(car==NULL)
        printf("\nA lista esta vazia.");
    else{
        int i;
        for(i=0;i<max;i++)
                if(car->info[i]!='\0')
                    printf("%c\n",car->info[i]);
    }
}