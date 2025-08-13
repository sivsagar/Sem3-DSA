/*Print the negative number of an array
i) 10, -20, 30, -40, 50 and output will be -20 -40
*/
#include <stdio.h>
int main() {
    int arr[5] = {10, -20, 30, -40, 50};
    int i;
    printf("Negative elements: ");
    for (i = 0; i < 5; i++) {
        if (arr[i] < 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
   }