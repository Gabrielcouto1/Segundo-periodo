typedef struct fila * Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, int elem);
int remove_ini(Fila f, int *elem);
void mostra_fila(Fila f);
int exclui_fila(Fila *f);
Fila apaga_fila(Fila *f);