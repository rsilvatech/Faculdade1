#include <stdio.h>
#include <stdlib.h>

    // Estrutura de Cartas
    typedef struct Carta {
        char estado;
        char codigo[4];
        char cidade[50];
        unsigned int populacao;
        unsigned int pontosTuristicos;
        float area;
        float pib;
        float densidadePopulacional;
        float pibPerCapita;
        float superPoder;
    } carta_t;

    // Primeira e segunda cartas
    carta_t c1;
    carta_t c2;

    //Inicialização da Primeira e Segunda Cartas
    carta_t c1 = {
        .estado = 'N', 
        .codigo = "000",
        .cidade = "Indefinida",
        .populacao = 10,
        .pontosTuristicos = 10,
        .area = 10.0,
        .pib = 10.0,
        .densidadePopulacional = 1.0,
        .pibPerCapita = 1.0,
        .superPoder = 1.0
    };

    carta_t c2 = {
        .estado = 'N',
        .codigo = "000",
        .cidade = "Indefinida",
        .populacao = 10,
        .pontosTuristicos = 10,
        .area = 10.0,
        .pib = 10.0,
        .densidadePopulacional = 1.0,
        .pibPerCapita = 1.0,
        .superPoder = 1.0
    };


    //Função para calcular Densidade Populacional;
    float CalcDensidadePopulacional(carta_t *c) {
        float densidadePopulacional = ((float)c->populacao / c->area);
        return c->densidadePopulacional;
    }

    //Função para calcular PIB per capita;
    float CalcPibPerCapita(carta_t *c) {
        float pibPerCapital = c->pib / (float)c->populacao;
        return c->pibPerCapita;
    }

    //Função para calcular "superpoder" da carta
    float CalcSuperPoder (carta_t *c) {
        float superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + CalcPibPerCapita(c) + (1 / CalcDensidadePopulacional(c));
        return c->superPoder;
    }

    //Funções de comparação de atributos entre cartas (linhas 59-156)
    int CompPopulação(carta_t *c1, carta_t *c2) {
        float pop_f = ((float)c1->populacao)/((float)c2->populacao);
        if (pop_f > 1) {
            printf("\nCarta 1 - %s: %d\n", c1->cidade, c1->populacao);
            printf("Carta 2 - %s: %d\n", c2->cidade, c2->populacao);
            printf("Resultado: Carta 1 - Venceu \n");
        } else if(pop_f == 1) {
            printf("\nCarta 1 - %s: %d\n", c1->cidade, c1->populacao);
            printf("Carta 2 - %s: %d\n", c2->cidade, c2->populacao);
            printf("Resultado: Empate! \n");
        } else if((0 <pop_f)&&(pop_f < 1)) {
            printf("\nCarta 1 - %s: %d\n", c1->cidade, c1->populacao);
            printf("Carta 2 - %s: %d\n", c2->cidade, c2->populacao);
            printf("Resultado: Carta 2 (%s) venceu \n", c2->cidade);
        } else {
            return 0;
        }
    }

    float CompÁrea(carta_t *c1, carta_t *c2) {
        float area_f = (c1->area)/(c2->area);
        if (area_f > 1) {
            printf("\nCarta 1 - %s: %.f km²\n", c1->cidade, c1->area);
            printf("Carta 2 - %s: %.f km²\n", c2->cidade, c2->area);
            printf("Resultado: Carta 1 (%s) venceu\n", c1->cidade);
        } else if(area_f == 1) {
            printf("\nCarta 1 - %s: %.f km²\n", c1->cidade, c1->area);
            printf("Carta 2 - %s: %.f km²\n", c2->cidade, c2->area);
            printf("Resultado: Empate! \n");
        } else if((0 <area_f)&&(area_f < 1)) {
            printf("\nCarta 1 - %s: %.f km²\n", c1->cidade, c1->area);
            printf("Carta 2 - %s: %.f km²\n", c2->cidade, c2->area);
            printf("Resultado: Carta 2 (%s) venceu \n", c2->cidade);
        } else {
            return 0;
        }
    }

    float CompPIB(carta_t *c1, carta_t *c2) {
        float pib_f = (c1->pib)/(c2->pib);
        if (pib_f > 1) {
            printf("\nCarta 1 - %s: %f \n", c1->cidade, c1->pib);
            printf("Carta 2 - %s: %f \n", c2->cidade, c2->pib);
            printf("Resultado: Carta 1 - %s venceu! \n", c1->cidade);
        } else if(pib_f == 1) {
            printf("\nCarta 1 - %s: %f \n", c1->cidade, c1->pib);
            printf("Carta 2 - %s: %f \n", c2->cidade, c2->pib);
            printf("Resultado: Empate! \n");
        } else if((0 <pib_f)&&(pib_f< 1)) {
            printf("\nCarta 1 - %s: %f \n", c1->cidade, c1->pib);
            printf("Carta 2 - %s: %f \n", c2->cidade, c2->pib);
            printf("Resultado: Carta 2 - %s venceu! \n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompPontoTuristico(carta_t *c1, carta_t *c2) {
        float ponTurist_f = ((float)c1->pontosTuristicos)/((float)c2->pontosTuristicos);
        if (ponTurist_f > 1) {
            printf("\nCarta 1 - %s: %d\n",c1->cidade, c1->pontosTuristicos);
            printf("Carta 2 - %s: %d\n",c2->cidade, c2->pontosTuristicos);
            printf("Resultado: Carta 1 (%s) venceu! \n", c1->cidade);
        } else if(ponTurist_f == 1) {
            printf("\nCarta 1 - %s: %d\n",c1->cidade, c1->pontosTuristicos);
            printf("Carta 2 - %s: %d\n",c2->cidade, c2->pontosTuristicos);
            printf("Resultado: Empate! \n");
        } else if((0 <ponTurist_f)&&(ponTurist_f < 1)) {
            printf("\nCarta 1 - %s: %d\n",c1->cidade, c1->pontosTuristicos);
            printf("Carta 2 - %s: %d\n",c2->cidade, c2->pontosTuristicos);
            printf("Resultado: Carta 2 - (%s) venceu! \n", c2->cidade);
        } else {
            return 0;
        }
    }

    float CompDensidadePopulacional(carta_t *c1, carta_t *c2) { 
        float densPop_f = CalcDensidadePopulacional(c1) / CalcDensidadePopulacional(c2);
        if (densPop_f > 1) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->densidadePopulacional);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->densidadePopulacional);
            printf("Resultado: Carta 1 (%s) venceu \n", c1->cidade);
        } else if(densPop_f == 1) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->densidadePopulacional);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->densidadePopulacional);
            printf("Resultado: Empate! \n");
        } else if((0 <densPop_f)&&(densPop_f < 1)) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->densidadePopulacional);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->densidadePopulacional);
            printf("Resultado: Carta 2 (%s) venceu\n", c2->cidade);
        } else {
            return 0;
        }
    }

    float CompPibPerCapita(carta_t *c1, carta_t *c2) {
        float PibPerCapita_f = CalcPibPerCapita(c1) / CalcPibPerCapita(c2);
        if (PibPerCapita_f > 1) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->pibPerCapita);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->pibPerCapita);
            printf("Resultado: Carta 1 - (%s) venceu \n", c1->cidade);
        } else if(PibPerCapita_f == 1) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->pibPerCapita);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->pibPerCapita);
            printf("Empate! \n");
        } else if((0<PibPerCapita_f)&&(PibPerCapita_f <1)) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->pibPerCapita);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->pibPerCapita);
            printf("Resultado: Carta 2 (%s) venceu  \n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompSuperPoder(carta_t *c1, carta_t *c2) {
        float superPoder_f = CalcSuperPoder(c1) / CalcSuperPoder(c2);
        if (superPoder_f > 1) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->superPoder);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->superPoder);
            printf("Resultado: Carta 1 (%s) venceu \n", c1->cidade);
        } else if(superPoder_f == 1) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->superPoder);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->superPoder);
            printf("Empate! \n");
        } else if((0< superPoder_f)&&(superPoder_f < 1)) {
            printf("\nCarta 1 - %s: %f\n", c1->cidade, c1->superPoder);
            printf("Carta 2 - %s: %f\n", c2->cidade, c2->superPoder);
            printf("Resultado: Carta 2 (%s) venceu \n", c2->cidade);
        } else {
            return 0;
        }
    }

    //Exibição da Primeira Carta
    void ExibeCarta1(carta_t c1) {
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
    void ExibeCarta2(carta_t c2) {
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

    //Comparando todos os atributos das cartas e exibindo os resultados
    float CompTodasCartas(carta_t c1, carta_t c2) {
        printf("\nComparação de Cartas:\n");
        CompPopulação(&c1, &c2);
        CompÁrea(&c1, &c2);
        CompPIB(&c1, &c2);
        CompPontoTuristico(&c1, &c2);
        CompDensidadePopulacional(&c1, &c2);
        CompPibPerCapita(&c1, &c2);
        CompSuperPoder(&c1, &c2); 
    }


    //Função de escolha aleatória do atributo para comparação
    float CompAtributoAleatorio(carta_t c1, carta_t c2) {
        const int escolha = (rand()%7)+1;
        switch (escolha) {
            case 1:
                CompPopulação(&c1, &c2);
                break;
            case 2:
                CompÁrea(&c1, &c2);
                break;
            case 3:
                CompPIB(&c1, &c2);
                break;
            case 4:
                CompPontoTuristico(&c1, &c2);
                break;
            case 5:
                CompDensidadePopulacional(&c1, &c2);
                break;
            case 6:
                CompPibPerCapita(&c1, &c2);
                break;
            case 7:
                CompSuperPoder(&c1, &c2);
                break;
        }
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


    //Leitura da Segunda Carta
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

    //Função de Escolha do atributo para comparação
    CompAtributoAleatorio(c1, c2);

    return 0;
}