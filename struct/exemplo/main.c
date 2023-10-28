#include <stdio.h>

#define TAM 50

struct tipo_pessoa
{
    int idade;
    float peso;
    char nome[TAM];
};

typedef struct tipo_pessoa pessoa;
int main()
{
    pessoa pes = {0, 0.0, "Teste"};

    printf("Inicio\n\n");
    printf("pes.idade = %d\n\n", pes.idade);
    printf("pes.peso = %f\n\n", pes.peso);
    printf("pes.nome = %s\n\n", pes.nome);

    printf("Entradas do usuário: \n\n");
    printf("Digite a idade --> ");
    scanf("%d", &pes.idade);
    printf("Digite o nome --> ");
    scanf("%s", &pes.nome);
    printf("Digite a peso --> ");
    scanf("%f", &pes.peso);

    printf("Nova idade = %d, Novo nome = %s, Novo peso = %.2f", pes.idade, pes.nome, pes.peso);
    return 0;
}