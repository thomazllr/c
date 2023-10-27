/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:03:40 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/27 00:03:40 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{

    int x, y, maior;

    printf("DIGITE DOIS NUMEROS ==> ");
    scanf("%d %d", &x, &y);
    maior = higherNumber(x, y);
    printf("\nMAIOR NUMERO = %d", maior);

    return 0;
}