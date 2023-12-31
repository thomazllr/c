#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void clearing(carro carro[25])
{
    int i;
    for (i = 0; i < 25; i++)
    {
        carro[i].id = -1;
    }
}
void menu()
{
    printf("\nO que deseja fazer?\n\n"
           "1- Relatorio Geral\n"
           "2- Consulta por cor\n"
           "3- Relatorio por Codigo\n"
           "4- Buscar por veiculo\n"
           "5- Cadastrar mais um veiculo\n"
           "6- Sair\n"
           "Option ==> ");
}

void cor()
{
    printf("\nDigite a cor do veiculo\n"
           "1-Branco\n"
           "2-Preto\n"
           "3-Vermelho\n"
           "4-Cinza"
           "\n==> ");
}

int returnID(carro carro[25], int codigo)
{
    int i, existe;
    for (i = 0; i < 25; i++)
    {
        if (codigo == carro[i].id)
        {
            return i;
        }
    }
    return 0;
}

int checkCar(carro carro[25], int codigo, int color)
{
    int i;
    for (i = 0; i < 25; i++ && carro[i].id != -1)
    {
        if (codigo == carro[i].id && color == carro[i].cor)
        {
            return 1;
        }
    }
    return 0;
}

int checkGaragem(carro carro[25], int *garagem, int i)
{
    int excesso;

    if (*garagem > 150)
    {
        printf("Limite maximo atingindo!\n");
        excesso = *garagem - 150;
        *garagem -= excesso;
        carro[i].qtd -= excesso;
        system("pause");
        return 1;
    }
    return 0;
}
void relatorioGeral(carro carro[25], int *garagem)
{
    int i;
    int color;
    float perct = 0;

    system("cls");
    for (i = 0; i < 25; i++)
    {
        if (carro[i].id != -1)
        {
            printf("==========\n");
            printf("Codigo: %d\n", carro[i].id);
            color = carro[i].cor;
            printf("Cor: ");
            checkCor(color);
            printf("Quantidade: %d\n", carro[i].qtd);
            printf("==========\n");
        }
    }
    printf("\nTotal de carros: %d\n", *garagem);
    perct = ((float)*garagem * 100) / 150;
    printf("Percentagem de ocupacao da garagem: %.2f%%\n", perct);
    system("pause");
}

void relatorioCor(carro carro[25], int color)
{
    int i;
    int total = 0;
    system("cls");
    for (i = 0; i < 25; i++)
    {
        if (carro[i].id != -1)
        {
            if (carro[i].cor == color)
            {
                printf("==========\n");
                printf("Codigo: %d\n", carro[i].id);
                printf("Cor: ");
                checkCor(color);
                total += carro[i].qtd;
            }
        }
    }
    printf("Total de carros da respectiva cor: %d\n", total);
    system("pause");
}

void checkCor(int color)
{
    if (color == 1)
    {
        printf("\033[47;30mBranco\033[0m\n");
    }
    else if (color == 2)
    {
        printf("\033[40;37mPreto\033[0m\n");
    }
    else if (color == 3)
    {
        printf("\033[41;30mVermelho\033[0m\n");
    }
    else
        printf("\033[47;30mCinza!\033[0m\n");
}

void relatorioCodigo(carro carro[25], int codigo)
{
    int total = 0, i;
    for (i = 0; i < 25; i++)
    {
        if (carro[i].id != -1)
        {
            if (codigo == carro[i].id)
            {
                printf("==========\n");
                printf("Codigo: %d\n", carro[i].id);
                printf("Cor: ");
                checkCor(carro[i].cor);
                printf("Quantidade: %d\n", carro[i].qtd);
                printf("==========\n");
                total += carro[i].qtd;
            }
        }
    }
    printf("Total de veiculos com o mesmo codigo: %d", total);
    system("pause");
}

void relatorioVeiculo(carro carro[25], int codigo, int color)
{
    int i;
    for (i = 0; i < 25; i++)
    {
        if (carro[i].id == codigo && carro[i].cor == color)
        {
            printf("==========\n");
            printf("Codigo: %d\n", carro[i].id);
            printf("Cor: ");
            checkCor(color);
            printf("Quantidade: %d\n", carro[i].qtd);
            printf("==========\n");
            system("pause");
        }
        else
        {
            printf("\033[31mCarro nao existente\033[0m\n");
            return;
        }
    }
}
