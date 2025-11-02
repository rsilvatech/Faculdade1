#include <stdio.h>

#define TamTabuleiro 10
#define TamNavio 3
#define Agua 0
#define Navio 3

int main() {

    // ===== Bloco de definição e inicialização do tabuleiro

    int tabuleiro[TamTabuleiro][TamTabuleiro];
    for (int i = 0; i < TamTabuleiro; i++) {
        for (int j = 0; j < TamTabuleiro; j++) {
            tabuleiro[i][j] = Agua; //preenche todas as posições do tabulero com zeros
        }
    }

    // ===== Bloco das coordenadas iniciais dos Navios =====

    //Coordenadas iniciais do navio horizontal C(1,2)
    int linhaNavioHorizontal = 0;
    int colunaNavioHorizontal = 3;

    //Coordenadas iniciais do navio vertical C(4,1)
    int linhaNavioVertical = 3;
    int colunaNavioVertical = 0;

    //Coordenadas iniciais do navio diagonal C(4,4)
    int linhaNavioDiagonal1 = 5;
    int colunaNavioDiagonal1 = 5;

    //Coordenadas iniciais do navio diagonal C(5,2)
    int linhaNavioDiagonal2 = 6;
    int colunaNavioDiagonal2 = 3;


    // ===== Bloco de descrição das posições dos navios no tabuleiro =====

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioHorizontal + TamNavio <= TamTabuleiro) {
        // Verifica se há sobreposição com o navio horizontal
        int sobreposicao = 0;
        for (int i = 0; i < TamNavio; i++) {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == Navio) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio vertical
            for (int i = 0; i < TamNavio; i++) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = Navio;
            }
        } else {
            printf("Erro: Sobreposição entre navios detectada.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio Horizontal 2 fora dos limites do tabuleiro.\n");
        return 1;
    }


    // Verifica se o navio horizontal cabe no tabuleiro
    if (linhaNavioVertical + TamNavio <= TamTabuleiro) {
        // Verifica se há sobreposição com o navio horizontal
        int sobreposicao = 0;
        for (int i = 0; i < TamNavio; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == Navio) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal
            for (int i = 0; i < TamNavio; i++) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = Navio;
            }
        } else {
            printf("Erro: Sobreposição entre navios detectada.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verifica se o navio diagonal 1 cabe no tabuleiro
    if (linhaNavioDiagonal1 + TamNavio <= TamTabuleiro) {
        // Verifica se há sobreposição com o navio diagonal 1
        int sobreposicao = 0;
        for (int i = 0; i < TamNavio; i++) {
            if (tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1+i] == Navio) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio diagonal 1
            for (int i = 0; i < TamNavio; i++) {
                tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1+i] = Navio;
            }
        } else {
            printf("Erro: Sobreposição entre navios detectada.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio diagonal 2 fora dos limites do tabuleiro.\n");
        return 1;
    }


    // Verifica se o navio diagonal 2 cabe no tabuleiro
    if (linhaNavioDiagonal2 + TamNavio <= TamTabuleiro) {
        // Verifica se há sobreposição com o navio diagonal 2
        int sobreposicao = 0;
        for (int i = 0; i < TamNavio; i++) {
            if (tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2] == Navio) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio diagonal 2
            for (int i = 0; i < TamNavio; i++) {
                tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2-i] = Navio;
            }
        } else {
            printf("Erro: Sobreposição entre navios detectada.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio diagonal 2 fora dos limites do tabuleiro.\n");
        return 1;
    }

    // ===== Bloco de exibição do tabuleiro e das peças

    char alfabeto[10] = {'A','B','C','D','E','F','G','H','I','J'};

    //Exibe tabuleiro e peças
    printf("Tabuleiro de Batalha Naval:\n\n");
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < TamTabuleiro; i++) {
        printf("%c ", alfabeto[i]);

        for (int j = 0; j < TamTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}