#include <stdio.h>

int binary_search(int arr[], int left, int right, int x) {
  if (left > right) {
    return -1;
  }

  int mid = left + (right - left) / 2;

  if (arr[mid] == x) {
    return mid;
  }
  if (arr[mid] < x) {
    return binary_search(arr, mid + 1, right, x);
  }
  return binary_search(arr, left, mid - 1, x);
}
int main() {
  int arr[100];
  int n, x;
  printf("Sorted array size: ");
  scanf("%d", &n);
  printf("Enter sorted array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Search: ");
  scanf("%d", &x);
  int result = binary_search(arr, 0, n - 1, x);
  if (result == -1) {
    printf("Element %d is not present in array\n", x);
  } else {
    printf("Element %d is present at index %d\n", x, result);
  }
  return 0;
}
