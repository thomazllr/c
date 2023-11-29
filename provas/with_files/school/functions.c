#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menu() {
    printf("\n\nO que deseja fazer?\n");
    printf("\t1-CONSULTA POR ALUNO\n");
    printf("\t2-CONSULTA POR TURMA\n");
    printf("\t3-SAIR\n");

}

void readData(Student students[3][30], data_Count *data) {

    char op;
    for(int i =0; i<3;i++) {
        printf(GREEN "\n\tTurma [%d]\n" RESET, i + 1 );
        for(int j=0; j<30;j++) {
            printf("\n\tAluno %d\n\n", j + 1);
            printf("Digite o nome do aluno ==> ");
            scanf("%s", students[i][j].nome);
            printf("Digite a nota 1 do aluno ==> ");
            scanf("%f", &students[i][j].grade1);
            printf("Digite a nota 2 do aluno == > ");
            scanf("%f", &students[i][j].grade2);
            printf("Digite a quantidade de faltas do aluno ==> ");
            scanf("%d", &students[i][j].frequency);
            counterData(students, data, i ,j);
            printf("Deseja adicionar mais um aluno (s/n)? ");
            scanf(" %c", &op);
            if(op == 'n') {
                break;
            }
        }
    }

}

void counterData(Student students[3][30], data_Count *data, int i, int j){

            int status;
            data->total_students_byclass[i] += 1;
            if(students[i][j].grade1 == 0 || students[i][j].grade2 == 0) {
                data->total_zeros[i] += 1;
            }
            students[i][j].final_grade = (students[i][j].grade1 + students[i][j].grade2) / 2.0;
            if(students[i][j].final_grade > 8) {
                data->total_grades_above8[i] += 1;
            }
            status = checkStudent(students, i , j);
            if (status == 2) {
                data->substitute[i] += 1;
            }
            data->total_grades_byclass[i] += students[i][j].final_grade;


}

int checkStudent(Student students[3][30], int i, int j) {

    if (students[i][j].frequency > 10 ) {
        return 3;
    }
    if (students[i][j].final_grade > 7) {
        return 1;
    }
    if(students[i][j].final_grade > 5) {
        return 2;
    } 
    return 0;
    
}

void report_bystudent(Student students[3][30], data_Count data) {

    int aluno, turma, status;
    printf("Digite o numero da turma que deseja buscar: ");
    scanf("%d", &turma);
    turma--;
    printf("Digite o numero do aluno que deseja buscar: ");
    scanf("%d", &aluno);
    aluno--;

    printf("Nome do aluno: %s\n", students[turma][aluno].nome);
    printf("Nota 1 do aluno: %.2f\n", students[turma][aluno].grade1);
    printf("Nota 2 do aluno: %.2f\n", students[turma][aluno].grade2);
    printf("Quantidade total de faltas: %d\n", students[turma][aluno].frequency);
    printf("Nota final do aluno ==> %.2f\n", students[turma][aluno].final_grade);
    status = checkStudent(students, turma, aluno);
    if (status == 3) {
        printf(RED "REPROVADO POR FALTA\n" RESET);
    }
    else if (status == 2) {
        printf(GREEN "FARA SUBSTITUTA" RESET);
    }
    else if (status == 1){
        printf(GREEN "APROVADO POR NOTA" RESET);
    }
    else {
        printf(RED"REPROVADO POR NOTA" RESET);
    }
}

void report_byclass(data_Count data) {
        int turma;
        float media_geral;
        printf("Digite o numero da turma que deseja buscar: ");
        scanf("%d", &turma);
        turma--;

        media_geral = data.total_grades_byclass[turma] / data.total_students_byclass[turma];

        printf("Numero total de alunos ==> %d\n", data.total_students_byclass[turma]);
        printf("Numero de alunos que tiveram nota acima de 8 ==> %d\n", data.total_grades_above8[turma]);
        printf("Alunos que tiveram algum zero ==> %d\n", data.total_zeros[turma]);
        printf("Quantos alunos farão a substituta ==> %d\n", data.substitute[turma]);
        printf("Media geral da turma -> %.2f\n", media_geral);

}