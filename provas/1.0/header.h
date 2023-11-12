
struct Carro
{
    int id;
    int cor;
    int qtd;
};
typedef struct Carro carro;

// Menu de Relatórios
void menu();

// Menu de Cores
void cor();

// Clearing Car IDs
void clearing(carro carro[25]);

// Checking existing car
int checkCar(carro carro[25], int codigo, int color);

// Checking car color
void checkCor(int color);

// Checking garage limit
int checkGaragem(carro carro[25], int *garagem, int i);

// Get ID
int returnID(carro carro[25], int codigo);

// Relatorios
void relatorioGeral(carro carro[25], int *garagem);
void relatorioCor(carro carro[25], int cor);
void relatorioCodigo(carro carro[25], int codigo);
void relatorioVeiculo(carro carro[25], int codigo, int color);
void cadastroVeiculo(carro carro[25], int codigo, int cor);