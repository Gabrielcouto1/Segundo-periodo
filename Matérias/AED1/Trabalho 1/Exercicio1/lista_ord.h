typedef struct caracteres * Caractere;
#define max 20

Caractere cria_lista();
int lista_vazia(Caractere car);
int lista_cheia(Caractere car);
int insere(Caractere car, char elem);
int remove(Caractere car, char elem);
void apaga_lista(Caractere *car);
Caractere esvazia_lista(Caractere car);
char get_elem_pos(Caractere car);
int remove_vogal(Caractere car);
int remove_elem_pos(Caractere car);
int tamanho_lista(Caractere car);
Caractere intercalar(Caractere car1, Caractere car2);