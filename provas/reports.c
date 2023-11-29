#include <stdio.h>
#include "header.h"

int main() {

    Student students[3][30] = {0};
    data_Count data = {0};
    int op;

    FILE *file = fopen("dados.bin", "rb");
    if (file == NULL) {
        printf(RED "Nao foi possivel abrir o arquivo\n" RESET);
    }
    fread(&students, sizeof(Student), 3 * 30, file);
    fread(&data, sizeof(data_Count), 1, file);
    printf(GREEN "Dados restaurados com sucesso!\n" RESET);

    do {
        menu();
        printf("Digite sua opcao ==> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            report_bystudent(students, data);
            break;

            case 2:
            report_byclass(data);
            break;
            
            default:
            break;

        }

    } while(op != 3);
    
    return 0;
}