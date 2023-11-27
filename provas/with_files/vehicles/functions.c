#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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

void readData(Car carro[25], counter_Data *cont)
{
    int i, codigo, cor, existe, id_Existente = 0, new_cars, max = 0;
    char op;
    for (i = 0; i < 25; i++)
    {
        printf("Digite o ID do veiculo: ");
        scanf("%d", &codigo);
        corMenu();
        scanf("%d", &cor);
        checkingColor(&cor);
        existe = checkCar(carro, cont, codigo, cor, &id_Existente);
        if (existe)
        {
            i = i - 1;
            printf("Carro existente!\n");
            printf("Quantos carros novos deseja adicionar? ");
            scanf("%d", &new_cars);
            carro[id_Existente].quantity += new_cars;
            cont->total_vehicles += new_cars;
            max = checkingGaragem(carro, cont, id_Existente);
            if (max)
            {
                break;
            }
            printf("Deseja adicionar mais carros? (S/N) ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
        else
        {
            printf(RED "Carro nao registrado" RESET "\n");
            cont->total_registers += 1;
            carro[i].code = codigo;
            carro[i].color = cor;
            printf("Quantos carros deseja adicionar? ");
            scanf("%d", &carro[i].quantity);
            cont->total_vehicles += carro[i].quantity;
            max = checkingGaragem(carro, cont, i);
            if (max == 1)
            {
                break;
            }
            printf("Deseja adicionar mais carros? (S/N) ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }
}

void corMenu()
{
    printf("\nDigite a cor do veiculo\n"
           "1-Branco\n"
           "2-Preto\n"
           "3-Vermelho\n"
           "4-Cinza"
           "\n==> ");
}

int checkCar(Car carro[25], counter_Data *cont, int codigo, int color, int *id_Existente)
{

    int i;
    for (i = 0; i < cont->total_registers; i++)
    {
        if (carro[i].code == codigo && carro[i].color == color)
        {
            *id_Existente = i;
            return 1;
        }
    }
    return 0;
}

void checkingColor(int *color)
{
    if (*color < 1 || *color > 4)
    {
        printf("Cor inválida, digite novamente: ");
        scanf("%d", color);
        checkingColor(color);
    }
}

int checkingGaragem(Car carro[25], counter_Data *cont, int i)
{

    int excesso;
    if (cont->total_vehicles > 150)
    {
        printf("Limite maximo atingindo!\n");
        excesso = cont->total_vehicles - 150;
        cont->total_vehicles -= excesso;
        carro[i].quantity -= excesso;
        return 1;
    }
    return 0;
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

void relatorioGeral(Car carro[25], int num)
{
    int i, total = 0;
    system("cls");
    for (i = 0; i < num; i++)
    {
        printf("ID: %d\n", carro[i].code);
        printf("Cor: ");
        checkCor(carro[i].color);
        printf("Quantidade: %d\n\n", carro[i].quantity);
        total += carro[i].quantity;
    }
    printf("Total de carros: %d\n", total);
    system("pause");
}

void relatorioCores(Car carro[25], int num)
{
    int total = 0, cor;
    system("cls");
    printf("Digite um cor: ");
    scanf("%d", &cor);
    for (int i = 0; i < num; i++)
    {
        if (carro[i].color == cor)
        {
            printf("==========\n");
            printf("Codigo: %d\n", carro[i].code);
            printf("Cor: ");
            checkCor(cor);
            total += carro[i].quantity;
        }
    }
    printf("Total de carros da respectiva cor: %d\n", total);
    system("pause");
}

void relatorioCodigo(Car carro[25], int num)
{
    int total = 0, codigo;
    system("cls");
    printf("Digite o codigo do veiculo: ");
    scanf("%d", &codigo);
    for (int i = 0; i < num; i++)
    {
        if (codigo == carro[i].code)
        {
            printf("==========\n");
            printf("Codigo: %d\n", carro[i].code);
            printf("Cor: ");
            checkCor(carro[i].color);
            printf("Quantidade: %d\n", carro[i].quantity);
            printf("==========\n");
            total += carro[i].quantity;
        }
    }
    printf("Total de veiculos com o mesmo codigo: %d\n", total);
    system("pause");
}

void relatorioVeiculo(Car carro[25], int num)
{
    int codigo, color;
    system("cls");
    printf("Digite o codigo: ");
    scanf("%d", &codigo);
    printf("Digite a cor: ");
    scanf("%d", &color);
    for (int i = 0; i < num; i++)
    {
        if (carro[i].code == codigo && carro[i].color == color)
        {
            printf("==========\n");
            printf("Codigo: %d\n", carro[i].code);
            printf("Cor: ");
            checkCor(color);
            printf("Quantidade: %d\n", carro[i].quantity);
            printf("==========\n");
            system("pause");
            return;
        }
        printf("\033[31mCarro nao existente\033[0m\n");
        return;
    }
}

void addOneVehicle(Car carro[25], counter_Data *cont)
{
    int codigo, cor, existe, id_Existente, limite, garagem = 0;
    int i = 0;
    printf("%d\n\n", cont->total_registers);
    if (cont->total_registers < 25)
    {
        printf("Digite o codigo do novo veiculo ==> ");
        scanf("%d", &codigo);
        printf("Digite a cor do novo veiculo ==> ");
        scanf("%d", &cor);
        checkingColor(&cor);
        existe = checkCar(carro, cont, codigo, cor, &id_Existente);
        if (existe)
        {
            printf(GREEN "Carro existente!" RESET "\n");
            carro[id_Existente].quantity += 1;
            cont->total_vehicles += 1;
            limite = checkingGaragem(carro, cont, id_Existente);
            if (limite)
            {
                return;
            }
        }
        else
        {
            printf(RED "Carro nao registrado" RESET "\n");
            carro[cont->total_registers].code = codigo;
            carro[cont->total_registers].color = cor;
            carro[cont->total_registers].quantity = 1;
            cont->total_vehicles += 1;
            limite = checkingGaragem(carro, cont, cont->total_registers);
            cont->total_registers += 1;
            if (limite)
            {
                return;
            }
        }
    }
    else
    {
        printf("\033[31mNao eh possivel adicionar mais carros novos.\033[0m\n");
    }
    return;
}
