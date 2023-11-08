/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <thomazllr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:07:13 by thomazllr         #+#    #+#             */
/*   Updated: 2023/11/01 09:33:42 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{

    int a, b, c;

    printf("Leia os valores --> ");
    scanf("%d %d %d", &a, &b, &c);

    maiorMenor(&a, &b, &c);

    printf("\nMaior numero -> %d\n", c);
    printf("\nMedio --> %d\n", b);
    printf("\nMenor numero --> %d\n", a);
    return 0;
}