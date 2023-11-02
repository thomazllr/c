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