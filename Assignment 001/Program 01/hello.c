/*Print 5 elements of an array using a for loop
i) 10,20,30,40,50 and output will be 10 20 30 40 50*/
#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int i;

    
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}

