#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct caracteres{
    char caractere[max];
    int Fim;
    int qtd;
};

/*  cria_lista()
Entrada: Nenhuma

Pr�-condi��o: Nenhuma

Processo: Cria uma instancia do struct caracteres na memoria e retorna ele. Tambem atribui
a posicao fim no come�o do struct.

Sa�da: Retorna a lista de caracteres criada

P�s-condi��o: Deve ser diferente de NULL

*/

Caractere cria_lista(){
    Caractere car;

    car = (Caractere)malloc(sizeof(struct caracteres));

    if(car!= NULL){
        car->Fim=0;
        int i;
        for(i=0;i<max;i++)
            car->caractere[i]='\0';
    }


    return car;
}

/*  lista_vazia(Caractere car)
Entrada: Lista de caracteres

Pr�-condi��o: A lista deve estar alocada

Processo: Verifica se o fim da lista � 0, se for, a lista esta vazia

Sa�da: 1 se a lista estiver vazia e 0 se nao estiver vazia

P�s-condi��o: Nenhuma

*/

int lista_vazia(Caractere car){
    if(car->Fim==0)
        return 1;//Lista vazia

    return 0;//Lista nao vazia
}

/*  lista_cheia(Caractere car)
Entrada: Lista de caracteres

Pr�-condi��o: A lista deve estar alocada

Processo: Verifica se o fim da lista � o tamanho maximo dela, se for, a lista esta cheia

Sa�da: 1 se a lista estiver cheia e 0 se nao estiver cheia

P�s-condi��o: Nenhuma

*/

int lista_cheia(Caractere car){
    if(car->Fim==max)
        return 1;//Lista cheia

    return 0;//Lista nao cheia
}

/*  insere(Caractere car, char elem)
Entrada: Lista de caracteres e um caractere

Pr�-condi��o: A lista deve estar alocada e nao pode estar cheia

Processo: Verifica as pre-condicoes. Em seguida, verifica se a lista esta vazia, se estiver, coloca
o elemento no come�o. Se nao, percorre a lista e acha o lugar devido que o elemento deve
ficar. Em seguida encrementa um no valor do Fim da lista.

Sa�da: 1 Se for sucesso e 0 Se for falha

P�s-condi��o: Deve retornar 1

*/

int insere(Caractere car, char elem){
    if(car==NULL||lista_cheia(car)==1)
        return 0;//Erro

    if(lista_vazia(car)==1||elem>=car->caractere[car->Fim-1])
        car->caractere[car->Fim]=elem;

    else{
        int i,aux=0;

        while (elem>=car->caractere[aux])
            aux++;

        for(i=car->Fim;i>aux;i--)
            car->caractere[i]=car->caractere[i-1];
        car->caractere[aux]=elem;
    }
    car->Fim++;
    return 1;//Sucesso
}

/*  remove(Caractere car, char elem)
Entrada: Lista de caracteres e um caractere

Pr�-condi��o: A lista deve estar alocada e nao pode estar cheia

Processo: Verifica as pre-condicoes. Em seguida, verifica se o elemento � maior que o ultimo ou menor
que o primeiro, se for, retorna 0. Caso contrario a funcao percorre a lista ate achar o elemento inserido.
Em seguida, remove ele da lista e reorganiza a lista crescente.

Sa�da: 1 Se for sucesso e 0 Se for falha

P�s-condi��o: Deve retornar 1

*/

int remove_elem(Caractere car, char elem){
    if(car==NULL||lista_vazia(car)||elem<car->caractere[0]||elem>car->caractere[car->Fim-1])
        return 0;//Erro

    int i,aux=0;

    while(aux<car->Fim&&elem>car->caractere[aux])
        aux++;

    if(aux==car->Fim||car->caractere[aux]>elem)
        return 0;//Falha

    for(i=aux+1;i<car->Fim;i++)
        car->caractere[i-1]=car->caractere[i];

    car->caractere[car->Fim-1]='\0';
    car->Fim--;
    return 1;//Sucesso
}

/*  apaga_lista(Caractere *car)
Entrada: Ponteiro para uma Lista de caractere

Pr�-condi��o: A lista deve estar alocada

Processo: Libera a memoria alocada para a lista e atribui NULL para o struct.

Sa�da: Nenhuma

P�s-condi��o: Deve estar NULL

*/

void apaga_lista(Caractere *car){
    free(*car);
    *car=NULL;
}

/*  esvazia_lista(Caractere car)
Entrada: Uma lista de caractere

Pr�-condi��o: A lista deve estar alocada

Processo: Chama a funcao apaga_lista e em seguida a funcao cria_lista.

Sa�da: Lista de caracteres

P�s-condi��o: A lista nao deve ser NULL

*/

Caractere esvazia_lista(Caractere car){
    apaga_lista(&car);
    car=cria_lista();

    return car;
}

/*  get_elem_pos(Caractere car, int pos, char *elem)
Entrada: Uma lista de caracteres, a posicao e um ponteiro de um caractere.

Pr�-condi��o: A lista deve estar alocada, a posicao deve existir.

Processo: Verifica as pre-condicoes e em seguida escreve no ponteiro do caractere o elemento
da posicao inserida.

Sa�da: 1 Se for sucesso ou 0 se for falha

P�s-condi��o: Deve retornar 1 e o caractere elemento deve conter o elemento desejado.

*/

int get_elem_pos(Caractere car, int pos, char *elem){
    if(car==NULL||lista_vazia(car)||pos>=car->Fim||pos>max)
        return 0;

    else
        *elem=car->caractere[pos];

    return 1;
}

/*  int remove_vogal(Caractere car)
Entrada: Lista de caracteres

Pr�-condi��o: A lista deve estar alocada e nao vazia.

Processo: Verifica as pre-condicoes e em seguida percorre a lista e verifica se cada caractere
e uma voga, se for, remove da lista.

Sa�da: 1 Se for sucesso e 0 se for falha

P�s-condi��o: Deve retornar 1 e nao deve ter mais nenhuma vogal na lista

*/

int remove_vogal(Caractere car){
    if(car==NULL||lista_vazia(car))
        return 0;//Falha

    int i;
    for(i=0;i<max;i++){
        switch (car->caractere[i])
        {
        case 'a':
            if(remove_elem(car,'a')==0)
                return 0;
            break;

        case 'A':
            if(remove_elem(car,'A')==0)
                return 0;
            break;

        case 'e':
            if(remove_elem(car,'e')==0)
                return 0;
            break;

        case 'E':
            if(remove_elem(car,'E')==0)
                return 0;
            break;

        case 'i':
            if(remove_elem(car,'i')==0)
                return 0;
            break;

        case 'I':
            if(remove_elem(car,'I')==0)
                return 0;
            break;

        case 'o':
            if(remove_elem(car,'o')==0)
                return 0;
            break;

        case 'O':
            if(remove_elem(car,'O')==0)
                return 0;
            break;

        case 'u':
            if(remove_elem(car,'u')==0)
                return 0;
            break;

        case 'U':
            if(remove_elem(car,'U')==0)
                return 0;
            break;

        }
    }
    return 1;
}

/*  remove_elem_pos(Caractere car, int pos)
Entrada: Lista de caracteres e uma posicao

Pr�-condi��o: A lista deve ser alocada e a posicao deve estar na lista

Processo: Verifica as pre-condicoes e em seguida chama a funcao get_elem_pos. Com esse elemento,
chama a funcao remove.

Sa�da: Retorna 1 se for sucesso. 0 se for falha.

P�s-condi��o: Deve retornar 1

*/

int remove_elem_pos(Caractere car, int pos){
    if(car==NULL||lista_vazia(car)||pos>=car->Fim||pos>max)
        return 0;


    char c;

    if(get_elem_pos(car,pos,&c)==0)
        return 0;//Falha

    if(remove_elem(car,c)==0)
        return 0;//Falha

    return 1;//Sucesso
}

/*  int tamanho_lista(Caractere car)
Entrada: Lista de caractere

Pr�-condi��o: A lista deve estar alocada

Processo: Verifica a pre-condicao, em seguida retorna o valor do fim da lista, que indica o tamanho.

Sa�da: Retorna o tamanho da lista. -1 se a lista nao estiver alocada.

P�s-condi��o: Nao deve retornar -1.

*/

int tamanho_lista(Caractere car){
    if(car==NULL)
        return -1;//lista vazia ou nao iniciada

    return car->Fim;
}

/*  Caractere intercalar(Caractere car1, Caractere car2)
Entrada: Duas listas de caracteres

Pr�-condi��o: Ambas devem estar alocadas e nao vazias

Processo: Verifica as pre-condicoes, em seguida cria uma nova lista. Depois percorre as duas listas
e insere os seus elementos em uma nova lista. Em seguida retorna a lista.

Sa�da: Retorna a lista intercalada

P�s-condi��o: A nova lista deve ser diferente de NULL

*/

Caractere intercalar(Caractere car1, Caractere car2){
    if(car1==NULL||car2==NULL||lista_vazia(car1)==1||lista_vazia(car2)==1)
        return 0;//Falha

    Caractere car3=cria_lista();
    int i;
    char elem1,elem2;

    for(i=0;i<max;i++){
        if(get_elem_pos(car1,i,&elem1))
            if(insere(car3,elem1)==0)
                return NULL;

        if(get_elem_pos(car2,i,&elem2))
            if(insere(car3,elem2)==0)
                return NULL;
    }
    return car3;
}

/*  mostra_lista(Caractere car)
Entrada: Uma lista

Pr�-condi��o: A lista nao deve estar vazia e deve ser alocada

Processo: Verifica as pre-condicoes. Em seguida, percorre cada no da lista e imprime a informacao
de cada um posicao de caractere na tela.

Sa�da: Nenhuma

P�s-condi��o: Nenhuma

*/

void mostra_lista(Caractere car){
    if(car==NULL||lista_vazia(car))
        printf("\nA lista esta vazia.");
    else{
        int i;
        for(i=0;i<max;i++)
                if(car->caractere[i]!='\0')
                    printf("%c\n",car->caractere[i]);
    }
}
