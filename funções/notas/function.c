float calculoNotas(float a, float b, float c, char op)
{
    if (op == 'A')
    {
        return (a + b + c) / 3;
    }
    else
    {
        return a * 5 + b * 3 + c * 2 / (a + b + c);
    }
}