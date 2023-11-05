#include <stdio.h>
#include "functions.h"

int relatorioSemana(int m[][2][15], int semana)
{
    int i, soma_alface = 0, soma_repolho = 0;
    for (i = 0; i < 50; i++)
    {
        soma_alface += m[i][0][semana];
        soma_repolho += m[i][1][semana];
    }

    printf("Total de alfaces ==> %d\n", soma_alface);
    printf("Total de repolho ==> %d\n", soma_repolho);
    return 0;
}

int relatorioProdutor(int m[][2][15], int produtor)
{
    int i, k, soma_alface = 0, soma_repolho = 0;
    for (k = 0; k < 3; k++)
    {
        soma_alface += m[produtor][0][k];
        soma_repolho += m[produtor][1][k];
    }
    printf("Total de alfaces ==> %d\n", soma_alface);
    printf("Total de repolho ==> %d\n", soma_repolho);
    return 0;
}

int relatorioAbastecimento(int m[][2][15])
{
    int i, k, soma_alface, soma_repolho, total_alface = 0, total_repolho = 0, zeradas = 0;

    for (k = 0; k < 15; k++)
    {
        soma_alface = 0;
        soma_repolho = 0;
        for (i = 0; i < 50; i++)
        {
            soma_alface += m[i][0][k];
            soma_repolho += m[i][1][k];
        }
        if (soma_alface == 0 && soma_alface == 0)
        {
            zeradas++;
        }
        total_alface += soma_alface;
        total_repolho += soma_repolho;
    }
    printf("Total de alfaces no periodo ==> %d\n", total_alface);
    printf("Total de repolho no periodo ==> %d\n", total_repolho);

    if (soma_alface + soma_repolho < 500)
    {
        printf("\033[31m");
        printf("\n\nRISCO DE DESABASTECIMENTO\n\n");
        printf("\033[0m");
    }
    else if (total_alface > 1300 || total_repolho > 1200)
    {
        printf("\033[32m");
        printf("\n\nSUPER PRODUCTION\n\n");
        printf("\033[0m");
    }

    if (zeradas > 0)
    {
        printf("Houve semanas zeradas\n\n");
    }
    return 0;
}
