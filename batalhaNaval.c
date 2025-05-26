#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_NAVIO 3
#define VALOR_AGUA 0

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    int navioHorizontal[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navioVertical[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Ajuste para o posicionamento igual ao print:
    // Navio vertical: linha 6, coluna J
    // Navio horizontal: linha 7, colunas H, I, J

    // Coordenadas navio vertical (coluna 9)
    int linhaV = 5; // linha 6 no print
    int colunaV = 9; // coluna J (index 9)

    // Coordenadas navio horizontal (linha 7)
    int linhaH = 6; // linha 7 no print
    int colunaH = 7; // coluna H (index 7)

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaV + i < TAM_TABULEIRO) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (colunaH + i < TAM_TABULEIRO) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    // Exibição com letras e números
    printf("TABULEIRO BATALHA NAVAL\n\n  ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Numeração das linhas

        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
