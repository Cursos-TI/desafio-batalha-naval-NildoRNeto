#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_NAVIO 3
#define VALOR_AGUA 0

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    int navioHorizontal[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navioVertical[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    int linhaH = 2; 
    int colunaH = 4; 

    int linhaV = 5; 
    int colunaV = 7; 

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (colunaH + i < TAM_TABULEIRO) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            printf("Navio Horizontal - Parte %d: (%d, %d)\n", i + 1, linhaH, colunaH + i);
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaV + i < TAM_TABULEIRO) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            printf("Navio Vertical - Parte %d: (%d, %d)\n", i + 1, linhaV + i, colunaV);
        }
    }

    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
