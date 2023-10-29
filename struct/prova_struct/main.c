/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:17:11 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/28 20:17:11 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define QT_PRODUTOR 50
#define SEMANAS 15

struct produtor
{
    int alface;
    int repolho;
};

typedef struct produtor produtor;

int main()
{
    produtor produtor[SEMANAS];
    int i, k;
    char op;

    for (k = 0; k < SEMANAS; k++)
    {
        printf("\nSEMANA [%d]\n\n", k + 1);
        for (i = 0; i < QT_PRODUTOR; i++)
        {
            printf("PRODUTOR [%d]\n\n", i + 1);
            puts("Quantidade de alface --> ");
            scanf("%d", &produtor[k].alface);
            puts("Quantidade de repolho --> ");
            scanf("%d", &produtor[k].repolho);
            printf("Deseja continuar? ==> ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }

    do
    {

    } while (op != 4);

    return 0;
}