#include <stdio.h>

int linear_search(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}
int main() {
  int arr[100]; 
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
