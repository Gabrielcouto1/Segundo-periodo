typedef struct no * Pilha;
#define tam 30

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p,long int matricula,char nome[tam],char setor,float salario);
const char * pop(Pilha *p,long int *matricula, char *setor, float *salario);
const char * le_topo(Pilha *p,long int *matricula, char *setor, float *salario);
int tam_pilha(Pilha *p);
Pilha esvazia_pilha(Pilha *p);
void apaga_pilha(Pilha *p);
void mostra_pilha(Pilha *p);