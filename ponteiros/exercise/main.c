/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <thomazllr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:26:29 by thomazllr         #+#    #+#             */
/*   Updated: 2023/11/01 08:40:14 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{
    float number;

    printf("Digite um numero em decilmal --> ");
    scanf("%f", &number);

    printf("Formato Percentual %.2f", percent(number));

    return 0;
}