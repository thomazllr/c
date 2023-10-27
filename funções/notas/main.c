/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:14:27 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/27 00:14:27 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{

    float notaA, notaB, notaC, notaFinal;
    char op;

    printf("Digite as notas dos aluno ==> ");
    scanf("%f %f %f", &notaA, &notaB, &notaC);
    printf("O que deseja calcular?\n\n"
           "A - Media Aritmetica\n\n"
           "P - Media Ponderada\n\n"
           "Option --> ");
    scanf(" %c", &op);

    notaFinal = calculoNotas(notaA, notaB, notaC, op);

    printf("Nota final do aluno ==> %.2f", notaFinal);

    return 0;
}