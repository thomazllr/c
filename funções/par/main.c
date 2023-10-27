/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:50:22 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/26 23:50:22 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{
    int x;

    printf("Digite um numero ==> ");
    scanf("%d", &x);

    par_ou_impar(x);

    return 0;
}