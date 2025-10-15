/*
 WAP in C to implement stack using linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

// push: insert at head
void push(Node **top, int value) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode) {
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
	newNode->data = value;
	newNode->next = *top;
	*top = newNode;
	printf("Pushed %d onto stack\n", value);
}

// pop: remove from head
int pop(Node **top, int *poppedValue) {
	if (*top == NULL) {
		return 0; // failure, empty
	}
	Node *temp = *top;
	*poppedValue = temp->data;
	*top = temp->next;
	free(temp);
	return 1; // success
}

// peek: look at head
int peek(Node *top, int *topValue) {
	if (top == NULL) return 0;
	*topValue = top->data;
	return 1;
}

int isEmpty(Node *top) {
	return top == NULL;
}

void display(Node *top) {
	if (top == NULL) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack (top -> bottom): ");
	Node *cur = top;
	while (cur) {
		printf("%d", cur->data);
		if (cur->next) printf(" -> ");
		cur = cur->next;
	}
	printf("\n");
}

void freeStack(Node **top) {
	Node *cur = *top;
	while (cur) {
		Node *tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*top = NULL;
}

int main(void) {
	Node *stack = NULL;
	int choice, value, ok;

	while (1) {
		printf("\n--- Stack using Linked List ---\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek (top)\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			// clear stdin and continue
			int c; while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Invalid input, please enter a number.\n");
			continue;
		}

		switch (choice) {
			case 1:
				printf("Enter value to push: ");
				if (scanf("%d", &value) != 1) {
					int c; while ((c = getchar()) != '\n' && c != EOF) {}
					printf("Invalid input.\n");
					break;
				}
				push(&stack, value);
				break;
			case 2:
				ok = pop(&stack, &value);
				if (ok)
					printf("Popped %d from stack\n", value);
				else
					printf("Stack underflow - stack is empty\n");
				break;
			case 3:
				ok = peek(stack, &value);
				if (ok)
					printf("Top element: %d\n", value);
				else
					printf("Stack is empty\n");
				break;
			case 4:
				display(stack);
				break;
			case 5:
				freeStack(&stack);
				printf("Exiting.\n");
				return 0;
			default:
				printf("Invalid choice. Please select 1-5.\n");
		}
	}

	return 0;
}

 /* Sample run (user input in bold):

 --- Stack using Linked List ---
 1. Push
 2. Pop
 3. Peek (top)
 4. Display
 5. Exit
 Enter your choice: 1
 Enter value to push: 10
 Pushed 10 onto stack

 --- Stack using Linked List ---
 Enter your choice: 1
 Enter value to push: 20
 Pushed 20 onto stack

 Enter your choice: 4
 Stack (top -> bottom): 20 -> 10

 Enter your choice: 3
 Top element: 20

 Enter your choice: 2
 Popped 20 from stack

 Enter your choice: 4
 Stack (top -> bottom): 10

 Enter your choice: 5
 Exiting.

*/