#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha{
    char info[max];
    int topo;
};

Pilha cria_pilha(){
    Pilha p;
    p=(Pilha)malloc(sizeof(struct pilha));

    if(p!=NULL)
        p->topo=-1;

    return p;
}

int pilha_vazia(Pilha p){
    if(p->topo=1)
        return 1;

    return 0;
}

int pilha_cheia(Pilha p){
    if(p->topo==max-1)
        return 1;
    return 0;
}

int push(Pilha p, char elem){
    if(p==NULL||pilha_cheia(p)==1)
        return 0;

    p->topo++;
    p->info[p->topo]=elem;
    return 1;
}

int pop(Pilha p, char *elem){
    if(p==NULL||pilha_vazia(p)==1)
        return 0;

    *elem=p->info[p->topo];
    p->topo--;

    return 1;
}

int le_topo(Pilha p, char *elem){
    if(p==NULL||pilha_vazia(p)==1)
        return 0;

    *elem=p->info[p->topo];

    return 1;
}

void mostra_pilha(Pilha p){
    if(pilha_vazia(p))
        printf("\nA pilha esta vazia.");

    else{
        int i;
        for(i=0;i<max;i++)
            printf("\n%c",p->info[i]);
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
    int res,cont=0;
    char r;
    int numdec=num,num1=num;

    while(num!=0){
        res=num%2;
        r=res+48;
        if(push(binario,r)==0)
            return 0;
        else
            cont++;
        num/=2;
    }

    printf("Numero decimal: %d\nNumero binario: ",numdec);

    int i;
    for(i=cont;i>=0;i--)
        printf("%c",binario->info[i]);

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
    int res,cont=0;
    char r;
    int num1=num;


    while(num!=0){
        res=num%8;
        r=res+48;
        if(push(octal,r)==0)
            return 0;
        else
            cont++;
        num/=8;
    }

    printf("Numero decimal: %d\nNumero octal: ",num1);

    int i;
    for(i=cont;i>=0;i--)
        printf("%c",octal->info[i]);

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
    int res,cont=0;
    char aux;
    char r;
    int num1=num;

    while(num!=0){
        res=num%16;
        r=res+48;

        if(res>=10){
            switch(res){
                case 10:
                    if(push(hexa,'A')==0)
                        return 0;
                    else
                        cont++;

                    break;
                case 11:
                    if(push(hexa,'B')==0)
                        return 0;
                    else
                        cont++;

                    break;
                case 12:
                    if(push(hexa,'C')==0)
                        return 0;
                    else
                        cont++;

                    break;
                case 13:
                    if(push(hexa,'D')==0)
                        return 0;
                    else
                        cont++;

                    break;
                case 14:
                    if(push(hexa,'E')==0)
                        return 0;
                    else
                        cont++;

                    break;
                case 15:
                    if(push(hexa,'F')==0)
                        return 0;
                    else
                        cont++;

                    break;
                default:
                    break;
            }
        }
        if(res<10){
            if(push(hexa,r)==0)
                return 0;
            else
                cont++;
        }
        num/=16;
    }

    printf("Numero decimal: %d\nNumero hexa: ",num1);

    int i;
    for(i=cont;i>=0;i--)
        printf("%c",hexa->info[i]);

    return 1;
}

void exclui_pilha(Pilha *p){
    free(*p);
    *p=NULL;
}

Pilha apaga_pilha(Pilha *p){
    exclui_pilha(p);
    return cria_pilha();
}
