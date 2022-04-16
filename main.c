#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct turma {
    char *nome;
    int idade;
    char *telefone;
    float nota_p1;
    float nota_p2;
    struct turma* prox;
};

typedef struct turma Turma;

Turma *inicializa (void);
Turma *insere (Turma *t, char *nome, int idade, char *telefone, float nota_p1, float nota_p2);
void imprime (Turma *t);
void libera (Turma *t);

int main()
{
    setlocale(LC_ALL, "portuguese");

    Turma *turma;

    turma = inicializa();
    turma = insere(turma, "João", 19, "+19123456789", 6.7, 7.8);
    turma = insere(turma, "Maria", 20, "+13556879832", 9.9, 9.8);
    turma = insere(turma, "Frederico", 23, "+55990216714", 8.5, 5.5);
    turma = insere(turma, "Ana", 22, "+20220981484", 7.0, 9.0);
    turma = insere(turma, "Pedro", 20, "+19886741345", 9.0, 10.0);
    turma = insere(turma, "Giovana", 20, "+18887711344", 4.0, 10.0);
    turma = insere(turma, "Rafael", 19, "+19990017887", 5.0, 4.0);
    turma = insere(turma, "Beatriz", 19, "+12223309881", 10.0, 10.0);

    imprime(turma);

    return 0;
}

Turma *inicializa (void) {
    return NULL;
}

void imprime (Turma *turma) {
    Turma *percorre;

    percorre = turma;

    printf("Listagem dos Alunos:\n");
    while (percorre != NULL) {
        printf("Nome: %s, Idade: %d, Telefone: %s, Notas: %.2f e %.2f\n",
               percorre->nome, percorre->idade, percorre->telefone, percorre->nota_p1, percorre->nota_p2);

        percorre = percorre->prox;
    }
    printf("\n");
}

Turma *insere (Turma *t, char *nome, int idade, char *telefone, float nota_p1, float nota_p2) {
    Turma *novo_aluno = (Turma*)malloc(sizeof(Turma));

    novo_aluno->nome = nome;
    novo_aluno->idade = idade;
    novo_aluno->telefone = telefone;
    novo_aluno->nota_p1 = nota_p1;
    novo_aluno->nota_p2 = nota_p2;
    novo_aluno->prox = t;

    return novo_aluno;
}

void libera (Turma *t) {
    Turma *percorre;

    percorre = t;

    while (percorre != NULL) {
        Turma *t = percorre->prox;
        free(percorre);
        percorre = t;
    }
}
