#ifndef NUMERO_H_INCLUDED
#define NUMERO_H_INCLUDED

typedef struct no * Lista;
int insere_elemento (Lista *lst, double elem);
int remove_elemento (Lista *lst, double elem);
int remove_ocorrencias (Lista *lst, double elem);
Lista cria_lista();
void imprime_lista (Lista lst);
int remove_menor (Lista *lst);
int insere_pos(Lista *lst, double elem, int pos);
int inverte_lista (Lista *lst, Lista *lst2);

#endif // NUMERO_H_INCLUDED
