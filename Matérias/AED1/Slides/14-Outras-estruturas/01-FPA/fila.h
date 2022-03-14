typedef struct no * Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_elem(Fila *f, int elem, int p);
int remove_ini(Fila *f, int *elem);
void mostra_fila(Fila f);