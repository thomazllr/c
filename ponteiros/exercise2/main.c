/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <thomazllr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:43:27 by thomazllr         #+#    #+#             */
/*   Updated: 2023/11/01 08:54:02 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{
    float number;

    printf("Digite um numero em decilmal --> ");
    scanf("%f", &number);

    percent(&number);

    printf("Formato Percentual %.2f %%", number);

    return 0;
}