#include <stdio.h>
#include "header.h"

int main() {
    Car carro[25];

    counter_Data cont = {0};

    FILE *file = fopen("binario", "rb");
    
    if (file == NULL)
    {
        printf("\nERROR: Arquivo inexistente.\n");
        fclose(file);
        return 1;
    }
    printf("\nResgatando dados!\n");

    for(int i = 0; i < 2 ; i++) {
        fread(&carro[i], sizeof(Car), 1, file);
    }
    fread(&cont, sizeof(counter_Data), 1, file);
    fclose(file);

    relatorioGeral(carro, cont.total_registers);

    return 0;
}