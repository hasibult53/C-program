#include <stdio.h>

void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      int temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
    }
  }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main() {
  int n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n]; 
  printf("Enter %d integers:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Unsorted array: \n");
  printArray(arr, n);
  selectionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
