#include <stdio.h>
#include "functions.h"

float notaBimestral(float x, float y)
{
    return x + y;
}

float notaFinal(float a, float b, float c, float d)
{
    return (a + b + c + d) / 4;
}

void status(float x, int y)
{
    if (x >= 7.0 || y > 75)
    {
        printf("APROVADO!");
    }
    else if (x < 7 || x > 5 && y >= 75)
    {
        printf("DIREITO A RECUPERAÇÃO!");
    }
    else
    {
        printf("REPROVADO!");
    }
}