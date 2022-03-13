#include <stdio.h> 
#include <stdlib.h> 

int main(){
    char c[33]="5";
    char d[33]="A";
    int cc;
    int dd;

    cc=atoi(c);
    dd=atoi(d);

    printf("\nc=%d\n",cc);
    printf("\nd=%d\n",dd);

    cc=10;
    dd=7;

    printf("\n%d ^ %d = %d\n",cc,dd,cc^dd);

    return 1;

}