/*Mutlipy the elements of a array by 2
i) 10,20,30,40,50 and output will be 20,40,60,80,100
*/

#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int i;

    printf("Multiplied elements: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i] * 2);
    }
    
    printf("\n");
    return 0;
}