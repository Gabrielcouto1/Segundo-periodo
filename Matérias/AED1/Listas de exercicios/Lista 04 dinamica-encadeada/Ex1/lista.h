typedef struct no * Aluno;

Aluno cria_lista();
int lista_vazia(Aluno lst);
int insere_ord(Aluno *lst, unsigned int matricula, char nome[20], float media, int faltas);
int remove_ord(Aluno *lst,unsigned int matricula);
int get_elem_pos(Aluno lst,int pos, unsigned int *matricula);
int esvazia_lista(Aluno *lst);
void mostra_lista(Aluno lst);