typedef struct lista * Lista;

#define tam 15
#define max 10

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst,char elem[tam]);
int remove_elem(Lista lst, char elem[tam]);
const char * get_elem_pos(Lista lst,int pos);
Lista esvazia_lista(Lista *lst);
void apaga_lista(Lista *lst);
void mostra_lista(Lista lst);
int insere_elem_pos(Lista lst, int pos, char elem[tam]);
const char * remove_menor(Lista lst);
int tamanho_lista(Lista lst);
Lista concatenar(Lista lst1, Lista lst2);