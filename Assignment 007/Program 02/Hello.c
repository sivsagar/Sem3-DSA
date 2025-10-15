/*
 WAP in C to implement queue using linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *front;
	Node *rear;
} Queue;

void initQueue(Queue *q) {
	q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
	return q->front == NULL;
}

void enqueue(Queue *q, int value) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode) {
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
	newNode->data = value;
	newNode->next = NULL;
	if (q->rear == NULL) {
		q->front = q->rear = newNode;
	} else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
	printf("Enqueued %d\n", value);
}

int dequeue(Queue *q, int *deqValue) {
	if (isEmpty(q)) return 0;
	Node *tmp = q->front;
	*deqValue = tmp->data;
	q->front = tmp->next;
	if (q->front == NULL) q->rear = NULL;
	free(tmp);
	return 1;
}

int peek(Queue *q, int *frontValue) {
	if (isEmpty(q)) return 0;
	*frontValue = q->front->data;
	return 1;
}

void display(Queue *q) {
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue (front -> rear): ");
	Node *cur = q->front;
	while (cur) {
		printf("%d", cur->data);
		if (cur->next) printf(" -> ");
		cur = cur->next;
	}
	printf("\n");
}

void freeQueue(Queue *q) {
	Node *cur = q->front;
	while (cur) {
		Node *tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	q->front = q->rear = NULL;
}

int main(void) {
	Queue q;
	initQueue(&q);
	int choice, value, ok;

	while (1) {
		printf("\n--- Queue using Linked List ---\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek (front)\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			int c; while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Invalid input, please enter a number.\n");
			continue;
		}

		switch (choice) {
			case 1:
				printf("Enter value to enqueue: ");
				if (scanf("%d", &value) != 1) {
					int c; while ((c = getchar()) != '\n' && c != EOF) {}
					printf("Invalid input.\n");
					break;
				}
				enqueue(&q, value);
				break;
			case 2:
				ok = dequeue(&q, &value);
				if (ok)
					printf("Dequeued %d\n", value);
				else
					printf("Queue underflow - queue is empty\n");
				break;
			case 3:
				ok = peek(&q, &value);
				if (ok)
					printf("Front element: %d\n", value);
				else
					printf("Queue is empty\n");
				break;
			case 4:
				display(&q);
				break;
			case 5:
				freeQueue(&q);
				printf("Exiting.\n");
				return 0;
			default:
				printf("Invalid choice. Please select 1-5.\n");
		}
	}

	return 0;
}

//  Sample run (user input in bold):

//  --- Queue using Linked List ---
//  1. Enqueue
//  2. Dequeue
//  3. Peek (front)
//  4. Display
//  5. Exit
//  Enter your choice: 1
//  Enter value to enqueue: 10
//  Enqueued 10

//  Enter your choice: 1
//  Enter value to enqueue: 20
//  Enqueued 20

//  Enter your choice: 4
//  Queue (front -> rear): 10 -> 20

//  Enter your choice: 3
//  Front element: 10

//  Enter your choice: 2
//  Dequeued 10

//  Enter your choice: 4
//  Queue (front -> rear): 20

//  Enter your choice: 5
//  Exiting.

