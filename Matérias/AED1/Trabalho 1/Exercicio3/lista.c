#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

struct no{
    float info;
    struct no * prox;
};

/*  Lista cria_lista()
Entrada: Nenhuma

Pré-condição: Nenhuma

Processo: Aloca a memoria para a Lista com cabecalho e coloca a quantidade de elementos no primeiro no.

Saída: Retorna a lista alocada

Pós-condição: A lista retornada deve ser diferente de NULL

*/

Lista cria_lista(){
    Lista cab;

    cab = (Lista)malloc(sizeof(struct no));     //Aloca no cabecalho
    
    if(cab!=NULL){
        cab->prox = NULL;   //Coloca lista no estade de vazio, se a alocacao nao falhar
        cab->info = 0;  //Opcional: guardar qtde
    }

    return cab;
}

/*  int lista_vazia(Lista lst)
Entrada: Recebe uma lista

Pré-condição: A lista deve estar alocada

Processo: Verifica se o ponteiro prox da lista eh NULL, se for ela esta vazia

Saída: 1 se a lista estiver vazia e 0 se nao estiver vazia

Pós-condição: Nenhuma

*/

int lista_vazia(Lista lst){
    if(lst->prox==NULL)
        return 1;//Lista vazia

    return 0;
}

/*  insere_ord(Lista *l,float elem)
Entrada: Um ponteiro para uma lista e um elemento float

Pré-condição: Nenhuma

Processo: Cria duas listas auxiliares e aloca memoria para uma delas, a segunda vai receber o ponteiro
para a lista inserida na funcao. A funcao percorre cada no para encontrar onde o elemento deve ficar
para manter a ordenacao. Quando for encontrado, o elemento vai para esse no e incrementa um no valor
do no cabecalho.

Saída: 1 Se for sucesso e 0 Se for falha

Pós-condição: Deve retornar 1

*/

int insere_ord(Lista *lst,float elem){
    if(*lst==NULL)
        return 0;

    Lista N,aux;

    N=(Lista)malloc(sizeof(struct no));

    if (N==NULL)
        return 0;

    N->info = elem;
    aux = *lst;

    while (aux->prox!=NULL&&(aux->prox)->info>elem)
        aux=aux->prox;

    N->prox=aux->prox;
    aux->prox=N;
    (*lst)->info++;

    return 1;
}

/*  remove_ord(Lista *lst,float elem)
Entrada: Um ponteiro para uma lista e um elemento float

Pré-condição: A lista nao deve estar vazia e deve estar alocada

Processo: Verifica a pre-condicao. Em seguida cria duas listas auxiliares. Uma delas recebe o ponteiro 
da lista inserida na funcao. Depois, a funcao percoretodos os nos ate encontrar o elemento a ser removido.
Entao a outra lista auxiliar recebe a lista apontando para o proximo, e em seguida libera memoria desse 
no a ser removido.

Saída: 1 se for sucesso ou 0 se for falha

Pós-condição: Deve ser 1

*/

int remove_ord(Lista *lst,float elem){
    if(*lst==NULL||lista_vazia(*lst)==1)
        return 0;

    Lista N,aux;
    N=*lst;

    while(N->prox!=NULL&&(N->prox)->info>elem)
        N=N->prox;

    if(N->prox==NULL||(N->prox)->info>elem)
        return 0;

    aux=N->prox;
    N->prox=aux->prox;
    free(aux);
    (*lst)->info--;

    return 1;
}

/*  tam_lista(Lista lst)
Entrada: Uma lista  

Pré-condição: Deve estar alocada

Processo: Retorna a informacao presente no primeiro no da lista, que eh o tamanho.

Saída: O tamanho da lista ou -1 se houver falha

Pós-condição: Nenhuma

*/

float tam_lista(Lista lst){
    if(lst==NULL)
        return -1;
    return lst->info;
}

/*  void mostra_lista(Lista lst)
Entrada: Uma lista

Pré-condição: A lista nao deve estar vazia e deve ser alocada

Processo: Verifica as pre-condicoes. Em seguida cria uma lista auxiliar e com ela, percorre todos
os nos da lista e imprime cada valor presente neles.

Saída: Nenhuma

Pós-condição: Nenhuma

*/

void mostra_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        printf("\nA lista esta vazia.\n");

    else{
        Lista aux=lst->prox;

        while(aux!=NULL){
            printf("\n%.2f",aux->info);
            aux=aux->prox;
        }
    }
}

/*  int esvazia_lista(Lista *lst)
Entrada: Ponteiro para uma lista

Pré-condição: A lista deve estar alocada

Processo: Verifica a pre-condicao, em seguida percorre todos os nos da lista. Em cada no, com a ajuda 
de uma lista auxiliar, libera a memoria alocada para cada um deles.

Saída: 1 se for sucesso e 0 se for falha

Pós-condição: Deve retornar 1

*/

int esvazia_lista(Lista *lst){
    if(lst==NULL)
        return 0;//parametro invalido

    while(*lst!=NULL){
        Lista aux = *lst;
        *lst = aux->prox;
        free(aux);
    }
    return 1;
}

/*  get_elem_pos(Lista lst, int pos, float *elem)
Entrada: Uma lista, um valor inteiro para posicao e um ponteiro para um elemento float

Pré-condição: A lista nao deve estar vazia, deve estar alocada e a posicao deve ser valida

Processo: Verifica as pre-condicoes. Em seguida, cria uma lista auxiliar que recebe o primeiro no
depois do cabecalho e percorre no por no ate chegar na posicao desejada. Quando chegar, escreve no
ponteiro do elemento a informacao que esta nesse no.

Saída: 1 se for sucesso e 0 se for falha

Pós-condição: Deve retornar 1 e o elemento float deve conter o elemento da posicao desejada

*/

int get_elem_pos(Lista lst, int pos, float *elem){
    if(lst==NULL||lista_vazia(lst)||pos<=0||pos>tam_lista(lst))
        return 0;

    int cont=1;
    Lista aux = lst->prox;

    while(aux->prox!=NULL&&cont<pos){
        aux = aux->prox;
        cont++;
    }
    *elem = aux->info;

    return 1;//Sucesso
}

/*   remove_posicao(Lista *lst, int pos)
Entrada: Recebe um ponteiro para uma lista e um inteiro representando a posicao

Pré-condição: Deve estar alocada e nao pode estar vazia

Processo: Chama a funcao get_elem_pos com a posicao inserida pelo usuario e em seguida
remove o elemento dessa posicao.

Saída: Retorna o elemento a ser removido, retorna -1 se for falha

Pós-condição: Nao deve retornar -1

*/

float remove_posicao(Lista *lst, int pos){
    if(*lst==NULL||lista_vazia(*lst))
        return -1;
    
    float elem;

    if(get_elem_pos(*lst,pos,&elem)==0)
        return -1;
    
    if(remove_ord(lst,elem)==0)
        return -1;

    return elem;
}

/*  iguais(Lista lst1, Lista lst2)
Entrada: Duas listas

Pré-condição: Devem estar alocadas   

Processo: Verifica as pre condicoes. Se forem de tamanhos diferentes, nao sao iguais. Se forem
de tamanhos iguais, a funcao percorre cada no das listas e compara elemento por elemento. Se todos 
forem iguais, retorna 1.

Saída: 1 se forem iguais, 0 se forem diferentes ou -1 se houver alguma falha

Pós-condição: Nenhuma

*/

int iguais(Lista lst1, Lista lst2){
    if(lst1==NULL||lst2==NULL)
        return -1;

    if(tam_lista(lst1)!=tam_lista(lst2))
        return 0;

    int i,tam=tam_lista(lst1);
    float elem1,elem2;

    for(i=1;i<=tam;i++){
        if(get_elem_pos(lst1,i,&elem1)==0)
            return -1;
        
        if(get_elem_pos(lst2,i,&elem2)==0)
            return -1;

        if(elem1!=elem2)
            return 0;
    }
}

/*  intercala(Lista lst1,Lista lst2)
Entrada: Duas listas

Pré-condição: Devem estar alocadas e nao podem estar vazias

Processo: Verifica as pre-condicoes. Em seguida cria e aloca uma nova lista. A funcao entao percorre
todos os nos das duas listas e insere eles nessa terceira lista, de maneira intercalada.

Saída: Retorna a lista intercalada ou NULL se der falha

Pós-condição: A lista deve ser diferente de NULL

*/

Lista intercala(Lista lst1,Lista lst2){
    if(lst1==NULL||lst2==NULL||lista_vazia(lst1)||lista_vazia(lst2))
        return NULL;

    Lista lst3=cria_lista();
    float elem;
    int i;
    
    for(i=1;i<=tam_lista(lst1);i++){
        if(get_elem_pos(lst1,i,&elem)==0)
            return NULL;

        if(insere_ord(&lst3,elem)==0)
            return NULL;
    }

    for(i=1;i<=tam_lista(lst2);i++){
        if(get_elem_pos(lst2,i,&elem)==0)
            return NULL;

        if(insere_ord(&lst3,elem)==0)
            return NULL;
    }

    return lst3;
}