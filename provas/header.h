#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"


typedef struct Student {
    char nome[50];
    float grade1, grade2, final_grade;
    int frequency;

} Student;

typedef struct data_Count {
    int total_students_byclass[3];
    float total_grades_byclass[3];
    int total_grades_above8[3];
    int substitute[3];
    int total_zeros[3];

} data_Count;

// Menus
void menu();

// Data
void readData(Student students[3][30], data_Count *data);
void counterData(Student students[3][30], data_Count *data, int i, int j);

// Checking Student
int checkStudent(Student students[3][30], int i, int j);

// Reports
void report_bystudent(Student students[3][30], data_Count data);
void report_byclass(data_Count data);


