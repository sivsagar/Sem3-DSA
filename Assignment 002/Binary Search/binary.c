#include <stdio.h>

int main() {
    int a[10], x, start = 0, end = 9, middle, i, found = 0;

    printf("Enter the elements of the array in sorted order: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    while (start <= end) {
        middle = (start + end) / 2;
        if (x < a[middle]) {
            end = middle - 1;
        } else if (x > a[middle]) {
            start = middle + 1;
        } else {
            printf("The element is found at index %d\n", middle);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}