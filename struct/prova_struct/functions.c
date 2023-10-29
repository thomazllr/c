#include <stdio.h>
#include "functions.h"
#include "produtor.h"

#define QT_PRODUTOR 50
#define SEMANAS 3

int relatorioSemana(produtor produtor[][SEMANAS], int semana)
{
    int i, soma_alface = 0, soma_repolho = 0;
    for (i = 0; i < QT_PRODUTOR; i++)
    {
        soma_alface += produtor[i][semana].alface;
        soma_repolho += produtor[i][semana].repolho;
    }

    printf("Total de alfaces ==> %d\n", soma_alface);
    printf("Total de repolho ==> %d\n", soma_repolho);
    return 0;
}

int relatorioProdutor(produtor produtor[][SEMANAS], int um)
{
    int k, soma_alface = 0, soma_repolho = 0;
    for (k = 0; k < SEMANAS; k++)
    {
        soma_alface += produtor[um][k].alface;
        soma_repolho += produtor[um][k].repolho;
    }

    printf("Total de alfaces ==> %d\n", soma_alface);
    printf("Total de repolho ==> %d\n", soma_repolho);
    return 0;
}