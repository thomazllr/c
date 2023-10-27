#include <stdio.h>
#include "function.h"

int par_ou_impar(int x)
{
    if (x % 2 == 0)
    {
        printf("PAR");
        return 1;
    }
    else
    {
        printf("IMPAR");
        return 0;
    }
}