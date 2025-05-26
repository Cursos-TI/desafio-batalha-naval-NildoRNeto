#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_NAVIO 3
#define VALOR_AGUA 0

int main() {
    // Declaração do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    // Navio Horizontal: linha 2, colunas 1 a 3
    int linhaH = 1, colunaH = 0;

    // Navio Vertical: coluna 5, linhas 5 a 7
    int linhaV = 4, colunaV = 5;

    // Navio Diagonal Principal: começa em (0,0)
    int linhaD1 = 0, colunaD1 = 0;

    // Navio Diagonal Secundária: começa em (0,9)
    int linhaD2 = 0, colunaD2 = 9;

    // Posicionamento do navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (colunaH + i < TAM_TABULEIRO && tabuleiro[linhaH][colunaH + i] == VALOR_AGUA) {
            tabuleiro[linhaH][colunaH + i] = VALOR_NAVIO;
        }
    }

    // Posicionamento do navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaV + i < TAM_TABULEIRO && tabuleiro[linhaV + i][colunaV] == VALOR_AGUA) {
            tabuleiro[linhaV + i][colunaV] = VALOR_NAVIO;
        }
    }

    // Posicionamento do navio diagonal principal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaD1 + i < TAM_TABULEIRO && colunaD1 + i < TAM_TABULEIRO && tabuleiro[linhaD1 + i][colunaD1 + i] == VALOR_AGUA) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = VALOR_NAVIO;
        }
    }

    // Posicionamento do navio diagonal secundária
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaD2 + i < TAM_TABULEIRO && colunaD2 - i >= 0 && tabuleiro[linhaD2 + i][colunaD2 - i] == VALOR_AGUA) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = VALOR_NAVIO;
        }
    }

    // Exibição do tabuleiro
    printf("TABULEIRO BATALHA NAVAL - Nível Aventureiro\n\n  ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
