#include <stdio.h>

int linear_search(int arr[], int n, int x) {
  // Loop through each element of the array
  for (int i = 0; i < n; i++) {
    // If element is found at current index
    if (arr[i] == x) {
      return i;
    }
  }

  // If element not found
  return -1;
}

int main() {
  int arr[100]; // Array to store elements (adjust size as needed)
  int n, x;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Search: ");
  scanf("%d", &x);

  int result = linear_search(arr, n, x);

  if (result == -1) {
    printf("Element %d is not present in array\n", x);
  } else {
    printf("Element %d is present at index %d\n", x, result);
  }

  return 0;
}
