#include <stdio.h>
#include "functions.h"

int relatorioSemana(int i, int semana, int soma_alface, int soma_repolho, int m[][2][15])
{
    soma_alface = 0;
    soma_repolho = 0;
    printf("Digite a semana que deseja buscar ==> ");
    scanf("%d", &semana);
    for (i = 0; i < 50; i++)
    {
        soma_alface += m[i][0][semana];
        soma_repolho += m[i][1][semana];
    }
    printf("Total de alfaces ==> %d", soma_alface);
    printf("Total de repolho ==> %d", soma_repolho);
    return 0;
}

int relatorioProdutor()
{
}

int relatorioAbastecimento()
{
}