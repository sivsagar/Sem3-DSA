/*Print odd index of a array
10,20,30,40,50 and output will be odd 10 30
*/

#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int i;

    printf("Odd indexed elements: ");
    for (i = 0; i < 5; i++) {
        if (i % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\n");
    return 0;
}