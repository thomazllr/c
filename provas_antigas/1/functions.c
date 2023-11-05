#include <stdio.h>

void cont(int matriz[][2][5], int *sim_procurava, int *nao_procurava, int *sim_satisfeito, int *nao_satisfeito)
{
    int i, k;

    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < 20; i++)
        {
            if (matriz[i][0][k] == 1)
            {
                *sim_procurava = *sim_procurava + 1;
            }
            else if (matriz[i][0][k] == 2)
            {
                *nao_procurava = *nao_procurava + 1;
            }
            if (matriz[i][1][k] == 1)
            {
                *sim_satisfeito = *sim_satisfeito + 1;
            }
            else if (matriz[i][1][k] == 2)
            {
                *nao_satisfeito = *nao_satisfeito + 1;
            }
        }
    }
}

void relatorioPergunta(int matriz[][2][5], int sim_procurava, int nao_procurava, int sim_satisfeito, int nao_satisfeito, int total, int pergunta)
{

    float percent_sim, percent_nao;
    if (pergunta == 1)
    {
        percent_sim = ((float)sim_procurava / total) * 100;
        percent_nao = ((float)nao_procurava / total) * 100;
        printf("Percentual de clientes que encontrou o que procurava: %.2f%%\n", percent_sim);
        printf("Percentual de clientes que nao encontrou o que procurava: %.2f%%\n", percent_nao);
    }
    else
    {
        percent_sim = ((float)sim_satisfeito / total) * 100;
        percent_nao = ((float)nao_satisfeito / total) * 100;
        printf("Percentual de clientes satisfeitos: %.2f%%\n", percent_sim);
        printf("Percentual de nao clientes satisfeitos: %.2f%%\n", percent_nao);
    }
}
void relatorioDia(int matriz[][2][5], int dia)
{
    int i, k;
    for (i = 0; i < 20; i++)
    {
        if (matriz[i][0][dia] == 0 || matriz[i][1][dia] == 0)
        {
            break;
        }
        printf("\n[CLIENTE %d]\n-Respostas --\n"
               "Procurava: %d \n"
               "Satisfeito: %d\n\n",
               i + 1,
               matriz[i][0][dia],
               matriz[i][1][dia]);
    }
}

void relatorioCliente(int matriz[][2][5], int client, int dia)
{
    printf("\n[CLIENTE %d]\n-Respostas --\n"
           "Procurava: %d \n"
           "Satisfeito: %d\n\n",
           client + 1,
           matriz[client][0][dia],
           matriz[client][1][dia]);
}

void relatorioGeral(int matriz[][2][5], int total, int clientes_5, int sim_satisfeito)
{
    int i, k, duas_questoes = 0;
    float percent = 0, porcentagem;
    printf("\nTotal de clientes consultados: %d\n", total);

    for (i = 0; i < 20; i++)
    {
        if (matriz[i][0][4] == 1)
        {
            percent++;
        }
    }
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < 20; i++)
        {
            if (matriz[i][0][2] == 2 && matriz[i][1][2] == 2)
            {
                duas_questoes++;
            }
        }
    }

    porcentagem = (percent * 100) / clientes_5;
    printf("Total de clientes que disse nao para as duas ==> %d\n", duas_questoes);
    printf("Quantidade total de clientes que estao satisfeitos ==> %d\n", sim_satisfeito);
    printf("Percentagem de clientes que encontrou o que procurava no dia 5 ==> %.2f%%\n", porcentagem);
}
