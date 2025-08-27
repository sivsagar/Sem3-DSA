/*Take 1 polynomial as input & integrate it */
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
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
    }
    printf("\n");
}

void printIntegratedPolynomial(Term poly[], int n) {
    printf("Integrated Polynomial: ");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" + ");
        printf("%.2fx^%d", (float)poly[i].coeff / (poly[i].exp + 1), poly[i].exp + 1);
    }
    printf(" + C\n");
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
    printIntegratedPolynomial(poly, n);
    
    free(poly);
    return 0;
}

/*
OUTPUT
Enter number of terms: 3
Enter coefficient and exponent for each term:
Term 1 - Coefficient: 3
Term 1 - Exponent: 2
Term 2 - Coefficient: -4
Term 2 - Exponent: 1
Term 3 - Coefficient: 5
Term 3 - Exponent: 0

Polynomial: 3x^2-4x^1 + 5x^0
Integrated Polynomial: 1.00x^3 + -2.00x^2 + 5.00x^1 + C
*/