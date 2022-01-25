#include <stdio.h>
#include <stdlib.h>
#include "lista_ord.h"

struct caracteres{
    char caractere[max];
    int Fim;
    int qtd;
};

Caractere cria_lista(){
    Caractere car;

    car = (Caractere)malloc(sizeof(struct caracteres));

    if(car!= NULL)
        car->Fim=0;
    
    return car;
}

int lista_vazia(Caractere car){
    if(car->Fim==0)
        return 1;//Lista vazia
    
    return 0;//Lista nao vazia
}

int lista_cheia(Caractere car){
    if(car->Fim==max)  
        return 1;//Lista cheia
    
    return 0;//Lista nao cheia
}

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

void apaga_lista(Caractere *car){
    free(*car);
    *car=NULL;
}

Caractere esvazia_lista(Caractere car){
    apaga_lista(&car);
    car=cria_lista();

    return car;
}

char get_elem_pos(Caractere car, int pos){
    if(pos>=car->Fim||pos>max){
        fprintf(stderr,"\nA posicao inserida eh invalida.\n");
        return 0;
    }

    else{
        printf("\n\t\tElemento da posicao %d: %c\n\n",pos,car->caractere[pos]);
        return car->caractere[pos];
    }
}

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

int remove_elem_pos(Caractere car){
    char c;
    c=get_elem_pos(car);
    if(c==0)
        return 0;//Falha

    if(remove(car,c)==0)
        return 0;//Falha
    
    return 1;//Sucesso
}

int tamanho_lista(Caractere car){
    if(car==NULL)
        return -1;//lista vazia ou nao iniciada

    return car->Fim;
}

Caractere intercalar(Caractere car1, Caractere car2){
    int i;
    char elem1,elem2;
    Caractere car3;

    for(i=0;i<max;i++){
        if(insere(car3,get_elem_pos(car1,i)==0))
            fprintf(stderr,"\nNao foi possivel inserir o elemento.\n");
        if(insere(car3,get_elem_pos(car2,i)==0))
            fprintf(stderr,"\nNao foi possivel inserir o elemento.\n");
    }
    
    return car3;
}