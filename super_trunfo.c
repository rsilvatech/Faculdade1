#include <stdio.h>

    // Estrutura de Cartas
    typedef struct Carta {
        char estado;
        char codigo[4];
        char cidade[50];
        unsigned int populacao;
        unsigned int pontosTuristicos;
        float area;
        float pib;
    } carta_t;

    // Primeira e segunda cartas
    carta_t c1;
    carta_t c2;

    //Inicialização da Primeira e Segunda Cartas
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

    //Função para calcular Densidade Populacional;
    float CalcDensidadePopulacional(const carta_t *c) {
        float DensidadePopulacional = ((float)c->populacao / c->area);
        return DensidadePopulacional;
    }

    //Função para calcular PIB per capita;
    float CalcPibPerCapita(const carta_t *c) {
        float pibPerCapital = c->pib / (float)c->populacao;
        return pibPerCapital;
    }

    //Função para calcular "superpoder" da carta
    float CalcSuperPoder (const carta_t *c) {
        float superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + CalcPibPerCapita(c) + (1 / CalcDensidadePopulacional(c));
        return superPoder;
    }


    //Funções de comparação de atributos entre cartas (linhas 59-156)
    int CompPopulação(const carta_t *c1, carta_t *c2) {
        printf("População: ");
        float pop_f = ((float)c1->populacao)/((float)c2->populacao);
        if (pop_f > 1) {
            printf("Carta 1 venceu \n");
        } else if(pop_f == 1) {
            printf("Empate! \n");
        } else if((0 <pop_f)&&(pop_f < 1)) {
            printf("Carta 2 Venceu \n");
        } else {
            return 0;
        }
    }

    float CompÁrea(const carta_t *c1, carta_t *c2) {
        printf("Área: ");
        float area_f = (c1->area)/(c2->area);
        if (area_f > 1) {
            printf("Carta 1 venceu \n");
        } else if(area_f == 1) {
            printf("Empate! \n");
        } else if((0 <area_f)&&(area_f < 1)) {
            printf("Carta 2 Venceu \n");
        } else {
            return 0;
        }
    }

    float CompPIB(const carta_t *c1, carta_t *c2) {
        printf("PIB: ");
        float pib_f = (c1->pib)/(c2->pib);
        if (pib_f > 1) {
            printf("Carta 1 venceu \n");
        } else if(pib_f == 1) {
            printf("Empate! \n");
        } else if((0 <pib_f)&&(pib_f< 1)) {
            printf("Carta 2 Venceu \n");
        } else {
            return 0;
        }
    }

    int CompPontoTuristico(const carta_t *c1, carta_t *c2) {
        printf("Pontos Turísticos: ");
        float ponTurist_f = ((float)c1->pontosTuristicos)/((float)c2->pontosTuristicos);
        if (ponTurist_f > 1) {
            printf("Carta 1 venceu \n");
        } else if(ponTurist_f == 1) {
            printf("Empate! \n");
        } else if((0 <ponTurist_f)&&(ponTurist_f < 1)) {
            printf("Carta 2 Venceu \n");
        } else {
            return 0;
        }
    }

    float CompDensidadePopulacional(const carta_t *c1, carta_t *c2) {
        printf("Densidade Populacional: "); 
        float densPop_f = CalcDensidadePopulacional(c1) / CalcDensidadePopulacional(c2);
        if (densPop_f > 1) {
            printf("Carta 1 venceu \n");
        } else if(densPop_f == 1) {
            printf("Empate! \n");
        } else if((0 <densPop_f)&&(densPop_f < 1)) {
            printf("Carta 2 Venceu \n");
        } else {
            return 0;
        }
    }

    float CompPibPerCapita(const carta_t *c1, carta_t *c2) {
        printf("PIB per capita: ");
        float PibPerCapita_f = CalcPibPerCapita(c1) / CalcPibPerCapita(c2);
        if (PibPerCapita_f > 1) {
            printf("Carta 1 venceu \n");
        } else if(PibPerCapita_f == 1) {
            printf("Empate! \n");
        } else if((0<PibPerCapita_f)&&(PibPerCapita_f <1)) {
            printf("Carta 2 Venceu  \n");
        } else {
            return 0;
        }
    }

    int CompSuperPoder(const carta_t *c1, carta_t *c2) {
        printf("Super Poder:");
        float superPoder_f = CalcSuperPoder(c1) / CalcSuperPoder(c2);
        if (superPoder_f > 1) {
            printf("Carta 1 venceu \n");
        } else if(superPoder_f == 1) {
            printf("Empate! \n");
        } else if((0< superPoder_f)&&(superPoder_f < 1)) {
            printf("Carta 2 Venceu \n");
        } else {
            return 0;
        }
    }

    //Exibição da Primeira Carta
    void ExibeCarta1(const carta_t c1) {
        printf("\nPrimeira Carta:\n");
        printf("Estado: %c\n", c1.estado);
        printf("Código: %s\n", c1.codigo);
        printf("Nome da Cidade: %s\n", c1.cidade);
        printf("População: %d\n", c1.populacao);
        printf("Área: %.f km²\n", c1.area);
        printf("PIB: %.f bilhões de reais\n", c1.pib);
        printf("Número de Pontos Turísticos: %d\n", c1.pontosTuristicos);
        printf("Densidade Populacional: %.2f habitantes/km²\n",CalcDensidadePopulacional(&c1));
        printf("PIB per capita: %f reais\2n",CalcPibPerCapita(&c1));
    }

    //Exibição da Segunda Carta
    void ExibeCarta2(const carta_t c2) {
        printf("\nSegunda Carta:\n");
        printf("Estado: %c\n", c2.estado);
        printf("Código: %s\n", c2.codigo);
        printf("Nome da Cidade: %s\n", c2.cidade);
        printf("População: %d\n", c2.populacao);
        printf("Área: %.f km²\n", c2.area);
        printf("PIB: %.f bilhões de reais\n", c2.pib);
        printf("Número de Pontos Turísticos: %d\n", c2.pontosTuristicos);
        printf("Densidade Populacional: %.2f habitantes/km²\n",CalcDensidadePopulacional(&c2));
        printf("PIB per capita: %f reais\2n",CalcPibPerCapita(&c2));
    }

int main() {
   

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

    //Comparando as cartas e exibindo os resultados
    printf("\nComparação de Cartas:\n");
    CompPopulação(&c1, &c2);
    CompÁrea(&c1, &c2);
    CompPIB(&c1, &c2);
    CompPontoTuristico(&c1, &c2);
    CompDensidadePopulacional(&c1, &c2);
    CompPibPerCapita(&c1, &c2);
    CompSuperPoder(&c1, &c2); 

    return 0;
}