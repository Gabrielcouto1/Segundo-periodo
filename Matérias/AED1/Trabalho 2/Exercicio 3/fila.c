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

/*
    Operação cria_fila:

    - Entrada: Nenhuma

    - Pré-condição: Nenhuma

    - Processo: Cria uma fila e a coloca no estado de fila vazia

    - Saída: Endereço da fila criada

    - Pós-condição: Nenhuma
*/
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

/*
    Operação fila_vazia:

    - Entrada: Endereço da fila

    - Pré-condição: Fila ser válida

    - Processo: Verifica se a fila está vazia

    - Saída: Retorna 1 se ela estiver vazia e 0 caso não

    - Pós-condição: Nenhuma
*/
int fila_vazia(Fila N)
{
    if (N != NULL && N->cont == 0)
        return 1;
    return 0;
}

/*
    Operação fila_cheia:

    - Entrada: Endereço da fila

    - Pré-condição: Fila ser válida

    - Processo: Verifica se a fila está cheia

    - Saída: Retorna 1 se ela estiver cheia e 0 caso não

    - Pós-condição: Nenhuma
*/
int fila_cheia(Fila N)
{
    if (N != NULL && N->cont == MAX)
        return 1;
    return 0;
}

/*
    Operação fila_tam:

    - Entrada: Endereço da fila

    - Pré-condição: Fila ser válida

    - Processo: Calcula o tamanho

    - Saída: Retorna o tamanho caso tenha dado certo e -1 caso não

    - Pós-condição: Nenhuma
*/
int fila_tam(Fila N)
{
    if (N == NULL)
        return -1;

    return N->cont;
}

/*
    Operação insere_fim:

    - Entrada: Endereço da fila

    - Pré-condição: Fila não estar cheia

    - Processo: Insere no final da fila

    - Saída: Retorna 1 caso tenha dado certo e 0 caso não

    - Pós-condição: Fila com mais um elemento
*/
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

/*
    Operação remove_inicio:

    - Entrada: Endereço da fila

    - Pré-condição: Fila não estar vazia

    - Processo: Remove do início da fila

    - Saída: Retorna 1 caso tenha dado certo e 0 caso não

    - Pós-condição: Fila com menos um elemento
*/
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

/*
    Operação apaga_fila:

    - Entrada: Endereço da fila

    - Pré-condição: Fila ser válida

    - Processo: Apaga a Fila

    - Saída: Retorna 1 caso tenha dado certo e 0 caso não

    - Pós-condição: Fila apagada
*/
int apaga_fila(Fila *N)
{
    if(N == NULL)
        return 0;

    free(*N);
    *N = NULL;
    return 1;
}

/*
    Operação esvazia_fila:

    - Entrada: Endereço da fila

    - Pré-condição: Fila ser válida e não estar vazia

    - Processo: Esvazia a fila

    - Saída: Retorna 1 caso tenha dado certo e 0 caso não

    - Pós-condição: Fila vazia
*/
int esvazia_fila(Fila N)
{
    if(N == NULL || fila_vazia(N))
        return 0;

    N->inicio = 0;
    N->cont = 0;
    return 1;
}
