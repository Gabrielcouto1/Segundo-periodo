#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"
#define MAX 5
#define BOX 3
#define STR 8

void simula_horaSaida (struct tm *, struct tm **);

int main()
{
    int i = 0;
    int n, b;
    Carro A, Lixo;
    Fila N[BOX];
    char pl[STR];

    while (i < BOX)
    {
        N[i] = cria_fila();
        i++;
    }

    while (1)
    {
        printf("Escolha uma das seguintes opcoes: \n");
        printf("[1] Entrada de veiculos\n");
        printf("[2] Saida de veiculos\n");
        printf("[3] Visualizacao do cenario\n");
        printf("[4] Encerrar o programa\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &n);

        if (n == 1)
        {
            i = 1;
            b = 0;

            while (i < BOX)
            {
                if (fila_tam(N[b]) > fila_tam(N[i]))
                {
                    b = i;
                }
                i++;
            }

            printf("Digite a placa do veiculo a ser adicionado: ");
            getchar();
            scanf("%s", A.placa);

            printf("\n'A' para servico avulso\n");
            printf("'M' para servico mensal\n");
            printf("Digite o tipo de servico: ");
            getchar();
            scanf("%c", &A.servico);

            time_t horas;
            time (&horas);
            A.hora = horas;

            if (insere_fim(N[b], A))
                printf("Veiculo adicionado com sucesso no box %d", b+1);
            else
                printf("Veiculo nao adicionado");
        }

        else if (n == 2)
        {
            i = 0;
            int verif = 0;

            printf("Digite a placa do veiculo a ser removido: ");
            getchar();
            scanf("%s", pl);

            while (i < BOX)
            {
                Fila L = cria_fila();
                while(!fila_vazia(N[i]))
                {
                    remove_inicio(N[i], &A);

                    if (strcmp(A.placa, pl) != 0)
                        insere_fim(L, A);
                    else
                    {
                        verif = 1;
                        Lixo = A;
                        b = i;
                    }

                }
                while(!fila_vazia(L))
                {
                    remove_inicio(L, &A);
                    insere_fim(N[i], A);
                }
                apaga_fila(&L);
                i++;
            }
            if (verif)
            {
                printf("\nVeiculo com a placa %s retirado da box %d\n", Lixo.placa, b+1);

                struct tm * tempo, * fi;
                float total = 0;

                fi = localtime(&Lixo.hora);
                simula_horaSaida(fi, &tempo);
                printf("O veiculo ficou das %d horas e %d minutos ate as %d horas %d e minutos",fi->tm_hour, fi->tm_min, tempo->tm_hour, tempo->tm_min);

                if (Lixo.servico == 'A')
                {
                    if ( (tempo->tm_min -= fi->tm_min) < 0)
                    {
                        tempo->tm_hour--;
                    }
                    else if (tempo->tm_min > 10)
                    {
                        tempo->tm_hour++;
                    }

                    tempo->tm_hour -= fi->tm_hour;

                    if (tempo->tm_hour > 0)
                    {
                        total = 7;
                        total += tempo->tm_hour;
                    }
                    printf("\n\nTotal a ser pago: R$ %.2f", total);
                }

            }
            else
                printf("\nVeiculo nao encontrado");

        }

        else if (n == 3)
        {
            i = 0;
            while (i < BOX)
            {
                printf("\n\nBOX %d:", i+1);

                if (fila_vazia(N[i]))
                {
                    printf("\nNenhum carro estacionado\n");
                    i++;
                    continue;
                }

                Fila L = cria_fila();

                while(!fila_vazia(N[i]))
                {
                    remove_inicio(N[i], &A);

                    printf("\n\nPlaca do veiculo: %s\n", A.placa);
                    printf("Tipo de servico: ");
                    if (A.servico == 'A')
                        printf("Avulso\n");
                    else
                        printf("Mensal\n");
                    printf("Horas:    %d\n", localtime(&A.hora)->tm_hour);
                    printf("Minutos: %d", localtime(&A.hora)->tm_min);

                    insere_fim(L, A);
                }

                while(!fila_vazia(L))
                {
                    remove_inicio(L, &A);
                    insere_fim(N[i], A);
                }

                apaga_fila(&L);
                i++;
            }
        }

        else if(n == 4)
        {
            break;
        }

        else
            printf("Digite um numero valido!\n");

        printf("\n\n");
    }


    return 0;
}

void simula_horaSaida (struct tm * tempo, struct tm **pagar)
{
    srand(time(NULL));
    int h = (rand() % 10) + 1;
    int m = rand() % 60;

    (*pagar)->tm_hour = h + tempo->tm_hour;

    if ( ((*pagar)->tm_min = m + tempo->tm_min) >= 60)
    {
        (*pagar)->tm_hour++;
        (*pagar)->tm_min = (*pagar)->tm_min - 60;
    }
    return;
}
