/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <thomazllr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:12:37 by thomazllr         #+#    #+#             */
/*   Updated: 2023/11/01 10:23:49 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{
    int x, y;

    printf("Digite dois numeros --> ");
    scanf("%d %d", &x, &y);

    calcula(&x, &y);

    printf("Soma ==> %d\n", x);
    printf("Subtração ==> %d", y);

    return 0;
}