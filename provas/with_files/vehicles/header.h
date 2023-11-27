#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

typedef struct Car
{
    int code,
        color,
        quantity;
} Car;

typedef struct counter_Data
{
    int total_registers,
        total_vehicles;
} counter_Data;

// Menus
void menu();
void corMenu();

// Datas & Checks
void readData(Car carro[25], counter_Data *cont);
void checkingColor(int *color);
int checkingGaragem(Car carro[25], counter_Data *cont, int i);
void checkCor(int color);
int checkCar(Car carro[25], counter_Data *cont, int codigo, int color, int *id_Existente);
int checkCar2(Car carro[25], counter_Data cont, int codigo, int color, int *id_Existente);

// Reports
void relatorioGeral(Car carro[25], int num);
void relatorioCores(Car carro[25], int num);
void relatorioCodigo(Car carro[25], int num);
void relatorioVeiculo(Car carro[25], int num);
void addOneVehicle(Car carro[25], counter_Data *cont);
