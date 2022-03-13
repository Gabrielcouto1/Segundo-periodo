typedef struct fila * Fila;
#define max 20
Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, int elem);
int remove_ini(Fila f, int *elem);
void mostra_fila(Fila f);
void exclui_fila(Fila *f);
Fila apaga_fila(Fila *f);