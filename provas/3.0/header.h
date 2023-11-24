typedef struct Car {
    int code;
    int color;
    int quantity;
} Car;

void createFile(Car carro[25]);
void updateFile(Car carro[25], int cont);
void corMenu();
int readData(Car carro[25]);
void checkingColor(int *color);
int checkingGaragem(Car carro[25], int *total, int i);
int checkCar(Car carro[25], int cont, int codigo,  int color, int *id_Existente);
void fill(Car carro[25], int cont);
void relatorioGeral();