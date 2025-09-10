/*WAP in C to reverse a number using stack*/
#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int main() {
    int num, digit, reversed = 0;
    Stack s;
    s.top = -1;

    printf("Enter a number: ");
    scanf("%d", &num);

    int temp = num;
    while (temp > 0) {
        digit = temp % 10;
        push(&s, digit);
        temp /= 10;
    }

    int multiplier = 1;
    while (s.top != -1) {
        reversed += pop(&s) * multiplier;
        multiplier *= 10;
    }

    printf("Reversed number: %d\n", reversed);
    return 0;
}

/*
Sample Output:
Enter a number: 12345
Reversed number: 54321
*/