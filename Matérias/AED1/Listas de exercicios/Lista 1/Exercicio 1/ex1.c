/*


    https://github.com/gabrielcouto1
*/

#include <stdio.h>
#include <string.h> 


struct Funcionarios{    //Inicializacao da estrutura Funcionarios
    int matricula;
    char nome[100];
    int idade;
    char cargo[100];
    float salario;
};

void consulta(struct Funcionarios func[10]);
void cadastro(struct Funcionarios func[10]);
void exibeDados(int j, struct Funcionarios func[10]);

int main()
{
    struct Funcionarios func[10];
    int i;
    
    cadastro(func); //Chama a funcao de cadastro com a estrutura criada anteriormente
    consulta(func); //Chama a funcao consulta, com os dados obtidos na funcao cadastro

    return 0;  //Encerra o programa e retorna o valor 0
}

void cadastro(struct Funcionarios func[10]){
    int i;
    char c; //variavel que ira armazenar os residuos do teclado

    for (i=0;i<10;i++){
        printf("\nInsira a matricula do funcionario numero %d: ",i+1);
        scanf("%d",&func[i].matricula);
        scanf("%c",&c);     //Coleta de residuo da ultima coleta do teclado

        if(func[i].matricula==0)    //Se o usuario digita 0 no numero de matricula, a funcao para
            break;

        printf("\nInsira o nome do funcionario numero %d: ",i+1);
        scanf("%[^\n]%*c",func[i].nome);

        printf("\nInsira a idade do funcionario numero %d: ",i+1);
        scanf("%d",&func[i].idade);
        scanf("%c",&c);     //Coleta de residuo da ultima coleta do teclado

        printf("\nInsira o cargo do funcionario numero %d: ",i+1);
        scanf("%[^\n]%*c",func[i].cargo);

        printf("\nInsira o salario do funcionario numero %d: ",i+1);
        scanf("%f",&func[i].salario);
        
    }
    printf("\n\n\n\n\n\n");
}

void consulta(struct Funcionarios func[10]){
    int i,j;    //Variavel auxiliar para verificar qual o funcionario foi achado pela consulta
    char pesquisa[100],c;   //Variavel que armazena o nome que o usuario digitou para consultar
    int fim=1;  //variavel para verificar se o usuario digitou FIM para finalizar a consulta

    do{
        for(i=0;i<90;i++)
            printf("=");

        printf("\n\n\t\tInsira o nome do funcionario que deseja exibir os dados: \n");
        scanf("%[^\n]%*c",pesquisa);
        fim=strcmp(pesquisa,"FIM"); //Se o usuario digitar "FIM", retornara 0

        if (fim==0)
            break;  
        
        for (i=0;i<10;i++){//Realiza a pesquisa do nome que foi inserido 
            j=-1;
            if(strcmp(func[i].nome,pesquisa)==0){
                j=i;
                break;
            }
        }
        if (j!=-1)  //Se 
            exibeDados(j,func);
        else
            fprintf(stderr,"\nNao achamos nenhum funcionario com o nome %s.\nTente novamente.\n",pesquisa);
    }while(1);
}

void exibeDados(int j, struct Funcionarios func[10]){   //Exibe os dados do funcionario numero j+1
    int i;

    for(i=0;i<90;i++)
        printf("=");

    printf("\n\nMatricula do funcionario numero %d: %d ",j+1,func[j].matricula);
    printf("\nNome do funcionario numero %d     : %s ",j+1,func[j].nome);
    printf("\nIdade do funcionario numero %d    : %d ",j+1,func[j].idade);
    printf("\nCargo do funcionario numero %d    : %s",j+1,func[j].cargo);
    printf("\nSalario do funcionario numero %d  : %.2f\n",j+1,func[j].salario);
}