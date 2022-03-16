#include <stdlib.h> 
#include "fila.h"

struct fila{
    int faltas[max];
    int matricula[max];
    float notas[max];
    char conceito[max];
    int ini,fim;
};

Fila cria_fila(){
    Fila f;
    f=(Fila)malloc(sizeof(struct fila));

    if(f!=NULL){
        f->ini=0;
        f->fim=0;
    }

    return f;
}

int fila_vazia(Fila f){
    if(f==NULL||f->ini==f->fim)
        return 1;
    return 0;
}

int fila_cheia(Fila f){
    if(f==NULL)
        return 0;
    if(f->ini==(f->fim+1)%max)
        return 1;
    return 0;
}

int insere_fim(Fila f, int matricula,int faltas,float notas,char conceito){
    if(f==NULL||fila_cheia(f)==1)
        return 0;
    
    f->matricula[f->fim]=matricula;
    f->faltas[f->fim]=faltas;
    f->notas[f->fim]=notas;
    f->conceito[f->fim]=conceito;

    f->fim=(f->fim+1)%max;
    return 1;
}

int remove_ini(Fila f, int *matricula,int *faltas, float *notas, char *conceito){
    if(f==NULL||fila_vazia(f)==1)
        return 0;
    
    *matricula=f->matricula[f->ini];
    *faltas=f->faltas[f->ini];
    *notas=f->notas[f->ini];
    *conceito=f->conceito[f->ini];
    f->ini=(f->ini+1)%max;

    return 1;
}

void mostra_fila(Fila f){
    if(f==NULL||fila_vazia(f))
        printf("\nA fila esta vazia.");
    else{
        int i;
        for(i=0;i<f->fim;i++)
            printf("\n%d",f->vetor[i]);
    }
}

void exclui_fila(Fila *f){
    free(*f);
    *f=NULL;
}

Fila apaga_fila(Fila *f){
    exclui_fila(f);
    return cria_fila();
}

Fila elimina_elem(Fila f,int falta){
    Fila f1=f;
    Fila f2=cria_fila();
    int cont=0;
    int matricula_aux;
    int faltas_aux;
    float notas_aux;
    char conceito_aux;

    while(fila_vazia(f1)!=1){
        if(remove_ini(f1,&matricula_aux,&faltas_aux,&notas_aux,&conceito_aux)==0){
            printf("\nNao foi possivel remover um elemento da lista");
            return NULL;
        }
        if(faltas_aux>=falta){
            if(insere_fim(f2,matricula_aux,faltas_aux,notas_aux,conceito_aux)==0){
                printf("\nNao foi possivel inserir um elemnto da lista ");
                return NULL;
            }
        }
        else    
            cont++;
    }
    pritnf("\nForam removidos %d alunos",cont);
    return f2;
}