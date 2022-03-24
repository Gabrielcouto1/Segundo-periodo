typedef struct pilha * Pilha;
#define max 20

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, char elem);
int pop(Pilha p, char *elem);
int le_topo(Pilha p, char *elem);
void mostra_pilha(Pilha p);
int decimal_binario(int num);
int decimal_octal(int num);
int decimal_hexadecimal(int num);
void exclui_pilha(Pilha *p);
Pilha apaga_pilha(Pilha *p);
