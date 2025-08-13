/*Print even index of a array
10,20,30,40,50 and output will be even 20 40
*/
#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int i;
    printf("Even indexed elements: ");
    for (i = 0; i < 5; i++) {
        if (i % 2 == 0 && i != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}