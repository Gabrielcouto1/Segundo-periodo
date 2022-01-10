typedef struct ponto Ponto;

Ponto * cria_esfera(float x, float y,float z);
void libera_esfera(Ponto **p);
float raio(Ponto *p1, Ponto *p2);
float area(Ponto *p1, Ponto *p2, float raio);
float volume(Ponto *p1, Ponto*p2, float raio);