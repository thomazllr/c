/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <thomazllr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:08 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/27 11:05:21 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "pt_BR.utf8");
    int produtos[50][2][15] = {{{0}}}, k, i, cont[15], semana, produtor;
    char op;

    for (k = 0; k < 3; k++)
    {
        printf("\n\nSEMANA [%d]\n\n", k + 1);
        cont[k] = 0;
        for (i = 0; i < 50; i++)
        {
            cont[k]++;
            printf("PRODUTOR [%d]\n\n", i + 1);
            printf("DIGITE O NUMERO DE ALFACES ==> ");
            scanf("%d", &produtos[i][0][k]);
            printf("DIGITE O NUMERO DE REPOLHOS ==> ");
            scanf("%d", &produtos[i][1][k]);
            printf("Deseja continuar -> ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }

    do
    {
        printf("1-Relatorio por Semana\n"
               "2-Relatorio por Produtor\n"
               "3-Relatorio de abastecimento\n");
        printf("\n\nQual opcao deseja buscar ==> ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite a semana que deseja buscar ==> ");
            scanf("%d", &semana);
            relatorioSemana(produtos, semana, cont[semana]);
            break;
        case 2:
            printf("Digite o produtor que deseja verificar ==> ");
            scanf("%d", &produtor);
            relatorioProdutor(produtos, produtor);
            break;
        case 3:
            relatorioAbastecimento(produtos);
            break;
        }

    } while (op != 4);

    return 0;
}