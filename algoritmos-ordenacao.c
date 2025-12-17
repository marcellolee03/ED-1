#include <stdio.h>

int main() {
  
  // Função auxiliar para printar os array
  void print_list(int arr[], int size) {
    for (int i = 0; i < size; i++) {
      printf("%d\n", arr[i]);
    }
  }

  // Insertion Sort
  void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) { 
      int pivot = arr[i];
      int j = i - 1;

      while (j>=0 && pivot < arr[j]) {
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = pivot;
    }
  }

  // Selection Sort
  void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i ++ ) {
      int target = arr[i];
      int smallest_index = i;
      for (int j = i + 1; j < size; j++) {
        if (arr[j] < arr[smallest_index]) {
          smallest_index = j;
        }
      }
      if (smallest_index != i) {
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

  int test[5] = {50, 40, 30, 20, 10};
  int henrique[10] = {12, 42, 83, 25, 67, 71, 3, 4, 94, 53};
  bubble_sort(henrique, 10);
  print_list(henrique, 10);
  return 0;
}
