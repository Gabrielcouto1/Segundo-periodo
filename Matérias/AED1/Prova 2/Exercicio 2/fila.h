typedef struct no * Fila;

Fila cria_deque();
int deque_vazio(Fila f);
int insere_final(Fila *f,double elem);
int insere_inicio(Fila *f, double elem);
int remove_inicio(Fila *f,double *elem);
int remove_final(Fila *f, double *elem);
int apaga_deque(Fila *f);