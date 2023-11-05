#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("teste.txt", "w");

    fpritnf(file, "Guilherme Thomaz Lindo");
    fclose(file);

    return 0;
}