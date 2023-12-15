#include "utils.h"

void ImprimirVetor(int vet[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

void preencherVetorAleatorio(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % 1000; 
    }
}

void preencherVetorOrdenado(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = i + 1;
    }
}

// Função para copiar um vetor para outro
void copiarVetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Função para imprimir estatísticas
void imprimirEstatisticas(int algoritmo, int tamanho, const char *tipoVetor, long long int comparacoes, long long int trocas, double tempo) {
    printf("%s - %s - Tamanho: %d - Comparações: %lld - Movimentações: %lld - Tempo: %f segundos\n",
           algoritmoNome(algoritmo), tipoVetor, tamanho, comparacoes, trocas, tempo);
}

const char *algoritmoNome(int indice) {
    const char *algoritmos[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Shell Sort", "Quick Sort", "Heap Sort", "Merge Sort"};
    return algoritmos[indice - 1];
}

void testarAlgoritmo(int algoritmo, int vet[], int tamanho, const char *tipoVetor, int imprimir) {
    stopWatch timer;
    double elapsedTime;
    long long int comparacoes = 0;
    long long int trocas = 0;

    // Chama a função de ordenação apropriada
    switch (algoritmo) {
        case 1:
            // Inicia o cronômetro
            startTimer(&timer);
            bubbleSort(vet, tamanho, &comparacoes, &trocas);
            // Para o cronômetro
            stopTimer(&timer);
            break;
        case 2:
            startTimer(&timer);
            selectionSort(vet, tamanho, &comparacoes, &trocas);
            stopTimer(&timer);
            break;
        case 3:
            startTimer(&timer);
            insertionSort(vet, tamanho, &comparacoes, &trocas);
            stopTimer(&timer);
            break;
        case 4:
            startTimer(&timer);
            shellSort(vet, tamanho, &comparacoes, &trocas);
            stopTimer(&timer);
            break;
        case 5:
            startTimer(&timer);
            quickSort(vet, 0, tamanho - 1, &comparacoes, &trocas);
            stopTimer(&timer);
            break;
        case 6:
            startTimer(&timer);
            heapSort(vet, tamanho, &comparacoes, &trocas);
            stopTimer(&timer);
            break;
        case 7:
            startTimer(&timer);
            mergeSort(vet, 0, tamanho - 1, &comparacoes, &trocas);
            stopTimer(&timer);
            break;
        default:
            printf("Algoritmo inválido.\n");
            return;
    }

    elapsedTime = getElapsedTime(&timer);

    // Aqui você pode imprimir as estatísticas
    imprimirEstatisticas(algoritmo, tamanho, tipoVetor, comparacoes, trocas, elapsedTime);

    if (imprimir) ImprimirVetor(vet, tamanho);
}
