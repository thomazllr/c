#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
float calculoNotas(float matriz[][3][2], int aluno, int turma)
{

    return (float)(matriz[aluno][0][turma] + matriz[aluno][1][turma] + matriz[aluno][2][turma]) / 3.0;
}

float calculoFrequencia(float matriz[][3][2], int aluno, int turma, int total_aulas)
{
    return matriz[aluno][3][turma] / total_aulas * 100;
}

void consultaAluno(float matriz[][3][2], char nome[][4][50], int aluno, int turma, int total_aulas)
{
    system("cls");
    float nota_final, frequencia;
    nota_final = calculoNotas(matriz, aluno, turma);
    frequencia = calculoFrequencia(matriz, aluno, turma, total_aulas);
    printf("Nome do aluno: %s\n\n", nome[aluno][turma]);
    printf("Nota 1: %.2f\n", matriz[aluno][0][turma]);
    printf("Nota 2: %.2f\n", matriz[aluno][1][turma]);
    printf("Nota 3: %.2f\n", matriz[aluno][2][turma]);
    printf("Nota final: %.2f\n", nota_final);
    printf("Frequencia ==> %.2f%%\n", frequencia);
    system("pause");
}
