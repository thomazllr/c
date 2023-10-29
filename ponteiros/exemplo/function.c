#include <stdio.h>
void status(int x, int *p)
{
    printf("\nVariavel [%d]\n", x);
    printf("Endereco da variavel [%p]\n", &x);
    printf("Ponteiro [%d]\n", *p);
    printf("Endereco apontado do ponteiro [%p]\n", p);
    printf("Endereco do ponteiro [%p]\n", &p);
}

int changeNumber(int *p)
{
    printf("\n\nDigite um novo numero ==> ");
    scanf("%d", p);
}