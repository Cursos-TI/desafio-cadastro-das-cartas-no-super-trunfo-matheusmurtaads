#include <stdio.h>

int main() {
    printf("Desafio Cartas Super Trunfo!\n");
    // Declaração das variáveis para armazenar os dados das oito cartas
    char estado[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char codigo[8][4] = {"A01", "B02", "C03", "D04", "E05", "F06", "G07", "H08"};
    char cidade[8][50] = {"São Paulo", "Rio de Janeiro", "Belo Horizonte", "Porto Alegre", "Salvador", "Fortaleza", "Curitiba", "Manaus"};
    unsigned long int populacao[8] = {12325000, 6748000, 2530701, 1484941, 2872347, 2686612, 1963726, 2322475};
    float area[8] = {1521.11, 1200.25, 331.40, 496.68, 692.81, 313.80, 435.03, 11401.06};
    float pib[8] = {699.28, 300.50, 104.36, 82.89, 63.92, 67.02, 96.15, 105.43};
    int pontosTuristicos[8] = {50, 30, 40, 35, 55, 45, 50, 25};
    float densidade[8], pibPerCapita[8];
    
    // Cálculo dos atributos
    for(int i = 0; i < 8; i++) {
        densidade[i] = populacao[i] / area[i];
        pibPerCapita[i] = (pib[i] * 1000000000) / populacao[i];
    }
    
    // Exibição das cartas
    for(int i = 0; i < 8; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", estado[i]);
        printf("Código: %s\n", codigo[i]);
        printf("Nome da Cidade: %s\n", cidade[i]);
        printf("População: %lu\n", populacao[i]);
        printf("Área: %.2f km²\n", area[i]);
        printf("PIB: %.2f bilhões de reais\n", pib[i]);
        printf("Número de Pontos Turísticos: %d\n", pontosTuristicos[i]);
        printf("Densidade Populacional: %.2f hab/km²\n", densidade[i]);
        printf("PIB per Capita: %.2f reais\n", pibPerCapita[i]);
    }
    
    // Escolha dos jogadores
    int escolha1, escolha2;
    printf("\nJogador 1, escolha uma carta (1-8): ");
    scanf("%d", &escolha1);
    printf("Jogador 2, escolha uma carta (1-8): ");
    scanf("%d", &escolha2);
    
    escolha1--; // Ajustando para índice do array
    escolha2--;
    
    // Comparação das cartas
    int vitoriasCarta1 = 0, vitoriasCarta2 = 0;
    
    printf("\nComparação entre Carta %d e Carta %d:\n", escolha1 + 1, escolha2 + 1);
    vitoriasCarta1 += (populacao[escolha1] > populacao[escolha2]);
    vitoriasCarta2 += (populacao[escolha1] < populacao[escolha2]);
    printf("População: Carta %d venceu\n", (populacao[escolha1] > populacao[escolha2]) ? escolha1 + 1 : escolha2 + 1);
    
    vitoriasCarta1 += (area[escolha1] > area[escolha2]);
    vitoriasCarta2 += (area[escolha1] < area[escolha2]);
    printf("Área: Carta %d venceu\n", (area[escolha1] > area[escolha2]) ? escolha1 + 1 : escolha2 + 1);
    
    vitoriasCarta1 += (pib[escolha1] > pib[escolha2]);
    vitoriasCarta2 += (pib[escolha1] < pib[escolha2]);
    printf("PIB: Carta %d venceu\n", (pib[escolha1] > pib[escolha2]) ? escolha1 + 1 : escolha2 + 1);
    
    vitoriasCarta1 += (pontosTuristicos[escolha1] > pontosTuristicos[escolha2]);
    vitoriasCarta2 += (pontosTuristicos[escolha1] < pontosTuristicos[escolha2]);
    printf("Pontos Turísticos: Carta %d venceu\n", (pontosTuristicos[escolha1] > pontosTuristicos[escolha2]) ? escolha1 + 1 : escolha2 + 1);
    
    vitoriasCarta1 += (densidade[escolha1] < densidade[escolha2]);
    vitoriasCarta2 += (densidade[escolha1] > densidade[escolha2]);
    printf("Densidade Populacional: Carta %d venceu\n", (densidade[escolha1] < densidade[escolha2]) ? escolha1 + 1 : escolha2 + 1);
    
    vitoriasCarta1 += (pibPerCapita[escolha1] > pibPerCapita[escolha2]);
    vitoriasCarta2 += (pibPerCapita[escolha1] < pibPerCapita[escolha2]);
    printf("PIB per Capita: Carta %d venceu\n", (pibPerCapita[escolha1] > pibPerCapita[escolha2]) ? escolha1 + 1 : escolha2 + 1);
    
    // Determinar a carta vencedora geral
    printf("\nResultado Final: ");
    if (vitoriasCarta1 > vitoriasCarta2) {
        printf("Carta %d venceu o duelo!\n", escolha1 + 1);
    } else if (vitoriasCarta2 > vitoriasCarta1) {
        printf("Carta %d venceu o duelo!\n", escolha2 + 1);
    } else {
        printf("O duelo terminou empatado!\n");
    }
    
    return 0;
}