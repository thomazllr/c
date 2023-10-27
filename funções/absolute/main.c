/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:09:55 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/27 00:09:55 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{

    int x, valorAbsoluto;

    printf("DIGITE UM VALOR PARA CONSEGUIR O VALOR ABSOLUTO ==> ");
    scanf("%d", &x);

    valorAbsoluto = absolute(x);
    printf("Valor absoluto -> %d", valorAbsoluto);

    return 0;
}