typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst,int elem);
int remove_elem(Lista *lst,int elem);
void mostra_lista(Lista *lst);
int tam_lista(Lista *lst);
int esvazia_lista(Lista *lst);
int apaga_lista(Lista *lst);
int get_elem_pos(Lista lst, int pos, int *elem);
int remove_ultimonegativo(Lista *lst, int *elem);