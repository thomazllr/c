void calcula(int *x, int *y)
{
    int X, Y;

    X = *x;
    Y = *y;
    *x = X + Y;
    *y = X - Y;
}