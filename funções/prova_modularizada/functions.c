#include <stdio.h>
#include "functions.h"

int relatorioSemana(int m[][2][15], int semana, int qtd)
{
    int i, k, soma_alface = 0, soma_repolho = 0;
    for (i = 0; i < qtd; i++)
    {
        soma_alface += m[i][0][semana];
        soma_repolho += m[i][1][semana];
    }

    printf("Total de alfaces ==> %d\n", soma_alface);
    printf("Total de repolho ==> %d\n", soma_repolho);
    return 0;
}
