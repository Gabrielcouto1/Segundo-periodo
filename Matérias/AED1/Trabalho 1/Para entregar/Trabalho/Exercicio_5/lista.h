typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int tamanho_lista(Lista lst);
int insere_final(Lista *lst,int elem);
int insere_inicio(Lista *lst, int elem);
int remove_inicio(Lista *lst,int *elem);
int remove_final(Lista *lst, int *elem);
void mostra_lista(Lista lst);
int insere_elem_pos(Lista *lst, int pos, int elem);
int remove_elem(Lista *lst, int elem);
int remove_pares(Lista *lst);
