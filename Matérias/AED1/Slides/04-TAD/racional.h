typedef struct racional Racional;

Racional * generate();
int set_value(Racional *p, int N, int D);
int get_value(Racional *p, int *N, int *D);
Racional * sum (Racional *R1, Racional *R2);
void delete (Racional **p);