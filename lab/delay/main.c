#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Iniciando...\n");

    // Pausa o programa por 2 segundos
    sleep(2);

    printf("Atraso de 2 segundos\n");

    system("clear");
    printf("Limpando a tela.\n\n");
    system("pause");

    return 0;
}
