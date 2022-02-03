#include "numero.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
    double info;
    struct no * prox;
    struct no * ant;
};



Lista cria_lista() {
    return NULL;
}
typedef struct no * Lista;

int lista_vazia (Lista lst) {
    if (lst == NULL)
        return 1;
    else
        return 0;

}

int insere_elemento (Lista *lst, double elem) {
    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) { return 0; } // Falha: nó não alocado
    N->info = elem; // Insere o conteúdo (valor do elem)
    N->ant = NULL; // Não tem antecessor do novo nó
    N->prox = *lst; // Sucessor do novo nó recebe mesmo end. da lista
    if (lista_vazia(*lst) == 0) // Se lista NÃO vazia
    (*lst)->ant = N; // Faz o antecessor do 1o nó ser o novo nó
    *lst = N; // Faz a lista apontar para o novo nó
    return 1;
}


int remove_elemento (Lista *lst, double elem) {
    if (lista_vazia(*lst)) // Trata lista vazia
    return 0;
    Lista aux = *lst; // Faz aux apontar para 1o nó

    while (aux->prox != NULL && aux->info != elem) aux = aux->prox;
    if (aux->info != elem) return 0; // Elemento não está na lista
    if (aux->prox != NULL) (aux)->prox->ant = aux->ant;
    if (aux->ant != NULL) (aux)->ant->prox = aux->prox;
    if (aux == *lst) *lst = aux->prox;
    free(aux); return 1;
}

void imprime_lista (Lista lst) {
if (lista_vazia(lst) == 1)
    printf("A lista esta vazia!\n");
else {
    while (lst != NULL) {
        printf("%.2f ", lst->info);
        lst = lst->prox;
    }
    printf("\n");
}
}

int remove_ocorrencias (Lista *lst, double elem) {
    if (lista_vazia(*lst)) // Trata lista vazia
    return 0;
    Lista aux = *lst; // Faz aux apontar para 1o nó

    while(aux != NULL){ // Ler até o final da lista
    while (aux->prox != NULL && aux->info != elem) aux = aux->prox;
    Lista aux2 = aux;
    if (aux2->info != elem) return 0; // Elemento não está na lista
    if (aux2->prox != NULL) (aux2)->prox->ant = aux2->ant;
    if (aux2->ant != NULL) (aux2)->ant->prox = aux2->prox;
    if (aux2 == *lst) *lst = aux2->prox;
    aux=aux->prox; //Faz apomtar para o proximo no
    free(aux2);
    }
     // Aponta no a ser removido
    //free(aux2)
    free(aux);
    return 1;


}

int remove_menor (Lista *lst) {
    if (lista_vazia(*lst)) // Trata lista vazia
    return 0;
    Lista aux = *lst; // Faz aux apontar para 1o nó
    double menor = aux->info;
    Lista aux2 = aux;
    while (aux->prox != NULL ){

        if(menor > aux->info){
            menor = aux->info;
            aux2 = aux;
        }
        aux = aux->prox;
    }
    //printf("aq%fqw", menor);

    if (aux2->prox != NULL) (aux2)->prox->ant = aux2->ant;
    if (aux2->ant != NULL) (aux2)->ant->prox = aux2->prox;
    if (aux2 == *lst) *lst = aux2->prox;
    free(aux2); return 1;
}

int insere_pos(Lista *lst, double elem, int pos) {
    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) { return 0; } // Falha: nó não alocado
    N->info = elem; // Insere o conteúdo (valor do elem)

    Lista aux = *lst;
    if(lista_vazia(*lst) == 1) return 0;

    if(pos == 0){ //Inserindo na primeira posição
        N->ant = NULL;
        N->prox = aux;
        *lst = N;
        return 1;
    }

    while(aux->prox != NULL && pos > 0) { //Percorrendoa lista para achar a posição a inserir
        aux=aux->prox;
        pos--;
    }
    if(pos > 0) return 0;//posição não existe

    aux->ant->prox = N; //proximo do no anterior aponta para o novo nó

    N->ant = aux->ant; // anterior do novo nó, aponta para o nó anterior
    aux->ant = N; // anterior do nó atual, aponta para o novo nó
    N->prox = aux; // próximo do novo nó recebe o nó atual

    //free(aux);
    return 1;
}

int inverte_lista (Lista *lst, Lista *lst2) {
    // Aloca um novo nó e preenche campo info
    Lista aux = *lst;
    while(aux != NULL){
        Lista N = (Lista) malloc(sizeof(struct no));
        if (N == NULL) { return 0; } // Falha: nó não alocado
        N->info = aux->info; // Insere o conteúdo (valor do elem)
        N->ant = NULL; // Não tem antecessor do novo nó
        N->prox = *lst2; // Sucessor do novo nó recebe mesmo end. da lista
        if (lista_vazia(*lst2) == 0){ // Se lista NÃO vazia
            (*lst2)->ant = N;
        } // Faz o antecessor do 1o nó ser o novo nó
        *lst2 = N; // Faz a lista apontar para o novo nó
        aux=aux->prox;
    }

    return 1;
}

