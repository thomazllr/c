/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <Hi! I'm a student at UFT>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:38:30 by thomazllr         #+#    #+#             */
/*   Updated: 2023/10/29 14:38:30 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "function.h"

int main()
{
    int var = 5;
    int *p;

    p = &var;

    status(var, p);

    changeNumber(&var);

    status(var, p);

    return 0;
}