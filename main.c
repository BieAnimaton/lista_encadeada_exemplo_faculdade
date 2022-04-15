#include <stdio.h>
#include <stdlib.h>

struct turma {
    char* nome;
    float nota;
    struct turma* prox;
};

typedef struct turma Turma;

Turma *inicializa (void);
Turma *insere (Turma *t, float nota, char *nome);
void imprime (Turma *t);
void libera (Turma *t);

int main()
{
    Turma *t;

    t = inicializa();
    t = insere(t, 6.5, "Joao");

    imprime(t);

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
        printf("Nota: %.2f, Nome: %s", percorre->nota, percorre->nome);

        percorre = percorre->prox;
    }
    printf("\n");
}

Turma *insere (Turma *t, float nota, char *nome) {
    Turma *novo_aluno = (Turma*)malloc(sizeof(Turma));

    novo_aluno->nome = nome;
    novo_aluno->nota = nota;
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
