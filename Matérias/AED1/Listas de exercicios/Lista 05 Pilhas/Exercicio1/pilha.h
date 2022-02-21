typedef struct pilha * Pilha;
#define max 10
#define tam 20

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int push(Pilha p, char elem[tam]);
const char * pop(Pilha p);
const char * le_topo(Pilha p);
void apaga_pilha(Pilha *p);
Pilha esvazia_pilha(Pilha *p);
int tamanho_pilha(Pilha p);
void imprime_pilha(Pilha p);