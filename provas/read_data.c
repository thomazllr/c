#include <stdio.h>
#include "header.h"

int main() {

    Student students[3][30] = {0};
    data_Count data = {0};

    readData(students, &data);

    FILE *file = fopen("dados.bin", "wb");
    if (file == NULL) {
        printf(RED "Nao foi possivel abrir o arquivo\n" RESET);
    }
    fwrite(&students, sizeof(Student), 3 * 30, file);
    fwrite(&data, sizeof(data_Count), 1, file);
    printf(GREEN "Arquivo salvo com sucesso!\n" RESET);
    

    return 0;
}