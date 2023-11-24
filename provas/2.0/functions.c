#include <stdio.h>
#include "header.h"


int cont = 0;

void Dealership(Car *carro, int *cont) {
    FILE *file = fopen("dados.txt", "r");
    if (file == NULL) {
        createFile();
    }
    else {
        fill(carro, cont);
    }
}
void createFile() {
    Car carro[25];
    FILE *file;
    file = fopen("dados.txt", "w");
    cont = readData(carro);
    updateFile(carro, cont);
    fclose(file);
}

void updateFile(Car *carro, int cont) {
    int i;
    FILE *file;
    file = fopen("dados.txt", "w");
    for(i = 0; i < cont ; i++) {
        fprintf(file, "Id: %d / Cor: %d / Quantidade: %d\n", carro[i].id, carro[i].cor, carro[i].qtd);
        fprintf(file, "-------------------------------------------\n");
    }

    
    fclose(file);
}
void fill(Car *carro, int *cont) {
    FILE *file;
    int i;
    file = fopen("dados.txt", "r");
    for(i = 0; i < 2 ; i++) {
        fscanf(file, "Id: %d / Cor: %d / Quantidade: %d\n", &carro[i].id, &carro[i].cor, &carro[i].qtd);
        char temp[50];
        fgets(temp, 50, file);
    }
    fclose(file);
}

int readData(Car *carro) {
    int i, codigo, color, existe, id_Existente = 0, new_cars, garagem = 0, total = 0;
    char op;
    for(i=0;i<25;i++) 
    {
        printf("Digite o ID do veiculo: ");
        scanf("%d", &codigo);
        cor();
        scanf("%d", &color);
        checkingColor(&color);
        existe = checkCar(carro, cont, codigo, color, &id_Existente);
        if(existe == 1) {
            i = i - 1;
            printf("Carro existente!\n");
            printf("Quantos carros novos deseja adicionar? ");
            scanf("%d", &new_cars);
            carro[id_Existente].qtd += new_cars;
            garagem += new_cars;
            total = checkingGaragem(&garagem, carro, id_Existente);
            if(total == 1) {
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
            cont += 1;
            carro[i].id = codigo;
            carro[i].cor = color;
            printf("Quantos carros deseja adicionar? ");
            scanf("%d", &carro[i].qtd);
            garagem += carro[i].qtd;
            total = checkingGaragem(&garagem, carro, i);
            if(total == 1) {
                break;
            }
            printf("Deseja adicionar mais carros? (S/N) ");
            scanf(" %c", &op);
            if(op == 'n') {
                break;
            }
        }
    }
    return cont;
}

void cor() {
        printf("\nDigite a cor do veiculo\n"
           "1-Branco\n"
           "2-Preto\n"
           "3-Vermelho\n"
           "4-Cinza"
           "\n==> ");
}

int checkCar(Car carro[25], int cont, int codigo,  int color, int *id_Existente) {

    int i;
    for(i=0;i<=cont;i++) {
        if(carro[i].id == codigo && carro[i].cor == color) {
            *id_Existente = i;
            return 1;     
        }
    return 0;
    }


}

void checkingColor(int *color) {
    if(*color < 1 || *color > 4) {
        printf("Cor inválida, digite novamente: ");
        scanf("%d", color);
        checkingColor(color);
    }
}

int checkingGaragem(int *garagem, Car carro[25], int i) {

    int excesso;
    if (*garagem > 150)
    {
        printf("Limite maximo atingindo!\n");
        excesso = *garagem - 150;
        *garagem -= excesso;
        carro[i].qtd -= excesso;
        return 1;
    }
    return 0;
}

void relatorioGeral(Car *carro, int cont) {
    int i;
    int total =0;

    for(i=0;i<cont;i++) {
        printf("Id: %d / Cor: %d / Quantidade: %d\n", carro[i].id, carro[i].cor, carro[i].qtd);
        total += carro[i].qtd;
        printf("-------------------------------------------------\n");
    }
    printf("Quantidade total de carros: %d", total); 
}