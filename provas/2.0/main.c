#include <stdio.h>
#include "header.h"

int main()
{
    Car carro[25];
    int cont = 0;

    Dealership(carro, &cont);
   
    printf("%d\n", cont);
    // Relatórios
    relatorioGeral(carro, cont);
}