typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *l,float elem);
int remove_ord(Lista *lst,float elem);
float tam_lista(Lista lst);
void mostra_lista(Lista lst);
int esvazia_lista(Lista *lst);
int get_elem_pos(Lista lst, int pos, float *elem);
float remove_posicao(Lista *lst, int pos);
int iguais(Lista lst1, Lista lst2);
Lista intercala(Lista lst1,Lista lst2);