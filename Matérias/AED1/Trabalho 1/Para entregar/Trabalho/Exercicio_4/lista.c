#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no * prox;
};

/*  cria_lista()
Entrada: Nenhuma

Pr�-condi��o: Nenhuma

Processo: Retorna NULL para uma lista

Sa�da: NULL

P�s-condi��o: Nenhuma

*/

Lista cria_lista(){
    return NULL;
}

/*  lista_vazia(Lista lst)
Entrada: Uma lista

Pr�-condi��o: Nenhuma

Processo: Verifica se a lista eh NULL

Sa�da: 1 se tiver vazia e 0 se nao estiver vazia

P�s-condi��o: Nenhuma

*/

int lista_vazia(Lista lst){
    if(lst==NULL)
        return 1;

    return 0;
}

/*  insere_elem(Lista *lst,int elem)
Entrada: Ponteiro para uma lista e um elemento inteiro

Pr�-condi��o: Nenhuma

Processo: Aloca um no para a lista. Em insere o elemento na lista e faz a lista apontar para
o novo no

Sa�da: 1 se for sucesso ou 0 se for falha

P�s-condi��o: Deve retornar 1

*/

int insere_elem(Lista *lst,int elem){
    Lista N=(Lista)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;//No nao alocado- falha

    N->info=elem;//Insere o valor do elem
    N->prox=*lst;//Aponta para o primeiro no atual da lista
    *lst=N;//Faz a lista apontar para o novo no

    return 1;
}

/*  remove_elem(Lista *lst,int elem)
Entrada: Ponteiro para uma lista e um elemento inteiro

Pr�-condi��o: A lista nao deve estar vazia e deve estar alocada

Processo: Verifica a pre-condicao. Em seguida cria uma lista auxiliar que aponta para o primeiro no.
Verifica se o elemento a ser removido esta no primeiro no. Se estiver, remove ele e faz a lista apontar
para o segundo no e libera a memoria do no removido. Se nao for o primeiro no, a funcao percorre todos
os nos ate encontrar o elemento e remove ele.

Sa�da: 1 se for sucesso ou 0 se for falha

P�s-condi��o: Deve retornar 1

*/

int remove_elem(Lista *lst,int elem){
    if (*lst==NULL||lista_vazia(*lst)==1)
        return 0;//Falha

    Lista aux=*lst; //Ponteiro aux para o primeiro no
    //Trata elemento=primeiro no da lista

    if(elem==(*lst)->info){
        *lst=aux->prox;//Lista aponta par ao segundo no
        free(aux);//Libera memoria
        return 1;
    }

    while(aux->prox!=NULL&&aux->prox->info!=elem)
        aux=aux->prox;//percorrimento ate achar o elemento ou o final da lista

    if(aux->prox==NULL) //Trata do final da lista
        return 0;//Falha

    Lista aux2=aux->prox;//Aponta o no a ser removido
    aux->prox=aux2->prox;//Retura o no da lista
    free(aux2);//Libera a lista auxiliar

    return 1;//Sucesso
}

/*  mostra_lista(Lista lst)
Entrada: Uma lista

Pr�-condi��o: A lista nao deve estar vazia e deve ser alocada

Processo: Verifica as pre-condicoes. Em seguida, percorre cada no da lista e imprime a informacao
de cada um na tela.

Sa�da: Nenhuma

P�s-condi��o: Nenhuma

*/

void mostra_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        printf("\nA lista esta vazia.");

    else{
        Lista aux=lst;

        while(aux!=NULL){
            printf("%d\n",aux->info);
            aux = aux->prox;
        }
    }
}

/*  tam_lista(Lista lst)
Entrada: Uma lista

Pr�-condi��o: A lista deve ser alocada

Processo: Verifica a pre-condicao. Verifica se a lista esta vazia e retorna 0 se for vazia.
Caso contrario, a funcao vai percorrer cada no da lista ate que o proximo seja NULL, e vai
contar cada no e retorna esse valor

Sa�da: -1 se der alguma falha. Se nao der falha retorna o tamanho da lista

P�s-condi��o: Deve ser diferente de -1

*/

int tam_lista(Lista lst){
    if(lst==NULL)
        return -1;
    if(lista_vazia(lst)==1)
        return 0;

    Lista aux = lst;
    int tam=0;

    while(aux!=NULL){
        tam++;
        aux=aux->prox;
    }

    return tam;
}

/*  int esvazia_lista(Lista *lst)
Entrada: Ponteiro para uma lista

Pr�-condi��o: A lista eve estar alocada

Processo: Verifica a pre-condicao. Percorre a lista no por no e libera a memoria alocada para
cada no.

Sa�da: 1 se for sucesso ou 0 se for falha

P�s-condi��o: Deve retornar 1

*/

int esvazia_lista(Lista *lst){
    if(*lst==NULL)//parametro invalido
        return 0;//Falha

    while(*lst!=NULL){
        Lista aux=*lst;
        *lst=aux->prox;
        free(aux);
    }

    return 1;//Sucesso
}

/*  int get_elem_pos(Lista lst, int pos, int *elem)
Entrada: Uma lista, um inteiro para a posicao e um ponteiro para um elemento inteiro

Pr�-condi��o: A lista nao deve estar vazia, deve estar alocada e a posicao deve existir

Processo: Verifica as pre-condicoes. Em seguida, com ajuda de uma Lista auxiliar, percorre
cada no ate chegar na posicao inserida e escreve no endereco do elemento a informacao
presente nesse no.

Sa�da: 1 se for sucesso ou 0 se for falha

P�s-condi��o: Deve retornar 0 e o elemento deve conter o conteudo do no desejado

*/

int get_elem_pos(Lista lst, int pos, int *elem){
    if(lista_vazia(lst)||pos<=0||pos>tam_lista(lst)||lst==NULL)
        return 0;//Falha

    int cont=1;
    Lista aux=lst;

    while(aux->prox!=NULL&&cont<pos){
        aux=aux->prox;
        cont++;
    }

    *elem=aux->info;
    return 1;//Sucesso
}

/*  int remove_maior(Lista *lst)
Entrada: Ponteiro para uma lista

Pr�-condi��o: A lista deve estar alocada

Processo: Verifica a pre-condicao. Em seguida, com a ajuda de uma lista auxiliar, percorre
todos os nos comparando os valores neles para achar o maior deles. Quando terminar, a funcao
chama a funcao remove_elem e remove o maior elemento da lista.

Sa�da: 1 se for sucesso ou 0 se for falha

P�s-condi��o: Deve retornar 1

*/

int remove_maior(Lista *lst){
    if((*lst)==NULL)
        return 0;

    int i,maior;
    Lista aux=*lst;
    maior=(*lst)->info;

    while(aux->prox!=NULL){
        if(maior<aux->info)
            maior=aux->info;
        aux=aux->prox;
    }

    if(remove_elem(lst,maior)==0)
        return 0;

    return 1;
}

/*  intercalar(Lista lst1, Lista lst2)
Entrada: Duas listas

Pr�-condi��o: As duas devem estar alocadas e nao vazias

Processo: Verifica as pre condicoes. Em seguida, cria uma terceira lista. Entao, a funcao percorre
cada no das duas listas e conforme faz isso, vai inserindo um elemento de cada um na lista nova,
de forma que insira um da lista 1 e um da lista 2, intercalados.

Sa�da: Retorna a lista intercalada ou NULL se der algum erro

P�s-condi��o: A lista intercalada deve ser diferente de NULL

*/

Lista intercalar(Lista lst1, Lista lst2){
    if(lst1==NULL||lst2==NULL||lista_vazia(lst1)||lista_vazia(lst2))
        return NULL;

    Lista lst3=cria_lista();
    int i,elem;
    int tam1=tam_lista(lst1);
    int tam2=tam_lista(lst2);

    if(tam1=tam2){
        for(i=1;i<=tam1;i++){
            if(get_elem_pos(lst1,i,&elem)==1)
                if(insere_elem(&lst3,elem)==0)
                    return NULL;

            if(get_elem_pos(lst2,i,&elem)==1)
                if(insere_elem(&lst3,elem)==0)
                    return NULL;
        }
    }

    else if(tam1>tam2){
        for(i=1;i<=tam1;i++){
            if(get_elem_pos(lst1,i,&elem)==1)
                if(insere_elem(&lst3,elem)==0)
                    return NULL;

            if(get_elem_pos(lst2,i,&elem)==1)
                if(insere_elem(&lst3,elem)==0)
                    return NULL;
        }
    }

    else if(tam2>tam1){
        for(i=1;i<=tam2;i++){
            if(get_elem_pos(lst1,i,&elem)==1)
                if(insere_elem(&lst3,elem)==0)
                    return NULL;

            if(get_elem_pos(lst2,i,&elem)==1)
                if(insere_elem(&lst3,elem)==0)
                    return NULL;
        }
    }

    return lst3;
}

/*  inverter(Lista lst1)
Entrada: Uma lista

Pr�-condi��o: Nao deve estar vazia e deve estar alocada

Processo: Verifica as pre-condicoes. Em seguida cria uma lista nova. Entao, percorre a lista
inserida no por no, comecando do ultimo e insere na lista nova.

Sa�da: Retorna a lista nova ou NULL se houver uma falha

P�s-condi��o: A lista invertida nao deve ser NULL

*/

Lista inverter(Lista lst1){
    if(lst1==NULL||lista_vazia(lst1))
        return NULL;

    Lista lst2=cria_lista();
    int elem,i,tam=tam_lista(lst1);
    int cont=1;

    for(i=tam;i>0;i--){
        if(get_elem_pos(lst1,cont,&elem)==0)
            return NULL;
        if(insere_elem(&lst2,elem)==0)
            return NULL;
        cont++;
    }

    return lst2;
}
