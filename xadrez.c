#include <stdio.h>

// Função recursiva para movimentar a Torre (horizontalmente para a direita)
void moverTorre(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

// Função recursiva para movimentar a Rainha (horizontalmente para a esquerda)
void moverRainha(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// Função recursiva para movimentar o Bispo (diagonal para cima e à direita)
void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casasRestantes - 1);
}

// Função com loops aninhados para simular o movimento diagonal do Bispo
void moverBispoComLoops(int movimentosVerticais, int movimentosHorizontais) {
    for (int i = 0; i < movimentosVerticais; i++) {
        for (int j = 0; j < movimentosHorizontais; j++) {
            // Simula uma casa diagonal como combinação de vertical e horizontal
            printf("Cima Direita\n");
        }
    }
}

// Função com loops complexos para o Cavalo (duas casas para cima e uma para a direita).
void moverCavalo() {
    int movimentosVerticais = 2;
    int movimentosHorizontais = 1;

    printf("Movimento do Cavalo:\n");

    for (int j = 0; j < movimentosVerticais+1; j++) {    

        for (int i = 0; i < movimentosHorizontais; i++) {
            if (i < movimentosVerticais) { 
                printf("Cima\n"); // <-- itera duas vezes e depois sai (condição if deixa de ser verdadeira) do for loop interno
                continue; 
            }
        }
        if (j == movimentosHorizontais) { //<-- itera uma vez e encerra o for loop externo
            printf("Direita\n");
            break;
        }
    }
}

int main() {

    // Movimento da Torre com recursividade
    int casasTorre = 5;
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    // Movimento do Bispo com recursividade
    int casasBispo = 5;
    printf("\nMovimento do Bispo (Recursivo):\n");
    moverBispoRecursivo(casasBispo);

    // Movimento do Bispo com loops aninhados
    printf("\nMovimento do Bispo (Loops Aninhados):\n");
    moverBispoComLoops(2, 3); // Exemplo: 2 verticais × 3 horizontais = 6 movimentos diagonais

    // Movimento da Rainha com recursividade
    int casasRainha = 8;
    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    // Movimento do Cavalo com loops complexos
    printf("\n");
    moverCavalo();

    return 0;
}
