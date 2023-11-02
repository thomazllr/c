/****************************************************************************************/
/*                                                                                      */
/*                                                ___  ___  ________ _________          */
/*   main.c                                      |\  \|\  \|\  _____\\___   ___\        */
/*                                               \ \  \\\  \ \  \__/\|___ \  \_|        */
/*   By: thomazllr <Hi! I'm a student at UFT>     \ \  \\\  \ \   __\    \ \  \         */
/*                                                 \ \  \\\  \ \  \_|     \ \  \        */
/*   Created: 2023/10/26 22:25:09 by thomazllr      \ \_______\ \__\       \ \__\       */
/*   Updated: 2023/11/01 00:30:31 by thomazllr       \|_______|\|__|        \|__|.uft   */
/*                                                                                      */
/* **************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "functions.h"
#include "produtor.h"

#define QT_PRODUTOR 50
#define SEMANAS 3

int main()
{
    produtor produtor[QT_PRODUTOR][SEMANAS] = {0};
    int i, k, option, semana, um;
    char op;

    for (k = 0; k < SEMANAS; k++)
    {
        printf("\nSEMANA [%d]\n\n", k + 1);
        for (i = 0; i < QT_PRODUTOR; i++)
        {
            printf("PRODUTOR [%d]\n\n", i + 1);
            puts("Quantidade de alface --> ");
            scanf("%d", &produtor[i][k].alface);
            puts("Quantidade de repolho --> ");
            scanf("%d", &produtor[i][k].repolho);
            printf("Deseja continuar? ==> ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }

    system("cls");

    do
    {
        printf("1-Relatorio por Semana\n"
               "2-Relatorio por Produtor\n"
               "3-Relatorio de abastecimento\n"
               "4-Sair\n");
        printf("\n\nQual opcao deseja buscar ==> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Qual semana deseja buscar? ");
            scanf("%d", &semana);
            semana--;
            relatorioSemana(produtor, semana);
            break;
        case 2:
            printf("Qual produtor deseja conferir? ");
            scanf("%d", &um);
            um--;
            relatorioProdutor(produtor, um);
            break;

        default:
            break;
        }

    } while (option != 4);

    return 0;
}