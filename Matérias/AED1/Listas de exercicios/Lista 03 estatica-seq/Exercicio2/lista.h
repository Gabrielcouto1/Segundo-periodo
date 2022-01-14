typedef struct bebidas * Bebida;
#define max 20
#define tam 20

Bebida cria_lista();
int lista_vazia(Bebida bebida);
int lista_cheia(Bebida bebida);
int insere_ord(Bebida bebida,char nome[max],int vol,float preco);
int remove_ord(Bebida bebida, char nome[max]);
int get_elem_pos(Bebida bebida);
Bebida esvazia_lista(Bebida bebida);
void apaga_lista(Bebida *bebida);
void mostra_lista(Bebida bebida);