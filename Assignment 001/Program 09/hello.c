/*print the Sum of elements of an array
i) 10,20,30,40,50 and output will be 150
*/
#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40,50};
    int sum = 0;
    int i;
    for (i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("SUM OF THE ELEMENTS: %d\n", sum);
    return 0;
}
