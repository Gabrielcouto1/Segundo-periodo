#include <stdlib.h> 
#include <stdio.h>
#include "pilha.h"

struct no{
    char info;
    struct no * prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p==NULL)
        return 1;

    return 0;
}

int push(Pilha *p, char elem){
    Pilha N=(Pilha)malloc(sizeof(struct no));

    if(N==NULL)
        return 0;
    
    N->info=elem;
    N->prox=*p;
    *p=N;

    return 1;
}

int pop(Pilha *p, char *elem){
    if(pilha_vazia(*p))
        return 0;
    
    Pilha aux=*p;

    *elem=aux->info;
    *p=aux->prox;

    free(aux);

    return 1;
}   

int le_topo(Pilha *p, char *elem){
    if(pilha_vazia(*p))
        return 0;
    
    *elem=(*p)->info;

    return 1;
}

void mostra_pilha(Pilha p){
    if(pilha_vazia(p))
        printf("\nA pilha esta vazia.");

    else{
        Pilha aux=p;
        printf("\n");
        while(aux!=NULL){
            printf("%c\n",aux->info);
            aux=aux->prox;
        }
    }
}

int decimal_binario(int num){
    if(num<0)
        return 0;
    if(num==0){
        printf("Numero decimal: 0\nNumero binario: 0");
        return 1;
    }

    Pilha binario=cria_pilha();
    int res;
    char r;
    int num1=num;

    while(num!=0){
        res=num%2;
        r=res+48;
        if(push(&binario,r)==0)
            return 0;
        num/=2;
    }
    
    printf("Numero decimal: %d\nNumero binario: ",num);
    
    while(binario!=NULL){
        printf("%c",binario->info);
        binario=binario->prox;
    }
    return 1;
}

int decimal_octal(int num){
    if(num<0)
        return 0;
    if(num==0){
        printf("Numero decimal: 0\nNumero octal: 0");
        return 1;
    }

    Pilha octal=cria_pilha();
    int res;
    char r;
    int num1=num;

    while(num!=0){
        res=num%8;
        r=res;
        if(push(&octal,r)==0)
            return 0;
        num/=8;
    }
    
    printf("Numero decimal: %d\nNumero octal: ",num1);
    
    while(octal!=NULL){
        printf("%d",octal->info);
        octal=octal->prox;
    }

    return 1;
}

int decimal_hexadecimal(int num){
    if(num<0)
        return 0;
    if(num==0){
        printf("Numero decimal: 0\nNumero Hexadecimal: 0");
        return 1;
    }

    Pilha hexa=cria_pilha();
    int res;
    char aux;
    char r;
    int num1=num;
    
    while(num!=0){
        res=num%16;
        r=res+48;

        if(res>=10){
            switch(res){
                case 10:
                    if(push(&hexa,'A')==0)
                        return 0;
                    
                    break;
                case 11:
                    if(push(&hexa,'B')==0)
                        return 0;
                    
                    break;
                case 12:
                    if(push(&hexa,'C')==0)
                        return 0;
                    
                    break;
                case 13:
                    if(push(&hexa,'D')==0)
                        return 0;
                    
                    break;
                case 14:
                    if(push(&hexa,'E')==0)
                        return 0;
                    
                    break;
                case 15:
                    if(push(&hexa,'F')==0)
                        return 0;
                    
                    break;
                default:
                    break;
            }
        }
        if(res<10)
            if(push(&hexa,r)==0)
                return 0;
        num/=16;
    }
    
    printf("Numero decimal: %d\nNumero hexa: ",num1);
    
    while(hexa!=NULL){
        printf("%c",hexa->info);
        hexa=hexa->prox;
    }

    return 1;
}