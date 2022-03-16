typedef struct fila * Fila;
#define max 20

Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, int matricula,int faltas,float notas,char conceito);
int remove_ini(Fila f, int *matricula,int *faltas, float *notas, char *conceito);
void exclui_fila(Fila *f);
Fila apaga_fila(Fila *f);