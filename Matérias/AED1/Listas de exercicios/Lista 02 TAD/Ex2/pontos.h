typedef struct ponto Ponto;

Ponto * cria_pt(float x, float y,float z);
void apaga_pto (Ponto **p);
float distancia(Ponto *p1, Ponto *p2);