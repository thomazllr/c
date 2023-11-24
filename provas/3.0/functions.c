#include <stdio.h>
#include "header.h"

int cont = 0;

void createFile() {
    Garage *garagem;
    FILE *file = fopen("binario", "rb");
    if (file == NULL) {
        cont = readData(garagem);
        updateFile(garagem, cont);
    }
    fill(garagem, cont);
}

void updateFile(Garage *garagem, int cont) {
    int i;
    FILE *file;
    file = fopen("binario", "wb");
    for(i = 0; i < 2 ; i++) {
        fwrite(&garagem->carro[i], sizeof(Car), 1, file);
        
    }
    fclose(file);
}

void fill(Garage *garagem, int cont) {
    FILE *file;
    int i;
    file = fopen("binario", "rb");
    for(i = 0; i < 2 ; i++) {
        fread(&garagem->carro[i], sizeof(Car), 1, file);
    }
    fclose(file);
}

int readData(Garage *garagem) {
    int i, codigo, cor, existe, id_Existente = 0, new_cars, total = 0, max = 0;
    char op;
    for(i=0;i<25;i++) 
    {
        printf("Digite o ID do veiculo: ");
        scanf("%d", &codigo);
        corMenu();
        scanf("%d", &cor);
        checkingColor(&cor);
        existe = checkCar(garagem, cont, codigo, cor, &id_Existente);
        if(existe == 1) {
            i = i - 1;
            printf("Carro existente!\n");
            printf("Quantos carros novos deseja adicionar? ");
            scanf("%d", &new_cars);
            garagem->carro[id_Existente].quantity += new_cars;
            garagem->total += new_cars;
            max = checkingGaragem(garagem, id_Existente);
            if(max == 1) {
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
            garagem->carro[i].code = codigo;
            garagem->carro[i].color = cor;
            printf("Quantos carros deseja adicionar? ");
            scanf("%d", &garagem->carro[i].quantity);
            garagem->total += garagem->carro[i].quantity;
            max = checkingGaragem(garagem, i);
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
    return cont;
}

void corMenu() {
        printf("\nDigite a cor do veiculo\n"
           "1-Branco\n"
           "2-Preto\n"
           "3-Vermelho\n"
           "4-Cinza"
           "\n==> ");
}

int checkCar(Garage *garagem, int cont, int codigo,  int color, int *id_Existente) {

    int i;
    for(i=0;i < cont;i++) {
        if(garagem->carro[i].code == codigo && garagem->carro[i].color == color) {
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

int checkingGaragem(Garage *garagem, int i) {

    int excesso;
    if (garagem->total > 150)
    {
        printf("Limite maximo atingindo!\n");
        excesso = garagem->total - 150;
        garagem->total -= excesso;
        garagem->carro[i].quantity -= excesso;
        return 1;
    }
    return 0;
}

void relatorioGeral() {
    Garage garagem;
    int i, total = 0;
    for(i = 0; i < 2; i++) {
        printf("ID: %d\n", garagem.carro[i].code);
        printf("Cor: %d\n", garagem.carro[i].color);
        printf("Quantidade: %d\n\n", garagem.carro[i].quantity);
        total += garagem.carro[i].quantity;
    }
    printf("Total de carros: %d\n", total);
}