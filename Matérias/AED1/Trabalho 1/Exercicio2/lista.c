#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
    char info[max][tam];
    int Fim;
};

/*  cria_lista()
Entrada: Nenhuma

Pré-condição: Nenhuma

Processo: Cria uma instancia do struct lista na memoria e retorna ele. Tambem atribui 
a posicao fim no começo do struct.

Saída: Retorna a lista criada

Pós-condição: Deve ser diferente de NULL

*/

Lista cria_lista(){
    Lista lst;

    lst=(Lista)malloc(sizeof(struct lista));

    if(lst!=NULL){
        lst->Fim=0;
        int i;
        for(i=0;i<max;i++)
            strcpy(lst->info[i],"\0");
    }

    return lst;
}

/*  lista_vazia(Lista lst)
Entrada: Uma lista

Pré-condição: A lista deve estar alocada

Processo: Verifica se o fim da lista é 0, se for, a lista esta vazia

Saída: 1 se a lista estiver vazia e 0 se nao estiver vazia

Pós-condição: Nenhuma

*/

int lista_vazia(Lista lst){
    if(lst->Fim==0)
        return 1;//a lista esta vazia
    
    return 0;//nao esta vazia
}

/*  lista_cheia(Lista lst)
Entrada: Uma lista

Pré-condição: A lista deve estar alocada

Processo: Verifica se o fim da lista é o tamanho maximo dela, se for, a lista esta cheia

Saída: 1 se a lista estiver cheia e 0 se nao estiver cheia

Pós-condição: Nenhuma

*/

int lista_cheia(Lista lst){
    if(lst->Fim==max)
        return 1;//a lista esta cheia

    return 0;//a lista nao esta cheia
}

/*  insere_elem(Lista lst,char elem[tam])
Entrada: Uma lista e uma string

Pré-condição: A lista deve estar alocada e nao pode estar cheia

Processo: Verifica as pre-condicoes. Em seguida, verifica se a lista esta vazia, se estiver, coloca
o elemento no começo. Se nao, coloca o elemnto no final.

Saída: 1 Se for sucesso e 0 Se for falha

Pós-condição: Deve retornar 1

*/

int insere_elem(Lista lst,char elem[tam]){
    if(lst==NULL||lista_cheia(lst))
        return 0;
    
    strcpy(lst->info[lst->Fim],elem);
    lst->Fim++;

    return 1;   
}

/*  remove_elem(Lista lst, char elem[tam])
Entrada: Uma lista e uma string

Pré-condição: A lista deve estar alocada e nao pode estar vazia

Processo: Verifica as pre-condicoes. Em seguida, verifica se o elemento esta na lista, se nao 
retorna 0. Caso contrario a funcao percorre a lista ate achar o elemento inserido.
Em seguida, remove ele da lista e retorna 1.

Saída: 1 Se for sucesso e 0 Se for falha

Pós-condição: Deve retornar 1

*/

int remove_elem(Lista lst, char elem[tam]){
    if(lst==NULL||lista_vazia(lst))
        return 0;

    int i,aux=0;

    while(aux<lst->Fim&&(strcmp(lst->info[aux],elem)!=0))
        aux++;
    
    if(aux==lst->Fim)
        return 0;

    for(i=aux+1;i<lst->Fim;i++)
        strcpy(lst->info[i-1],lst->info[i]);

    strcpy(lst->info[lst->Fim-1],"\0");
    lst->Fim--;

    return 1;
}

/*  get_elem_pos(Lista lst,int pos)
Entrada: Uma lista e a posicao do elemento desejado

Pré-condição: A lista deve estar alocada e a posicao deve existir.

Processo: Verifica as pre-condicoes e em seguida retorna o elemento da posicao 
inserida na funcao.

Saída: Elemento da posicao inserida

Pós-condição: O elemento retornado deve ser diferente de "\0"

*/

const char * get_elem_pos(Lista lst,int pos){
    if(lst==NULL||lista_vazia(lst)||pos>=lst->Fim||pos>max||pos<=0)
        return "\0";//Posicao invalida

    return lst->info[pos];
}

/*  Lista esvazia_lista(Lista lst)
Entrada: Uma lista

Pré-condição: A lista deve estar alocada

Processo: Chama a funcao apaga_lista e em seguida a funcao cria_lista.

Saída: Lista de caracteres

Pós-condição: A lista nao deve ser NULL

*/

Lista esvazia_lista(Lista *lst){
    if(*lst==NULL)
        return cria_lista();
    apaga_lista(lst);
    *lst=cria_lista();

    return *lst;
}

/*  apaga_lista(Lista *lst)
Entrada: Ponteiro para uma Lista

Pré-condição: A lista deve estar alocada

Processo: Libera a memoria alocada para a lista e atribui NULL para o struct.

Saída: Nenhuma

Pós-condição: Deve estar NULL

*/

void apaga_lista(Lista *lst){
    if(*lst==NULL)  
        return;
    else{
        free(*lst);
        *lst=NULL;
    }
    
}

/*  mostra_lista(Lista car)
Entrada: Uma lista

Pré-condição: A lista nao deve estar vazia e deve ser alocada

Processo: Verifica as pre-condicoes. Em seguida, percorre cada no da lista e imprime a informacao
de cada um posicao de caractere na tela.

Saída: Nenhuma

Pós-condição: Nenhuma

*/

void mostra_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        printf("\nA lista nao esta alocada ou esta vazia.");
    else{
        int i;
        printf("\nLista: \n");
        for(i=0;i<max;i++){
            if(strcmp(lst->info[i],"\0")!=0)
                printf("%s\n",lst->info[i]);
        }
    }
}

/*  insere_elem_pos(Lista lst, int pos, char elem[tam])
Entrada: Lista de caracteres, posicao e uma string

Pré-condição: A lista deve ser alocada e a posicao deve estar na lista

Processo: Verifica as pre-condicoes e em seguida insere o elemento na posicao desejada

Saída: Retorna 1 se for sucesso. 0 se for falha.

Pós-condição: Deve retornar 1

*/

int insere_elem_pos(Lista lst, int pos, char elem[tam]){
    if(lst==NULL||lista_cheia(lst)||pos<=0||pos>max)
        return 0;

    strcpy(lst->info[pos],elem);
    lst->Fim++;
    
    return 1;
}

/*  remove_menor(Lista lst)
Entrada: Uma lista

Pré-condição: A lista deve ser alocada

Processo: Verifica a pre-condicao e em seguida aloca memoria para uma variavel char 
que armazenara o menor elemento presente na lista. Depois percorre toda a lista e
compara elemento por elemento para encontrar o menor. Entao remove o menor elemento
da lista e retorna o mesmo.

Saída: Retorna o menor elemento da lista. Retorna "\0" se houver alguma falha

Pós-condição: Deve retornar diferente de "\0"

*/

const char * remove_menor(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        return "\0";

    int i,cont=0;
    char *aux;
    aux=malloc(sizeof(char)*tam);
    
    strcpy(aux,lst->info[0]);

    for(i=0;i<max;i++)
        if(strcmp(aux,lst->info[i])>0){
            strcpy(aux,lst->info[i]);
            cont++;
        }
    strcpy(aux,lst->info[cont-1]);
    remove_elem(lst,aux);
    
    return aux;
}

/*  tamanho_lista(Lista lst)
Entrada: Uma lista

Pré-condição: A lista deve estar alocada

Processo: Verifica a pre-condicao, em seguida retorna o valor do fim da lista, que indica o tamanho.

Saída: Retorna o tamanho da lista. -1 se a lista nao estiver alocada. 

Pós-condição: Nao deve retornar -1.

*/

int tamanho_lista(Lista lst){
    if(lst==NULL)
        return -1;
    
    return lst->Fim;
}

/*   concatenar(Lista lst1, Lista lst2)
Entrada: Duas listas

Pré-condição: Ambas devem estar alocadas e nao vazias

Processo: Verifica as pre-condicoes, em seguida cria uma nova lista. Percorre a
primeira lista e insere seus elementos na nova lista, depois percorre a segunda
lista e tambem insere seus elementos na nova lista. Em seguida retorna a lista.

Saída: Retorna a lista concatenada

Pós-condição: A nova lista deve ser diferente de NULL

*/

Lista concatenar(Lista lst1, Lista lst2){
    if(lst1==NULL||lst2==NULL||lista_vazia(lst1)||lista_vazia(lst2))
        return NULL;

    if((tamanho_lista(lst1)+tamanho_lista(lst2))>max)
        return NULL;

    Lista lst3=cria_lista();
    if(lst3==NULL)
        return NULL;
    int i;

    for(i=0;i<max;i++){
        if(strcmp(lst1->info[i],"\0")!=0)
            if(insere_elem(lst3,lst1->info[i])==0)
                return NULL;
    }

    for(i=0;i<max;i++){
        if(strcmp(lst2->info[i],"\0")!=0)
            if(insere_elem(lst3,lst2->info[i])==0)
                return NULL;
    }

    return lst3;
}