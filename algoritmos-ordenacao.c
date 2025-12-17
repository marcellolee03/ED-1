#include <stdio.h>
#include <math.h>

// Insertion Sort
void insertion_sort(int arr[], int size) {
  for (int i = 1; i < size; i++) { 
    int pivot = arr[i];
    int j = i - 1;
    while (j>0 && pivot < arr[j-1]) {

      arr[j] = arr[j-1];

      j = j - 1;

    }
    arr[j] = pivot;
  }
}


// Selection Sort
void selection_sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i ++ ) {
    int target = arr[i];
    printf("alo");
    int smallest_index = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[smallest_index]) {
        smallest_index = j;
      }
    }

  if (smallest_index != i){
    arr[i] = arr[smallest_index];
    arr[smallest_index] = target;
    }
  }
}

// Bubble Sort
void bubble_sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i ; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}


// Shell Sort
void shell_sort(int arr[], int size){
  int gap = size/2;
  while (gap > 0){
    for (int i = gap; i < size; i++) {
      int pivot = arr[i];
      int j = i - gap;

      while (j>=0 && arr[j] > pivot){
        arr[j+gap] = arr[j];
        j = j-gap;
      }
      arr[j+gap] = pivot;
    }
    gap = gap/2;
  }
}


// Merge Sort AUX
void merge(int target[], int L1[], int n1, int L2[], int n2) { 
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (L1[i] < L2[j]) {
            target[k++] = L1[i++];
        } else {
            target[k++] = L2[j++];
        }
    }

    while (i < n1) target[k++] = L1[i++];
    while (j < n2) target[k++] = L2[j++];
}

void split(int arr[], int size) {
    if (size <= 1) return;

    int n1 = size / 2;
    int n2 = size - n1; 
    int L1[n1], L2[n2];

    for (int i = 0; i < n1; i++) L1[i] = arr[i];
    for (int i = n1, j = 0; i < size; i++, j++) L2[j] = arr[i];

    split(L1, n1);
    split(L2, n2);

    merge(arr, L1, n1, L2, n2);
}

// Merge Sort
void merge_sort(int arr[], int size) {
    split(arr, size);
}

// Quick Sort AUX
int partition(int arr[], int low, int high){
  int pivot = arr[high-1];
  int i = low, j = low;
  while (i < high) {
    if (arr[i] < pivot) {
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
      j++;
    }
    i++;
  }
  
  int temp = arr[j];
  arr[j] = arr[high-1];
  arr[high-1] = temp; 

  return j;
}

// Quick Sort
void quick_sort(int arr[], int low, int high){
  if (low < high) {
    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi);
    quick_sort(arr, pi+1, high);
  }
}

// Heap Sort AUX
void heapify(int arr[], int n, int i){
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (left < n && arr[left] > arr[largest]) largest = left;
  if (right < n && arr[right] > arr[largest]) largest = right;
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }

}

// Heap Sort
void heap_sort(int arr[], int n){
  for (int i = (n/2) - 1; i >= 0; i--) heapify(arr, n, i);
  for (int i = n-1; i > 0; i--) {
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;

    heapify(arr, i, 0);
  }
}


int main() {
  int dados[] = {38, 27, 43, 3, 9, 82, 10};
  int tam = sizeof(dados) / sizeof(dados[0]);

  heap_sort(dados, tam);
  for(int i = 0; i < tam; i++) printf("%d ", dados[i]);

  return 0;
}
