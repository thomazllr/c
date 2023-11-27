#include <stdio.h>
#include "header.h"

int main()
{
    Car carro[25];

    counter_Data cont = {0};

    FILE *file = fopen("binario", "wb");

    readData(carro, &cont);

    if (file == NULL)
    {
        printf(RED "ERROR: Arquivo inexistente" RESET "\n");
        fclose(file);
        return 1;
    }
    printf(GREEN "\nArquivo salvo com sucesso!" RESET "\n");

    fwrite(&carro, sizeof(Car), 25, file);
    fwrite(&cont, sizeof(counter_Data), 1, file);

    printf("%d\n\n", cont.total_registers);

    fclose(file);
    return 0;
}