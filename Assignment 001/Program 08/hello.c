/*Print backward elements of a given array
 10,20,30,40,50 and output will be 50 40 30 20 10
*/
#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int i;

    printf("Backward elements: ");
    for (i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}