#include <stdlib.h>
#include <string.h>
#include "fila.h"
#define MAX 5
#define STR 31

struct fila
{
    Carro elem[MAX];
    int inicio, cont;
};

Fila cria_fila()
{
    Fila N = (Fila)malloc(sizeof(struct fila));
    if (N != NULL)
    {
        N->inicio = 0;
        N->cont = 0;
    }
    return N;
}

int fila_vazia(Fila N)
{
    if (N != NULL && N->cont == 0)
        return 1;
    return 0;
}

int fila_cheia(Fila N)
{
    if (N != NULL && N->cont == MAX)
        return 1;
    return 0;
}

int fila_tam(Fila N)
{
    if (N == NULL)
        return -1;

    return N->cont;
}

int insere_fim(Fila fi, Carro A)
{
    if (fila_cheia(fi))
        return 0;

    strcpy(fi->elem[(fi->inicio+fi->cont) % MAX].placa, A.placa);
    fi->elem[(fi->inicio+fi->cont) % MAX].servico = A.servico;
    fi->elem[(fi->inicio+fi->cont) % MAX].hora = A.hora;
    fi->cont++;
    return 1;
}

int remove_inicio(Fila fi, Carro *A)
{
    if (fila_vazia(fi))
        return 0;

    strcpy(A->placa, fi->elem[fi->inicio].placa);
    A->servico = fi->elem[fi->inicio].servico;
    A->hora = fi->elem[fi->inicio].hora;

    fi->inicio = (fi->inicio + 1) % MAX;
    fi->cont--;
    return 1;
}


int apaga_fila(Fila *N)
{
    if(N == NULL)
        return 0;

    free(*N);
    *N = NULL;
    return 1;
}


int esvazia_fila(Fila N)
{
    if(N == NULL || fila_vazia(N))
        return 0;

    N->inicio = 0;
    N->cont = 0;
    return 1;
}
