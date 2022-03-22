#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct no{
    int tipo;
    union{
        int i_int;
        char i_char;
    }info;
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
    
    int aux;
        
    if(elem>=48&&elem<=57){
        aux=elem-48;
        N->info.i_int=aux;
        N->tipo=0;
    }
    else{
        N->info.i_char=elem;
        N->tipo=1;
    }
        
    N->prox=*p;
    *p=N;

    return 1;
}

int pop(Pilha *p, char *elem){
    if(pilha_vazia(*p))
        return 0;

    Pilha aux=*p;

    if((*p)->tipo==1)
        *elem=aux->info.i_char;
    else   
        *elem=aux->info.i_int;
    
    *p=aux->prox;
    free(aux);

    return 1;
}   

int le_topo(Pilha *p, char *elem){
    if(pilha_vazia(*p))
        return 0;
    
    if((*p)->tipo==1)
        *elem=(*p)->info.i_char;
    else   
        *elem=(*p)->info.i_int;

    return 1;
}

void mostra_pilha(Pilha p){
    if(pilha_vazia(p))
        printf("\nA pilha esta vazia.");

    else{
        Pilha aux=p;
        printf("\n");
        while(aux!=NULL){
            if(aux->tipo==1)
                printf("%c\n",aux->info.i_char);
            else 
                printf("%d\n",aux->info.i_int);
            
            aux=aux->prox;
        }
    }
}

int verificar_escopo(char elem[]){
    int i;
    char aux,aux1='\0';
    Pilha pilha1=cria_pilha();

    for(i=0;elem[i]!='\0';i++){
        if(elem[i]=='{'||elem[i]=='['||elem[i]=='('){
            if(push(&pilha1,elem[i])==0)
                return 0;
            switch(elem[i]){
                case '{':
                    if(aux1=='('||aux1=='[')
                        return 2;
                    break;
                case '[':
                    if(aux1=='(')
                        return 2;
                    break;
                case '\0':
                    break;
                default:
                    break;
            }
            aux1=elem[i];
        }
            

        if(elem[i]=='}'||elem[i]==']'||elem[i]==')'){
            if(pop(&pilha1,&aux)==0)
                return 0;
                
            switch(aux){
                case '(':
                    if(elem[i]!=')')
                        return 3;
                    break;
                case '[':
                    if(elem[i]!=']')
                        return 3;
                    break;
                case '{':
                    if(elem[i]!='}')
                        return 3;
                    break;
                default: 
                    break;
            }
        }
    }

    if(pilha_vazia(pilha1)==1)
        return 1;
    else 
        return 3;
}

int infixa_posfixa(char elem[]){
    int i,cont=0;
    char saida[255]="\0";

    Pilha pilha1=cria_pilha();

    for(i=0;elem[i]!='\0';i++){
        if(elem[i]=='('||elem[i]=='['||elem[i]=='{')
            continue;

        if((elem[i]>='0'&&elem[i]<='9')||(elem[i]>='A'&&elem[i]<='Z')||(elem[i]>='a'&&elem[i]<='z')){
            saida[cont]=elem[i];
            cont++;
        }

        if(elem[i]=='-'||elem[i]=='+'||elem[i]=='*'||elem[i]=='/'||elem[i]=='^')
            if(push(&pilha1,elem[i])==0)
                return 0;
            
        if(elem[i]==')'||elem[i]==']'||elem[i]=='}'){
            if(pop(&pilha1,&saida[cont])==0)
                return 0;
            else    
                cont++;
        }
    }

    if(pilha_vazia(pilha1)==1){
        strcpy(elem,saida);
        return 1;
    }
    else 
        return 0;
}

int avaliar_posfixa(){
    
}