/*
write a program in C to perform the following stack operations with a menu based system. Observe the fow of data in stack and write the outputs in your laboratory notes.
i. push- add item to stack.(print overflow if stack is full)
ii. pop- remove item from stack
iii. peek - see the top item of stack
iv. view - gives the view of the stack
Instruction:- 1. You may use a global integer for the stack.
*/
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = item;
    printf("%d pushed to stack.\n", item);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

// View operation
void view() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. View\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                view();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

/*output
--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. View
5. Exit
Enter your choice: 1
Enter item to push: 10
10 pushed to stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. View
5. Exit
Enter your choice: 1
Enter item to push: 20
20 pushed to stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. View
5. Exit
Enter your choice: 4
Stack elements: 20 10 

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. View
5. Exit
Enter your choice: 3
Top element: 20

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. View
5. Exit
Enter your choice: 2
20 popped from stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. View
5. Exit
Enter your choice: 4
Stack elements: 10 

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. View
5. Exit
Enter your*/