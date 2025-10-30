#include <stdio.h>

int main() {
    // Movimento da Torre: 5 casas para a direita usando estrutura for
    int movimentoTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 0; i < movimentoTorre; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita usando while
    int movimentoBispo = 5;
    int contadorBispo = 0;
    printf("\nMovimento do Bispo:\n");
    while (contadorBispo < movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    // Movimento da Rainha: 8 casas para a esquerda usando do-while
    int movimentoRainha = 8;
    int contadorRainha = 0;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentoRainha);

    // Movimento do Cavalo: 2 casas para baixo e 1 para a esquerda usando loops aninhados
    int movimentoVertical = 2;
    int movimentoHorizontal = 1;
    int i;

    printf("\nMovimento do Cavalo:\n");

    // Loop externo: movimentação vertical (2 casas para baixo)
    for (i = 0; i < movimentoVertical; i++) {
        printf("Baixo\n");

        // Loop interno: após cada movimento vertical, verifica se é hora de mover horizontalmente
        int j = 0;
        while (j < movimentoHorizontal && i == movimentoVertical - 1) {
            printf("Esquerda\n");
            j++;
        }
    }

    return 0;
}

