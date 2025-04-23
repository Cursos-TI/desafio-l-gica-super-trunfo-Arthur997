#include <stdio.h>

int main() {
    int num_cartas;
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &num_cartas);

    char estado[num_cartas][50];
    int codigo[num_cartas];
    char cidade[num_cartas][50];
    double populacao[num_cartas];
    double PIB[num_cartas];
    double area[num_cartas];
    int pontos_turisticos[num_cartas];
    double densidade_populacional[num_cartas];
    double PIB_per_capita[num_cartas];

    // Cadastro das cartas
    for (int i = 0; i < num_cartas; i++) {
        printf("\nCadastro da Carta %d:\n", i + 1);
        printf("Estado: ");
        scanf("%s", estado[i]);
        printf("Nome da cidade: ");
        scanf("%s", cidade[i]);
        printf("Populacao: ");
        scanf("%lf", &populacao[i]);
        printf("PIB: ");
        scanf("%lf", &PIB[i]);
        printf("Area (km quadrado): ");
        scanf("%lf", &area[i]);
        printf("Numero de pontos turisticos: ");
        scanf("%d", &pontos_turisticos[i]);

        // Cálculos automáticos
        densidade_populacional[i] = populacao[i] / area[i];
        PIB_per_capita[i] = PIB[i] / populacao[i];
        codigo[i] = i; 
    }

    // Menu principal
    int opcao;
    do {
        printf("\n===== MENU SUPER TRUNFO - CIDADES =====\n");
        printf("1 - Visualizar Cartas\n");
        printf("2 - Comparar Cidades (1 atributo)\n");
        printf("3 - Comparar Cidades (2 atributos)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            for (int i = 0; i < num_cartas; i++) {
                printf("\nCarta da Cidade de: %s\n", cidade[i]);
                printf("Estado: %s\n", estado[i]);
                printf("Codigo: %d\n", codigo[i]);
                printf("Populacao: %.2f\n", populacao[i]);
                printf("PIB: %.2f\n", PIB[i]);
                printf("Area: %.2f km2\n", area[i]);
                printf("Pontos turisticos: %d\n", pontos_turisticos[i]);
                printf("Densidade populacional: %.2f hab/km2\n", densidade_populacional[i]);
                printf("PIB per capita: %.2f\n\n", PIB_per_capita[i]);
            }
        }

        else if (opcao == 2) {
            int c1, c2, atributo;
            printf("\nDigite o codigo da primeira cidade: ");
            scanf("%d", &c1);
            printf("Digite o codigo da segunda cidade: ");
            scanf("%d", &c2);

            printf("\nEscolha o atributo para comparar:\n");
            printf("1 - Populacao\n2 - PIB\n3 - Area\n4 - Pontos Turisticos\n5 - Densidade Populacional\n6 - PIB per capita\n");
            scanf("%d", &atributo);

            double valor1, valor2;
            switch (atributo) {
                case 1: valor1 = populacao[c1]; valor2 = populacao[c2]; break;
                case 2: valor1 = PIB[c1]; valor2 = PIB[c2]; break;
                case 3: valor1 = area[c1]; valor2 = area[c2]; break;
                case 4: valor1 = pontos_turisticos[c1]; valor2 = pontos_turisticos[c2]; break;
                case 5: valor1 = densidade_populacional[c1]; valor2 = densidade_populacional[c2]; break;
                case 6: valor1 = PIB_per_capita[c1]; valor2 = PIB_per_capita[c2]; break;
                default: printf("Atributo inválido!\n"); continue;
            }

            printf("\nResultado da Comparação:\n");
            if (valor1 > valor2)
                printf("%s venceu!\n", cidade[c1]);
            else if (valor2 > valor1)
                printf("%s venceu!\n", cidade[c2]);
            else
                printf("Empate!\n");
        }

        else if (opcao == 3) {
            int c1, c2, a1, a2;
            printf("\nDigite o codigo da primeira cidade: ");
            scanf("%d", &c1);
            printf("Digite o codigo da segunda cidade: ");
            scanf("%d", &c2);

            printf("\nEscolha o primeiro atributo:\n1-Populacao 2-PIB 3-Area 4-Pontos 5-Densidade 6-PIB/capita\n");
            scanf("%d", &a1);
            printf("Escolha o segundo atributo:\n1-Populacao 2-PIB 3-Area 4-Pontos 5-Densidade 6-PIB/capita\n");
            scanf("%d", &a2);

            double v1a =(a1 == 1) ? populacao[c1] : (a1 == 2) ? PIB[c1] :
                        (a1 == 3) ? area[c1] : (a1 == 4) ? pontos_turisticos[c1] :
                        (a1 == 5) ? densidade_populacional[c1] : PIB_per_capita[c1];

            double v2a =(a1 == 1) ? populacao[c2] : (a1 == 2) ? PIB[c2] :
                        (a1 == 3) ? area[c2] : (a1 == 4) ? pontos_turisticos[c2] :
                        (a1 == 5) ? densidade_populacional[c2] : PIB_per_capita[c2];

            double v1b =(a2 == 1) ? populacao[c1] : (a2 == 2) ? PIB[c1] :
                        (a2 == 3) ? area[c1] : (a2 == 4) ? pontos_turisticos[c1] :
                        (a2 == 5) ? densidade_populacional[c1] : PIB_per_capita[c1];

            double v2b =(a2 == 1) ? populacao[c2] : (a2 == 2) ? PIB[c2] :
                        (a2 == 3) ? area[c2] : (a2 == 4) ? pontos_turisticos[c2] :
                        (a2 == 5) ? densidade_populacional[c2] : PIB_per_capita[c2];

            double total1 = v1a + v1b;
            double total2 = v2a + v2b;

            printf("\nTotal %s: %.2f\n", cidade[c1], total1);
            printf("Total %s: %.2f\n", cidade[c2], total2);

            (total1 > total2) ? printf("%s venceu!\n", cidade[c1]) :
            (total2 > total1) ? printf("%s venceu!\n", cidade[c2]) :
            printf("Empate!\n");
        }

        else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
