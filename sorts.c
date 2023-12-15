// Bubble Sort
void bubbleSort(int vet[], int tamanho, long long int *comparacoes, long long int *trocas) {
    int i, j;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            (*comparacoes)++; 
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

// Selection Sort
void selectionSort(int vet[], int tamanho, long long int *comparacoes, long long int *trocas) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        int min_index = i;

        for (j = i + 1; j < tamanho; j++) {
            (*comparacoes)++; 
            if (vet[j] < vet[min_index]) {
                min_index = j;
            }
        }

        int temp = vet[i];
        vet[i] = vet[min_index];
        vet[min_index] = temp;
        (*trocas)++; 
    }

}

// Insertion Sort
void insertionSort(int vet[], int tamanho, long long int *comparacoes, long long int *trocas) {
    int i, j, copia;

    for (i = 1; i < tamanho; i++) {
        copia = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > copia) {
            (*comparacoes)++; 
            vet[j + 1] = vet[j];
            (*trocas)++;
            j--;
        }

        if (j + 1 != i) {
            vet[j + 1] = copia; 
            (*trocas)++; 
        } else {
            (*comparacoes)++;
        }
    }
}



// Shell Sort
void shellSort(int arr[], int n, long long int *comparacoes, long long int *trocas) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            int temp = arr[i];
            int j;
            (*comparacoes)++;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                (*comparacoes)++;
                (*trocas)++;
                arr[j] = arr[j - interval];
            }
            (*trocas)++;
            arr[j] = temp;
        }
    }
}

// Quick Sort
void quickSort(int Vetor[], int Left, int Right, long long int *comparacoes, long long int *trocas) {
    int Aux, Pivor, L, R;

    L = Left;
    R = Right;
    Pivor = Vetor[(Left + Right) / 2];

    while (L <= R) {
        while (Vetor[L] < Pivor && L < Right) {
            L++;
            (*comparacoes)++; // Incrementa o contador de comparações
        }
        while (Vetor[R] > Pivor && R > Left) {
            R--;
            (*comparacoes)++; // Incrementa o contador de comparações
        }
        if (L <= R) {
            Aux = Vetor[L];
            Vetor[L] = Vetor[R];
            Vetor[R] = Aux;
            L++;
            R--;
            (*trocas)++; // Incrementa o contador de trocas (2 trocas ocorreram)
        }
    }

    if (R > Left) {
        quickSort(Vetor, Left, R, comparacoes, trocas); // Chama recursivamente quickSort com o vetor completo
    }

    if (L < Right) {
        quickSort(Vetor, L, Right, comparacoes, trocas); // Chama recursivamente quickSort com o vetor completo
    }
}

// Heap Sort
void heapify(int arr[], int n, int i, long long int *comparacoes, long long int *trocas) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    (*comparacoes)++;
    if (left < n && arr[left] > arr[maior]) {
        maior = left;
    }

    (*comparacoes)++;
    if (right < n && arr[right] > arr[maior]) {
        maior = right;
    }

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        (*trocas)++;

        heapify(arr, n, maior, comparacoes, trocas);
    }
}

void heapSort(int arr[], int n, long long int *comparacoes, long long int *trocas) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparacoes, trocas);
    }

    for (int i = n - 1; i > 0; i--) {
        // Troca o elemento no topo do heap com o último elemento não ordenado
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*trocas)++;

        heapify(arr, i, 0, comparacoes, trocas);
    }
}


// Merge Sort
void merge(int arr[], int l, int m, int r, long long int *comparacoes, long long int *trocas) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar vetores temporarios
    int L[n1], R[n2];

    // Copiar dados para vetores temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Mesclar os vetores temporários de volta em arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (L[i] <= R[j]) {
            (*trocas)++;
            arr[k] = L[i];
            i++;
        } else {
            (*trocas)++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie os elementos restantes de L[] se houver algum
    while (i < n1) {
        (*trocas)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de R[] se houver algum
    while (j < n2) {
        (*trocas)++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, long long int *comparacoes, long long int *trocas) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Classifique a primeira e a segunda metades
        mergeSort(arr, l, m, comparacoes, trocas);
        mergeSort(arr, m + 1, r, comparacoes, trocas);

        merge(arr, l, m, r, comparacoes, trocas);
    }
}
