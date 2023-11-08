#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{

    carro carro[25];

    int codigo, color, qtd, limite = 0;
    int i, k, j, existe, new_id, option;
    int garagem = 0;
    char op;

    for (i = 0; i < 25; i++)
    {
        printf("Digite o código do veiculo ==> ");
        scanf("%d", &codigo);
        cor();
        scanf("%d", &color);
        existe = checkCar(carro, codigo, color);
        if (existe == 1)
        {
            printf("Carro existente\n");
            printf("Deseja adicionar quantos veiculos? ");
            addCar(&carro);
        }
        else
        {
            printf("Carro nao existente\n");
            carro[i].id = codigo;
            carro[i].cor = color;
        }

        printf("Digite o quantidade de veiculos ==> ");
        scanf("%d", &carro[i].qtd);
        garagem += carro[i].qtd;
        printf("Deseja adicionar mais um carro? ");
        scanf(" %c", &op);
        if (op == 'n')
        {
            break;
        }

        if (garagem > 150)
        {
            printf("Limite Máximo atingindo");
            break;
        }
    }

    do
    {
        menu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            break;
        }

    } while (option != 5);

    return 0;
}