#define GARAGEM 150
#define TIPOS 25

struct Carro
{
    int id;
    int cor;
    int qtd;
};
typedef struct Carro carro;

void menu();

void cor();

int checkID(carro carro[25], int id);

int checkCar(carro carro[25], int id, int color);

int addCar(carro carro[25], int *new_cars);

int addCarro();

void relatorioGeral(carro carro[25]);
void relatorioCor(carro carro[25], int cor);
void relatorioCodigo(carro carro[25], int codigo);
void relatorioVeiculo(carro carro[25], int codigo, int cor);