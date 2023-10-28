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

int main()
{

    int produtos[50][2][15], k, i, cont[15], semana;
    char op;

    for (k = 0; k < 3; k++)
    {
        printf("\n\nSEMANA [%d]\n\n", k + 1);
        cont[k] = 0;
        for (i = 0; i < 50; i++)
        {
            cont[k]++;
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
    printf("Digite a semana que deseja buscar ==> ");
    scanf("%d", &semana);
    relatorioSemana(produtos, semana, cont[semana]);

    return 0;
}