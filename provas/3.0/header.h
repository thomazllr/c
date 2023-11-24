typedef struct Car {
    int code;
    int color;
    int quantity;
} Car;

typedef struct counter_Data {
    int total_registers;
    int total_by_code;
    int total_by_color;
    int one_by_code_color;

} counter_Data;

void createFile(Car carro[25], counter_Data *cont);
void updateFile(Car carro[25], counter_Data *cont);
void corMenu();
void readData(Car carro[25], counter_Data *cont);
void checkingColor(int *color);
int checkingGaragem(Car carro[25], int *total, int i);
int checkCar(Car carro[25], counter_Data *cont, int codigo,  int color, int *id_Existente);
void fill(Car carro[25], counter_Data *cont);
void relatorioGeral(Car carro[25], int num);