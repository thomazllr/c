#include <stdio.h>

struct Car {
    int id;
    int cor;
    int qtd;
};
typedef struct Car Car;

void createFile();
void readData();

void cor();
int checkCar(Car carro[25], int codigo, int cor, int *id_Existente);