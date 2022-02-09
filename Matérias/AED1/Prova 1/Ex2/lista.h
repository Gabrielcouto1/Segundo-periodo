typedef struct lista * Lista;
#define max 30

Lista cria_lista();
void apaga_lista(Lista *lst);
int insere_elem(Lista lst, char elem);
Lista intercalar(Lista lst1, Lista lst2);
void mostra_lista(Lista car);