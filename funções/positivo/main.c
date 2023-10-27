/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:57:42 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/26 23:57:42 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{

    int x;

    printf("DIGITE UM NUMERO ==> ");
    scanf("%d", &x);
    verify(x);

    return 0;
}