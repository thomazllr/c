#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define TURMAS 2
#define ALUNOS 5

int main()
{

    float escola[ALUNOS][3][TURMAS];
    int i, j, k, cont[2], option, total_aulas, aluno, turma;
    float notas[5][2];
    char nome[5][2][50];
    char op;

    printf("Digite o numero total de aulas ==> ");
    scanf("%d", &total_aulas);

    for (k = 0; k < TURMAS; k++)
    {
        printf("\n\nTURMA [%d]\n", k + 1);
        cont[k] = 0;
        for (i = 0; i < ALUNOS; i++)
        {
            cont[k]++;
            fflush(stdin);
            printf("\nAluno [%d]\n", i + 1);
            printf("Digite o nome do aluno: ");
            scanf("%[^\n]", &nome[i][k]);
            fflush(stdin);
            printf("Digite a primeira nota: ");
            scanf("%f", &escola[i][0][k]);
            printf("Digite a segunda nota: ");
            scanf("%f", &escola[i][1][k]);
            printf("Digite a terceira nota: ");
            scanf("%f", &escola[i][2][k]);
            printf("Frequencia do aluno: ");
            scanf("%f", &escola[i][3][k]);
            printf("Deseja adicionar mais um aluno(s/n)? ==> ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }

    system("cls");

    calculoNotas2(escola, notas);
    p do
    {
        system("cls");
        printf("\nO que deseja fazer?\n\n"
               "1- Consulta por aluno\n"
               "2- Consulta por turma\n"
               "3- Sair\n"
               "Option ==> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o numero da turma: ");
            scanf("%d", &turma);
            if (turma > 2)
            {
                printf("\033[31mTurma nao encontrado\033[0m\n");
                system("pause");
                break;
            }
            printf("Digite o numero do aluno: ");
            scanf("%d", &aluno);
            if (aluno > cont[turma])
            {
                printf("\033[31mAluno nao encontrado\033[0m\n");
                system("pause");
                break;
            }
            consultaAluno(escola, nome, aluno, turma, total_aulas, notas);
            break;
        }
    }
    while (option != 3)
        ;
    return 0;
}