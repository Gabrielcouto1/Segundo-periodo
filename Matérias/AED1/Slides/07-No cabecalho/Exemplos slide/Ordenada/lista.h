typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst,int elem);
int remove_ord(Lista *lst,int elem);
int tam_lista(Lista lst);
void mostra_lista(Lista lst);
int esvazia_lista(Lista *lst);
int get_elem_pos(Lista lst, int pos, int *elem);