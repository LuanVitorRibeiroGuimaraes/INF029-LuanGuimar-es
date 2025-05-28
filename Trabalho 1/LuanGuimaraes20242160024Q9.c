#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define QTD_NAVIOS 5

typedef struct {
    int tamanho;
    int vida;
} Navio;

typedef struct {
    char grade[TAM][TAM];
    Navio navios[QTD_NAVIOS];
} Jogador;

void inicializarTabuleiro(Jogador* jogador) {
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            jogador->grade[i][j] = ' ';
}

void mostrarTabuleiro(Jogador* jogador, int revelarNavios) {
    printf("  ");
    for(int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");
    for(int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for(int j = 0; j < TAM; j++) {
            char c = jogador->grade[i][j];
            if (!revelarNavios && c == 'N') printf("  ");
            else printf("%c ", c);
        }
        printf("\n");
    }
}

int podePosicionar(Jogador* jogador, int x, int y, int tamanho, char direcao) {
    if (direcao == 'H') {
        if (y + tamanho > TAM) return 0;
        for (int i = 0; i < tamanho; i++)
            if (jogador->grade[x][y+i] != ' ') return 0;
    } else {
        if (x + tamanho > TAM) return 0;
        for (int i = 0; i < tamanho; i++)
            if (jogador->grade[x+i][y] != ' ') return 0;
    }
    return 1;
}

void posicionarNavio(Jogador* jogador, int id, int tamanho) {
    int x, y;
    char direcao;
    while (1) {
        printf("Posicione navio de tamanho %d (x y H/V): ", tamanho);
        scanf("%d %d %c", &x, &y, &direcao);
        if (podePosicionar(jogador, x, y, tamanho, direcao)) break;
        else printf("Posição inválida.\n");
    }
    jogador->navios[id].tamanho = tamanho;
    jogador->navios[id].vida = tamanho;
    if (direcao == 'H')
        for (int i = 0; i < tamanho; i++) jogador->grade[x][y+i] = 'N';
    else
        for (int i = 0; i < tamanho; i++) jogador->grade[x+i][y] = 'N';
}

int atirar(Jogador* atacante, Jogador* defensor) {
    int x, y;
    printf("Digite a coordenada do tiro (x y): ");
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= TAM || y < 0 || y >= TAM) {
        printf("Tiro inválido.\n");
        return 0;
    }
    if (defensor->grade[x][y] == 'N') {
        defensor->grade[x][y] = 'B';
        printf("Acertou!\n");
        return 1;
    } else if (defensor->grade[x][y] == ' '){
        defensor->grade[x][y] = 'X';
        printf("Errou.\n");
        return 0;
    } else {
        printf("Tiro repetido.\n");
        return 0;
    }
}

int acabou(Jogador* jogador) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (jogador->grade[i][j] == 'N') return 0;
    return 1;
}

int main() {
    Jogador jogador1, jogador2;
    int tamanhos[QTD_NAVIOS] = {4, 3, 1, 1, 1};
    inicializarTabuleiro(&jogador1);
    inicializarTabuleiro(&jogador2);

    printf("Jogador 1 - posicionamento dos navios\n");
    for (int i = 0; i < QTD_NAVIOS; i++)
        posicionarNavio(&jogador1, i, tamanhos[i]);

    printf("\nJogador 2 - posicionamento dos navios\n");
    for (int i = 0; i < QTD_NAVIOS; i++)
        posicionarNavio(&jogador2, i, tamanhos[i]);

    int turno = 0;
    while (1) {
        printf("\n--- Turno do Jogador %d ---\n", turno % 2 + 1);
        if (turno % 2 == 0) {
            printf("Tabuleiro inimigo:\n");
            mostrarTabuleiro(&jogador2, 0);
            if (atirar(&jogador1, &jogador2) && acabou(&jogador2)) {
                printf("Jogador 1 venceu!\n");
                break;
            }
        } else {
            printf("Tabuleiro inimigo:\n");
            mostrarTabuleiro(&jogador1, 0);
            if (atirar(&jogador2, &jogador1) && acabou(&jogador1)) {
                printf("Jogador 2 venceu!\n");
                break;
            }
        }
        turno++;
    }
    return 0;
}
