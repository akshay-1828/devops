#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

char queue[SIZE];
int front = -1, rear = -1;

// Check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if the queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Insert element into circular queue
void enqueue(char element) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert '%c'\n", element);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = element;
    printf("Inserted '%c' into queue\n", element);
}

// Delete element from circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }
    printf("Deleted '%c' from queue\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Menu-driven program
int main() {
    int choice;
    char element;
    
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}