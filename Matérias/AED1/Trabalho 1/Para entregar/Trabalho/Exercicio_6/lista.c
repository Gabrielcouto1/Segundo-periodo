#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
    double info;
    struct no * prox;
    struct no * ant;
};

/*  cria_lista()
Entrada: Nenhuma

Pre-Condicao: Nenhuma

Processo: Retorna NULL para uma lista

Saida: NULL

Pos-condicao: Nenhuma

*/

Lista cria_lista() {
    return NULL;
}

/*  lista_vazia(Lista lst)
Entrada: Uma lista

Pre-Condicao: Nenhuma

Processo: Verifica se a lista eh NULL

Saida: 1 se tiver vazia e 0 se nao estiver vazia

Pos-Condicao: Nenhuma

*/

int lista_vazia (Lista lst) {
    if (lst == NULL)
        return 1;
    else
        return 0;

}

/*  insere_elemento (Lista *lst, double elem)
Entrada: Ponteiro para uma lista e um numero double

Pre-Condicao: Lista ser valida

Processo: Insere elemento no final da lista

Saida: 0 - se falha

Pos-Condicao: Lista aponta para novo no

*/

int insere_elemento (Lista *lst, double elem) {
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N->info=elem;
    N->ant=NULL;
    N->prox=*lst;

    if(lista_vazia(*lst) == 0)
        (*lst)->ant=N;

    *lst = N;
    return 1;
}

/* remove_elemento (Lista *lst, double elem)
Entrada: Ponteiro para uma lista e um numero double

Pre-Condicao: Lista ser valida, nao vazia

Processo: Percorrer a lista ate encontrar o elemento
desejado ou chegar ao seu final. Se o elemento
existe, remova-o da lista.

Saida: 0 - se falha

Pos-Condicao: Lista de entrada com um elemento a menos

*/

int remove_elemento (Lista *lst, double elem) {
    if (lista_vazia(*lst))
        return 0;
    Lista aux = *lst;

    while(aux->prox!=NULL&&aux->info!=elem)
        aux = aux->prox;

    if(aux->info!=elem)
        return 0;

    if(aux->prox!=NULL)
        (aux)->prox->ant=aux->ant;

    if(aux->ant!=NULL)
        (aux)->ant->prox=aux->prox;

    if(aux==*lst)
        *lst=aux->prox;

    free(aux);
    return 1;
}

/* imprime_lista (Lista lst)
Entrada: Uma lista

Pre-Condicao: A lista nao deve estar vazia

Processo: Verifica as pre-condicoes. Em seguida, percorre cada no da lista e imprime a informacao
de cada um na tela.

Saida: Nenhuma

Pos-Condicao: Nenhuma

*/

void imprime_lista (Lista lst) {
    //if(lista_vazia(lst) == 1)
      //  printf("A lista esta vazia!\n");

    {
        while (lst != NULL) {
            printf("%.2f\n", lst->info);
            lst = lst->prox;
        }
    printf("\n");
    }
}

/* remove_ocorrencias (Lista *lst, double elem)
Entrada: Ponteiro para uma lista e um numero double

Pre-Condicao: Lista ser valida, nao vazia

Processo: Percorrer a lista ate encontrar o elemento
desejado e suas ocorrencias ou chegar ao seu final. Se o elemento
existe, remove todas suas ocorrencias e os remove

Saida: 0 - se falha

Pos-Condicao: Lista de entrada os elementos a menos

*/

int remove_ocorrencias (Lista *lst, double elem) {
    if(lista_vazia(*lst))
        return 0;
    Lista aux = *lst;

    while(aux != NULL){
        while(aux->prox!=NULL&&aux->info!=elem)
            aux=aux->prox;
        Lista aux2 = aux;

        if(aux2->info!=elem)
            return 0;

        if(aux2->prox!=NULL)
            (aux2)->prox->ant=aux2->ant;

        if(aux2->ant!=NULL)
            (aux2)->ant->prox=aux2->prox;

        if(aux2==*lst)
            *lst = aux2->prox;

        aux=aux->prox;
        free(aux2);
    }

    free(aux);
    return 1;
}

/* remove_menor (Lista *lst)
Entrada: Ponteiro para uma lista e um numero double

Pre-Condicao: Lista ser valida, nao vazia

Processo: Percorrer a lista comparando os elementos ate encontrar
o menor, assim o remove.

Saida: 1 - se sucesso

Pos-Condicao: Lista de entrada com o menor elemento a menos.

*/

int remove_menor (Lista *lst) {
    if (lista_vazia(*lst))
        return 0;

    Lista aux = *lst;
    double menor = aux->info;
    Lista aux2 = aux;

    while(aux->prox!=NULL){
        if(menor>aux->info){
            menor=aux->info;
            aux2=aux;
        }
        aux = aux->prox;
    }

    if(aux2->prox!=NULL)
        (aux2)->prox->ant=aux2->ant;

    if(aux2->ant != NULL)
        (aux2)->ant->prox=aux2->prox;

    if(aux2==*lst)
        *lst=aux2->prox;

    free(aux2);
    return 1;
}

/* insere_pos(Lista *lst, double elem, int pos)
Entrada: Ponteiro para uma lista, um numero double e uma posicao

Pre-Condicao: Lista ser valida, nao vazia

Processo: Percorre a lista ate a posicao ser encontrada,
caso seja, elemento eh inserido

Saida: 0 - se falha

Pos-Condicao: Lista retorna 1 se sucesso.

*/

int insere_pos(Lista *lst, double elem, int pos) {
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N->info = elem;

    Lista aux = *lst;
    if(lista_vazia(*lst) == 1) return 0;

    if(pos == 0){
        N->ant = NULL;
        N->prox = aux;
        *lst = N;
        return 1;
    }

    while(aux->prox != NULL && pos > 0) {
        aux=aux->prox;
        pos--;
    }

    if(pos > 0) return 0;

    aux->ant->prox = N;

    N->ant = aux->ant;
    aux->ant = N;
    N->prox = aux;

    return 1;
}

/* inverte_lista (Lista *lst, Lista *lst2)
Entrada: Ponteiro para uma lista e um numero double

Pre-Condicao: Lista ser valida, nao vazia

Processo: Percorrer a lista ate encontrar o elemento
desejado ou chegar ao seu final. Se o elemento
existe, remova-o da lista.

Saida: 0 - se falha

Pos-Condicao: Lista de entrada com um elemento a menos

*/

Lista inverte_lista (Lista *lst) {
    if(*lst==NULL)
        return NULL;

    Lista lst2=cria_lista();
    Lista aux = *lst;
    while(aux != NULL){
        Lista N = (Lista) malloc(sizeof(struct no));

        if (N == NULL)
            return NULL;

        N->info = aux->info;
        N->ant = NULL;
        N->prox = lst2;

        if (lista_vazia(lst2) == 0)
            (lst2)->ant = N;

        lst2 = N;
        aux=aux->prox;
    }
    return lst2;
}
