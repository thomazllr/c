#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define DIAS 5
#define CLIENTES 20
#define RESPOSTAS 2

int main()
{
    int cliente[CLIENTES][RESPOSTAS][DIAS] = {{{0}}};
    int i, j, k, option, dia, client, total_perguntas = 0, clientes_5 = 0;
    int sim_satisfeito = 0, nao_satisfeito = 0, sim_procurava = 0, nao_procurava = 0, pergunta;
    char op;

    for (k = 0; k < DIAS; k++)
    {
        printf("\n\nDIA [%d]\n", k + 1);
        for (i = 0; i < CLIENTES; i++)
        {
            printf("CLIENTE [%d]\n", i + 1);
            total_perguntas++;
            printf("\nEncontrou o que procurava? (1-Sim/2-Nao) ==> ");
            scanf("%d", &cliente[i][0][k]);
            printf("Esta satisfeito? (1-Sim/2-Nao) ==> ");
            scanf("%d", &cliente[i][1][k]);
            if (k == 4)
            {
                clientes_5++;
            }
            printf("Deseja continuar? (s/n) --> ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }

    system("cls");

    cont(cliente, &sim_procurava, &nao_procurava, &sim_satisfeito, &nao_satisfeito);

    do
    {
        system("cls");
        printf("%d %d %d %d %d -- %d ", sim_procurava, nao_procurava, sim_satisfeito, nao_satisfeito, total_perguntas, clientes_5);
        printf("O que deseja verificar?\n"
               "1-Relatorio por dia\n"
               "2-Relatorio por pergunta\n"
               "3-Relatorio por cliente\n"
               "4-Relatorio geral\n"
               "5-Sair\n"
               "\nOption ==> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Informe o dia: ");
            scanf("%d", &dia);
            dia--;
            relatorioDia(cliente, dia);
            system("pause");
            break;
        case 2:
            printf("Informe a pergunta (1- Encontrou o que procurava / 2 - Satisfeito): ");
            scanf("%d", &pergunta);
            relatorioPergunta(cliente, sim_procurava, nao_procurava, sim_satisfeito, nao_satisfeito, total_perguntas, pergunta);
            system("pause");
            break;
        case 3:
            printf("Informe o cliente ==> ");
            scanf("%d", &client);
            client--;
            printf("Informe o dia: ");
            scanf("%d", &dia);
            dia--;
            relatorioCliente(cliente, client, dia);
            system("pause");
            break;
        case 4:
            relatorioGeral(cliente, total_perguntas, clientes_5, sim_satisfeito);
            system("pause");
            break;
        }

    } while (option != 5);

    return 0;
}