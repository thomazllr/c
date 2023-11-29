#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Producers producers[15][50];
    data_Counter data_counter = {0};
    int option;

    FILE *file = fopen("dados.bin", "rb");
    if (file == NULL)
    {
        printf(RED "Falha ao abrir o arquivo" RESET);
    }
    fread(&producers, sizeof(Producers), 15 * 50, file);
    fread(&data_counter, sizeof(data_Counter), 1, file);
    printf(GREEN "Dados restaurados com sucesso!\n\n" RESET);
    system("pause");
    system("cls");

    do
    {
        menu();
        printf("\n\nDigite sua opcao == > ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            reports_byweek(producers, data_counter);
            break;

        default:
            break;
        }
    } while (option != 4);

    return 0;
}