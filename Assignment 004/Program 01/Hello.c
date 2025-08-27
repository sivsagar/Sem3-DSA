/*Write a program to take a polynomial as input store it in*/
#include <stdio.h>

int main() {
    int degree, i;
    
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    
    int coefficients[degree + 1];
    
    printf("Enter the coefficients (from highest degree to constant term):\n");
    for(i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", degree - i);
        scanf("%d", &coefficients[i]);
    }
    
    printf("\nThe polynomial is: ");
    for(i = 0; i <= degree; i++) {
        if(coefficients[i] != 0) {
            if(i > 0 && coefficients[i] > 0) {
                printf(" + ");
            } else if(coefficients[i] < 0) {
                printf(" - ");
                coefficients[i] = -coefficients[i];
            }
            
            if(degree - i == 0) {
                printf("%d", coefficients[i]);
            } else if(degree - i == 1) {
                if(coefficients[i] == 1) {
                    printf("x");
                } else {
                    printf("%dx", coefficients[i]);
                }
            } else {
                if(coefficients[i] == 1) {
                    printf("x^%d", degree - i);
                } else {
                    printf("%dx^%d", coefficients[i], degree - i);
                }
            }
        }
    }
    printf("\n");
    
    return 0;
}

/*
---------------------OUTPUT------------------
Enter the degree of the polynomial: 3
Enter the coefficients (from highest degree to constant term):
Coefficient of x^3: 2
Coefficient of x^2: -5
Coefficient of x^1: 0
Coefficient of x^0: 7

The polynomial is: 2x^3 - 5x^2 + 7
*/