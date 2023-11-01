/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomazllr <thomazllr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:25:09 by thomazllr         #+#    #+#             */
/*   Updated: 2023/11/01 00:30:31 by thomazllr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>

int main()
{

  float x, y, result;
  int op;

  printf("Digite dois numeros ==> ");
  scanf("%f %f", &x, &y);

  do
  {
    printf("\n\n== CALCULADORA ==\n\n"
           "O que deseja fazer\n\n?"
           "\n\n1-Soma\n2-Sub\n3-Multi\n4-Divisao\n"
           "5-Trocar os numeros\n6-Sair\nOption ==> ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      result = somar(x, y);
      printResult(result);
      break;
    case 2:
      result = sub(x, y);
      printResult(result);
      break;
    case 3:
      result = multi(x, y);
      printResult(result);
      break;
    case 4:
      result = divi(x, y);
      if (result == 0)
      {
        break;
      }
      printResult(result);
      break;
    case 5:
      changeNumber(&x, &y);
    default:
      break;
    }
  } while (op != 6);

  return 0;
}
