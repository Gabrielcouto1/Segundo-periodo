typedef struct no * Bebida;

Bebida cria_lista();
int lista_vazia(Bebida lst);
int insere_elem(Bebida *lst,char nome[20],int vol,float preco);
int remove_ultimo(Bebida *lst);
void mostra_lista(Bebida *lst);
int esvazia_lista(Bebida *lst);
int apaga_lista(Bebida *lst);