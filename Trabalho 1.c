#include <stdio.h>

#define MAX_ALUNOS 30  // Máximo de alunos permitido

// Função p/ calcular média das notas de um aluno
float calcular_media(float notas[], int qtd_notas) {
    float soma = 0.0;
    for (int i = 0; i < qtd_notas; i++) {
        soma += notas[i];  // Soma todas as notas do aluno
    }
    return soma / qtd_notas;  // Retorna a média das notas
}

// Função p/ calcular média geral da turma
float calcular_media_geral(float medias[], int qtd_alunos) {
    float soma = 0.0;
    for (int i = 0; i < qtd_alunos; i++) {
        soma += medias[i];  // Soma as médias de todos os alunos
    }
    return soma / qtd_alunos;  // Retorna a média geral
}

// Função p/ encontrar maior e menor nota da turma
void encontrar_maior_menor_nota(float notas[], int qtd_notas, float *maior, float *menor) {
    *maior = notas[0];
    *menor = notas[0];
    for (int i = 1; i < qtd_notas; i++) {
        if (notas[i] > *maior) {
            *maior = notas[i];  // Atualiza a maior nota se achar uma maior
        }
        if (notas[i] < *menor) {
            *menor = notas[i];  // Atualiza a menor nota se achar uma menor
        }
    }
}

// Função p/ mostrar o relatório de alunos acima/abaixo da média geral
void exibir_relatorio(float medias[], int qtd_alunos, float media_geral) {
    printf("\nAlunos acima da média geral:\n");
    for (int i = 0; i < qtd_alunos; i++) {
        if (medias[i] > media_geral) {
            printf("Aluno %d com média %.2f\n", i + 1, medias[i]);  // Exibe aluno acima da média
        }
    }
    printf("\nAlunos abaixo da média geral:\n");
    for (int i = 0; i < qtd_alunos; i++) {
        if (medias[i] < media_geral) {
            printf("Aluno %d com média %.2f\n", i + 1, medias[i]);  // Exibe aluno abaixo da média
        }
    }
}

int main() {
    int qtd_alunos;
    float notas[MAX_ALUNOS][3];  // Matriz p/ guardar 3 notas de cada aluno
    float medias[MAX_ALUNOS];  // Guarda a média de cada aluno
    float todas_notas[MAX_ALUNOS * 3];  // Guarda todas as notas p/ achar maior/menor
    int nota_idx = 0;

    // Pergunta qtde de alunos e valida o valor
    printf("Digite a quantidade de alunos na turma (máx 30): ");
    scanf("%d", &qtd_alunos);

    if (qtd_alunos > MAX_ALUNOS || qtd_alunos <= 0) {
        printf("Quantidade de alunos inválida!\n");
        return 1;  // Termina o programa se qtde de alunos for inválida
    }

    // Entrada de dados: ID e notas de cada aluno
    for (int i = 0; i < qtd_alunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);  // Lê cada nota do aluno
            todas_notas[nota_idx++] = notas[i][j];  // Armazena em todas_notas p/ cálculo de maior/menor nota
        }
        medias[i] = calcular_media(notas[i], 3);  // Calcula e armazena a média do aluno
    }

    // Acha a maior e menor nota da turma
    float maior_nota, menor_nota;
    encontrar_maior_menor_nota(todas_notas, qtd_alunos * 3, &maior_nota, &menor_nota);

    // Calcula a média geral da turma
    float media_geral = calcular_media_geral(medias, qtd_alunos);

    // Mostra resultados
    printf("\nResultado:\n");
    for (int i = 0; i < qtd_alunos; i++) {
        printf("Aluno %d - Média: %.2f\n", i + 1, medias[i]);  // Exibe a média individual de cada aluno
    }
    printf("Maior nota da turma: %.2f\n", maior_nota);  // Exibe a maior nota da turma
    printf("Menor nota da turma: %.2f\n", menor_nota);  // Exibe a menor nota da turma
    printf("Média geral da turma: %.2f\n", media_geral);  // Exibe a média geral da turma

    // Mostra relatório dos alunos acima/abaixo da média geral
    exibir_relatorio(medias, qtd_alunos, media_geral);
}
