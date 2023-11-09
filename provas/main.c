#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{

    carro carro[25];

    int codigo, color, qtd, id_Existente = 0;
    int i, k, j, existe, option, limite = 0;
    int garagem = 0, new_cars;
    char op;

    clearing(carro);

    for (i = 0; i < 25; i++)
    {
        system("cls");
        printf("Digite o codigo do veiculo ==> ");
        scanf("%d", &codigo);
        cor();
        scanf("%d", &color);
        existe = checkCar(carro, codigo, color);
        if (existe == 1)
        {
            printf("\033[34mCarro existente\033[0m\n");
            id_Existente = returnID(carro, codigo);
            printf("Quantos veiculos quer adicionar? ");
            scanf("%d", &new_cars);
            carro[id_Existente].qtd += new_cars;
            garagem += new_cars;
            limite = checkGaragem(carro, &garagem, id_Existente);
            if (limite == 1)
            {
                break;
            }
            printf("\nDeseja adicionar mais um carro? ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
            continue;
        }
        else
        {
            printf("\033[31mCarro nao registrado\033[0m\n");
            carro[i].id = codigo;
            carro[i].cor = color;
        }

        printf("Digite o quantidade de veiculos ==> ");
        scanf("%d", &carro[i].qtd);
        limite = checkGaragem(carro, &garagem, i);
        garagem += carro[i].qtd;
        if (limite == 1)
        {
            break;
        }

        printf("\nDeseja adicionar mais um carro? ");
        scanf(" %c", &op);
        if (op == 'n')
        {
            break;
        }
    }
    system("cls");

    do
    {
        menu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            relatorioGeral(carro, &garagem);
            break;
        case 2:
            cor();
            scanf("%d", &color);
            relatorioCor(carro, color);
            break;
        case 3:
            printf("Digite o codigo do veiculo ==> ");
            scanf("%d", &codigo);
            printf("Digite a cor que deseja buscar ==> ");
            scanf("%d", &color);
            relatorioCodigo(carro, codigo, color);
            break;
        case 4:
            printf("Digite o codigo do veiculo ==> ");
            scanf("%d", &codigo);
            printf("Digite a cor do veiculo ==> ");
            scanf("%d", &color);
            relatorioVeiculo(carro, codigo, color);
            break;
        case 5:
            break;
        }

    } while (option != 6);

    return 0;
}