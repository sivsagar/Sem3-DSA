/*[5 , 2 , 10 , 7 , 9 , 3 , 4 , 1]
Q2) Take the same array and apply quick sort  try to find the element 8 in the  sorted array using 
optimal method if not found insert the element in its proper position in the sorted array*/
#include <stdio.h>

// Function to swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot
    int i = (low - 1);       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Binary Search function
int binarySearch(int arr[], int size, int key, int *pos) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return 1; // Found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    *pos = low; // Insertion point
    return 0; // Not found
}

// Insert key into correct position
void insertInSortedArray(int arr[], int *size, int key, int pos) {
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = key;
    (*size)++;
}

int main() {
    int arr[100] = {5, 2, 10, 7, 9, 3, 4, 1}; // Original array
    int size = 8;

    // Step 1: Sort the array using Quick Sort
    quickSort(arr, 0, size - 1);

    // Display the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Step 2: Search for 8 using Binary Search
    int key = 8, pos;
    if (binarySearch(arr, size, key, &pos)) {
        printf("Element %d found at index %d.\n", key, pos);
    } else {
        printf("Element %d not found. \n Inserting at correct position...\n", key);
        insertInSortedArray(arr, &size, key, pos);

        // Display the new array after insertion
        printf("New Array after Insertion: ");
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}
