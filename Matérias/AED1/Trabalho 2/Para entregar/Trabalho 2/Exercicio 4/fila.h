typedef struct no * Fila;

struct paciente{
    char doenca,nome[100];
    float peso,altura;
    int idade,gravidade;
};

Fila cria_fila();
int fila_vazia(Fila f);
int insere_paciente(Fila *f, struct paciente elem);
int remove_paciente(Fila *f, struct paciente *elem);
int exclui_fila(Fila *f);
Fila apaga_fila(Fila *f);
void mostra_fila(Fila f);
void mostra_paciente(struct paciente elem);
