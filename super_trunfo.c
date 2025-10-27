
/*
TO DO;
- Corrigir entradas inválidas (ex: letras em vez de números ou maiores do que aguentam os funções)
- Melhorar a interface do usuário (ex: limpar a tela entre menus)
- Função de entrada e saida de menus
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


    /*Chamando funções que serão declaradas e descritas
     posteriormente no codigo. Serão usadas principalmente em*/

    void TerminaJogo();
    void MenuPrincipal();


    // Estrutura de Cartas
    typedef struct Carta {
        char estado;
        char codigo[4];
        char cidade[50];
        unsigned long populacao;
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

    //Função para calcular Densidade Populacional;
    float CalcDensidadePopulacional(carta_t *c) {
        if (c == NULL || c->area <= 0.0f) {
            c->densidadePopulacional = 0.0f;
        } else {
            c->densidadePopulacional = (float)c->populacao / c->area;
        }  
    return c->densidadePopulacional;
    }

    //Função para calcular PIB per capita;
    float CalcPibPerCapita(carta_t *c) {
        if (c == NULL || c->populacao == 0) {
            c->pibPerCapita = 0.0f;
        } else {
            c->pibPerCapita = c->pib / (float)c->populacao;
        }
        return c->pibPerCapita;
    }  

    //Função para calcular "superpoder" da carta
    float CalcSuperPoder (carta_t *c) {
        if (c == NULL) {
            return 0.0f;
        } else {
        float superPoder_f = c->populacao + c->area + c->pib + c->pontosTuristicos + CalcPibPerCapita(c) + (1 / CalcDensidadePopulacional(c));
        return c->superPoder = superPoder_f;
        }
    }

    //Funções de comparação de atributos entre cartas (linhas 59-156)
    int CompPopulacao(carta_t *c1, carta_t *c2) {
        printf("\nAtributo: População\n");
        if (c1->populacao > c2->populacao) {
            printf(">>Carta 1 - %s: %lu pessoas\n", c1->cidade, c1->populacao);
            printf(">>Carta 2 - %s: %lu pessoas\n", c2->cidade, c2->populacao);
            printf("Resultado: Carta 1 (%s) - Venceu \n",c1->cidade);
        } else if(c1->populacao == c2->populacao) {
            printf(">>Carta 1 - %s: %lu pessoas\n", c1->cidade, c1->populacao);
            printf(">>Carta 2 - %s: %lu pessoas\n", c2->cidade, c2->populacao);
            printf("Resultado: Empate! \n");
        } else if(c1->populacao < c2->populacao) {
            printf(">>Carta 1 - %s: %lu pessoas\n", c1->cidade, c1->populacao);
            printf(">>Carta 2 - %s: %lu pessoas\n", c2->cidade, c2->populacao);
            printf("Resultado: Carta 2 (%s) venceu \n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompArea(carta_t *c1, carta_t *c2) {
        printf("\nAtributo: Área\n");
        if (c1->area > c2->area) {
            printf(">>Carta 1 - %s: %.f km²\n", c1->cidade, c1->area);
            printf(">>Carta 2 - %s: %.f km²\n", c2->cidade, c2->area);
            printf("Resultado: Carta 1 (%s) venceu\n", c1->cidade);
        } else if(c1->area == c2->area) {
            printf(">>Carta 1 - %s: %.f km²\n", c1->cidade, c1->area);
            printf(">>Carta 2 - %s: %.f km²\n", c2->cidade, c2->area);
            printf("Resultado: Empate! \n");
        } else if(c1->area < c2->area) {
            printf(">>Carta 1 - %s: %.f km²\n", c1->cidade, c1->area);
            printf(">>Carta 2 - %s: %.f km²\n", c2->cidade, c2->area);
            printf("Resultado: Carta 2 (%s) venceu \n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompPIB(carta_t *c1, carta_t *c2) {
        printf("\nAtributo: PIB\n");
        if (c1->pib > c2->pib) {
            printf("\nAtributo: PIB");
            printf(">>Carta 1 - %s: %f reais\n", c1->cidade, c1->pib);
            printf(">>Carta 2 - %s: %f reais\n", c2->cidade, c2->pib);
            printf("Resultado: Carta 1 - %s venceu! \n", c1->cidade);
        } else if(c1->pib == c2->pib) {
            printf(">>Carta 1 - %s: %f reais\n", c1->cidade, c1->pib);
            printf(">>Carta 2 - %s: %f reais\n", c2->cidade, c2->pib);
            printf("Resultado: Empate! \n");
        } else if(c1->pib < c2->pib) {
            printf(">>Carta 1 - %s: %f reais\n", c1->cidade, c1->pib);
            printf(">>Carta 2 - %s: %f reais\n", c2->cidade, c2->pib);
            printf("Resultado: Carta 2 - %s venceu! \n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompPontoTuristico(carta_t *c1, carta_t *c2) {
        printf("\nAtributo: Número de Pontos Turísticos\n");
        if (c1->pontosTuristicos > c2->pontosTuristicos) {
            printf(">>Carta 1 - %s: %d pontos turísticos\n ",c1->cidade, c1->pontosTuristicos);
            printf(">>Carta 2 - %s: %d pontos turísticos\n",c2->cidade, c2->pontosTuristicos);
            printf("Resultado: Carta 1 (%s) venceu! \n", c1->cidade);
        } else if(c1->pontosTuristicos == c2->pontosTuristicos) {
            printf(">>Carta 1 - %s: %d pontos turísiticos\n",c1->cidade, c1->pontosTuristicos);
            printf(">>Carta 2 - %s: %d pontos turísticos\n",c2->cidade, c2->pontosTuristicos);
            printf("Resultado: Empate! \n");
        } else if(c1->pontosTuristicos < c2->pontosTuristicos) {
            printf(">>Carta 1 - %s: %d pontos turisticos\n",c1->cidade, c1->pontosTuristicos);
            printf(">>Carta 2 - %s: %d pontos turísticos\n",c2->cidade, c2->pontosTuristicos);
            printf("Resultado: Carta 2 - (%s) venceu! \n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompDensidadePopulacional(carta_t *c1, carta_t *c2) { 
        printf("\nAtributo: Densidade Populacional\n");
        if (CalcDensidadePopulacional(c1) < CalcDensidadePopulacional(c2)) {
            printf(">>Carta 1 - %s: %f pessoas/km²\n", c1->cidade, c1->densidadePopulacional);
            printf(">>Carta 2 - %s: %f pessoas/km²\n", c2->cidade, c2->densidadePopulacional);
            printf("Resultado: Carta 1 (%s) venceu \n", c1->cidade);
        } else if(CalcDensidadePopulacional(c1) == CalcDensidadePopulacional(c2)) {
            printf(">>Carta 1 - %s: %f pessoas/km²\n", c1->cidade, c1->densidadePopulacional);
            printf(">>Carta 2 - %s: %f pessoas/km²\n", c2->cidade, c2->densidadePopulacional);
            printf("Resultado: Empate! \n");
        } else if(CalcDensidadePopulacional(c1) > CalcDensidadePopulacional(c2)) {
            printf(">>Carta 1 - %s: %f pessoas/km²\n", c1->cidade, c1->densidadePopulacional);
            printf(">>Carta 2 - %s: %f pessoas/km²\n", c2->cidade, c2->densidadePopulacional);
            printf("Resultado: Carta 2 (%s) venceu\n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompPibPerCapita(carta_t *c1, carta_t *c2) {
        printf("\nAtributo: PIB per capita\n");
        if (CalcPibPerCapita(c1) > CalcPibPerCapita(c2)) {
            printf(">>Carta 1 - %s: %f reais por pessoa\n", c1->cidade, c1->pibPerCapita);
            printf(">>Carta 2 - %s: %f reais por pessoa\n", c2->cidade, c2->pibPerCapita);
            printf("Resultado: Carta 1 - (%s) venceu \n", c1->cidade);
        } else if(CalcPibPerCapita(c1) == CalcPibPerCapita(c2)) {
            printf(">>Carta 1 - %s: %f reais por pessoa\n", c1->cidade, c1->pibPerCapita);
            printf(">>Carta 2 - %s: %f reais por pessoa\n", c2->cidade, c2->pibPerCapita);
            printf("Empate! \n");
        } else if(CalcPibPerCapita(c1) < CalcPibPerCapita(c2)) {
            printf(">>Carta 1 - %s: %f reais por pessoa\n", c1->cidade, c1->pibPerCapita);
            printf(">>Carta 2 - %s: %f reais por pessoa\n", c2->cidade, c2->pibPerCapita);
            printf("Resultado: Carta 2 (%s) venceu  \n", c2->cidade);
        } else {
            return 0;
        }
    }

    int CompSuperPoder(carta_t *c1, carta_t *c2) {
        printf("\nAtributo: Superpoder (soma de todos os atributos)\n");
        if (CalcSuperPoder(c1) > CalcSuperPoder(c2)) {
            printf(">>Carta 1 - %s: %f\n", c1->cidade, c1->superPoder);
            printf(">>Carta 2 - %s: %f\n", c2->cidade, c2->superPoder);
            printf("Resultado: Carta 1 (%s) venceu \n", c1->cidade);
        } else if(CalcSuperPoder(c1) == CalcSuperPoder(c2)) {
            printf(">>Carta 1 - %s: %f\n", c1->cidade, c1->superPoder);
            printf(">>Carta 2 - %s: %f\n", c2->cidade, c2->superPoder);
            printf("Empate! \n");
        } else if(CalcSuperPoder(c1) < CalcSuperPoder(c2)) {
            printf(">>Carta 1 - %s: %f\n", c1->cidade, c1->superPoder);
            printf(">>Carta 2 - %s: %f\n", c2->cidade, c2->superPoder);
            printf("Resultado: Carta 2 (%s) venceu \n", c2->cidade);
        } else {
            return 0;
        }
    }

    //Comparando todos os atributos das cartas e exibindo os resultados
    void CompTodosAtributos(carta_t c1, carta_t c2) {
        printf("\nComparando todos os atributos das Cartas:\n");
        CompPopulacao(&c1, &c2);
        CompArea(&c1, &c2);
        CompPIB(&c1, &c2);
        CompPontoTuristico(&c1, &c2);
        CompDensidadePopulacional(&c1, &c2);
        CompPibPerCapita(&c1, &c2);
        CompSuperPoder(&c1, &c2); 
    }


    //Função de escolha aleatória do atributo para comparação
    void CompAtributoAleatorio(carta_t c1, carta_t c2) {
        const int escolha = (rand()%7)+1;
        switch (escolha) {
            case 1:
                CompPopulacao(&c1, &c2);
                break;
            case 2:
                CompArea(&c1, &c2);
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
            default:
                printf("Erro na escolha do atributo para comparação.\n"); //Para possivel depuração
                break;
        }
        TerminaJogo();
    }


    //Função de escolha do atributo para comparação pelo usuário
    int num;
    void CompAtributoEscolhido(carta_t c1, carta_t c2, int num) {
        int escolha_f = num;
        switch (escolha_f) {
            case 1:
                CompPopulacao(&c1, &c2);
                break;
            case 2:
                CompArea(&c1, &c2);
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
            default:
                printf("Erro na escolha do atributo para comparação.\n"); //Para póssivel depuração
                break;
        }
        TerminaJogo();
    }
    
//Exibição da Primeira Carta
    void ExibeCarta1(carta_t c1) {
        printf("\nPrimeira Carta:\n");
        printf("Estado: %c\n", c1.estado);
        printf("Código: %s\n", c1.codigo);
        printf("Nome da Cidade: %s\n", c1.cidade);
        printf("População: %lu\n", c1.populacao);
        printf("Área: %.f km²\n", c1.area);
        printf("PIB: %.f bilhões de reais\n", c1.pib);
        printf("Número de Pontos Turísticos: %d\n", c1.pontosTuristicos);
        printf("Densidade Populacional: %.2f habitantes/km²\n",CalcDensidadePopulacional(&c1));
        printf("PIB per capita: %f reais\n",CalcPibPerCapita(&c1));
    }

    //Exibição da Segunda Carta
    void ExibeCarta2(carta_t c2) {
        printf("\nSegunda Carta:\n");
        printf("Estado: %c\n", c2.estado);
        printf("Código: %s\n", c2.codigo);
        printf("Nome da Cidade: %s\n", c2.cidade);
        printf("População: %lu\n", c2.populacao);
        printf("Área: %.f km²\n", c2.area);
        printf("PIB: %.f bilhões de reais\n", c2.pib);
        printf("Número de Pontos Turísticos: %d\n", c2.pontosTuristicos);
        printf("Densidade Populacional: %.2f habitantes/km²\n",CalcDensidadePopulacional(&c2));
        printf("PIB per capita: %f reais\n",CalcPibPerCapita(&c2));
    }


    static void LimpaDataBuffer() {
        int num;
        while ((num = getchar()) != '\n' && num != EOF);
    }

    static void LimpaTerminal() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    //Função para exibir as regras do jogo
    void MenuRegrasJogo() {
        char escolha_f;
        while(1) {
            printf("\nRegras do Jogo Super Trunfo:\n");
            printf("1. Cada jogador possui uma carta com atributos diferentes.\n");
            printf("2. Os jogadores escolhem um atributo para comparar.\n");
            printf("3. O jogador com o maior valor no atributo escolhido vence a rodada.\n");
            printf("4. Em caso de empate, nenhuma carta vence.\n");
            printf("5. O jogo pode ser jogado em várias rodadas, acumulando pontos.\n");
            printf("6. Divirta-se e boa sorte!\n");
            printf("\n Voltar para o menu?(s/n)\n");
            scanf(" %c", &escolha_f);
            if (escolha_f == 'S' || escolha_f == 's' ) {
                LimpaTerminal();
                MenuPrincipal();
                break;
            } else if (escolha_f == 'N' || escolha_f =='n') {
                exit(0);
                break;
            } else {
                LimpaDataBuffer();
                printf("\nOpção invalida. Tente novamente\n");
                continue;
            }
        }
     }

  void MenuExibeTodasCartas(carta_t c1, carta_t c2) {
        char escolha_f;
        while (1) {
            ExibeCarta1(c1);
            ExibeCarta2(c2);
            printf("\n Voltar para o menu?(s/n)\n");
            scanf(" %c", &escolha_f);
            if (escolha_f == 'S' || escolha_f == 's' ) {
                LimpaTerminal();
                MenuPrincipal();
                break;
            } else if (escolha_f == 'N' || escolha_f =='n') {
                exit(0);
                break;
            } else {
                LimpaDataBuffer();
                printf("\nOpção invalida. Tente novamente\n");
                continue;
            }
        }
     }


    //Função para exibir o menu de escolha de atributo -> Á fazer
    void MenuEscolhaUmAtributo(const carta_t c1, const carta_t c2) {
        int escolha = 0;
        while (1) {
            printf("\nEscolha o atributo para comparação:\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Número de Pontos Turísticos\n");
            printf("5. Densidade Populacional\n");
            printf("6. PIB per capita\n");
            printf("7. Superpoder\n");
            printf("Digite o número correspondente ao atributo escolhido: ");
            scanf("%d", &escolha);
            if (escolha < 1 || escolha > 7) {
                printf("Opção inválida. Tente novamente.\n");
                LimpaDataBuffer();
                continue;
            }
            if (escolha >= 1 && escolha <= 7) {
                CompAtributoEscolhido(c1, c2, escolha);
            }
        break;
        }
    }

    //Menu de inicio de jogo. Usuario escolhe entre atributos aleatorios ou escolhidos
    void MenuInicioJogo() {
        int modo = 0;
        while(1){
            printf("\nEscolha o modo de jogo:\n");
            printf("1. Escolha 1 Atributo\n");
            printf("2. Escolha 2 Atributos");
            printf("3. Atributo Aleatório\n");
            printf("4. Comparar Todos os Atributos\n");
            printf("5. Exibir Cartas\n");
            scanf("%d", &modo);
            if (modo < 1 || modo > 5) {
                printf("Entrada inválida. Por favor, insira um número.\n");
                LimpaDataBuffer();
                continue;
            }
            if (modo >= 1 && modo <= 4) {
                switch (modo) {
                    case 1:
                        MenuEscolhaUmAtributo(c1, c2);
                        break;
                    case 2:
                        CompAtributoAleatorio(c1, c2);
                        break;
                    case 3:
                        CompTodosAtributos(c1, c2);
                        break;
                    case 4:
                        MenuExibeTodasCartas(c1, c2);
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                    continue;
                }
            } break;
        
        }
    }

    //Menu Principal (Inicio, Regras e Sair)
    void MenuPrincipal() {
        int opcao = 0;
        while (1) {
            printf("\nMenu Principal\n");
            printf("1. Iniciar Jogo\n");
            printf("2. Ver Regras\n");
            printf("3. Sair\n");
            printf("Escolha uma opção: \n");
            scanf("%d", &opcao);
                if (opcao < 1 || opcao > 3) {
                    printf("Entrada inválida. Tente novamente\n");
                    LimpaDataBuffer();
                    continue;
                }
                switch (opcao) {
                    case 1: 
                        MenuInicioJogo();
                        break;
                    case 2:
                        MenuRegrasJogo();
                        break;
                    case 3:
                        printf("Saindo do jogo. Até a próxima!\n");
                        exit(0);
                        break;
                }
        break;
        }
            
    }

    void TerminaJogo() {
        char resposta_f = '0';
        LimpaDataBuffer();
        printf("\nContinuar jogo?(s/n)\n");
        while (1) {
            scanf(" %c", &resposta_f);
            if (resposta_f == 's' || resposta_f == 'S') {
                LimpaTerminal();
                MenuPrincipal();
                break;
            } else if (resposta_f == 'n' || resposta_f == 'N') {
                LimpaTerminal();
                exit(0);
                break;
            } else {
                printf("\nOpção inválida. Tente novamente\n");
                continue;
            }
        }
    }



int main() {
   
    /*Inicializando a função "rand" (Retorna um número pseudoaleatório)
    dentro de CompAtributoAleatorio (escolhe atributo aleatório para comparar) */
    srand(time(0));
    rand();

    //Leitura da Primeira Carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c1.estado);
    printf("Código da Carta (ex: A01): ");
    scanf(" %3s", c1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", c1.cidade);
    printf("População: ");
    scanf(" %lu", &c1.populacao);
    printf("Área (em km²): ");
    scanf(" %f", &c1.area);
    printf("PIB (em bilhões): ");
    scanf(" %f", &c1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf(" %d", &c1.pontosTuristicos);

    //Leitura da Segunda Carta
    printf("\nCadastro da segunda carta :\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c2.estado);
    printf("Código da Carta (ex: B02): ");
    scanf(" %3s", c2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", c2.cidade);
    printf("População: ");
    scanf(" %lu", &c2.populacao);
    printf("Área (em km²): ");
    scanf(" %f", &c2.area);
    printf("PIB (em bilhões): ");
    scanf(" %f", &c2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf(" %d", &c2.pontosTuristicos);

    //Menu Principal: Exibe a opção de iniciar o jogo, ver as regras ou sair
    MenuPrincipal();

    TerminaJogo();

    return 0;
}