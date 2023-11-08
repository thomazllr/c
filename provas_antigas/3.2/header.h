#define TURMAS 2
#define ALUNOS 5

struct alunos
{
    char nome[50];
    float n1;
    float n2;
    float n3;
    float nf;
    int presenca;
};
typedef struct alunos dadosAlunos;

struct turma
{
    float notas[5];
    int notas_zeradas;
};
typedef struct turma dadosTurmas;

void menu();

void consultaAluno(dadosAlunos alunos[][2], int aluno, int turma);

void notaFinal(dadosAlunos alunos[][2]);
int verificaStatus(dadosAlunos alunos[][2], int aluno, int turma);