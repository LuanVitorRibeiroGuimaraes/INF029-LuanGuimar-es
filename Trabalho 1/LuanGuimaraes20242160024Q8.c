#include <stdio.h>
#include <string.h>
#include <ctype.h>

void mostrarTabuleiro(char tabuleiro[3][3]) {
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n  -----------\n");
    }
    printf("\n");
}

int verificarVencedor(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];

    return 0;
}

int main() {
    char tabuleiro[3][3];
    char entrada[3];
    int jogador = 1, jogadas = 0;

    // Inicializa o tabuleiro com espaços
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';

    while (1) {
        mostrarTabuleiro(tabuleiro);
        printf("Jogador %d (%c), informe sua jogada (ex: B3): ", jogador, jogador == 1 ? 'X' : 'O');
        scanf("%s", entrada);

        if (strlen(entrada) != 2) {
            printf("Entrada inválida! Use formato como A1, B2...\n");
            continue;
        }

        int linha = toupper(entrada[0]) - 'A';
        int coluna = entrada[1] - '1';

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Posição inválida!\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != ' ') {
            printf("Essa célula já está ocupada!\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador == 1 ? 'X' : 'O';
        jogadas++;

        int vencedor = verificarVencedor(tabuleiro);
        if (vencedor) {
            mostrarTabuleiro(tabuleiro);
            printf("Jogador %d (%c) venceu!\n", vencedor == 'X' ? 1 : 2, vencedor);
            break;
        } else if (jogadas == 9) {
            mostrarTabuleiro(tabuleiro);
            printf("Empate! Ninguém venceu.\n");
            break;
        }

        jogador = jogador == 1 ? 2 : 1;
    }

    return 0;
}
