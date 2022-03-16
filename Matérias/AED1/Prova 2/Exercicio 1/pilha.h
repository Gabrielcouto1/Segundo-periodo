typedef struct pilha * Pilha;

#define max 100

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, char elem);
int pop(Pilha p, char *elem);
int inverte_palavras(char elem[]);