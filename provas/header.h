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

void clearing(carro carro[25]);

int checkCar(carro carro[25], int codigo, int color);
void checkCor(int color);
int checkGaragem(carro carro[25], int *garagem, int i);

void addVeiculos(carro carro[25], int new_cars, int *existente);

int returnID(carro carro[25], int codigo);

void relatorioGeral(carro carro[25], int *garagem);
void relatorioCor(carro carro[25], int cor);
void relatorioCodigo(carro carro[25], int codigo, int color);
void relatorioVeiculo(carro carro[25], int codigo, int color);
void cadastroVeiculo(carro carro[25], int codigo, int cor);