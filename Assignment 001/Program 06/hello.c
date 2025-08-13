/*Print postion of the elements of an array
i) 10,20,30,40,50
*/

#include <stdio.h>
int main () {
    int arr[5] = {10, 20, 30, 40, 50};
    int i;

    printf("Elements and Postions: ");
    for (i = 0; i < 5; i++) {
        printf("Element: %d at Position: %d ", arr[i], i);
    }
    
    printf("\n");
    return 0;
}