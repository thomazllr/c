#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("\nO que deseja fazer?\n\n"
           "1- Consulta por aluno\n"
           "2- Consulta por turma\n"
           "3- Sair\n"
           "Option ==> ");
}

void consultaAluno(dadosAlunos alunos[][2], int aluno, int turma)
{
    int status;
    aluno--;
    turma--;
    notaFinal(alunos);
    printf("Nome do aluno: %s\n", alunos[aluno][turma].nome);
    printf("Nota N1: %.2f\n", alunos[aluno][turma].n1);
    printf("Nota N2: %.2f\n", alunos[aluno][turma].n2);
    printf("Nota N3: %.2f\n", alunos[aluno][turma].n3);
    printf("Frequencia: %d\n", alunos[aluno][turma].presenca);
    printf("Nota final: %.2f\n", alunos[aluno][turma].nf);

    status = verificaStatus(alunos, aluno, turma);

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

void notaFinal(dadosAlunos alunos[][2])
{
    int i, k;
    for (k = 0; k < TURMAS; k++)
    {
        for (i = 0; i < ALUNOS; i++)
        {
            alunos[i][k].nf = (alunos[i][k].n1 + alunos[i][k].n2 + alunos[i][k].n3) / 3.0;
        }
    }
}

int verificaStatus(dadosAlunos alunos[][2], int aluno, int turma)
{
    if (alunos[aluno][turma].presenca < 10)
        return 0;
    if (alunos[aluno][turma].nf >= 7)
        return 2;
    if (alunos[aluno][turma].nf >= 5)
        return 3;
    return 1;
}
