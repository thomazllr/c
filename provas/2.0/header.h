#include <stdio.h>

struct Car {
    int id;
    int cor;
    int qtd;
};
typedef struct Car Car;


void Dealership(Car *carro, int *cont);
void createFile();
void updateFile(Car *carro, int cont);
void fill(Car *carro, int *cont);
int readData(Car *carro);
void cor();
void checkingColor(int *color);
int checkCar(Car carro[25], int cont, int codigo,  int color, int *id_Existente);
int checkingGaragem(int *garagem, Car carro[25], int i);

// Relatorios

void relatorioGeral(Car *carro, int cont);