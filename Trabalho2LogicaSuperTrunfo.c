#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para imprimir as opções de atributos
void exibirAtributos() {
    printf("\nEscolha um atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área (em km²)\n");
    printf("3. PIB (em bilhões de reais)\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional (hab/km²)\n");
    printf("6. PIB per Capita (em reais)\n");
}

// Função para comparar os atributos escolhidos
float compararAtributos(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    float valor1 = 0, valor2 = 0;

    // Comparar o primeiro atributo
    switch (atributo1) {
        case 1: valor1 = carta1.populacao; break;
        case 2: valor1 = carta1.area; break;
        case 3: valor1 = carta1.pib; break;
        case 4: valor1 = carta1.pontosTuristicos; break;
        case 5: valor1 = carta1.densidadePopulacional; break;
        case 6: valor1 = carta1.pibPerCapita; break;
        default: break;
    }

    // Comparar o segundo atributo
    switch (atributo2) {
        case 1: valor2 = carta2.populacao; break;
        case 2: valor2 = carta2.area; break;
        case 3: valor2 = carta2.pib; break;
        case 4: valor2 = carta2.pontosTuristicos; break;
        case 5: valor2 = carta2.densidadePopulacional; break;
        case 6: valor2 = carta2.pibPerCapita; break;
        default: break;
    }

    // Se o atributo for densidade populacional, inverte a comparação
    if (atributo1 == 5 || atributo2 == 5) {
        // Menor valor de densidade populacional vence
        return (valor1 < valor2) ? valor1 : valor2;
    } else {
        // Maior valor vence
        return (valor1 > valor2) ? valor1 : valor2;
    }
}

// Função para exibir a carta escolhida
void exibirCarta(Carta carta) {
    printf("\nCidade: %s\n", carta.nomeCidade);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

int main() {
    // Definindo as cartas
    Carta cartas[8] = {
        {"A", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50, 8102.47, 56724.32},
        {"B", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30, 5622.24, 44532.91},
        {"C", "C03", "Belo Horizonte", 2530701, 331.40, 104.36, 40, 7638.13, 41249.56},
        {"D", "D04", "Porto Alegre", 1484941, 496.68, 82.89, 35, 2989.37, 55800.02},
        {"E", "E05", "Salvador", 2872347, 692.81, 63.92, 55, 4147.75, 22253.49},
        {"F", "F06", "Fortaleza", 2686612, 313.80, 67.02, 45, 8559.46, 24951.87},
        {"G", "G07", "Curitiba", 1963726, 435.03, 96.15, 50, 4514.79, 48972.86},
        {"H", "H08", "Manaus", 2322475, 11401.06, 105.43, 25, 203.71, 45399.83}
    };

    int escolhaJogador1, escolhaJogador2;
    int atributo1, atributo2;
    float somaJogador1, somaJogador2;

    printf("Desafio Lógica Super Trunfo!\n");

    // Jogador 1 escolhe a carta
    printf("\nJogador 1, escolha sua carta (1 a 8): ");
    scanf("%d", &escolhaJogador1);
    exibirCarta(cartas[escolhaJogador1 - 1]);

    // Jogador 2 escolhe a carta
    printf("\nJogador 2, escolha sua carta (1 a 8): ");
    scanf("%d", &escolhaJogador2);
    exibirCarta(cartas[escolhaJogador2 - 1]);

    // Exibir as opções de atributos
    exibirAtributos();
    
    // Jogador 1 escolhe os atributos
    printf("\nJogador 1, escolha o primeiro atributo (1-6): ");
    scanf("%d", &atributo1);
    printf("Jogador 1, escolha o segundo atributo (1-6): ");
    scanf("%d", &atributo2);

    // Jogador 2 escolhe os atributos
    printf("\nJogador 2, escolha o primeiro atributo (1-6): ");
    scanf("%d", &atributo1);
    printf("Jogador 2, escolha o segundo atributo (1-6): ");
    scanf("%d", &atributo2);

    // Comparar os atributos
    somaJogador1 = compararAtributos(cartas[escolhaJogador1 - 1], cartas[escolhaJogador2 - 1], atributo1, atributo2);
    somaJogador2 = compararAtributos(cartas[escolhaJogador2 - 1], cartas[escolhaJogador1 - 1], atributo1, atributo2);

    // Exibir quem venceu
    if (somaJogador1 > somaJogador2)
        printf("\nJogador 1 venceu com a soma de %.2f!\n", somaJogador1);
    else if (somaJogador2 > somaJogador1)
        printf("\nJogador 2 venceu com a soma de %.2f!\n", somaJogador2);
    else
        printf("\nEmpate!\n");

    return 0;
}