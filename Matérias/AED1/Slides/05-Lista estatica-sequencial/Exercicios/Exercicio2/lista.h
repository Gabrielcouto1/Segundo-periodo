typedef struct lista * Lista;
#define max 20

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, double elem);
int remove_ord(Lista lst, double elem);
void obtem_valor_elem(Lista lst);
void libera_lista(Lista *lst);