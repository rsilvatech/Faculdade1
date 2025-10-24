

#include <stdio.h>

// Primeira carta
    typedef struct Carta1 {
        char estado1;
        char codigo1[4];
        char cidade1[50];
        int populacao1;
        int pontosTuristicos1;
        float area1;
        float pib1;
    } carta1_t;

    //Segunda carta
    typedef struct Carta2 {
        char estado2;
        char codigo2[4];
        char cidade2[50];
        int populacao2;
        int pontosTuristicos2;
        float area2;
        float pib2;
    } carta2_t;

int main() {
   
    //Inicialização da Primeira e Segunda Carta
    carta1_t c1 = {
        .estado1 = 'N', 
        .codigo1 = "000",
        .cidade1 = "Indefinida",
        .populacao1 = 0,
        .pontosTuristicos1 = 0,
        .area1 = 0.0,
        .pib1 = 0.0
    };

    carta2_t c2 = {
        .estado2 = 'N',
        .codigo2 = "000",
        .cidade2 = "Indefinida",
        .populacao2 = 0,
        .pontosTuristicos2 = 0,
        .area2 = 0.0,
        .pib2 = 0.0
    };



    //Leitura da Primeira Carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c1.estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", c1.codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", c1.cidade1);
    printf("População: ");
    scanf("%d", &c1.populacao1);
    printf("Área (em km²): ");
    scanf("%f", &c1.area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &c1.pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c1.pontosTuristicos1);

    // Leitura da Segunda Carta
    printf("\nCadastro da segunda carta :\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c2.estado2);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", c2.codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", c2.cidade2);
    printf("População: ");
    scanf("%d", &c2.populacao2);
    printf("Área (em km²): ");
    scanf("%f", &c2.area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &c2.pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c2.pontosTuristicos2);


    
    //Exibição da Primeira Carta
    printf("\nPrimeira Carta:\n");
    printf("Estado: %c\n", c1.estado1);
    printf("Código: %s\n", c1.codigo1);
    printf("Nome da Cidade: %s\n", c1.cidade1);
    printf("População: %d\n", c1.populacao1);
    printf("Área: %.f km²\n", c1.area1);
    printf("PIB: %.f bilhões de reais\n", c1.pib1);
    printf("Número de Pontos Turísticos: %d\n", c1.pontosTuristicos1);

    // Exibição da Segunda Carta
    printf("\nPrimeira Carta:\n");
    printf("Estado: %c\n", c2.estado2);
    printf("Código: %s\n", c2.codigo2);
    printf("Nome da Cidade: %s\n", c2.cidade2);
    printf("População: %d\n", c2.populacao2);
    printf("Área: %.2f km²\n", c2.area2);
    printf("Número de Pontos Turísticos: %d\n", c2.pontosTuristicos2);

    return 0;
}