#include <stdio.h>

int verify(int x)
{
    if (x > 0)
    {
        printf("POSITIVO!");
        return 1;
    }
    else if (x < 0)
    {
        printf("NEGATIVO!");
        return -1;
    }
    else
    {
        printf("ZERO!");
        return 0;
    }
}