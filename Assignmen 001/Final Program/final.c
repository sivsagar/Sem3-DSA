#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int choice, i, sum;

    printf("Menu:\n");
    printf("1. Print all elements\n");
    printf("2. Print element at index 2\n");
    printf("3. Print odd indexed elements\n");
    printf("4. Print even indexed elements (excluding index 0)\n");
    printf("5. Print elements multiplied by 2\n");
    printf("6. Print elements with their positions\n");
    printf("7. Print negative elements\n");
    printf("8. Print elements in reverse order\n");
    printf("9. Print sum of elements\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < 5; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("%d\n", arr[2]);
            break;
        case 3:
            printf("Odd indexed elements: ");
            for (i = 0; i < 5; i++) {
                if (i % 2 != 0) {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n");
            break;
        case 4:
            printf("Even indexed elements: ");
            for (i = 0; i < 5; i++) {
                if (i % 2 == 0 && i != 0) {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n");
            break;
        case 5:
            printf("Multiplied elements: ");
            for (i = 0; i < 5; i++) {
                printf("%d ", arr[i] * 2);
            }
            printf("\n");
            break;
        case 6:
            printf("Elements and Positions: ");
            for (i = 0; i < 5; i++) {
                printf("Element: %d at Position: %d ", arr[i], i);
            }
            printf("\n");
            break;
        case 7:
            
            {
                int arr2[5] = {10, -20, 30, -40, 50};
                printf("Negative elements: ");
                for (i = 0; i < 5; i++) {
                    if (arr2[i] < 0) {
                        printf("%d ", arr2[i]);
                    }
                }
                printf("\n");
            }
            break;
        case 8:
            printf("Backward elements: ");
            for (i = 4; i >= 0; i--) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 9:
            sum = 0;
            for (i = 0; i < 5; i++) {
                sum += arr[i];
            }
            printf("SUM OF THE ELEMENTS: %d\n", sum);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
