#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insertion Sort
void insertion_sort(int arr[], int size) {
  int testes = 0;
  int trocas = 0;

  for (int i = 1; i < size; i++) { 
    int pivot = arr[i];
    int j = i - 1;
    while (j>0 && pivot < arr[j-1]) {
      testes++;
      arr[j] = arr[j-1];
      trocas++;
      j = j - 1;
    }
    if (j > 0) testes++;
    arr[j] = pivot;
    trocas++;
  }
  printf("Testes: %d, Trocas: %d\n", testes, trocas);
}


// Selection Sort
void selection_sort(int arr[], int size) {
  int testes = 0;
  int trocas = 0;

  for (int i = 0; i < size - 1; i ++ ) {
    int target = arr[i];
    int smallest_index = i;
    for (int j = i + 1; j < size; j++) {
      testes++;
      if (arr[j] < arr[smallest_index]) {
        smallest_index = j;
      }
    }

  if (smallest_index != i){
    arr[i] = arr[smallest_index];
    arr[smallest_index] = target;
    trocas++;
    }
  }
  printf("Testes: %d, Trocas: %d\n", testes, trocas);
}

// Bubble Sort
void bubble_sort(int arr[], int size) {
  int testes = 0;
  int trocas = 0;

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i ; j++) {
      testes++;
      if (arr[j] > arr[j+1]) {
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        trocas++;
      }
    }
  }
  printf("Testes: %d, Trocas: %d\n", testes, trocas);
}


// Shell Sort
void shell_sort(int arr[], int size){
  int testes = 0;
  int trocas = 0;
  int gap = size/2;
  while (gap > 0){
    for (int i = gap; i < size; i++) {
      int pivot = arr[i];
      int j = i - gap;

      while (j>=0 && arr[j] > pivot){
        testes++;
        arr[j+gap] = arr[j];
        trocas++;
        j = j-gap;
      }
      if (j >= 0) testes++;
      arr[j+gap] = pivot;
      trocas++;
    }
    gap = gap/2;
  }
  printf("Testes: %d, Trocas: %d\n", testes, trocas);
}


// Merge Sort AUX
void merge(int target[], int L1[], int n1, int L2[], int n2, int *testes, int *trocas) { 
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        (*testes)++;
        if (L1[i] < L2[j]) {
            target[k++] = L1[i++];
        } else {
            target[k++] = L2[j++];
        }
        (*trocas)++;
    }

    while (i < n1) {
        target[k++] = L1[i++];
        (*trocas)++;
    }
    while (j < n2) {
        target[k++] = L2[j++];
        (*trocas)++;
    }
}

void split(int arr[], int size, int *testes, int *trocas) {
    if (size <= 1) return;

    int n1 = size / 2;
    int n2 = size - n1; 
    int L1[n1], L2[n2];

    for (int i = 0; i < n1; i++) {
        L1[i] = arr[i];
        (*trocas)++;
    }
    for (int i = n1, j = 0; i < size; i++, j++) {
        L2[j] = arr[i];
        (*trocas)++;
    }

    split(L1, n1, testes, trocas);
    split(L2, n2, testes, trocas);

    merge(arr, L1, n1, L2, n2, testes, trocas);
}

// Merge Sort
void merge_sort(int arr[], int size) {
    int testes = 0;
    int trocas = 0;
    split(arr, size, &testes, &trocas);
    printf("Testes: %d, Trocas: %d\n", testes, trocas);
}


// Quick Sort AUX
int partition(int arr[], int low, int high, int *testes, int *trocas){
  int pivot = arr[high-1];
  int i = low, j = low;
  while (i < high) {
    (*testes)++;
    if (arr[i] < pivot) {
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
      (*trocas)++;
      j++;
    }
    i++;
  }
  
  int temp = arr[j];
  arr[j] = arr[high-1];
  arr[high-1] = temp; 
  (*trocas)++;

  return j;
}

// Quick Sort Recursivo (Auxiliar)
void quick_sort_helper(int arr[], int low, int high, int *testes, int *trocas){
  if (low < high) {
    int pi = partition(arr, low, high, testes, trocas);

    quick_sort_helper(arr, low, pi, testes, trocas);
    quick_sort_helper(arr, pi+1, high, testes, trocas);
  }
}

// Quick Sort Principal
void quick_sort(int arr[], int low, int high){
  int testes = 0;
  int trocas = 0;
  quick_sort_helper(arr, low, high, &testes, &trocas);
  printf("Testes: %d, Trocas: %d\n", testes, trocas);
}


// Heap Sort AUX
void heapify(int arr[], int n, int i, int *testes, int *trocas){
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  // Verificação separada para contar o teste apenas se o filho existir
  if (left < n) {
    (*testes)++;
    if (arr[left] > arr[largest]) largest = left;
  }
  
  if (right < n) {
    (*testes)++;
    if (arr[right] > arr[largest]) largest = right;
  }

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    (*trocas)++;
    heapify(arr, n, largest, testes, trocas);
  }
}

// Heap Sort
void heap_sort(int arr[], int n){
  int testes = 0;
  int trocas = 0;

  for (int i = (n/2) - 1; i >= 0; i--) heapify(arr, n, i, &testes, &trocas);
  for (int i = n-1; i > 0; i--) {
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    trocas++;

    heapify(arr, i, 0, &testes, &trocas);
  }
  printf("Testes: %d, Trocas: %d\n", testes, trocas);
}


// Counting Sort
void counting_sort(int arr[], int size){
  int testes = 0;
  int trocas = 0;
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    testes++;
    if (arr[i] > max){
      max = arr[i];
    }
  }
  
  int *count = calloc(max+1, sizeof(int));
  for (int i = 0; i < size; i++) count[arr[i]] ++;
  
  int j = 0;
  for(int i = 0; i < max+1; i ++ ) {
    while (count[i] > 0) {
      arr[j] = i;
      trocas++;
      count[i]--;
      j++;
    }
  } 
  free(count);
  printf("Testes: %d, Trocas: %d\n", testes, trocas);
}

// Função auxiliar para imprimir o array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int dados_originais[10][10] = {
        {12, 42, 83, 25, 67, 71, 3, 4, 94, 53},
        {100, 48, 19, 61, 86, 33, 13, 43, 84, 28},
        {81, 60, 6, 49, 40, 41, 38, 64, 44, 36},
        {45, 27, 11, 89, 63, 39, 9, 58, 52, 17},
        {88, 77, 26, 62, 30, 96, 56, 65, 98, 99},
        {76, 73, 16, 95, 35, 87, 68, 69, 51, 92},
        {37, 75, 90, 82, 8, 18, 23, 93, 57, 10},
        {15, 97, 14, 29, 7, 24, 31, 59, 78, 85},
        {5, 70, 55, 91, 47, 72, 2, 20, 34, 74},
        {50, 66, 32, 22, 54, 79, 21, 1, 80, 46}
    };

    int linhas = 10;
    int colunas = 10;
    int buffer[10];

    printf("\n=== INSERTION SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        insertion_sort(buffer, colunas);
        print_array(buffer, colunas);
    }

    printf("\n=== SELECTION SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        selection_sort(buffer, colunas);
        print_array(buffer, colunas);
    }

    printf("\n=== BUBBLE SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        bubble_sort(buffer, colunas);
        print_array(buffer, colunas);
    }

    printf("\n=== SHELL SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        shell_sort(buffer, colunas);
        print_array(buffer, colunas);
    }

    printf("\n=== MERGE SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        merge_sort(buffer, colunas);
        print_array(buffer, colunas);
    }

    printf("\n=== QUICK SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        quick_sort(buffer, 0, colunas - 1);
        print_array(buffer, colunas);
    }

    printf("\n=== HEAP SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        heap_sort(buffer, colunas);
        print_array(buffer, colunas);
    }

    printf("\n=== COUNTING SORT ===\n");
    for (int i = 0; i < linhas; i++) {
        memcpy(buffer, dados_originais[i], colunas * sizeof(int));
        printf("Lista %d -> ", i + 1);
        counting_sort(buffer, colunas);
        print_array(buffer, colunas);
    }

    return 0;
}
