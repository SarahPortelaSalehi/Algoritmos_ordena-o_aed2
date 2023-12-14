#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vet[], int tamanho) {
    int i, j;
    long long int comparacoes = 0; 
    long long int trocas = 0;
    clock_t start_time, end_time;

    start_time = clock();

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            comparacoes++; 
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocas++;
            }
        }
    }

    end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Bubble Sort fez %lld comparações e %lld trocas em %.6f segundos.\n", comparacoes, trocas, execution_time);
}

void insertionSort(int vet[], int tamanho) {
    int i, j;
    long long int comparacoes = 0; 
    long long int trocas = 0; 
    clock_t start_time, end_time;

    start_time = clock();

    for (i = 1; i < tamanho; i++) {
        int copia = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > copia) {
            comparacoes++; 
            vet[j + 1] = vet[j]; 
            j--;
            trocas++; 
        }
        vet[j + 1] = copia; 
    }

    end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Insertion Sort fez %lld comparações e %lld trocas em %.6f segundos.\n", comparacoes, trocas, execution_time);
}

void selectionSort(int vet[], int tamanho) {
    int i, j;
    long long int comparacoes = 0; 
    long long int trocas = 0; 
    clock_t start_time, end_time;

    start_time = clock();

    for (i = 0; i < tamanho - 1; i++) {
        int min_index = i;

        for (j = i + 1; j < tamanho; j++) {
            comparacoes++; 
            if (vet[j] < vet[min_index]) {
                min_index = j;
            }
        }

        int temp = vet[i];
        vet[i] = vet[min_index];
        vet[min_index] = temp;
        trocas++; 
    }

    end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Selection Sort fez %lld comparações e %lld trocas em %.6f segundos.\n", comparacoes, trocas, execution_time);
}

void imprimirVetor(int vet[], int tamanho, const char* mensagem) {
    printf("%s:\n", mensagem);
    for (int i = 0; i < tamanho; i++) {
        printf("%4d", vet[i]);
    }
    printf("\n\n");
}

void preencherVetorAleatorio(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % 1000; 
    }
}
int main() {
    srand(time(NULL)); 

    int tamanhos[] = {100, 1000, 10000, 100000};

    printf("Deseja imprimir os vetores antes e depois da execução? (1 - Sim, 0 - Não): ");
    int opcao;
    scanf("%d", &opcao);

    for (int k = 0; k < sizeof(tamanhos) / sizeof(tamanhos[0]); k++) {
        int tamanho = tamanhos[k];
        int vet[tamanho]; 

        printf("Tamanho do vetor: %d\n", tamanho);

        preencherVetorAleatorio(vet, tamanho);

        if (opcao == 1) {
            imprimirVetor(vet, tamanho, "Vetor original");
        }

        bubbleSort(vet, tamanho);
        insertionSort(vet, tamanho);
        selectionSort(vet, tamanho);

        if (opcao == 1) {
            imprimirVetor(vet, tamanho, "Vetor ordenado");
        }

        printf("\n\n");
    }

    return 0;
}