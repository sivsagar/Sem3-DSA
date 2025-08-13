#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i, j, temp;

    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // use this loop to see intermediate steps
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

/*-------------------OUTPUT--------------
Enter the number of elements in the array: 5
Enter 5 elements: 98 23 70 60 69
23 70 60 69 98
23 60 69 70 98
23 60 69 70 98
23 60 69 70 98
23 60 69 70 98
Sorted array:
23 60 69 70 98
*/