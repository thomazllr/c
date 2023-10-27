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
    int i, total_aulas, status;
    float notaA, notaB, notasBimestrais[4], final, presenca = 0;

    printf("Digite o total de aulas --> ");
    scanf("%d", &total_aulas);
    printf("Digite a presença do aluno --> ");
    scanf("%f", &presenca);

    presenca = calculoPresenca(presenca, total_aulas);

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

    final = notaFinal(notasBimestrais);
    printf("\n\nNOTA FINAL ==> %.2f\n", final);

    // status(final, presenca);

    status = statusInt(final, presenca);

    if (status == 0)
    {
        printf("Reprovado\n");
    }
    else if (status == 1)
    {
        printf("Aprovado\n");
    }
    else
    {
        printf("Recuperação\n");
    }
}