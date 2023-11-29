#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menu()
{
    printf("\t1-RELATORIO DA SEMANA\n");
    printf("\t2-RELATORIO POR PRODUTOR\n");
    printf("\t3- RELATORIO DE ANALISE DE ABASTECIMENTO\n");
    printf(RED "\t4- SAIR" RESET);
}

void readData(Producers producers[15][50], data_Counter *data)
{
    char op;
    for (int i = 0; i < 3; i++)
    {
        printf("\tSEMANA [%d]\n\n", i + 1);
        for (int j = 0; j < 50; j++)
        {
            printf("\tPRODUTOR [%d]\n\n", j + 1);

            printf("Digite a quantidade de alfaces: ");
            scanf("%d", &producers[i][j].lettuce);
            printf("Digite a quantidade de repolhos: ");
            scanf("%d", &producers[i][j].cabagge);
            data->total_byweek[0][i] = producers[i][j].lettuce;
            data->total_byweek[1][i] = producers[i][j].cabagge;
            data->total_byproducer[0][j] = producers[i][j].lettuce;
            data->total_byproducer[1][j] = producers[i][j].cabagge;
            printf("Deseja adicionar mais um produtor? ==> ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }
}

void reports_byweek(Producers producers[15][50], data_Counter data)
{
    int semana, total;
    printf("\tDigite a semana que deseja buscar ==> ");
    scanf("%d", &semana);

    total = data.total_byweek[0][semana] + data.total_byweek[1][semana];

    printf("Total de alfaces da semana [%d] ==> %d\n", semana + 1, data.total_byweek[0][semana]);
    printf("Total de repolhos da semana [%d] ==> %d\n", semana + 1, data.total_byweek[1][semana]);
    printf("Total da semana ==> %d\n", total);
    system("pause");
}

void reports_byproducer(Producers producers[15][50], data_Counter data)
{
}