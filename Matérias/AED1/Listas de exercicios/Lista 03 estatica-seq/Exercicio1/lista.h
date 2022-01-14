typedef struct lista * Lista;
#define max 20
#define tam 11

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, char elem[tam]);
int remove_elem(Lista lst, char elem[tam]);
void mostra_lista(Lista lst);
void libera_lista(Lista *lst);
Lista esvazia_lista(Lista lst);
int get_elem_pos(Lista lst);