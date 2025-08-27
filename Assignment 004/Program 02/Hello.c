/*WAP to take 2 polynomials as input and perform the following
operations-
a. additon
b. subtraction 
c. multiplication */
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int coeff;
    int exp;
} Term;

typedef struct {
    Term terms[MAX_TERMS];
    int count;
} Polynomial;

void inputPolynomial(Polynomial *p, int polyNum) {
    printf("Enter number of terms for polynomial %d: ", polyNum);
    scanf("%d", &p->count);
    
    printf("Enter terms (coefficient exponent):\n");
    for(int i = 0; i < p->count; i++) {
        printf("Term %d: ", i+1);
        scanf("%d %d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void printPolynomial(Polynomial p) {
    for(int i = 0; i < p.count; i++) {
        if(i > 0 && p.terms[i].coeff > 0) printf(" + ");
        if(p.terms[i].coeff < 0) printf(" - ");
        
        if(abs(p.terms[i].coeff) != 1 || p.terms[i].exp == 0)
            printf("%d", abs(p.terms[i].coeff));
        
        if(p.terms[i].exp > 1) printf("x^%d", p.terms[i].exp);
        else if(p.terms[i].exp == 1) printf("x");
    }
    printf("\n");
}

Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result = {0};
    int i = 0, j = 0;
    
    while(i < p1.count && j < p2.count) {
        if(p1.terms[i].exp > p2.terms[j].exp) {
            result.terms[result.count++] = p1.terms[i++];
        }
        else if(p1.terms[i].exp < p2.terms[j].exp) {
            result.terms[result.count++] = p2.terms[j++];
        }
        else {
            result.terms[result.count].coeff = p1.terms[i].coeff + p2.terms[j].coeff;
            result.terms[result.count].exp = p1.terms[i].exp;
            if(result.terms[result.count].coeff != 0) result.count++;
            i++; j++;
        }
    }
    
    while(i < p1.count) result.terms[result.count++] = p1.terms[i++];
    while(j < p2.count) result.terms[result.count++] = p2.terms[j++];
    
    return result;
}

Polynomial subtractPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result = {0};
    int i = 0, j = 0;
    
    while(i < p1.count && j < p2.count) {
        if(p1.terms[i].exp > p2.terms[j].exp) {
            result.terms[result.count++] = p1.terms[i++];
        }
        else if(p1.terms[i].exp < p2.terms[j].exp) {
            result.terms[result.count].coeff = -p2.terms[j].coeff;
            result.terms[result.count].exp = p2.terms[j].exp;
            result.count++;
            j++;
        }
        else {
            result.terms[result.count].coeff = p1.terms[i].coeff - p2.terms[j].coeff;
            result.terms[result.count].exp = p1.terms[i].exp;
            if(result.terms[result.count].coeff != 0) result.count++;
            i++; j++;
        }
    }
    
    while(i < p1.count) result.terms[result.count++] = p1.terms[i++];
    while(j < p2.count) {
        result.terms[result.count].coeff = -p2.terms[j].coeff;
        result.terms[result.count].exp = p2.terms[j].exp;
        result.count++;
        j++;
    }
    
    return result;
}

Polynomial multiplyPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result = {0};
    
    for(int i = 0; i < p1.count; i++) {
        for(int j = 0; j < p2.count; j++) {
            int coeff = p1.terms[i].coeff * p2.terms[j].coeff;
            int exp = p1.terms[i].exp + p2.terms[j].exp;
            
            // Find if term with same exponent exists
            int found = -1;
            for(int k = 0; k < result.count; k++) {
                if(result.terms[k].exp == exp) {
                    found = k;
                    break;
                }
            }
            
            if(found != -1) {
                result.terms[found].coeff += coeff;
            } else {
                result.terms[result.count].coeff = coeff;
                result.terms[result.count].exp = exp;
                result.count++;
            }
        }
    }
    
    return result;
}

int main() {
    Polynomial p1, p2, result;
    
    printf("=== Polynomial Operations ===\n");
    inputPolynomial(&p1, 1);
    inputPolynomial(&p2, 2);
    
    printf("\nPolynomial 1: ");
    printPolynomial(p1);
    printf("Polynomial 2: ");
    printPolynomial(p2);
    
    // Addition
    result = addPolynomials(p1, p2);
    printf("\nAddition: ");
    printPolynomial(result);
    
    // Subtraction
    result = subtractPolynomials(p1, p2);
    printf("Subtraction: ");
    printPolynomial(result);
    
    // Multiplication
    result = multiplyPolynomials(p1, p2);
    printf("Multiplication: ");
    printPolynomial(result);
    
    return 0;
}
