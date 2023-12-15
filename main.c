#include <stdio.h>
#include "hr_time.c"
#include "sorts.c"
#include "utils.c"

int main() {
    int opcao;
    int escolha;

    printf("Quantos tamanhos de vetor deseja testar?\n 1 para {100}\n 2 para {1000}\n 3 para {10000}\n 4 para {100000}\n 5 para {100, 1000}\n 6 para {100, 1000, 10000}\n 7 para {100, 1000, 10000, 100000}\n");
    scanf("%d", &escolha);

    int tamanhos[4];

    switch (escolha) {
        case 1:
            tamanhos[0] = 100;
            break;
        case 2:
            tamanhos[0] = 1000;
            break;
        case 3:
            tamanhos[0] = 10000;
            break;
        case 4:
            tamanhos[0] = 100000;
            break;
        case 5:
            tamanhos[0] = 100;
            tamanhos[1] = 1000;
            break;
        case 6:
            tamanhos[0] = 100;
            tamanhos[1] = 1000;
            tamanhos[2] = 10000;
            break;
        case 7:
            tamanhos[0] = 100;
            tamanhos[1] = 1000;
            tamanhos[2] = 10000;
            tamanhos[3] = 100000;
            break;
        default:
            printf("Escolha inválida.\n");
            return 1;
    }

    int numTamanhos = 0;
    while (tamanhos[numTamanhos] != 0 && numTamanhos < 4) {
        numTamanhos++;
    }

    char *algoritmos[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Shell Sort", "Quick Sort", "Heap Sort", "Merge Sort"};

    printf("Deseja imprimir os vetores antes e depois da execução? (1 - Sim, 0 - Não): ");
    scanf("%d", &opcao);
    printf("\n\n");
    for (int i = 0; i < numTamanhos; i++) {
        int tamanho = tamanhos[i];
        int vetAleatorio[tamanho];
        int vetOrdenado[tamanho];
        int copiaVetorA[tamanho];
        int copiaVetorO[tamanho];

        preencherVetorAleatorio(vetAleatorio, tamanho);
        preencherVetorOrdenado(vetOrdenado, tamanho);

        if (opcao == 1) {
            printf("Vetor Aleatório\n");
            ImprimirVetor(vetAleatorio, tamanho);
            printf("Vetor Ordenado\n");
            ImprimirVetor(vetOrdenado, tamanho);
        }

        copiarVetor(vetAleatorio, copiaVetorA, tamanho);
        copiarVetor(vetOrdenado, copiaVetorO, tamanho);

        for (int j = 0; j < sizeof(algoritmos) / sizeof(algoritmos[0]); j++) {
            printf("\n");
            copiarVetor(copiaVetorA, vetAleatorio, tamanho);
            testarAlgoritmo(j + 1, vetAleatorio, tamanho, "Vetor Aleatório", opcao);
            copiarVetor(copiaVetorO, vetOrdenado, tamanho);
            testarAlgoritmo(j + 1, vetOrdenado, tamanho, "Vetor Ordenado", opcao);
        }

        printf("\n\n");
    }

    return 0;
}
