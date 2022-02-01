#include <stdio.h>
#include <stdlib.h>
#include "lista_ord.h"

struct caracteres{
    char caractere[max];
    int Fim;
    int qtd;
};

/*  cria_lista()
Entrada: Nenhuma

Pré-condição: Nenhuma

Processo: Cria uma instancia do struct caracteres na memoria e retorna ele. Tambem atribui 
a posicao fim no começo do struct.

Saída: Retorna a lista de caracteres criada

Pós-condição: Deve ser diferente de NULL

*/

Caractere cria_lista(){
    Caractere car;

    car = (Caractere)malloc(sizeof(struct caracteres));

    if(car!= NULL)
        car->Fim=0;
    
    return car;
}

/*  lista_vazia(Caractere car)
Entrada: Lista de caracteres

Pré-condição: A lista deve estar alocada

Processo: Verifica se o fim da lista é 0, se for, a lista esta vazia

Saída: 1 se a lista estiver vazia e 0 se nao estiver vazia

Pós-condição: Nenhuma

*/

int lista_vazia(Caractere car){
    if(car->Fim==0)
        return 1;//Lista vazia
    
    return 0;//Lista nao vazia
}

/*  lista_cheia(Caractere car)
Entrada: Lista de caracteres

Pré-condição: A lista deve estar alocada

Processo: Verifica se o fim da lista é o tamanho maximo dela, se for, a lista esta cheia

Saída: 1 se a lista estiver cheia e 0 se nao estiver cheia

Pós-condição: Nenhuma

*/

int lista_cheia(Caractere car){
    if(car->Fim==max)  
        return 1;//Lista cheia
    
    return 0;//Lista nao cheia
}

/*  insere(Caractere car, char elem)
Entrada: Lista de caracteres e um caractere

Pré-condição: A lista deve estar alocada e nao pode estar cheia

Processo: Verifica as pre-condicoes. Em seguida, verifica se a lista esta vazia, se estiver, coloca
o elemento no começo. Se nao, percorre a lista e acha o lugar devido que o elemento deve
ficar. Em seguida encrementa um no valor do Fim da lista.

Saída: 1 Se for sucesso e 0 Se for falha

Pós-condição: Deve retornar 1

*/

int insere(Caractere car, char elem){
    if(car==NULL||lista_cheia(car)==1)
        return 0;//Erro
    
    if(lista_vazia(car)==1||elem>=car->caractere[car->Fim-1])
        car->caractere[car->Fim]=elem;
    
    else{
        int i,aux=0;

        while (elem>=lst->caractere[aux])
            aux++;
        
        for(i=car->Fim;i>aux;i--)
            car->caractere[i]=car->caractere[i-1];
    }
    car->Fim++;
    return 1;//Sucesso
}

/*  remove(Caractere car, char elem)
Entrada: Lista de caracteres e um caractere

Pré-condição: A lista deve estar alocada e nao pode estar cheia

Processo: Verifica as pre-condicoes. Em seguida, verifica se o elemento é maior que o ultimo ou menor
que o primeiro, se for, retorna 0. Caso contrario a funcao percorre a lista ate achar o elemento inserido.
Em seguida, remove ele da lista e reorganiza a lista crescente.

Saída: 1 Se for sucesso e 0 Se for falha

Pós-condição: Deve retornar 1

*/

int remove(Caractere car, char elem){
    if(car==NULL||lista_vazia(car)==1||elem<car->caractere[0]||elem>car->caractere[Fim-1])
        return 0;//Erro
    
    int i,aux=0;

    while(aux<car->Fim&&elem>car->caractere[aux])
        aux++;
    
    if(aux==car->Fim||car->caractere[aux]>elem)
        return 0;//Falha
    
    for(i=aux+1;i<car->Fim;i++)
        car->caractere[i-1]=car->caractere[i];
    
    car->caractere[car->Fim-1]='';
    car->Fim--;
    return 1;//Sucesso
}

/*  apaga_lista(Caractere *car)
Entrada: Ponteiro para uma Lista de caractere

Pré-condição: A lista deve estar alocada

Processo: Libera a memoria alocada para a lista e atribui NULL para o struct.

Saída: Nenhuma

Pós-condição: Deve estar NULL

*/

void apaga_lista(Caractere *car){
    free(*car);
    *car=NULL;
}

/*  esvazia_lista(Caractere car)
Entrada: Uma lista de caractere

Pré-condição: A lista deve estar alocada

Processo: Chama a funcao apaga_lista e em seguida a funcao cria_lista.

Saída: Lista de caracteres

Pós-condição: A lista nao deve ser NULL

*/

Caractere esvazia_lista(Caractere car){
    apaga_lista(&car);
    car=cria_lista();

    return car;
}

/*  get_elem_pos(Caractere car, int pos, char *elem)
Entrada: Uma lista de caracteres, a posicao e um ponteiro de um caractere.

Pré-condição: A lista deve estar alocada, a posicao deve existir.

Processo: Verifica as pre-condicoes e em seguida escreve no ponteiro do caractere o elemento
da posicao inserida.

Saída: 1 Se for sucesso ou 0 se for falha

Pós-condição: Deve retornar 1 e o caractere elemento deve conter o elemento desejado.

*/

int get_elem_pos(Caractere car, int pos, char *elem){
    if(pos>=car->Fim||pos>max)
        return 0;

    else
        *elem=car->caractere[pos];
    
    return 1;
}

/*  int remove_vogal(Caractere car)
Entrada: Lista de caracteres

Pré-condição: A lista deve estar alocada e nao vazia.

Processo: Verifica as pre-condicoes e em seguida percorre a lista e verifica se cada caractere
e uma voga, se for, remove da lista.

Saída: 1 Se for sucesso e 0 se for falha

Pós-condição: Deve retornar 1 e nao deve ter mais nenhuma vogal na lista

*/

int remove_vogal(Caractere car){
    if(car==NULL||lista_vazia(car)==1)
        return 0;//Falha
    
    int i;
    for(i=0;i<max;i++){
        switch (car->caractere[i])
        {
        case 'a':
            if(remove(car,'a')==0)
                return 0;
            break;
        case 'A':
            if(remove(car,'A')==0)
                return 0;
            break;
        case 'e':
            if(remove(car,'e')==0)
                return 0;
            break;
        case 'E':
            if(remove(car,'E')==0)
                return 0;
            break;
        case 'i':
            if(remove(car,'i')==0)
                return 0;
            break;
        case 'I':
            if(remove(car,'I')==0)
                return 0;
            break;
        case 'o':
            if(remove(car,'o')==0)
                return 0;
            break;
        case 'O':
            if(remove(car,'O')==0)
                return 0;
            break;
        case 'u':
            if(remove(car,'u')==0)
                return 0;
            break;
        case 'U':
            if(remove(car,'U')==0)
                return 0;
            break;
        default:
            break;
        }
    }
    return 1;
}

/*  remove_elem_pos(Caractere car, int pos)
Entrada: Lista de caracteres e uma posicao

Pré-condição: A lista deve ser alocada e a posicao deve estar na lista

Processo: Verifica as pre-condicoes e em seguida chama a funcao get_elem_pos. Com esse elemento,
chama a funcao remove.

Saída: Retorna 1 se for sucesso. 0 se for falha.

Pós-condição: Deve retornar 1

*/

int remove_elem_pos(Caractere car, int pos){
    if(pos>=car->Fim||pos>max)
        return 0;


    char c;

    if(get_elem_pos(car,pos,*c)==0)
        return 0;//Falha

    if(remove(car,c)==0)
        return 0;//Falha
    
    return 1;//Sucesso
}

/*  int tamanho_lista(Caractere car)
Entrada: Lista de caractere

Pré-condição: A lista deve estar alocada

Processo: Verifica a pre-condicao, em seguida retorna o valor do fim da lista, que indica o tamanho.

Saída: Reotrna o tamanho da lista. -1 se a lista nao estiver alocada. 

Pós-condição: Nao deve retornar -1.

*/

int tamanho_lista(Caractere car){
    if(car==NULL)
        return -1;//lista vazia ou nao iniciada

    return car->Fim;
}

/*  Caractere intercalar(Caractere car1, Caractere car2)
Entrada: Duas listas de caracteres

Pré-condição: Ambas devem estar alocadas e nao vazias

Processo: Verifica as pre-condicoes, em seguida cria uma nova lista. Depois percorre as duas listas 
e insere os seus elementos em uma nova lista. Em seguida retorna a lista.

Saída: Retorna a lista intercalada

Pós-condição: A nova lista deve ser diferente de NULL

*/

Caractere intercalar(Caractere car1, Caractere car2){
    if(car1==NULL||lista_vazia(car1)==1||car2==NULL||lista_vazia(car2)==1)
        return 0;//Falha
    
    Caractere car3=cria_lista();
    int i;

    for(i=0;i<max;i++){
        if(insere(car3,car1->caractere[i])==0)
            return NULL;
        if(insere(car3,car2->caractere[i])==0)
            return NULL;
    }   
    
    return car3;
}