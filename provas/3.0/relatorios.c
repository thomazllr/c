#include <stdio.h>
#include "header.h"

int main() {
    Car carro[25];

    counter_Data cont = {0};

    FILE *file = fopen("binario", "rb");
    
    if (file == NULL)
    {
        printf("\nERROR: Arquivo inexistente.\033[0m\n");
        fclose(file);
        return 1;
    }
    printf(GREEN "Restaurando dados!" RESET "\n");

    fread(&carro, sizeof(Car), 25, file);
    fread(&cont, sizeof(counter_Data), 1, file);
    fclose(file);


    relatorioGeral(carro, cont.total_registers);

    return 0;
}