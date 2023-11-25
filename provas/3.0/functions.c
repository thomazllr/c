#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void fill(Car carro[25], counter_Data *cont) {
    FILE *file;
    int i;
    file = fopen("binario", "rb");
    for(i = 0; i < cont->total_registers ; i++) {
        fread(&carro[i], sizeof(Car), 1, file);
    }
    fclose(file);
}

void readData(Car carro[25], counter_Data *cont) {
    int i, codigo, cor, existe, id_Existente = 0, new_cars, total = 0, max = 0;
    char op;
    for(i=0;i<25;i++) 
    {
        printf("Digite o ID do veiculo: ");
        scanf("%d", &codigo);
        corMenu();
        scanf("%d", &cor);
        checkingColor(&cor);
        existe = checkCar(carro, cont, codigo, cor, &id_Existente);
        if(existe) {
            i = i - 1;
            printf("Carro existente!\n");
            printf("Quantos carros novos deseja adicionar? ");
            scanf("%d", &new_cars);
            carro[id_Existente].quantity += new_cars;
            total += new_cars;
            max = checkingGaragem(carro, &total, id_Existente);
            if(max) {
                break;
            }
            printf("Deseja adicionar mais carros? (S/N) ");
            scanf(" %c", &op);
            if(op == 'n') {
                break;
            }
        }
        else {
            printf("Carro nao registrado\n");
            cont->total_registers += 1;
            carro[i].code = codigo;
            carro[i].color = cor;
            printf("Quantos carros deseja adicionar? ");
            scanf("%d", &carro[i].quantity);
            total += carro[i].quantity;
            max = checkingGaragem(carro, &total, i);
            if(max == 1) {
                break;
            }
            printf("Deseja adicionar mais carros? (S/N) ");
            scanf(" %c", &op);
            if(op == 'n') {
                break;
            }
        }
    }
}

void corMenu() {
        printf("\nDigite a cor do veiculo\n"
           "1-Branco\n"
           "2-Preto\n"
           "3-Vermelho\n"
           "4-Cinza"
           "\n==> ");
}

int checkCar(Car carro[25], counter_Data *cont, int codigo,  int color, int *id_Existente) {

    int i;
    for(i=0;i < cont->total_registers;i++) {
        if(carro[i].code == codigo && carro[i].color == color) {
            *id_Existente = i;
            return 1;     
        }
    }    
    return 0;

}

void checkingColor(int *color) {
    if(*color < 1 || *color > 4) {
        printf("Cor inválida, digite novamente: ");
        scanf("%d", color);
        checkingColor(color);
    }
}

int checkingGaragem(Car carro[25], int *total, int i) {

    int excesso;
    if (*total > 150)
    {
        printf("Limite maximo atingindo!\n");
        excesso = *total - 150;
        *total -= excesso;
        carro[i].quantity -= excesso;
        return 1;
    }
    return 0;
}

void relatorioGeral(Car carro[25], int num) {
    int i, total = 0;
    for(i = 0; i < num ; i++) {
        printf("ID: %d\n", carro[i].code);
        printf("Cor: %d\n", carro[i].color);
        printf("Quantidade: %d\n\n", carro[i].quantity);
        total += carro[i].quantity;
    }
    printf("Total de carros: %d\n", total);
}