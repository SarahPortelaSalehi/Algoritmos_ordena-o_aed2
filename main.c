#include <stdio.h>

void bubbleSort(int vet[], int tamanho) {
    int i, j;
    int comparacoes = 0; // Inicialize o contador de comparações
    int trocas = 0; // Contador de trocas

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            comparacoes++; // Incrementa o contador de comparações
            if (vet[j] > vet[j + 1]) {
                // Troca os elementos vet[j] e vet[j+1]
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocas++; // Incrementa o contador de trocas
            }
        }
    }

    printf("Bubble Sort fez %d comparações e %d trocas.\n", comparacoes, trocas);
}

void insertionSort(int vet[], int tamanho) {
    int i, j;
    int comparacoes = 0; // Inicialize o contador de comparações
    int trocas = 0; // Contador de trocas

    for (i = 1; i < tamanho; i++) {
        int copia = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > copia) {
            comparacoes++; // Incrementa o contador de comparações
            vet[j + 1] = vet[j];
            j--;
            trocas++; // Incrementa o contador de trocas
        }
        vet[j + 1] = copia;
    }

    printf("Insertion Sort fez %d comparações e %d trocas.\n", comparacoes, trocas);
}

void selectionSort(int vet[], int tamanho) {
    int i, j;
    int comparacoes = 0; // Inicialize o contador de comparações
    int trocas = 0; // Contador de trocas

    for (i = 0; i < tamanho - 1; i++) {
        int min_index = i;

        for (j = i + 1; j < tamanho; j++) {
            comparacoes++; // Incrementa o contador de comparações
            if (vet[j] < vet[min_index]) {
                min_index = j;
            }
        }

        // Troca o elemento mínimo encontrado com o elemento em i
        int temp = vet[i];
        vet[i] = vet[min_index];
        vet[min_index] = temp;
        trocas++; // Incrementa o contador de trocas
    }

    printf("Selection Sort fez %d comparações e %d trocas.\n", comparacoes, trocas);
}

int main() {
    int i;
    int vet[50] = {45, 5, 72, 19, 28, 2, 7, 100, 15, 33, 46, 1, 62, 11, 20, 27, 9, 104, 152, 330, 555, 3, 99, 87, 45, 10, 25, 31, 14, 68, 37, 8, 56, 22, 40, 52, 60, 42, 91, 67, 77, 51, 38, 88, 74, 69, 93, 94, 48};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    // Imprimir vetor original
    printf("Vetor original:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%4d", vet[i]);
    }

    printf("\n\n");

    // Chamar a função bubbleSort para ordenar o vetor
    bubbleSort(vet, tamanho);

    // Imprimir vetor ordenado pelo Bubble Sort
    printf("\nVetor ordenado pelo Bubble Sort:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%4d", vet[i]);
    }

    printf("\n\n");

    // Recriar o vetor original
   int vet2[50] = {45, 5, 72, 19, 28, 2, 7, 100, 15, 33, 46, 1, 62, 11, 20, 27, 9, 104, 152, 330, 555, 3, 99, 87, 45, 10, 25, 31, 14, 68, 37, 8, 56, 22, 40, 52, 60, 42, 91, 67, 77, 51, 38, 88, 74, 69, 93, 94, 48};
   
    // Chamar a função insertionSort para ordenar o vetor
    insertionSort(vet2, tamanho);

    // Imprimir vetor ordenado pelo Insertion Sort
    printf("\nVetor ordenado pelo Insertion Sort:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%4d", vet2[i]);
    }

    printf("\n\n");

    // Recriar o vetor original
    int vet3[50] = {45, 5, 72, 19, 28, 2, 7, 100, 15, 33, 46, 1, 62, 11, 20, 27, 9, 104, 152, 330, 555, 3, 99, 87, 45, 10, 25, 31, 14, 68, 37, 8, 56, 22, 40, 52, 60, 42, 91, 67, 77, 51, 38, 88, 74, 69, 93, 94, 48};
    
    // Chamar a função selectionSort para ordenar o vetor
    selectionSort(vet3, tamanho);

    // Imprimir vetor ordenado pelo Selection Sort
    printf("\nVetor ordenado pelo Selection Sort:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%4d", vet3[i]);
    }

    return 0;
}

