#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void inicializaTabuleiro(int tabuleiro[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void imprimeTabuleiro(int tabuleiro[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void desenhaCone(int tabuleiro[TAM][TAM], int x, int y) {
    // Desenha um cone com o vértice em (x,y) expandindo para baixo
    for(int i = 0; i < 3; i++) {  // Altura do cone
        for(int j = -i; j <= i; j++) {  // Largura variável
            int nx = x + i;
            int ny = y + j;
            if(nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
                tabuleiro[nx][ny] = 1;  // Marca com 1
            }
        }
    }
}

void desenhaCruz(int tabuleiro[TAM][TAM], int x, int y) {
    // Centro
    if(x >= 0 && x < TAM && y >= 0 && y < TAM)
        tabuleiro[x][y] = 3;

    // Linhas da cruz
    for(int i = -2; i <= 2; i++) {
        if(x + i >= 0 && x + i < TAM)
            tabuleiro[x + i][y] = 3;  // Vertical
        if(y + i >= 0 && y + i < TAM)
            tabuleiro[x][y + i] = 3;  // Horizontal
    }
}

void desenhaOctaedro(int tabuleiro[TAM][TAM], int x, int y) {
    // Desenha um losango
    for(int i = -2; i <= 2; i++) {
        for(int j = -2; j <= 2; j++) {
            if(abs(i) + abs(j) <= 2) {  // Condição do losango
                int nx = x + i;
                int ny = y + j;
                if(nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
                    tabuleiro[nx][ny] = 2;  // Marca com 2
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    
    inicializaTabuleiro(tabuleiro);
    
    // Desenhar as figuras em posições arbitrárias
    desenhaCone(tabuleiro, 0, 5);
    desenhaCruz(tabuleiro, 5, 5);
    desenhaOctaedro(tabuleiro, 8, 2);
    
    imprimeTabuleiro(tabuleiro);

    return 0;
}
