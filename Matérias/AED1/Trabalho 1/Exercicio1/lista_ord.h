typedef struct caracteres * Caractere;
#define max 20

Caractere cria_lista();
int lista_vazia(Caractere car);
int lista_cheia(Caractere car);
int insere(Caractere car, char elem);
int remove_elem(Caractere car, char elem);
void apaga_lista(Caractere *car);
Caractere esvazia_lista(Caractere car);
int get_elem_pos(Caractere car, int pos, char *elem);
int remove_vogal(Caractere car);
int remove_elem_pos(Caractere car, int pos);
int tamanho_lista(Caractere car);
Caractere intercalar(Caractere car1, Caractere car2);
void mostra_lista(Caractere car);