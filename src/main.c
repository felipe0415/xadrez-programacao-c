#include <stdio.h>
#include <stdlib.h>

// Tamanho do tabuleiro
#define TAM 8

// Função para imprimir o tabuleiro com os movimentos possíveis
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para limpar o tabuleiro
void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// MÓDULO NOVATO

// Torre - movimentos horizontais e verticais (usando FOR)
void moverTorre(int linha, int coluna) {
    int tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    for (int i = 0; i < TAM; i++) {
        tabuleiro[linha][i] = 1; // horizontal
        tabuleiro[i][coluna] = 1; // vertical
    }

    tabuleiro[linha][coluna] = 8; // posição da peça
    printf("Movimentos da Torre:\n");
    imprimirTabuleiro(tabuleiro);
}

// Bispo - movimentos diagonais (usando WHILE)
void moverBispo(int linha, int coluna) {
    int tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    int i, j;

    // Diagonal superior esquerda
    i = linha; j = coluna;
    while (i >= 0 && j >= 0)
        tabuleiro[i--][j--] = 1;

    // Diagonal superior direita
    i = linha; j = coluna;
    while (i >= 0 && j < TAM)
        tabuleiro[i--][j++] = 1;

    // Diagonal inferior esquerda
    i = linha; j = coluna;
    while (i < TAM && j >= 0)
        tabuleiro[i++][j--] = 1;

    // Diagonal inferior direita
    i = linha; j = coluna;
    while (i < TAM && j < TAM)
        tabuleiro[i++][j++] = 1;

    tabuleiro[linha][coluna] = 8; // posição da peça
    printf("Movimentos do Bispo:\n");
    imprimirTabuleiro(tabuleiro);
}

// Rainha - combinação de torre e bispo (usando DO-WHILE)
void moverRainha(int linha, int coluna) {
    int tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    int i;

    // Horizontais e verticais
    i = 0;
    do {
        tabuleiro[linha][i] = 1;
        tabuleiro[i][coluna] = 1;
        i++;
    } while (i < TAM);

    // Diagonais
    int x, y;

    x = linha; y = coluna;
    do { x--; y--; if (x >= 0 && y >= 0) tabuleiro[x][y] = 1; } while (x > 0 && y > 0);
    x = linha; y = coluna;
    do { x--; y++; if (x >= 0 && y < TAM) tabuleiro[x][y] = 1; } while (x > 0 && y < TAM-1);
    x = linha; y = coluna;
    do { x++; y--; if (x < TAM && y >= 0) tabuleiro[x][y] = 1; } while (x < TAM-1 && y > 0);
    x = linha; y = coluna;
    do { x++; y++; if (x < TAM && y < TAM) tabuleiro[x][y] = 1; } while (x < TAM-1 && y < TAM-1);

    tabuleiro[linha][coluna] = 8;
    printf("Movimentos da Rainha:\n");
    imprimirTabuleiro(tabuleiro);
}

// MÓDULO AVENTUREIRO

// Cavalo - movimento em L (usando loops aninhados)
void moverCavalo(int linha, int coluna) {
    int tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    int movimentos[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };

    for (int i = 0; i < 8; i++) {
        int novaLinha = linha + movimentos[i][0];
        int novaColuna = coluna + movimentos[i][1];

        if (novaLinha >= 0 && novaLinha < TAM && novaColuna >= 0 && novaColuna < TAM)
            tabuleiro[novaLinha][novaColuna] = 1;
    }

    tabuleiro[linha][coluna] = 8;
    printf("Movimentos do Cavalo:\n");
    imprimirTabuleiro(tabuleiro);
}

// MÓDULO MESTRE

// Rainha recursiva - marca caminhos até a borda do tabuleiro
void moverRainhaRecursiva(int linha, int coluna, int tabuleiro[TAM][TAM], int dx, int dy) {
    int novaLinha = linha + dx;
    int novaColuna = coluna + dy;

    if (novaLinha < 0 || novaLinha >= TAM || novaColuna < 0 || novaColuna >= TAM)
        return;

    tabuleiro[novaLinha][novaColuna] = 2; // marca o caminho com 2
    moverRainhaRecursiva(novaLinha, novaColuna, tabuleiro, dx, dy);
}

void simularRainhaRecursiva(int linha, int coluna) {
    int tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    // Todas as 8 direções possíveis da Rainha
    int direcoes[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, // vertical/horizontal
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // diagonais
    };

    for (int i = 0; i < 8; i++) {
        moverRainhaRecursiva(linha, coluna, tabuleiro, direcoes[i][0], direcoes[i][1]);
    }

    tabuleiro[linha][coluna] = 8;
    printf("Movimentos da Rainha com Recursividade:\n");
    imprimirTabuleiro(tabuleiro);
}

// Menu principal
int main() {
    int linha, coluna, opcao;

    printf("=== SIMULADOR DE MOVIMENTOS DE XADREZ ===\n");
    printf("Informe a posição inicial da peça (linha e coluna de 0 a 7):\n");
    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);

    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
        printf("Posição inválida!\n");
        return 1;
    }

    do {
        printf("\nEscolha a peça:\n");
        printf("1 - Torre\n");
        printf("2 - Bispo\n");
        printf("3 - Rainha (movimento simples)\n");
        printf("4 - Cavalo\n");
        printf("5 - Rainha (recursiva - avançado)\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: moverTorre(linha, coluna); break;
            case 2: moverBispo(linha, coluna); break;
            case 3: moverRainha(linha, coluna); break;
            case 4: moverCavalo(linha, coluna); break;
            case 5: simularRainhaRecursiva(linha, coluna); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 0);

    return 0;
}
