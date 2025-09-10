/*WAP in C to Reverse a string using stack
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Stack functions
void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    return '\0';
}

int main() {
    char str[MAX];
    Stack s;
    s.top = -1;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }

    // Push all characters to stack
    for (size_t i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    printf("Reversed string: ");
    // Pop all characters from stack
    while (s.top != -1) {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}

/*
Sample Output:
Enter a string: hello world
Reversed string: dlrow olleh
*/