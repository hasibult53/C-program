#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;

    // Start from the second element (already sorted)
    for (i = 1; i < n; i++) {
        key = arr[i]; // Element to be inserted

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert the shifted key element at its correct position
    }
}

int main() {
    int arr[100]; // Array to store elements (adjust size as needed)
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Sorting the array using insertion sort...\n");
    insertionSort(arr, n);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
