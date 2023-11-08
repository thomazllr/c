#include <stdio.h>
#include "functions.h"

int main()
{

    int carros[25][3][150];
    int codigo, cor, quantidade = 0;

    for (k = 0; k < 150; k++)
    {
        for (i = 0; i < 25; i++)
        {
            printf("Digite o código do veiculo: ");
            scanf("%d", &carros[i][0][k]);
            printf("Digite a cor do veiculo: ");
            scanf("%d", &carros[i][1][k]);
            printf("Digite a quantidade do veiculo: ");
            scanf("%d", &carros[i][2][k]);

            quantidade += carros[i][2][k];

            if (quantidade > 150)
            {
                break;
            }
        }
    }

    return 0;
}