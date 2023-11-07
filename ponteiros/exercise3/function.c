void maiorMenor(int *a, int *b, int *c)
{
    int A, B, C;
    A = *a;
    B = *b;
    C = *c;

    if (A > B && A > C)
    {
        *c = A;
        if (B < C)
        {
            *a = B;
            *b = C;
        }
        else
        {
            *a = C;
        }
    }
    else if (B > C)
    {
        *c = B;
        if (A > C)
        {
            *a = C;
            *b = A;
        }
    }
    else
    {
        if (B < A)
        {
            *a = B;
            *b = A;
        }
    }
}