#include <stdio.h>
#include "header.h"

void menu()
{
    printf("\nO que deseja fazer?\n\n"
           "1- Relatorio Geral\n"
           "2- Consulta por cor\n"
           "3- Relatorio por Codigo\n"
           "4- Buscar por veiculo\n"
           "5- Sair\n"
           "Option ==> ");
}

void cor()
{
    printf("\nDigite o código da cor do veiculo\n"
           "1-Branco\n"
           "2-Preto\n"
           "3-Vermelho\n"
           "4-Cinza"
           "\n==> ");
}

int checkID(carro carro[25], int codigo)
{
    int i, existe;
    for (i = 0; i < 25; i++)
    {
        if (codigo == carro[i].id)
        {
            return 1;
        }
    }
    return 0;
}

int checkCar(carro carro[25], int codigo, int color)
{
    int i, existe;
    for (i = 0; i < 25; i++)
    {
        if (codigo == carro[i].id && color == carro[i].cor)
        {
            return 1;
        }
    }
    return 0;
}

void changeID(int *new_id)
{
    printf("Digite um ID existente: ");
    scanf("&d", &new_id);
}

int addCar(carro carro[25], int *new_cars)
{
    int i = 0;
    printf("Quantos carros voce quer adicionar? ");
    scanf("%d", new_cars);
    for (i = 0; i < 25; i++)
    {
        carro[i].qtd += *new_cars;
    }
}