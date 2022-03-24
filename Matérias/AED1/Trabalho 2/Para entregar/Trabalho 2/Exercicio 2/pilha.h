typedef struct no * Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, char elem);
int pop(Pilha *p, char *elem);
int le_topo(Pilha *p, char *elem);
void mostra_pilha(Pilha p);
int verificar_escopo(char elem[]);
int infixa_posfixa(char elem[]);
