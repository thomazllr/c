#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

int main()
{
    dadosAlunos alunos[ALUNOS][TURMAS];
    dadosTurmas class;
    char op;
    int i, k, j, option, turma, aluno, cont[2];

    for (k = 0; k < TURMAS; k++)
    {
        cont[k] = 0;
        printf("\n\nTURMA [%d]\n", k + 1);
        for (i = 0; i < ALUNOS; i++)
        {
            cont[k]++;
            fflush(stdin);
            printf("\nAluno [%d]\n", i + 1);
            printf("Digite o nome do aluno: ");
            scanf("%[^\n]", &alunos[i][k].nome);
            fflush(stdin);
            printf("Digite a primeira nota: ");
            scanf("%f", &alunos[i][k].n1);
            printf("Digite a segunda nota: ");
            scanf("%f", &alunos[i][k].n2);
            printf("Digite a terceira nota: ");
            scanf("%f", &alunos[i][k].n3);
            printf("Frequencia do aluno: ");
            scanf("%d", &alunos[i][k].presenca);
            printf("Deseja adicionar mais um aluno(s/n)? ==> ");
            scanf(" %c", &op);
            if (op == 'n')
            {
                break;
            }
        }
    }

    system("clear");

    do
    {
        system("clear");
        menu();
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
            consultaAluno(alunos, aluno, turma);
            break;

        default:
            break;
        }

    } while (option != 3);

    return 0;
}