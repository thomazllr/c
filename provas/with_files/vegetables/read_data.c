#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Producers producers[15][50];
    data_Counter data_counter = {0};

    readData(producers, &data_counter);

    FILE *file = fopen("dados.bin", "wb");
    if (file == NULL)
    {
        printf(RED "Não foi possível abrir o arquivo\n\n" RESET);
    }
    fwrite(&producers, sizeof(Producers), 15 * 50, file);
    fwrite(&data_counter, sizeof(data_Counter), 1, file);
    printf(GREEN "Dados salvos com sucesso!" RESET);

    return 0;
}