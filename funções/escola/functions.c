#include <stdio.h>
#include "functions.h"

float notaBimestral(float x, float y)
{
    return (x * 0.6) + (y * 0.4);
}

float notaFinal(float a, float b, float c, float d)
{
    return (a + b + c + d) / 4;
}

float calculoPresenca(float x, float y)
{
    return x * 100 / y;
}

void status(float x, int y)
{
    if (y >= 75)
    {
        if (x >= 7)
        {
            printf("APROVADO!");
        }
        else if (x >= 5)
        {
            printf("RECUPERAÇÃO");
        }
        else
        {
            printf("REPROVADO");
        }
    }
    else
    {
        printf("REPROVADO!");
    }
}

int statusInt(float x, int y)
{
    if (y < 75)
        return 0;
    if (x >= 7)
        return 1;
    if (x >= 5)
        return 2;
    return 0;
}