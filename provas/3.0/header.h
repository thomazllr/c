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

void corMenu();
void readData(Car carro[25], counter_Data *cont);
void checkingColor(int *color);
int checkingGaragem(Car carro[25], int *total, int i);
int checkCar(Car carro[25], counter_Data *cont, int codigo,  int color, int *id_Existente);
void fill(Car carro[25], counter_Data *cont);
void relatorioGeral(Car carro[25], int num);