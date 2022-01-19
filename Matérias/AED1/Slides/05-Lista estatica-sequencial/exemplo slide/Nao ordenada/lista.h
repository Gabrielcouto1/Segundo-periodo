typedef struct lista * Lista;
#define max 10

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, int elem);
int remove_elem(Lista lst, int elem);
void mostra_lista(Lista lst);
void libera_lista(Lista *lst);