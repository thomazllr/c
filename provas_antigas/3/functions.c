#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void calculoNotas(float matriz[][3][2], float notas[][2])
{
    int i, k;

    for (k = 0; k < 2; k++)
    {
        for (i = 0; i < 5; i++)
        {
            notas[i][k] = (float)(matriz[i][0][k] + matriz[i][1][k] + matriz[i][2][k]) / 3.0;
        }
    }
}

float calculoFrequencia(float matriz[][3][2], int aluno, int turma, int total_aulas)
{
    return total_aulas - matriz[aluno][3][turma];
}

void consultaAluno(float matriz[][3][2], char nome[][2][50], int aluno, int turma, int total_aulas, float notas[][2])
{
    system("cls");
    int status;
    float nota_final, frequencia;
    aluno = aluno - 1;
    turma = turma - 1;
    frequencia = calculoFrequencia(matriz, aluno, turma, total_aulas);
    printf("Nome do aluno: %s\n\n", nome[aluno][turma]);
    printf("Nota 1: %.2f\n", matriz[aluno][0][turma]);
    printf("Nota 2: %.2f\n", matriz[aluno][1][turma]);
    printf("Nota 3: %.2f\n", matriz[aluno][2][turma]);
    printf("Nota final: %.0f\n", notas[aluno][turma]);
    printf("Faltas ==> %.2f\n", frequencia);
    status = verificaStatus(notas, aluno, turma, frequencia);

    status = verificaStatus(notas, aluno, turma, frequencia);

    if (status == 0)
    {
        printf("\033[31mReprovado por falta!\033[0m\n");
    }
    else if (status == 1)
    {
        printf("\033[31mReprovado por nota!\033[0m\n");
    }
    else if (status == 2)
    {
        printf("\033[32mCertificado liberado!\033[0m\n");
    }
    else
    {
        printf("\033[34mFara substituta!\033[0m\n");
    }

    system("pause");
    status = verificaStatus(notas, aluno, turma, frequencia);

    if (status == 0)
    {
        printf("\033[31mReprovado por falta!\033[0m\n");
    }
    else if (status == 1)
    {
        printf("\033[31mReprovado por nota!\033[0m\n");
    }
    else if (status == 2)
    {
        printf("\033[32mCertificado liberado!\033[0m\n");
    }
    else
    {
        printf("\033[34mFara substituta!\033[0m\n");
    }

    system("pause");
}

int verificaStatus(float notas[][2], int aluno, int turma, float frequencia)
{
    if (frequencia > 10)
        return 0;
    if (notas[aluno][turma] >= 7)
        return 2;
    if (notas[aluno][turma] >= 5)
        return 3;
    return 1;
}
