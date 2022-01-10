typedef struct complexo Complexo;

Complexo * cria_nro();
int set_nro(Complexo *num,int R, int I);
int get_nro(Complexo *num, int *R, int *I);
void libera_nro(Complexo ** num);
Complexo * soma(Complexo *N1,Complexo *N2);
Complexo * sub(Complexo *N1,Complexo *N2);
Complexo * mult(Complexo *N1, Complexo *N2);