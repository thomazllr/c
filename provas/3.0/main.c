#include <stdio.h>
#include "header.h"

int main() {
    Car carro[25];
    counter_Data cont = {0};

    createFile(carro, &cont);

    printf("%d\n", cont.total_registers);

    // Relatorios

    relatorioGeral(carro, cont.total_registers);

    return 0;
}