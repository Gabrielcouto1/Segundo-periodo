#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h"

struct no{
    int info;
    struct no * prox;
};

/*  cria_lista()
Entrada: Nenhuma

Pré-condição: Nenhuma

Processo: Retorna NULL para uma lista

Saída: NULL

Pós-condição: Nenhuma

*/

Lista cria_lista(){
    return NULL;
}

/*  lista_vazia(Lista lst)
Entrada: Uma lista

Pré-condição: Nenhuma

Processo: Verifica se a lista eh NULL

Saída: 1 se tiver vazia e 0 se nao estiver vazia 

Pós-condição: Nenhuma

*/

int lista_vazia(Lista lst){
    if(lst==NULL)
        return 1;

    return 0;
}

/*  tamanho_lista(Lista lst)
Entrada: Uma lista

Pré-condição: A lista deve ser alocada

Processo: Verifica a pre-condicao. Verifica se a lista esta vazia e retorna 0 se for vazia.
Caso contrario, a funcao vai percorrer cada no da lista ate que o proximo seja NULL, e vai
contar cada no e retorna esse valor

Saída: -1 se der alguma falha. Se nao der falha retorna o tamanho da lista

Pós-condição: Deve ser diferente de -1

*/

int tamanho_lista(Lista lst){
    if(lst==NULL)
        return -1;
        
    if(lista_vazia(lst))
        return 0;

    Lista aux=lst;
    int cont=1;
     
    while(aux->prox!=lst){
        cont++;
        aux=aux->prox;
    }

    return cont;
}

/*  insere_final(Lista *lst,int elem)
Entrada: Ponteiro para uma lista e um numero inteiro

Pré-condição: Nenhuma

Processo: Cria um no e aloca memoria para ele. Em seguida faz o no apontar para o começo da 
lista e coloca o elemento inserido nesse no. Ele fica no final da lista.

Saída: 1 se for sucesso e 0 se tiver falha

Pós-condição: Deve retornar 1

*/

int insere_final(Lista *lst,int elem){
    Lista N= (Lista)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
        
    N->info=elem;

    if(lista_vazia(*lst)==1){
        N->prox=N;
        *lst=N;
    }
    else{
        N->prox=(*lst)->prox;
        (*lst)->prox=N;
        *lst=N;
    }
    return 1;
}

/*  insere_inicio(Lista *lst, int elem)
Entrada: Ponteiro para uma lista e um numero inteiro

Pré-condição: Nenhuma

Processo: Cria um no e aloca memoria para ele. Em seguida faz o no apontar para o proximo no. 
Se for o primeiro elemento, ele aponta para si mesmo. Se nao, aponta para o proximo no inserido.

Saída: 1 se for sucesso e 0 se tiver falha

Pós-condição: Deve retornar 1

*/

int insere_inicio(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;
    
    if(*lst==NULL){
        N->info=elem;
        N->prox=N;
        *lst=N;
    }
    else{
        N->info=elem;
        N->prox=(*lst)->prox;
        (*lst)->prox=N;
    }

    return 1;
}

/*  remove_inicio(Lista *lst,int *elem)
Entrada: Ponteiro para uma lista e um ponteiro para um numero inteiro

Pré-condição: A lista deve ser alocada e nao pode estar vazia

Processo: Verifica as pre-condicoes. Em seguida cria um no auxiliar que aponta para o segundo
no da lista. Escreve no elemento inteiro o elemento a ser removido. Depois disso, exclui o 
primeiro no, que estava o elemento.

Saída: 1 se for sucesso e 0 se tiver falha

Pós-condição: Deve retornar 1

*/

int remove_inicio(Lista *lst,int *elem){
    if(lst==NULL||lista_vazia(*lst)==1)
        return 0;//Falha
    
    Lista aux=(*lst)->prox;
    *elem=aux->info;//Retorna o valor do no a ser removido

    if(*lst==(*lst)->prox)
        *lst=NULL;

    else
        (*lst)->prox=aux->prox;

    free(aux);

    return 1;
}

/*  remove_final(Lista *lst, int *elem)
Entrada: Ponteiro para uma lista e um ponteiro para um numero inteiro

Pré-condição: A lista deve ser alocada e nao pode estar vazia

Processo: Verifica as pre-condicoes. Em seguida cria um no auxiliar que aponta para o segundo
no da lista. Escreve no elemento inteiro o elemento a ser removido. Depois disso, exclui o 
ultimo no, que estava o elemento.

Saída: 1 se for sucesso e 0 se tiver falha

Pós-condição: Deve retornar 1

*/

int remove_final(Lista *lst, int *elem){
    if(lst==NULL||lista_vazia(*lst))
        return 0;

    Lista aux=(*lst)->prox;

    while(aux->prox!=(*lst))
        aux=aux->prox;
    
    *elem=aux->prox->info;

    aux->prox=(*lst)->prox;
    (*lst)=aux;

    return 1;    
}

/*  mostra_lista(Lista lst)
Entrada: Uma lista

Pré-condição: A lista nao deve estar vazia e deve ser alocada

Processo: Verifica as pre-condicoes. Em seguida, percorre cada no da lista e imprime a informacao
de cada um na tela.

Saída: Nenhuma

Pós-condição: Nenhuma

*/

void mostra_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        printf("\nA lista esta vazia.\n");

    else{
        Lista aux=lst->prox;
        do{
            printf("%d\n",aux->info);
            aux=aux->prox;
        }while(aux!=lst->prox);
    }
}

/*  insere_elem_pos(Lista *lst, int pos, int elem)
Entrada: Ponteiro para uma lista, um numero inteiro indicando a posicao e um numero inteiro

Pré-condição: A lista deve estar alocada e a posicao deve ser maior que 0

Processo: Verifica as pre condicoes. Se a posicao inserida na funcao for =1, chama a funcao 
insere_iniciou. Se a posicao for maior que o tamanho da lista, chama a funcao insere_final.
Caso contrario, percorre no por no ate chegar ao no indicado pela posicao. Em seguida insere
o elemento na posicao indicada.

Saída: 1 se for sucesso e 0 se tiver falha

Pós-condição: Deve retornar 1

*/

int insere_elem_pos(Lista *lst, int pos, int elem){
    if(*lst==NULL||pos<=0)
        return 0;

    else if(pos==1){
        if(insere_inicio(lst,elem)==0)
            return 0;
    }
    else if(tamanho_lista(*lst)<pos){
        if(insere_final(lst,elem)==0)
            return 0;
    }

    else{
        pos++;
        Lista N = (Lista)malloc(sizeof(struct no));
        Lista aux = *lst;
        int i;

        N->info=elem;
    
        for(i=2;i<=pos-1;i++)
            aux=aux->prox;

        N->prox= aux->prox;
        aux->prox=N;
    }
    
    return 1;
}

/*  remove_elem(Lista *lst,int elem)
Entrada: Ponteiro para uma lista e um numero inteiro

Pré-condição: A lista deve estar alocada

Processo: Verifica as pre condicoes. A funcao percorre a lista no por no e em seguida remove
o elemento e exclui o no em que ele se encontra.

Saída: 1 se for sucesso e 0 se tiver falha

Pós-condição: Deve retornar 1

*/

int remove_elem(Lista *lst,int elem){
    if(*lst==NULL)  
        return 0;

    Lista aux=*lst;
    Lista N;
    int x;

    while(aux->info!=elem){
        if(aux->prox==*lst)
            break;
        N=aux;
        aux=aux->prox;
    }

    if(aux==*lst)
        return remove_final(lst,&x);

    else{
        N->prox=aux->prox;
        free(aux);
    }
    return 1;
}

/*  remove_pares(Lista *lst)
Entrada: Ponteiro para uma lista

Pré-condição: A lista deve estar alocada

Processo: Verifica as pre condicoes. A funcao percorre a lista no por no e armazena 
os valores contidos em cada no em um vetor de int. Em seguida, percorre esse vetor
e pega os valores pares e chama a funcao remove_elem, que foi feita excluisivamente
para esta operacao. 

Saída: 1 se for sucesso e 0 se tiver falha

Pós-condição: Deve retornar 1

*/

int remove_pares(Lista *lst){
    if(*lst==NULL)
        return 0;
    
    Lista aux=*lst;
    int tam,i;
    tam=tamanho_lista(*lst);

    if(tam==-1)
        return 0;
    

    int info[tam];
    
    for(i=0;i<tam;i++){
        info[i]=aux->info;
        aux=aux->prox;
    }

    for(i=0;i<tam;i++){
        if((info[i]%2)==0)
            if(remove_elem(lst,info[i])==0)
                return 0;
    }

    if(tamanho_lista(*lst)==1){
        if((aux->info%2)==0){
            int x;
            return remove_inicio(lst,&x);
        }
            
    }

    return 1;
}