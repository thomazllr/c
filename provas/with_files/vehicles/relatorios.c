#include <stdio.h>
#include "header.h"

int main()
{
    Car carro[25];
    counter_Data cont = {0};
    int op, i;

    FILE *file = fopen("binario", "rb+");

    if (file == NULL)
    {
        printf("\nERROR: Arquivo inexistente.\033[0m\n");
        fclose(file);
        return 1;
    }
    printf(GREEN "Restaurando dados!" RESET "\n");

    fread(&carro, sizeof(Car), 25, file);
    fread(&cont, sizeof(counter_Data), 1, file);

    do
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            relatorioGeral(carro, cont.total_registers);
            break;
        case 2:
            relatorioCores(carro, cont.total_registers);
            break;
        case 3:
            relatorioCodigo(carro, cont.total_registers);
            break;
        case 4:
            relatorioVeiculo(carro, cont.total_registers);
            break;
        case 5:
            addOneVehicle(carro, &cont);
            break;
        default:
            break;
        }

    } while (op != 6);

    file = fopen("binario", "wb");

    if (file == NULL)
    {
        printf("\nERROR: Arquivo inexistente.\033[0m\n");
        fclose(file);
        return 1;
    }
    fwrite(&carro, sizeof(Car), 25, file);
    fwrite(&cont, sizeof(counter_Data), 1, file);
    printf(GREEN "Dados salvos!" RESET "\n");

    return 0;
}