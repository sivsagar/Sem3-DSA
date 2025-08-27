/*Take 1 polynomial as input & differentiate it */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coeff;
    int exp;
} Term;

void printPolynomial(Term poly[], int n) {
    printf("Polynomial: ");
    for (int i = 0; i < n; i++) {
        if (i > 0 && poly[i].coeff > 0) printf(" + ");
        if (poly[i].coeff < 0) printf(" - ");
        printf("%dx^%d", abs(poly[i].coeff), poly[i].exp);
    }
    printf("\n");
}

void printDifferentiatedPolynomial(Term poly[], int n) {
    printf("Differentiated Polynomial: ");
    int first = 1;
    
    for (int i = 0; i < n; i++) {
        if (poly[i].exp == 0) {
            // Derivative of constant is 0, skip it
            continue;
        }
        
        int newCoeff = poly[i].coeff * poly[i].exp;
        int newExp = poly[i].exp - 1;
        
        if (!first && newCoeff > 0) printf(" + ");
        if (newCoeff < 0) printf(" - ");
        
        if (newExp == 0) {
            printf("%d", abs(newCoeff));
        } else if (newExp == 1) {
            if (abs(newCoeff) == 1) {
                printf("x");
            } else {
                printf("%dx", abs(newCoeff));
            }
        } else {
            if (abs(newCoeff) == 1) {
                printf("x^%d", newExp);
            } else {
                printf("%dx^%d", abs(newCoeff), newExp);
            }
        }
        first = 0;
    }
    
    if (first) {
        printf("0");  // If all terms were constants
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    Term *poly = (Term*)malloc(n * sizeof(Term));
    
    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d - Coefficient: ", i + 1);
        scanf("%d", &poly[i].coeff);
        printf("Term %d - Exponent: ", i + 1);
        scanf("%d", &poly[i].exp);
    }
    
    printPolynomial(poly, n);
    printDifferentiatedPolynomial(poly, n);
    
    free(poly);
    return 0;
}

/*
OUTPUT
Enter number of terms: 3
Enter coefficient and exponent for each term:
Term 1 - Coefficient: 4
Term 1 - Exponent: 3
Term 2 - Coefficient: -6
Term 2 - Exponent: 2
Term 3 - Coefficient: 5
Term 3 - Exponent: 0

Polynomial: 4x^3 - 6x^2 + 5x^0
Differentiated Polynomial: 12x^2 - 12x
*/