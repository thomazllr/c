#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    FILE *file;
    file = fopen("dados.txt", "r");
    setlocale(LC_ALL, "pt_BR.utf8");
    int produtos[50][2][15] = {{{0}}}, k, i, semana, produtor, option;
    int op;

    // for (k = 0; k < 3; k++)
    // {
    //     printf("\n\nSEMANA [%d]\n\n", k + 1);
    //     for (i = 0; i < 50; i++)
    //     {
    //         printf("PRODUTOR [%d]\n\n", i + 1);
    //         printf("DIGITE O NUMERO DE ALFACES ==> ");
    //         scanf("%d", &produtos[i][0][k]);
    //         printf("DIGITE O NUMERO DE REPOLHOS ==> ");
    //         scanf("%d", &produtos[i][1][k]);
    //         printf("Deseja continuar -> ");
    //         scanf(" %c", &op);
    //         if (op == 'n')
    //         {
    //             break;
    //         }
    //     }
    // }

    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 50; i++)
        {
            fscanf(file, "%d %d", &produtos[i][0][k], &produtos[i][1][k]);
        }
    }

    fclose(file);

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
            printf("Digite a semana que deseja buscar ==> ");
            scanf("%d", &semana);
            semana--;
            relatorioSemana(produtos, semana);
            break;

        case 2:
            printf("Digite o produtor que deseja verificar ==> ");
            scanf("%d", &produtor);
            produtor--;
            relatorioProdutor(produtos, produtor);
            break;
        case 3:
            relatorioAbastecimento(produtos);
            break;
        }
    } while (op != 4);

    return 0;
}
