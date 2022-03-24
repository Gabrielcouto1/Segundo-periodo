#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct carro
{
    char placa[8], servico;
    time_t hora;
};
typedef struct carro Carro;
typedef struct fila * Fila;

Fila cria_fila();

int fila_vazia(Fila);

int fila_cheia(Fila);

int fila_tam(Fila);

int insere_fim(Fila, Carro);

int remove_inicio(Fila, Carro *);

int apaga_fila(Fila *);

int esvazia_fila(Fila);

#endif // LISTA_H_INCLUDED
