#include <stdio.h>
#include <stdlib.h>

#define TamTabuleiro 10
#define TamHabilidade 5
#define Habilidade 1
#define TamNavio 3
#define Navio 3
#define Agua 0

// ===== Bloco das coordenadas iniciais dos Navios ===== //

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

// ===== Bloco de definição da Habilidade ===== //

// Função para construir o cone dentro de uma submatriz
void ConstruirCone(int matrizCone[TamHabilidade][TamHabilidade]) {
    for (int i = 0; i < TamHabilidade-2; i++) {
        for (int j=0; j<TamHabilidade; j++) {
            if (j>=TamHabilidade/2 - i && j <= TamHabilidade / 2 + i) {
                matrizCone[i][j] = 1;
            } else {
                matrizCone[i][j] = 0;
            }
        }
    }
}

// Função para construir a cruz dentro de uma submatriz
void ConstruirCruz(int matrizCruz[TamHabilidade][TamHabilidade]) {
    for (int i = 0; i < TamHabilidade; i++) {
        for (int j=0; j<TamHabilidade; j++) {
            if (i==TamHabilidade/2  || j == TamHabilidade / 2) {
                matrizCruz[i][j] = 1;
            } else {
                matrizCruz[i][j] = 0;
            }
        }
    }
}

// Função para construir o octaedro (lozango) dentro de uma submatriz
void construirOctaedro(int matrizOctaedro[TamHabilidade][TamHabilidade]) {
    for (int i = 0; i < TamHabilidade; i++) {
        for (int j = 0; j < TamHabilidade; j++) {
            int distancia = abs(i - TamHabilidade / 2) + abs(j - TamHabilidade / 2);
            if (distancia <= TamHabilidade / 2) {
                matrizOctaedro[i][j] = 1;
            } else {
                matrizOctaedro[i][j] = 0;
            }
        }
    }
}


// Função para aplicar a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TamTabuleiro][TamTabuleiro], int submatriz[TamHabilidade][TamHabilidade], int origemLinha, int origemColuna) {
    for (int i = 0; i < TamHabilidade; i++) {
        for (int j = 0; j < TamHabilidade; j++) {
            int linhaTab = origemLinha - TamHabilidade / 2 + i;
            int colunaTab = origemColuna - TamHabilidade / 2 + j;

            if (linhaTab >= 0 && linhaTab < TamTabuleiro && colunaTab >= 0 && colunaTab < TamTabuleiro) {
                if (submatriz[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = Habilidade;
                }
            }
        }
    }
}


int main() {

    // ===== Bloco de definição e inicialização do tabuleiro e matrizes de habilidade ===== //

    int tabuleiro[TamTabuleiro][TamTabuleiro];
    int matrizCone[TamHabilidade][TamHabilidade];
    int matrizCruz[TamHabilidade][TamHabilidade];
    int matrizOctaedro[TamHabilidade][TamHabilidade];
    

    for (int i = 0; i < TamTabuleiro; i++) {
        for (int j = 0; j < TamTabuleiro; j++) {
            tabuleiro[i][j] = Agua; //preenche todas as posições do tabulero com zeros
        }
    }

    // ===== Bloco de descrição das posições dos navios no tabuleiro ===== //

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

    // ===== Bloco de exibição do tabuleiro e das peças ===== //

    
    //Constrói e aplica as habilidades
    ConstruirCone(matrizCone);
    aplicarHabilidade(tabuleiro, matrizCone, 2, 7);
\
    construirOctaedro(matrizOctaedro);
    aplicarHabilidade(tabuleiro, matrizOctaedro, 5, 2);

    ConstruirCruz(matrizCruz);
    aplicarHabilidade(tabuleiro, matrizCruz, 7, 7);


    // ===== Bloco de exibição do tabuleiro e das peças ===== //
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