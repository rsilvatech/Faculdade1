

#include <stdio.h>

    // Estrutura de Cartas
    typedef struct Carta {
        char estado;
        char codigo[4];
        char cidade[50];
        int populacao;
        int pontosTuristicos;
        float area;
        float pib;
    } carta_t;


    // Primeira e segunda cartas
    carta_t c1;
    carta_t c2;


    //Funções para calcular Densidade Populacional;
    float CalcDensidadePopulacional1(const carta_t *c1) {
        float DensidadePopulacional1 = (c1->populacao / c1->area);
        return DensidadePopulacional1;
    }

   float CalcDensidadePopulacional2(const carta_t *c2) {
        float DensidadePopulacional2 = (c2->populacao / c2->area);
        return DensidadePopulacional2;
    }


    //Funções para calcular PIB per capita;
    float CalcPibPerCapita1(const carta_t *c1) {
        float pibPerCapital1 = c1->pib / c1->populacao;
        return pibPerCapital1;
    }

    float CalcPibPerCapita2(const carta_t *c2) {
        float pibPerCapital2= c2->pib / c2->populacao;
        return pibPerCapital2;
    }


int main() {
   
    //Inicialização da Primeira e Segunda Carta
    carta_t c1 = {
        .estado = 'N', 
        .codigo = "000",
        .cidade = "Indefinida",
        .populacao = 0,
        .pontosTuristicos = 0,
        .area = 0.0,
        .pib = 0.0
    };

    carta_t c2 = {
        .estado = 'N',
        .codigo = "000",
        .cidade = "Indefinida",
        .populacao = 0,
        .pontosTuristicos = 0,
        .area = 0.0,
        .pib = 0.0
    };

    //Leitura da Primeira Carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c1.estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", c1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", c1.cidade);
    printf("População: ");
    scanf("%d", &c1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c1.pontosTuristicos);

    // Leitura da Segunda Carta
    printf("\nCadastro da segunda carta :\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c2.estado);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", c2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", c2.cidade);
    printf("População: ");
    scanf("%d", &c2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c2.pontosTuristicos);

    //Exibição da Primeira Carta
    printf("\nPrimeira Carta:\n");
    printf("Estado: %c\n", c1.estado);
    printf("Código: %s\n", c1.codigo);
    printf("Nome da Cidade: %s\n", c1.cidade);
    printf("População: %d\n", c1.populacao);
    printf("Área: %.f km²\n", c1.area);
    printf("PIB: %.f bilhões de reais\n", c1.pib);
    printf("Número de Pontos Turísticos: %d\n", c1.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km²\n",CalcDensidadePopulacional1(&c1));
    printf("PIB per capita: %f reais\2n",CalcPibPerCapita1(&c1));


    // Exibição da Segunda Carta
    printf("\nSegunda Carta:\n");
    printf("Estado: %c\n", c2.estado);
    printf("Código: %s\n", c2.codigo);
    printf("Nome da Cidade: %s\n", c2.cidade);
    printf("População: %d\n", c2.populacao);
    printf("Área: %.2f km²\n", c2.area);
    printf("Número de Pontos Turísticos: %d\n", c2.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", CalcDensidadePopulacional2(&c2));
    printf("PIB per capita: %.2f reais\n", CalcPibPerCapita2(&c2));

    return 0;

}