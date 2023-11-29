#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

typedef struct Producers
{
    int lettuce, cabagge;
} Producers;

typedef struct data_Counter
{
    int total,
        total_byweek[2][15],
        total_byproducer[2][50];
} data_Counter;

void menu();

// ReadData
void readData(Producers producers[15][50], data_Counter *data);
void counterData(Producers producers[15][50], data_Counter *data, int i, int j);

// Reports
void reports_byweek(Producers producers[15][50], data_Counter data);
void reports_byproducer(Producers producers[15][50], data_Counter data);