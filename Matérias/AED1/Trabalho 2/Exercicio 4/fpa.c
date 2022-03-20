#include <stdio.h> 
#include <stdlib.h> 
#include "fpa.h"

struct no {
    struct paciente pcnt;
    struct no * prox;
};

Fila cria_fila(){
    return NULL;
}

int fila_vazia(Fila f){
    if(f==NULL)
        return 1;
    return 0;
}

int insere_paciente(Fila *f, struct paciente elem){
    Fila N=(Fila)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;

    N->pcnt=elem;

    if(fila_vazia(*f)){
        N->prox=N;
        *f=N;
    }
    else{
        Fila aux=*f;

        while(aux->prox!=(*f)&&aux->prox->pcnt.gravidade>elem.gravidade)
            aux=aux->prox;
        
        if(aux->prox==(*f)&&aux->prox->pcnt.gravidade>elem.gravidade){
            aux=aux->prox;
            N->prox=aux->prox;
            aux->prox=N;
            *f=N;
        }
        else{
            N->prox=aux->prox;
            aux->prox=N;
        }
    }

    return 1;
}

int remove_paciente(Fila *f,struct paciente *elem){
    if(fila_vazia(*f))
        return 0;

    Fila aux=(*f)->prox;
    *elem=aux->pcnt;

    if((*f)==(*f)->prox)
        *f=NULL;
    else    
        (*f)->prox=aux->prox;

    free(aux);
    return 1;
}

int exclui_fila(Fila *f){
    if((*f)==NULL||fila_vazia(*f))
        return 0;
    struct paciente elem;

    while(remove_paciente(f,&elem)!=0);
    
    return 1;
}

Fila apaga_fila(Fila *f){
    exclui_fila(f);
    return cria_fila();
}

void mostra_fila(Fila f){
    if(fila_vazia(f))
        printf("\nA fila esta vazia");
    else{
        Fila aux=f->prox;
        do{
            mostra_paciente(aux->pcnt);
            aux=aux->prox;
        }while(aux!=f->prox);
    }
    
}

void mostra_paciente(struct paciente elem){
    printf("\n----------------------------\n");
    printf("\nNome:%s",elem.nome);
    printf("\nIdade:%d anos",elem.idade);
    printf("\nPeso:%.2f Kg",elem.peso);
    printf("\nAltura:%.2f m",elem.altura);
    switch(elem.doenca){
        case 'C':
            printf("\nDoenca: Cardiaca");
            break;
        case 'N':
            printf("\nDoenca: Neurologica");
            break;
        case 'S':
            printf("\nDoenca: Sanguinea");
            break;
        case 'R':
            printf("\nDoenca: Respiratoria");
            break;
        default:
            printf("\nDoenca desconhecida");
            break;
    }
    printf("\nGravidade:%d",elem.gravidade);
}