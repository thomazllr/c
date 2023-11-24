#include <stdio.h>
#include "header.h"

int main() {
    Car carro[25];

    counter_Data cont = {0};

    FILE *file = fopen("binario", "ab");

    readData(carro, &cont);

    
    if (file == NULL)
    {
        printf("\nERROR: Arquivo inexistente.\n");
        fclose(file);
        return 1;
    }
    printf("\nArquivo salvo com sucesso!\n");

    for (int i = 0; i < 2 ; i++) {
        fwrite(&carro[i], sizeof(Car), 1, file);
    }
    fwrite(&cont, sizeof(counter_Data), 1, file);
    fclose(file);
    return 0;
}