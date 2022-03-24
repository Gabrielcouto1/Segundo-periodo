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
    Opera��o cria_fila:

    - Entrada: Nenhuma

    - Pr�-condi��o: Nenhuma

    - Processo: Cria uma fila e a coloca no estado de fila vazia

    - Sa�da: Endere�o da fila criada

    - P�s-condi��o: Nenhuma
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
    Opera��o fila_vazia:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila ser v�lida

    - Processo: Verifica se a fila est� vazia

    - Sa�da: Retorna 1 se ela estiver vazia e 0 caso n�o

    - P�s-condi��o: Nenhuma
*/
int fila_vazia(Fila N)
{
    if (N != NULL && N->cont == 0)
        return 1;
    return 0;
}

/*
    Opera��o fila_cheia:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila ser v�lida

    - Processo: Verifica se a fila est� cheia

    - Sa�da: Retorna 1 se ela estiver cheia e 0 caso n�o

    - P�s-condi��o: Nenhuma
*/
int fila_cheia(Fila N)
{
    if (N != NULL && N->cont == MAX)
        return 1;
    return 0;
}

/*
    Opera��o fila_tam:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila ser v�lida

    - Processo: Calcula o tamanho

    - Sa�da: Retorna o tamanho caso tenha dado certo e -1 caso n�o

    - P�s-condi��o: Nenhuma
*/
int fila_tam(Fila N)
{
    if (N == NULL)
        return -1;

    return N->cont;
}

/*
    Opera��o insere_fim:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila n�o estar cheia

    - Processo: Insere no final da fila

    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o

    - P�s-condi��o: Fila com mais um elemento
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
    Opera��o remove_inicio:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila n�o estar vazia

    - Processo: Remove do in�cio da fila

    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o

    - P�s-condi��o: Fila com menos um elemento
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
    Opera��o apaga_fila:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila ser v�lida

    - Processo: Apaga a Fila

    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o

    - P�s-condi��o: Fila apagada
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
    Opera��o esvazia_fila:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila ser v�lida e n�o estar vazia

    - Processo: Esvazia a fila

    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o

    - P�s-condi��o: Fila vazia
*/
int esvazia_fila(Fila N)
{
    if(N == NULL || fila_vazia(N))
        return 0;

    N->inicio = 0;
    N->cont = 0;
    return 1;
}
