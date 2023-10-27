/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:28:44 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/27 00:28:44 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions.h"

int main()
{
    int i;
    float notaA, notaB, notasBimestrais[4], final;

    for (i = 0; i < 4; i++)
    {
        printf("\n\nBIMESTRE [%d]\n\n", i + 1);
        printf("Digite da prova ==> ");
        scanf("%f", &notaA);
        printf("Digite a nota do trabalho ==> ");
        scanf("%f", &notaB);
        notasBimestrais[i] = notaBimestral(notaA, notaB);
        printf("Nota do bimestre ==> %2.f", notasBimestrais[i]);
    }

    final = notaFinal(notasBimestrais[0], notasBimestrais[1], notasBimestrais[2], notasBimestrais[3]);
    printf("\n\nNOTA FINAL ==> %.2f", final);
}