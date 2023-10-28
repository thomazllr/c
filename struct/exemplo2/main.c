/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:57:38 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/28 19:57:38 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define TAM 3

struct tipo_pessoa
{
    int idade;
    float peso;
    char nome[50];
};

typedef struct tipo_pessoa pessoa;

int main()
{
    pessoa lista[TAM];
    int i;

    printf("DIGITE OS DADOS DAS PESSOAS ABAIXO: \n\n");
    for (i = 0; i < TAM; i++)
    {
        printf("\n");
        puts("Nome ==> ");
        scanf("%50[^\n]s", &lista[i].nome);
        fflush(stdin);

        puts("Idade ==> ");
        scanf("%d", &lista[i].idade);
        fflush(stdin);

        puts("Peso ==> ");
        scanf("%f", &lista[i].peso);
        fflush(stdin);
    }
    system("cls");

    for (i = 0; i < TAM; i++)
    {
        printf("\n\nPESSOA [%d]\n\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Idade: %d\n", lista[i].idade);
        printf("Peso: %.2f\n", lista[i].peso);
    }
    return 0;
}