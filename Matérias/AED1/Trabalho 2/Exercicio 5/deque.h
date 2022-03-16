typedef struct fila * Fila;

#define max 10
#define tam 20

Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, char elem[tam]);
int remove_ini(Fila f, char elem[]);
int insere_ini(Fila f, char elem[tam]);
int remove_fim(Fila f, char elem[]);
void mostra_fila(Fila f);
void exclui_fila(Fila *f);
Fila apaga_fila(Fila *f);