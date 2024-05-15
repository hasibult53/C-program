#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function for quicksort
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Pivot element is the last element
  int i = (low - 1); // Index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // Check if current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // Increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]); // Place pivot at its correct position
  return (i + 1);
}

// Recursive quicksort function
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[p] is now at right place
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[100]; // Array to store elements (adjust size as needed)
  int n;

  printf("Size of array: ");
  scanf("%d", &n);

  printf("Enter array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Sorting the array using quicksort...\n");
  quickSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
