#include "functions.h"
#include <stdio.h>

float somar(float a, float b) { return a + b; }

float sub(float a, float b) { return a - b; }

float multi(float a, float b) { return a * b; }

float divi(float a, float b) {
  if (a == 0) {
    printf("\033[31m");
    printf("Nao eh possivel realizar a divisao\n");
    printf("\033[0m");
    return 0;
  } else {
    return a / b;
  }
}

float changeNumber(float *a, float *b) {
  printf("Digite 1 numero ==> ");
  scanf("%f", a);
  printf("Digite 2 numero ==> ");
  scanf("%f", b);
  return 0;
}

void printResult(float x) { printf("O resultado da op : %.2f\n", x); }
