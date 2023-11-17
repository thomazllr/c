#include <stdio.h>
#include "header.h"

void clearing(Car carro[25]) {
    int i;

    for(i=0;i<25;i++) {
        carro[i].id = -1;
    }
}

void createFile() {
    FILE *file;
    file = fopen("dados.txt", "w");
    fclose(file);
}

void readData() {
    Car carro[25];
    int i, codigo, color, existe, id_Existente = 0, new_cars;
    for(i=0;i<25;i++) 
    {
        printf("Digite o ID do veículo: ");
        scanf("%d", &codigo);
        cor();
        scanf("%d", &color);
        existe = checkCar(carro, codigo, color, &id_Existente);
        if(existe == 1) {
            printf("Carro existente!");
            printf("Quantos carros novos deseja adicionar? ");
            scanf("%d", &new_cars);
            carro[id_Existente].qtd += new_cars;
        }
        else {
            printf("Carro não registrado");
            carro[i].id = codigo;
            carro[i].cor = color;
            printf("Quantos carros deseja adicionar? ");
            scanf("%d", &carro[i].qtd);
        }
    }
    
}

void cor() {
        printf("\nDigite a cor do veiculo\n"
           "1-Branco\n"
           "2-Preto\n"
           "3-Vermelho\n"
           "4-Cinza"
           "\n==> ");
}

int checkCar(Car carro[25], int codigo,  int color, int *id_Existente) {

    int i;

    for(i=0;i<25;i++ && carro[i].id != -1) {
        if(carro[i].id == codigo && carro[i].cor == color) {
            *id_Existente = i;
            return 1;     
        }
    return 0;
    }


}