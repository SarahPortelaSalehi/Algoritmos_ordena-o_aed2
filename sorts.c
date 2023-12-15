// Bubble Sort
void bubbleSort(int vet[], int tamanho, long long int *comparacoes, long long int *trocas) {
    int i, j;

    // loop externo percorre todo o array.
    for (i = 0; i < tamanho - 1; i++) {
        // loop interno percorre até o último elemento não ordenado.
        for (j = 0; j < tamanho - 1 - i; j++) {
            (*comparacoes)++; 
            // verifica se o elemento atual é maior que o próximo.
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
    // loop externo percorre todo o array.
    for (i = 0; i < tamanho - 1; i++) {
        // loop interno encontra o índice do menor elemento na parte não ordenada.
        int min_index = i;
        for (j = i + 1; j < tamanho; j++) {
            (*comparacoes)++; 
            if (vet[j] < vet[min_index]) {
                min_index = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado.
        if (min_index != i) {
            int temp = vet[i];
            vet[i] = vet[min_index];
            vet[min_index] = temp;
            (*trocas)++;
        }
    }
}

// Insertion Sort
void insertionSort(int vet[], int tamanho, long long int *comparacoes, long long int *trocas) {
    int i, j, copia;

    // Loop externo percorre todo o array
    for (i = 1; i < tamanho; i++) {
        copia = vet[i]; // Elemento a ser inserido na parte ordenada
        j = i - 1;

        // Loop interno encontra a posição correta para o elemento a ser inserido
        while (j >= 0 && vet[j] > copia) {
            (*comparacoes)++; // Contabiliza a comparação
            vet[j + 1] = vet[j]; // Move elementos maiores para a direita
            (*trocas)++; // Contabiliza a troca
            j--;
        }

        // Insere o elemento na posição correta
        if (j + 1 != i) {
            vet[j + 1] = copia; 
            (*trocas)++; // Contabiliza a troca
        } else {
            (*comparacoes)++; // Contabiliza a comparação (caso especial)
        }
    }
}

// Shell Sort
void shellSort(int vet[], int tamanho, long long *comparacoes, long long *trocas) {
    int i, j, increment, temp;

    increment = 3;
    // O loop externo controla o tamanho das lacunas.
    while (increment > 0) {
        // O loop interno itera pelo array.
        for (i = 0; i < tamanho; i++) {
            j = i;
            temp = vet[i];
            // O loop while interno move os elementos para frente até encontrar a posição correta.
            while (j >= increment) {
                (*comparacoes)++; // incrementa o contador de comparações
                if (vet[j - increment] > temp) {
                    (*trocas)++;
                    vet[j] = vet[j - increment];
                    j = j - increment;
                } else {
                    break; // Sai do loop quando a posição correta é encontrada
                }
            }
            // Insere o elemento na posição correta após as movimentações.
            if (j != i) {
                vet[j] = temp;
                (*trocas)++;
            }
        }
        if (increment / 2 != 0)
            increment = increment / 2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
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
void merge(int arr[], int l, int m, int r, long long int *comparacoes, long long int *trocas)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar vetores temporarios
    int L[n1], R[n2];

    // Copiar dados para vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os vetores temporários de volta em arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*trocas)++;
        }
        k++;
    }

    // Copie os elementos restantes de L[] se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*trocas)++;
    }

    // Copie os elementos restantes de R[] se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*trocas)++;
    }
}

// l é para o índice esquerdo e r é o índice direito do subvetor a ser ordenado
void mergeSort(int arr[], int l, int r, long long int *comparacoes, long long int *trocas)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Classifique a primeira e a segunda metades
        mergeSort(arr, l, m, comparacoes, trocas);
        mergeSort(arr, m + 1, r, comparacoes, trocas);

        merge(arr, l, m, r, comparacoes, trocas);
    }
}
