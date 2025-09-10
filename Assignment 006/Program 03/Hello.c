/* 
WAP in C to perform bubble sort using a function where the comparison
function will be passed using a function pointer where the function
of comparison will return 1 for swap & -1 for no swap (give the sample out put also)
*/

#include <stdio.h>

// Comparison function for ascending order
int ascending(int a, int b) {
    if (a > b) return 1;  // swap needed
    return -1;            // no swap
}

// Comparison function for descending order
int descending(int a, int b) {
    if (a < b) return 1;  // swap needed
    return -1;            // no swap
}

// Bubble sort function using function pointer
void bubbleSort(int arr[], int n, int (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) == 1) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    // Sort in ascending order
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr1, n, ascending);
    printf("Ascending order: ");
    printArray(arr1, n);
    
    // Sort in descending order
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr2, n, descending);
    printf("Descending order: ");
    printArray(arr2, n);
    
    return 0;
}

/*OUTPUT
Original array: 64 34 25 12 22 11 90 
Ascending order: 11 12 22 25 34 64 90 
Descending order: 90 64 34 25 22 12 11 */