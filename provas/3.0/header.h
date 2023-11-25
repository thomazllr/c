#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

typedef struct Car {
    int code;
    int color;
    int quantity;
} Car;

typedef struct counter_Data {
    int total_registers;
} counter_Data;

// Menus
void menu();
void corMenu();

// Datas & Checks
void readData(Car carro[25], counter_Data *cont);
void checkingColor(int *color);
int checkingGaragem(Car carro[25], int *total, int i);
void checkCor(int color);
int checkCar(Car carro[25], counter_Data *cont, int codigo,  int color, int *id_Existente);


// Reports
void relatorioGeral(Car carro[25], int num);
void relatorioCores(Car carro[25], int num);
void relatorioCodigo(Car carro[25], int num);
void relatorioVeiculo(Car carro[25], int num);
void addOneVehicle();